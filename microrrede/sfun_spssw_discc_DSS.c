/*
 * no debug
 * mex -v -largeArrayDims sfun_spssw_discc_DSS.c -I./codegen/lib/DSS_Functions_Lib2
 * ./codegen/lib/DSS_Functions_Lib2/DSS_Functions_Lib2.lib debugF mex -v -g -largeArrayDims
 * sfun_spssw_discc_DSS.c -I./codegen/lib/DSS_Functions_Lib2
 * ./codegen/lib/DSS_Functions_Lib2/DSS_Functions_Lib2.lib
 */

/*
 * File:    %M%
 * Version: %I%
 * ------------------------------------------------------------------------
 * The "sfun_spssw_discc_DSS" Sfunction is a discrete implementation of state-space
 * system for Specialized Power Systems. It is used for discrete simulation of
 * an electrical system which may contains switches and non linear elements.
 *
 * Switches are modelled by resistances. In the open state, resistance is infinite.
 * In the closed state, resistance is specified by the RS_PARAM input argument.
 *
 * Inputs/Outputs:
 * ------------------------------------------------------------------------
 *    Three input ports.
 *        Port 0: Currents and voltages (direct feedthrough)
 *        Port 1: Switch gate signals (0/1)  (NO DIRECT FEEDTHROUGH!)
 *        Port 2: Concatenated D matrices of non linear elements (direct feedthrough)
 *
 *    Three output ports.
 *        Port 0: Current and voltage outputs.
 *        Port 1: Switch status (0/1)
 *        Port 2: Continuous states of nonlinear inductances (flux-likage of Lsat elements).
 *
 * The S function uses (NINPUT+NSWITCH) inputs on first two input ports
 * and D matrices of non linear elements on third port.
 * It returns (NOUTPUT+NSWITCH) outputs on first two output ports
 * and fluxes of iterative non linear inductances on third port,
 * where NINPUT and NOUTPUTare the number of inputs and outputs of the
 * state-space system and NSWITCH is the number of switches.
 *
 * The number of inputs is given by the number of columns of matrix B,
 * the number of outputs is given by the number of rows of matrix C and
 * the number of switches is given by the length of the switch resistance
 * array if present.
 *
 * Input vectors:
 *
 *  Port 0:
 *
 *  _______________________NINPUT____________________
 * /                                                 \
 * +----------------+--------------------------------+
 * |0               |                                |
 * +----------------+--------------------------------+
 * \____NSWITCH_____/\________NINPUT-NSWITCH_________/
 *       (1)                       (2)
 *
 * (1)- The first NSWITCH inputs are the switch currents inputs
 *      which must be set to zero
 *
 * (2)- The next inputs (NSWITCH+1:NINPUT) are the other current and voltage
 *      source inputs.
 *
 *
 *  Port 1:
 *
 *  _____NSWITCH_____
 * /                 \
 * +-----------------+
 * |      GATES      |
 * +-----------------+
 *
 * Port 1 inputs are the switch gate signals (0/1).
 * (Diodes have no gate signal but corresponding input should be set to 0)
 *
 *  Port 2:
 *
 *  _______N_ D_____
 * /                 \
 * +-----------------+
 * |   D_NONLIN      |
 * +-----------------+
 *
 * Port 2 inputs are the continuous state space D matrices
 * of nonlinear elements concatenated  D1D2D3...
 *
 * Output vectors:
 *
 *  Port 0:
 *
 *  _____________________NOUTPUT_____________________
 * /                                                 \
 * +----------------+--------------------------------+
 * |0               |                                |
 * +----------------+--------------------------------+
 * \____NSWITCH_____/\________NOUTPUT-NSWITCH________/
 *       (3)                       (4)
 *
 * (3)- The first NSWITCH outputs are the switch voltages.
 *
 * (4)- The next outputs (NSWITCH+1:NOUTPUT) are the other current and voltage
 *      outputs.
 *
 *
 *  Port 1:
 *
 *  _____NSWITCH_____
 * /                 \
 * +-----------------+
 * | SWITCHES STATES |
 * +-----------------+
 *
 * Port 1 NSWITCH outputs are the switch status (0=open; 1=closed)
 *
 *  Port 2:
 *
 *  __NSTATE_NONLIN__
 * /                 \
 * +-----------------+
 * |  NONLIN STATES  |
 * +-----------------+
 *
 *  Port 2 NSTATE_NONLIN outputs are the continuous states of
 *  nonlinear iterative elements (fluxes of saturable inductancea)
 *
 *
 * Function parameters:
 * -------------------
 *
 *   Index  Symbolic Name        Description
 *   -----  -------------------- --------------------------------------
 *   0      TS_PARAM             Sampling time.
 *   1      A_PARAM              A,B,C,D: Continuous state space matrices of
 *   2      B_PARAM              electrical system (all switches open).
 *   3      C_PARAM
 *   4      D_PARAM
 *   5      XO_PARAM             Vector (1,NSTATES) of initial values of discrete states.
 *   6      EnableUseOfTLC_PARAM Enable the use of the TLC with accelarator.
 *
 *   The following parameters are used by Dynamic State-Space (DSS)
 *   modelling of the N nonlinear elements (iterative and non-iterative)
 *
 *   7      DSS_Dim_PARAM        Matrix (N,3) specifying the state-space dimensions
 *                               of the N nonlinear elements (iterative or non iterative)
 *                               one line per element containing:
 *                                 Nx  : Number of states
 *                                 Nu  : Number of inputs
 *                                 Ny  : Number of outputs
 *   8      DSS_xInit_PARAM      Vector (sum(Nx)) of continuous initial states of nonlinear
 * iterative elements Lsat All states of the N Lsat elements are concatenated 9 DSS_Inputs_PARAM
 * Matrix (N,ncol) of input numbers of linear system A B C D connected to outputs of the N nonlinear
 * elements ncol =  max number of outputs of all nonlinear elements Unused columns are set to zero
 *   10     DSS_Outputs_PARAM    Matrix (N,ncol) of output numbers of linear system A B C D
 *                               connected to inputs of the N nonlinear elements
 *                               ncol =  max number of inputs of all nonlinear elements
 *                               Unused columns are set to zero
 *   11     DSS_InitialOutputs_PARAM Matrix (N,ncol) of initial outputs of linear system A B C D
 *                               (corresponding the initial inputs of nonlinear elements)
 *                               ncol =  max number of inputs of all nonlinear elements
 *                               Unused columns are set to zero
 *                               These initial outputs are used to discretize the
 *                               initial continuous states on nonlinear elements
 *   12     DSS_Iterative_PARAM  Vector (N,1) indicating if  nonlinear elements are iterative or non
 * iterative 0 : element is noniterative 1 : element is iterative 13     DSS_VI_SIZE_PARAM    Vector
 * (N,1) of number of V/I  or Flux/I pairs defining the non linear characteristics of iterative
 * elements 14     DSS_VI_PARAM         Matrix (n,2) of all  V-I or Flux-I characteristics
 *                               concatenated for all iterative elements (RnonLin, Lsat)
 *                               ("piecewise linear" characteristics)
 *                                  column 1 = V (Volts) or flux linkage (V.s)
 *                                  column 2 = I (Amp)
 *   15     DSS_Method_PARAM    Vector (N,1) indicating discretization method for nonlinear elements
 *                              Two methods are available:
 *                                      1 = 'Backward Euler'
 *                                      2 = 'Tustin'
 *
 *   The Following three parameters control convergence for iterative nonlinear elements
 * (RnonLin,Lsat)
 *
 *   16     DSS_TOLERANCE_NONLINEAR  Relative tolerance (recommended value 1e-4)
 *   17     DSS_NITER_NONLINEAR_MAX  Maximum number of iterations
 *   18     DSS_CONTINUE_ON_MAX_ITERATION Integer 0/1
 *                             0 -> Stop with error if max. number of iterations is reached
 *                             1 -> Contimue without error if max. number of iterations is reached
 *                                 (Option to be used for real time, with limited number of
 * iterations)
 *
 *   The following parameters are omitted when switch count is 0.
 *
 *   19     RS_PARAM         Vector (1,NSWITCH) of switch resistances
 *                           in the closed state
 *   20     SWT_PARAM        Vector (1,NSWITCH) of switch types :
 *                             1 : Ideal switch
 *                             2 : Circuit breaker (closes on demand;
 *                                 opens at zero crossing current)
 *                             3 : Diode ; closes if V>0 Opens if I<0
 *                             4 : Thyristor
 *                             5 : GTO
 *                             6 : IBGT
 *                             7 : IBGT/diode pair or MOSFET with internal diode
 *   21     GIV_PARAM        Vector (1,NSWITCH) of switch gate initial values (0/1)
 *
 *   22     YISW_PARAM       Vector (1,NSWITCH) of switch current measurement indexes (Indexes in
 * output vector). Output current of corresponding switches will be forced to '0'  when switches are
 * open. A zero index means a zero current is not forced on that particular switch when open.
 *
 *   23     TBEON            (0/1) Enables Tustin/Backward-Euler option
 *
 *
 * Special compilation flags:
 * --------------------------
 *
 *  The following flags can be defined on the "mex" command line
 *
 *    mex -DDEBUG :   Enable debug printout. Default: No printout.
 *
 * ------------------------------------------------------------------------
 *  Gilbert Sybille, (IREQ) 2004 : Author of original file in M
 *  R. Roussel (IREQ) 2004 , C version of M file.
 *  B. DeKelper ETS, 01-nov-2006, 10-may-2007,  Revisions and updates
 *  E. Lemieux (IREQ), 12-nov-2007, Added "EnableUseOfTLC" option
 *  O. Tremblay (IREQ), 12-April-2013, Added the TBE simulation engine
 *  O. Tremblay (IREQ), 10-Feb-2015, Added the Save ABCD option
 *  P. Brunelle , Jan-2014, mods related to "TBEON" new parameter
 *  G. Sybille / E. LeHuy (IREQ), Aug 2018, Added DSS for nonlinear elements
 *  G. Sybille (IREQ), July 2019, Modify iterations for nonlinear resistances and inductances
 *  Copyright 1997-2019 Hydro-Quebec, and The MathWorks, Inc.
 * ------------------------------------------------------------------------
 */

#define S_FUNCTION_NAME  sfun_spssw_discc_DSS
#define S_FUNCTION_LEVEL 2

#include "simstruc.h"

#ifdef MATLAB_MEX_FILE /* Is this file being compiled as a MEX-file? */
#include "matrix.h"
#include "mex.h"
#endif

#include <math.h>
#include <stdlib.h> /* for calloc, free */
#include <string.h> /* for memcpy */

/*DSS*/
#include "DSS_Utils.h"
#ifdef MATLAB_MEX_FILE /* Is this file being compiled as a MEX-file? */
#include "DSS_Utils.c" /* MEX-file interface mechanism */
#else
#endif

#define U0(element)     (*u0Ptrs[element]) /* Pointer to Input Port0 */
#define U1(element)     (*u1Ptrs[element]) /* Pointer to Input Port1 */
#define U_ABCD(element) (*u2Ptrs[element]) /* Pointer to Input Port2 (DSS) */

/* Parameter access macros */

/* Parameters indexes */

enum paramIdx_tag {
    TS_PARAM_IDX,
    A_PARAM_IDX,
    B_PARAM_IDX,
    C_PARAM_IDX,
    D_PARAM_IDX,
    XO_PARAM_IDX,
    EnableUseOfTLC_PARAM_IDX,
    DSS_Dim_PARAM_IDX,
    DSS_xInit_PARAM_IDX,
    DSS_Inputs_PARAM_IDX,
    DSS_Outputs_PARAM_IDX,
    DSS_InitialOutputs_PARAM_IDX,
    DSS_Iterative_PARAM_IDX,
    DSS_VI_SIZE_PARAM_IDX,
    DSS_VI_PARAM_IDX,
    DSS_Method_PARAM_IDX,
    DSS_TOLERANCE_NONLINEAR_IDX,
    DSS_NITER_NONLINEAR_MAX_IDX,
    DSS_CONTINUE_ON_MAX_ITERATION_IDX,
    RS_PARAM_IDX,   /* only when switches are present */
    SWT_PARAM_IDX,  /* only when switches are present */
    GIV_PARAM_IDX,  /* only when switches are present */
    YISW_PARAM_IDX, /* only when switches are present */
    TBEON_PARAM_IDX /* only when switches are present */
};

#define NPARAMS_NOSWITCH   7 + 12  /*Number of Sfun parameters when no switches +12 (DSS)*/
#define NPARAMS_WITHSWITCH 12 + 12 /*Number of Sfun parameters when switches +12 (DSS)*/
#define NOERROR_PARAM      1       /*P.B.sept13*/
#define MAX_ITERATION      20      /*O.T. april 2013*/
#define NONLIN_ITER_TOL    1e-4    /*DSS*/

#define TS_PARAM(S)                      ssGetSFcnParam(S, TS_PARAM_IDX)
#define A_PARAM(S)                       ssGetSFcnParam(S, A_PARAM_IDX)
#define B_PARAM(S)                       ssGetSFcnParam(S, B_PARAM_IDX)
#define C_PARAM(S)                       ssGetSFcnParam(S, C_PARAM_IDX)
#define D_PARAM(S)                       ssGetSFcnParam(S, D_PARAM_IDX)
#define XO_PARAM(S)                      ssGetSFcnParam(S, XO_PARAM_IDX)
#define EnableUseOfTLC_PARAM(S)          ssGetSFcnParam(S, EnableUseOfTLC_PARAM_IDX)
#define DSS_Dim_PARAM(S)                 ssGetSFcnParam(S, DSS_Dim_PARAM_IDX)
#define DSS_xInit_PARAM(S)               ssGetSFcnParam(S, DSS_xInit_PARAM_IDX)
#define DSS_Inputs_PARAM(S)              ssGetSFcnParam(S, DSS_Inputs_PARAM_IDX)
#define DSS_Outputs_PARAM(S)             ssGetSFcnParam(S, DSS_Outputs_PARAM_IDX)
#define DSS_InitialOutputs_PARAM(S)      ssGetSFcnParam(S, DSS_InitialOutputs_PARAM_IDX)
#define DSS_Iterative_PARAM(S)           ssGetSFcnParam(S, DSS_Iterative_PARAM_IDX)
#define DSS_VI_PARAM(S)                  ssGetSFcnParam(S, DSS_VI_PARAM_IDX)
#define DSS_VI_SIZE_PARAM(S)             ssGetSFcnParam(S, DSS_VI_SIZE_PARAM_IDX)
#define DSS_Method_PARAM(S)              ssGetSFcnParam(S, DSS_Method_PARAM_IDX)
#define DSS_TOLERANCE_NONLINEAR(S)       ssGetSFcnParam(S, DSS_TOLERANCE_NONLINEAR_IDX)
#define DSS_NITER_NONLINEAR_MAX(S)       ssGetSFcnParam(S, DSS_NITER_NONLINEAR_MAX_IDX)
#define DSS_CONTINUE_ON_MAX_ITERATION(S) ssGetSFcnParam(S, DSS_CONTINUE_ON_MAX_ITERATION_IDX)
#define RS_PARAM(S)                      ssGetSFcnParam(S, RS_PARAM_IDX)
#define SWT_PARAM(S)                     ssGetSFcnParam(S, SWT_PARAM_IDX)
#define GIV_PARAM(S)                     ssGetSFcnParam(S, GIV_PARAM_IDX)
#define YISW_PARAM(S)                    ssGetSFcnParam(S, YISW_PARAM_IDX)
#define TBE_ON(S)                        ssGetSFcnParam(S, TBEON_PARAM_IDX)

/* Work vectors sizes and indexes definitions */

/* Integer work vector */

enum IWORK_idx_tag {
    NINPUT = 0,
    NOUTPUT,
    NSWITCH,
    NSTATES,
    NSTATES_NSTATES,
    NSTATES_NINPUTS,
    NOUTPUTS_NSTATES,
    NOUTPUTS_NINPUTS,
    SWITCHES_HAVE_CHANGED,
    NU1,
    NY1,
#ifdef DEBUG
    STEP_NUMBER,
    MAJOR_STEP_NUMBER,
#endif

    NSTEP,
    /* Must always be last! */
    N_IWORKS
};

/* Real work vector */

enum RWORK_idx_tag {
    TIME_NO_SWITCH_CONV = 0,
    /* Must always be last! */
    N_RWORKS
};


/* Pointer work vector indexes */

enum PWORK_idx_tag {
    AS = 0, /* A matrix address (DSS: A_Global)*/
    BS,     /* B matrix address (DSS: B_Global)*/
    CS,     /* C matrix address (DSS: C_Global)*/
    DS,     /* D matrix address (DSS: D_Global)*/
    DX_COL,
    BD_COL,
    TMP1,
    TMP2,
    XTMP,

    D_NONLINEAR_DISC,
    A_GLOBAL,
    B_GLOBAL,
    C_GLOBAL,
    D_GLOBAL,

    D12D2,
    EYEMATRIX,
    WI12,
    RESULTINV1,
    RESULTINV2,
    WORKINGC1,
    WORKINGC2,
    WORKINGD1,
    WORKINGD2,
    WORKINGINV0,
    WORKINGINV1,
    WORKINGINV2,
    MMATRIX,
    RESULT1,
    RESULT2,
    REFROWS,
    REFCOLS,
    RESHAPEMATRIX,

    NONLINEAR_DIM,
    NONLINEAR_INPUTS,
    NONLINEAR_OUTPUTS,
    NONLINEAR_ITERATIVE,
    NONLINEAR_METHOD,
    NONLINEAR_SIZE_VI,
    NONLINEAR_VI,
    Y_NONLINEAR_ITERATIVE,
    Y_NONLINEAR_ITERATIVE_LAST,
    STOP_ITER_NONLINEAR,
    NOSEG,
    NOSEG_LAST,
    ASEG,
    BSEG,

    U_ARRAY,
    NONLINEAR_LSAT,
    XD_LSAT,
    U0_HIST_LSAT,
    Y_X_NONLINEAR,
    Y_ARRAY,

    /* The following pointers are used when circuit has switches */

    SWITCH_STATUS,      /* Switches states */
    SWITCH_STATUS_INIT, /* P.B. Used to keep initial switches status (open or closed) */
    SW_CHG,
    G_STATE,
    USWLAST,
    XKM12, /* TBE solver */
    XKP12, /* TBE solver */
    XLAST, /* TBE solver */
    ULAST, /* TBE solver */

    IDX_SW_CHG,
    Y_SWITCH, /* Switches conductance */
    SWITCH_TYPES,
    IDX_OUT_SW, /* Indexes of switch current outputs */

#ifdef DEBUG
    SWITCH_TOPO_COUNT,
    SWITCH_TOPO_TIME,
#endif

    /* Must always be last! */
    N_PWORKS
};

/*====================*
 * S-function methods *
 *====================*/

#undef MDL_CHECK_PARAMETERS
#if defined(MDL_CHECK_PARAMETERS) && defined(MATLAB_MEX_FILE)
/* Function: mdlCheckParameters ====================================================================
 * Abstract:
 *    Validate our parameters to verify they are okay.
 */

static void mdlCheckParameters(SimStruct* S) {}
#endif /* MDL_CHECK_PARAMETERS */

/* matrix operation (multiplication, sub, invert) functions */
#if 1
static __inline int addMatrix(emxArray_real_T* x, emxArray_real_T* y, emxArray_real_T* r) {
    int     idx, max;
    double* x_data = x->data;
    double* y_data = y->data;
    double* r_data = r->data;

    if (x->size[0] != y->size[0] || r->size[0] != x->size[0] || r->size[1] != y->size[1] ||
        x->size[1] != y->size[1]) {
        return 1;
    }

    for (idx = 0, max = x->size[0] * x->size[1]; idx < max; idx++) {
        r_data[idx] = x_data[idx] + y_data[idx];
    }

    return 0;
}

static __inline int multiplyMatlab(emxArray_real_T* x, emxArray_real_T* y, emxArray_real_T* r) {
    int     idxCY, columnJumpY, idxRX, rowJumpX, idx, rowY, colY, rowX;
    double  val;
    double* x_data = x->data;
    double* y_data = y->data;
    double* r_data = r->data;

    if (x->size[1] != y->size[0] || r->size[0] != x->size[0] || r->size[1] != y->size[1]) {
        /* dim are not ok */
        return 1;
    }

    colY = y->size[1];
    rowY = y->size[0];
    rowX = x->size[0];
    /* loop for each column of Y */
    for (idxCY = 0; idxCY < colY; idxCY++) {
        /* loop for each row of X */
        columnJumpY = idxCY * rowY;

        for (idxRX = 0; idxRX < rowX; idxRX++) {
            val      = 0;
            rowJumpX = idxRX;

            for (idx = 0; idx < rowY; idx++) {
                val += y_data[idx + columnJumpY] * x_data[idx * rowX + rowJumpX];
            }

            r_data[idxRX + idxCY * rowX] = val;
        }
    }

    return 0;
}

static __inline int multiplyZone(emxArray_real_T* a,
                                 emxArray_real_T* b,
                                 emxArray_real_T* r,
                                 int              aX,
                                 int              aY,
                                 int              aRow,
                                 int              aCol,
                                 int              bX,
                                 int              bY,
                                 int              bRow,
                                 int              bCol,
                                 int              rX,
                                 int              rY,
                                 int              rRow,
                                 int              rCol) {
    int     idxColB, maxColB, idxRowA, maxRowA, idxRowB, maxRowB, rowA, rowB, rowR;
    double* a_data = a->data;
    double* b_data = b->data;
    double* r_data = r->data;

    if (aCol != bRow || rRow != aRow || rCol != bCol) {
        return 1;
    }
    rowB = b->size[0];
    rowR = r->size[0];
    rowA = a->size[0];
    for (idxColB = 0, maxColB = bCol; idxColB < maxColB; idxColB++) {
        /* loop for each row of X */
        /* int columnJumpB = idxColB*bRow; */
        int jumpZoneB = (bX + idxColB) * rowB + bY;

        for (idxRowA = 0, maxRowA = aRow; idxRowA < maxRowA; idxRowA++) {
            double val       = 0;
            int    rowJumpA  = idxRowA;
            int    jumpZoneR = (rX + idxColB) * rowR + rY;

            for (idxRowB = 0, maxRowB = bRow; idxRowB < maxRowB; idxRowB++) {
                int jumpZoneA = (aX + idxRowB) * rowA + aY;
                val += b_data[idxRowB + jumpZoneB] * a_data[rowJumpA + jumpZoneA];
            }


            r_data[idxRowA + jumpZoneR] = val;
        }
    }

    return 0;
}

static __inline int multiplyZoneMatlab(emxArray_real_T* a,
                                       emxArray_real_T* b,
                                       emxArray_real_T* r,
                                       int              aRowStart,
                                       int              aRowEnd,
                                       int              aColStart,
                                       int              aColEnd,
                                       int              bRowStart,
                                       int              bRowEnd,
                                       int              bColStart,
                                       int              bColEnd,
                                       int              rRowStart,
                                       int              rRowEnd,
                                       int              rColStart,
                                       int              rColEnd) {
    /*
     * A        *      B      =     R
     *
     * | A B C D |     | A B C |     | A B C |
     * | E F G H |     | D|E F||     | D E F |
     * | I|J K|L |  *  | G|H I||  =  | G|H I||
     * | M|N O|P |     | J K L |     | J|K L||
     * | Q|R S|T |                   | M|N O||
     *
     *
     * in memory:
     *
     * A = { A E I M Q  B F J N R  C G K O S  D H L P T }
     * 0       4  5       9  10     14  15     19
     *
     * B = { A D G J  B E H K  C F I L }
     *
     * result = { A D G J M  B E H K N  C F I L O }
     *
     * but in a specified zone, like using smaller matrix inside the big ones.
     * in this example, inputs are (after the structure): 2,4,1,2
     * aX = colStart
     * aY = rowStart
     * aRow = rowEnd - rowStart + 1
     * aCol = colEnd - colStart + 1
     */
    return multiplyZone(a, b, r, aColStart, aRowStart, aRowEnd - aRowStart + 1,
                        aColEnd - aColStart + 1, bColStart, bRowStart, bRowEnd - bRowStart + 1,
                        bColEnd - bColStart + 1, rColStart, rRowStart, rRowEnd - rRowStart + 1,
                        rColEnd - rColStart + 1);
}

static __inline int invert(emxArray_real_T*  a_,
                           emxArray_real_T*  r_,
                           emxArray_real_T*  A_,
                           emxArray_int32_T* ipiv_,
                           emxArray_int32_T* p_) {
    /* vars */
    int    n;
    int    i1;
    int    yk;
    int    b_n;
    int    k;
    int    j;
    int    mmj;
    int    c;
    int    ix;
    double smax;
    int    i2;
    int    jy;
    double s;
    int    ijA;
    int    A_numRow, r_numRow, r_numCol;

    double* a__data    = a_->data;
    double* r__data    = r_->data;
    double* A__data    = a_->data;
    int*    ipiv__data = ipiv_->data;
    int*    p__data    = p_->data;

    /* initial protection ... required? */
    /*
     * if (a_->size[0] != r_->size[0] || a_->size[1] != r_->size[1] || a_->size[0] != a_->size[1]
     * || A_->size[0] != a_->size[0] || A_->size[1] != a_->size[1] || ipiv_->size[0] != 1
     * || p_->size[0] != 1 || ipiv_->size[1] != a_->size[0] || p_->size[1] != a_->size[0]) {
     * return 1;
     * }
     */
    /* ceux-la sont les principaux dans les boucles de calculs */
    r_numRow = r_->size[0];
    r_numCol = r_->size[1];
    A_numRow = A_->size[0];

    /* step1, clear result matrix */
    n  = a_->size[0];
    yk = r_numRow * r_numCol;

    for (i1 = 0; i1 < yk; i1++) {
        r__data[i1] = 0.0;
    }

    /* copy data */
    yk = i1;
    for (i1 = 0; i1 < yk; i1++) {
        A__data[i1] = a__data[i1];
    }

    /* protection? */
    yk = a_->size[0];
    if (yk < 1) {
        b_n = 0;
    } else {
        b_n = yk;
    }

    /* step3 init ipiv */
    if (b_n > 0) {
        ipiv__data[0] = 1;
        yk            = 1;
        for (k = 2; k <= b_n; k++) {
            yk++;
            ipiv__data[k - 1] = yk;
        }
    }

    /* step4 let's start! WTF is all that!? */
    if (a_->size[0] < 1) {
        /* do nothing! */
    } else {
        /*
         * if (a_->size[0] - 1 <= a_->size[0]) {
         */
        i1 = a_->size[0] - 1;
        /*
         * }
         * else {
         * i1 = a_->size[0];
         * }
         */
        for (j = 0; j + 1 <= i1; j++) {
            mmj = n - j;
            c   = j * (n + 1);
            if (mmj < 1) {
                yk = -1;
            } else {
                yk = 0;
                if (mmj > 1) {
                    ix   = c;
                    smax = fabs(A__data[c]);
                    for (k = 1; k + 1 <= mmj; k++) {
                        ix++;
                        s = fabs(A__data[ix]);
                        if (s > smax) {
                            yk   = k;
                            smax = s;
                        }
                    }
                }
            }

            if (A__data[c + yk] != 0.0) {
                if (yk != 0) {
                    ipiv__data[j] = (j + yk) + 1;
                    ix            = j;
                    yk += j;
                    for (k = 1; k <= n; k++) {
                        smax        = A__data[ix];
                        A__data[ix] = A__data[yk];
                        A__data[yk] = smax;
                        ix += n;
                        yk += n;
                    }
                }

                i2 = c + mmj;
                for (jy = c + 1; jy + 1 <= i2; jy++) {
                    A__data[jy] /= A__data[c];
                }
            }

            yk  = (n - j) - 1;
            b_n = c + n;
            jy  = c + n;
            for (k = 1; k <= yk; k++) {
                smax = A__data[jy];
                if (A__data[jy] != 0.0) {
                    ix = c + 1;
                    i2 = mmj + b_n;
                    for (ijA = 1 + b_n; ijA + 1 <= i2; ijA++) {
                        A__data[ijA] += A__data[ix] * -smax;
                        ix++;
                    }
                }

                jy += n;
                b_n += n;
            }
        }
    }

    /* step5 WTF la suite!!*/
    if (a_->size[0] < 1) {
        b_n = 0;
    } else {
        b_n = a_->size[0];
    }

    /* init p*/
    if (b_n > 0) {
        p__data[0] = 1;
        yk         = 1;
        for (k = 2; k <= b_n; k++) {
            yk++;
            p__data[k - 1] = yk;
        }
    }

    /* step6 use that ipiv*/
    for (k = 0; k < ipiv_->size[1]; k++) {
        if (ipiv__data[k] > 1 + k) {
            yk                         = p__data[ipiv__data[k] - 1];
            p__data[ipiv__data[k] - 1] = p__data[k];
            p__data[k]                 = yk;
        }
    }

    /* step7 use the p*/
    for (k = 0; k + 1 <= n; k++) {
        c                                        = p__data[k] - 1;
        r__data[k + r_numRow * (p__data[k] - 1)] = 1.0;
        for (j = k; j + 1 <= n; j++) {
            if (r__data[j + r_numRow * c] != 0.0) {
                for (jy = j + 1; jy + 1 <= n; jy++) {
                    r__data[jy + r_numRow * c] -=
                        r__data[j + r_numRow * c] * A__data[jy + A_numRow * j];
                }
            }
        }
    }

    /* step8 ... WT again :)*/
    if ((a_->size[0] == 0) || ((r_numRow == 0) || (r_numCol == 0))) {
    } else {
        for (j = 1; j <= n; j++) {
            yk = n * (j - 1);
            for (k = n - 1; k + 1 > 0; k--) {
                b_n = n * k;
                if (r__data[k + yk] != 0.0) {
                    smax            = r__data[k + yk];
                    s               = A__data[k + b_n];
                    r__data[k + yk] = smax / s;
                    for (jy = 0; jy + 1 <= k; jy++) {
                        r__data[jy + yk] -= r__data[k + yk] * A__data[jy + b_n];
                    }
                }
            }
        }
    }

    return 0;
}

static __inline int copyZone(emxArray_real_T* a,
                             emxArray_real_T* r,
                             int              rX,
                             int              rY,
                             int              rRow,
                             int              rCol) {
    double val;
    int    jumpZoneA, jumpZoneR, columnJumpR, idxColR, idxRowR, rowR;

    double* a_data = a->data;
    double* r_data = r->data;

    if (rRow != a->size[0] || rCol != a->size[1]) {
        return 1;
    }

    rowR = r->size[0];
    /* scan col*/
    for (idxColR = 0; idxColR < rCol; idxColR++) {
        columnJumpR = idxColR * rRow;
        jumpZoneR   = (rX + idxColR) * rowR + rY;

        /* scan row*/
        for (idxRowR = 0; idxRowR < rRow; idxRowR++) {
            jumpZoneA = columnJumpR;
            /* get value in A*/
            val = a_data[idxRowR + jumpZoneA];

            /* write in in zone of matirx R*/
            r_data[idxRowR + jumpZoneR] = val;
        }
    }

    return 0;
}

static __inline int copyZoneMatlab(emxArray_real_T* a,
                                   emxArray_real_T* r,
                                   int              rRowStart,
                                   int              rRowEnd,
                                   int              rColStart,
                                   int              rColEnd) {
    return copyZone(a, r, rColStart, rRowStart, rRowEnd - rRowStart + 1, rColEnd - rColStart + 1);
}

static __inline int sprinkleMatrix(emxArray_real_T*  a,
                                   emxArray_real_T*  b,
                                   emxArray_int32_T* rows,
                                   emxArray_int32_T* cols) {
    int    aNumRow, bNumCol, bNumRow, col, row;
    double val;

    double* a_data    = a->data;
    double* b_data    = b->data;
    int*    rows_data = rows->data;
    int*    cols_data = cols->data;

    aNumRow = a->size[0];
    bNumCol = b->size[1];
    bNumRow = b->size[0];

    /* scan les elements de B a saupoudrer dans A*/
    for (col = 0; col < bNumCol; col++) {
        for (row = 0; row < bNumRow; row++) {
            /* get value*/
            val = b_data[bNumRow * col + row];

            /* sprinkle it in the A matrix at the desired location*/
            a_data[cols_data[col] * aNumRow + rows_data[row]] = val;
        }
    }

    return 0;
}

static __inline int writeValue(emxArray_real_T* a, int row, int col, real_T val) {
    a->data[col * a->size[0] + row] = val;

    return 0;
}

static __inline int extractReference(emxArray_int32_T* a,
                                     emxArray_int32_T* ref,
                                     int               row,
                                     int               colStart,
                                     int               colEnd,
                                     int               offset) {
    /*
     * ex: | A B  C|
     * ||D E| F|
     * | G H  I|
     * | J K  L|
     * row_ = 1
     * colStart_ = 0
     * colEnd_ = 1
     * offset will result in D - offset and E - offset
     * in memory, column-major:  a_ = { A D G J, B E H K, C F I L}
     * 1        5
     */
    int idx, pos, val, max;

    /* clear ref, do memcopy*/
    for (idx = 0, max = ref->size[1]; idx < max; idx++) {
        ref->data[idx] = 0;
    }

    pos = 0;
    for (idx = colStart; idx <= colEnd; idx++) {
        val = a->data[a->size[0] * idx + row];

        ref->data[pos++] = val - offset;
    }

    return 0;
}

/* lazy path, same pos in b and R */
static __inline int additionToZone(emxArray_real_T* a,
                                   emxArray_real_T* b,
                                   emxArray_real_T* r,
                                   int              bX,
                                   int              bY,
                                   int              bRow,
                                   int              bCol) {
    /*
     * A + B => B
     * |A B C|   |A B  C D E |    |A B   C   D   E  |
     * |D E F| + |F G |H I J||    |F G |H+A I+B J+C||
     * |G H I|   |K L |M N O|| => |K L |M+D N+E O+F||
     * |P Q |R S T||    |P Q |R+G S+H T+I||
     * |U V  W X Y |    |U V   W   X   Y  |
     *
     * in this example: bX = 2, bY = 1, bRow = 3, bCol = 3
     */
    double  val;
    int     jumpZoneA, jumpZoneB, columnJumpB, pos, idxColB, idxRowB, rowB;
    double* a_data = a->data;
    double* b_data = b->data;
    double* r_data = r->data;

    if (a->size[0] != bRow || a->size[1] != bCol) {
        /* bad size */
        return 1;
    }

    rowB = b->size[0];
    /* loop column*/
    for (idxColB = 0; idxColB < bCol; idxColB++) {
        /* prepare jumping vars for zoning*/
        columnJumpB = idxColB * bRow;
        jumpZoneB   = (bX + idxColB) * rowB + bY;

        /* loop row*/
        for (idxRowB = 0; idxRowB < bRow; idxRowB++) {
            jumpZoneA = columnJumpB;
            pos       = idxRowB + jumpZoneA;

            /* compute, addition */
            val = a_data[pos] + b_data[idxRowB + jumpZoneB];

            /* save back in b position*/
            r_data[idxRowB + jumpZoneB] = val;
        }
    }

    return 0;
}

static __inline int additionToZoneMatlab(emxArray_real_T* a,
                                         emxArray_real_T* b,
                                         emxArray_real_T* r,
                                         int              bRowStart,
                                         int              bRowEnd,
                                         int              bColStart,
                                         int              bColEnd) {
    /*
     * bX = colStart
     * bY = rowStart
     * bRow = rowEnd - rowStart + 1
     * bCol = colEnd - colStart + 1
     */
    return additionToZone(a, b, r, bColStart, bRowStart, bRowEnd - bRowStart + 1,
                          bColEnd - bColStart + 1);
}

static __inline int additionZone(emxArray_real_T* a,
                                 emxArray_real_T* b,
                                 emxArray_real_T* r,
                                 int              bX,
                                 int              bY,
                                 int              bRow,
                                 int              bCol) {
    /*
     * A + B = R
     * |A B C|   |A B  C D E |
     * |D E F| + |F G |H I J||   |A B C|
     * |G H I|   |K L |M N O|| = |D E F|
     * |P Q |R S T||   |G H I|
     * |U V  W X Y |
     *
     * in this example: bX = 2, bY = 1, bRow = 3, bCol = 3
     */
    double  val;
    int     jumpZoneA, jumpZoneB, columnJumpB, pos, idxColB, idxRowB, rowB;
    double* a_data = a->data;
    double* b_data = b->data;
    double* r_data = r->data;

    if (a->size[0] != bRow || a->size[1] != bCol) {
        /* bad size */
        return 1;
    }

    rowB = b->size[0];
    /* loop column*/
    for (idxColB = 0; idxColB < bCol; idxColB++) {
        /* prepare jumping vars for zoning*/
        columnJumpB = idxColB * bRow;
        jumpZoneB   = (bX + idxColB) * rowB + bY;

        /* loop row*/
        for (idxRowB = 0; idxRowB < bRow; idxRowB++) {
            jumpZoneA = columnJumpB;
            pos       = idxRowB + jumpZoneA;

            /* compute, addition */
            val = a_data[pos] + b_data[idxRowB + jumpZoneB];

            /* save */
            r_data[pos] = val;
        }
    }

    return 0;
}

static __inline int additionZoneMatlab(emxArray_real_T* a,
                                       emxArray_real_T* b,
                                       emxArray_real_T* r,
                                       int              bRowStart,
                                       int              bRowEnd,
                                       int              bColStart,
                                       int              bColEnd) {
    /*
     * bX = colStart
     * bY = rowStart
     * bRow = rowEnd - rowStart + 1
     * bCol = colEnd - colStart + 1
     */
    return additionZone(a, b, r, bColStart, bRowStart, bRowEnd - bRowStart + 1,
                        bColEnd - bColStart + 1);
}

static __inline int substractionZone(emxArray_real_T* a,
                                     emxArray_real_T* b,
                                     emxArray_real_T* r,
                                     int              bX,
                                     int              bY,
                                     int              bRow,
                                     int              bCol) {
    /*
     * A - B = R
     * |A B C|   |A B  C D E |
     * |D E F| - |F G |H I J||   |A B C|
     * |G H I|   |K L |M N O|| = |D E F|
     * |P Q |R S T||   |G H I|
     * |U V  W X Y |
     *
     * in this example: bX = 2, bY = 1, bRow = 3, bCol = 3
     */
    double  val;
    int     jumpZoneA, jumpZoneB, columnJumpB, pos, idxColB, idxRowB, rowB;
    double* a_data = a->data;
    double* b_data = b->data;
    double* r_data = r->data;

    if (a->size[0] != bRow || a->size[1] != bCol) {
        /* bad size */
        return 1;
    }

    rowB = b->size[0];
    /* loop column*/
    for (idxColB = 0; idxColB < bCol; idxColB++) {
        /* prepare jumping vars for zoning*/
        columnJumpB = idxColB * bRow;
        jumpZoneB   = (bX + idxColB) * rowB + bY;

        /* loop row*/
        for (idxRowB = 0; idxRowB < bRow; idxRowB++) {
            jumpZoneA = columnJumpB;
            pos       = idxRowB + jumpZoneA;

            /* compute, substraction */
            val = a_data[pos] - b_data[idxRowB + jumpZoneB];

            /* save */
            r_data[pos] = val;
        }
    }

    return 0;
}

static __inline int substractionZoneMatlab(emxArray_real_T* a,
                                           emxArray_real_T* b,
                                           emxArray_real_T* r,
                                           int              bRowStart,
                                           int              bRowEnd,
                                           int              bColStart,
                                           int              bColEnd) {
    /*
     * bX = colStart
     * bY = rowStart
     * bRow = rowEnd - rowStart + 1
     * bCol = colEnd - colStart + 1
     */
    return substractionZone(a, b, r, bColStart, bRowStart, bRowEnd - bRowStart + 1,
                            bColEnd - bColStart + 1);
}
#endif


#if 0
/**
 * we use this to convert from row-major (C) to column-major (Matlab ... fortran origin)
 * x is column or j in matrix term
 * y is row or i in matrix term
 **/
static __inline void transpose(double *src_, double *dest_, int y_, int x_) {
    int posNew;
    int posOld;
    int i;
    int j;

    for (j = 0; j < y_; j++) {
        for (i = 0; i < x_; i++) {
            posNew = j + y_*i;
            posOld = i + x_*j;

            dest_[posNew] = src_[posOld];
        }
    }
}

static __inline void rowMajorToColumnMajor(emxArray_real_T *src_, emxArray_real_T *dest_) {
    /* assume matrix are same size, checking will slow thing down */
    transpose(src_->data, dest_->data, src_->size[0], src_->size[1]);
}

static __inline void columMajorToRowMajor(emxArray_real_T *src_, emxArray_real_T *dest_) {
    transpose(src_->data, dest_->data, src_->size[1], src_->size[0]);
}
#endif

/* Function: mdlInitializeSizes ====================================================================
 * Abstract:
 *    The sizes information is used by Simulink to determine the S-function
 *    block's characteristics (number of inputs, outputs, states, etc.).
 */
static void mdlInitializeSizes(SimStruct* S) {
    int_T   nStates          = (int)mxGetM(A_PARAM(S));
    int_T   nInputs          = (int)mxGetN(B_PARAM(S));
    int_T   nOutputs         = (int)mxGetM(C_PARAM(S));
    int_T   nSwitch          = 0;
    int_T   EnableUseOfTLC   = 0;
    int_T   EnableDSS        = 1; /* DSS todo: params? */
    real_T* NonLinearDim     = (real_T*)(mxGetData(DSS_Dim_PARAM(S)));
    int_T   nNonLinear       = (int)mxGetM(DSS_Dim_PARAM(S));
    int_T   nABCD_NonLinear  = 0;
    int_T   nState_NonLinear = 0;


    real_T* NonLinearIterative = (real_T*)mxGetPr(DSS_Iterative_PARAM(S));

    if (ssGetSFcnParamsCount(S) > NPARAMS_NOSWITCH) {
        /* Circuit has switches */
        nSwitch = (int)mxGetN(RS_PARAM(S));
        ssSetNumSFcnParams(S, NPARAMS_WITHSWITCH);
    } else {
        /* Switchless circuit */
        ssSetNumSFcnParams(S, NPARAMS_NOSWITCH);
    }

#if defined(MATLAB_MEX_FILE)
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
        return; /* Parameter mismatch will be reported by Simulink */
    }
#endif

    /* Set tunability of parameters */

    ssSetSFcnParamTunable(S, TS_PARAM_IDX, 0);
    ssSetSFcnParamTunable(S, EnableUseOfTLC_PARAM_IDX, 0);
    /* OT Fev 2014: Due to scalability problem, we set those parameters as tunab < -
     * In practice, it will be impossible to change it during simulation*/

    /* test OT: non tunable */
    ssSetSFcnParamTunable(S, A_PARAM_IDX, 0);
    ssSetSFcnParamTunable(S, B_PARAM_IDX, 0);
    ssSetSFcnParamTunable(S, C_PARAM_IDX, 0);
    ssSetSFcnParamTunable(S, XO_PARAM_IDX, 0);


    ssSetSFcnParamTunable(S, D_PARAM_IDX, 0);

    ssSetSFcnParamTunable(S, DSS_Dim_PARAM_IDX, 0);
    ssSetSFcnParamTunable(S, DSS_xInit_PARAM_IDX, 0);
    ssSetSFcnParamTunable(S, DSS_Inputs_PARAM_IDX, 0);
    ssSetSFcnParamTunable(S, DSS_Outputs_PARAM_IDX, 0);
    ssSetSFcnParamTunable(S, DSS_InitialOutputs_PARAM_IDX, 0);
    ssSetSFcnParamTunable(S, DSS_Iterative_PARAM_IDX, 0);
    ssSetSFcnParamTunable(S, DSS_VI_PARAM_IDX, 0);
    ssSetSFcnParamTunable(S, DSS_VI_SIZE_PARAM_IDX, 0);
    ssSetSFcnParamTunable(S, DSS_Method_PARAM_IDX, 0);
    ssSetSFcnParamTunable(S, DSS_TOLERANCE_NONLINEAR_IDX, 0);
    ssSetSFcnParamTunable(S, DSS_NITER_NONLINEAR_MAX_IDX, 0);
    ssSetSFcnParamTunable(S, DSS_CONTINUE_ON_MAX_ITERATION_IDX, 0);

    if (nSwitch) {
        ssSetSFcnParamTunable(S, RS_PARAM_IDX, 0);
        ssSetSFcnParamTunable(S, SWT_PARAM_IDX, 0);
        ssSetSFcnParamTunable(S, GIV_PARAM_IDX, 0);
        ssSetSFcnParamTunable(S, YISW_PARAM_IDX, 0);
        ssSetSFcnParamTunable(S, TBEON_PARAM_IDX, 0);
    }

    ssSetNumContStates(S, 0);

    /* deplace + bas, besoin de nstate tot */
    /*ssSetNumDiscStates(S, nStates);*/

    /* U, gate, Dss always there*/
    if (!ssSetNumInputPorts(S, 3)) {
        return;
    }

    /* set taille de u0 */
    ssSetInputPortWidth(S, 0, nInputs);
    ssSetInputPortDirectFeedThrough(S, 0, 1);

    /* set taille u1 */
    if (nSwitch) {
        ssSetInputPortWidth(S, 1, nSwitch);
        /*ssSetInputPortDirectFeedThrough(S, 1, 1);*/
        ssSetInputPortDirectFeedThrough(S, 1, 0);
    } else {
        ssSetInputPortWidth(S, 1, 1); /* dummy input*/
        /*ssSetInputPortDirectFeedThrough(S, 1, 1);*/
        ssSetInputPortDirectFeedThrough(S, 1, 0);
    }

    if (nNonLinear) {
        int_T nABCD_NonLinear = 0;
        int_T i               = 0;

        for (i = 0; i < nNonLinear; i++) {
            int_T Nx = (int_T)NonLinearDim[i];
            int_T Nu = (int_T)NonLinearDim[i + nNonLinear];
            int_T Ny = (int_T)NonLinearDim[i + nNonLinear * 2];
            nABCD_NonLinear += Nu * Ny;
            nState_NonLinear += Nx * (int_T)NonLinearIterative[i];
        }

        /* set taille u2*/
        ssSetInputPortWidth(S, 2, nABCD_NonLinear);
        ssSetInputPortDirectFeedThrough(S, 2, 1); /*TODO verifier*/
    } else {
        ssSetInputPortWidth(S, 2, 1); /* dummy input */
        ssSetInputPortDirectFeedThrough(S, 2, 1);
    }
    /*
     * // set input writeable
     * // if you do this, the input can only be used in mdloutputs function
     * //ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_GLOBAL); // U0
     * //ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_GLOBAL); // U1
     * //ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_GLOBAL); // U2
     */
    ssSetNumDiscStates(S, nStates);

    if (!ssSetNumOutputPorts(S, 3)) {
        return;
    }

    ssSetOutputPortWidth(S, 0, nOutputs);

    if (nSwitch) {
        ssSetOutputPortWidth(S, 1, nSwitch);
    } else {
        ssSetOutputPortWidth(S, 1, 1); /* dummy output */
    }

    if (nState_NonLinear) {
        ssSetOutputPortWidth(S, 2, nState_NonLinear);
    } else {
        ssSetOutputPortWidth(S, 2, 1); /* dummy output */
    }

    ssSetNumSampleTimes(S, 1);
    ssSetNumRWork(S, N_RWORKS);
    ssSetNumIWork(S, N_IWORKS);
    ssSetNumPWork(S, N_PWORKS);
    ssSetNumModes(S, 0);
    ssSetNumNonsampledZCs(S, 0);

    /* Take care when specifying exception free code - see sfuntmpl_doc.c */
    /*    test OT
     * EnableUseOfTLC = (int_T)*((real_T *)mxGetPr(EnableUseOfTLC_PARAM(S)));
     *
     * if (EnableUseOfTLC == 1)
     * {
     * ssSetOptions(S, (SS_OPTION_USE_TLC_WITH_ACCELERATOR | SS_OPTION_EXCEPTION_FREE_CODE |
     * SS_OPTION_WORKS_WITH_CODE_REUSE));
     * }
     * else
     * {
     * ssSetOptions(S, (SS_OPTION_EXCEPTION_FREE_CODE | SS_OPTION_WORKS_WITH_CODE_REUSE));
     * }
     */
    ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE);
    /*
     * //    ssSetSimStateCompliance(S, USE_CUSTOM_SIM_STATE);
     */
    ssSupportsMultipleExecInstances(S, true);
}


/* Function: mdlInitializeSampleTimes */
static void mdlInitializeSampleTimes(SimStruct* S) {
    real_T* Ts = (real_T*)mxGetPr(TS_PARAM(S));

    ssSetSampleTime(S, 0, *Ts);
    ssSetOffsetTime(S, 0, 0.0);
}

#undef MDL_SET_WORK_WIDTHS /* Change to #undef to remove function */
#if defined(MDL_SET_WORK_WIDTHS) && defined(MATLAB_MEX_FILE)
/* Function: mdlSetWorkWidths ======================================================================
 * Abstract:
 *      Set up run-time parameters.
 */
static void mdlSetWorkWidths(SimStruct* S) {
    int_T nStates = (int)mxGetM(A_PARAM(S));
}
#endif /* MDL_SET_WORK_WIDTHS */

static const char* allocErrorMess = "Memory allocation error in mdlStart";

static void* sf_alloc(SimStruct* S, size_t num_elem, size_t elem_size) {
    if (ssGetErrorStatus(S) == (char_T*)0 && num_elem > 0 && elem_size > 0) {
        void* mem = calloc(num_elem, elem_size);

        if (mem == (void*)0) {
            ssSetErrorStatus(S, allocErrorMess);
        }

        return mem;
    } else {
        return (void*)0;
    }
}

#define MDL_START
#if defined(MDL_START)

static const char* badSwTypeMess = "Switch types must be from 1 to 7!!!";
static const char* badImIdxMess =
    "A switch current measure index is greater than the number of block outputs!!!";

static void mdlStart(SimStruct* S) {
    real_T* y         = ssGetOutputPortRealSignal(S, 0);
    real_T* y_xNonLin = ssGetOutputPortRealSignal(S, 2);

    int     i;
    real_T* As                 = NULL;
    real_T* Bs                 = NULL;
    real_T* Cs                 = NULL;
    real_T* Ds                 = NULL;
    real_T* DxCol              = NULL;
    real_T* BDcol              = NULL;
    real_T* tmp1               = NULL;
    real_T* tmp2               = NULL;
    real_T* uswlast            = NULL;
    real_T* xtmp               = NULL;
    real_T* xkm12              = NULL;
    real_T* xkp12              = NULL;
    real_T* xLast              = NULL;
    real_T* uLast              = NULL;
    int_T*  switch_status      = NULL;
    int_T*  switch_status_init = NULL;
    int_T*  SwitchChange       = NULL;
    int_T*  gate               = NULL;
    int_T*  idxSwChng          = NULL;
    real_T* yswitch            = NULL;
    int_T*  switchTypes        = NULL;
    int_T*  idxOutSw           = NULL;

    real_T* NonLinear_VI     = NULL;
    real_T* NonLinear_SizeVI = NULL;
    /*real_T		*NonLinearIterative = NULL;*/

    const int_T nNonLinear = (int)mxGetM(DSS_Dim_PARAM(S));

    const int_T nStates  = (int)mxGetM(A_PARAM(S));
    const int_T nInputs  = (int)mxGetN(B_PARAM(S));
    const int_T nOutputs = (int)mxGetM(C_PARAM(S));

    /* for DSS */
    int_T Ny1 = 0;
    int_T Nu1 = 0;
    /*int_T nStates_tot = nStates;*/
    int_T nNuNonLinear = 0;
    int_T nNxNonLinear = 0;
    int_T nNyNonLinear = 0;
    int_T sizeU        = 0;

    emxArray_real_T*  Y_NonLinearIterative      = NULL;
    emxArray_real_T*  Y_NonLinearIterative_last = NULL;
    emxArray_int32_T* StopIterNonLinear         = NULL;
    emxArray_real_T*  aseg                      = NULL;
    emxArray_real_T*  bseg                      = NULL;
    emxArray_int32_T* noseg                     = NULL;
    emxArray_int32_T* nosegLast                 = NULL;

    emxArray_real_T* uArray = NULL;

    emxArray_int32_T* NonLinearDimInt       = NULL;
    emxArray_int32_T* NonLinearInputsInt    = NULL;
    emxArray_int32_T* NonLinearOutputsInt   = NULL;
    emxArray_int32_T* NonLinearIterativeInt = NULL;
    emxArray_int32_T* NonLinearMethodInt    = NULL;

    emxArray_int32_T* NonLinearSizeVIInt = NULL;
    emxArray_real_T*  NonLinearVIReal    = NULL;



    emxArray_real_T* D_NonLinearDisc = NULL;

    emxArray_real_T* A_Global = NULL;
    emxArray_real_T* B_Global = NULL;
    emxArray_real_T* C_Global = NULL;
    emxArray_real_T* D_Global = NULL;

    emxArray_real_T*  d12d2       = NULL;
    emxArray_real_T*  eyeMatrix   = NULL;
    emxArray_real_T*  Wi12        = NULL;
    emxArray_real_T*  resultInv1  = NULL;
    emxArray_real_T*  resultInv2  = NULL;
    emxArray_real_T*  workingC1   = NULL;
    emxArray_real_T*  workingC2   = NULL;
    emxArray_real_T*  workingD1   = NULL;
    emxArray_real_T*  workingD2   = NULL;
    emxArray_real_T*  workingInv0 = NULL;
    emxArray_int32_T* workingInv1 = NULL;
    emxArray_int32_T* workingInv2 = NULL;

    emxArray_real_T* MMatrix = NULL;
    emxArray_real_T* result1 = NULL;
    emxArray_real_T* result2 = NULL;

    emxArray_int32_T* refRows       = NULL;
    emxArray_int32_T* refCols       = NULL;
    emxArray_real_T*  reshapeMatrix = NULL;

    emxArray_int32_T* NonLinearLsatInt = NULL;
    emxArray_real_T*  xDLsat           = NULL;

    /* pour conserver les courants historiques associes aux elements Lsat*/
    emxArray_real_T* U0_histLsat = NULL;

    emxArray_real_T* y_xNonLinArray = NULL;
    emxArray_real_T* yArray         = NULL;

    int_T   TBEon           = 0;
    int_T   nSwitch         = 0;
    real_T* switchTypeParam = NULL;
    real_T* I_MeasIdxs      = NULL;
    int_T   swt;

    /* pour conserver le premier temps de non-convergence */
    real_T timeNoSwitchConv = -1.0;

    if (ssGetSFcnParamsCount(S) > NPARAMS_NOSWITCH) {
        nSwitch         = (int)mxGetN(RS_PARAM(S));
        switchTypeParam = (real_T*)mxGetPr(SWT_PARAM(S));
        I_MeasIdxs      = (real_T*)mxGetPr(YISW_PARAM(S));
        TBEon           = (int)mxGetScalar(TBE_ON(S));
    }

#ifdef DEBUG
    mexPrintf("mdlStart:\n");
    mexPrintf("nInputs = %d\n", nInputs);
    mexPrintf("nOutputs = %d\n", nOutputs);
    mexPrintf("nStates = %d\n", nStates);
    mexPrintf("nSwitch = %d\n", nSwitch);
#endif


    /* Verify switches types and switches current measures indexes */

    for (i = 0; i < nSwitch; ++i) {
        swt = (int_T)switchTypeParam[i];

#ifdef DEBUG
        mexPrintf("Switch %d type: %d\n", i, swt);
#endif

        if (swt < 1 || swt > 7) {
            ssSetErrorStatus(S, badSwTypeMess);
            return;
        }

        if (I_MeasIdxs[i] > nOutputs) {
            ssSetErrorStatus(S, badImIdxMess);
            return;
        }
    }


    As = (real_T*)sf_alloc(S, nStates * nStates, sizeof(real_T));
    Bs = (real_T*)sf_alloc(S, nStates * nInputs, sizeof(real_T));
    Cs = (real_T*)sf_alloc(S, nOutputs * nStates, sizeof(real_T));
    Ds = (real_T*)sf_alloc(S, nOutputs * nInputs, sizeof(real_T));

    DxCol = (real_T*)sf_alloc(S, nOutputs, sizeof(real_T));
    BDcol = (real_T*)sf_alloc(S, nStates, sizeof(real_T));
    tmp1  = (real_T*)sf_alloc(S, nStates, sizeof(real_T));
    tmp2  = (real_T*)sf_alloc(S, nInputs, sizeof(real_T));
    /*	xtmp           = (real_T*)sf_alloc(S, nStates,sizeof(real_T));*/


    /* Le data de ces matrices existe  deja  (As, Bs, Cs, Ds): pas d'allocation de mem */
    /* on fait un creat soon, car on va mettre le data direct dedans ... soon*/
    A_Global = emxCreateWrapper_real_T(As, nStates, nStates);  /* TODO  nbSwitch_topo??*/
    B_Global = emxCreateWrapper_real_T(Bs, nStates, nInputs);  /* TODO  nbSwitch_topo??*/
    C_Global = emxCreateWrapper_real_T(Cs, nOutputs, nStates); /* TODO  nbSwitch_topo??*/
    D_Global = emxCreateWrapper_real_T(Ds, nOutputs, nInputs); /* TODO  nbSwitch_topo??*/

    U0_histLsat = emxCreate_real_T(nInputs, 1);

    if (nNonLinear) {
        /*
         * // ex : |0 1 1|  Nx Nu Ny
         * //      |0 4 4|
         */
        real_T* NonLinearDim = (real_T*)(mxGetData(DSS_Dim_PARAM(S)));

        real_T* NonLinear_Inputs = (real_T*)mxGetPr(DSS_Inputs_PARAM(S));

        real_T* NonLinear_Outputs = (real_T*)mxGetPr(DSS_Outputs_PARAM(S));

        real_T* NonLinearIterative = (real_T*)mxGetPr(DSS_Iterative_PARAM(S));

        real_T* NonLinear_MethodTest = (real_T*)mxGetPr(DSS_Method_PARAM(S));

        int_T nRow_NL_VI = (int_T)mxGetM(DSS_VI_PARAM(S));

        int_T  i    = 0;
        int_T  k    = 0;
        int_T  nSeg = 0;
        int_T  Nu = 0, Ny = 0, Nx = 0;
        real_T Ymin = 0.0, Y = 0.0;
        real_T V1 = 0.0, V2 = 0.0, I1 = 0.0, I2 = 0.0;
        int_T  nStates_NonLinear = 0;
        int_T  nOffsetVI         = 0;
        int_T  nRow, nCol, max;

        /* pour creer matrice au maximum requis */
        int_T maxNu = 0;
        int_T maxNy = 0;

        /*
         * // prepare stuff for SolveNonLinearIterativeElement_New()
         */
        NonLinear_VI = (real_T*)mxGetPr(DSS_VI_PARAM(S));
        nRow         = (int_T)mxGetM(DSS_VI_PARAM(S));

        NonLinear_SizeVI = (real_T*)mxGetPr(DSS_VI_SIZE_PARAM(S));
        /*NonLinearIterative = (real_T*)mxGetPr(DSS_Iterative_PARAM(S));*/

        NonLinearVIReal = emxCreateWrapper_real_T(NonLinear_VI, nRow, 2);



        /* calloc under the hood, so 0 everywhere :)*/
        Y_NonLinearIterative      = emxCreate_real_T(1, nNonLinear);
        Y_NonLinearIterative_last = emxCreate_real_T(1, nNonLinear);
        StopIterNonLinear         = emxCreate_int32_T(1, nNonLinear);

        /*
         * // NonLinearDimInt
         * // ================
         * // ex : |0 1 1|  Nx Nu Ny
         * //      |0 4 4|
         */
        NonLinearDimInt = emxCreate_int32_T(nNonLinear, 3);
        /* fill it up!*/
        max = 3 * nNonLinear;
        for (i = 0; i < max; i++) {
            NonLinearDimInt->data[i] = (int_T)NonLinearDim[i];
        }

        /*
         * // size of Uarray, nNuNonLinear & nNyNonLinear,
         * // ============================================
         */
        sizeU        = 0;
        nNuNonLinear = 0;
        nNyNonLinear = 0;
        for (i = 0; i < nNonLinear; i++) {
            Nx = NonLinearDimInt->data[i];
            nNxNonLinear += Nx * (int_T)NonLinearIterative[i];

            Nu = NonLinearDimInt->data[i + nNonLinear];
            nNuNonLinear += Nu;
            if (Nu > maxNu) {
                maxNu = Nu;
            }

            Ny = NonLinearDimInt->data[i + nNonLinear * 2];
            nNyNonLinear += Ny;
            if (Ny > maxNy) {
                maxNy = Ny;
            }

            /*sizeU = sizeU + (Nx + Nu) * (Nx + Ny);*/
            sizeU = sizeU + Nu * Ny;
        }

        /* creation xDLsat */
        xDLsat = emxCreate_real_T(nNxNonLinear, 1);

        /* creation nonlinLsat vector*/
        NonLinearLsatInt = emxCreate_int32_T(nNxNonLinear, 1);

        k = 0;
        /* scan pour les elements lsat present*/
        for (i = 0; i < nNonLinear; i++) {
            Nx = NonLinearDimInt->data[i];

            if (Nx > 0 && (int_T)NonLinearIterative[i] > 0) {
                /* on conserve la position (dans NonLinearDimInt) de l'element lsat dans le vecteur
                 * NonLinearLsat*/
                NonLinearLsatInt->data[k++] = i;
            }
        }

        /* wrap output*/
        y_xNonLinArray = emxCreateWrapper_real_T(y_xNonLin, nNxNonLinear, 1);
        yArray         = emxCreateWrapper_real_T(y, nOutputs, 1);


        Ny1 = nOutputs - nNuNonLinear;
        Nu1 = nInputs - nNyNonLinear;

        D_NonLinearDisc = emxCreate_real_T(nInputs - Nu1, nOutputs - Ny1);

        /* creer reshapeMatrix, refRows et refCols avec les max */
        refRows       = emxCreate_int32_T(1, maxNy);
        refCols       = emxCreate_int32_T(1, maxNu);
        reshapeMatrix = emxCreate_real_T(maxNy, maxNu);

        /* TEST_C pour tester multiplication matrice en C*/
        d12d2       = emxCreate_real_T(nOutputs, nNuNonLinear);
        eyeMatrix   = emxCreate_real_T(nOutputs - Ny1, nOutputs - Ny1); /* same as nNuNonLinear*/
        Wi12        = emxCreate_real_T(Ny1, nNuNonLinear);
        resultInv1  = emxCreate_real_T(nNuNonLinear, nNuNonLinear);
        resultInv2  = emxCreate_real_T(nNuNonLinear, nNuNonLinear);
        workingC1   = emxCreate_real_T(Ny1, nStates);
        workingC2   = emxCreate_real_T(nNuNonLinear, nStates);
        workingD1   = emxCreate_real_T(Ny1, nInputs);
        workingD2   = emxCreate_real_T(nNuNonLinear, nInputs);
        workingInv0 = emxCreate_real_T(nNuNonLinear, nNuNonLinear);
        workingInv1 = emxCreate_int32_T(1, nNuNonLinear);
        workingInv2 = emxCreate_int32_T(1, nNuNonLinear);

        MMatrix = emxCreate_real_T(nStates, nOutputs - Ny1);
        result1 = emxCreate_real_T(nStates, nStates);
        result2 = emxCreate_real_T(nStates, nInputs);

        uArray = emxCreate_real_T(sizeU, 1);
        /*Wi = emxCreate_real_T(nOutputs, nOutputs); */
        /*
         * // matrice de taille nOutputs x nOutputs
         * // on doit mettre une diagonale de 1 mais sur une dimension + petite, Ny1
         * // ex: nOuputs = 5 et Ny1 = 3
         * //
         * //  1 0 0 0 0
         * //  0 1 0 0 0
         * //  0 0 1 0 0
         * //  0 0 0 0 0
         * //  0 0 0 0 0
         * //             0             6             12
         * // im memory { 1 0 0 0 0 / 0 1 0 0 0 / 0 0 1 0 0 / 0 0 0 0 0 / 0 0 0 0 0 }
         * // i + i * nOutputs
         * // i + 5i
         * // i = 0 -> 0 + 5*0 = 0
         * //     1 -> 1 + 5*1 = 6
         * //     2 -> 2 + 5*2 = 12
         */

        /* eye matrix, juste des 0, on met les 1 sur la diagonale*/
        for (i = 0; i < eyeMatrix->size[0]; i++) {
            eyeMatrix->data[i + eyeMatrix->size[0] * i] = 1.0;
        }

        /*
         * // NonLinearInputs
         * // ========================
         * // get number or row and col
         */
        nRow               = (int_T)mxGetM(DSS_Inputs_PARAM(S));
        nCol               = (int_T)mxGetN(DSS_Inputs_PARAM(S));
        max                = nRow * nCol;
        NonLinearInputsInt = emxCreate_int32_T(nRow, nCol);
        for (i = 0; i < max; i++) {
            NonLinearInputsInt->data[i] = (int_T)NonLinear_Inputs[i];
        }

        /*
         * // NonLinearOutputs
         * // ================
         * // get number or row and col
         */
        nRow = (int)mxGetM(DSS_Outputs_PARAM(S));
        nCol = (int)mxGetN(DSS_Outputs_PARAM(S));
        max  = nRow * nCol;

        NonLinearOutputsInt = emxCreate_int32_T(nRow, nCol);
        for (i = 0; i < max; i++) {
            NonLinearOutputsInt->data[i] = (int_T)NonLinear_Outputs[i];
        }

        /*
         * // NonLinearIterative
         * // ===================
         */
        nRow = (int)mxGetM(DSS_Iterative_PARAM(S));
        /*nCol = (int)mxGetN(DSS_Iterative_PARAM(S));*/
        /*NonLinearIterativeInt32 = emxCreateWrapper_int32_T(NonLinearIterative, nRow, nCol);*/
        NonLinearIterativeInt = emxCreate_int32_T(nRow, 1);
        for (i = 0; i < nRow; i++) {
            NonLinearIterativeInt->data[i] = (int_T)NonLinearIterative[i];
        }

        /*
         * // NonLinearMethod
         * // ================
         * // on a change ca pour des 1 et des 2 au lieu de 'tustin' et 'backward-euler'
         * // la taille est nNonLinear
         */
        NonLinearMethodInt = emxCreate_int32_T(nNonLinear, 1);
        for (i = 0; i < nNonLinear; i++) {
            NonLinearMethodInt->data[i] = (int_T)NonLinear_MethodTest[i];
        }

        /* NonLInearSizeVI*/
        NonLinearSizeVIInt = emxCreate_int32_T(nNonLinear, 1);
        for (i = 0; i < nNonLinear; i++) {
            NonLinearSizeVIInt->data[i] = (int_T)NonLinear_SizeVI[i];
        }

        aseg      = emxCreate_real_T(1, nNonLinear);
        bseg      = emxCreate_real_T(1, nNonLinear);
        noseg     = emxCreate_int32_T(1, nNonLinear);
        nosegLast = emxCreate_int32_T(1, nNonLinear);

        /* not used*/
        /*nosegLast = emxCreate_int32_T(1, nNonLinear);*/

#if 0
        nOffsetVI = 0;
        for (i = 0; i < nNonLinear; i++) {
            if (NonLinearIterative[i]) {
                /*
                 * // on fonctionne en segment, on prend le pt et le pt suivant,
                 * // il faut donc arreter a l'avant dernier
                 */
                nSeg = (int_T)NonLinear_SizeVI[i] - 1;
                Ymin = 1e37;

                /*
                 * // remember we are in column-major, VI table and table with number of pts
                 * // ex:
                 * // |1 10|          |0|  -> taille = nNonLinear
                 * // |2 11|          |0|
                 * // |3 12|          |4|
                 * // |4 13|          |2|
                 * // |5 14|
                 * // |6 15|
                 * //
                 * // {1 2 3 4 5 6 10 11 12 13 14 15}  et {0 0 4 2}
                 * // dans cet exemple, les 2 premierers valeurs de i sont 0, pas vriament de loop
                 * // ensuite on loop 4 pts (3 segments) et le dernier 2pts (d'ou le nombre total de row a 6)
                 */
                for (k = 0; k < nSeg; k++) {
                    V1 = NonLinear_VI[nOffsetVI + k];
                    I1 = NonLinear_VI[nOffsetVI + k + nRow_NL_VI];
                    /* pt suivant*/
                    V2 = NonLinear_VI[nOffsetVI + k + 1];
                    I2 = NonLinear_VI[nOffsetVI + k + 1 + nRow_NL_VI];

                    Y = (I2 - I1) / (V2 - V1);

                    if (Y < Ymin) {
                        Ymin = Y;

                        /* noseg et nosegLast utilisent 0-based indexing (1er segment -> noseg=0 */
                        noseg->data[i] = k ;
                        nosegLast->data[i] = k;

                        Y_NonLinearIterative->data[i] = Ymin;

                        aseg->data[i] = (V2 - V1) / (I2 - I1);
                        bseg->data[i] = V1 - aseg->data[i] * I1;
                    }
                }
            } else {
                /* element non iteratif*/
                StopIterNonLinear->data[i] = 1;
            }
            nOffsetVI += (int_T)NonLinear_SizeVI[i];
        }
#endif

    }

    else {

        A_Global = emxCreateWrapper_real_T(As, nStates, nStates);  /* TODO  nbSwitch_topo??*/
        B_Global = emxCreateWrapper_real_T(Bs, nStates, nInputs);  /* TODO  nbSwitch_topo??*/
        C_Global = emxCreateWrapper_real_T(Cs, nOutputs, nStates); /* TODO  nbSwitch_topo??*/
        D_Global = emxCreateWrapper_real_T(Ds, nOutputs, nInputs); /* TODO  nbSwitch_topo??*/
    }

    xtmp = (real_T*)sf_alloc(S, nStates, sizeof(real_T));



    if (TBEon) {

        xkm12 = (real_T*)sf_alloc(S, nStates, sizeof(real_T));
        xkp12 = (real_T*)sf_alloc(S, nStates, sizeof(real_T));
        xLast = (real_T*)sf_alloc(S, nStates, sizeof(real_T));
        uLast = (real_T*)sf_alloc(S, nInputs, sizeof(real_T));
    }

    if (nSwitch) {
        switch_status      = (int_T*)sf_alloc(S, nSwitch, sizeof(int_T));
        switch_status_init = (int_T*)sf_alloc(S, nSwitch, sizeof(int_T));
        SwitchChange       = (int_T*)sf_alloc(S, nSwitch, sizeof(int_T));
        gate               = (int_T*)sf_alloc(S, nSwitch, sizeof(int_T));
        idxSwChng          = (int_T*)sf_alloc(S, nSwitch, sizeof(int_T));
        yswitch            = (real_T*)sf_alloc(S, nSwitch, sizeof(real_T));
        switchTypes        = (int_T*)sf_alloc(S, nSwitch, sizeof(int_T));
        idxOutSw           = (int_T*)sf_alloc(S, nSwitch, sizeof(int_T));
        uswlast            = (real_T*)sf_alloc(S, nSwitch, sizeof(real_T));
    }

    if (ssGetErrorStatus(S) != NULL) {
        return;
    }

    ssSetPWorkValue(S, AS, As);
    ssSetPWorkValue(S, BS, Bs);
    ssSetPWorkValue(S, CS, Cs);
    ssSetPWorkValue(S, DS, Ds);
    ssSetPWorkValue(S, DX_COL, DxCol);
    ssSetPWorkValue(S, BD_COL, BDcol);
    ssSetPWorkValue(S, TMP1, tmp1);
    ssSetPWorkValue(S, TMP2, tmp2);
    ssSetPWorkValue(S, XTMP, xtmp);

    ssSetPWorkValue(S, XKM12, xkm12);
    ssSetPWorkValue(S, XKP12, xkp12);
    ssSetPWorkValue(S, XLAST, xLast);
    ssSetPWorkValue(S, ULAST, uLast);

    ssSetPWorkValue(S, SWITCH_STATUS, switch_status);
    ssSetPWorkValue(S, SWITCH_STATUS_INIT, switch_status_init);
    ssSetPWorkValue(S, SW_CHG, SwitchChange);
    ssSetPWorkValue(S, G_STATE, gate);
    ssSetPWorkValue(S, IDX_SW_CHG, idxSwChng);
    ssSetPWorkValue(S, Y_SWITCH, yswitch);
    ssSetPWorkValue(S, SWITCH_TYPES, switchTypes);
    ssSetPWorkValue(S, IDX_OUT_SW, idxOutSw);
    ssSetPWorkValue(S, USWLAST, uswlast);

    ssSetIWorkValue(S, NSTATES, nStates);
    ssSetIWorkValue(S, NINPUT, nInputs);
    ssSetIWorkValue(S, NOUTPUT, nOutputs);
    ssSetIWorkValue(S, NSWITCH, nSwitch);

    ssSetIWorkValue(S, NSTATES_NSTATES, nStates * nStates);
    ssSetIWorkValue(S, NSTATES_NINPUTS, nStates * nInputs);
    ssSetIWorkValue(S, NOUTPUTS_NSTATES, nOutputs * nStates);
    ssSetIWorkValue(S, NOUTPUTS_NINPUTS, nOutputs * nInputs);
    ssSetIWorkValue(S, NU1, Nu1);
    ssSetIWorkValue(S, NY1, Ny1);

    ssSetPWorkValue(S, D_NONLINEAR_DISC, D_NonLinearDisc);

    ssSetPWorkValue(S, A_GLOBAL, A_Global);
    ssSetPWorkValue(S, B_GLOBAL, B_Global);
    ssSetPWorkValue(S, C_GLOBAL, C_Global);
    ssSetPWorkValue(S, D_GLOBAL, D_Global);

    ssSetPWorkValue(S, D12D2, d12d2);
    ssSetPWorkValue(S, EYEMATRIX, eyeMatrix);
    ssSetPWorkValue(S, WI12, Wi12);
    ssSetPWorkValue(S, RESULTINV1, resultInv1);
    ssSetPWorkValue(S, RESULTINV2, resultInv2);
    ssSetPWorkValue(S, WORKINGC1, workingC1);
    ssSetPWorkValue(S, WORKINGC2, workingC2);
    ssSetPWorkValue(S, WORKINGD1, workingD1);
    ssSetPWorkValue(S, WORKINGD2, workingD2);
    ssSetPWorkValue(S, WORKINGINV0, workingInv0);
    ssSetPWorkValue(S, WORKINGINV1, workingInv1);
    ssSetPWorkValue(S, WORKINGINV2, workingInv2);
    ssSetPWorkValue(S, MMATRIX, MMatrix);
    ssSetPWorkValue(S, RESULT1, result1);
    ssSetPWorkValue(S, RESULT2, result2);
    ssSetPWorkValue(S, REFROWS, refRows);
    ssSetPWorkValue(S, REFCOLS, refCols);
    ssSetPWorkValue(S, RESHAPEMATRIX, reshapeMatrix);

    ssSetPWorkValue(S, Y_NONLINEAR_ITERATIVE, Y_NonLinearIterative);
    ssSetPWorkValue(S, Y_NONLINEAR_ITERATIVE_LAST, Y_NonLinearIterative_last);
    ssSetPWorkValue(S, STOP_ITER_NONLINEAR, StopIterNonLinear);
    ssSetPWorkValue(S, NONLINEAR_DIM, NonLinearDimInt);
    ssSetPWorkValue(S, NONLINEAR_INPUTS, NonLinearInputsInt);
    ssSetPWorkValue(S, NONLINEAR_OUTPUTS, NonLinearOutputsInt);
    ssSetPWorkValue(S, NONLINEAR_ITERATIVE, NonLinearIterativeInt);
    ssSetPWorkValue(S, NONLINEAR_METHOD, NonLinearMethodInt);
    ssSetPWorkValue(S, NONLINEAR_SIZE_VI, NonLinearSizeVIInt);
    ssSetPWorkValue(S, NONLINEAR_VI, NonLinearVIReal);
    ssSetPWorkValue(S, ASEG, aseg);
    ssSetPWorkValue(S, BSEG, bseg);
    ssSetPWorkValue(S, NOSEG, noseg);
    ssSetPWorkValue(S, NOSEG_LAST, nosegLast);

    ssSetPWorkValue(S, U_ARRAY, uArray);
    ssSetPWorkValue(S, NONLINEAR_LSAT, NonLinearLsatInt);
    ssSetPWorkValue(S, XD_LSAT, xDLsat);
    ssSetPWorkValue(S, U0_HIST_LSAT, U0_histLsat);
    ssSetPWorkValue(S, Y_X_NONLINEAR, y_xNonLinArray);
    ssSetPWorkValue(S, Y_ARRAY, yArray);

    ssSetIWorkValue(S, NSTEP, 0);

    ssSetRWorkValue(S, TIME_NO_SWITCH_CONV, timeNoSwitchConv);
}
#endif /* MDL_START */

#define MDL_INITIALIZE_CONDITIONS
/* Function: mdlInitializeConditions ===================================== */

static void mdlInitializeConditions(SimStruct* S) {
    real_T* x0  = (real_T*)mxGetPr(XO_PARAM(S));
    real_T* apr = (real_T*)mxGetPr(A_PARAM(S));
    real_T* bpr = (real_T*)mxGetPr(B_PARAM(S));
    real_T* cpr = (real_T*)mxGetPr(C_PARAM(S));
    real_T* dpr = (real_T*)mxGetPr(D_PARAM(S));
    real_T* xD  = (real_T*)ssGetRealDiscStates(S);

    real_T* xkp12 = (real_T*)ssGetPWorkValue(S, XKP12);
    real_T* xLast = (real_T*)ssGetPWorkValue(S, XLAST);
    real_T* uLast = (real_T*)ssGetPWorkValue(S, ULAST);

    real_T* As      = (real_T*)ssGetPWorkValue(S, AS);
    real_T* Bs      = (real_T*)ssGetPWorkValue(S, BS);
    real_T* Cs      = (real_T*)ssGetPWorkValue(S, CS);
    real_T* Ds      = (real_T*)ssGetPWorkValue(S, DS);
    real_T* uswlast = (real_T*)ssGetPWorkValue(S, USWLAST);

    real_T* NonLinear_SizeVI   = (real_T*)mxGetPr(DSS_VI_SIZE_PARAM(S));
    real_T* NonLinearIterative = (real_T*)mxGetPr(DSS_Iterative_PARAM(S));
    int_T   nRow_NL_VI         = (int_T)mxGetM(DSS_VI_PARAM(S));

    emxArray_int32_T* noseg     = (emxArray_int32_T*)ssGetPWorkValue(S, NOSEG);
    emxArray_int32_T* nosegLast = (emxArray_int32_T*)ssGetPWorkValue(S, NOSEG_LAST);
    emxArray_real_T*  aseg      = (emxArray_real_T*)ssGetPWorkValue(S, ASEG);
    emxArray_real_T*  bseg      = (emxArray_real_T*)ssGetPWorkValue(S, BSEG);
    emxArray_real_T*  Y_NonLinearIterative =
        (emxArray_real_T*)ssGetPWorkValue(S, Y_NONLINEAR_ITERATIVE);
    emxArray_int32_T* StopIterNonLinear =
        (emxArray_int32_T*)ssGetPWorkValue(S, STOP_ITER_NONLINEAR);
    emxArray_real_T* NonLinearVIReal = (emxArray_real_T*)ssGetPWorkValue(S, NONLINEAR_VI);
    emxArray_real_T* D_NonLinearDisc = (emxArray_real_T*)ssGetPWorkValue(S, D_NONLINEAR_DISC);
    emxArray_real_T* Y_NonLinearIterative_last =
        (emxArray_real_T*)ssGetPWorkValue(S, Y_NONLINEAR_ITERATIVE_LAST);
    emxArray_real_T* U0_histLsat = (emxArray_real_T*)ssGetPWorkValue(S, U0_HIST_LSAT);

    const int_T nStates    = ssGetIWorkValue(S, NSTATES);
    const int_T nInputs    = ssGetIWorkValue(S, NINPUT);
    const int_T nOutputs   = ssGetIWorkValue(S, NOUTPUT);
    const int_T nSwitch    = ssGetIWorkValue(S, NSWITCH);
    const int_T nNonLinear = (int)mxGetM(DSS_Dim_PARAM(S));


#ifdef DEBUG
    int_T*  sw_topo_count = (int_T*)ssGetPWorkValue(S, SWITCH_TOPO_COUNT);
    real_T* sw_topo_time  = (real_T*)ssGetPWorkValue(S, SWITCH_TOPO_TIME);
#endif

    int_T  TBEon     = 0;
    int_T  nOffsetVI = 0;
    int_T  i;
    int_T  k;
    int_T  nSeg = 0;
    real_T Ymin = 0.0;
    real_T Y    = 0.0;
    real_T V1   = 0.0;
    real_T V2   = 0.0;
    real_T I1   = 0.0;
    real_T I2   = 0.0;

    /* initialize to zero (for fast restart) even if creation with 0s at mdlStart was done */
    memset(D_NonLinearDisc->data, '\0', D_NonLinearDisc->allocatedSize * sizeof(real_T));
    memset(Y_NonLinearIterative_last->data, '\0',
           Y_NonLinearIterative_last->allocatedSize * sizeof(real_T));
    memset(U0_histLsat->data, '\0', U0_histLsat->allocatedSize * sizeof(real_T));

    /* initialize inital states */
    memcpy(xD, x0, nStates * sizeof(real_T));
    /*
     * // NEW
     * // for now use the As Bs Cs & Ds
     * // keep the column-major array info
     * // copy data stupid way at first
     */

    for (i = 0; i < (nStates * nStates); i++) {
        As[i] = apr[i];
    }

    for (i = 0; i < (nStates * nInputs); i++) {
        Bs[i] = bpr[i];
    }

    /*
     * // NEW
     * // keep the Column-Major memory order
     */
    for (i = 0; i < (nOutputs * nStates); i++) {
        Cs[i] = cpr[i];
    }

    for (i = 0; i < (nOutputs * nInputs); i++) {
        Ds[i] = dpr[i];
    }

    if (nSwitch) {
        /* Switches parameters */

        const real_T* rsw             = (real_T*)mxGetPr(RS_PARAM(S));
        const real_T* switchTypeParam = (real_T*)mxGetPr(SWT_PARAM(S));
        const real_T* giv             = (real_T*)mxGetPr(GIV_PARAM(S));
        const real_T* etas            = (real_T*)mxGetPr(YISW_PARAM(S));

        /* Switches work vectors */

        int_T*  switch_status      = (int_T*)ssGetPWorkValue(S, SWITCH_STATUS);
        int_T*  switch_status_init = (int_T*)ssGetPWorkValue(S, SWITCH_STATUS_INIT);
        int_T*  gate               = (int_T*)ssGetPWorkValue(S, G_STATE);
        real_T* yswitch            = (real_T*)ssGetPWorkValue(S, Y_SWITCH);
        int_T*  switchTypes        = (int_T*)ssGetPWorkValue(S, SWITCH_TYPES);
        int_T*  idxOutSw           = (int_T*)ssGetPWorkValue(S, IDX_OUT_SW);

        /* Initialize work vectors */

        for (i = 0; i < nSwitch; i++) {
            switch_status[i]      = 0;
            switch_status_init[i] = 0;
            gate[i]               = (int_T)giv[i]; /* Initial gate state */
            yswitch[i]            = 1 / rsw[i];
            switchTypes[i]        = (int_T)switchTypeParam[i];
            idxOutSw[i] = ((int_T)etas[i]) - 1; /* Indexes of switch current measure outputs*/
            uswlast[i]  = 0.0;
        }

        TBEon = (int)mxGetScalar(TBE_ON(S));

        if (TBEon) {
            memcpy(xkp12, x0, nStates * sizeof(real_T));
            memcpy(xLast, x0, nStates * sizeof(real_T));
            memset(uLast, '\0', nInputs * sizeof(real_T));
        }
    }

    /* initalize non linear iterative elements */
    nOffsetVI = 0;
    for (i = 0; i < nNonLinear; i++) {
        if (NonLinearIterative[i]) {
            StopIterNonLinear->data[i] = 0;
            /*
             * // on fonctionne en segment, on prend le pt et le pt suivant,
             * // il faut donc arreter a l'avant dernier
             */
            nSeg = (int_T)NonLinear_SizeVI[i] - 1;
            Ymin = 1e37;

            /*
             * // remember we are in column-major, VI table and table with number of pts
             * // ex:
             * // |1 10|          |0|  -> taille = nNonLinear
             * // |2 11|          |0|
             * // |3 12|          |4|
             * // |4 13|          |2|
             * // |5 14|
             * // |6 15|
             * //
             * // {1 2 3 4 5 6 10 11 12 13 14 15}  et {0 0 4 2}
             * // dans cet exemple, les 2 premierers valeurs de i sont 0, pas vriament de loop
             * // ensuite on loop 4 pts (3 segments) et le dernier 2pts (d'ou le nombre total de row
             * a 6)
             */
            for (k = 0; k < nSeg; k++) {
                V1 = NonLinearVIReal->data[nOffsetVI + k];
                I1 = NonLinearVIReal->data[nOffsetVI + k + nRow_NL_VI];
                /* pt suivant*/
                V2 = NonLinearVIReal->data[nOffsetVI + k + 1];
                I2 = NonLinearVIReal->data[nOffsetVI + k + 1 + nRow_NL_VI];

                Y = (I2 - I1) / (V2 - V1);

                if (Y < Ymin) {
                    Ymin = Y;

                    /* noseg et nosegLast utilisent 0-based indexing (1er segment -> noseg=0 */
                    noseg->data[i]     = k;
                    nosegLast->data[i] = k;

                    Y_NonLinearIterative->data[i] = Ymin;

                    aseg->data[i] = (V2 - V1) / (I2 - I1);
                    bseg->data[i] = V1 - aseg->data[i] * I1;
                }
            }
        } else {
            /* element non iteratif*/
            StopIterNonLinear->data[i] = 1;
        }
        nOffsetVI += (int_T)NonLinear_SizeVI[i];
    }
}

/* Helper macros for switches signals */

#define V_SW(sw_idx) (y[(sw_idx)]) /* Switch voltage */
#define I_SW(sw_idx) (y[(sw_idx)]) /* Switch current */

/* True if switch voltage is > 0.0 */
#define V_SW_GT_ZERO(sw_idx) (V_SW(sw_idx) > 0.0)

/* True if switch voltage is < 0.0 */
#define V_SW_LT_ZERO(sw_idx) (V_SW(sw_idx) < 0.0)

/* True if switch current is > 0.0 */
#define I_SW_GT_ZERO(sw_idx) (I_SW(sw_idx) > 0.0)

/* True if switch current is < 0.0 */
#define I_SW_LT_ZERO(sw_idx) (I_SW(sw_idx) < 0.0)

/* Function: mdlOutputs ============================================================================
 * Abstract:
 *      y = Cx + Du
 */
static void mdlOutputs(SimStruct* S, int_T tid) {
    InputRealPtrsType u0Ptrs = ssGetInputPortRealSignalPtrs(S, 0);
    InputRealPtrsType u2Ptrs = ssGetInputPortRealSignalPtrs(S, 2);

    real_T* y         = ssGetOutputPortRealSignal(S, 0);
    real_T* y_xNonLin = ssGetOutputPortRealSignal(S, 2);
    real_T* xD        = ssGetRealDiscStates(S);
    int_T   xDSize    = ssGetNumDiscStates(S);
    /* TBE */
    int_T   TBEon = 0;
    real_T* xkm12 = (real_T*)ssGetPWorkValue(S, XKM12);
    real_T* xkp12 = (real_T*)ssGetPWorkValue(S, XKP12);
    real_T* xLast = (real_T*)ssGetPWorkValue(S, XLAST);
    real_T* uLast = (real_T*)ssGetPWorkValue(S, ULAST);

    real_T* Ts         = (real_T*)mxGetPr(TS_PARAM(S));
    int_T   nNonLinear = (int_T)mxGetM(DSS_Dim_PARAM(S)); /*TODO stocker dans le IWork*/

    /*TODO remove*/

    real_T time = ssGetT(S);

    const int_T nStates  = ssGetIWorkValue(S, NSTATES);
    const int_T nInputs  = ssGetIWorkValue(S, NINPUT);
    const int_T nOutputs = ssGetIWorkValue(S, NOUTPUT);
    const int_T nSwitch  = ssGetIWorkValue(S, NSWITCH);

    const int_T Ny1 = ssGetIWorkValue(S, NY1);
    const int_T Nu1 = ssGetIWorkValue(S, NU1);


    int_T nStep = ssGetIWorkValue(S, NSTEP);

    int_T nIterNonLinMax         = (int)mxGetScalar(DSS_NITER_NONLINEAR_MAX(S));
    int_T continueOnMaxIteration = (int)mxGetScalar(DSS_CONTINUE_ON_MAX_ITERATION(S));

    int_T stopCheck          = 0;
    int_T countIterNonLinear = 0;

    real_T tmp; /* variable utilis? pour conserver la pr?cision des multiplications-additions */
    real_T temp2;

    int_T SwitchesHaveChanged = 0; /* flag for Tustin / BE */

    /* to remove, once we put vals in linear matrix directly */
    real_T* As      = (real_T*)ssGetPWorkValue(S, AS);
    real_T* Bs      = (real_T*)ssGetPWorkValue(S, BS);
    real_T* Cs      = (real_T*)ssGetPWorkValue(S, CS);
    real_T* Ds      = (real_T*)ssGetPWorkValue(S, DS);
    real_T* uswlast = (real_T*)ssGetPWorkValue(S, USWLAST);

    /*
     * //number of non linear states   nNxNonLinear
     * //number of non linear outputs  nNyNonLinear
     * //number of non linear inputs   nNuNonLinear
     */
    int_T i, j, memPos;
    int_T D_NonLinearIsNotZero;
    /*real_T            accum;*/

    /*
    real_T            NonLinearIterTol = 1e-4;
    */
    real_T NonLinearIterTol = (real_T)mxGetScalar(DSS_TOLERANCE_NONLINEAR(S));

    emxArray_real_T* u0Array                      = NULL;
    emxArray_real_T* NonLinearxInitReal           = NULL;
    emxArray_real_T* NonLinear_InitialOutputsReal = NULL;

    real_T* NonLinear_Inputs  = NULL;
    real_T* NonLinear_Outputs = NULL;
    /*real_T             *NonLinearIterative = NULL;*/
    real_T* NonLinearxInit           = NULL;
    real_T* NonLinear_InitialOutputs = NULL;
    /*real_T            *NonLinear_VI = NULL;*/

    int_T*  NonLinear_Method     = NULL;
    real_T* NonLinear_MethodTest = NULL;
    /*real_T *ptr;*/

    emxArray_real_T* A_Global = (emxArray_real_T*)ssGetPWorkValue(S, A_GLOBAL);
    emxArray_real_T* B_Global = (emxArray_real_T*)ssGetPWorkValue(S, B_GLOBAL);
    emxArray_real_T* C_Global = (emxArray_real_T*)ssGetPWorkValue(S, C_GLOBAL);
    emxArray_real_T* D_Global = (emxArray_real_T*)ssGetPWorkValue(S, D_GLOBAL);

    emxArray_real_T* D_NonLinearDisc = (emxArray_real_T*)ssGetPWorkValue(S, D_NONLINEAR_DISC);

    emxArray_real_T*  d12d2         = (emxArray_real_T*)ssGetPWorkValue(S, D12D2);
    emxArray_real_T*  eyeMatrix     = (emxArray_real_T*)ssGetPWorkValue(S, EYEMATRIX);
    emxArray_real_T*  Wi12          = (emxArray_real_T*)ssGetPWorkValue(S, WI12);
    emxArray_real_T*  resultInv1    = (emxArray_real_T*)ssGetPWorkValue(S, RESULTINV1);
    emxArray_real_T*  resultInv2    = (emxArray_real_T*)ssGetPWorkValue(S, RESULTINV2);
    emxArray_real_T*  workingC1     = (emxArray_real_T*)ssGetPWorkValue(S, WORKINGC1);
    emxArray_real_T*  workingC2     = (emxArray_real_T*)ssGetPWorkValue(S, WORKINGC2);
    emxArray_real_T*  workingD1     = (emxArray_real_T*)ssGetPWorkValue(S, WORKINGD1);
    emxArray_real_T*  workingD2     = (emxArray_real_T*)ssGetPWorkValue(S, WORKINGD2);
    emxArray_real_T*  workingInv0   = (emxArray_real_T*)ssGetPWorkValue(S, WORKINGINV0);
    emxArray_int32_T* workingInv1   = (emxArray_int32_T*)ssGetPWorkValue(S, WORKINGINV1);
    emxArray_int32_T* workingInv2   = (emxArray_int32_T*)ssGetPWorkValue(S, WORKINGINV2);
    emxArray_real_T*  MMatrix       = (emxArray_real_T*)ssGetPWorkValue(S, MMATRIX);
    emxArray_real_T*  result1       = (emxArray_real_T*)ssGetPWorkValue(S, RESULT1);
    emxArray_real_T*  result2       = (emxArray_real_T*)ssGetPWorkValue(S, RESULT2);
    emxArray_int32_T* refRows       = (emxArray_int32_T*)ssGetPWorkValue(S, REFROWS);
    emxArray_int32_T* refCols       = (emxArray_int32_T*)ssGetPWorkValue(S, REFCOLS);
    emxArray_real_T*  reshapeMatrix = (emxArray_real_T*)ssGetPWorkValue(S, RESHAPEMATRIX);

    emxArray_real_T* Y_NonLinearIterative =
        (emxArray_real_T*)ssGetPWorkValue(S, Y_NONLINEAR_ITERATIVE);
    emxArray_real_T* Y_NonLinearIterative_last =
        (emxArray_real_T*)ssGetPWorkValue(S, Y_NONLINEAR_ITERATIVE_LAST);
    emxArray_int32_T* StopIterNonLinearInt32 =
        (emxArray_int32_T*)ssGetPWorkValue(S, STOP_ITER_NONLINEAR);
    emxArray_int32_T* NonLinearDimInt32 = (emxArray_int32_T*)ssGetPWorkValue(S, NONLINEAR_DIM);
    emxArray_int32_T* NonLinear_InputsInt32 =
        (emxArray_int32_T*)ssGetPWorkValue(S, NONLINEAR_INPUTS);
    emxArray_int32_T* NonLinear_OutputsInt32 =
        (emxArray_int32_T*)ssGetPWorkValue(S, NONLINEAR_OUTPUTS);
    emxArray_int32_T* NonLinearIterativeInt32 =
        (emxArray_int32_T*)ssGetPWorkValue(S, NONLINEAR_ITERATIVE);
    emxArray_int32_T* NonLinearMethodInt32 =
        (emxArray_int32_T*)ssGetPWorkValue(S, NONLINEAR_METHOD);

    emxArray_int32_T* NonLinearSizeVIInt32 =
        (emxArray_int32_T*)ssGetPWorkValue(S, NONLINEAR_SIZE_VI);
    emxArray_real_T* NonLinearVIReal = (emxArray_real_T*)ssGetPWorkValue(S, NONLINEAR_VI);

    emxArray_int32_T* noseg     = (emxArray_int32_T*)ssGetPWorkValue(S, NOSEG);
    emxArray_int32_T* nosegLast = (emxArray_int32_T*)ssGetPWorkValue(S, NOSEG_LAST);
    emxArray_real_T*  aseg      = (emxArray_real_T*)ssGetPWorkValue(S, ASEG);
    emxArray_real_T*  bseg      = (emxArray_real_T*)ssGetPWorkValue(S, BSEG);
    /*emxArray_real_T   *Wi = (emxArray_real_T*)ssGetPWorkValue(S, WI);*/
    emxArray_real_T* uArray = (emxArray_real_T*)ssGetPWorkValue(S, U_ARRAY);

    emxArray_int32_T* nonLinearLsatInt32 = (emxArray_int32_T*)ssGetPWorkValue(S, NONLINEAR_LSAT);
    emxArray_real_T*  xDLsat             = (emxArray_real_T*)ssGetPWorkValue(S, XD_LSAT);
    emxArray_real_T*  U0_histLsat        = (emxArray_real_T*)ssGetPWorkValue(S, U0_HIST_LSAT);

    /* output, wrapped*/
    emxArray_real_T* yArray         = (emxArray_real_T*)ssGetPWorkValue(S, Y_ARRAY);
    emxArray_real_T* y_xNonLinArray = (emxArray_real_T*)ssGetPWorkValue(S, Y_X_NONLINEAR);

    int     loopsToDo       = MAX_ITERATION;
    int_T   nbSwChng        = 0;
    real_T* y_switch_status = ssGetOutputPortRealSignal(S, 1);

    int_T* switch_status      = (int_T*)ssGetPWorkValue(S, SWITCH_STATUS);
    int_T* switch_status_init = (int_T*)ssGetPWorkValue(
        S, SWITCH_STATUS_INIT); /*P.B.sept13:  keep an inital copy of switch_status*/
    int_T*  SwitchChange = (int_T*)ssGetPWorkValue(S, SW_CHG);
    int_T*  gate         = (int_T*)ssGetPWorkValue(S, G_STATE);
    int_T*  idxSwChng    = (int_T*)ssGetPWorkValue(S, IDX_SW_CHG);
    real_T* yswitch      = (real_T*)ssGetPWorkValue(S, Y_SWITCH);
    int_T*  switchType   = (int_T*)ssGetPWorkValue(S, SWITCH_TYPES);

    real_T*     DxCol            = (real_T*)ssGetPWorkValue(S, DX_COL);
    real_T*     BDcol            = (real_T*)ssGetPWorkValue(S, BD_COL);
    real_T*     tmp1             = (real_T*)ssGetPWorkValue(S, TMP1);
    real_T*     tmp2             = (real_T*)ssGetPWorkValue(S, TMP2);
    const int_T nStatesXnStates  = ssGetIWorkValue(S, NSTATES_NSTATES);
    const int_T nStatesXnInputs  = ssGetIWorkValue(S, NSTATES_NINPUTS);
    const int_T nOutputsXnStates = ssGetIWorkValue(S, NOUTPUTS_NSTATES);
    const int_T nOutputsXnInputs = ssGetIWorkValue(S, NOUTPUTS_NINPUTS);
    int_T       newState         = 0;
    int_T       actualState;
    real_T      kMult;
    int_T       nSwXnStates, nSwXnInputs, nSwXnOutputs;
    real_T      temp;
    int_T       k, idx2, nSw, kSw /*, rowPos*/;

    real_T timeNoSwitchConv = ssGetRWorkValue(S, TIME_NO_SWITCH_CONV);

    if (nSwitch) {
        TBEon = (int)mxGetScalar(TBE_ON(S));
        /* keep an initial copy of switch_status*/
        memcpy(switch_status_init, switch_status, nSwitch * sizeof(int_T));
        memcpy(uswlast, y, nSwitch * sizeof(real_T));
    }


    if (nNonLinear) {
        NonLinearxInit           = (real_T*)mxGetPr(DSS_xInit_PARAM(S));
        NonLinear_InitialOutputs = (real_T*)mxGetPr(DSS_InitialOutputs_PARAM(S));

        /*
         * not good wrapper
         * uArray = emxCreateWrapper_real_T((real_T*)*u2Ptrs, sizeU, 1);
         * uArray = emxCreate_real_T(sizeU, 1);
         */
        for (i = 0; i < uArray->size[0]; i++) {
            uArray->data[i] = *u2Ptrs[i];
        }

        /*
         * // Prepare for loop, put back initial 0 and 1 in the stop var
         * // stop when stopCheck == nNonLinear
         */
        stopCheck          = 0;
        countIterNonLinear = 0;

        for (i = 0; i < nNonLinear; i++) {
            if (NonLinearIterativeInt32->data[i]) {
                StopIterNonLinearInt32->data[i] = 0;
            }
            /* pas requis, on a deja mis 1 dans mdlStart()
             * else
             * {
             * StopIterNonLinear->data[i] = 1;
             * }
             */
            stopCheck += StopIterNonLinearInt32->data[i];
        }
    }
    /*
     * // do while car stopcheck peut etre deja au max si aucun element iteratif
     * //while (stopCheck < nNonLinear && countIterNonLinear < NITER_NONLINEAR_MAX)
     */

    do {
        /* Debut Boucle externe -> Iterations Switchings
         * =============================================
         */
        countIterNonLinear = 0;

        if ((loopsToDo == 1) && (NOERROR_PARAM)) {
            /*P.B.sept13 - BDK 04/11/2006*/
            /* Even if the maximum number of iteration is reached, we decide to not popup an error:
             * Reset switches to their original status, then compute outputs and continue simulation
             */

            /* mexPrintf("t = %f   Max Iteration mode reached\n", ssGetT(S));*/

            /* conserver le temps de la premiere non-convergence */
            if (timeNoSwitchConv < 0) {
                timeNoSwitchConv = ssGetT(S);
                ssSetRWorkValue(S, TIME_NO_SWITCH_CONV, timeNoSwitchConv);
            }

            /* Need to reset some variables: */
            nbSwChng = 0;

            /* return to the original switch status*/
            for (i = 0; i < nSwitch; i++) {
                /* loop every switch, reset a new switch_status vector */
                SwitchChange[i]  = switch_status_init[i] - switch_status[i];
                switch_status[i] = switch_status_init[i];
                /*mexPrintf("SwitchChange[%d] = %d\n", i,SwitchChange[i] );*/
                if (SwitchChange[i] != 0) {
                    idxSwChng[nbSwChng++] = i;
                }
            }
        } else {
            do {
                /* Debut Boucle interne
                 * NonLinear non-iterative elements + iterative elements (RnonLin, Lsat)
                 * =====================================================================*/
                if (nNonLinear) {
                    int_T Nx, Nu, Ny;
                    /*real_T val;*/
                    int_T Noffset = 0;

                    /* Initialisation des etats discrets LSat a t=0 seulement*/
                    if (nStep == 0 && countIterNonLinear == 0) {
                        for (i = 0; i < xDLsat->size[0]; i++) {
                            j = nonLinearLsatInt32->data[i];
                            if (NonLinearMethodInt32->data[j] == 1) {
                                /* Backward Euler*/
                                xDLsat->data[i] =
                                    NonLinearxInit[i] / (*Ts) - NonLinear_InitialOutputs[j];
                            } else if (NonLinearMethodInt32->data[j] == 2) {
                                /* Tustin*/
                                xDLsat->data[i] =
                                    NonLinearxInit[i] / (*Ts) - NonLinear_InitialOutputs[j] / 2;
                            }
                        }
                    }

                    /* START replacement for DSS_GetABCD_NonLinearDisc*/
                    for (i = 0; i < nNonLinear; i++) {
                        Nx = NonLinearDimInt32->data[i];
                        Nu = NonLinearDimInt32->data[NonLinearDimInt32->size[0] + i];
                        Ny = NonLinearDimInt32->data[NonLinearDimInt32->size[0] * 2 + i];

                        if (NonLinearIterativeInt32->data[i] == 0) {
                            /*
                             * adjust size of reshape matrix
                             * important for the sprinkle matrix
                             */
                            reshapeMatrix->size[0] = Ny;
                            reshapeMatrix->size[1] = Nu;

                            /*
                             * // since uArray is alreay constructed using loop
                             * // we could do a mem copy.
                             */
                            /* mettre a jour D_NonLinearDisc avec Uarray lors de la 1ere iteration
                             * seulement, sinon 0 */
                            if (countIterNonLinear == 0 && loopsToDo == MAX_ITERATION) {
                                for (j = 0; j < Ny * Nu; j++) {
                                    reshapeMatrix->data[j] = uArray->data[j + Noffset];
                                }
                            } else {
                                for (j = 0; j < Ny * Nu; j++) {
                                    reshapeMatrix->data[j] = 0;
                                }
                            }

                            /*
                             * // get the references
                             * // offset a un +1 car on veut enlever 1 pour avoir un indice de
                             * matrice partant a 0
                             * // les valeurs de position sont basees sur un depart a 1
                             */
                            extractReference(NonLinear_InputsInt32, refRows, i, 0, Ny - 1, Nu1 + 1);
                            extractReference(NonLinear_OutputsInt32, refCols, i, 0, Nu - 1,
                                             Ny1 + 1);

                            /* sprinkle it!*/
                            sprinkleMatrix(D_NonLinearDisc, reshapeMatrix, refRows, refCols);
                        } else {
                            if (Nx == 0) {
                                /*
                                 * // row & col, on va toujours chercher la colonne 0, donc la
                                 * formule col * numRow + row revient a juste row
                                 * // (sachant que c'est column-major en memoire)
                                 */
                                writeValue(D_NonLinearDisc,
                                           NonLinear_InputsInt32->data[i] - Nu1 - 1,
                                           NonLinear_OutputsInt32->data[i] - Ny1 - 1,
                                           Y_NonLinearIterative->data[i] -
                                               Y_NonLinearIterative_last->data[i]);
                            } else if (Nx == 1) {
                                if (NonLinearMethodInt32->data[i] == 1) {
                                    /* Backward Euler*/
                                    writeValue(D_NonLinearDisc,
                                               NonLinear_InputsInt32->data[i] - Nu1 - 1,
                                               NonLinear_OutputsInt32->data[i] - Ny1 - 1,
                                               (Y_NonLinearIterative->data[i] -
                                                Y_NonLinearIterative_last->data[i]) *
                                                   (*Ts));
                                } else if (NonLinearMethodInt32->data[i] == 2) {
                                    /* Tustin*/
                                    writeValue(D_NonLinearDisc,
                                               NonLinear_InputsInt32->data[i] - Nu1 - 1,
                                               NonLinear_OutputsInt32->data[i] - Ny1 - 1,
                                               (Y_NonLinearIterative->data[i] -
                                                Y_NonLinearIterative_last->data[i]) *
                                                   (*Ts) / 2);
                                }
                            } else {
                                /* error not supported*/
                            }
                        }

                        Noffset += Ny * Nu;
                    }

                    /*
                     * Sauvegarder Y_NonLinearIterative precedent
                     * Y_NonLinearIterative_last = Y_NonLinearIterative
                     * faire un memcopy?
                     */
                    for (i = 0; i < Y_NonLinearIterative_last->size[1]; i++) {
                        Y_NonLinearIterative_last->data[i] = Y_NonLinearIterative->data[i];
                    }

                    /* Mettre a jour les entrees courant historiques des elements non lineaires
                     * Lsat*/
                    /*
                     * %   I_hist = C*xNonLinearDisc
                     * %   Discretisation Tustin et Backward Euler->C = Ts / L
                     * %   ou 1 / L = Y_NonLinearIterative
                     */
                    for (i = 0; i < nonLinearLsatInt32->size[0]; i++) {
                        /* position dans le verteur NonLinear_InputsInt32*/
                        j = nonLinearLsatInt32->data[i];

                        /* position dans le vecteur U0 history Lsat, -1 vu que la position est en
                         * matlab (debut a 1) et que le vecteur est en C*/
                        U0_histLsat->data[NonLinear_InputsInt32->data[j] - 1] =
                            xDLsat->data[i] * Y_NonLinearIterative->data[j] * (*Ts);

                        /* *u0Ptrs[NonLinear_InputsInt32->data[j]] = xDLsat->data[j] *
                         * Y_NonLinearIterative->data[j] * (*Ts); */
                    }


                    D_NonLinearIsNotZero = 0;
                    for (i = 0; i < D_NonLinearDisc->size[0] * D_NonLinearDisc->size[1]; i++) {
                        if (D_NonLinearDisc->data[i] != 0.0) {
                            D_NonLinearIsNotZero = 1;
                            break;
                        }
                    }

                    if (D_NonLinearIsNotZero) {
                        /* DEBUT FEEDBACK Systeme lineaire - Systeme non lineaire
                         * =======================================================*/
                        /*Correspondance entre dimensions code M et code C
                         * Dimensions sorties  M   ny         ny1    ny2
                         * C   nOutputs   Ny1    nNuNonLinear
                         *
                         * ny1 = premieres sorties qui ne sont pas en feedback
                         * nu2	= dernieres sorties qui sont en feedback par elements non lineaires
                         * ny = ny1 + ny2
                         * nOutputs = Ny1 + nNuNonLinea2
                         *
                         * Dimensions entrees  M   nu         nu1   nu2
                         * C   nInputs    Nu1   nNyNonLinear
                         *
                         * nu1 = premieres entrees qui ne sont pas en feedback
                         * nu2	= dernieres entrees qui sont en feedback par elements non lineaires
                         * nu = nu1 + nu2
                         * nInputs = Nu1 + nNuNonLinear
                         *
                         * Dimensions  etats   M   nx
                         * C   nStates
                         *
                         * Ny1 = nOutputs - nNuNonLinear;
                         * Nu1 = nInputs - nNyNonLinear;
                         */
                        /*
                         * Calcul de d12d2 = d1(:, nu1 + 1 : nu)*d2;  % d12*d2 -> dimension(ny, ny2)
                         * ou
                         * d1-> (ny,nu)   ->  D_Global
                         * d12 -> (ny,nu2)  ->  nu2 dernieres colonnes de d1
                         * d2 -> (nu2,ny2) ->  D_NonLinearDisc
                         * d12d2 -> (ny,ny2)
                         */
                        multiplyZoneMatlab(D_Global, D_NonLinearDisc, d12d2, 0, nOutputs - 1, Nu1,
                                           nInputs - 1, 0, D_NonLinearDisc->size[0] - 1, 0,
                                           D_NonLinearDisc->size[1] - 1, 0, d12d2->size[0] - 1, 0,
                                           d12d2->size[1] - 1);

                        /* Calcul de Wi12 Wi22
                         * Wi22= inv(eye(ny2,ny2)-d12d2(ny1+1:ny,:)); % Wi22 = inv(I-W2)   ->
                         * (ny2,ny2) Wi12= d12d2(1:ny1,:)*Wi22;                 % Wi12 =
                         * W1*inv(I-W2)-> (ny1,ny2)
                         */

                        /*
                         * Wi22-> resultInv2 = inv( eye(ny2, ny2) - d12d2(ny1+1:ny,:) )
                         */
                        substractionZoneMatlab(eyeMatrix, d12d2, resultInv1, Ny1, nOutputs - 1, 0,
                                               d12d2->size[1] - 1);
                        invert(resultInv1, resultInv2, workingInv0, workingInv1, workingInv2);


                        /* Wi12 = d12d2(1:ny1,:) * Wi22
                         * Wi12 is resultInv1 now ...
                         * row start, row end, col start, col end */
                        multiplyZoneMatlab(d12d2, resultInv2, Wi12, 0, Ny1 - 1, 0,
                                           d12d2->size[1] - 1, 0, resultInv2->size[0] - 1, 0,
                                           resultInv2->size[1] - 1, 0, Wi12->size[0] - 1, 0,
                                           Wi12->size[1] - 1);


                        /* Mise a jour de C_Global et D_Global */
                        /*
                         * C(1:ny1,:)    = c1(1:ny1,:) + Wi12*c1(ny1+1:ny,:); (C PART 1)
                         * C(ny1+1:ny,:) =               Wi22*c1(ny1+1:ny,:); (C PART 2)
                         * ou   C -> C_Global
                         * c1 -> C_Global
                         *
                         * D(1:ny1,:)    = d1(1:ny1,:) + Wi12*d1(ny1+1:ny,:); (D PART 1)
                         * D(ny1+1:ny,:) =               Wi22*d1(ny1+1:ny,:); (D PART 2)
                         * ou   D -> D_Global
                         * d1 -> D_Global
                         */
                        /* C PART 1 */
                        multiplyZoneMatlab(Wi12, C_Global, workingC1, 0, Wi12->size[0] - 1, 0,
                                           Wi12->size[1] - 1, Ny1, nOutputs - 1, 0, nStates - 1, 0,
                                           workingC1->size[0] - 1, 0, workingC1->size[1] - 1);

                        additionToZoneMatlab(workingC1, C_Global, C_Global, 0, Ny1 - 1, 0,
                                             nStates - 1);

                        /* C PART 2, Wi22 is resultInv2 */
                        multiplyZoneMatlab(resultInv2, C_Global, workingC2, 0,
                                           resultInv2->size[0] - 1, 0, resultInv2->size[1] - 1, Ny1,
                                           nOutputs - 1, 0, nStates - 1, 0, workingC2->size[0] - 1,
                                           0, workingC2->size[1] - 1);

                        copyZoneMatlab(workingC2, C_Global, Ny1, nOutputs - 1, 0, nStates - 1);

                        /* D PART 1 */
                        multiplyZoneMatlab(Wi12, D_Global, workingD1, 0, Wi12->size[0] - 1, 0,
                                           Wi12->size[1] - 1, Ny1, nOutputs - 1, 0, nInputs - 1, 0,
                                           workingD1->size[0] - 1, 0, workingD1->size[1] - 1);

                        additionToZoneMatlab(workingD1, D_Global, D_Global, 0, Ny1 - 1, 0,
                                             nInputs - 1);

                        /* D PART 2, Wi22 is resultInv2*/
                        multiplyZoneMatlab(resultInv2, D_Global, workingD2, 0,
                                           resultInv2->size[0] - 1, 0, resultInv2->size[1] - 1, Ny1,
                                           nOutputs - 1, 0, nInputs - 1, 0, workingD2->size[0] - 1,
                                           0, workingD2->size[1] - 1);

                        copyZoneMatlab(workingD2, D_Global, Ny1, nOutputs - 1, 0, nInputs - 1);

                        /* Mise a jour de A_Global et B_Global */
                        /* M=b1(:,nu1+1:nu)*d2;       -> dim(M) = (nx,nu2)*(nu2,ny2)=(nx,ny2) */
                        /* A=a1 + M*C(ny1+1:ny,:);
                         * B=b1 + M*D(ny1+1:ny,:);
                         * ou   A  a1 ->  A_Global
                         * B  b1 ->  B_Global
                         * C     ->  C_Global
                         * D     ->  D_Global */

                        /* M=b1(:, nu1+1:nu)*d2	*/
                        multiplyZoneMatlab(B_Global, D_NonLinearDisc, MMatrix, 0, nStates - 1, Nu1,
                                           nInputs - 1, 0, D_NonLinearDisc->size[0] - 1, 0,
                                           D_NonLinearDisc->size[1] - 1, 0, MMatrix->size[0] - 1, 0,
                                           MMatrix->size[1] - 1);
                        /* A=a1 + M*C(ny1+1:ny,:);*/
                        multiplyZoneMatlab(MMatrix, C_Global, result1, 0, MMatrix->size[0] - 1, 0,
                                           MMatrix->size[1] - 1, Ny1, nOutputs - 1, 0, nStates - 1,
                                           0, result1->size[0] - 1, 0, result1->size[1] - 1);

                        addMatrix(A_Global, result1, A_Global);
                        /* B=b1 + M*D(ny1+1:ny,:);*/
                        multiplyZoneMatlab(MMatrix, D_Global, result2, 0, MMatrix->size[0] - 1, 0,
                                           MMatrix->size[1] - 1, Ny1, nOutputs - 1, 0, nInputs - 1,
                                           0, result2->size[0] - 1, 0, result2->size[1] - 1);

                        addMatrix(B_Global, result2, B_Global);

                        /* FIN FEEDBACK Systeme lineaire - Systeme non lineaire*/
                    }
                }

                memset(y, '\0', nOutputs * sizeof(real_T));

                /*
                 * // part 1
                 * // loop on column first
                 * // size = {row, col}
                 */
                memPos = 0;
                for (j = 0; j < nStates; j++) {
                    /* loop on row*/
                    for (i = 0; i < nOutputs; i++) {
                        y[i] += Cs[memPos++] * xD[j];
                    }
                }

                /*
                 * // part 2
                 * // loop on column first
                 * // size = {row, col}
                 * // since loop NOT starting at 0, must compute the right starting value
                 * // ex:
                 * // matrix=
                 * // |A B C D|
                 * // |E F G H|
                 * // |I J K L|
                 * //
                 * // column-major memory -> matrix = {A E I B F J C G K D H L}
                 * // if we start at the column 2, nSwitch = 2, it a simple offset and after it's a
                 * simple +1 increment
                 * // we start at 2 * number of row -> 2 * 3 = 6, we then start at C in the array.
                 */
                memPos = nSwitch * nOutputs;
                for (j = nSwitch; j < nInputs; j++) {
                    /*loop on row*/
                    for (i = 0; i < nOutputs; i++) {
                        y[i] += Ds[memPos++] * (U0(j) + U0_histLsat->data[j]);
                    }
                }


                if (nNonLinear) {
                    int_T  Nx, nloPos, nliPos, skip;
                    int_T  istate_n1 = 0;
                    int_T  nOffsetVI = 0;
                    real_T V_nonLinear, Rth1, Rth, Vth, aVar, bVar, phi, phid, Isol, Vsol, V1, I1,
                        V2, I2, errorV;

                    /*
                     * // Mettre a jour groupe de sorties  No 3 (y_xNonLinArray) contenant les etats
                     * continus non lineaires(phi_Lsat)
                     * // Discretisation Backward Euler->xc = (xd + u)*Ts
                     * // Discretisation Tustin->xc = (xd + u / 2)*Ts
                     * // ou  xd = phid  xc = phi  u = tension VL = sortie
                     * NonLinear_Outputs(iNonLin, 1)
                     * //  yArray         = vecteur des sorties V/I (groupe de sorties No 1)
                     * //  y_xNonLinArray = vecteur des etats non lineaires continus (groupe de
                     * sorties No 3)
                     */
                    for (i = 0; i < xDLsat->size[0]; i++) {
                        j = nonLinearLsatInt32->data[i];
                        if (NonLinearMethodInt32->data[j] == 1) {
                            /* backward EULER*/
                            y_xNonLinArray->data[i] =
                                (xDLsat->data[i] +
                                 yArray->data[NonLinear_OutputsInt32->data[j] - 1]) *
                                (*Ts);
                        } else if (NonLinearMethodInt32->data[j] == 2) {
                            /* TUSTIN*/
                            y_xNonLinArray->data[i] =
                                (xDLsat->data[i] +
                                 yArray->data[NonLinear_OutputsInt32->data[j] - 1] / 2) *
                                (*Ts);
                        }
                    }


                    /* Solve nonlinear iterative elements (R or or Lsat) */

                    /*
                     * DSS_SolveNonLinearIterativeElements(
                     * y_xNonLinArray,
                     * xDLsat,
                     * yArray,
                     *Ts,
                     * Y_NonLinearIterative,
                     * noseg,
                     * aseg,
                     * bseg,
                     * StopIterNonLinearInt32,
                     *
                     * nNonLinear,
                     * D_Global,
                     * NonLinear_InputsInt32,
                     * NonLinear_OutputsInt32,
                     * NonLinearDimInt32,
                     * NonLinearIterativeInt32,
                     * NonLinearMethodInt32,
                     * NonLinearSizeVIInt32,
                     * NonLinearVIReal,
                     * NonLinearIterTol);
                     */
                    /*DSS Code de la fonction M*/
                    for (i = 0; i < nNonLinear; i++) {
                        /* 2 dims mais on est dans la 1ere col, col=0 ->  pos = col * numCol + row =
                         * 0 * numCol + row = row */
                        Nx = NonLinearDimInt32->data[i] * NonLinearIterativeInt32->data[i];
                        istate_n1 += Nx;

                        if (NonLinearIterativeInt32->data[i] > 0) {
                            /*% Equation V = a*I + b du reseau lineaire ->V_nonLinear
                             * % Equivalent de Thevenin resistitif
                             * %        ou a= -Rthevenin  -> aVar
                             * %           b=  Vthevenin  -> bVar
                             */


                            /* 2 dims mais on est dans la 1ere col, col=0 ->  pos = col * numCol +
                             * row = 0 * numCol + row = row */
                            nloPos = NonLinear_OutputsInt32->data[i] - 1;
                            nliPos = NonLinear_InputsInt32->data[i] - 1;

                            V_nonLinear = yArray->data[nloPos];

                            if (Nx == 0) {
                                /*
                                 * % Element non lineaire iteratif = inductance
                                 * % Equivalent de Thevenin V=-Rth*I + Vth excluant l'inductance non
                                 * lineaire %    V = Vth - Rth*InonLnin %  Vth = V + Rth*IL ou
                                 * IL=phi/L
                                 */

                                /* pos = col * numRow + row */
                                Rth1 = -D_Global->data[D_Global->size[0] * nliPos + nloPos];
                                Rth  = Rth1 / (1 - Rth1 * Y_NonLinearIterative->data[i]);

                                Vth = V_nonLinear * (1 + Rth * Y_NonLinearIterative->data[i]);

                                aVar = -Rth;
                                bVar = Vth;
                            } else {
                                /*
                                 * % Pour l'inductance non lineaire, on doit convertir
                                 * % la caracteristique (V=a*I +b) en caracteristique Flux-I telle
                                 * que %   phi = a1*I + b1
                                 * %
                                 * %  discretisation BE (Backward-Euler) de l'inductance
                                 * %     phid = phi/Ts - VL
                                 * %
                                 * %  discretisation Tustin de l'inductance
                                 * %     phid = phi/Ts - VL/2
                                 * %
                                 * %   (pour discretisation Tustin -> phid= phi/Ts -VL/2)
                                 * % ou
                                 * %      VL  = tension aux bornes de l'inductance
                                 * %      phi = flux continu = integrale de VL
                                 * %     phid = flux discret
                                 * %
                                 * %  discretisaton BE
                                 * %      VL = a*I+b = -phid + phi/Ts
                                 * % ->  phi = a*Ts*I + (phid + b)*Ts = a1*I + b1
                                 * % ->   a1 = a*Ts ; b1=(phid + b)*Ts
                                 * %  discretisaton Tustin
                                 * %     VL = a*I+b = 2*(-phid + phi/Ts)
                                 * % ->  phi = a*Ts/2*I + (phid + b/2)*Ts = a1*I + b1
                                 * % ->   a1 = a*Ts/2 ; b1=(phid + b/2)*Ts
                                 */

                                Rth = -D_Global->data[D_Global->size[0] * nliPos + nloPos];
                                Vth = V_nonLinear + Rth * y_xNonLinArray->data[istate_n1 - 1] *
                                                        Y_NonLinearIterative->data[i];

                                aVar = -Rth;
                                bVar = Vth;

                                phi  = y_xNonLinArray->data[istate_n1 - 1];
                                phid = xDLsat->data[istate_n1 - 1];

                                V_nonLinear = phi;

                                switch (NonLinearMethodInt32->data[i]) {
                                case 1:
                                    /* Backward Euler */
                                    aVar = aVar * (*Ts);
                                    bVar = (phid + bVar) * (*Ts);
                                    break;
                                case 2:
                                    /* Tustin */
                                    aVar = aVar * (*Ts) / 2;
                                    bVar = (phid + bVar / 2) * (*Ts);
                                    break;
                                }
                            }

                            /*
                             * % Mettre a jour le no de segment noseg selon valeur de la tension ou
                             * du flux %
                             * --------------------------------------------------------------------------
                             * % Dans le code ci-dessous :
                             * %  Vsol =  tension aux bornes de la resistance non lineaire
                             * %          ou flux dans l'inductance non lineaire
                             * %          correspondant a intersectiion entre les droites
                             * %            V   =    a*I + b       du reseau
                             * %            V   = aseg*I + bseg    du dernier segment
                             * % NonLinear_VI{iNonLin} = caracteristique V-I de la resistance
                             * %                         ou caracteristique Flux-I de l'inductance
                             */

                            Isol = (bseg->data[i] - bVar) / (aVar - aseg->data[i]);
                            Vsol = aVar * Isol + bVar;

                            skip = -2;
                            for (j = nOffsetVI; j < nOffsetVI + NonLinearSizeVIInt32->data[i];
                                 j++) {
                                /* scan la 1ere colonne, pas besoin vu que pos = col * numRow + row
                                 * et que col = 0 */
                                if (NonLinearVIReal->data[j] > Vsol) {
                                    /* on veut celui juste avant! */
                                    skip = j - 1;
                                    break;
                                }
                            }

                            if (skip == -2) {
                                /* rien, on garde le dernier (why -1?) -1 mais avec - 1 en + donc
                                 * -2. */
                                noseg->data[i] = NonLinearSizeVIInt32->data[i] - 2;
                            } else if (skip == -1) {
                                /* on garde le premier */
                                noseg->data[i] = 0;
                            } else {
                                /* on garde celui qu'on a trouve! mais on doit consider le depart
                                 * comme zero donc - offset */
                                /* il est possible d'avoir skip < nOffset dans le cas du premier. ex
                                 * on trouve skip = 11 car on fait j -1 et l' offset est 12 */
                                if (skip < nOffsetVI) {

                                    noseg->data[i] = 0;
                                } else {
                                    noseg->data[i] = skip - nOffsetVI;
                                }
                            }

                            /* Modif G.S 2019-07-23
                               Si nb de points de la caracteristique V-I ou phi-I est <=10
                               permettre deplacement de 1 seul segment a la fois */
                            if (NonLinearSizeVIInt32->data[i] <= 10) {
                                if (noseg->data[i] - nosegLast->data[i] > 1) {
                                    noseg->data[i] = nosegLast->data[i] + 1;
                                } else if (noseg->data[i] - nosegLast->data[i] < -1) {
                                    noseg->data[i] = nosegLast->data[i] - 1;
                                }
                            }
                            /* conserver noseg */
                            nosegLast->data[i] = noseg->data[i];

                            /*
                             * % Equation V = aseg * I + bseg of the noseg segment of nonlinear
                             * resistance or inductance % coordinates of the 2 ends of the segment:
                             * (V1, I1), (V2, I2) % (V-V1)/(I-I1) = (V2-V1)/(I2-I1) % (V-V1) =
                             * (V2-V1)/(I2-I1)* (I-I1) = - (V2-V1)/(I2-I1)*I1 % V =
                             * (V2-V1)/(I2-I1)*I + (V1 - (V2-V1)/(I2-I1)*I1) = aseg*I + bseg
                             */

                            /*
                             * we reuse skip to put the number of passes
                             * pos = col * numRow + row
                             */
                            skip = NonLinearVIReal->size[0];
                            V1   = NonLinearVIReal->data[nOffsetVI + noseg->data[i]];
                            I1   = NonLinearVIReal->data[skip + nOffsetVI + noseg->data[i]];
                            V2   = NonLinearVIReal->data[nOffsetVI + noseg->data[i] + 1];
                            I2   = NonLinearVIReal->data[skip + nOffsetVI + noseg->data[i] + 1];

                            aseg->data[i] = (V2 - V1) / (I2 - I1);
                            bseg->data[i] = V1 - aseg->data[i] * I1;

                            /*
                             * % Solution = intersection of the characteristics of the linear
                             * network % and the noseg segment of the nonlinear element % V = a*I +
                             * b = aseg*I + bseg
                             */

                            Isol = (bseg->data[i] - bVar) / (aVar - aseg->data[i]);
                            Vsol = aVar * Isol + bVar;

                            if (Isol == 0) {
                                Y_NonLinearIterative->data[i] = (I2 - I1) / (V2 - V1);
                            } else {
                                Y_NonLinearIterative->data[i] = Isol / Vsol;
                            }

                            /*if (V_nonLinear == 0)*/
                            if (fabs(V_nonLinear) < 1e-6) {
                                errorV = 0;
                            } else {
                                errorV = (V_nonLinear - Vsol) / V_nonLinear;
                            }

                            if (fabs(errorV) < NonLinearIterTol) {
                                StopIterNonLinearInt32->data[i] = 1;
                            } else {
                                StopIterNonLinearInt32->data[i] = 0;
                            }
                        }

                        nOffsetVI += NonLinearSizeVIInt32->data[i];
                    }

                    /* update our stopping conditions*/
                    countIterNonLinear++;
                    stopCheck = 0;
                    for (i = 0; i < nNonLinear; i++) {
                        stopCheck += StopIterNonLinearInt32->data[i];
                    }
                } else {
                    break;
                }

            } while (stopCheck < nNonLinear && countIterNonLinear < nIterNonLinMax);

            if (nSwitch) {
                /* Circuit has switches */

                /* 2.0 Check for switch operation:*/

                /* --------------------------
                 *
                 * Determine the switches states according to the actual conditions.
                 *
                 * Conditions determining switch state:
                 *
                 *   Gate         Gate signal (trigger, command).
                 *   V            Switch voltage
                 *   I         Switch current
                 *   AS         Actual switch state (open or close).
                 *
                 * Switch states table:
                 *
                 * ===========================+===============================+=======
                 * Switch type                |Condition                      | State
                 * ===========================+===============================+=======
                 *                            |                               |
                 * Ideal switch and breaker   | Gate > 0                      | Close
                 *                            | Gate <= 0                     | Open
                 * ---------------------------+-------------------------------+-------
                 *                            |                               |
                 * Diodes                     | V > 0                         | Close
                 *                            | V <= 0                        | AS
                 *                            | I < 0  (or V < 0)             | Open
                 * ---------------------------+-------------------------------+-------
                 *                            |                               |
                 * Thyristor                  | V > 0 and Gate > 0            | Close
                 *                            | V <= 0                        | AS
                 *                            | I < 0  (or V < 0)             | Open
                 * ---------------------------+-------------------------------+-------
                 *                            |                               |
                 * GTO                        | V > 0 and Gate > 0            | Close
                 *                            | V == 0                        | AS
                 *                            | I < 0 or Gate == 0            | Open
                 * ---------------------------+-------------------------------+-------
                 *                            |                               |
                 * IGBT                       | V > 0 and Gate > 0            | Close
                 *                            | V == 0                        | AS
                 *                            | I < 0 or Gate == 0            | Open
                 * ---------------------------+-------------------------------+-------
                 *                            |                               |
                 * MOSFETs or                 | V > 0 and Gate > 0            | Close
                 * IGBT/Diode pairs           | V < 0                         | Close
                 *                            | V == 0                        | AS
                 *                            | I > 0 and Gate == 0           | Open
                 * ===========================+===============================+=======
                 *
                 * A new switch state will be computed for every switch in model.
                 * If the switch state has changed compared to actual, we will keep
                 * the switch index, the direction of change ( Open -> Close or
                 * Close -> Open) and update the actual switches states vector.
                 */

                nbSwChng = 0; /* reset the number of switch changes to 0 */

                for (j = 0; j < nSwitch; j++) { /* Loop every switch*/

                    actualState = switch_status[j];

                    newState = actualState;
                    switch (switchType[j]) {
                    case 1: /* Ideal switch */
                        if (gate[j] > 0 && actualState == 0) {
                            newState = 1;
                        } else if (gate[j] == 0 && actualState == 1) {
                            newState = 0;
                        }
                        break;
                    case 2: /* Breaker */
                        if (gate[j] > 0 && actualState == 0) {
                            newState = 1;
                        } else if (gate[j] == 0 && (V_SW(j) * uswlast[j] < 0) && actualState == 1) {
                            newState = 0;
                        }
                        break;
                    case 3: /* Diodes */
                        if (V_SW(j) > 0.0 && actualState == 0) {
                            newState = 1;
                        } else if (V_SW(j) < 0.0 && actualState == 1) {
                            newState = 0;
                        }
                        break;

                    case 4: /* Thyristor */
                        if (gate[j] > 0 && V_SW(j) > 0.0 && actualState == 0) {
                            newState = 1; /* Switch Close */
                        }
                        if (V_SW(j) < 0.0 && actualState == 1) {
                            newState = 0; /* Switch Open */
                        }
                        break;

                    case 5: /* GTO */
                        if (gate[j] > 0 && V_SW(j) > 0.0 && actualState == 0) {
                            newState = 1; /* Switch Close */
                        }
                        if ((gate[j] == 0 || V_SW(j) < 0.0) && actualState == 1) {
                            newState = 0; /* Switch Open */
                        }
                        break;

                    case 6: /* IGBT */
                        if (gate[j] > 0 && V_SW(j) > 0.0 && actualState == 0) {
                            newState = 1; /* Switch Close */
                        }
                        if ((gate[j] == 0 || V_SW(j) < 0.0) && actualState == 1) {
                            newState = 0; /* Switch Open */
                        }
                        break;

                    case 7: /* MOSFETs or IGBT/Diode pairs */
                        if (((gate[j] > 0 && V_SW(j) > 0.0) || V_SW(j) < 0.0) && actualState == 0) {
                            newState = 1; /* Switch Close */
                        }
                        if (gate[j] == 0 && V_SW(j) > 0.0 && actualState == 1) {
                            newState = 0; /* Switch Open */
                        }
                        break;
                    }



                    if (newState != actualState) { /* 2.2 This switch has changed */

#ifdef DEBUG
                        /*mexPrintf("Switch changed!\n");*/
                        /*mexPrintf("loopsToDo = %d\n", loopsToDo);*/
                        /*mexPrintf("Switch index = %d\n", j);*/
                        /*mexPrintf("oldState = %d; newState = %d\n", switch_status[j], newState);*/
#endif

                        /* Update the number of changed switches:*/
                        /* The output y will be recomputed in step 1.0 above*/

                        idxSwChng[nbSwChng++] = j; /* Index of changed switch */
                        SwitchChange[j]  = newState - switch_status[j]; /* Direction of change */
                        switch_status[j] = newState;                    /* Keep new state */

                        SwitchesHaveChanged = 1;
                    }
                } /* End of Loop every switch*/
            }
        }

        /************************ TBE ALGORITHM *************************/
        /* Pas de demi-pas au premier pas */
        if ((TBEon) && (SwitchesHaveChanged == 1) && (loopsToDo == MAX_ITERATION) && nStep > 0 &&
            nSwitch > 0) {
            /* Effectuer un demi-pas BE a partir des anciens etats xLast a t-Ts et des matrices non
             * modifees
             * -> xkm12= etats a l'instant t-Ts/2
             * xkm12 = (Asw+I)/2*xLast + Bsw/2*uLast; */

            /* column-major must scan column then row, so twice as number of col not the same*/
            memset(xkm12, '\0', nStates * sizeof(real_T));

            /*	 scan col */
            for (j = 0; j < nStates; j++) {
                /* scan row*/
                for (i = 0; i < nStates; i++) {
                    xkm12[i] += ((i == j) ? (As[j * nStates + i] + 1) * 0.5 * xLast[j]
                                          : As[j * nStates + i] * 0.5 * xLast[j]);
                }
            }

            /* matrix B */
            for (j = nSwitch; j < nInputs; j++) {
                for (i = 0; i < nStates; i++) {
                    xkm12[i] += Bs[j * nStates + i] * 0.5 * uLast[j];
                }
            }
        }

        /*
         * 3.0 For the case where  a switch changed, we need to
         *     compute new As, Bs, Cs and Ds matrixes:
         */

#ifdef DEBUG
        if (nbSwChng > 0) {
            mexPrintf("Number of switches that changed status = %d\n", nbSwChng);
            mexPrintf("step_number = %d\n", step_number);
        }
#endif
        /* DEBUT de mise a jour a jour des matrices ABCD_Global suite a un changement de switches
         * ======================================================================================*/
        if (nbSwChng > 0 && nSwitch > 0) {
            for (k = 0; k < nbSwChng; k++) {

                nSw          = idxSwChng[k];
                nSwXnStates  = nSw * nStates;
                nSwXnInputs  = nSw * nInputs;
                nSwXnOutputs = nSw * nOutputs;
                kSw          = SwitchChange[nSw];

                /* Compute DxCol */

                tmp = Ds[nSwXnOutputs + nSw] * yswitch[nSw]; /* multiplication-addition precision */
                temp  = 1.0 / (1 - tmp * kSw);
                temp2 = yswitch[nSw] * temp * kSw;

                for (i = 0; i < nOutputs; i++) {
                    DxCol[i] = Ds[i + nSwXnOutputs] * temp2;
                }

                DxCol[nSw] = temp;

                /* Compute BDcol */

                temp2 = yswitch[nSw] * kSw;
                for (i = 0; i < nStates; i++) {
                    BDcol[i] = Bs[i + nSwXnStates] * temp2;
                }

                /* Copy row nSw of Cs into tmp1 and zero it out in Cs */

                for (i = 0; i < nStates; i++) {
                    tmp1[i] = Cs[nSw + i * nOutputs];
                }


                /* Copy row nSw of Ds into tmp2 and zero it out in Ds */

                for (i = 0; i < nInputs; i++) {
                    /* nSw est la rangee qu'on desire*/
                    tmp2[i] = Ds[nSw + i * nOutputs];
                }

                /* Cs = Cs + DxCol * tmp1, Ds = Ds + DxCol * tmp2 *******************/

                for (i = 0; i < nOutputs; i++) {
                    idx2  = i * nStates; /* position du debut de la rangee en row-major*/
                    kMult = (idx2 == nSwXnStates ? 0.0 : 1.0);

                    for (j = 0; j < nStates; j++) {

                        tmp = DxCol[i] * tmp1[j]; /* multiplication-addition precision */
                        Cs[j * nOutputs + i] = Cs[j * nOutputs + i] * kMult + tmp;
                    }

                    idx2  = i * nInputs; /* start of row in row-major*/
                    kMult = (idx2 == nSwXnInputs ? 0.0 : 1.0);

                    /* scan colonne*/
                    for (j = 0; j < nInputs; j++) {
                        tmp = DxCol[i] * tmp2[j]; /* multiplication-addition precision */
                        Ds[j * nOutputs + i] = Ds[j * nOutputs + i] * kMult + tmp;
                    }
                }

                /* As = As + BdCol*Cs(nSw,:), Bs = Bs + BdCol*Ds(nSw,:) */
                for (i = 0; i < nStates; i++) {
                    idx2 = i * nStates;

                    /* loop columns of matrix A*/
                    for (j = 0; j < nStates; j++) {
                        tmp                 = BDcol[i] * Cs[j * nOutputs + nSw];
                        As[j * nStates + i] = As[j * nStates + i] + tmp;
                    }

                    idx2 = i * nInputs;

                    /* loop column of B*/
                    for (j = 0; j < nInputs; j++) {
                        tmp                 = BDcol[i] * Ds[j * nOutputs + nSw];
                        Bs[j * nStates + i] = Bs[j * nStates + i] + tmp;
                        ;
                    }
                }

            } /* end for k */

        } /* end if (nbSwChng > 0) */
        /* FIN de mise a jour a jour des matrices ABCD_Global suite a un changement de switches */

    } while ((nbSwChng > 0) && (--loopsToDo > 0));

    ssSetIWorkValue(S, SWITCHES_HAVE_CHANGED, SwitchesHaveChanged);

    /************************ TBE ALGORITHM *************************/
    if (TBEon && (SwitchesHaveChanged == 1) && nStep > 0) {
        /*
         * % Effectuer un demi-pas BE a partir des etats x a l'instant t avec les nouvelles matrices
         * % -> xkp12= etats a l'instant t+Ts/2
         * xkp12 = (Asw+I)/2*x + Bsw/2*u(1:NINPUT);
         */

        /* Calculer etats BE a (t+Ts/2) et recalculer les sorties  */

        memset(xkp12, '\0', nStates * sizeof(real_T));
        /*
         * // Matrix A
         * // scan column
         */
        for (j = 0; j < nStates; j++) {
            /* scan row*/
            for (i = 0; i < nStates; i++) {
                xkp12[i] += ((i == j) ? (As[j * nStates + i] + 1) * 0.5 * xD[j]
                                      : As[j * nStates + i] * 0.5 * xD[j]);
            }
        }

        /*
         * // Matrix B
         * // scan column
         */
        for (j = nSwitch; j < nInputs; j++) {
            /* scan row*/
            for (i = 0; i < nStates; i++) {
                xkp12[i] += Bs[j * nStates + i] * 0.5 * (U0(j) + U0_histLsat->data[j]);
            }
        }

        /*
         * % Interpoler les etats obtenus a (t-Ts/2) et (t+Ts/2) pour obtenir
         * % les  etats actuels corriges a l'instant  t
         * % xk -> etats corriges a utiliser pour recalculer les sorties
         * xk = (xkp12 + xkm12)/2;
         *
         * Mettre a jour les sorties avec les etats corriges xk
         * sys(1:NOUTPUT,1) = Csw*xk + Dsw(:,NSWITCH+1:NINPUT)*u(NSWITCH+1:NINPUT);
         */

        memset(y, '\0', nOutputs * sizeof(real_T));
        /*
         * // scan column then row, so twice
         * // Matrix C
         * // scan col
         */
        for (j = 0; j < nStates; j++) {
            /* scan row*/
            for (i = 0; i < nOutputs; i++) {
                y[i] += Cs[j * nOutputs + i] * (xkp12[j] + xkm12[j]) * 0.5;
            }
        }

        /*
         * // Matrix D
         * // scan col
         */
        for (j = nSwitch; j < nInputs; j++) {
            /* scan row*/
            for (i = 0; i < nOutputs; i++) {
                y[i] += Ds[j * nOutputs + i] * (U0(j) + U0_histLsat->data[j]);
            }
        }
    }

    if (loopsToDo == 0) {
        if (NOERROR_PARAM) {

            memset(y, '\0', nOutputs * sizeof(real_T));

            /*
             * // part 1
             * // loop on column first
             */
            memPos = 0;
            for (j = 0; j < nStates; j++) {
                /* loop on row*/
                for (i = 0; i < nOutputs; i++) {
                    y[i] += Cs[memPos++] * xD[j];
                }
            }

            /* part 2*/
            memPos = nSwitch * nOutputs;
            for (j = nSwitch; j < nInputs; j++) {
                /* loop on row*/
                for (i = 0; i < nOutputs; i++) {
                    y[i] += Ds[memPos++] * (U0(j) + U0_histLsat->data[j]);
                }
            }
        } else {
            /* ce else n'arrive jamais avec NOERROR_PARAM =1 ...*/
            /* ERROR -- Reached max. number of iteration! */
            ssSetErrorStatus(S, "ERROR! - Reached 20 iterations without result!!");
        }
    }
    /* Output new switches states */
    for (i = 0; i < nSwitch; ++i) {
        y_switch_status[i] = (real_T)switch_status[i];
    }

    /*
     *  Signaler erreur si exit avec countIterNonLinear == NITER_NONLINEAR_MAX
     */

    if (continueOnMaxIteration == 0 && countIterNonLinear == nIterNonLinMax &&
        stopCheck < nNonLinear) {

        static char msg[100];
        sprintf(msg,
                "Nonlinear element(s) (RnonLin, Lsat) failed to converge after %i iterations, t=%g "
                "sec\n",
                nIterNonLinMax, (real_T)ssGetT(S));
        ssSetErrorStatus(S, msg);
    }
}

#define MDL_UPDATE
/* Function: mdlUpdate =============================================================================
 * Abstract:
 *      x(k+1) = Ax(k) + Bu0(k)
 */
static void mdlUpdate(SimStruct* S, int_T tid) {
    InputRealPtrsType u0Ptrs = ssGetInputPortRealSignalPtrs(S, 0);
    real_T*           xD     = ssGetRealDiscStates(S);

    int_T xDSize = ssGetNumDiscStates(S);

    /* recuperer Linear like previous mdlOuput */
    const real_T* As    = (real_T*)ssGetPWorkValue(S, AS);
    const real_T* Bs    = (real_T*)ssGetPWorkValue(S, BS);
    real_T*       xtmp  = (real_T*)ssGetPWorkValue(S, XTMP);
    real_T*       xLast = (real_T*)ssGetPWorkValue(S, XLAST);
    real_T*       uLast = (real_T*)ssGetPWorkValue(S, ULAST);
    real_T*       xkp12 = (real_T*)ssGetPWorkValue(S, XKP12);

    const int_T nStates = ssGetIWorkValue(S, NSTATES);
    /*
     * // todo nstate tot
     * //const int_T       nStates_tot = ssGetIWorkValue(S, NSTATES);
     */
    const int_T nInputs         = ssGetIWorkValue(S, NINPUT);
    const int_T nSwitch         = ssGetIWorkValue(S, NSWITCH);
    const int_T nStatesXnStates = ssGetIWorkValue(S, NSTATES_NSTATES);
    const int_T nStatesXnInputs = ssGetIWorkValue(S, NSTATES_NINPUTS);

    int_T nStep = ssGetIWorkValue(S, NSTEP);

    int_T TBEon = 0;

    int_T iStates /*, iInputs, kAs, kBs */;

    int_T SwitchesHaveChanged = ssGetIWorkValue(S, SWITCHES_HAVE_CHANGED);

    int_T i, j;
    /*real_T     accum;*/

    /* get the new arrays*/
    emxArray_real_T* A_Global = (emxArray_real_T*)ssGetPWorkValue(S, A_GLOBAL);
    emxArray_real_T* B_Global = (emxArray_real_T*)ssGetPWorkValue(S, B_GLOBAL);

    emxArray_real_T*  U0_histLsat        = (emxArray_real_T*)ssGetPWorkValue(S, U0_HIST_LSAT);
    emxArray_real_T*  xDLsat             = (emxArray_real_T*)ssGetPWorkValue(S, XD_LSAT);
    emxArray_int32_T* nonLinearLsatInt32 = (emxArray_int32_T*)ssGetPWorkValue(S, NONLINEAR_LSAT);
    emxArray_int32_T* NonLinear_OutputsInt32 =
        (emxArray_int32_T*)ssGetPWorkValue(S, NONLINEAR_OUTPUTS);

    real_T* y = ssGetOutputPortRealSignal(S, 0);

    /*
     * emxArray_real_T  *C_Global = (emxArray_real_T*)ssGetPWorkValue(S, C_GLOBAL);
     * emxArray_real_T  *D_Global = (emxArray_real_T*)ssGetPWorkValue(S, D_GLOBAL);
     */
    /* Calculate new states... */


    /************************ TBE ALGORITHM *************************/

    if (nSwitch) {
        TBEon = (int)mxGetScalar(TBE_ON(S));
    }
    if (TBEon) {
        memcpy(xLast, xD, nStates * sizeof(real_T)); /* save xLast before write xD */
        for (j = 0; j < nInputs; j++) {
            uLast[j] = U0(j) + U0_histLsat->data[j];
        }
    }
    if (TBEon && SwitchesHaveChanged && nStep > 0) {
        /* When a switch operation occurs, we replace
         * the Tustin update by two half-steps BE so as to
         * dampen Tustin's own digital oscillations.
         * In addition, in the "Update Outputs" section, the outputs
         * are recalculated with states corrected in a way
         * eliminate the "glitch" that remains with the CDA technique of EMTP.
         * These corrected states are obtained by interpolation of the BE states
         * xkm12 and xkp12 obtained respectively a (t-Ts / 2) and (t + Ts / 2)
         *
         * Relations between Tustin (Ts) and Backward-Euler (Ts / 2) discretization
         *   x_BE = x_Tustin
         *   A_BE = (A_Tustin+I)/2 = (Asw+I)/2
         *   B_BE = B_Tustin/2     = Bsw/2
         *   C_BE = C_Tustin       = Csw
         *   D_BE = D_Tustin       = Dsw
         *
         * Backward-Euler update
         * Carry out a half-step BE from states xkp12 at t + Ts / 2
         * calcules dans la sections "Update Outputs"
         * --> sys = BE states = Tustin states updated to use the next step (t + Ts)
         * xkp1 = (Asw+I)/2*xkp12 + Bsw/2*u(1:NINPUT); */


        memset(xtmp, '\0', xDSize * sizeof(real_T));
        /*
         * // matrix A
         * // scan col
         */
        for (j = 0; j < nStates; j++) {
            /* scan row*/
            for (i = 0; i < nStates; i++) {
                xtmp[i] += ((i == j) ? (As[j * nStates + i] + 1) * 0.5 * xkp12[j]
                                     : As[j * nStates + i] * 0.5 * xkp12[j]);
            }
        }

        /*
         * // matrix B
         * // scan col
         */
        for (j = nSwitch; j < nInputs; j++) {
            /* scan row*/
            for (i = 0; i < nStates; i++) {
                xtmp[i] += Bs[j * nStates + i] * 0.5 * (U0(j) + U0_histLsat->data[j]);
            }
        }

    } else {

        memset(xtmp, '\0', xDSize * sizeof(real_T));

        iStates = 0;
        /* loop column */
        for (j = 0; j < nStates; j++) {
            /* loop row*/
            for (i = 0; i < nStates; i++) {
                xtmp[i] += As[iStates++] * xD[j];
            }
        }


        iStates = nSwitch * nStates;
        /* loop column*/
        for (j = nSwitch; j < nInputs; j++) {
            /* loop row*/
            for (i = 0; i < nStates; i++) {
                xtmp[i] += Bs[iStates++] * (U0(j) + U0_histLsat->data[j]);
            }
        }
    }

    /*
     * // Mettre a jour les etats non lineaires discrets phid des elements Lsat
     * // et les conserver dans xNonLinearDisc
     * // Discretisation Tustin et BE->phid(k + 1) = phid(k) + VL / (k)
     * // 1 / L = Y_NonLinearIterative(iNonLin)
     */
    if (nonLinearLsatInt32 != NULL) {
        for (i = 0; i < xDLsat->size[0]; i++) {
            j = nonLinearLsatInt32->data[i];
            /* backward EULER et TUSTIN, pareil*/
            xDLsat->data[i] = xDLsat->data[i] + y[NonLinear_OutputsInt32->data[j] - 1];
        }
    }

    /* nstate tot*/
    memcpy(xD, xtmp, xDSize * sizeof(real_T));

    if (nSwitch) {
        /* Store switch gates values for next step */

        InputRealPtrsType u1Ptrs = ssGetInputPortRealSignalPtrs(S, 1);
        int_T*            gate   = (int_T*)ssGetPWorkValue(S, G_STATE);

        for (i = 0; i < nSwitch; ++i) {
            gate[i] = (int_T)U1(i);
        }
    }
    ssSetIWorkValue(S, NSTEP, 12345);
}

/* Functions required to support SimStates
 */
static const char* fieldNames[] = {
    "DiscStates",
    "AS",
    "BS",
    "CS",
    "DS",
    "DX_COL",
    "BD_COL",
    "TMP1",
    "TMP2",
    "XTMP",
    "SWITCH_STATUS",
    "SWITCH_STATUS_INIT",
    "SW_CHG",
    "G_STATE",
    "IDX_SW_CHG",
    "Y_SWITCH",
    "SWITCH_TYPES",
    "IDX_OUT_SW",
};
static const int nFields = sizeof(fieldNames) / sizeof(const char*);

/* Define to indicate that this S-function has the mdlG[S]etSimState method */
#if 1
#if defined(MATLAB_MEX_FILE)
#define MDL_SIM_STATE

static mxArray* mdlGetSimState(SimStruct* S) {
    real_T* xD                 = (real_T*)ssGetRealDiscStates(S);
    real_T* As                 = (real_T*)ssGetPWorkValue(S, AS);
    real_T* Bs                 = (real_T*)ssGetPWorkValue(S, BS);
    real_T* Cs                 = (real_T*)ssGetPWorkValue(S, CS);
    real_T* Ds                 = (real_T*)ssGetPWorkValue(S, DS);
    real_T* DxCol              = (real_T*)ssGetPWorkValue(S, DX_COL);
    real_T* BDcol              = (real_T*)ssGetPWorkValue(S, BD_COL);
    real_T* tmp1               = (real_T*)ssGetPWorkValue(S, TMP1);
    real_T* tmp2               = (real_T*)ssGetPWorkValue(S, TMP2);
    real_T* xtmp               = (real_T*)ssGetPWorkValue(S, XTMP);
    int_T*  switch_status      = (int_T*)ssGetPWorkValue(S, SWITCH_STATUS);
    int_T*  switch_status_init = (int_T*)ssGetPWorkValue(S, SWITCH_STATUS_INIT);
    int_T*  SwitchChange       = (int_T*)ssGetPWorkValue(S, SW_CHG);
    int_T*  gate               = (int_T*)ssGetPWorkValue(S, G_STATE);
    int_T*  idxSwChng          = (int_T*)ssGetPWorkValue(S, IDX_SW_CHG);
    real_T* yswitch            = (real_T*)ssGetPWorkValue(S, Y_SWITCH);
    int_T*  switchType         = (int_T*)ssGetPWorkValue(S, SWITCH_TYPES);
    int_T*  idxOutSw           = (int_T*)ssGetPWorkValue(S, IDX_OUT_SW);

    const int_T nStates  = ssGetIWorkValue(S, NSTATES);
    const int_T nInputs  = ssGetIWorkValue(S, NINPUT);
    const int_T nOutputs = ssGetIWorkValue(S, NOUTPUT);
    const int_T nSwitch  = ssGetIWorkValue(S, NSWITCH);

    /* Create a MATLAB structure to hold the run-time data */
    mxArray* simSnap = mxCreateStructMatrix(1, 1, nFields, fieldNames);

    {
        mxArray* mxD = mxCreateDoubleMatrix(1, nStates, mxREAL);
        memcpy(mxGetPr(mxD), xD, nStates * sizeof(real_T));
        mxSetFieldByNumber(simSnap, 0, 0, mxD);
    }

    {
        mxArray* mAs = mxCreateDoubleMatrix(1, nStates * nStates, mxREAL);
        memcpy(mxGetPr(mAs), &As[0], nStates * nStates * sizeof(real_T));
        mxSetFieldByNumber(simSnap, 0, 1, mAs);
    }
    {
        mxArray* mBs = mxCreateDoubleMatrix(1, nStates * nInputs, mxREAL);
        memcpy(mxGetPr(mBs), &Bs[0], nStates * nInputs * sizeof(real_T));
        mxSetFieldByNumber(simSnap, 0, 2, mBs);
    }
    {
        mxArray* mCs = mxCreateDoubleMatrix(1, nOutputs * nStates, mxREAL);
        memcpy(mxGetPr(mCs), &Cs[0], nOutputs * nStates * sizeof(real_T));
        mxSetFieldByNumber(simSnap, 0, 3, mCs);
    }
    {
        mxArray* mDs = mxCreateDoubleMatrix(1, nOutputs * nInputs, mxREAL);
        memcpy(mxGetPr(mDs), &Ds[0], nOutputs * nInputs * sizeof(real_T));
        mxSetFieldByNumber(simSnap, 0, 4, mDs);
    }
    {
        mxArray* mDxCol = mxCreateDoubleMatrix(1, nOutputs, mxREAL);
        memcpy(mxGetPr(mDxCol), DxCol, nOutputs * sizeof(real_T));
        mxSetFieldByNumber(simSnap, 0, 5, mDxCol);
    }
    {
        mxArray* mBDcol = mxCreateDoubleMatrix(1, nStates, mxREAL);
        memcpy(mxGetPr(mBDcol), BDcol, nStates * sizeof(real_T));
        mxSetFieldByNumber(simSnap, 0, 6, mBDcol);
    }
    {
        mxArray* mtmp1 = mxCreateDoubleMatrix(1, nStates, mxREAL);
        memcpy(mxGetPr(mtmp1), tmp1, nStates * sizeof(real_T));
        mxSetFieldByNumber(simSnap, 0, 7, mtmp1);
    }
    {
        mxArray* mtmp2 = mxCreateDoubleMatrix(1, nInputs, mxREAL);
        memcpy(mxGetPr(mtmp2), tmp2, nInputs * sizeof(real_T));
        mxSetFieldByNumber(simSnap, 0, 8, mtmp2);
    }
    {
        mxArray* mxtmp = mxCreateDoubleMatrix(1, nStates, mxREAL);
        memcpy(mxGetPr(mxtmp), xtmp, nStates * sizeof(real_T));
        mxSetFieldByNumber(simSnap, 0, 9, mxtmp);
    }
    if (nSwitch > 0) {
        {
            mxArray* mswitch_status = mxCreateDoubleMatrix(1, nSwitch, mxREAL);
            memcpy(mxGetPr(mswitch_status), switch_status, nSwitch * sizeof(int_T));
            mxSetFieldByNumber(simSnap, 0, 10, mswitch_status);
        }
        {
            mxArray* mswitch_status_init = mxCreateDoubleMatrix(1, nSwitch, mxREAL);
            memcpy(mxGetPr(mswitch_status_init), switch_status_init, nSwitch * sizeof(int_T));
            mxSetFieldByNumber(simSnap, 0, 11, mswitch_status_init);
        }
        {
            mxArray* mSwitchChange = mxCreateDoubleMatrix(1, nSwitch, mxREAL);
            memcpy(mxGetPr(mSwitchChange), SwitchChange, nSwitch * sizeof(int_T));
            mxSetFieldByNumber(simSnap, 0, 12, mSwitchChange);
        }
        {
            mxArray* mgState = mxCreateDoubleMatrix(1, nSwitch, mxREAL);
            memcpy(mxGetPr(mgState), gate, nSwitch * sizeof(int_T));
            mxSetFieldByNumber(simSnap, 0, 13, mgState);
        }
        {
            mxArray* midxSwChng = mxCreateDoubleMatrix(1, nSwitch, mxREAL);
            memcpy(mxGetPr(midxSwChng), idxSwChng, nSwitch * sizeof(int_T));
            mxSetFieldByNumber(simSnap, 0, 14, midxSwChng);
        }
        {
            mxArray* myswitch = mxCreateDoubleMatrix(1, nSwitch, mxREAL);
            memcpy(mxGetPr(myswitch), yswitch, nSwitch * sizeof(real_T));
            mxSetFieldByNumber(simSnap, 0, 15, myswitch);
        }
        {
            mxArray* mswitchType = mxCreateDoubleMatrix(1, nSwitch, mxREAL);
            memcpy(mxGetPr(mswitchType), switchType, nSwitch * sizeof(int_T));
            mxSetFieldByNumber(simSnap, 0, 16, mswitchType);
        }
        {
            mxArray* midxOutSw = mxCreateDoubleMatrix(1, nSwitch, mxREAL);
            memcpy(mxGetPr(midxOutSw), idxOutSw, nSwitch * sizeof(int_T));
            mxSetFieldByNumber(simSnap, 0, 17, midxOutSw);
        }
    }
    return simSnap;
}

/* Function: mdlSetSimState ========================================================================
 * Abstract:
 *   Unpack the MATLAB structure passed and restore it into the RunTimeData
 *   structure
 */
static void mdlSetSimState(SimStruct* S, const mxArray* simSnap) {
    real_T* xD                 = (real_T*)ssGetRealDiscStates(S);
    real_T* As                 = (real_T*)ssGetPWorkValue(S, AS);
    real_T* Bs                 = (real_T*)ssGetPWorkValue(S, BS);
    real_T* Cs                 = (real_T*)ssGetPWorkValue(S, CS);
    real_T* Ds                 = (real_T*)ssGetPWorkValue(S, DS);
    real_T* DxCol              = (real_T*)ssGetPWorkValue(S, DX_COL);
    real_T* BDcol              = (real_T*)ssGetPWorkValue(S, BD_COL);
    real_T* tmp1               = (real_T*)ssGetPWorkValue(S, TMP1);
    real_T* tmp2               = (real_T*)ssGetPWorkValue(S, TMP2);
    real_T* xtmp               = (real_T*)ssGetPWorkValue(S, XTMP);
    int_T*  switch_status      = (int_T*)ssGetPWorkValue(S, SWITCH_STATUS);
    int_T*  switch_status_init = (int_T*)ssGetPWorkValue(S, SWITCH_STATUS_INIT);
    int_T*  SwitchChange       = (int_T*)ssGetPWorkValue(S, SW_CHG);
    int_T*  gate               = (int_T*)ssGetPWorkValue(S, G_STATE);
    int_T*  idxSwChng          = (int_T*)ssGetPWorkValue(S, IDX_SW_CHG);
    real_T* yswitch            = (real_T*)ssGetPWorkValue(S, Y_SWITCH);
    int_T*  switchType         = (int_T*)ssGetPWorkValue(S, SWITCH_TYPES);
    int_T*  idxOutSw           = (int_T*)ssGetPWorkValue(S, IDX_OUT_SW);

    const int_T nStates  = ssGetIWorkValue(S, NSTATES);
    const int_T nInputs  = ssGetIWorkValue(S, NINPUT);
    const int_T nOutputs = ssGetIWorkValue(S, NOUTPUT);
    const int_T nSwitch  = ssGetIWorkValue(S, NSWITCH);

    {
        const mxArray* mxD = mxGetField(simSnap, 0, fieldNames[0]);
        memcpy(xD, mxGetPr(mxD), nStates * sizeof(real_T));
    }

    {
        const mxArray* mAs = mxGetField(simSnap, 0, fieldNames[1]);
        memcpy(As, mxGetPr(mAs), nStates * nStates * sizeof(real_T));
    }

    {
        const mxArray* mBs = mxGetField(simSnap, 0, fieldNames[2]);
        memcpy(Bs, mxGetPr(mBs), nStates * nInputs * sizeof(real_T));
    }
    {
        const mxArray* mCs = mxGetField(simSnap, 0, fieldNames[3]);
        memcpy(Cs, mxGetPr(mCs), nOutputs * nStates * sizeof(real_T));
    }
    {
        const mxArray* mDs = mxGetField(simSnap, 0, fieldNames[4]);
        memcpy(Ds, mxGetPr(mDs), nOutputs * nInputs * sizeof(real_T));
    }
    {
        const mxArray* mDxCol = mxGetField(simSnap, 0, fieldNames[5]);
        memcpy(DxCol, mxGetPr(mDxCol), nOutputs * sizeof(real_T));
    }
    {
        const mxArray* mBDcol = mxGetField(simSnap, 0, fieldNames[6]);
        memcpy(BDcol, mxGetPr(mBDcol), nStates * sizeof(real_T));
    }
    {
        const mxArray* mtmp1 = mxGetField(simSnap, 0, fieldNames[7]);
        memcpy(tmp1, mxGetPr(mtmp1), nStates * sizeof(real_T));
    }
    {
        const mxArray* mtmp2 = mxGetField(simSnap, 0, fieldNames[8]);
        memcpy(tmp2, mxGetPr(mtmp2), nInputs * sizeof(real_T));
    }
    {
        const mxArray* mxtmp = mxGetField(simSnap, 0, fieldNames[9]);
        memcpy(xtmp, mxGetPr(mxtmp), nStates * sizeof(real_T));
    }

    if (nSwitch > 0) {
        {
            const mxArray* mswitch_status = mxGetField(simSnap, 0, fieldNames[10]);
            memcpy(switch_status, mxGetPr(mswitch_status), nSwitch * sizeof(int_T));
        }
        {
            const mxArray* mswitch_status_init = mxGetField(simSnap, 0, fieldNames[11]);
            memcpy(switch_status_init, mxGetPr(mswitch_status_init), nSwitch * sizeof(int_T));
        }
        {
            const mxArray* mSwitchChange = mxGetField(simSnap, 0, fieldNames[12]);
            memcpy(SwitchChange, mxGetPr(mSwitchChange), nSwitch * sizeof(int_T));
        }
        {
            const mxArray* mgState = mxGetField(simSnap, 0, fieldNames[13]);
            memcpy(gate, mxGetPr(mgState), nSwitch * sizeof(int_T));
        }
        {
            const mxArray* midxSwChng = mxGetField(simSnap, 0, fieldNames[14]);
            memcpy(idxSwChng, mxGetPr(midxSwChng), nSwitch * sizeof(int_T));
        }
        {
            const mxArray* myswitch = mxGetField(simSnap, 0, fieldNames[15]);
            memcpy(yswitch, mxGetPr(myswitch), nSwitch * sizeof(real_T));
        }
        {
            const mxArray* mswitchType = mxGetField(simSnap, 0, fieldNames[16]);
            memcpy(switchType, mxGetPr(mswitchType), nSwitch * sizeof(int_T));
        }
        {
            const mxArray* midxOutSw = mxGetField(simSnap, 0, fieldNames[17]);
            memcpy(idxOutSw, mxGetPr(midxOutSw), nSwitch * sizeof(int_T));
        }
    }
    ssSetIWorkValue(S, NSTEP, 0);
}

#endif
#endif
/* Function: mdlTerminate */
static void mdlTerminate(SimStruct* S) {
    int_T             i;
    emxArray_real_T*  matrixPtr;
    emxArray_int32_T* matrixIntPtr;

    const int_T nNonLinear       = (int)mxGetM(DSS_Dim_PARAM(S));
    real_T      timeNoSwitchConv = ssGetRWorkValue(S, TIME_NO_SWITCH_CONV);

#ifdef DEBUG
    /* code elimine*/
#endif

    if (timeNoSwitchConv >= 0.0) {
        static char msg[200];
        sprintf(msg,
                "Failed to converge on switch status after %i iterations at t=%g sec (first "
                "occurrence).\nSimulation results for t>=%g sec may be inaccurate",
                MAX_ITERATION, timeNoSwitchConv, timeNoSwitchConv);
        ssWarning(S, msg);
    }

    /* on doit liberer a la mitaine...*/
    if (nNonLinear) {

        matrixPtr = (emxArray_real_T*)ssGetPWorkValue(S, A_GLOBAL);
        emxFree_real_T(&matrixPtr);
        matrixPtr = (emxArray_real_T*)ssGetPWorkValue(S, B_GLOBAL);
        emxFree_real_T(&matrixPtr);
        matrixPtr = (emxArray_real_T*)ssGetPWorkValue(S, C_GLOBAL);
        emxFree_real_T(&matrixPtr);
        matrixPtr = (emxArray_real_T*)ssGetPWorkValue(S, D_GLOBAL);
        emxFree_real_T(&matrixPtr);

        matrixPtr = (emxArray_real_T*)ssGetPWorkValue(S, D12D2);
        emxFree_real_T(&matrixPtr);
        matrixPtr = (emxArray_real_T*)ssGetPWorkValue(S, EYEMATRIX);
        emxFree_real_T(&matrixPtr);
        matrixPtr = (emxArray_real_T*)ssGetPWorkValue(S, WI12);
        emxFree_real_T(&matrixPtr);
        matrixPtr = (emxArray_real_T*)ssGetPWorkValue(S, RESULTINV1);
        emxFree_real_T(&matrixPtr);
        matrixPtr = (emxArray_real_T*)ssGetPWorkValue(S, RESULTINV2);
        emxFree_real_T(&matrixPtr);
        matrixPtr = (emxArray_real_T*)ssGetPWorkValue(S, WORKINGC1);
        emxFree_real_T(&matrixPtr);
        matrixPtr = (emxArray_real_T*)ssGetPWorkValue(S, WORKINGC2);
        emxFree_real_T(&matrixPtr);
        matrixPtr = (emxArray_real_T*)ssGetPWorkValue(S, WORKINGD1);
        emxFree_real_T(&matrixPtr);
        matrixPtr = (emxArray_real_T*)ssGetPWorkValue(S, WORKINGD2);
        emxFree_real_T(&matrixPtr);
        matrixPtr = (emxArray_real_T*)ssGetPWorkValue(S, WORKINGINV0);
        emxFree_real_T(&matrixPtr);

        matrixIntPtr = (emxArray_int32_T*)ssGetPWorkValue(S, WORKINGINV1);
        emxFree_int32_T(&matrixIntPtr);
        matrixIntPtr = (emxArray_int32_T*)ssGetPWorkValue(S, WORKINGINV2);
        emxFree_int32_T(&matrixIntPtr);

        matrixPtr = (emxArray_real_T*)ssGetPWorkValue(S, MMATRIX);
        emxFree_real_T(&matrixPtr);
        matrixPtr = (emxArray_real_T*)ssGetPWorkValue(S, RESULT1);
        emxFree_real_T(&matrixPtr);
        matrixPtr = (emxArray_real_T*)ssGetPWorkValue(S, RESULT2);
        emxFree_real_T(&matrixPtr);

        matrixIntPtr = (emxArray_int32_T*)ssGetPWorkValue(S, REFROWS);
        emxFree_int32_T(&matrixIntPtr);
        matrixIntPtr = (emxArray_int32_T*)ssGetPWorkValue(S, REFCOLS);
        emxFree_int32_T(&matrixIntPtr);
        matrixPtr = (emxArray_real_T*)ssGetPWorkValue(S, RESHAPEMATRIX);
        emxFree_real_T(&matrixPtr);

        matrixPtr = (emxArray_real_T*)ssGetPWorkValue(S, D_NONLINEAR_DISC);
        emxFree_real_T(&matrixPtr);
        matrixPtr = (emxArray_real_T*)ssGetPWorkValue(S, Y_NONLINEAR_ITERATIVE);
        emxFree_real_T(&matrixPtr);
        matrixPtr = (emxArray_real_T*)ssGetPWorkValue(S, Y_NONLINEAR_ITERATIVE_LAST);
        emxFree_real_T(&matrixPtr);

        matrixIntPtr = (emxArray_int32_T*)ssGetPWorkValue(S, STOP_ITER_NONLINEAR);
        emxFree_int32_T(&matrixIntPtr);
        matrixIntPtr = (emxArray_int32_T*)ssGetPWorkValue(S, NONLINEAR_DIM);
        emxFree_int32_T(&matrixIntPtr);
        matrixIntPtr = (emxArray_int32_T*)ssGetPWorkValue(S, NONLINEAR_INPUTS);
        emxFree_int32_T(&matrixIntPtr);
        matrixIntPtr = (emxArray_int32_T*)ssGetPWorkValue(S, NONLINEAR_OUTPUTS);
        emxFree_int32_T(&matrixIntPtr);
        matrixIntPtr = (emxArray_int32_T*)ssGetPWorkValue(S, NONLINEAR_ITERATIVE);
        emxFree_int32_T(&matrixIntPtr);
        matrixIntPtr = (emxArray_int32_T*)ssGetPWorkValue(S, NONLINEAR_METHOD);
        emxFree_int32_T(&matrixIntPtr);


        matrixIntPtr = (emxArray_int32_T*)ssGetPWorkValue(S, NONLINEAR_SIZE_VI);
        emxFree_int32_T(&matrixIntPtr);

        matrixPtr = (emxArray_real_T*)ssGetPWorkValue(S, NONLINEAR_VI);
        emxFree_real_T(&matrixPtr);

        matrixIntPtr = (emxArray_int32_T*)ssGetPWorkValue(S, NOSEG);
        emxFree_int32_T(&matrixIntPtr);

        matrixIntPtr = (emxArray_int32_T*)ssGetPWorkValue(S, NOSEG_LAST);
        emxFree_int32_T(&matrixIntPtr);

        matrixPtr = (emxArray_real_T*)ssGetPWorkValue(S, ASEG);
        emxFree_real_T(&matrixPtr);
        matrixPtr = (emxArray_real_T*)ssGetPWorkValue(S, BSEG);
        emxFree_real_T(&matrixPtr);
        /*matrixPtr = (emxArray_real_T*)ssGetPWorkValue(S, WI);*/
        emxFree_real_T(&matrixPtr);
        matrixPtr = (emxArray_real_T*)ssGetPWorkValue(S, U_ARRAY);
        emxFree_real_T(&matrixPtr);

        matrixIntPtr = (emxArray_int32_T*)ssGetPWorkValue(S, NONLINEAR_LSAT);
        emxFree_int32_T(&matrixIntPtr);

        matrixPtr = (emxArray_real_T*)ssGetPWorkValue(S, XD_LSAT);
        emxFree_real_T(&matrixPtr);
        matrixPtr = (emxArray_real_T*)ssGetPWorkValue(S, U0_HIST_LSAT);
        emxFree_real_T(&matrixPtr);

        matrixPtr = (emxArray_real_T*)ssGetPWorkValue(S, Y_ARRAY);
        emxFree_real_T(&matrixPtr);
        matrixPtr = (emxArray_real_T*)ssGetPWorkValue(S, Y_X_NONLINEAR);
        emxFree_real_T(&matrixPtr);
    } else {
        matrixPtr = (emxArray_real_T*)ssGetPWorkValue(S, A_GLOBAL);
        emxFree_real_T(&matrixPtr);
        matrixPtr = (emxArray_real_T*)ssGetPWorkValue(S, B_GLOBAL);
        emxFree_real_T(&matrixPtr);
        matrixPtr = (emxArray_real_T*)ssGetPWorkValue(S, C_GLOBAL);
        emxFree_real_T(&matrixPtr);
        matrixPtr = (emxArray_real_T*)ssGetPWorkValue(S, D_GLOBAL);
        emxFree_real_T(&matrixPtr);
    }

    /* free pointers saved */
    /*
     * for (i = 0; i < ssGetNumPWork(S); i++)
     * if (ssGetPWorkValue(S, i) != NULL)
     * free(ssGetPWorkValue(S, i));
     */
    for (i = 0; i < D_NONLINEAR_DISC; i++) {
        if (ssGetPWorkValue(S, i) != NULL) {
            free(ssGetPWorkValue(S, i));
        }
    }

    for (i = Y_ARRAY + 1; i < N_PWORKS; i++) {
        if (ssGetPWorkValue(S, i) != NULL) {
            free(ssGetPWorkValue(S, i));
        }
    }
}


#ifdef MATLAB_MEX_FILE /* Is this file being compiled as a MEX-file? */
#include "simulink.c"  /* MEX-file interface mechanism */
#else
#include "cg_sfun.h" /* Code generation registration function */
#endif
