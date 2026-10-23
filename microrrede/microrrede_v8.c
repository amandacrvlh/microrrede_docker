/*
 * File: microrrede_v8.c
 *
 * Code generated for Simulink model 'microrrede_v8'.
 *
 * Model version                  : 1.20
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Aug  7 08:57:15 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "microrrede_v8.h"
#include "rtwtypes.h"
#include "microrrede_v8_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include <float.h>
#include "rt_defines.h"

const real_T microrrede_v8_RGND = 0.0; /* real_T ground */

/* Block signals (default storage) */
B_microrrede_v8_T microrrede_v8_B;

/* Block states (default storage) */
DW_microrrede_v8_T microrrede_v8_DW;

/* External inputs (root inport signals with default storage) */
ExtU_microrrede_v8_T microrrede_v8_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_microrrede_v8_T microrrede_v8_Y;

/* Real-time model */
static RT_MODEL_microrrede_v8_T microrrede_v8_M_;
RT_MODEL_microrrede_v8_T *const microrrede_v8_M = &microrrede_v8_M_;
real_T look1_pbinlxpw(real_T u0, const real_T bp0[], const real_T table[],
                      uint32_T prevIndex[], uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T bpIdx;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'on'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'on'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    bpIdx = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    uint32_T found;
    uint32_T iLeft;
    uint32_T iRght;

    /* Binary Search using Previous Index */
    bpIdx = prevIndex[0U];
    iLeft = 0U;
    iRght = maxIndex;
    found = 0U;
    while (found == 0U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx - 1U;
        bpIdx = ((bpIdx + iLeft) - 1U) >> 1U;
      } else if (u0 < bp0[bpIdx + 1U]) {
        found = 1U;
      } else {
        iLeft = bpIdx + 1U;
        bpIdx = ((bpIdx + iRght) + 1U) >> 1U;
      }
    }

    frac = (u0 - bp0[bpIdx]) / (bp0[bpIdx + 1U] - bp0[bpIdx]);
  } else {
    bpIdx = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  prevIndex[0U] = bpIdx;

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[bpIdx];
  return (table[bpIdx + 1U] - yL_0d0) * frac + yL_0d0;
}

/*
 * System initialize for atomic system:
 *    '<S2>/MATLAB Function'
 *    '<S153>/MATLAB Function'
 *    '<S773>/MATLAB Function'
 */
void microrrede__MATLABFunction_Init(DW_MATLABFunction_microrrede__T *localDW)
{
  localDW->Dold = 260.0;
}

/*
 * Output and update for atomic system:
 *    '<S2>/MATLAB Function'
 *    '<S153>/MATLAB Function'
 *    '<S773>/MATLAB Function'
 */
void microrrede_v8_MATLABFunction(real_T rtu_V, real_T rtu_I, real_T *rty_D,
  DW_MATLABFunction_microrrede__T *localDW)
{
  real_T P;
  real_T dP;
  P = rtu_V * rtu_I;
  dP = P - localDW->Pold;
  if (dP != 0.0) {
    if (dP < 0.0) {
      if (rtu_V - localDW->Vold < 0.0) {
        *rty_D = localDW->Dold + 0.03;
      } else {
        *rty_D = localDW->Dold - 0.03;
      }
    } else if (rtu_V - localDW->Vold < 0.0) {
      *rty_D = localDW->Dold - 0.03;
    } else {
      *rty_D = localDW->Dold + 0.03;
    }
  } else {
    *rty_D = localDW->Dold;
  }

  if ((*rty_D >= 290.0) || (*rty_D <= 230.0)) {
    *rty_D = localDW->Dold;
  }

  localDW->Dold = *rty_D;
  localDW->Vold = rtu_V;
  localDW->Pold = P;
}

/*
 * Output and update for enable system:
 *    '<S312>/Subsystem - pi//2 delay'
 *    '<S614>/Subsystem - pi//2 delay'
 *    '<S932>/Subsystem - pi//2 delay'
 */
void microrrede_v8_Subsystempi2delay(uint8_T rtu_Enable, real_T rtu_alpha_beta,
  real_T rtu_alpha_beta_c, real_T rtu_wt, real_T *rty_dq, real_T *rty_dq_a)
{
  /* Outputs for Enabled SubSystem: '<S312>/Subsystem - pi//2 delay' incorporates:
   *  EnablePort: '<S316>/Enable'
   */
  if (rtu_Enable > 0) {
    real_T tmp;
    real_T tmp_0;

    /* Fcn: '<S316>/Fcn' incorporates:
     *  Fcn: '<S316>/Fcn1'
     */
    tmp = cos(rtu_wt);
    tmp_0 = sin(rtu_wt);
    *rty_dq = rtu_alpha_beta * tmp_0 - rtu_alpha_beta_c * tmp;

    /* Fcn: '<S316>/Fcn1' */
    *rty_dq_a = rtu_alpha_beta * tmp + rtu_alpha_beta_c * tmp_0;
  }

  /* End of Outputs for SubSystem: '<S312>/Subsystem - pi//2 delay' */
}

/*
 * Output and update for enable system:
 *    '<S312>/Subsystem1'
 *    '<S614>/Subsystem1'
 *    '<S932>/Subsystem1'
 */
void microrrede_v8_Subsystem1(uint8_T rtu_Enable, real_T rtu_alpha_beta, real_T
  rtu_alpha_beta_k, real_T rtu_wt, real_T *rty_dq, real_T *rty_dq_k)
{
  /* Outputs for Enabled SubSystem: '<S312>/Subsystem1' incorporates:
   *  EnablePort: '<S317>/Enable'
   */
  if (rtu_Enable > 0) {
    real_T tmp;
    real_T tmp_0;

    /* Fcn: '<S317>/Fcn' incorporates:
     *  Fcn: '<S317>/Fcn1'
     */
    tmp = sin(rtu_wt);
    tmp_0 = cos(rtu_wt);
    *rty_dq = rtu_alpha_beta * tmp_0 + rtu_alpha_beta_k * tmp;

    /* Fcn: '<S317>/Fcn1' */
    *rty_dq_k = -rtu_alpha_beta * tmp + rtu_alpha_beta_k * tmp_0;
  }

  /* End of Outputs for SubSystem: '<S312>/Subsystem1' */
}

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (rtIsInf(u1)) {
    y = u0;
  } else if ((u1 != 0.0) && (u1 != trunc(u1))) {
    real_T q;
    q = fabs(u0 / u1);
    if (!(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q)) {
      y = 0.0 * u0;
    } else {
      y = fmod(u0, u1);
    }
  } else {
    y = fmod(u0, u1);
  }

  return y;
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    int32_T tmp;
    int32_T tmp_0;
    if (u0 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u1 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = atan2(tmp, tmp_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T a;
  real_T b;
  real_T y;
  a = fabs(u0);
  b = fabs(u1);
  if (a < b) {
    a /= b;
    y = sqrt(a * a + 1.0) * b;
  } else if (a > b) {
    b /= a;
    y = sqrt(b * b + 1.0) * a;
  } else if (rtIsNaN(b)) {
    y = (rtNaN);
  } else {
    y = a * 1.4142135623730951;
  }

  return y;
}

/* Model step function */
void microrrede_v8_step(void)
{
  real_T DataTypeConversion_tmp;
  real_T Initial;
  real_T numAccum;
  real_T rtb_A21;
  real_T rtb_A21_c;
  real_T rtb_A21_p;
  real_T rtb_Add4;
  real_T rtb_Divide1_idx_0_tmp;
  real_T rtb_Fcn6;
  real_T rtb_Gain;
  real_T rtb_Gain3_m;
  real_T rtb_IntegralGain;
  real_T rtb_Integrator_bx_tmp;
  real_T rtb_Integrator_c_idx_1;
  real_T rtb_Integrator_e;
  real_T rtb_Integrator_h;
  real_T rtb_Integrator_jg;
  real_T rtb_Integrator_l;
  real_T rtb_Integrator_m;
  real_T rtb_Numberofsamplespercycle;
  real_T rtb_Numberofsamplespercycle_e;
  real_T rtb_Numberofsamplespercycle_ej;
  real_T rtb_Numberofsamplespercycle_f;
  real_T rtb_Numberofsamplespercycle_lo;
  real_T rtb_Numberofsamplespercycle_mb;
  real_T rtb_Product1_f_tmp;
  real_T rtb_RateLimiter;
  real_T rtb_RoundingFunction;
  real_T rtb_RoundingFunction_ay;
  real_T rtb_RoundingFunction_d4;
  real_T rtb_RoundingFunction_go;
  real_T rtb_RoundingFunction_je;
  real_T rtb_RoundingFunction_jv;
  real_T rtb_RoundingFunction_m;
  real_T rtb_Saturation1;
  real_T rtb_Saturation1_k;
  real_T rtb_Saturation_d;
  real_T rtb_Sum5_ij;
  real_T rtb_Switch7;
  real_T rtb_uR_j;
  real_T rtb_x2k;
  uint8_T rtb_Compare;
  boolean_T rtb_RelationalOperator1;
  boolean_T rtb_RelationalOperator3;
  boolean_T rtb_RelationalOperator_hn;
  boolean_T rtb_RelationalOperator_mb;
  boolean_T rtb_RelationalOperator_nv;

  /* Gain: '<S39>/R2' incorporates:
   *  Gain: '<S39>/R3'
   *  Memory: '<S39>/it init1'
   */
  rtb_Fcn6 = 0.9999 * microrrede_v8_DW.itinit1_PreviousInput;

  /* DiscreteTransferFcn: '<S39>/Current filter' */
  numAccum = 1.249992287533086E-5 * microrrede_v8_DW.Currentfilter_states;

  /* RelationalOperator: '<S41>/Compare' incorporates:
   *  Constant: '<S41>/Constant'
   *  DiscreteTransferFcn: '<S39>/Current filter'
   */
  rtb_Compare = (uint8_T)(numAccum > 0.0);

  /* DiscreteIntegrator: '<S39>/int(i)' incorporates:
   *  DataTypeConversion: '<S39>/Data Type Conversion2'
   *  Memory: '<S39>/it init'
   */
  if (microrrede_v8_DW.inti_IC_LOADING != 0) {
    microrrede_v8_DW.inti_DSTATE = microrrede_v8_DW.itinit_PreviousInput;
    if (microrrede_v8_DW.inti_DSTATE > 757499.87880000006) {
      microrrede_v8_DW.inti_DSTATE = 757499.87880000006;
    }
  }

  if ((rtb_Compare > 0) && (microrrede_v8_DW.inti_PrevResetState <= 0)) {
    microrrede_v8_DW.inti_DSTATE = microrrede_v8_DW.itinit_PreviousInput;
    if (microrrede_v8_DW.inti_DSTATE > 757499.87880000006) {
      microrrede_v8_DW.inti_DSTATE = 757499.87880000006;
    }
  }

  /* Gain: '<S39>/Gain' incorporates:
   *  DiscreteIntegrator: '<S39>/int(i)'
   */
  rtb_Gain = 0.00027777777777777778 * microrrede_v8_DW.inti_DSTATE;

  /* Switch: '<S46>/Switch2' incorporates:
   *  Constant: '<S39>/Constant9'
   *  Gain: '<S39>/R2'
   *  RelationalOperator: '<S46>/LowerRelop1'
   *  RelationalOperator: '<S46>/UpperRelop'
   *  Switch: '<S46>/Switch'
   */
  if (rtb_Gain > rtb_Fcn6) {
    rtb_Integrator_h = rtb_Fcn6;
  } else if (rtb_Gain < 0.0) {
    /* Switch: '<S46>/Switch' incorporates:
     *  Constant: '<S39>/Constant9'
     */
    rtb_Integrator_h = 0.0;
  } else {
    rtb_Integrator_h = rtb_Gain;
  }

  /* End of Switch: '<S46>/Switch2' */

  /* Switch: '<S39>/Switch7' incorporates:
   *  Fcn: '<S39>/Fcn9'
   *  Gain: '<S39>/R2'
   *  RelationalOperator: '<S39>/Relational Operator'
   */
  if (1.000001 * rtb_Fcn6 * 0.99009900990099009 / 0.9999 <= rtb_Integrator_h) {
    rtb_Switch7 = rtb_Fcn6;
  } else {
    rtb_Switch7 = rtb_Integrator_h;
  }

  /* End of Switch: '<S39>/Switch7' */

  /* Switch: '<S47>/Switch2' incorporates:
   *  RelationalOperator: '<S47>/LowerRelop1'
   */
  if (rtb_Gain > rtb_Fcn6) {
    rtb_Gain = rtb_Fcn6;
  } else {
    /* Fcn: '<S39>/Fcn6' */
    rtb_Fcn6 = -rtb_Fcn6 * 0.999 * 0.1 * 0.9999;

    /* Switch: '<S47>/Switch' incorporates:
     *  RelationalOperator: '<S47>/UpperRelop'
     */
    if (rtb_Gain < rtb_Fcn6) {
      rtb_Gain = rtb_Fcn6;
    }

    /* End of Switch: '<S47>/Switch' */
  }

  /* End of Switch: '<S47>/Switch2' */

  /* Fcn: '<S39>/E_dyn Discharge' incorporates:
   *  Fcn: '<S39>/E_NL'
   *  Memory: '<S39>/it init1'
   */
  rtb_Fcn6 = microrrede_v8_DW.itinit1_PreviousInput - rtb_Switch7;

  /* Sum: '<S39>/Add3' incorporates:
   *  Constant: '<S39>/Constant'
   *  Constant: '<S42>/Constant'
   *  DataTypeConversion: '<S39>/Data Type Conversion1'
   *  DataTypeConversion: '<S39>/Data Type Conversion2'
   *  DiscreteIntegrator: '<S44>/Discrete-Time Integrator'
   *  DiscreteTransferFcn: '<S39>/Current filter'
   *  Fcn: '<S39>/E_NL'
   *  Fcn: '<S39>/E_dyn Discharge'
   *  Fcn: '<S39>/Fcn5'
   *  Fcn: '<S43>/Charge Lead-Acid'
   *  Memory: '<S39>/it init1'
   *  MultiPortSwitch: '<S43>/Multiport Switch1'
   *  Product: '<S43>/Product3'
   *  RelationalOperator: '<S42>/Compare'
   *  Sum: '<S39>/Add2'
   */
  microrrede_v8_B.Switch2 = ((((-(real_T)rtb_Compare * 0.00012587940635096274 *
    numAccum * microrrede_v8_DW.itinit1_PreviousInput / rtb_Fcn6 +
    -0.00012587940635096274 * microrrede_v8_DW.itinit1_PreviousInput / rtb_Fcn6 *
    rtb_Switch7) + -(real_T)(numAccum < 0.0) * 0.00012587940635096274 * numAccum
    * (210.41663300000002 / (rtb_Gain + 21.041663300000003))) +
    microrrede_v8_DW.DiscreteTimeIntegrator_DSTATE) + -0.0 * rtb_Switch7) +
    48.268958577459159;

  /* Switch: '<S45>/Switch2' incorporates:
   *  Constant: '<S39>/Constant1'
   *  Memory: '<S39>/Memory2'
   *  RelationalOperator: '<S45>/LowerRelop1'
   *  RelationalOperator: '<S45>/UpperRelop'
   *  Switch: '<S45>/Switch'
   */
  if (microrrede_v8_B.Switch2 > 96.537917154918318) {
    /* Sum: '<S39>/Add3' incorporates:
     *  Switch: '<S45>/Switch2'
     */
    microrrede_v8_B.Switch2 = 96.537917154918318;
  } else if (microrrede_v8_B.Switch2 < microrrede_v8_DW.Memory2_PreviousInput) {
    /* Sum: '<S39>/Add3' incorporates:
     *  Memory: '<S39>/Memory2'
     *  Switch: '<S45>/Switch'
     *  Switch: '<S45>/Switch2'
     */
    microrrede_v8_B.Switch2 = microrrede_v8_DW.Memory2_PreviousInput;
  }

  /* End of Switch: '<S45>/Switch2' */

  /* UnitDelay: '<S676>/Unit Delay' */
  microrrede_v8_B.UnitDelay = microrrede_v8_DW.UnitDelay_DSTATE;

  /* Gain: '<S679>/1//Sref' incorporates:
   *  Inport: '<Root>/Fator1'
   *  Inport: '<Root>/Irr1'
   *  Product: '<Root>/Product'
   */
  rtb_Integrator_e = microrrede_v8_U.Irr1 * microrrede_v8_U.Fator1 * 0.001;

  /* Product: '<S679>/Product1' */
  microrrede_v8_B.IL = microrrede_v8_ConstB.Add * rtb_Integrator_e;

  /* UnitDelay: '<S688>/Unit Delay' */
  microrrede_v8_B.UnitDelay_i = microrrede_v8_DW.UnitDelay_DSTATE_c;

  /* Gain: '<S691>/1//Sref' incorporates:
   *  Inport: '<Root>/Fator2'
   *  Inport: '<Root>/Irr2'
   *  Product: '<Root>/Product2'
   */
  rtb_Integrator_jg = microrrede_v8_U.Irr2 * microrrede_v8_U.Fator2 * 0.001;

  /* Product: '<S691>/Product1' */
  microrrede_v8_B.IL_f = microrrede_v8_ConstB.Add_ko * rtb_Integrator_jg;

  /* UnitDelay: '<S700>/Unit Delay' */
  microrrede_v8_B.UnitDelay_f = microrrede_v8_DW.UnitDelay_DSTATE_d;

  /* Gain: '<S703>/1//Sref' incorporates:
   *  Inport: '<Root>/Fator3'
   *  Inport: '<Root>/Irr3'
   *  Product: '<Root>/Product1'
   */
  rtb_Integrator_h = microrrede_v8_U.Irr3 * microrrede_v8_U.Fator3 * 0.001;

  /* Product: '<S703>/Product1' */
  microrrede_v8_B.IL_b = microrrede_v8_ConstB.Add_n * rtb_Integrator_h;

  /* Sin: '<S152>/Sine Wave A' */
  if (microrrede_v8_DW.systemEnable != 0) {
    rtb_Gain = 376.99111843077515 * microrrede_v8_M->Timing.t[0];
    microrrede_v8_DW.lastSin = sin(rtb_Gain);
    microrrede_v8_DW.lastCos = cos(rtb_Gain);
    microrrede_v8_DW.systemEnable = 0;
  }

  /* Sin: '<S152>/Sine Wave A' */
  microrrede_v8_B.SineWaveA = ((microrrede_v8_DW.lastSin * 0.99999876629950613 +
    microrrede_v8_DW.lastCos * -0.0015707958064944299) * 0.99999876629950613 +
    (microrrede_v8_DW.lastCos * 0.99999876629950613 - microrrede_v8_DW.lastSin *
     -0.0015707958064944299) * 0.0015707958064944299) * 310.26870075253595;

  /* Sin: '<S152>/Sine Wave B' */
  if (microrrede_v8_DW.systemEnable_d != 0) {
    rtb_Gain = 376.99111843077515 * microrrede_v8_M->Timing.t[0];
    microrrede_v8_DW.lastSin_c = sin(rtb_Gain);
    microrrede_v8_DW.lastCos_l = cos(rtb_Gain);
    microrrede_v8_DW.systemEnable_d = 0;
  }

  /* Sin: '<S152>/Sine Wave B' */
  microrrede_v8_B.SineWaveB = ((microrrede_v8_DW.lastSin_c *
    -0.50135973222233521 + microrrede_v8_DW.lastCos_l * -0.86523893746522318) *
    0.99999876629950613 + (microrrede_v8_DW.lastCos_l * -0.50135973222233521 -
    microrrede_v8_DW.lastSin_c * -0.86523893746522318) * 0.0015707958064944299) *
    310.26870075253595;

  /* Sin: '<S152>/Sine Wave C' */
  if (microrrede_v8_DW.systemEnable_d3 != 0) {
    rtb_Gain = 376.99111843077515 * microrrede_v8_M->Timing.t[0];
    microrrede_v8_DW.lastSin_cr = sin(rtb_Gain);
    microrrede_v8_DW.lastCos_f = cos(rtb_Gain);
    microrrede_v8_DW.systemEnable_d3 = 0;
  }

  /* Sin: '<S152>/Sine Wave C' */
  microrrede_v8_B.SineWaveC = ((microrrede_v8_DW.lastSin_cr *
    -0.49863903407717053 + microrrede_v8_DW.lastCos_f * 0.86680973327171773) *
    0.99999876629950613 + (microrrede_v8_DW.lastCos_f * -0.49863903407717053 -
    microrrede_v8_DW.lastSin_cr * 0.86680973327171773) * 0.0015707958064944299) *
    310.26870075253595;

  /* Switch: '<S758>/Switch' incorporates:
   *  Abs: '<S758>/Abs'
   *  Inport: '<Root>/LoadA'
   *  Signum: '<S758>/Sign'
   */
  if (fabs(microrrede_v8_U.LoadA) > 0.001) {
    rtb_Saturation_d = microrrede_v8_U.LoadA;
  } else {
    if (rtIsNaN(microrrede_v8_U.LoadA)) {
      /* Signum: '<S758>/Sign' */
      rtb_RoundingFunction_jv = (rtNaN);
    } else if (microrrede_v8_U.LoadA < 0.0) {
      /* Signum: '<S758>/Sign' */
      rtb_RoundingFunction_jv = -1.0;
    } else {
      /* Signum: '<S758>/Sign' */
      rtb_RoundingFunction_jv = (microrrede_v8_U.LoadA > 0.0);
    }

    /* Switch: '<S758>/Switch1' incorporates:
     *  Constant: '<S758>/Constant'
     *  Constant: '<S758>/Constant1'
     *  Signum: '<S758>/Sign'
     */
    if (rtb_RoundingFunction_jv > 0.0) {
      rtb_Saturation_d = 0.001;
    } else {
      rtb_Saturation_d = -0.001;
    }

    /* End of Switch: '<S758>/Switch1' */
  }

  /* End of Switch: '<S758>/Switch' */

  /* Product: '<S28>/1//R' incorporates:
   *  Constant: '<S28>/Constant5'
   */
  rtb_Gain = 1.0 / rtb_Saturation_d;

  /* Switch: '<S762>/Switch' incorporates:
   *  Abs: '<S762>/Abs'
   *  Inport: '<Root>/LoadB'
   *  Signum: '<S762>/Sign'
   */
  if (fabs(microrrede_v8_U.LoadB) > 0.001) {
    rtb_Saturation_d = microrrede_v8_U.LoadB;
  } else {
    if (rtIsNaN(microrrede_v8_U.LoadB)) {
      /* Signum: '<S762>/Sign' */
      rtb_RoundingFunction_jv = (rtNaN);
    } else if (microrrede_v8_U.LoadB < 0.0) {
      /* Signum: '<S762>/Sign' */
      rtb_RoundingFunction_jv = -1.0;
    } else {
      /* Signum: '<S762>/Sign' */
      rtb_RoundingFunction_jv = (microrrede_v8_U.LoadB > 0.0);
    }

    /* Switch: '<S762>/Switch1' incorporates:
     *  Constant: '<S762>/Constant'
     *  Constant: '<S762>/Constant1'
     *  Signum: '<S762>/Sign'
     */
    if (rtb_RoundingFunction_jv > 0.0) {
      rtb_Saturation_d = 0.001;
    } else {
      rtb_Saturation_d = -0.001;
    }

    /* End of Switch: '<S762>/Switch1' */
  }

  /* End of Switch: '<S762>/Switch' */

  /* Product: '<S29>/1//R' incorporates:
   *  Constant: '<S29>/Constant5'
   */
  rtb_Fcn6 = 1.0 / rtb_Saturation_d;

  /* Switch: '<S766>/Switch' incorporates:
   *  Abs: '<S766>/Abs'
   *  Inport: '<Root>/LoadC'
   *  Signum: '<S766>/Sign'
   */
  if (fabs(microrrede_v8_U.LoadC) > 0.001) {
    rtb_Saturation_d = microrrede_v8_U.LoadC;
  } else {
    if (rtIsNaN(microrrede_v8_U.LoadC)) {
      /* Signum: '<S766>/Sign' */
      rtb_RoundingFunction_jv = (rtNaN);
    } else if (microrrede_v8_U.LoadC < 0.0) {
      /* Signum: '<S766>/Sign' */
      rtb_RoundingFunction_jv = -1.0;
    } else {
      /* Signum: '<S766>/Sign' */
      rtb_RoundingFunction_jv = (microrrede_v8_U.LoadC > 0.0);
    }

    /* Switch: '<S766>/Switch1' incorporates:
     *  Constant: '<S766>/Constant'
     *  Constant: '<S766>/Constant1'
     *  Signum: '<S766>/Sign'
     */
    if (rtb_RoundingFunction_jv > 0.0) {
      rtb_Saturation_d = 0.001;
    } else {
      rtb_Saturation_d = -0.001;
    }

    /* End of Switch: '<S766>/Switch1' */
  }

  /* End of Switch: '<S766>/Switch' */

  /* Product: '<S30>/1//R' incorporates:
   *  Constant: '<S30>/Constant5'
   */
  rtb_uR_j = 1.0 / rtb_Saturation_d;

  /* Sum: '<S998>/Sum' incorporates:
   *  UnitDelay: '<S998>/Unit Delay'
   */
  microrrede_v8_B.Sum[0] = rtb_Gain - microrrede_v8_DW.UnitDelay_DSTATE_g[0];
  microrrede_v8_B.Sum[1] = rtb_Fcn6 - microrrede_v8_DW.UnitDelay_DSTATE_g[1];
  microrrede_v8_B.Sum[2] = rtb_uR_j - microrrede_v8_DW.UnitDelay_DSTATE_g[2];

  /* S-Function (sfun_spssw_discc_DSS): '<S998>/State-Space' incorporates:
   *  Constant: '<S1002>/SwitchCurrents'
   *  Constant: '<S105>/eee'
   *  Constant: '<S369>/eee'
   *  Constant: '<S989>/eee'
   *  Inport: '<Root>/XCBR_CC_1_in'
   *  Inport: '<Root>/XCBR_CC_2_in'
   *  Inport: '<Root>/XCBR_CC_3_in'
   */

  /* Level2 S-Function Block: '<S998>/State-Space' (sfun_spssw_discc_DSS) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[6];
    sfcnOutputs(rts,0);
  }

  /* Outport: '<Root>/XCBR_PCC_out' incorporates:
   *  Inport: '<Root>/XCBR_PCC_in'
   */
  microrrede_v8_Y.XCBR_PCC_out = microrrede_v8_U.XCBR_PCC_in;

  /* Switch: '<S131>/Switch3' incorporates:
   *  Constant: '<S10>/Constant5'
   *  Switch: '<S10>/Switch'
   */
  microrrede_v8_B.Switch3 = 1.0;

  /* Switch: '<S133>/Switch3' incorporates:
   *  Constant: '<S10>/Constant5'
   *  Switch: '<S10>/Switch1'
   */
  microrrede_v8_B.Switch3_d = 1.0;

  /* Switch: '<S135>/Switch3' incorporates:
   *  Constant: '<S10>/Constant5'
   *  Switch: '<S10>/Switch2'
   */
  microrrede_v8_B.Switch3_k = 1.0;

  /* Outport: '<Root>/V PCC 1' */
  microrrede_v8_Y.VPCC1[0] = microrrede_v8_B.StateSpace_o1[48];

  /* Outport: '<Root>/I PCC 1' */
  microrrede_v8_Y.IPCC1[0] = microrrede_v8_B.StateSpace_o1[72];

  /* Outport: '<Root>/V PCC 2' */
  microrrede_v8_Y.VPCC2[0] = microrrede_v8_B.StateSpace_o1[51];

  /* Outport: '<Root>/I PCC 2' */
  microrrede_v8_Y.IPCC2[0] = microrrede_v8_B.StateSpace_o1[75];

  /* Outport: '<Root>/Vload3' */
  microrrede_v8_Y.Vload3[0] = microrrede_v8_B.StateSpace_o1[54];

  /* Outport: '<Root>/Iload3' */
  microrrede_v8_Y.Iload3[0] = microrrede_v8_B.StateSpace_o1[78];

  /* Outport: '<Root>/V PCC 1' */
  microrrede_v8_Y.VPCC1[1] = microrrede_v8_B.StateSpace_o1[49];

  /* Outport: '<Root>/I PCC 1' */
  microrrede_v8_Y.IPCC1[1] = microrrede_v8_B.StateSpace_o1[73];

  /* Outport: '<Root>/V PCC 2' */
  microrrede_v8_Y.VPCC2[1] = microrrede_v8_B.StateSpace_o1[52];

  /* Outport: '<Root>/I PCC 2' */
  microrrede_v8_Y.IPCC2[1] = microrrede_v8_B.StateSpace_o1[76];

  /* Outport: '<Root>/Vload3' */
  microrrede_v8_Y.Vload3[1] = microrrede_v8_B.StateSpace_o1[55];

  /* Outport: '<Root>/Iload3' */
  microrrede_v8_Y.Iload3[1] = microrrede_v8_B.StateSpace_o1[79];

  /* Outport: '<Root>/V PCC 1' */
  microrrede_v8_Y.VPCC1[2] = microrrede_v8_B.StateSpace_o1[50];

  /* Outport: '<Root>/I PCC 1' */
  microrrede_v8_Y.IPCC1[2] = microrrede_v8_B.StateSpace_o1[74];

  /* Outport: '<Root>/V PCC 2' */
  microrrede_v8_Y.VPCC2[2] = microrrede_v8_B.StateSpace_o1[53];

  /* Outport: '<Root>/I PCC 2' */
  microrrede_v8_Y.IPCC2[2] = microrrede_v8_B.StateSpace_o1[77];

  /* Outport: '<Root>/Vload3' */
  microrrede_v8_Y.Vload3[2] = microrrede_v8_B.StateSpace_o1[56];

  /* Outport: '<Root>/Iload3' */
  microrrede_v8_Y.Iload3[2] = microrrede_v8_B.StateSpace_o1[80];

  /* Outport: '<Root>/XCBR_N_out' incorporates:
   *  Inport: '<Root>/XCBR_N_in'
   */
  microrrede_v8_Y.XCBR_N_out = microrrede_v8_U.XCBR_N_in;

  /* Switch: '<S138>/Switch3' incorporates:
   *  Inport: '<Root>/XCBR_N_in'
   */
  microrrede_v8_B.Switch3_g = microrrede_v8_U.XCBR_N_in;

  /* Outport: '<Root>/XCBR_CC_3_out' incorporates:
   *  Inport: '<Root>/XCBR_CC_3_in'
   */
  microrrede_v8_Y.XCBR_CC_3_out = microrrede_v8_U.XCBR_CC_3_in;

  /* Outport: '<Root>/XCBR_CC_2_out' incorporates:
   *  Inport: '<Root>/XCBR_CC_2_in'
   */
  microrrede_v8_Y.XCBR_CC_2_out = microrrede_v8_U.XCBR_CC_2_in;

  /* Outport: '<Root>/XCBR_CC_1_out' incorporates:
   *  Inport: '<Root>/XCBR_CC_1_in'
   */
  microrrede_v8_Y.XCBR_CC_1_out = microrrede_v8_U.XCBR_CC_1_in;

  /* Gain: '<S6>/do not delete this gain' */
  microrrede_v8_B.I3 = microrrede_v8_B.StateSpace_o1[66];

  /* Outport: '<Root>/I3' */
  microrrede_v8_Y.I3 = microrrede_v8_B.I3;

  /* Gain: '<S33>/do not delete this gain' */
  microrrede_v8_B.V3 = microrrede_v8_B.StateSpace_o1[59];

  /* Outport: '<Root>/V3' */
  microrrede_v8_Y.V3 = microrrede_v8_B.V3;

  /* Gain: '<S5>/do not delete this gain' */
  microrrede_v8_B.I2 = microrrede_v8_B.StateSpace_o1[65];

  /* Outport: '<Root>/I2' */
  microrrede_v8_Y.I2 = microrrede_v8_B.I2;

  /* Gain: '<S32>/do not delete this gain' */
  microrrede_v8_B.V2 = microrrede_v8_B.StateSpace_o1[58];

  /* Outport: '<Root>/V2' */
  microrrede_v8_Y.V2 = microrrede_v8_B.V2;

  /* Gain: '<S4>/do not delete this gain' */
  microrrede_v8_B.I1 = microrrede_v8_B.StateSpace_o1[64];

  /* Outport: '<Root>/I1' */
  microrrede_v8_Y.I1 = microrrede_v8_B.I1;

  /* Gain: '<S31>/do not delete this gain' */
  microrrede_v8_B.V1 = microrrede_v8_B.StateSpace_o1[57];

  /* Outport: '<Root>/V1' */
  microrrede_v8_Y.V1 = microrrede_v8_B.V1;

  /* Outport: '<Root>/XCBR_banco3p_out' incorporates:
   *  Inport: '<Root>/XCBR_banco3p_in'
   */
  microrrede_v8_Y.XCBR_banco3p_out = microrrede_v8_U.XCBR_banco3p_in;

  /* Switch: '<S116>/Switch3' incorporates:
   *  Constant: '<S7>/Constant5'
   *  Switch: '<S7>/Switch'
   */
  microrrede_v8_B.Switch3_b = 1.0;

  /* Switch: '<S118>/Switch3' incorporates:
   *  Constant: '<S7>/Constant5'
   *  Switch: '<S7>/Switch1'
   */
  microrrede_v8_B.Switch3_p = 1.0;

  /* Switch: '<S120>/Switch3' incorporates:
   *  Constant: '<S7>/Constant5'
   *  Switch: '<S7>/Switch2'
   */
  microrrede_v8_B.Switch3_kf = 1.0;

  /* Outport: '<Root>/XCBR_banco1p_out' incorporates:
   *  Inport: '<Root>/XCBR_banco1p_in'
   */
  microrrede_v8_Y.XCBR_banco1p_out = microrrede_v8_U.XCBR_banco1p_in;

  /* Switch: '<S125>/Switch3' incorporates:
   *  Inport: '<Root>/XCBR_banco1p_in'
   */
  microrrede_v8_B.Switch3_bx = microrrede_v8_U.XCBR_banco1p_in;

  /* MATLAB Function: '<S2>/MATLAB Function' */
  microrrede_v8_MATLABFunction(microrrede_v8_B.StateSpace_o1[45],
    microrrede_v8_B.StateSpace_o1[69], &rtb_RateLimiter,
    &microrrede_v8_DW.sf_MATLABFunction);

  /* Sum: '<S2>/Sum' */
  rtb_Saturation_d = microrrede_v8_B.StateSpace_o1[45] - rtb_RateLimiter;

  /* Gain: '<S80>/Integral Gain' */
  rtb_IntegralGain = 0.0075 * rtb_Saturation_d;

  /* Sum: '<S92>/Sum' incorporates:
   *  DiscreteIntegrator: '<S83>/Integrator'
   *  Gain: '<S88>/Proportional Gain'
   */
  rtb_Saturation_d = 0.0075 * rtb_Saturation_d +
    microrrede_v8_DW.Integrator_DSTATE;

  /* DigitalClock: '<S102>/Digital Clock' incorporates:
   *  DigitalClock: '<S225>/Digital Clock'
   *  DigitalClock: '<S507>/Digital Clock'
   */
  rtb_Sum5_ij = microrrede_v8_M->Timing.t[0];

  /* Fcn: '<S51>/Fcn' incorporates:
   *  Constant: '<S102>/Constant2'
   *  DigitalClock: '<S102>/Digital Clock'
   *  Fcn: '<S102>/Fcn'
   *  Fcn: '<S162>/Fcn'
   *  Fcn: '<S782>/Fcn'
   *  Gain: '<S102>/1\ib1'
   *  Math: '<S102>/Math Function'
   */
  DataTypeConversion_tmp = ((10000.0 * rt_remd_snf(rtb_Sum5_ij, 0.0001) * 2.0 -
    1.0) + 1.0) * 0.5;

  /* DataTypeConversion: '<S51>/Data Type Conversion' incorporates:
   *  Constant: '<S100>/Constant'
   *  Fcn: '<S51>/Fcn'
   *  Logic: '<S51>/Logical Operator'
   *  RelationalOperator: '<S100>/Compare'
   *  RelationalOperator: '<S51>/Relational Operator'
   */
  microrrede_v8_B.DataTypeConversion = ((rtb_Saturation_d != 0.0) &&
    (rtb_Saturation_d >= DataTypeConversion_tmp));

  /* Sum: '<S683>/Add1' incorporates:
   *  Constant: '<S683>/Rs_array_'
   *  Product: '<S683>/Product2'
   */
  rtb_Integrator_m = microrrede_v8_B.StateSpace_o1[69] * 4.6101 +
    microrrede_v8_B.StateSpace_o1[45];

  /* Sum: '<S676>/Add1' incorporates:
   *  Constant: '<S676>/Rsh_array'
   *  Constant: '<S676>/Rsh_array_5%Sref'
   *  Constant: '<S676>/one'
   *  Math: '<S676>/Math Function'
   *  Product: '<S676>/Product'
   *  Product: '<S676>/Product1'
   *  Product: '<S676>/Product2'
   *  Product: '<S676>/Product5'
   *  Sum: '<S676>/Add'
   *  UnitDelay: '<S676>/Unit Delay'
   *
   * About '<S676>/Math Function':
   *  Operator: exp
   */
  microrrede_v8_DW.UnitDelay_DSTATE = ((exp(1.0 / microrrede_v8_ConstB.VT *
    rtb_Integrator_m) - 1.0) * microrrede_v8_ConstB.Product4 + rtb_Integrator_m /
    2322.603 * rtb_Integrator_e) - rtb_Integrator_m / 46452.06;

  /* MATLAB Function: '<S153>/MATLAB Function' */
  microrrede_v8_MATLABFunction(microrrede_v8_B.StateSpace_o1[46],
    microrrede_v8_B.StateSpace_o1[70], &rtb_RateLimiter,
    &microrrede_v8_DW.sf_MATLABFunction_n);

  /* Sum: '<S153>/Sum' */
  rtb_Integrator_m = microrrede_v8_B.StateSpace_o1[46] - rtb_RateLimiter;

  /* Gain: '<S191>/Integral Gain' */
  rtb_Integrator_e = 0.0075 * rtb_Integrator_m;

  /* Sum: '<S203>/Sum' incorporates:
   *  DiscreteIntegrator: '<S194>/Integrator'
   *  Gain: '<S199>/Proportional Gain'
   */
  rtb_Integrator_m = 0.0075 * rtb_Integrator_m +
    microrrede_v8_DW.Integrator_DSTATE_f;

  /* DataTypeConversion: '<S162>/Data Type Conversion' incorporates:
   *  Constant: '<S211>/Constant'
   *  Logic: '<S162>/Logical Operator'
   *  RelationalOperator: '<S162>/Relational Operator'
   *  RelationalOperator: '<S211>/Compare'
   */
  microrrede_v8_B.DataTypeConversion_f = ((rtb_Integrator_m != 0.0) &&
    (rtb_Integrator_m >= DataTypeConversion_tmp));

  /* Gain: '<S225>/1\ib1' incorporates:
   *  Constant: '<S225>/Constant1'
   *  Constant: '<S225>/Constant3'
   *  Gain: '<S504>/1\ib1'
   *  Gain: '<S527>/1\ib1'
   *  Gain: '<S845>/1\ib1'
   *  Math: '<S225>/Math Function'
   *  Sum: '<S225>/Add1'
   */
  rtb_Integrator_bx_tmp = rt_remd_snf(rtb_Sum5_ij + 5.0000000000000009E-5,
    0.0002) * 5000.0;

  /* Lookup_n-D: '<S225>/1-D Lookup Table' incorporates:
   *  Gain: '<S225>/1\ib1'
   */
  rtb_Integrator_m = look1_pbinlxpw(rtb_Integrator_bx_tmp,
    microrrede_v8_ConstP.pooled58, microrrede_v8_ConstP.pooled57,
    &microrrede_v8_DW.m_bpIndex, 2U);

  /* Sum: '<S216>/Add4' incorporates:
   *  Constant: '<S225>/Constant2'
   *  Product: '<S216>/MUL1'
   *  Sum: '<S225>/Add3'
   */
  rtb_Integrator_m = ((rtb_Integrator_m - 1.0) * microrrede_v8_ConstB.Gain1 -
                      1.0) + microrrede_v8_ConstB.Gain1;

  /* DiscreteIntegrator: '<S241>/Integ4' */
  if (microrrede_v8_DW.Integ4_SYSTEM_ENABLE != 0) {
    /* DiscreteIntegrator: '<S241>/Integ4' */
    microrrede_v8_B.Integ4 = microrrede_v8_DW.Integ4_DSTATE;
  } else {
    /* DiscreteIntegrator: '<S241>/Integ4' */
    microrrede_v8_B.Integ4 = 2.0833335E-6 * microrrede_v8_B.StateSpace_o1[41] +
      microrrede_v8_DW.Integ4_DSTATE;
  }

  /* End of DiscreteIntegrator: '<S241>/Integ4' */

  /* S-Function (sfun_discreteVariableDelay): '<S242>/S-Function' incorporates:
   *  Constant: '<S241>/K1'
   */

  /* Level2 S-Function Block: '<S242>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[7];
    sfcnOutputs(rts,0);
  }

  /* Switch: '<S241>/Switch' incorporates:
   *  Constant: '<S241>/K1'
   *  Constant: '<S241>/K2'
   *  DigitalClock: '<S102>/Digital Clock'
   *  Gain: '<S241>/Gain'
   *  Gain: '<S241>/Gain1'
   *  Product: '<S241>/Product'
   *  RelationalOperator: '<S241>/Relational Operator'
   *  Sum: '<S241>/Sum1'
   *  Sum: '<S241>/Sum5'
   *  Sum: '<S241>/Sum7'
   *  UnitDelay: '<S241>/Unit Delay'
   *  UnitDelay: '<S241>/Unit Delay1'
   */
  if (rtb_Sum5_ij >= 0.016666668) {
    microrrede_v8_DW.UnitDelay1_DSTATE = (microrrede_v8_B.Integ4 -
      microrrede_v8_B.SFunction) * 60.0 + (-7.9987200059934818E-8 *
      microrrede_v8_B.StateSpace_o1[41] - 1.2799998994857576E-11 *
      microrrede_v8_DW.UnitDelay_DSTATE_cn);
  }

  /* End of Switch: '<S241>/Switch' */

  /* Saturate: '<S231>/Saturation' */
  if (microrrede_v8_DW.UnitDelay_DSTATE_i > 70.0) {
    rtb_RoundingFunction_jv = 70.0;
  } else if (microrrede_v8_DW.UnitDelay_DSTATE_i < 40.0) {
    rtb_RoundingFunction_jv = 40.0;
  } else {
    rtb_RoundingFunction_jv = microrrede_v8_DW.UnitDelay_DSTATE_i;
  }

  /* Gain: '<S231>/Gain' incorporates:
   *  Math: '<S231>/Math Function'
   *  Saturate: '<S231>/Saturation'
   *
   * About '<S231>/Math Function':
   *  Operator: reciprocal
   */
  microrrede_v8_B.Gain = 1.0 / rtb_RoundingFunction_jv * 0.25;

  /* S-Function (sfun_discreteVariableDelay): '<S313>/S-Function' */

  /* Level2 S-Function Block: '<S313>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[8];
    sfcnOutputs(rts,0);
  }

  /* RelationalOperator: '<S291>/Relational Operator' incorporates:
   *  Constant: '<S291>/Constant2'
   */
  rtb_RelationalOperator_mb = (microrrede_v8_DW.DiscreteTimeIntegrator_DSTATE_k >
    6.2831853071795862);

  /* InitialCondition: '<S291>/Initial' */
  if (microrrede_v8_DW.Initial_FirstOutputTime) {
    microrrede_v8_DW.Initial_FirstOutputTime = false;

    /* InitialCondition: '<S291>/Initial' */
    Initial = 0.0;
  } else {
    /* InitialCondition: '<S291>/Initial' incorporates:
     *  Constant: '<S291>/Constant2'
     *  Sum: '<S291>/Subtract'
     */
    Initial = microrrede_v8_DW.DiscreteTimeIntegrator_DSTATE_k -
      6.2831853071795862;
  }

  /* End of InitialCondition: '<S291>/Initial' */

  /* DiscreteIntegrator: '<S291>/Discrete-Time Integrator' */
  if (rtb_RelationalOperator_mb &&
      (microrrede_v8_DW.DiscreteTimeIntegrator_PrevRese <= 0)) {
    microrrede_v8_DW.DiscreteTimeIntegrator_DSTATE_k = Initial;
  }

  /* Outputs for Enabled SubSystem: '<S312>/Subsystem1' */
  microrrede_v8_Subsystem1(microrrede_v8_ConstB.Compare,
    microrrede_v8_ConstB.Gain2, microrrede_v8_B.SFunction_f,
    microrrede_v8_DW.DiscreteTimeIntegrator_DSTATE_k, &microrrede_v8_B.Fcn_n,
    &microrrede_v8_B.Fcn1_j);

  /* End of Outputs for SubSystem: '<S312>/Subsystem1' */

  /* Outputs for Enabled SubSystem: '<S312>/Subsystem - pi//2 delay' */
  microrrede_v8_Subsystempi2delay(microrrede_v8_ConstB.Compare_e,
    microrrede_v8_ConstB.Gain2, microrrede_v8_B.SFunction_f,
    microrrede_v8_DW.DiscreteTimeIntegrator_DSTATE_k, &microrrede_v8_B.Fcn_l,
    &microrrede_v8_B.Fcn1_f1);

  /* End of Outputs for SubSystem: '<S312>/Subsystem - pi//2 delay' */

  /* Switch: '<S312>/Switch' */
  if (microrrede_v8_ConstB.Compare != 0) {
    Initial = microrrede_v8_B.Fcn_n;
    rtb_Integrator_c_idx_1 = microrrede_v8_B.Fcn1_j;
  } else {
    Initial = microrrede_v8_B.Fcn_l;
    rtb_Integrator_c_idx_1 = microrrede_v8_B.Fcn1_f1;
  }

  /* End of Switch: '<S312>/Switch' */

  /* Gain: '<S215>/Gain3' incorporates:
   *  Constant: '<S215>/Constant'
   *  Sum: '<S215>/Add'
   *  UnitDelay: '<S241>/Unit Delay1'
   */
  rtb_Saturation_d = (microrrede_v8_DW.UnitDelay1_DSTATE - 400.0) * 0.0025;

  /* Sum: '<S283>/Sum' incorporates:
   *  DiscreteIntegrator: '<S274>/Integrator'
   *  Gain: '<S279>/Proportional Gain'
   */
  rtb_Gain3_m = 12.0 * rtb_Saturation_d + microrrede_v8_DW.Integrator_DSTATE_n;

  /* Saturate: '<S281>/Saturation' */
  if (rtb_Gain3_m > 1.5) {
    rtb_Gain3_m = 1.5;
  } else if (rtb_Gain3_m < -1.5) {
    rtb_Gain3_m = -1.5;
  }

  /* End of Saturate: '<S281>/Saturation' */

  /* Sum: '<S232>/Add' incorporates:
   *  Constant: '<S215>/Constant1'
   */
  Initial = rtb_Gain3_m - Initial;
  rtb_Integrator_c_idx_1 = 0.0 - rtb_Integrator_c_idx_1;

  /* Sum: '<S359>/Sum' incorporates:
   *  DiscreteIntegrator: '<S350>/Integrator'
   *  Gain: '<S355>/Proportional Gain'
   */
  rtb_RoundingFunction_m = 0.15 * Initial +
    microrrede_v8_DW.Integrator_DSTATE_k[0];
  rtb_Numberofsamplespercycle_ej = 0.15 * rtb_Integrator_c_idx_1 +
    microrrede_v8_DW.Integrator_DSTATE_k[1];

  /* Outputs for Enabled SubSystem: '<S291>/Automatic Gain Control' incorporates:
   *  EnablePort: '<S292>/Enable'
   */
  /* Product: '<S226>/Product1' incorporates:
   *  DiscreteIntegrator: '<S291>/Discrete-Time Integrator'
   *  Gain: '<S226>/Gain1'
   *  Product: '<S296>/Product1'
   *  Trigonometry: '<S226>/Trigonometric Function'
   */
  rtb_Product1_f_tmp = 2.0 * sin
    (microrrede_v8_DW.DiscreteTimeIntegrator_DSTATE_k) *
    microrrede_v8_ConstB.Gain;

  /* End of Outputs for SubSystem: '<S291>/Automatic Gain Control' */

  /* DiscreteIntegrator: '<S235>/Integ4' */
  if (microrrede_v8_DW.Integ4_SYSTEM_ENABLE_h != 0) {
    /* DiscreteIntegrator: '<S235>/Integ4' */
    microrrede_v8_B.Integ4_p = microrrede_v8_DW.Integ4_DSTATE_l;
  } else {
    /* DiscreteIntegrator: '<S235>/Integ4' incorporates:
     *  Product: '<S226>/Product1'
     */
    microrrede_v8_B.Integ4_p = 2.0833335E-6 * rtb_Product1_f_tmp +
      microrrede_v8_DW.Integ4_DSTATE_l;
  }

  /* End of DiscreteIntegrator: '<S235>/Integ4' */

  /* Saturate: '<S235>/To avoid division  by zero' */
  if (microrrede_v8_DW.UnitDelay_DSTATE_i > 1.0E+6) {
    rtb_RoundingFunction_jv = 1.0E+6;
  } else if (microrrede_v8_DW.UnitDelay_DSTATE_i < 2.2204460492503131E-16) {
    rtb_RoundingFunction_jv = 2.2204460492503131E-16;
  } else {
    rtb_RoundingFunction_jv = microrrede_v8_DW.UnitDelay_DSTATE_i;
  }

  /* Fcn: '<S235>/Number of samples per cycle' incorporates:
   *  Saturate: '<S235>/To avoid division  by zero'
   */
  rtb_Numberofsamplespercycle = 1.0 / rtb_RoundingFunction_jv / 4.166667e-6;

  /* Rounding: '<S235>/Rounding Function' */
  rtb_RoundingFunction = ceil(rtb_Numberofsamplespercycle);

  /* Gain: '<S235>/Gain' */
  microrrede_v8_B.Delay = 4.166667E-6 * rtb_RoundingFunction;

  /* S-Function (sfun_discreteVariableDelay): '<S237>/S-Function' */

  /* Level2 S-Function Block: '<S237>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[9];
    sfcnOutputs(rts,0);
  }

  /* Switch: '<S235>/Switch' incorporates:
   *  Constant: '<S235>/Constant'
   *  DigitalClock: '<S102>/Digital Clock'
   *  Gain: '<S236>/Gain1'
   *  Product: '<S226>/Product1'
   *  Product: '<S235>/Product'
   *  Product: '<S236>/Product2'
   *  Product: '<S236>/Product4'
   *  Product: '<S236>/Product5'
   *  RelationalOperator: '<S235>/Relational Operator'
   *  Sum: '<S235>/Sum5'
   *  Sum: '<S235>/Sum7'
   *  Sum: '<S236>/Sum1'
   *  Sum: '<S236>/Sum4'
   *  UnitDelay: '<S235>/Unit Delay1'
   *  UnitDelay: '<S236>/Unit Delay'
   *  UnitDelay: '<S291>/Unit Delay'
   */
  if (rtb_Sum5_ij >= 0.016666666666666666) {
    /* Sum: '<S236>/Sum5' */
    rtb_RoundingFunction = rtb_Numberofsamplespercycle - rtb_RoundingFunction;
    microrrede_v8_DW.UnitDelay1_DSTATE_p = ((rtb_Product1_f_tmp -
      microrrede_v8_DW.UnitDelay_DSTATE_dc) * rtb_RoundingFunction * 0.5 +
      rtb_Product1_f_tmp) * (rtb_RoundingFunction / rtb_Numberofsamplespercycle)
      + (microrrede_v8_B.Integ4_p - microrrede_v8_B.SFunction_o) *
      microrrede_v8_DW.UnitDelay_DSTATE_i;
  }

  /* End of Switch: '<S235>/Switch' */

  /* Trigonometry: '<S226>/Trigonometric Function' incorporates:
   *  DiscreteIntegrator: '<S291>/Discrete-Time Integrator'
   *  Trigonometry: '<S291>/Trigonometric Function2'
   */
  rtb_RoundingFunction = cos(microrrede_v8_DW.DiscreteTimeIntegrator_DSTATE_k);

  /* Product: '<S226>/Product2' incorporates:
   *  Gain: '<S226>/Gain3'
   *  Trigonometry: '<S226>/Trigonometric Function'
   */
  rtb_Numberofsamplespercycle = 2.0 * rtb_RoundingFunction *
    microrrede_v8_ConstB.Gain;

  /* DiscreteIntegrator: '<S238>/Integ4' */
  if (microrrede_v8_DW.Integ4_SYSTEM_ENABLE_a != 0) {
    /* DiscreteIntegrator: '<S238>/Integ4' */
    microrrede_v8_B.Integ4_e = microrrede_v8_DW.Integ4_DSTATE_h;
  } else {
    /* DiscreteIntegrator: '<S238>/Integ4' */
    microrrede_v8_B.Integ4_e = 2.0833335E-6 * rtb_Numberofsamplespercycle +
      microrrede_v8_DW.Integ4_DSTATE_h;
  }

  /* End of DiscreteIntegrator: '<S238>/Integ4' */

  /* Saturate: '<S238>/To avoid division  by zero' */
  if (microrrede_v8_DW.UnitDelay_DSTATE_i > 1.0E+6) {
    rtb_RoundingFunction_jv = 1.0E+6;
  } else if (microrrede_v8_DW.UnitDelay_DSTATE_i < 2.2204460492503131E-16) {
    rtb_RoundingFunction_jv = 2.2204460492503131E-16;
  } else {
    rtb_RoundingFunction_jv = microrrede_v8_DW.UnitDelay_DSTATE_i;
  }

  /* Fcn: '<S238>/Number of samples per cycle' incorporates:
   *  Saturate: '<S238>/To avoid division  by zero'
   */
  rtb_Numberofsamplespercycle_f = 1.0 / rtb_RoundingFunction_jv / 4.166667e-6;

  /* Rounding: '<S238>/Rounding Function' */
  rtb_RoundingFunction_ay = ceil(rtb_Numberofsamplespercycle_f);

  /* Gain: '<S238>/Gain' */
  microrrede_v8_B.Delay_g = 4.166667E-6 * rtb_RoundingFunction_ay;

  /* S-Function (sfun_discreteVariableDelay): '<S240>/S-Function' */

  /* Level2 S-Function Block: '<S240>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[10];
    sfcnOutputs(rts,0);
  }

  /* Switch: '<S238>/Switch' incorporates:
   *  Constant: '<S238>/Constant'
   *  DigitalClock: '<S102>/Digital Clock'
   *  Gain: '<S239>/Gain1'
   *  Product: '<S238>/Product'
   *  Product: '<S239>/Product2'
   *  Product: '<S239>/Product4'
   *  Product: '<S239>/Product5'
   *  RelationalOperator: '<S238>/Relational Operator'
   *  Sum: '<S238>/Sum5'
   *  Sum: '<S238>/Sum7'
   *  Sum: '<S239>/Sum1'
   *  Sum: '<S239>/Sum4'
   *  UnitDelay: '<S238>/Unit Delay1'
   *  UnitDelay: '<S239>/Unit Delay'
   *  UnitDelay: '<S291>/Unit Delay'
   */
  if (rtb_Sum5_ij >= 0.016666666666666666) {
    /* Sum: '<S239>/Sum5' */
    rtb_RoundingFunction_ay = rtb_Numberofsamplespercycle_f -
      rtb_RoundingFunction_ay;
    microrrede_v8_DW.UnitDelay1_DSTATE_c = ((rtb_Numberofsamplespercycle -
      microrrede_v8_DW.UnitDelay_DSTATE_m) * rtb_RoundingFunction_ay * 0.5 +
      rtb_Numberofsamplespercycle) * (rtb_RoundingFunction_ay /
      rtb_Numberofsamplespercycle_f) + (microrrede_v8_B.Integ4_e -
      microrrede_v8_B.SFunction_e) * microrrede_v8_DW.UnitDelay_DSTATE_i;
  }

  /* End of Switch: '<S238>/Switch' */

  /* Gain: '<S215>/Gain1' incorporates:
   *  ComplexToMagnitudeAngle: '<S226>/Complex to Magnitude-Angle'
   *  Gain: '<S226>/Rad->Deg.'
   *  RealImagToComplex: '<S226>/Real-Imag to Complex'
   *  UnitDelay: '<S235>/Unit Delay1'
   *  UnitDelay: '<S238>/Unit Delay1'
   */
  rtb_Integrator_l = 57.295779513082323 * rt_atan2d_snf
    (microrrede_v8_DW.UnitDelay1_DSTATE_c, microrrede_v8_DW.UnitDelay1_DSTATE_p)
    * 0.017453292519943295;

  /* Product: '<S230>/Divide1' incorporates:
   *  Constant: '<S230>/Constant'
   *  Product: '<S230>/Divide'
   *  UnitDelay: '<S241>/Unit Delay1'
   */
  rtb_RoundingFunction_jv = 1.0 / (microrrede_v8_DW.UnitDelay1_DSTATE /
    311.12698372208092);

  /* Saturate: '<S357>/Saturation' */
  if (rtb_RoundingFunction_m > 1.5) {
    rtb_RoundingFunction_m = 1.5;
  } else if (rtb_RoundingFunction_m < -1.5) {
    rtb_RoundingFunction_m = -1.5;
  }

  /* ComplexToMagnitudeAngle: '<S226>/Complex to Magnitude-Angle' incorporates:
   *  RealImagToComplex: '<S226>/Real-Imag to Complex'
   *  UnitDelay: '<S235>/Unit Delay1'
   *  UnitDelay: '<S238>/Unit Delay1'
   */
  rtb_Numberofsamplespercycle_f = rt_hypotd_snf
    (microrrede_v8_DW.UnitDelay1_DSTATE_p, microrrede_v8_DW.UnitDelay1_DSTATE_c);

  /* Sum: '<S232>/Add1' incorporates:
   *  ComplexToMagnitudeAngle: '<S226>/Complex to Magnitude-Angle'
   *  Gain: '<S232>/Gain'
   *  MagnitudeAngleToComplex: '<S215>/Magnitude-Angle to Complex'
   *  Saturate: '<S357>/Saturation'
   *  Sum: '<S232>/Add2'
   */
  rtb_RoundingFunction_go = ((rtb_Numberofsamplespercycle_f * cos
    (rtb_Integrator_l) + 0.002 * rtb_Gain3_m) - microrrede_v8_ConstB.Gain1_g) +
    rtb_RoundingFunction_m;

  /* Saturate: '<S357>/Saturation' */
  if (rtb_Numberofsamplespercycle_ej > 1.5) {
    rtb_Numberofsamplespercycle_ej = 1.5;
  } else if (rtb_Numberofsamplespercycle_ej < -1.5) {
    rtb_Numberofsamplespercycle_ej = -1.5;
  }

  /* Sum: '<S232>/Add1' incorporates:
   *  Gain: '<S232>/Gain2'
   *  MagnitudeAngleToComplex: '<S215>/Magnitude-Angle to Complex'
   *  Saturate: '<S357>/Saturation'
   *  Sum: '<S232>/Add3'
   */
  rtb_x2k = ((rtb_Numberofsamplespercycle_f * sin(rtb_Integrator_l) + 0.2 *
              rtb_Gain3_m) + microrrede_v8_ConstB.Gain3) +
    rtb_Numberofsamplespercycle_ej;

  /* Saturate: '<S232>/Saturation' */
  if (rtb_RoundingFunction_go > 1.5) {
    rtb_RoundingFunction_go = 1.5;
  } else if (rtb_RoundingFunction_go < -1.5) {
    rtb_RoundingFunction_go = -1.5;
  }

  /* Product: '<S230>/Divide1' incorporates:
   *  Saturate: '<S232>/Saturation'
   */
  rtb_RoundingFunction_go *= rtb_RoundingFunction_jv;

  /* Saturate: '<S232>/Saturation' */
  if (rtb_x2k > 1.5) {
    rtb_x2k = 1.5;
  } else if (rtb_x2k < -1.5) {
    rtb_x2k = -1.5;
  }

  /* Product: '<S230>/Divide1' incorporates:
   *  Saturate: '<S232>/Saturation'
   */
  rtb_x2k *= rtb_RoundingFunction_jv;

  /* Product: '<S230>/Divide2' incorporates:
   *  ComplexToMagnitudeAngle: '<S230>/Complex to Magnitude-Angle'
   *  Constant: '<S230>/Constant1'
   *  DiscreteIntegrator: '<S291>/Discrete-Time Integrator'
   *  RealImagToComplex: '<S230>/Real-Imag to Complex'
   *  Sum: '<S230>/Add'
   *  Sum: '<S230>/Add1'
   *  Trigonometry: '<S230>/Sin'
   */
  rtb_Integrator_l = sin((microrrede_v8_DW.DiscreteTimeIntegrator_DSTATE_k +
    0.0037699111843077517) + rt_atan2d_snf(rtb_x2k, rtb_RoundingFunction_go)) *
    rt_hypotd_snf(rtb_RoundingFunction_go, rtb_x2k);

  /* RelationalOperator: '<S220>/Relational Operator1' */
  rtb_RelationalOperator3 = (rtb_Integrator_l >= rtb_Integrator_m);

  /* RelationalOperator: '<S220>/Relational Operator3' incorporates:
   *  Gain: '<S220>/Gain'
   */
  rtb_RelationalOperator1 = (-rtb_Integrator_l >= rtb_Integrator_m);

  /* DataTypeConversion: '<S214>/Data Type Conversion' incorporates:
   *  Logic: '<S214>/Logical Operator4'
   */
  microrrede_v8_B.DataTypeConversion_m[0] = rtb_RelationalOperator3;
  microrrede_v8_B.DataTypeConversion_m[1] = !rtb_RelationalOperator3;
  microrrede_v8_B.DataTypeConversion_m[2] = rtb_RelationalOperator1;
  microrrede_v8_B.DataTypeConversion_m[3] = !rtb_RelationalOperator1;

  /* Gain: '<S271>/Integral Gain' */
  rtb_Integrator_m = 200.0 * rtb_Saturation_d;

  /* Outputs for Enabled SubSystem: '<S291>/Automatic Gain Control' incorporates:
   *  EnablePort: '<S292>/Enable'
   */
  if (!microrrede_v8_DW.AutomaticGainControl_MODE_ow) {
    /* Enable for DiscreteIntegrator: '<S299>/Integ4' */
    microrrede_v8_DW.Integ4_SYSTEM_ENABLE_l = 1U;

    /* Enable for DiscreteIntegrator: '<S302>/Integ4' */
    microrrede_v8_DW.Integ4_SYSTEM_ENABLE_iz = 1U;
    microrrede_v8_DW.AutomaticGainControl_MODE_ow = true;
  }

  /* DiscreteIntegrator: '<S299>/Integ4' */
  if (microrrede_v8_DW.Integ4_SYSTEM_ENABLE_l != 0) {
    /* DiscreteIntegrator: '<S299>/Integ4' */
    microrrede_v8_B.Integ4_jd = microrrede_v8_DW.Integ4_DSTATE_f5;
  } else {
    /* DiscreteIntegrator: '<S299>/Integ4' */
    microrrede_v8_B.Integ4_jd = 2.0833335E-6 * rtb_Product1_f_tmp +
      microrrede_v8_DW.Integ4_DSTATE_f5;
  }

  /* End of DiscreteIntegrator: '<S299>/Integ4' */

  /* Saturate: '<S299>/To avoid division  by zero' */
  if (microrrede_v8_DW.UnitDelay_DSTATE_i > 1.0E+6) {
    rtb_RoundingFunction_jv = 1.0E+6;
  } else if (microrrede_v8_DW.UnitDelay_DSTATE_i < 2.2204460492503131E-16) {
    rtb_RoundingFunction_jv = 2.2204460492503131E-16;
  } else {
    rtb_RoundingFunction_jv = microrrede_v8_DW.UnitDelay_DSTATE_i;
  }

  /* Fcn: '<S299>/Number of samples per cycle' incorporates:
   *  Saturate: '<S299>/To avoid division  by zero'
   */
  rtb_Numberofsamplespercycle_f = 1.0 / rtb_RoundingFunction_jv / 4.166667e-6;

  /* Rounding: '<S299>/Rounding Function' */
  rtb_RoundingFunction_ay = ceil(rtb_Numberofsamplespercycle_f);

  /* Gain: '<S299>/Gain' */
  microrrede_v8_B.Delay_du = 4.166667E-6 * rtb_RoundingFunction_ay;

  /* S-Function (sfun_discreteVariableDelay): '<S301>/S-Function' */

  /* Level2 S-Function Block: '<S301>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[0];
    sfcnOutputs(rts,0);
  }

  /* Switch: '<S299>/Switch' incorporates:
   *  Constant: '<S299>/Constant'
   *  DigitalClock: '<S102>/Digital Clock'
   *  Gain: '<S300>/Gain1'
   *  Product: '<S299>/Product'
   *  Product: '<S300>/Product2'
   *  Product: '<S300>/Product4'
   *  Product: '<S300>/Product5'
   *  RelationalOperator: '<S299>/Relational Operator'
   *  Sum: '<S299>/Sum5'
   *  Sum: '<S299>/Sum7'
   *  Sum: '<S300>/Sum1'
   *  Sum: '<S300>/Sum4'
   *  UnitDelay: '<S291>/Unit Delay'
   *  UnitDelay: '<S299>/Unit Delay1'
   *  UnitDelay: '<S300>/Unit Delay'
   */
  if (rtb_Sum5_ij >= 0.016666666666666666) {
    /* Sum: '<S300>/Sum5' */
    rtb_RoundingFunction_ay = rtb_Numberofsamplespercycle_f -
      rtb_RoundingFunction_ay;
    microrrede_v8_DW.UnitDelay1_DSTATE_o = ((rtb_Product1_f_tmp -
      microrrede_v8_DW.UnitDelay_DSTATE_ne) * rtb_RoundingFunction_ay * 0.5 +
      rtb_Product1_f_tmp) * (rtb_RoundingFunction_ay /
      rtb_Numberofsamplespercycle_f) + (microrrede_v8_B.Integ4_jd -
      microrrede_v8_B.SFunction_pp) * microrrede_v8_DW.UnitDelay_DSTATE_i;
  }

  /* End of Switch: '<S299>/Switch' */

  /* Product: '<S296>/Product2' incorporates:
   *  DiscreteIntegrator: '<S291>/Discrete-Time Integrator'
   *  Gain: '<S296>/Gain3'
   *  Trigonometry: '<S296>/Trigonometric Function'
   */
  rtb_Numberofsamplespercycle_f = 2.0 * cos
    (microrrede_v8_DW.DiscreteTimeIntegrator_DSTATE_k) *
    microrrede_v8_ConstB.Gain;

  /* DiscreteIntegrator: '<S302>/Integ4' */
  if (microrrede_v8_DW.Integ4_SYSTEM_ENABLE_iz != 0) {
    /* DiscreteIntegrator: '<S302>/Integ4' */
    microrrede_v8_B.Integ4_i3 = microrrede_v8_DW.Integ4_DSTATE_hw;
  } else {
    /* DiscreteIntegrator: '<S302>/Integ4' */
    microrrede_v8_B.Integ4_i3 = 2.0833335E-6 * rtb_Numberofsamplespercycle_f +
      microrrede_v8_DW.Integ4_DSTATE_hw;
  }

  /* End of DiscreteIntegrator: '<S302>/Integ4' */

  /* Saturate: '<S302>/To avoid division  by zero' */
  if (microrrede_v8_DW.UnitDelay_DSTATE_i > 1.0E+6) {
    rtb_RoundingFunction_jv = 1.0E+6;
  } else if (microrrede_v8_DW.UnitDelay_DSTATE_i < 2.2204460492503131E-16) {
    rtb_RoundingFunction_jv = 2.2204460492503131E-16;
  } else {
    rtb_RoundingFunction_jv = microrrede_v8_DW.UnitDelay_DSTATE_i;
  }

  /* Fcn: '<S302>/Number of samples per cycle' incorporates:
   *  Saturate: '<S302>/To avoid division  by zero'
   */
  rtb_RoundingFunction_ay = 1.0 / rtb_RoundingFunction_jv / 4.166667e-6;

  /* Rounding: '<S302>/Rounding Function' */
  rtb_RoundingFunction_go = ceil(rtb_RoundingFunction_ay);

  /* Gain: '<S302>/Gain' */
  microrrede_v8_B.Delay_b = 4.166667E-6 * rtb_RoundingFunction_go;

  /* S-Function (sfun_discreteVariableDelay): '<S304>/S-Function' */

  /* Level2 S-Function Block: '<S304>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[1];
    sfcnOutputs(rts,0);
  }

  /* Switch: '<S302>/Switch' incorporates:
   *  Constant: '<S302>/Constant'
   *  DigitalClock: '<S102>/Digital Clock'
   *  Gain: '<S303>/Gain1'
   *  Product: '<S302>/Product'
   *  Product: '<S303>/Product2'
   *  Product: '<S303>/Product4'
   *  Product: '<S303>/Product5'
   *  RelationalOperator: '<S302>/Relational Operator'
   *  Sum: '<S302>/Sum5'
   *  Sum: '<S302>/Sum7'
   *  Sum: '<S303>/Sum1'
   *  Sum: '<S303>/Sum4'
   *  UnitDelay: '<S291>/Unit Delay'
   *  UnitDelay: '<S302>/Unit Delay1'
   *  UnitDelay: '<S303>/Unit Delay'
   */
  if (rtb_Sum5_ij >= 0.016666666666666666) {
    /* Sum: '<S303>/Sum5' */
    rtb_RoundingFunction_go = rtb_RoundingFunction_ay - rtb_RoundingFunction_go;
    microrrede_v8_DW.UnitDelay1_DSTATE_gn = ((rtb_Numberofsamplespercycle_f -
      microrrede_v8_DW.UnitDelay_DSTATE_l) * rtb_RoundingFunction_go * 0.5 +
      rtb_Numberofsamplespercycle_f) * (rtb_RoundingFunction_go /
      rtb_RoundingFunction_ay) + (microrrede_v8_B.Integ4_i3 -
      microrrede_v8_B.SFunction_f0) * microrrede_v8_DW.UnitDelay_DSTATE_i;
  }

  /* End of Switch: '<S302>/Switch' */

  /* ComplexToMagnitudeAngle: '<S296>/Complex to Magnitude-Angle' incorporates:
   *  RealImagToComplex: '<S296>/Real-Imag to Complex'
   *  UnitDelay: '<S299>/Unit Delay1'
   *  UnitDelay: '<S302>/Unit Delay1'
   */
  rtb_RateLimiter = rt_hypotd_snf(microrrede_v8_DW.UnitDelay1_DSTATE_o,
    microrrede_v8_DW.UnitDelay1_DSTATE_gn);

  /* Saturate: '<S292>/Saturation' */
  if (rtb_RateLimiter <= 2.2204460492503131E-16) {
    rtb_RateLimiter = 2.2204460492503131E-16;
  }

  /* End of Saturate: '<S292>/Saturation' */

  /* Math: '<S292>/Math Function'
   *
   * About '<S292>/Math Function':
   *  Operator: reciprocal
   */
  microrrede_v8_B.MathFunction_c = 1.0 / rtb_RateLimiter;

  /* Update for DiscreteIntegrator: '<S299>/Integ4' */
  microrrede_v8_DW.Integ4_SYSTEM_ENABLE_l = 0U;
  microrrede_v8_DW.Integ4_DSTATE_f5 = 2.0833335E-6 * rtb_Product1_f_tmp +
    microrrede_v8_B.Integ4_jd;

  /* Update for S-Function (sfun_discreteVariableDelay): '<S301>/S-Function' */
  /* Level2 S-Function Block: '<S301>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[0];
    sfcnUpdate(rts,0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Update for UnitDelay: '<S300>/Unit Delay' */
  microrrede_v8_DW.UnitDelay_DSTATE_ne = rtb_Product1_f_tmp;

  /* Update for DiscreteIntegrator: '<S302>/Integ4' */
  microrrede_v8_DW.Integ4_SYSTEM_ENABLE_iz = 0U;
  microrrede_v8_DW.Integ4_DSTATE_hw = 2.0833335E-6 *
    rtb_Numberofsamplespercycle_f + microrrede_v8_B.Integ4_i3;

  /* Update for S-Function (sfun_discreteVariableDelay): '<S304>/S-Function' */
  /* Level2 S-Function Block: '<S304>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[1];
    sfcnUpdate(rts,0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Update for UnitDelay: '<S303>/Unit Delay' */
  microrrede_v8_DW.UnitDelay_DSTATE_l = rtb_Numberofsamplespercycle_f;

  /* End of Outputs for SubSystem: '<S291>/Automatic Gain Control' */

  /* Product: '<S291>/Product1' */
  rtb_RoundingFunction *= microrrede_v8_ConstB.Gain;

  /* DiscreteIntegrator: '<S305>/Integ4' */
  if (microrrede_v8_DW.Integ4_SYSTEM_ENABLE_j != 0) {
    /* DiscreteIntegrator: '<S305>/Integ4' */
    microrrede_v8_B.Integ4_ep = microrrede_v8_DW.Integ4_DSTATE_o;
  } else {
    /* DiscreteIntegrator: '<S305>/Integ4' */
    microrrede_v8_B.Integ4_ep = 2.0833335E-6 * rtb_RoundingFunction +
      microrrede_v8_DW.Integ4_DSTATE_o;
  }

  /* End of DiscreteIntegrator: '<S305>/Integ4' */

  /* Saturate: '<S305>/To avoid division  by zero' */
  if (microrrede_v8_DW.UnitDelay_DSTATE_i > 1.0E+6) {
    rtb_RoundingFunction_jv = 1.0E+6;
  } else if (microrrede_v8_DW.UnitDelay_DSTATE_i < 2.2204460492503131E-16) {
    rtb_RoundingFunction_jv = 2.2204460492503131E-16;
  } else {
    rtb_RoundingFunction_jv = microrrede_v8_DW.UnitDelay_DSTATE_i;
  }

  /* Fcn: '<S305>/Number of samples per cycle' incorporates:
   *  Saturate: '<S305>/To avoid division  by zero'
   */
  rtb_Numberofsamplespercycle_f = 1.0 / rtb_RoundingFunction_jv / 4.166667e-6;

  /* Rounding: '<S305>/Rounding Function' */
  rtb_RoundingFunction_ay = ceil(rtb_Numberofsamplespercycle_f);

  /* Gain: '<S305>/Gain' */
  microrrede_v8_B.Delay_c = 4.166667E-6 * rtb_RoundingFunction_ay;

  /* S-Function (sfun_discreteVariableDelay): '<S307>/S-Function' */

  /* Level2 S-Function Block: '<S307>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[11];
    sfcnOutputs(rts,0);
  }

  /* Switch: '<S305>/Switch' incorporates:
   *  Constant: '<S305>/Constant'
   *  DigitalClock: '<S102>/Digital Clock'
   *  Gain: '<S306>/Gain1'
   *  Product: '<S305>/Product'
   *  Product: '<S306>/Product2'
   *  Product: '<S306>/Product4'
   *  Product: '<S306>/Product5'
   *  RelationalOperator: '<S305>/Relational Operator'
   *  Sum: '<S305>/Sum5'
   *  Sum: '<S305>/Sum7'
   *  Sum: '<S306>/Sum1'
   *  Sum: '<S306>/Sum4'
   *  UnitDelay: '<S291>/Unit Delay'
   *  UnitDelay: '<S305>/Unit Delay1'
   *  UnitDelay: '<S306>/Unit Delay'
   */
  if (rtb_Sum5_ij >= 0.016666666666666666) {
    /* Sum: '<S306>/Sum5' */
    rtb_RoundingFunction_ay = rtb_Numberofsamplespercycle_f -
      rtb_RoundingFunction_ay;
    microrrede_v8_DW.UnitDelay1_DSTATE_h = ((rtb_RoundingFunction -
      microrrede_v8_DW.UnitDelay_DSTATE_cm) * rtb_RoundingFunction_ay * 0.5 +
      rtb_RoundingFunction) * (rtb_RoundingFunction_ay /
      rtb_Numberofsamplespercycle_f) + (microrrede_v8_B.Integ4_ep -
      microrrede_v8_B.SFunction_m) * microrrede_v8_DW.UnitDelay_DSTATE_i;
  }

  /* End of Switch: '<S305>/Switch' */

  /* Product: '<S291>/Divide' incorporates:
   *  UnitDelay: '<S305>/Unit Delay1'
   */
  rtb_Numberofsamplespercycle_f = microrrede_v8_DW.UnitDelay1_DSTATE_h *
    microrrede_v8_B.MathFunction_c;

  /* DiscreteTransferFcn: '<S293>/Discrete Derivative ' */
  rtb_RoundingFunction_ay = (rtb_Numberofsamplespercycle_f - -9.5833333E-5 *
    microrrede_v8_DW.DiscreteDerivative_states) / 0.0001;

  /* Sum: '<S293>/Sum6' incorporates:
   *  DiscreteIntegrator: '<S293>/Discrete-Time Integrator'
   *  DiscreteTransferFcn: '<S293>/Discrete Derivative '
   *  Gain: '<S293>/Kp4'
   */
  rtb_Integrator_l = (180.0 * rtb_Numberofsamplespercycle_f +
                      microrrede_v8_DW.DiscreteTimeIntegrator_DSTATE_n) +
    (rtb_RoundingFunction_ay - microrrede_v8_DW.DiscreteDerivative_states);

  /* Saturate: '<S293>/Saturation1' */
  if (rtb_Integrator_l <= 0.0) {
    rtb_Saturation1 = 0.0;
  } else {
    rtb_Saturation1 = rtb_Integrator_l;
  }

  /* End of Saturate: '<S293>/Saturation1' */

  /* Gain: '<S291>/Gain10' */
  rtb_Integrator_l = 0.15915494309189535 * rtb_Saturation1;

  /* RateLimiter: '<S291>/Rate Limiter' */
  rtb_Saturation_d = rtb_Integrator_l - microrrede_v8_DW.PrevY;
  if (rtb_Saturation_d > 5.0000004E-5) {
    rtb_Integrator_l = microrrede_v8_DW.PrevY + 5.0000004E-5;
  } else if (rtb_Saturation_d < -5.0000004E-5) {
    rtb_Integrator_l = microrrede_v8_DW.PrevY - 5.0000004E-5;
  }

  microrrede_v8_DW.PrevY = rtb_Integrator_l;

  /* End of RateLimiter: '<S291>/Rate Limiter' */

  /* UnitDelay: '<S308>/Delay_x1' */
  rtb_RoundingFunction_go = microrrede_v8_DW.Delay_x1_DSTATE;

  /* UnitDelay: '<S308>/Delay_x2' */
  rtb_x2k = microrrede_v8_DW.Delay_x2_DSTATE;

  /* Gain: '<S309>/A21' incorporates:
   *  UnitDelay: '<S308>/Delay_x1'
   */
  rtb_A21 = -0.10276083316900773 * microrrede_v8_DW.Delay_x1_DSTATE;

  /* Sum: '<S308>/A*x1(k) + B*u1(k) ' incorporates:
   *  Gain: '<S309>/A11'
   *  Gain: '<S309>/A12'
   *  Gain: '<S310>/B11'
   *  Sum: '<S309>/sum2'
   *  UnitDelay: '<S308>/Delay_x1'
   *  UnitDelay: '<S308>/Delay_x2'
   */
  microrrede_v8_DW.Delay_x1_DSTATE = (0.99999978591491367 *
    microrrede_v8_DW.Delay_x1_DSTATE + 4.1647394021622489E-6 *
    microrrede_v8_DW.Delay_x2_DSTATE) + 2.082369701081124E-6 * rtb_Integrator_l;

  /* Sum: '<S308>/A*x2(k) + B*u2(k)' incorporates:
   *  Gain: '<S309>/A22'
   *  Gain: '<S310>/B21'
   *  Sum: '<S309>/sum3'
   *  UnitDelay: '<S308>/Delay_x2'
   */
  microrrede_v8_DW.Delay_x2_DSTATE = (0.999074753111899 *
    microrrede_v8_DW.Delay_x2_DSTATE + rtb_A21) + 0.99953737655594943 *
    rtb_Integrator_l;

  /* Sum: '<S308>/C*X(k)+D*u(k)' incorporates:
   *  Gain: '<S308>/D*u(k)'
   *  Gain: '<S311>/C11'
   *  Gain: '<S311>/C12'
   *  Sum: '<S311>/sum2'
   *  UnitDelay: '<S291>/Unit Delay'
   */
  microrrede_v8_DW.UnitDelay_DSTATE_i = (0.10280838373778885 *
    rtb_RoundingFunction_go + 2.1408508622890496E-7 * rtb_x2k) +
    1.0704254311445248E-7 * rtb_Integrator_l;

  /* Sum: '<S695>/Add1' incorporates:
   *  Constant: '<S695>/Rs_array_'
   *  Product: '<S695>/Product2'
   */
  rtb_Integrator_l = microrrede_v8_B.StateSpace_o1[70] * 4.6101 +
    microrrede_v8_B.StateSpace_o1[46];

  /* Sum: '<S688>/Add1' incorporates:
   *  Constant: '<S688>/Rsh_array'
   *  Constant: '<S688>/Rsh_array_5%Sref'
   *  Constant: '<S688>/one'
   *  Math: '<S688>/Math Function'
   *  Product: '<S688>/Product'
   *  Product: '<S688>/Product1'
   *  Product: '<S688>/Product2'
   *  Product: '<S688>/Product5'
   *  Sum: '<S688>/Add'
   *  UnitDelay: '<S688>/Unit Delay'
   *
   * About '<S688>/Math Function':
   *  Operator: exp
   */
  microrrede_v8_DW.UnitDelay_DSTATE_c = ((exp(1.0 / microrrede_v8_ConstB.VT_p *
    rtb_Integrator_l) - 1.0) * microrrede_v8_ConstB.Product4_i +
    rtb_Integrator_l / 2322.603 * rtb_Integrator_jg) - rtb_Integrator_l /
    46452.06;

  /* MATLAB Function: '<S773>/MATLAB Function' */
  microrrede_v8_MATLABFunction(microrrede_v8_B.StateSpace_o1[47],
    microrrede_v8_B.StateSpace_o1[71], &rtb_RateLimiter,
    &microrrede_v8_DW.sf_MATLABFunction_c);

  /* Sum: '<S773>/Sum' */
  rtb_Integrator_l = microrrede_v8_B.StateSpace_o1[47] - rtb_RateLimiter;

  /* Gain: '<S811>/Integral Gain' */
  rtb_A21 = 0.0075 * rtb_Integrator_l;

  /* Sum: '<S823>/Sum' incorporates:
   *  DiscreteIntegrator: '<S814>/Integrator'
   *  Gain: '<S819>/Proportional Gain'
   */
  rtb_Integrator_l = 0.0075 * rtb_Integrator_l +
    microrrede_v8_DW.Integrator_DSTATE_p;

  /* DataTypeConversion: '<S782>/Data Type Conversion' incorporates:
   *  Constant: '<S831>/Constant'
   *  Logic: '<S782>/Logical Operator'
   *  RelationalOperator: '<S782>/Relational Operator'
   *  RelationalOperator: '<S831>/Compare'
   */
  microrrede_v8_B.DataTypeConversion_a = ((rtb_Integrator_l != 0.0) &&
    (rtb_Integrator_l >= DataTypeConversion_tmp));

  /* Lookup_n-D: '<S845>/1-D Lookup Table' */
  rtb_Integrator_l = look1_pbinlxpw(rtb_Integrator_bx_tmp,
    microrrede_v8_ConstP.pooled58, microrrede_v8_ConstP.pooled57,
    &microrrede_v8_DW.m_bpIndex_e, 2U);

  /* Sum: '<S836>/Add4' incorporates:
   *  Constant: '<S845>/Constant2'
   *  Product: '<S836>/MUL1'
   *  Sum: '<S845>/Add3'
   */
  rtb_Integrator_l = ((rtb_Integrator_l - 1.0) * microrrede_v8_ConstB.Gain1_d -
                      1.0) + microrrede_v8_ConstB.Gain1_d;

  /* DiscreteIntegrator: '<S861>/Integ4' */
  if (microrrede_v8_DW.Integ4_SYSTEM_ENABLE_n != 0) {
    /* DiscreteIntegrator: '<S861>/Integ4' */
    microrrede_v8_B.Integ4_b = microrrede_v8_DW.Integ4_DSTATE_f;
  } else {
    /* DiscreteIntegrator: '<S861>/Integ4' */
    microrrede_v8_B.Integ4_b = 2.0833335E-6 * microrrede_v8_B.StateSpace_o1[61]
      + microrrede_v8_DW.Integ4_DSTATE_f;
  }

  /* End of DiscreteIntegrator: '<S861>/Integ4' */

  /* S-Function (sfun_discreteVariableDelay): '<S862>/S-Function' incorporates:
   *  Constant: '<S861>/K1'
   */

  /* Level2 S-Function Block: '<S862>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[12];
    sfcnOutputs(rts,0);
  }

  /* Switch: '<S861>/Switch' incorporates:
   *  Constant: '<S861>/K1'
   *  Constant: '<S861>/K2'
   *  DigitalClock: '<S102>/Digital Clock'
   *  Gain: '<S861>/Gain'
   *  Gain: '<S861>/Gain1'
   *  Product: '<S861>/Product'
   *  RelationalOperator: '<S861>/Relational Operator'
   *  Sum: '<S861>/Sum1'
   *  Sum: '<S861>/Sum5'
   *  Sum: '<S861>/Sum7'
   *  UnitDelay: '<S861>/Unit Delay'
   *  UnitDelay: '<S861>/Unit Delay1'
   */
  if (rtb_Sum5_ij >= 0.016666668) {
    microrrede_v8_DW.UnitDelay1_DSTATE_ci = (microrrede_v8_B.Integ4_b -
      microrrede_v8_B.SFunction_j) * 60.0 + (-7.9987200059934818E-8 *
      microrrede_v8_B.StateSpace_o1[61] - 1.2799998994857576E-11 *
      microrrede_v8_DW.UnitDelay_DSTATE_gf);
  }

  /* End of Switch: '<S861>/Switch' */

  /* Saturate: '<S851>/Saturation' */
  if (microrrede_v8_DW.UnitDelay_DSTATE_e > 70.0) {
    rtb_RoundingFunction_jv = 70.0;
  } else if (microrrede_v8_DW.UnitDelay_DSTATE_e < 40.0) {
    rtb_RoundingFunction_jv = 40.0;
  } else {
    rtb_RoundingFunction_jv = microrrede_v8_DW.UnitDelay_DSTATE_e;
  }

  /* Gain: '<S851>/Gain' incorporates:
   *  Math: '<S851>/Math Function'
   *  Saturate: '<S851>/Saturation'
   *
   * About '<S851>/Math Function':
   *  Operator: reciprocal
   */
  microrrede_v8_B.Gain_m = 1.0 / rtb_RoundingFunction_jv * 0.25;

  /* S-Function (sfun_discreteVariableDelay): '<S933>/S-Function' */

  /* Level2 S-Function Block: '<S933>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[13];
    sfcnOutputs(rts,0);
  }

  /* RelationalOperator: '<S911>/Relational Operator' incorporates:
   *  Constant: '<S911>/Constant2'
   */
  rtb_RelationalOperator_hn = (microrrede_v8_DW.DiscreteTimeIntegrator_DSTATE_h >
    6.2831853071795862);

  /* InitialCondition: '<S911>/Initial' */
  if (microrrede_v8_DW.Initial_FirstOutputTime_o) {
    microrrede_v8_DW.Initial_FirstOutputTime_o = false;

    /* InitialCondition: '<S911>/Initial' */
    rtb_RoundingFunction_go = 0.0;
  } else {
    /* InitialCondition: '<S911>/Initial' incorporates:
     *  Constant: '<S911>/Constant2'
     *  Sum: '<S911>/Subtract'
     */
    rtb_RoundingFunction_go = microrrede_v8_DW.DiscreteTimeIntegrator_DSTATE_h -
      6.2831853071795862;
  }

  /* End of InitialCondition: '<S911>/Initial' */

  /* DiscreteIntegrator: '<S911>/Discrete-Time Integrator' */
  if (rtb_RelationalOperator_hn &&
      (microrrede_v8_DW.DiscreteTimeIntegrator_PrevRe_g <= 0)) {
    microrrede_v8_DW.DiscreteTimeIntegrator_DSTATE_h = rtb_RoundingFunction_go;
  }

  /* Outputs for Enabled SubSystem: '<S932>/Subsystem1' */
  microrrede_v8_Subsystem1(microrrede_v8_ConstB.Compare_m,
    microrrede_v8_ConstB.Gain2_b, microrrede_v8_B.SFunction_oz,
    microrrede_v8_DW.DiscreteTimeIntegrator_DSTATE_h, &microrrede_v8_B.Fcn,
    &microrrede_v8_B.Fcn1);

  /* End of Outputs for SubSystem: '<S932>/Subsystem1' */

  /* Outputs for Enabled SubSystem: '<S932>/Subsystem - pi//2 delay' */
  microrrede_v8_Subsystempi2delay(microrrede_v8_ConstB.Compare_h,
    microrrede_v8_ConstB.Gain2_b, microrrede_v8_B.SFunction_oz,
    microrrede_v8_DW.DiscreteTimeIntegrator_DSTATE_h, &microrrede_v8_B.Fcn_g,
    &microrrede_v8_B.Fcn1_c);

  /* End of Outputs for SubSystem: '<S932>/Subsystem - pi//2 delay' */

  /* Switch: '<S932>/Switch' */
  if (microrrede_v8_ConstB.Compare_m != 0) {
    rtb_RoundingFunction_go = microrrede_v8_B.Fcn;
    rtb_x2k = microrrede_v8_B.Fcn1;
  } else {
    rtb_RoundingFunction_go = microrrede_v8_B.Fcn_g;
    rtb_x2k = microrrede_v8_B.Fcn1_c;
  }

  /* End of Switch: '<S932>/Switch' */

  /* Gain: '<S835>/Gain3' incorporates:
   *  Constant: '<S835>/Constant'
   *  Sum: '<S835>/Add'
   *  UnitDelay: '<S861>/Unit Delay1'
   */
  rtb_Gain3_m = (microrrede_v8_DW.UnitDelay1_DSTATE_ci - 400.0) * 0.0025;

  /* Sum: '<S903>/Sum' incorporates:
   *  DiscreteIntegrator: '<S894>/Integrator'
   *  Gain: '<S899>/Proportional Gain'
   */
  rtb_Integrator_jg = 12.0 * rtb_Gain3_m + microrrede_v8_DW.Integrator_DSTATE_h;

  /* Saturate: '<S901>/Saturation' */
  if (rtb_Integrator_jg > 1.5) {
    rtb_Integrator_jg = 1.5;
  } else if (rtb_Integrator_jg < -1.5) {
    rtb_Integrator_jg = -1.5;
  }

  /* End of Saturate: '<S901>/Saturation' */

  /* Sum: '<S852>/Add' incorporates:
   *  Constant: '<S835>/Constant1'
   */
  rtb_RoundingFunction_go = rtb_Integrator_jg - rtb_RoundingFunction_go;
  rtb_x2k = 0.0 - rtb_x2k;

  /* Sum: '<S979>/Sum' incorporates:
   *  DiscreteIntegrator: '<S970>/Integrator'
   *  Gain: '<S975>/Proportional Gain'
   */
  rtb_RoundingFunction_m = 0.15 * rtb_RoundingFunction_go +
    microrrede_v8_DW.Integrator_DSTATE_f5[0];
  rtb_Numberofsamplespercycle_ej = 0.15 * rtb_x2k +
    microrrede_v8_DW.Integrator_DSTATE_f5[1];

  /* Outputs for Enabled SubSystem: '<S911>/Automatic Gain Control' incorporates:
   *  EnablePort: '<S912>/Enable'
   */
  /* Product: '<S846>/Product1' incorporates:
   *  DiscreteIntegrator: '<S911>/Discrete-Time Integrator'
   *  Gain: '<S846>/Gain1'
   *  Product: '<S916>/Product1'
   *  Trigonometry: '<S846>/Trigonometric Function'
   */
  DataTypeConversion_tmp = 2.0 * sin
    (microrrede_v8_DW.DiscreteTimeIntegrator_DSTATE_h) *
    microrrede_v8_ConstB.Gain_n;

  /* End of Outputs for SubSystem: '<S911>/Automatic Gain Control' */

  /* DiscreteIntegrator: '<S855>/Integ4' */
  if (microrrede_v8_DW.Integ4_SYSTEM_ENABLE_nm != 0) {
    /* DiscreteIntegrator: '<S855>/Integ4' */
    microrrede_v8_B.Integ4_j = microrrede_v8_DW.Integ4_DSTATE_fu;
  } else {
    /* DiscreteIntegrator: '<S855>/Integ4' incorporates:
     *  Product: '<S846>/Product1'
     */
    microrrede_v8_B.Integ4_j = 2.0833335E-6 * DataTypeConversion_tmp +
      microrrede_v8_DW.Integ4_DSTATE_fu;
  }

  /* End of DiscreteIntegrator: '<S855>/Integ4' */

  /* Saturate: '<S855>/To avoid division  by zero' */
  if (microrrede_v8_DW.UnitDelay_DSTATE_e > 1.0E+6) {
    rtb_RoundingFunction_jv = 1.0E+6;
  } else if (microrrede_v8_DW.UnitDelay_DSTATE_e < 2.2204460492503131E-16) {
    rtb_RoundingFunction_jv = 2.2204460492503131E-16;
  } else {
    rtb_RoundingFunction_jv = microrrede_v8_DW.UnitDelay_DSTATE_e;
  }

  /* Fcn: '<S855>/Number of samples per cycle' incorporates:
   *  Saturate: '<S855>/To avoid division  by zero'
   */
  rtb_Numberofsamplespercycle_e = 1.0 / rtb_RoundingFunction_jv / 4.166667e-6;

  /* Rounding: '<S855>/Rounding Function' */
  rtb_RoundingFunction_d4 = ceil(rtb_Numberofsamplespercycle_e);

  /* Gain: '<S855>/Gain' */
  microrrede_v8_B.Delay_n = 4.166667E-6 * rtb_RoundingFunction_d4;

  /* S-Function (sfun_discreteVariableDelay): '<S857>/S-Function' */

  /* Level2 S-Function Block: '<S857>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[14];
    sfcnOutputs(rts,0);
  }

  /* Switch: '<S855>/Switch' incorporates:
   *  Constant: '<S855>/Constant'
   *  DigitalClock: '<S102>/Digital Clock'
   *  Gain: '<S856>/Gain1'
   *  Product: '<S846>/Product1'
   *  Product: '<S855>/Product'
   *  Product: '<S856>/Product2'
   *  Product: '<S856>/Product4'
   *  Product: '<S856>/Product5'
   *  RelationalOperator: '<S855>/Relational Operator'
   *  Sum: '<S855>/Sum5'
   *  Sum: '<S855>/Sum7'
   *  Sum: '<S856>/Sum1'
   *  Sum: '<S856>/Sum4'
   *  UnitDelay: '<S855>/Unit Delay1'
   *  UnitDelay: '<S856>/Unit Delay'
   *  UnitDelay: '<S911>/Unit Delay'
   */
  if (rtb_Sum5_ij >= 0.016666666666666666) {
    /* Sum: '<S856>/Sum5' */
    rtb_RoundingFunction_d4 = rtb_Numberofsamplespercycle_e -
      rtb_RoundingFunction_d4;
    microrrede_v8_DW.UnitDelay1_DSTATE_n = ((DataTypeConversion_tmp -
      microrrede_v8_DW.UnitDelay_DSTATE_h) * rtb_RoundingFunction_d4 * 0.5 +
      DataTypeConversion_tmp) * (rtb_RoundingFunction_d4 /
      rtb_Numberofsamplespercycle_e) + (microrrede_v8_B.Integ4_j -
      microrrede_v8_B.SFunction_g) * microrrede_v8_DW.UnitDelay_DSTATE_e;
  }

  /* End of Switch: '<S855>/Switch' */

  /* Trigonometry: '<S846>/Trigonometric Function' incorporates:
   *  DiscreteIntegrator: '<S911>/Discrete-Time Integrator'
   *  Trigonometry: '<S911>/Trigonometric Function2'
   */
  rtb_RoundingFunction_d4 = cos(microrrede_v8_DW.DiscreteTimeIntegrator_DSTATE_h);

  /* Product: '<S846>/Product2' incorporates:
   *  Gain: '<S846>/Gain3'
   *  Trigonometry: '<S846>/Trigonometric Function'
   */
  rtb_Numberofsamplespercycle_e = 2.0 * rtb_RoundingFunction_d4 *
    microrrede_v8_ConstB.Gain_n;

  /* DiscreteIntegrator: '<S858>/Integ4' */
  if (microrrede_v8_DW.Integ4_SYSTEM_ENABLE_i != 0) {
    /* DiscreteIntegrator: '<S858>/Integ4' */
    microrrede_v8_B.Integ4_f = microrrede_v8_DW.Integ4_DSTATE_d;
  } else {
    /* DiscreteIntegrator: '<S858>/Integ4' */
    microrrede_v8_B.Integ4_f = 2.0833335E-6 * rtb_Numberofsamplespercycle_e +
      microrrede_v8_DW.Integ4_DSTATE_d;
  }

  /* End of DiscreteIntegrator: '<S858>/Integ4' */

  /* Saturate: '<S858>/To avoid division  by zero' */
  if (microrrede_v8_DW.UnitDelay_DSTATE_e > 1.0E+6) {
    rtb_RoundingFunction_jv = 1.0E+6;
  } else if (microrrede_v8_DW.UnitDelay_DSTATE_e < 2.2204460492503131E-16) {
    rtb_RoundingFunction_jv = 2.2204460492503131E-16;
  } else {
    rtb_RoundingFunction_jv = microrrede_v8_DW.UnitDelay_DSTATE_e;
  }

  /* Fcn: '<S858>/Number of samples per cycle' incorporates:
   *  Saturate: '<S858>/To avoid division  by zero'
   */
  rtb_Numberofsamplespercycle_mb = 1.0 / rtb_RoundingFunction_jv / 4.166667e-6;

  /* Rounding: '<S858>/Rounding Function' */
  rtb_RoundingFunction_je = ceil(rtb_Numberofsamplespercycle_mb);

  /* Gain: '<S858>/Gain' */
  microrrede_v8_B.Delay_i = 4.166667E-6 * rtb_RoundingFunction_je;

  /* S-Function (sfun_discreteVariableDelay): '<S860>/S-Function' */

  /* Level2 S-Function Block: '<S860>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[15];
    sfcnOutputs(rts,0);
  }

  /* Switch: '<S858>/Switch' incorporates:
   *  Constant: '<S858>/Constant'
   *  DigitalClock: '<S102>/Digital Clock'
   *  Gain: '<S859>/Gain1'
   *  Product: '<S858>/Product'
   *  Product: '<S859>/Product2'
   *  Product: '<S859>/Product4'
   *  Product: '<S859>/Product5'
   *  RelationalOperator: '<S858>/Relational Operator'
   *  Sum: '<S858>/Sum5'
   *  Sum: '<S858>/Sum7'
   *  Sum: '<S859>/Sum1'
   *  Sum: '<S859>/Sum4'
   *  UnitDelay: '<S858>/Unit Delay1'
   *  UnitDelay: '<S859>/Unit Delay'
   *  UnitDelay: '<S911>/Unit Delay'
   */
  if (rtb_Sum5_ij >= 0.016666666666666666) {
    /* Sum: '<S859>/Sum5' */
    rtb_RoundingFunction_je = rtb_Numberofsamplespercycle_mb -
      rtb_RoundingFunction_je;
    microrrede_v8_DW.UnitDelay1_DSTATE_e = ((rtb_Numberofsamplespercycle_e -
      microrrede_v8_DW.UnitDelay_DSTATE_ds) * rtb_RoundingFunction_je * 0.5 +
      rtb_Numberofsamplespercycle_e) * (rtb_RoundingFunction_je /
      rtb_Numberofsamplespercycle_mb) + (microrrede_v8_B.Integ4_f -
      microrrede_v8_B.SFunction_ed) * microrrede_v8_DW.UnitDelay_DSTATE_e;
  }

  /* End of Switch: '<S858>/Switch' */

  /* Gain: '<S835>/Gain1' incorporates:
   *  ComplexToMagnitudeAngle: '<S846>/Complex to Magnitude-Angle'
   *  Gain: '<S846>/Rad->Deg.'
   *  RealImagToComplex: '<S846>/Real-Imag to Complex'
   *  UnitDelay: '<S855>/Unit Delay1'
   *  UnitDelay: '<S858>/Unit Delay1'
   */
  rtb_Add4 = 57.295779513082323 * rt_atan2d_snf
    (microrrede_v8_DW.UnitDelay1_DSTATE_e, microrrede_v8_DW.UnitDelay1_DSTATE_n)
    * 0.017453292519943295;

  /* Product: '<S850>/Divide1' incorporates:
   *  Constant: '<S850>/Constant'
   *  Product: '<S850>/Divide'
   *  UnitDelay: '<S861>/Unit Delay1'
   */
  rtb_RoundingFunction_jv = 1.0 / (microrrede_v8_DW.UnitDelay1_DSTATE_ci /
    311.12698372208092);

  /* Saturate: '<S977>/Saturation' */
  if (rtb_RoundingFunction_m > 1.5) {
    rtb_RoundingFunction_m = 1.5;
  } else if (rtb_RoundingFunction_m < -1.5) {
    rtb_RoundingFunction_m = -1.5;
  }

  /* ComplexToMagnitudeAngle: '<S846>/Complex to Magnitude-Angle' incorporates:
   *  RealImagToComplex: '<S846>/Real-Imag to Complex'
   *  UnitDelay: '<S855>/Unit Delay1'
   *  UnitDelay: '<S858>/Unit Delay1'
   */
  rtb_Numberofsamplespercycle_mb = rt_hypotd_snf
    (microrrede_v8_DW.UnitDelay1_DSTATE_n, microrrede_v8_DW.UnitDelay1_DSTATE_e);

  /* Sum: '<S852>/Add1' incorporates:
   *  ComplexToMagnitudeAngle: '<S846>/Complex to Magnitude-Angle'
   *  Gain: '<S852>/Gain'
   *  MagnitudeAngleToComplex: '<S835>/Magnitude-Angle to Complex'
   *  Saturate: '<S977>/Saturation'
   *  Sum: '<S852>/Add2'
   */
  rtb_RoundingFunction_je = ((rtb_Numberofsamplespercycle_mb * cos(rtb_Add4) +
    0.002 * rtb_Integrator_jg) - microrrede_v8_ConstB.Gain1_e) +
    rtb_RoundingFunction_m;

  /* Saturate: '<S977>/Saturation' */
  if (rtb_Numberofsamplespercycle_ej > 1.5) {
    rtb_Numberofsamplespercycle_ej = 1.5;
  } else if (rtb_Numberofsamplespercycle_ej < -1.5) {
    rtb_Numberofsamplespercycle_ej = -1.5;
  }

  /* Sum: '<S852>/Add1' incorporates:
   *  Gain: '<S852>/Gain2'
   *  MagnitudeAngleToComplex: '<S835>/Magnitude-Angle to Complex'
   *  Saturate: '<S977>/Saturation'
   *  Sum: '<S852>/Add3'
   */
  rtb_A21_p = ((rtb_Numberofsamplespercycle_mb * sin(rtb_Add4) + 0.2 *
                rtb_Integrator_jg) + microrrede_v8_ConstB.Gain3_p) +
    rtb_Numberofsamplespercycle_ej;

  /* Saturate: '<S852>/Saturation' */
  if (rtb_RoundingFunction_je > 1.5) {
    rtb_RoundingFunction_je = 1.5;
  } else if (rtb_RoundingFunction_je < -1.5) {
    rtb_RoundingFunction_je = -1.5;
  }

  /* Product: '<S850>/Divide1' incorporates:
   *  Saturate: '<S852>/Saturation'
   */
  rtb_RoundingFunction_je *= rtb_RoundingFunction_jv;

  /* Saturate: '<S852>/Saturation' */
  if (rtb_A21_p > 1.5) {
    rtb_A21_p = 1.5;
  } else if (rtb_A21_p < -1.5) {
    rtb_A21_p = -1.5;
  }

  /* Product: '<S850>/Divide1' incorporates:
   *  Saturate: '<S852>/Saturation'
   */
  rtb_A21_p *= rtb_RoundingFunction_jv;

  /* Product: '<S850>/Divide2' incorporates:
   *  ComplexToMagnitudeAngle: '<S850>/Complex to Magnitude-Angle'
   *  Constant: '<S850>/Constant1'
   *  DiscreteIntegrator: '<S911>/Discrete-Time Integrator'
   *  RealImagToComplex: '<S850>/Real-Imag to Complex'
   *  Sum: '<S850>/Add'
   *  Sum: '<S850>/Add1'
   *  Trigonometry: '<S850>/Sin'
   */
  rtb_Add4 = sin((microrrede_v8_DW.DiscreteTimeIntegrator_DSTATE_h +
                  0.0037699111843077517) + rt_atan2d_snf(rtb_A21_p,
    rtb_RoundingFunction_je)) * rt_hypotd_snf(rtb_RoundingFunction_je, rtb_A21_p);

  /* RelationalOperator: '<S840>/Relational Operator1' */
  rtb_RelationalOperator1 = (rtb_Add4 >= rtb_Integrator_l);

  /* RelationalOperator: '<S840>/Relational Operator3' incorporates:
   *  Gain: '<S840>/Gain'
   */
  rtb_RelationalOperator3 = (-rtb_Add4 >= rtb_Integrator_l);

  /* DataTypeConversion: '<S834>/Data Type Conversion' incorporates:
   *  Logic: '<S834>/Logical Operator4'
   */
  microrrede_v8_B.DataTypeConversion_i[0] = rtb_RelationalOperator1;
  microrrede_v8_B.DataTypeConversion_i[1] = !rtb_RelationalOperator1;
  microrrede_v8_B.DataTypeConversion_i[2] = rtb_RelationalOperator3;
  microrrede_v8_B.DataTypeConversion_i[3] = !rtb_RelationalOperator3;

  /* Gain: '<S891>/Integral Gain' */
  rtb_Integrator_jg = 200.0 * rtb_Gain3_m;

  /* Outputs for Enabled SubSystem: '<S911>/Automatic Gain Control' incorporates:
   *  EnablePort: '<S912>/Enable'
   */
  if (!microrrede_v8_DW.AutomaticGainControl_MODE) {
    /* Enable for DiscreteIntegrator: '<S919>/Integ4' */
    microrrede_v8_DW.Integ4_SYSTEM_ENABLE_g = 1U;

    /* Enable for DiscreteIntegrator: '<S922>/Integ4' */
    microrrede_v8_DW.Integ4_SYSTEM_ENABLE_gv = 1U;
    microrrede_v8_DW.AutomaticGainControl_MODE = true;
  }

  /* DiscreteIntegrator: '<S919>/Integ4' */
  if (microrrede_v8_DW.Integ4_SYSTEM_ENABLE_g != 0) {
    /* DiscreteIntegrator: '<S919>/Integ4' */
    microrrede_v8_B.Integ4_m = microrrede_v8_DW.Integ4_DSTATE_e;
  } else {
    /* DiscreteIntegrator: '<S919>/Integ4' */
    microrrede_v8_B.Integ4_m = 2.0833335E-6 * DataTypeConversion_tmp +
      microrrede_v8_DW.Integ4_DSTATE_e;
  }

  /* End of DiscreteIntegrator: '<S919>/Integ4' */

  /* Saturate: '<S919>/To avoid division  by zero' */
  if (microrrede_v8_DW.UnitDelay_DSTATE_e > 1.0E+6) {
    rtb_RoundingFunction_jv = 1.0E+6;
  } else if (microrrede_v8_DW.UnitDelay_DSTATE_e < 2.2204460492503131E-16) {
    rtb_RoundingFunction_jv = 2.2204460492503131E-16;
  } else {
    rtb_RoundingFunction_jv = microrrede_v8_DW.UnitDelay_DSTATE_e;
  }

  /* Fcn: '<S919>/Number of samples per cycle' incorporates:
   *  Saturate: '<S919>/To avoid division  by zero'
   */
  rtb_Gain3_m = 1.0 / rtb_RoundingFunction_jv / 4.166667e-6;

  /* Rounding: '<S919>/Rounding Function' */
  rtb_Integrator_l = ceil(rtb_Gain3_m);

  /* Gain: '<S919>/Gain' */
  microrrede_v8_B.Delay_h = 4.166667E-6 * rtb_Integrator_l;

  /* S-Function (sfun_discreteVariableDelay): '<S921>/S-Function' */

  /* Level2 S-Function Block: '<S921>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[4];
    sfcnOutputs(rts,0);
  }

  /* Switch: '<S919>/Switch' incorporates:
   *  Constant: '<S919>/Constant'
   *  DigitalClock: '<S102>/Digital Clock'
   *  Gain: '<S920>/Gain1'
   *  Product: '<S919>/Product'
   *  Product: '<S920>/Product2'
   *  Product: '<S920>/Product4'
   *  Product: '<S920>/Product5'
   *  RelationalOperator: '<S919>/Relational Operator'
   *  Sum: '<S919>/Sum5'
   *  Sum: '<S919>/Sum7'
   *  Sum: '<S920>/Sum1'
   *  Sum: '<S920>/Sum4'
   *  UnitDelay: '<S911>/Unit Delay'
   *  UnitDelay: '<S919>/Unit Delay1'
   *  UnitDelay: '<S920>/Unit Delay'
   */
  if (rtb_Sum5_ij >= 0.016666666666666666) {
    /* Sum: '<S920>/Sum5' */
    rtb_Integrator_l = rtb_Gain3_m - rtb_Integrator_l;
    microrrede_v8_DW.UnitDelay1_DSTATE_k = ((DataTypeConversion_tmp -
      microrrede_v8_DW.UnitDelay_DSTATE_j) * rtb_Integrator_l * 0.5 +
      DataTypeConversion_tmp) * (rtb_Integrator_l / rtb_Gain3_m) +
      (microrrede_v8_B.Integ4_m - microrrede_v8_B.SFunction_ip) *
      microrrede_v8_DW.UnitDelay_DSTATE_e;
  }

  /* End of Switch: '<S919>/Switch' */

  /* Product: '<S916>/Product2' incorporates:
   *  DiscreteIntegrator: '<S911>/Discrete-Time Integrator'
   *  Gain: '<S916>/Gain3'
   *  Trigonometry: '<S916>/Trigonometric Function'
   */
  rtb_Gain3_m = 2.0 * cos(microrrede_v8_DW.DiscreteTimeIntegrator_DSTATE_h) *
    microrrede_v8_ConstB.Gain_n;

  /* DiscreteIntegrator: '<S922>/Integ4' */
  if (microrrede_v8_DW.Integ4_SYSTEM_ENABLE_gv != 0) {
    /* DiscreteIntegrator: '<S922>/Integ4' */
    microrrede_v8_B.Integ4_je = microrrede_v8_DW.Integ4_DSTATE_aa;
  } else {
    /* DiscreteIntegrator: '<S922>/Integ4' */
    microrrede_v8_B.Integ4_je = 2.0833335E-6 * rtb_Gain3_m +
      microrrede_v8_DW.Integ4_DSTATE_aa;
  }

  /* End of DiscreteIntegrator: '<S922>/Integ4' */

  /* Saturate: '<S922>/To avoid division  by zero' */
  if (microrrede_v8_DW.UnitDelay_DSTATE_e > 1.0E+6) {
    rtb_RoundingFunction_jv = 1.0E+6;
  } else if (microrrede_v8_DW.UnitDelay_DSTATE_e < 2.2204460492503131E-16) {
    rtb_RoundingFunction_jv = 2.2204460492503131E-16;
  } else {
    rtb_RoundingFunction_jv = microrrede_v8_DW.UnitDelay_DSTATE_e;
  }

  /* Fcn: '<S922>/Number of samples per cycle' incorporates:
   *  Saturate: '<S922>/To avoid division  by zero'
   */
  rtb_Integrator_l = 1.0 / rtb_RoundingFunction_jv / 4.166667e-6;

  /* Rounding: '<S922>/Rounding Function' */
  rtb_Numberofsamplespercycle_mb = ceil(rtb_Integrator_l);

  /* Gain: '<S922>/Gain' */
  microrrede_v8_B.Delay_j = 4.166667E-6 * rtb_Numberofsamplespercycle_mb;

  /* S-Function (sfun_discreteVariableDelay): '<S924>/S-Function' */

  /* Level2 S-Function Block: '<S924>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[5];
    sfcnOutputs(rts,0);
  }

  /* Switch: '<S922>/Switch' incorporates:
   *  Constant: '<S922>/Constant'
   *  DigitalClock: '<S102>/Digital Clock'
   *  Gain: '<S923>/Gain1'
   *  Product: '<S922>/Product'
   *  Product: '<S923>/Product2'
   *  Product: '<S923>/Product4'
   *  Product: '<S923>/Product5'
   *  RelationalOperator: '<S922>/Relational Operator'
   *  Sum: '<S922>/Sum5'
   *  Sum: '<S922>/Sum7'
   *  Sum: '<S923>/Sum1'
   *  Sum: '<S923>/Sum4'
   *  UnitDelay: '<S911>/Unit Delay'
   *  UnitDelay: '<S922>/Unit Delay1'
   *  UnitDelay: '<S923>/Unit Delay'
   */
  if (rtb_Sum5_ij >= 0.016666666666666666) {
    /* Sum: '<S923>/Sum5' */
    rtb_Numberofsamplespercycle_mb = rtb_Integrator_l -
      rtb_Numberofsamplespercycle_mb;
    microrrede_v8_DW.UnitDelay1_DSTATE_b = ((rtb_Gain3_m -
      microrrede_v8_DW.UnitDelay_DSTATE_ar) * rtb_Numberofsamplespercycle_mb *
      0.5 + rtb_Gain3_m) * (rtb_Numberofsamplespercycle_mb / rtb_Integrator_l) +
      (microrrede_v8_B.Integ4_je - microrrede_v8_B.SFunction_a) *
      microrrede_v8_DW.UnitDelay_DSTATE_e;
  }

  /* End of Switch: '<S922>/Switch' */

  /* ComplexToMagnitudeAngle: '<S916>/Complex to Magnitude-Angle' incorporates:
   *  RealImagToComplex: '<S916>/Real-Imag to Complex'
   *  UnitDelay: '<S919>/Unit Delay1'
   *  UnitDelay: '<S922>/Unit Delay1'
   */
  rtb_RateLimiter = rt_hypotd_snf(microrrede_v8_DW.UnitDelay1_DSTATE_k,
    microrrede_v8_DW.UnitDelay1_DSTATE_b);

  /* Saturate: '<S912>/Saturation' */
  if (rtb_RateLimiter <= 2.2204460492503131E-16) {
    rtb_RateLimiter = 2.2204460492503131E-16;
  }

  /* Math: '<S912>/Math Function' incorporates:
   *  Saturate: '<S912>/Saturation'
   *
   * About '<S912>/Math Function':
   *  Operator: reciprocal
   */
  microrrede_v8_B.MathFunction = 1.0 / rtb_RateLimiter;

  /* Update for DiscreteIntegrator: '<S919>/Integ4' */
  microrrede_v8_DW.Integ4_SYSTEM_ENABLE_g = 0U;
  microrrede_v8_DW.Integ4_DSTATE_e = 2.0833335E-6 * DataTypeConversion_tmp +
    microrrede_v8_B.Integ4_m;

  /* Update for S-Function (sfun_discreteVariableDelay): '<S921>/S-Function' */
  /* Level2 S-Function Block: '<S921>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[4];
    sfcnUpdate(rts,0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Update for UnitDelay: '<S920>/Unit Delay' */
  microrrede_v8_DW.UnitDelay_DSTATE_j = DataTypeConversion_tmp;

  /* Update for DiscreteIntegrator: '<S922>/Integ4' */
  microrrede_v8_DW.Integ4_SYSTEM_ENABLE_gv = 0U;
  microrrede_v8_DW.Integ4_DSTATE_aa = 2.0833335E-6 * rtb_Gain3_m +
    microrrede_v8_B.Integ4_je;

  /* Update for S-Function (sfun_discreteVariableDelay): '<S924>/S-Function' */
  /* Level2 S-Function Block: '<S924>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[5];
    sfcnUpdate(rts,0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Update for UnitDelay: '<S923>/Unit Delay' */
  microrrede_v8_DW.UnitDelay_DSTATE_ar = rtb_Gain3_m;

  /* End of Outputs for SubSystem: '<S911>/Automatic Gain Control' */

  /* Product: '<S911>/Product1' */
  rtb_Integrator_l = microrrede_v8_ConstB.Gain_n * rtb_RoundingFunction_d4;

  /* DiscreteIntegrator: '<S925>/Integ4' */
  if (microrrede_v8_DW.Integ4_SYSTEM_ENABLE_p != 0) {
    /* DiscreteIntegrator: '<S925>/Integ4' */
    microrrede_v8_B.Integ4_eu = microrrede_v8_DW.Integ4_DSTATE_fb;
  } else {
    /* DiscreteIntegrator: '<S925>/Integ4' */
    microrrede_v8_B.Integ4_eu = 2.0833335E-6 * rtb_Integrator_l +
      microrrede_v8_DW.Integ4_DSTATE_fb;
  }

  /* End of DiscreteIntegrator: '<S925>/Integ4' */

  /* Saturate: '<S925>/To avoid division  by zero' */
  if (microrrede_v8_DW.UnitDelay_DSTATE_e > 1.0E+6) {
    rtb_RoundingFunction_jv = 1.0E+6;
  } else if (microrrede_v8_DW.UnitDelay_DSTATE_e < 2.2204460492503131E-16) {
    rtb_RoundingFunction_jv = 2.2204460492503131E-16;
  } else {
    rtb_RoundingFunction_jv = microrrede_v8_DW.UnitDelay_DSTATE_e;
  }

  /* Fcn: '<S925>/Number of samples per cycle' incorporates:
   *  Saturate: '<S925>/To avoid division  by zero'
   */
  rtb_Gain3_m = 1.0 / rtb_RoundingFunction_jv / 4.166667e-6;

  /* Rounding: '<S925>/Rounding Function' */
  rtb_RoundingFunction_d4 = ceil(rtb_Gain3_m);

  /* Gain: '<S925>/Gain' */
  microrrede_v8_B.Delay_d = 4.166667E-6 * rtb_RoundingFunction_d4;

  /* S-Function (sfun_discreteVariableDelay): '<S927>/S-Function' */

  /* Level2 S-Function Block: '<S927>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[16];
    sfcnOutputs(rts,0);
  }

  /* Switch: '<S925>/Switch' incorporates:
   *  Constant: '<S925>/Constant'
   *  DigitalClock: '<S102>/Digital Clock'
   *  Gain: '<S926>/Gain1'
   *  Product: '<S925>/Product'
   *  Product: '<S926>/Product2'
   *  Product: '<S926>/Product4'
   *  Product: '<S926>/Product5'
   *  RelationalOperator: '<S925>/Relational Operator'
   *  Sum: '<S925>/Sum5'
   *  Sum: '<S925>/Sum7'
   *  Sum: '<S926>/Sum1'
   *  Sum: '<S926>/Sum4'
   *  UnitDelay: '<S911>/Unit Delay'
   *  UnitDelay: '<S925>/Unit Delay1'
   *  UnitDelay: '<S926>/Unit Delay'
   */
  if (rtb_Sum5_ij >= 0.016666666666666666) {
    /* Sum: '<S926>/Sum5' */
    rtb_RoundingFunction_d4 = rtb_Gain3_m - rtb_RoundingFunction_d4;
    microrrede_v8_DW.UnitDelay1_DSTATE_j = ((rtb_Integrator_l -
      microrrede_v8_DW.UnitDelay_DSTATE_a) * rtb_RoundingFunction_d4 * 0.5 +
      rtb_Integrator_l) * (rtb_RoundingFunction_d4 / rtb_Gain3_m) +
      (microrrede_v8_B.Integ4_eu - microrrede_v8_B.SFunction_gc) *
      microrrede_v8_DW.UnitDelay_DSTATE_e;
  }

  /* End of Switch: '<S925>/Switch' */

  /* Product: '<S911>/Divide' incorporates:
   *  UnitDelay: '<S925>/Unit Delay1'
   */
  rtb_RoundingFunction_d4 = microrrede_v8_DW.UnitDelay1_DSTATE_j *
    microrrede_v8_B.MathFunction;

  /* DiscreteTransferFcn: '<S913>/Discrete Derivative ' */
  rtb_Numberofsamplespercycle_mb = (rtb_RoundingFunction_d4 - -9.5833333E-5 *
    microrrede_v8_DW.DiscreteDerivative_states_h) / 0.0001;

  /* Sum: '<S913>/Sum6' incorporates:
   *  DiscreteIntegrator: '<S913>/Discrete-Time Integrator'
   *  DiscreteTransferFcn: '<S913>/Discrete Derivative '
   *  Gain: '<S913>/Kp4'
   */
  rtb_Add4 = (180.0 * rtb_RoundingFunction_d4 +
              microrrede_v8_DW.DiscreteTimeIntegrator_DSTAT_ht) +
    (rtb_Numberofsamplespercycle_mb -
     microrrede_v8_DW.DiscreteDerivative_states_h);

  /* Saturate: '<S913>/Saturation1' */
  if (rtb_Add4 <= 0.0) {
    rtb_Saturation1_k = 0.0;
  } else {
    rtb_Saturation1_k = rtb_Add4;
  }

  /* End of Saturate: '<S913>/Saturation1' */

  /* Gain: '<S911>/Gain10' */
  rtb_Add4 = 0.15915494309189535 * rtb_Saturation1_k;

  /* RateLimiter: '<S911>/Rate Limiter' */
  rtb_Saturation_d = rtb_Add4 - microrrede_v8_DW.PrevY_e;
  if (rtb_Saturation_d > 5.0000004E-5) {
    rtb_Add4 = microrrede_v8_DW.PrevY_e + 5.0000004E-5;
  } else if (rtb_Saturation_d < -5.0000004E-5) {
    rtb_Add4 = microrrede_v8_DW.PrevY_e - 5.0000004E-5;
  }

  microrrede_v8_DW.PrevY_e = rtb_Add4;

  /* End of RateLimiter: '<S911>/Rate Limiter' */

  /* UnitDelay: '<S928>/Delay_x1' */
  rtb_Gain3_m = microrrede_v8_DW.Delay_x1_DSTATE_k;

  /* UnitDelay: '<S928>/Delay_x2' */
  rtb_RoundingFunction_je = microrrede_v8_DW.Delay_x2_DSTATE_g;

  /* Gain: '<S929>/A21' incorporates:
   *  UnitDelay: '<S928>/Delay_x1'
   */
  rtb_A21_p = -0.10276083316900773 * microrrede_v8_DW.Delay_x1_DSTATE_k;

  /* Sum: '<S928>/A*x1(k) + B*u1(k) ' incorporates:
   *  Gain: '<S929>/A11'
   *  Gain: '<S929>/A12'
   *  Gain: '<S930>/B11'
   *  Sum: '<S929>/sum2'
   *  UnitDelay: '<S928>/Delay_x1'
   *  UnitDelay: '<S928>/Delay_x2'
   */
  microrrede_v8_DW.Delay_x1_DSTATE_k = (0.99999978591491367 *
    microrrede_v8_DW.Delay_x1_DSTATE_k + 4.1647394021622489E-6 *
    microrrede_v8_DW.Delay_x2_DSTATE_g) + 2.082369701081124E-6 * rtb_Add4;

  /* Sum: '<S928>/A*x2(k) + B*u2(k)' incorporates:
   *  Gain: '<S929>/A22'
   *  Gain: '<S930>/B21'
   *  Sum: '<S929>/sum3'
   *  UnitDelay: '<S928>/Delay_x2'
   */
  microrrede_v8_DW.Delay_x2_DSTATE_g = (0.999074753111899 *
    microrrede_v8_DW.Delay_x2_DSTATE_g + rtb_A21_p) + 0.99953737655594943 *
    rtb_Add4;

  /* Sum: '<S928>/C*X(k)+D*u(k)' incorporates:
   *  Gain: '<S928>/D*u(k)'
   *  Gain: '<S931>/C11'
   *  Gain: '<S931>/C12'
   *  Sum: '<S931>/sum2'
   *  UnitDelay: '<S911>/Unit Delay'
   */
  microrrede_v8_DW.UnitDelay_DSTATE_e = (0.10280838373778885 * rtb_Gain3_m +
    2.1408508622890496E-7 * rtb_RoundingFunction_je) + 1.0704254311445248E-7 *
    rtb_Add4;

  /* Sum: '<S707>/Add1' incorporates:
   *  Constant: '<S707>/Rs_array_'
   *  Product: '<S707>/Product2'
   */
  rtb_Add4 = microrrede_v8_B.StateSpace_o1[71] * 4.6101 +
    microrrede_v8_B.StateSpace_o1[47];

  /* Sum: '<S700>/Add1' incorporates:
   *  Constant: '<S700>/Rsh_array'
   *  Constant: '<S700>/Rsh_array_5%Sref'
   *  Constant: '<S700>/one'
   *  Math: '<S700>/Math Function'
   *  Product: '<S700>/Product'
   *  Product: '<S700>/Product1'
   *  Product: '<S700>/Product2'
   *  Product: '<S700>/Product5'
   *  Sum: '<S700>/Add'
   *  UnitDelay: '<S700>/Unit Delay'
   *
   * About '<S700>/Math Function':
   *  Operator: exp
   */
  microrrede_v8_DW.UnitDelay_DSTATE_d = ((exp(1.0 / microrrede_v8_ConstB.VT_d *
    rtb_Add4) - 1.0) * microrrede_v8_ConstB.Product4_a + rtb_Add4 / 2322.603 *
    rtb_Integrator_h) - rtb_Add4 / 46452.06;

  /* Switch: '<S123>/Switch3' */
  microrrede_v8_B.Switch3_e = 0.0;

  /* DiscreteIntegrator: '<S670>/Integ4' */
  if (microrrede_v8_DW.Integ4_SYSTEM_ENABLE_e != 0) {
    /* DiscreteIntegrator: '<S670>/Integ4' */
    microrrede_v8_B.Integ4_b5 = microrrede_v8_DW.Integ4_DSTATE_p;
  } else {
    /* DiscreteIntegrator: '<S670>/Integ4' */
    microrrede_v8_B.Integ4_b5 = 2.0833335E-6 * microrrede_v8_B.StateSpace_o1[43]
      + microrrede_v8_DW.Integ4_DSTATE_p;
  }

  /* End of DiscreteIntegrator: '<S670>/Integ4' */

  /* S-Function (sfun_discreteVariableDelay): '<S671>/S-Function' incorporates:
   *  Constant: '<S670>/K1'
   */

  /* Level2 S-Function Block: '<S671>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[17];
    sfcnOutputs(rts,0);
  }

  /* Switch: '<S670>/Switch' incorporates:
   *  Constant: '<S670>/K1'
   *  Constant: '<S670>/K2'
   *  DigitalClock: '<S102>/Digital Clock'
   *  Gain: '<S670>/Gain'
   *  Gain: '<S670>/Gain1'
   *  Product: '<S670>/Product'
   *  RelationalOperator: '<S670>/Relational Operator'
   *  Sum: '<S670>/Sum1'
   *  Sum: '<S670>/Sum5'
   *  Sum: '<S670>/Sum7'
   *  UnitDelay: '<S670>/Unit Delay'
   *  UnitDelay: '<S670>/Unit Delay1'
   */
  if (rtb_Sum5_ij >= 0.016666668) {
    microrrede_v8_DW.UnitDelay1_DSTATE_g = (microrrede_v8_B.Integ4_b5 -
      microrrede_v8_B.SFunction_mo) * 60.0 + (-7.9987200059934818E-8 *
      microrrede_v8_B.StateSpace_o1[43] - 1.2799998994857576E-11 *
      microrrede_v8_DW.UnitDelay_DSTATE_n);
  }

  /* End of Switch: '<S670>/Switch' */

  /* Sum: '<S439>/Sum' incorporates:
   *  Constant: '<S20>/Constant7'
   *  DiscreteIntegrator: '<S430>/Integrator'
   *  Sum: '<S20>/Sum1'
   *  UnitDelay: '<S670>/Unit Delay1'
   */
  rtb_RoundingFunction_m = (400.0 - microrrede_v8_DW.UnitDelay1_DSTATE_g) +
    microrrede_v8_DW.Integrator_DSTATE_j;

  /* Saturate: '<S437>/Saturation' */
  if (rtb_RoundingFunction_m > 27.0) {
    rtb_RoundingFunction_m = 27.0;
  } else if (rtb_RoundingFunction_m < -27.0) {
    rtb_RoundingFunction_m = -27.0;
  }

  /* Sum: '<S20>/Sum2' incorporates:
   *  Saturate: '<S437>/Saturation'
   */
  rtb_Gain3_m = microrrede_v8_B.StateSpace_o1[63] - rtb_RoundingFunction_m;

  /* Sum: '<S487>/Sum' incorporates:
   *  DiscreteIntegrator: '<S478>/Integrator'
   *  Gain: '<S483>/Proportional Gain'
   */
  rtb_Integrator_h = 0.02 * rtb_Gain3_m + microrrede_v8_DW.Integrator_DSTATE_kn;

  /* Saturate: '<S20>/Saturation' */
  if (rtb_Integrator_h > 1.0) {
    rtb_Integrator_h = 1.0;
  } else if (rtb_Integrator_h < -0.95) {
    rtb_Integrator_h = -0.95;
  }

  /* End of Saturate: '<S20>/Saturation' */

  /* DataTypeConversion: '<S383>/Data Type Conversion' incorporates:
   *  Constant: '<S505>/Constant'
   *  Constant: '<S507>/Constant2'
   *  Fcn: '<S383>/Fcn'
   *  Fcn: '<S507>/Fcn'
   *  Gain: '<S507>/1\ib1'
   *  Logic: '<S383>/Logical Operator'
   *  Math: '<S507>/Math Function'
   *  RelationalOperator: '<S383>/Relational Operator'
   *  RelationalOperator: '<S505>/Compare'
   */
  microrrede_v8_B.DataTypeConversion_h = ((rtb_Integrator_h != 0.0) &&
    (rtb_Integrator_h >= ((5000.0 * rt_remd_snf(rtb_Sum5_ij, 0.0002) * 2.0 - 1.0)
    + 1.0) * 0.5));

  /* DataTypeConversion: '<S397>/Data Type Conversion' incorporates:
   *  Logic: '<S20>/Logical Operator1'
   */
  microrrede_v8_B.DataTypeConversion_hq = !(microrrede_v8_B.DataTypeConversion_h
    != 0.0);

  /* Gain: '<S475>/Integral Gain' */
  rtb_Integrator_h = 11.0 * rtb_Gain3_m;

  /* Lookup_n-D: '<S504>/1-D Lookup Table' */
  rtb_Add4 = look1_pbinlxpw(rtb_Integrator_bx_tmp, microrrede_v8_ConstP.pooled58,
    microrrede_v8_ConstP.pooled57, &microrrede_v8_DW.m_bpIndex_d, 2U);

  /* Sum: '<S495>/Add4' incorporates:
   *  Constant: '<S504>/Constant2'
   *  Product: '<S495>/MUL1'
   *  Sum: '<S504>/Add3'
   */
  rtb_Add4 = ((rtb_Add4 - 1.0) * microrrede_v8_ConstB.Gain1_j - 1.0) +
    microrrede_v8_ConstB.Gain1_j;

  /* Sin: '<S500>/Sine Wave' */
  if (microrrede_v8_DW.systemEnable_m != 0) {
    rtb_Gain3_m = 376.99111843077515 * microrrede_v8_M->Timing.t[0];
    microrrede_v8_DW.lastSin_h = sin(rtb_Gain3_m);
    microrrede_v8_DW.lastCos_m = cos(rtb_Gain3_m);
    microrrede_v8_DW.systemEnable_m = 0;
  }

  rtb_Gain3_m = ((microrrede_v8_DW.lastSin_h * 0.99999876629950613 +
                  microrrede_v8_DW.lastCos_m * -0.0015707958064944299) *
                 0.99999876629950613 + (microrrede_v8_DW.lastCos_m *
    0.99999876629950613 - microrrede_v8_DW.lastSin_h * -0.0015707958064944299) *
                 0.0015707958064944299) * 0.78;

  /* End of Sin: '<S500>/Sine Wave' */

  /* RelationalOperator: '<S499>/Relational Operator1' */
  rtb_RelationalOperator1 = (rtb_Gain3_m >= rtb_Add4);

  /* RelationalOperator: '<S499>/Relational Operator3' incorporates:
   *  Gain: '<S499>/Gain'
   */
  rtb_RelationalOperator3 = (-rtb_Gain3_m >= rtb_Add4);

  /* DataTypeConversion: '<S382>/Data Type Conversion' incorporates:
   *  Logic: '<S382>/Logical Operator4'
   */
  microrrede_v8_B.DataTypeConversion_ad[0] = rtb_RelationalOperator1;
  microrrede_v8_B.DataTypeConversion_ad[1] = !rtb_RelationalOperator1;
  microrrede_v8_B.DataTypeConversion_ad[2] = rtb_RelationalOperator3;
  microrrede_v8_B.DataTypeConversion_ad[3] = !rtb_RelationalOperator3;

  /* Lookup_n-D: '<S527>/1-D Lookup Table' */
  rtb_Add4 = look1_pbinlxpw(rtb_Integrator_bx_tmp, microrrede_v8_ConstP.pooled58,
    microrrede_v8_ConstP.pooled57, &microrrede_v8_DW.m_bpIndex_b, 2U);

  /* Sum: '<S518>/Add4' incorporates:
   *  Constant: '<S527>/Constant2'
   *  Product: '<S518>/MUL1'
   *  Sum: '<S527>/Add3'
   */
  rtb_Add4 = ((rtb_Add4 - 1.0) * microrrede_v8_ConstB.Gain1_c - 1.0) +
    microrrede_v8_ConstB.Gain1_c;

  /* DiscreteIntegrator: '<S543>/Integ4' */
  if (microrrede_v8_DW.Integ4_SYSTEM_ENABLE_pi != 0) {
    /* DiscreteIntegrator: '<S543>/Integ4' */
    microrrede_v8_B.Integ4_ps = microrrede_v8_DW.Integ4_DSTATE_a;
  } else {
    /* DiscreteIntegrator: '<S543>/Integ4' */
    microrrede_v8_B.Integ4_ps = 2.0833335E-6 * microrrede_v8_B.StateSpace_o1[43]
      + microrrede_v8_DW.Integ4_DSTATE_a;
  }

  /* End of DiscreteIntegrator: '<S543>/Integ4' */

  /* S-Function (sfun_discreteVariableDelay): '<S544>/S-Function' incorporates:
   *  Constant: '<S543>/K1'
   */

  /* Level2 S-Function Block: '<S544>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[18];
    sfcnOutputs(rts,0);
  }

  /* Switch: '<S543>/Switch' incorporates:
   *  Constant: '<S543>/K1'
   *  Constant: '<S543>/K2'
   *  DigitalClock: '<S102>/Digital Clock'
   *  Gain: '<S543>/Gain'
   *  Gain: '<S543>/Gain1'
   *  Product: '<S543>/Product'
   *  RelationalOperator: '<S543>/Relational Operator'
   *  Sum: '<S543>/Sum1'
   *  Sum: '<S543>/Sum5'
   *  Sum: '<S543>/Sum7'
   *  UnitDelay: '<S543>/Unit Delay'
   *  UnitDelay: '<S543>/Unit Delay1'
   */
  if (rtb_Sum5_ij >= 0.016666668) {
    microrrede_v8_DW.UnitDelay1_DSTATE_a = (microrrede_v8_B.Integ4_ps -
      microrrede_v8_B.SFunction_k) * 60.0 + (-7.9987200059934818E-8 *
      microrrede_v8_B.StateSpace_o1[43] - 1.2799998994857576E-11 *
      microrrede_v8_DW.UnitDelay_DSTATE_f);
  }

  /* End of Switch: '<S543>/Switch' */

  /* Saturate: '<S533>/Saturation' */
  if (microrrede_v8_DW.UnitDelay_DSTATE_b > 70.0) {
    rtb_RoundingFunction_jv = 70.0;
  } else if (microrrede_v8_DW.UnitDelay_DSTATE_b < 40.0) {
    rtb_RoundingFunction_jv = 40.0;
  } else {
    rtb_RoundingFunction_jv = microrrede_v8_DW.UnitDelay_DSTATE_b;
  }

  /* Gain: '<S533>/Gain' incorporates:
   *  Math: '<S533>/Math Function'
   *  Saturate: '<S533>/Saturation'
   *
   * About '<S533>/Math Function':
   *  Operator: reciprocal
   */
  microrrede_v8_B.Gain_a = 1.0 / rtb_RoundingFunction_jv * 0.25;

  /* S-Function (sfun_discreteVariableDelay): '<S615>/S-Function' */

  /* Level2 S-Function Block: '<S615>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[19];
    sfcnOutputs(rts,0);
  }

  /* RelationalOperator: '<S593>/Relational Operator' incorporates:
   *  Constant: '<S593>/Constant2'
   */
  rtb_RelationalOperator_nv = (microrrede_v8_DW.DiscreteTimeIntegrator_DSTATE_l >
    6.2831853071795862);

  /* InitialCondition: '<S593>/Initial' */
  if (microrrede_v8_DW.Initial_FirstOutputTime_g) {
    microrrede_v8_DW.Initial_FirstOutputTime_g = false;

    /* InitialCondition: '<S593>/Initial' */
    rtb_Gain3_m = 0.0;
  } else {
    /* InitialCondition: '<S593>/Initial' incorporates:
     *  Constant: '<S593>/Constant2'
     *  Sum: '<S593>/Subtract'
     */
    rtb_Gain3_m = microrrede_v8_DW.DiscreteTimeIntegrator_DSTATE_l -
      6.2831853071795862;
  }

  /* End of InitialCondition: '<S593>/Initial' */

  /* DiscreteIntegrator: '<S593>/Discrete-Time Integrator' */
  if (rtb_RelationalOperator_nv &&
      (microrrede_v8_DW.DiscreteTimeIntegrator_PrevRe_j <= 0)) {
    microrrede_v8_DW.DiscreteTimeIntegrator_DSTATE_l = rtb_Gain3_m;
  }

  /* Outputs for Enabled SubSystem: '<S614>/Subsystem1' */
  microrrede_v8_Subsystem1(microrrede_v8_ConstB.Compare_b,
    microrrede_v8_ConstB.Gain2_f, microrrede_v8_B.SFunction_gq,
    microrrede_v8_DW.DiscreteTimeIntegrator_DSTATE_l, &microrrede_v8_B.Fcn_p,
    &microrrede_v8_B.Fcn1_n);

  /* End of Outputs for SubSystem: '<S614>/Subsystem1' */

  /* Outputs for Enabled SubSystem: '<S614>/Subsystem - pi//2 delay' */
  microrrede_v8_Subsystempi2delay(microrrede_v8_ConstB.Compare_b0,
    microrrede_v8_ConstB.Gain2_f, microrrede_v8_B.SFunction_gq,
    microrrede_v8_DW.DiscreteTimeIntegrator_DSTATE_l, &microrrede_v8_B.Fcn_f,
    &microrrede_v8_B.Fcn1_f);

  /* End of Outputs for SubSystem: '<S614>/Subsystem - pi//2 delay' */

  /* Switch: '<S614>/Switch' */
  if (microrrede_v8_ConstB.Compare_b != 0) {
    rtb_RoundingFunction_je = microrrede_v8_B.Fcn_p;
    rtb_A21_p = microrrede_v8_B.Fcn1_n;
  } else {
    rtb_RoundingFunction_je = microrrede_v8_B.Fcn_f;
    rtb_A21_p = microrrede_v8_B.Fcn1_f;
  }

  /* End of Switch: '<S614>/Switch' */

  /* Gain: '<S517>/Gain3' incorporates:
   *  Constant: '<S517>/Constant'
   *  Sum: '<S517>/Add'
   *  UnitDelay: '<S543>/Unit Delay1'
   */
  rtb_Gain3_m = (microrrede_v8_DW.UnitDelay1_DSTATE_a - 400.0) * 0.0025;

  /* Sum: '<S585>/Sum' incorporates:
   *  DiscreteIntegrator: '<S576>/Integrator'
   *  Gain: '<S581>/Proportional Gain'
   */
  rtb_Saturation_d = 12.0 * rtb_Gain3_m + microrrede_v8_DW.Integrator_DSTATE_g;

  /* Saturate: '<S583>/Saturation' */
  if (rtb_Saturation_d > 1.5) {
    rtb_Saturation_d = 1.5;
  } else if (rtb_Saturation_d < -1.5) {
    rtb_Saturation_d = -1.5;
  }

  /* End of Saturate: '<S583>/Saturation' */

  /* Sum: '<S534>/Add' incorporates:
   *  Constant: '<S517>/Constant1'
   */
  rtb_RoundingFunction_je = rtb_Saturation_d - rtb_RoundingFunction_je;
  rtb_A21_p = 0.0 - rtb_A21_p;

  /* Sum: '<S661>/Sum' incorporates:
   *  DiscreteIntegrator: '<S652>/Integrator'
   *  Gain: '<S657>/Proportional Gain'
   */
  rtb_RoundingFunction_m = 0.15 * rtb_RoundingFunction_je +
    microrrede_v8_DW.Integrator_DSTATE_m[0];
  rtb_Numberofsamplespercycle_ej = 0.15 * rtb_A21_p +
    microrrede_v8_DW.Integrator_DSTATE_m[1];

  /* Outputs for Enabled SubSystem: '<S593>/Automatic Gain Control' incorporates:
   *  EnablePort: '<S594>/Enable'
   */
  /* Product: '<S528>/Product1' incorporates:
   *  DiscreteIntegrator: '<S593>/Discrete-Time Integrator'
   *  Gain: '<S528>/Gain1'
   *  Product: '<S598>/Product1'
   *  Trigonometry: '<S528>/Trigonometric Function'
   */
  rtb_Integrator_bx_tmp = 2.0 * sin
    (microrrede_v8_DW.DiscreteTimeIntegrator_DSTATE_l) *
    microrrede_v8_ConstB.Gain_m;

  /* End of Outputs for SubSystem: '<S593>/Automatic Gain Control' */

  /* DiscreteIntegrator: '<S537>/Integ4' */
  if (microrrede_v8_DW.Integ4_SYSTEM_ENABLE_eq != 0) {
    /* DiscreteIntegrator: '<S537>/Integ4' */
    microrrede_v8_B.Integ4_c = microrrede_v8_DW.Integ4_DSTATE_hc;
  } else {
    /* DiscreteIntegrator: '<S537>/Integ4' incorporates:
     *  Product: '<S528>/Product1'
     */
    microrrede_v8_B.Integ4_c = 2.0833335E-6 * rtb_Integrator_bx_tmp +
      microrrede_v8_DW.Integ4_DSTATE_hc;
  }

  /* End of DiscreteIntegrator: '<S537>/Integ4' */

  /* Saturate: '<S537>/To avoid division  by zero' */
  if (microrrede_v8_DW.UnitDelay_DSTATE_b > 1.0E+6) {
    rtb_RoundingFunction_jv = 1.0E+6;
  } else if (microrrede_v8_DW.UnitDelay_DSTATE_b < 2.2204460492503131E-16) {
    rtb_RoundingFunction_jv = 2.2204460492503131E-16;
  } else {
    rtb_RoundingFunction_jv = microrrede_v8_DW.UnitDelay_DSTATE_b;
  }

  /* Fcn: '<S537>/Number of samples per cycle' incorporates:
   *  Saturate: '<S537>/To avoid division  by zero'
   */
  rtb_Numberofsamplespercycle_lo = 1.0 / rtb_RoundingFunction_jv / 4.166667e-6;

  /* Rounding: '<S537>/Rounding Function' */
  rtb_RateLimiter = ceil(rtb_Numberofsamplespercycle_lo);

  /* Gain: '<S537>/Gain' */
  microrrede_v8_B.Delay_go = 4.166667E-6 * rtb_RateLimiter;

  /* S-Function (sfun_discreteVariableDelay): '<S539>/S-Function' */

  /* Level2 S-Function Block: '<S539>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[20];
    sfcnOutputs(rts,0);
  }

  /* Switch: '<S537>/Switch' incorporates:
   *  Constant: '<S537>/Constant'
   *  DigitalClock: '<S102>/Digital Clock'
   *  Gain: '<S538>/Gain1'
   *  Product: '<S528>/Product1'
   *  Product: '<S537>/Product'
   *  Product: '<S538>/Product2'
   *  Product: '<S538>/Product4'
   *  Product: '<S538>/Product5'
   *  RelationalOperator: '<S537>/Relational Operator'
   *  Sum: '<S537>/Sum5'
   *  Sum: '<S537>/Sum7'
   *  Sum: '<S538>/Sum1'
   *  Sum: '<S538>/Sum4'
   *  UnitDelay: '<S537>/Unit Delay1'
   *  UnitDelay: '<S538>/Unit Delay'
   *  UnitDelay: '<S593>/Unit Delay'
   */
  if (rtb_Sum5_ij >= 0.016666666666666666) {
    /* Sum: '<S538>/Sum5' */
    rtb_RateLimiter = rtb_Numberofsamplespercycle_lo - rtb_RateLimiter;
    microrrede_v8_DW.UnitDelay1_DSTATE_f = ((rtb_Integrator_bx_tmp -
      microrrede_v8_DW.UnitDelay_DSTATE_al) * rtb_RateLimiter * 0.5 +
      rtb_Integrator_bx_tmp) * (rtb_RateLimiter / rtb_Numberofsamplespercycle_lo)
      + (microrrede_v8_B.Integ4_c - microrrede_v8_B.SFunction_o4) *
      microrrede_v8_DW.UnitDelay_DSTATE_b;
  }

  /* End of Switch: '<S537>/Switch' */

  /* Trigonometry: '<S528>/Trigonometric Function' incorporates:
   *  DiscreteIntegrator: '<S593>/Discrete-Time Integrator'
   *  Trigonometry: '<S593>/Trigonometric Function2'
   */
  rtb_A21_c = cos(microrrede_v8_DW.DiscreteTimeIntegrator_DSTATE_l);

  /* Product: '<S528>/Product2' incorporates:
   *  Gain: '<S528>/Gain3'
   *  Trigonometry: '<S528>/Trigonometric Function'
   */
  rtb_Numberofsamplespercycle_lo = 2.0 * rtb_A21_c * microrrede_v8_ConstB.Gain_m;

  /* DiscreteIntegrator: '<S540>/Integ4' */
  if (microrrede_v8_DW.Integ4_SYSTEM_ENABLE_b != 0) {
    /* DiscreteIntegrator: '<S540>/Integ4' */
    microrrede_v8_B.Integ4_g = microrrede_v8_DW.Integ4_DSTATE_lt;
  } else {
    /* DiscreteIntegrator: '<S540>/Integ4' */
    microrrede_v8_B.Integ4_g = 2.0833335E-6 * rtb_Numberofsamplespercycle_lo +
      microrrede_v8_DW.Integ4_DSTATE_lt;
  }

  /* End of DiscreteIntegrator: '<S540>/Integ4' */

  /* Saturate: '<S540>/To avoid division  by zero' */
  if (microrrede_v8_DW.UnitDelay_DSTATE_b > 1.0E+6) {
    rtb_RoundingFunction_jv = 1.0E+6;
  } else if (microrrede_v8_DW.UnitDelay_DSTATE_b < 2.2204460492503131E-16) {
    rtb_RoundingFunction_jv = 2.2204460492503131E-16;
  } else {
    rtb_RoundingFunction_jv = microrrede_v8_DW.UnitDelay_DSTATE_b;
  }

  /* Fcn: '<S540>/Number of samples per cycle' incorporates:
   *  Saturate: '<S540>/To avoid division  by zero'
   */
  rtb_RateLimiter = 1.0 / rtb_RoundingFunction_jv / 4.166667e-6;

  /* Rounding: '<S540>/Rounding Function' */
  rtb_RoundingFunction_jv = ceil(rtb_RateLimiter);

  /* Gain: '<S540>/Gain' */
  microrrede_v8_B.Delay_n4 = 4.166667E-6 * rtb_RoundingFunction_jv;

  /* S-Function (sfun_discreteVariableDelay): '<S542>/S-Function' */

  /* Level2 S-Function Block: '<S542>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[21];
    sfcnOutputs(rts,0);
  }

  /* Switch: '<S540>/Switch' incorporates:
   *  Constant: '<S540>/Constant'
   *  DigitalClock: '<S102>/Digital Clock'
   *  Gain: '<S541>/Gain1'
   *  Product: '<S540>/Product'
   *  Product: '<S541>/Product2'
   *  Product: '<S541>/Product4'
   *  Product: '<S541>/Product5'
   *  RelationalOperator: '<S540>/Relational Operator'
   *  Sum: '<S540>/Sum5'
   *  Sum: '<S540>/Sum7'
   *  Sum: '<S541>/Sum1'
   *  Sum: '<S541>/Sum4'
   *  UnitDelay: '<S540>/Unit Delay1'
   *  UnitDelay: '<S541>/Unit Delay'
   *  UnitDelay: '<S593>/Unit Delay'
   */
  if (rtb_Sum5_ij >= 0.016666666666666666) {
    /* Sum: '<S541>/Sum5' */
    rtb_RoundingFunction_jv = rtb_RateLimiter - rtb_RoundingFunction_jv;
    microrrede_v8_DW.UnitDelay1_DSTATE_cr = ((rtb_Numberofsamplespercycle_lo -
      microrrede_v8_DW.UnitDelay_DSTATE_o) * rtb_RoundingFunction_jv * 0.5 +
      rtb_Numberofsamplespercycle_lo) * (rtb_RoundingFunction_jv /
      rtb_RateLimiter) + (microrrede_v8_B.Integ4_g - microrrede_v8_B.SFunction_p)
      * microrrede_v8_DW.UnitDelay_DSTATE_b;
  }

  /* End of Switch: '<S540>/Switch' */

  /* Gain: '<S517>/Gain1' incorporates:
   *  ComplexToMagnitudeAngle: '<S528>/Complex to Magnitude-Angle'
   *  Gain: '<S528>/Rad->Deg.'
   *  RealImagToComplex: '<S528>/Real-Imag to Complex'
   *  UnitDelay: '<S537>/Unit Delay1'
   *  UnitDelay: '<S540>/Unit Delay1'
   */
  rtb_RateLimiter = 57.295779513082323 * rt_atan2d_snf
    (microrrede_v8_DW.UnitDelay1_DSTATE_cr, microrrede_v8_DW.UnitDelay1_DSTATE_f)
    * 0.017453292519943295;

  /* Product: '<S532>/Divide1' incorporates:
   *  Constant: '<S532>/Constant'
   *  Product: '<S532>/Divide'
   *  UnitDelay: '<S543>/Unit Delay1'
   */
  rtb_RoundingFunction_jv = 1.0 / (microrrede_v8_DW.UnitDelay1_DSTATE_a /
    311.12698372208092);

  /* Saturate: '<S659>/Saturation' */
  if (rtb_RoundingFunction_m > 1.5) {
    rtb_RoundingFunction_m = 1.5;
  } else if (rtb_RoundingFunction_m < -1.5) {
    rtb_RoundingFunction_m = -1.5;
  }

  /* ComplexToMagnitudeAngle: '<S528>/Complex to Magnitude-Angle' incorporates:
   *  RealImagToComplex: '<S528>/Real-Imag to Complex'
   *  UnitDelay: '<S537>/Unit Delay1'
   *  UnitDelay: '<S540>/Unit Delay1'
   */
  rtb_Divide1_idx_0_tmp = rt_hypotd_snf(microrrede_v8_DW.UnitDelay1_DSTATE_f,
    microrrede_v8_DW.UnitDelay1_DSTATE_cr);

  /* Sum: '<S534>/Add1' incorporates:
   *  ComplexToMagnitudeAngle: '<S528>/Complex to Magnitude-Angle'
   *  Gain: '<S534>/Gain'
   *  MagnitudeAngleToComplex: '<S517>/Magnitude-Angle to Complex'
   *  Saturate: '<S659>/Saturation'
   *  Sum: '<S534>/Add2'
   */
  rtb_RoundingFunction_m += (rtb_Divide1_idx_0_tmp * cos(rtb_RateLimiter) +
    0.002 * rtb_Saturation_d) - microrrede_v8_ConstB.Gain1_m;

  /* Saturate: '<S659>/Saturation' */
  if (rtb_Numberofsamplespercycle_ej > 1.5) {
    rtb_Numberofsamplespercycle_ej = 1.5;
  } else if (rtb_Numberofsamplespercycle_ej < -1.5) {
    rtb_Numberofsamplespercycle_ej = -1.5;
  }

  /* Sum: '<S534>/Add1' incorporates:
   *  Gain: '<S534>/Gain2'
   *  MagnitudeAngleToComplex: '<S517>/Magnitude-Angle to Complex'
   *  Saturate: '<S659>/Saturation'
   *  Sum: '<S534>/Add3'
   */
  rtb_Numberofsamplespercycle_ej += (rtb_Divide1_idx_0_tmp * sin(rtb_RateLimiter)
    + 0.2 * rtb_Saturation_d) + microrrede_v8_ConstB.Gain3_o;

  /* Saturate: '<S534>/Saturation' */
  if (rtb_RoundingFunction_m > 1.5) {
    rtb_RoundingFunction_m = 1.5;
  } else if (rtb_RoundingFunction_m < -1.5) {
    rtb_RoundingFunction_m = -1.5;
  }

  /* Product: '<S532>/Divide1' incorporates:
   *  Saturate: '<S534>/Saturation'
   */
  rtb_RoundingFunction_m *= rtb_RoundingFunction_jv;

  /* Saturate: '<S534>/Saturation' */
  if (rtb_Numberofsamplespercycle_ej > 1.5) {
    rtb_Numberofsamplespercycle_ej = 1.5;
  } else if (rtb_Numberofsamplespercycle_ej < -1.5) {
    rtb_Numberofsamplespercycle_ej = -1.5;
  }

  /* Product: '<S532>/Divide1' incorporates:
   *  Saturate: '<S534>/Saturation'
   */
  rtb_Numberofsamplespercycle_ej *= rtb_RoundingFunction_jv;

  /* Product: '<S532>/Divide2' incorporates:
   *  ComplexToMagnitudeAngle: '<S532>/Complex to Magnitude-Angle'
   *  Constant: '<S532>/Constant1'
   *  DiscreteIntegrator: '<S593>/Discrete-Time Integrator'
   *  RealImagToComplex: '<S532>/Real-Imag to Complex'
   *  Sum: '<S532>/Add'
   *  Sum: '<S532>/Add1'
   *  Trigonometry: '<S532>/Sin'
   */
  rtb_RateLimiter = sin((microrrede_v8_DW.DiscreteTimeIntegrator_DSTATE_l +
    0.0037699111843077517) + rt_atan2d_snf(rtb_Numberofsamplespercycle_ej,
    rtb_RoundingFunction_m)) * rt_hypotd_snf(rtb_RoundingFunction_m,
    rtb_Numberofsamplespercycle_ej);

  /* RelationalOperator: '<S522>/Relational Operator1' */
  rtb_RelationalOperator1 = (rtb_RateLimiter >= rtb_Add4);

  /* RelationalOperator: '<S522>/Relational Operator3' incorporates:
   *  Gain: '<S522>/Gain'
   */
  rtb_RelationalOperator3 = (-rtb_RateLimiter >= rtb_Add4);

  /* DataTypeConversion: '<S516>/Data Type Conversion' incorporates:
   *  Logic: '<S516>/Logical Operator4'
   */
  microrrede_v8_B.DataTypeConversion_g[0] = rtb_RelationalOperator1;
  microrrede_v8_B.DataTypeConversion_g[1] = !rtb_RelationalOperator1;
  microrrede_v8_B.DataTypeConversion_g[2] = rtb_RelationalOperator3;
  microrrede_v8_B.DataTypeConversion_g[3] = !rtb_RelationalOperator3;

  /* Outputs for Enabled SubSystem: '<S593>/Automatic Gain Control' incorporates:
   *  EnablePort: '<S594>/Enable'
   */
  if (!microrrede_v8_DW.AutomaticGainControl_MODE_o) {
    /* Enable for DiscreteIntegrator: '<S601>/Integ4' */
    microrrede_v8_DW.Integ4_SYSTEM_ENABLE_k = 1U;

    /* Enable for DiscreteIntegrator: '<S604>/Integ4' */
    microrrede_v8_DW.Integ4_SYSTEM_ENABLE_bq = 1U;
    microrrede_v8_DW.AutomaticGainControl_MODE_o = true;
  }

  /* DiscreteIntegrator: '<S601>/Integ4' */
  if (microrrede_v8_DW.Integ4_SYSTEM_ENABLE_k != 0) {
    /* DiscreteIntegrator: '<S601>/Integ4' */
    microrrede_v8_B.Integ4_mt = microrrede_v8_DW.Integ4_DSTATE_hi;
  } else {
    /* DiscreteIntegrator: '<S601>/Integ4' */
    microrrede_v8_B.Integ4_mt = 2.0833335E-6 * rtb_Integrator_bx_tmp +
      microrrede_v8_DW.Integ4_DSTATE_hi;
  }

  /* End of DiscreteIntegrator: '<S601>/Integ4' */

  /* Saturate: '<S601>/To avoid division  by zero' */
  if (microrrede_v8_DW.UnitDelay_DSTATE_b > 1.0E+6) {
    rtb_RoundingFunction_jv = 1.0E+6;
  } else if (microrrede_v8_DW.UnitDelay_DSTATE_b < 2.2204460492503131E-16) {
    rtb_RoundingFunction_jv = 2.2204460492503131E-16;
  } else {
    rtb_RoundingFunction_jv = microrrede_v8_DW.UnitDelay_DSTATE_b;
  }

  /* Fcn: '<S601>/Number of samples per cycle' incorporates:
   *  Saturate: '<S601>/To avoid division  by zero'
   */
  rtb_Numberofsamplespercycle_ej = 1.0 / rtb_RoundingFunction_jv / 4.166667e-6;

  /* Rounding: '<S601>/Rounding Function' */
  rtb_RateLimiter = ceil(rtb_Numberofsamplespercycle_ej);

  /* Gain: '<S601>/Gain' */
  microrrede_v8_B.Delay_le = 4.166667E-6 * rtb_RateLimiter;

  /* S-Function (sfun_discreteVariableDelay): '<S603>/S-Function' */

  /* Level2 S-Function Block: '<S603>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[2];
    sfcnOutputs(rts,0);
  }

  /* Switch: '<S601>/Switch' incorporates:
   *  Constant: '<S601>/Constant'
   *  DigitalClock: '<S102>/Digital Clock'
   *  Gain: '<S602>/Gain1'
   *  Product: '<S601>/Product'
   *  Product: '<S602>/Product2'
   *  Product: '<S602>/Product4'
   *  Product: '<S602>/Product5'
   *  RelationalOperator: '<S601>/Relational Operator'
   *  Sum: '<S601>/Sum5'
   *  Sum: '<S601>/Sum7'
   *  Sum: '<S602>/Sum1'
   *  Sum: '<S602>/Sum4'
   *  UnitDelay: '<S593>/Unit Delay'
   *  UnitDelay: '<S601>/Unit Delay1'
   *  UnitDelay: '<S602>/Unit Delay'
   */
  if (rtb_Sum5_ij >= 0.016666666666666666) {
    /* Sum: '<S602>/Sum5' */
    rtb_RateLimiter = rtb_Numberofsamplespercycle_ej - rtb_RateLimiter;
    microrrede_v8_DW.UnitDelay1_DSTATE_l = ((rtb_Integrator_bx_tmp -
      microrrede_v8_DW.UnitDelay_DSTATE_fx) * rtb_RateLimiter * 0.5 +
      rtb_Integrator_bx_tmp) * (rtb_RateLimiter / rtb_Numberofsamplespercycle_ej)
      + (microrrede_v8_B.Integ4_mt - microrrede_v8_B.SFunction_h) *
      microrrede_v8_DW.UnitDelay_DSTATE_b;
  }

  /* End of Switch: '<S601>/Switch' */

  /* Product: '<S598>/Product2' incorporates:
   *  DiscreteIntegrator: '<S593>/Discrete-Time Integrator'
   *  Gain: '<S598>/Gain3'
   *  Trigonometry: '<S598>/Trigonometric Function'
   */
  rtb_Numberofsamplespercycle_ej = 2.0 * cos
    (microrrede_v8_DW.DiscreteTimeIntegrator_DSTATE_l) *
    microrrede_v8_ConstB.Gain_m;

  /* DiscreteIntegrator: '<S604>/Integ4' */
  if (microrrede_v8_DW.Integ4_SYSTEM_ENABLE_bq != 0) {
    /* DiscreteIntegrator: '<S604>/Integ4' */
    microrrede_v8_B.Integ4_i = microrrede_v8_DW.Integ4_DSTATE_c;
  } else {
    /* DiscreteIntegrator: '<S604>/Integ4' */
    microrrede_v8_B.Integ4_i = 2.0833335E-6 * rtb_Numberofsamplespercycle_ej +
      microrrede_v8_DW.Integ4_DSTATE_c;
  }

  /* End of DiscreteIntegrator: '<S604>/Integ4' */

  /* Saturate: '<S604>/To avoid division  by zero' */
  if (microrrede_v8_DW.UnitDelay_DSTATE_b > 1.0E+6) {
    rtb_RoundingFunction_jv = 1.0E+6;
  } else if (microrrede_v8_DW.UnitDelay_DSTATE_b < 2.2204460492503131E-16) {
    rtb_RoundingFunction_jv = 2.2204460492503131E-16;
  } else {
    rtb_RoundingFunction_jv = microrrede_v8_DW.UnitDelay_DSTATE_b;
  }

  /* Fcn: '<S604>/Number of samples per cycle' incorporates:
   *  Saturate: '<S604>/To avoid division  by zero'
   */
  rtb_RateLimiter = 1.0 / rtb_RoundingFunction_jv / 4.166667e-6;

  /* Rounding: '<S604>/Rounding Function' */
  rtb_RoundingFunction_m = ceil(rtb_RateLimiter);

  /* Gain: '<S604>/Gain' */
  microrrede_v8_B.Delay_ja = 4.166667E-6 * rtb_RoundingFunction_m;

  /* S-Function (sfun_discreteVariableDelay): '<S606>/S-Function' */

  /* Level2 S-Function Block: '<S606>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[3];
    sfcnOutputs(rts,0);
  }

  /* Switch: '<S604>/Switch' incorporates:
   *  Constant: '<S604>/Constant'
   *  DigitalClock: '<S102>/Digital Clock'
   *  Gain: '<S605>/Gain1'
   *  Product: '<S604>/Product'
   *  Product: '<S605>/Product2'
   *  Product: '<S605>/Product4'
   *  Product: '<S605>/Product5'
   *  RelationalOperator: '<S604>/Relational Operator'
   *  Sum: '<S604>/Sum5'
   *  Sum: '<S604>/Sum7'
   *  Sum: '<S605>/Sum1'
   *  Sum: '<S605>/Sum4'
   *  UnitDelay: '<S593>/Unit Delay'
   *  UnitDelay: '<S604>/Unit Delay1'
   *  UnitDelay: '<S605>/Unit Delay'
   */
  if (rtb_Sum5_ij >= 0.016666666666666666) {
    /* Sum: '<S605>/Sum5' */
    rtb_RoundingFunction_m = rtb_RateLimiter - rtb_RoundingFunction_m;
    microrrede_v8_DW.UnitDelay1_DSTATE_fb = ((rtb_Numberofsamplespercycle_ej -
      microrrede_v8_DW.UnitDelay_DSTATE_nt) * rtb_RoundingFunction_m * 0.5 +
      rtb_Numberofsamplespercycle_ej) * (rtb_RoundingFunction_m /
      rtb_RateLimiter) + (microrrede_v8_B.Integ4_i -
                          microrrede_v8_B.SFunction_pe) *
      microrrede_v8_DW.UnitDelay_DSTATE_b;
  }

  /* End of Switch: '<S604>/Switch' */

  /* ComplexToMagnitudeAngle: '<S598>/Complex to Magnitude-Angle' incorporates:
   *  RealImagToComplex: '<S598>/Real-Imag to Complex'
   *  UnitDelay: '<S601>/Unit Delay1'
   *  UnitDelay: '<S604>/Unit Delay1'
   */
  rtb_RateLimiter = rt_hypotd_snf(microrrede_v8_DW.UnitDelay1_DSTATE_l,
    microrrede_v8_DW.UnitDelay1_DSTATE_fb);

  /* Saturate: '<S594>/Saturation' */
  if (rtb_RateLimiter <= 2.2204460492503131E-16) {
    rtb_RateLimiter = 2.2204460492503131E-16;
  }

  /* Math: '<S594>/Math Function' incorporates:
   *  Saturate: '<S594>/Saturation'
   *
   * About '<S594>/Math Function':
   *  Operator: reciprocal
   */
  microrrede_v8_B.MathFunction_l = 1.0 / rtb_RateLimiter;

  /* Update for DiscreteIntegrator: '<S601>/Integ4' */
  microrrede_v8_DW.Integ4_SYSTEM_ENABLE_k = 0U;
  microrrede_v8_DW.Integ4_DSTATE_hi = 2.0833335E-6 * rtb_Integrator_bx_tmp +
    microrrede_v8_B.Integ4_mt;

  /* Update for S-Function (sfun_discreteVariableDelay): '<S603>/S-Function' */
  /* Level2 S-Function Block: '<S603>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[2];
    sfcnUpdate(rts,0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Update for UnitDelay: '<S602>/Unit Delay' */
  microrrede_v8_DW.UnitDelay_DSTATE_fx = rtb_Integrator_bx_tmp;

  /* Update for DiscreteIntegrator: '<S604>/Integ4' */
  microrrede_v8_DW.Integ4_SYSTEM_ENABLE_bq = 0U;
  microrrede_v8_DW.Integ4_DSTATE_c = 2.0833335E-6 *
    rtb_Numberofsamplespercycle_ej + microrrede_v8_B.Integ4_i;

  /* Update for S-Function (sfun_discreteVariableDelay): '<S606>/S-Function' */
  /* Level2 S-Function Block: '<S606>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[3];
    sfcnUpdate(rts,0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Update for UnitDelay: '<S605>/Unit Delay' */
  microrrede_v8_DW.UnitDelay_DSTATE_nt = rtb_Numberofsamplespercycle_ej;

  /* End of Outputs for SubSystem: '<S593>/Automatic Gain Control' */

  /* Product: '<S593>/Product1' */
  rtb_Numberofsamplespercycle_ej = microrrede_v8_ConstB.Gain_m * rtb_A21_c;

  /* DiscreteIntegrator: '<S607>/Integ4' */
  if (microrrede_v8_DW.Integ4_SYSTEM_ENABLE_c != 0) {
    /* DiscreteIntegrator: '<S607>/Integ4' */
    microrrede_v8_B.Integ4_l = microrrede_v8_DW.Integ4_DSTATE_h5;
  } else {
    /* DiscreteIntegrator: '<S607>/Integ4' */
    microrrede_v8_B.Integ4_l = 2.0833335E-6 * rtb_Numberofsamplespercycle_ej +
      microrrede_v8_DW.Integ4_DSTATE_h5;
  }

  /* End of DiscreteIntegrator: '<S607>/Integ4' */

  /* Saturate: '<S607>/To avoid division  by zero' */
  if (microrrede_v8_DW.UnitDelay_DSTATE_b > 1.0E+6) {
    rtb_RoundingFunction_jv = 1.0E+6;
  } else if (microrrede_v8_DW.UnitDelay_DSTATE_b < 2.2204460492503131E-16) {
    rtb_RoundingFunction_jv = 2.2204460492503131E-16;
  } else {
    rtb_RoundingFunction_jv = microrrede_v8_DW.UnitDelay_DSTATE_b;
  }

  /* Fcn: '<S607>/Number of samples per cycle' incorporates:
   *  Saturate: '<S607>/To avoid division  by zero'
   */
  rtb_RateLimiter = 1.0 / rtb_RoundingFunction_jv / 4.166667e-6;

  /* Rounding: '<S607>/Rounding Function' */
  rtb_RoundingFunction_m = ceil(rtb_RateLimiter);

  /* Gain: '<S607>/Gain' */
  microrrede_v8_B.Delay_l = 4.166667E-6 * rtb_RoundingFunction_m;

  /* S-Function (sfun_discreteVariableDelay): '<S609>/S-Function' */

  /* Level2 S-Function Block: '<S609>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[22];
    sfcnOutputs(rts,0);
  }

  /* Switch: '<S607>/Switch' incorporates:
   *  Constant: '<S607>/Constant'
   *  DigitalClock: '<S102>/Digital Clock'
   *  Gain: '<S608>/Gain1'
   *  Product: '<S607>/Product'
   *  Product: '<S608>/Product2'
   *  Product: '<S608>/Product4'
   *  Product: '<S608>/Product5'
   *  RelationalOperator: '<S607>/Relational Operator'
   *  Sum: '<S607>/Sum5'
   *  Sum: '<S607>/Sum7'
   *  Sum: '<S608>/Sum1'
   *  Sum: '<S608>/Sum4'
   *  UnitDelay: '<S593>/Unit Delay'
   *  UnitDelay: '<S607>/Unit Delay1'
   *  UnitDelay: '<S608>/Unit Delay'
   */
  if (rtb_Sum5_ij >= 0.016666666666666666) {
    /* Sum: '<S608>/Sum5' */
    rtb_Sum5_ij = rtb_RateLimiter - rtb_RoundingFunction_m;
    microrrede_v8_DW.UnitDelay1_DSTATE_em = ((rtb_Numberofsamplespercycle_ej -
      microrrede_v8_DW.UnitDelay_DSTATE_hk) * rtb_Sum5_ij * 0.5 +
      rtb_Numberofsamplespercycle_ej) * (rtb_Sum5_ij / rtb_RateLimiter) +
      (microrrede_v8_B.Integ4_l - microrrede_v8_B.SFunction_i) *
      microrrede_v8_DW.UnitDelay_DSTATE_b;
  }

  /* End of Switch: '<S607>/Switch' */

  /* Product: '<S593>/Divide' incorporates:
   *  UnitDelay: '<S607>/Unit Delay1'
   */
  rtb_Sum5_ij = microrrede_v8_DW.UnitDelay1_DSTATE_em *
    microrrede_v8_B.MathFunction_l;

  /* DiscreteTransferFcn: '<S595>/Discrete Derivative ' */
  rtb_RoundingFunction_m = (rtb_Sum5_ij - -9.5833333E-5 *
    microrrede_v8_DW.DiscreteDerivative_states_o) / 0.0001;

  /* Sum: '<S595>/Sum6' incorporates:
   *  DiscreteIntegrator: '<S595>/Discrete-Time Integrator'
   *  DiscreteTransferFcn: '<S595>/Discrete Derivative '
   *  Gain: '<S595>/Kp4'
   */
  rtb_RateLimiter = (180.0 * rtb_Sum5_ij +
                     microrrede_v8_DW.DiscreteTimeIntegrator_DSTATE_m) +
    (rtb_RoundingFunction_m - microrrede_v8_DW.DiscreteDerivative_states_o);

  /* Saturate: '<S595>/Saturation1' */
  if (rtb_RateLimiter <= 0.0) {
    rtb_RoundingFunction_jv = 0.0;
  } else {
    rtb_RoundingFunction_jv = rtb_RateLimiter;
  }

  /* End of Saturate: '<S595>/Saturation1' */

  /* Gain: '<S593>/Gain10' */
  rtb_RateLimiter = 0.15915494309189535 * rtb_RoundingFunction_jv;

  /* RateLimiter: '<S593>/Rate Limiter' */
  rtb_Saturation_d = rtb_RateLimiter - microrrede_v8_DW.PrevY_j;
  if (rtb_Saturation_d > 5.0000004E-5) {
    rtb_RateLimiter = microrrede_v8_DW.PrevY_j + 5.0000004E-5;
  } else if (rtb_Saturation_d < -5.0000004E-5) {
    rtb_RateLimiter = microrrede_v8_DW.PrevY_j - 5.0000004E-5;
  }

  microrrede_v8_DW.PrevY_j = rtb_RateLimiter;

  /* End of RateLimiter: '<S593>/Rate Limiter' */

  /* UnitDelay: '<S610>/Delay_x1' */
  rtb_Saturation_d = microrrede_v8_DW.Delay_x1_DSTATE_a;

  /* UnitDelay: '<S610>/Delay_x2' */
  rtb_Add4 = microrrede_v8_DW.Delay_x2_DSTATE_b;

  /* Gain: '<S611>/A21' incorporates:
   *  UnitDelay: '<S610>/Delay_x1'
   */
  rtb_A21_c = -0.10276083316900773 * microrrede_v8_DW.Delay_x1_DSTATE_a;

  /* Sum: '<S610>/A*x1(k) + B*u1(k) ' incorporates:
   *  Gain: '<S611>/A11'
   *  Gain: '<S611>/A12'
   *  Gain: '<S612>/B11'
   *  Sum: '<S611>/sum2'
   *  UnitDelay: '<S610>/Delay_x1'
   *  UnitDelay: '<S610>/Delay_x2'
   */
  microrrede_v8_DW.Delay_x1_DSTATE_a = (0.99999978591491367 *
    microrrede_v8_DW.Delay_x1_DSTATE_a + 4.1647394021622489E-6 *
    microrrede_v8_DW.Delay_x2_DSTATE_b) + 2.082369701081124E-6 * rtb_RateLimiter;

  /* Sum: '<S610>/A*x2(k) + B*u2(k)' incorporates:
   *  Gain: '<S611>/A22'
   *  Gain: '<S612>/B21'
   *  Sum: '<S611>/sum3'
   *  UnitDelay: '<S610>/Delay_x2'
   */
  microrrede_v8_DW.Delay_x2_DSTATE_b = (0.999074753111899 *
    microrrede_v8_DW.Delay_x2_DSTATE_b + rtb_A21_c) + 0.99953737655594943 *
    rtb_RateLimiter;

  /* Sum: '<S610>/C*X(k)+D*u(k)' incorporates:
   *  Gain: '<S610>/D*u(k)'
   *  Gain: '<S613>/C11'
   *  Gain: '<S613>/C12'
   *  Sum: '<S613>/sum2'
   *  UnitDelay: '<S593>/Unit Delay'
   */
  microrrede_v8_DW.UnitDelay_DSTATE_b = (0.10280838373778885 * rtb_Saturation_d
    + 2.1408508622890496E-7 * rtb_Add4) + 1.0704254311445248E-7 *
    rtb_RateLimiter;

  /* Update for Memory: '<S39>/it init1' incorporates:
   *  Constant: '<S39>/Constant12'
   */
  microrrede_v8_DW.itinit1_PreviousInput = 210.41663300000002;

  /* Update for DiscreteTransferFcn: '<S39>/Current filter' */
  microrrede_v8_DW.Currentfilter_states = microrrede_v8_B.StateSpace_o1[63] -
    -0.99998750007712467 * microrrede_v8_DW.Currentfilter_states;

  /* Update for Memory: '<S39>/it init' incorporates:
   *  Gain: '<S39>/Gain2'
   */
  microrrede_v8_DW.itinit_PreviousInput = 3600.0 * rtb_Switch7;

  /* Update for DiscreteIntegrator: '<S39>/int(i)' incorporates:
   *  Constant: '<S41>/Constant'
   *  DiscreteTransferFcn: '<S39>/Current filter'
   *  RelationalOperator: '<S41>/Compare'
   */
  microrrede_v8_DW.inti_IC_LOADING = 0U;
  microrrede_v8_DW.inti_DSTATE += 4.166667E-6 * microrrede_v8_B.StateSpace_o1[63];
  if (microrrede_v8_DW.inti_DSTATE > 757499.87880000006) {
    microrrede_v8_DW.inti_DSTATE = 757499.87880000006;
  }

  if (numAccum > 0.0) {
    microrrede_v8_DW.inti_PrevResetState = 1;
  } else {
    microrrede_v8_DW.inti_PrevResetState = 0;
  }

  /* End of Update for DiscreteIntegrator: '<S39>/int(i)' */

  /* Update for DiscreteIntegrator: '<S44>/Discrete-Time Integrator' incorporates:
   *  Abs: '<S44>/Abs'
   *  Constant: '<S48>/Constant'
   *  DataTypeConversion: '<S44>/Data Type Conversion1'
   *  Gain: '<S44>/Gain1'
   *  Gain: '<S44>/Gain4'
   *  Product: '<S44>/Divide'
   *  RelationalOperator: '<S48>/Compare'
   *  Sum: '<S44>/Add3'
   */
  microrrede_v8_DW.DiscreteTimeIntegrator_DSTATE += ((real_T)
    (microrrede_v8_B.StateSpace_o1[63] < 0.0) * 14.86455342254084 -
    microrrede_v8_DW.DiscreteTimeIntegrator_DSTATE) * fabs
    (microrrede_v8_B.StateSpace_o1[63]) * 0.0012499993750003124 * 4.166667E-6;

  /* Update for Memory: '<S39>/Memory2' incorporates:
   *  Gain: '<S39>/R1'
   */
  microrrede_v8_DW.Memory2_PreviousInput = 0.0024 *
    microrrede_v8_B.StateSpace_o1[63];

  /* Update for Sin: '<S152>/Sine Wave A' */
  numAccum = microrrede_v8_DW.lastSin;
  microrrede_v8_DW.lastSin = microrrede_v8_DW.lastSin * 0.99999876629950613 +
    microrrede_v8_DW.lastCos * 0.0015707958064944299;
  microrrede_v8_DW.lastCos = microrrede_v8_DW.lastCos * 0.99999876629950613 -
    numAccum * 0.0015707958064944299;

  /* Update for Sin: '<S152>/Sine Wave B' */
  numAccum = microrrede_v8_DW.lastSin_c;
  microrrede_v8_DW.lastSin_c = microrrede_v8_DW.lastSin_c * 0.99999876629950613
    + microrrede_v8_DW.lastCos_l * 0.0015707958064944299;
  microrrede_v8_DW.lastCos_l = microrrede_v8_DW.lastCos_l * 0.99999876629950613
    - numAccum * 0.0015707958064944299;

  /* Update for Sin: '<S152>/Sine Wave C' */
  numAccum = microrrede_v8_DW.lastSin_cr;
  microrrede_v8_DW.lastSin_cr = microrrede_v8_DW.lastSin_cr *
    0.99999876629950613 + microrrede_v8_DW.lastCos_f * 0.0015707958064944299;
  microrrede_v8_DW.lastCos_f = microrrede_v8_DW.lastCos_f * 0.99999876629950613
    - numAccum * 0.0015707958064944299;

  /* Update for UnitDelay: '<S998>/Unit Delay' */
  microrrede_v8_DW.UnitDelay_DSTATE_g[0] = rtb_Gain;
  microrrede_v8_DW.UnitDelay_DSTATE_g[1] = rtb_Fcn6;
  microrrede_v8_DW.UnitDelay_DSTATE_g[2] = rtb_uR_j;

  /* Update for S-Function (sfun_spssw_discc_DSS): '<S998>/State-Space' incorporates:
   *  Constant: '<S1002>/SwitchCurrents'
   *  Constant: '<S105>/eee'
   *  Constant: '<S369>/eee'
   *  Constant: '<S989>/eee'
   *  Inport: '<Root>/XCBR_CC_1_in'
   *  Inport: '<Root>/XCBR_CC_2_in'
   *  Inport: '<Root>/XCBR_CC_3_in'
   */
  /* Level2 S-Function Block: '<S998>/State-Space' (sfun_spssw_discc_DSS) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[6];
    sfcnUpdate(rts,0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Update for DiscreteIntegrator: '<S83>/Integrator' */
  microrrede_v8_DW.Integrator_DSTATE += 4.166667E-6 * rtb_IntegralGain;

  /* Update for DiscreteIntegrator: '<S194>/Integrator' */
  microrrede_v8_DW.Integrator_DSTATE_f += 4.166667E-6 * rtb_Integrator_e;

  /* Update for DiscreteIntegrator: '<S241>/Integ4' */
  microrrede_v8_DW.Integ4_SYSTEM_ENABLE = 0U;
  microrrede_v8_DW.Integ4_DSTATE = 2.0833335E-6 * microrrede_v8_B.StateSpace_o1
    [41] + microrrede_v8_B.Integ4;

  /* Update for S-Function (sfun_discreteVariableDelay): '<S242>/S-Function' incorporates:
   *  Constant: '<S241>/K1'
   */
  /* Level2 S-Function Block: '<S242>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[7];
    sfcnUpdate(rts,0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Update for UnitDelay: '<S241>/Unit Delay' */
  microrrede_v8_DW.UnitDelay_DSTATE_cn = microrrede_v8_B.StateSpace_o1[41];

  /* Update for S-Function (sfun_discreteVariableDelay): '<S313>/S-Function' */
  /* Level2 S-Function Block: '<S313>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[8];
    sfcnUpdate(rts,0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Update for DiscreteIntegrator: '<S291>/Discrete-Time Integrator' */
  microrrede_v8_DW.DiscreteTimeIntegrator_DSTATE_k += 4.166667E-6 *
    rtb_Saturation1;
  microrrede_v8_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
    rtb_RelationalOperator_mb;

  /* Update for DiscreteIntegrator: '<S274>/Integrator' */
  microrrede_v8_DW.Integrator_DSTATE_n += 4.166667E-6 * rtb_Integrator_m;

  /* Update for DiscreteIntegrator: '<S350>/Integrator' incorporates:
   *  Gain: '<S347>/Integral Gain'
   */
  microrrede_v8_DW.Integrator_DSTATE_k[0] += 6.6 * Initial * 4.166667E-6;
  microrrede_v8_DW.Integrator_DSTATE_k[1] += 6.6 * rtb_Integrator_c_idx_1 *
    4.166667E-6;

  /* Update for DiscreteIntegrator: '<S235>/Integ4' incorporates:
   *  Product: '<S226>/Product1'
   */
  microrrede_v8_DW.Integ4_SYSTEM_ENABLE_h = 0U;
  microrrede_v8_DW.Integ4_DSTATE_l = 2.0833335E-6 * rtb_Product1_f_tmp +
    microrrede_v8_B.Integ4_p;

  /* Update for S-Function (sfun_discreteVariableDelay): '<S237>/S-Function' */
  /* Level2 S-Function Block: '<S237>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[9];
    sfcnUpdate(rts,0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Update for UnitDelay: '<S236>/Unit Delay' incorporates:
   *  Product: '<S226>/Product1'
   */
  microrrede_v8_DW.UnitDelay_DSTATE_dc = rtb_Product1_f_tmp;

  /* Update for DiscreteIntegrator: '<S238>/Integ4' */
  microrrede_v8_DW.Integ4_SYSTEM_ENABLE_a = 0U;
  microrrede_v8_DW.Integ4_DSTATE_h = 2.0833335E-6 * rtb_Numberofsamplespercycle
    + microrrede_v8_B.Integ4_e;

  /* Update for S-Function (sfun_discreteVariableDelay): '<S240>/S-Function' */
  /* Level2 S-Function Block: '<S240>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[10];
    sfcnUpdate(rts,0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Update for UnitDelay: '<S239>/Unit Delay' */
  microrrede_v8_DW.UnitDelay_DSTATE_m = rtb_Numberofsamplespercycle;

  /* Update for DiscreteIntegrator: '<S305>/Integ4' */
  microrrede_v8_DW.Integ4_SYSTEM_ENABLE_j = 0U;
  microrrede_v8_DW.Integ4_DSTATE_o = 2.0833335E-6 * rtb_RoundingFunction +
    microrrede_v8_B.Integ4_ep;

  /* Update for S-Function (sfun_discreteVariableDelay): '<S307>/S-Function' */
  /* Level2 S-Function Block: '<S307>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[11];
    sfcnUpdate(rts,0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Update for UnitDelay: '<S306>/Unit Delay' */
  microrrede_v8_DW.UnitDelay_DSTATE_cm = rtb_RoundingFunction;

  /* Update for DiscreteTransferFcn: '<S293>/Discrete Derivative ' */
  microrrede_v8_DW.DiscreteDerivative_states = rtb_RoundingFunction_ay;

  /* Update for DiscreteIntegrator: '<S293>/Discrete-Time Integrator' */
  microrrede_v8_DW.DiscreteTimeIntegrator_DSTATE_n += 0.0133333344 *
    rtb_Numberofsamplespercycle_f;
  if (microrrede_v8_DW.DiscreteTimeIntegrator_DSTATE_n < 0.0) {
    microrrede_v8_DW.DiscreteTimeIntegrator_DSTATE_n = 0.0;
  }

  /* End of Update for DiscreteIntegrator: '<S293>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S814>/Integrator' */
  microrrede_v8_DW.Integrator_DSTATE_p += 4.166667E-6 * rtb_A21;

  /* Update for DiscreteIntegrator: '<S861>/Integ4' */
  microrrede_v8_DW.Integ4_SYSTEM_ENABLE_n = 0U;
  microrrede_v8_DW.Integ4_DSTATE_f = 2.0833335E-6 *
    microrrede_v8_B.StateSpace_o1[61] + microrrede_v8_B.Integ4_b;

  /* Update for S-Function (sfun_discreteVariableDelay): '<S862>/S-Function' incorporates:
   *  Constant: '<S861>/K1'
   */
  /* Level2 S-Function Block: '<S862>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[12];
    sfcnUpdate(rts,0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Update for UnitDelay: '<S861>/Unit Delay' */
  microrrede_v8_DW.UnitDelay_DSTATE_gf = microrrede_v8_B.StateSpace_o1[61];

  /* Update for S-Function (sfun_discreteVariableDelay): '<S933>/S-Function' */
  /* Level2 S-Function Block: '<S933>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[13];
    sfcnUpdate(rts,0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Update for DiscreteIntegrator: '<S911>/Discrete-Time Integrator' */
  microrrede_v8_DW.DiscreteTimeIntegrator_DSTATE_h += 4.166667E-6 *
    rtb_Saturation1_k;
  microrrede_v8_DW.DiscreteTimeIntegrator_PrevRe_g = (int8_T)
    rtb_RelationalOperator_hn;

  /* Update for DiscreteIntegrator: '<S894>/Integrator' */
  microrrede_v8_DW.Integrator_DSTATE_h += 4.166667E-6 * rtb_Integrator_jg;

  /* Update for DiscreteIntegrator: '<S970>/Integrator' incorporates:
   *  Gain: '<S967>/Integral Gain'
   */
  microrrede_v8_DW.Integrator_DSTATE_f5[0] += 6.6 * rtb_RoundingFunction_go *
    4.166667E-6;
  microrrede_v8_DW.Integrator_DSTATE_f5[1] += 6.6 * rtb_x2k * 4.166667E-6;

  /* Update for DiscreteIntegrator: '<S855>/Integ4' incorporates:
   *  Product: '<S846>/Product1'
   */
  microrrede_v8_DW.Integ4_SYSTEM_ENABLE_nm = 0U;
  microrrede_v8_DW.Integ4_DSTATE_fu = 2.0833335E-6 * DataTypeConversion_tmp +
    microrrede_v8_B.Integ4_j;

  /* Update for S-Function (sfun_discreteVariableDelay): '<S857>/S-Function' */
  /* Level2 S-Function Block: '<S857>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[14];
    sfcnUpdate(rts,0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Update for UnitDelay: '<S856>/Unit Delay' incorporates:
   *  Product: '<S846>/Product1'
   */
  microrrede_v8_DW.UnitDelay_DSTATE_h = DataTypeConversion_tmp;

  /* Update for DiscreteIntegrator: '<S858>/Integ4' */
  microrrede_v8_DW.Integ4_SYSTEM_ENABLE_i = 0U;
  microrrede_v8_DW.Integ4_DSTATE_d = 2.0833335E-6 *
    rtb_Numberofsamplespercycle_e + microrrede_v8_B.Integ4_f;

  /* Update for S-Function (sfun_discreteVariableDelay): '<S860>/S-Function' */
  /* Level2 S-Function Block: '<S860>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[15];
    sfcnUpdate(rts,0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Update for UnitDelay: '<S859>/Unit Delay' */
  microrrede_v8_DW.UnitDelay_DSTATE_ds = rtb_Numberofsamplespercycle_e;

  /* Update for DiscreteIntegrator: '<S925>/Integ4' */
  microrrede_v8_DW.Integ4_SYSTEM_ENABLE_p = 0U;
  microrrede_v8_DW.Integ4_DSTATE_fb = 2.0833335E-6 * rtb_Integrator_l +
    microrrede_v8_B.Integ4_eu;

  /* Update for S-Function (sfun_discreteVariableDelay): '<S927>/S-Function' */
  /* Level2 S-Function Block: '<S927>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[16];
    sfcnUpdate(rts,0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Update for UnitDelay: '<S926>/Unit Delay' */
  microrrede_v8_DW.UnitDelay_DSTATE_a = rtb_Integrator_l;

  /* Update for DiscreteTransferFcn: '<S913>/Discrete Derivative ' */
  microrrede_v8_DW.DiscreteDerivative_states_h = rtb_Numberofsamplespercycle_mb;

  /* Update for DiscreteIntegrator: '<S913>/Discrete-Time Integrator' */
  microrrede_v8_DW.DiscreteTimeIntegrator_DSTAT_ht += 0.0133333344 *
    rtb_RoundingFunction_d4;
  if (microrrede_v8_DW.DiscreteTimeIntegrator_DSTAT_ht < 0.0) {
    microrrede_v8_DW.DiscreteTimeIntegrator_DSTAT_ht = 0.0;
  }

  /* End of Update for DiscreteIntegrator: '<S913>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S670>/Integ4' */
  microrrede_v8_DW.Integ4_SYSTEM_ENABLE_e = 0U;
  microrrede_v8_DW.Integ4_DSTATE_p = 2.0833335E-6 *
    microrrede_v8_B.StateSpace_o1[43] + microrrede_v8_B.Integ4_b5;

  /* Update for S-Function (sfun_discreteVariableDelay): '<S671>/S-Function' incorporates:
   *  Constant: '<S670>/K1'
   */
  /* Level2 S-Function Block: '<S671>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[17];
    sfcnUpdate(rts,0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Update for UnitDelay: '<S670>/Unit Delay' */
  microrrede_v8_DW.UnitDelay_DSTATE_n = microrrede_v8_B.StateSpace_o1[43];

  /* Update for DiscreteIntegrator: '<S430>/Integrator' incorporates:
   *  Constant: '<S20>/Constant7'
   *  Gain: '<S427>/Integral Gain'
   *  Sum: '<S20>/Sum1'
   *  UnitDelay: '<S670>/Unit Delay1'
   */
  microrrede_v8_DW.Integrator_DSTATE_j += (400.0 -
    microrrede_v8_DW.UnitDelay1_DSTATE_g) * 4.20837 * 4.166667E-6;

  /* Update for DiscreteIntegrator: '<S478>/Integrator' */
  microrrede_v8_DW.Integrator_DSTATE_kn += 4.166667E-6 * rtb_Integrator_h;

  /* Update for Sin: '<S500>/Sine Wave' */
  numAccum = microrrede_v8_DW.lastSin_h;
  microrrede_v8_DW.lastSin_h = microrrede_v8_DW.lastSin_h * 0.99999876629950613
    + microrrede_v8_DW.lastCos_m * 0.0015707958064944299;
  microrrede_v8_DW.lastCos_m = microrrede_v8_DW.lastCos_m * 0.99999876629950613
    - numAccum * 0.0015707958064944299;

  /* Update for DiscreteIntegrator: '<S543>/Integ4' */
  microrrede_v8_DW.Integ4_SYSTEM_ENABLE_pi = 0U;
  microrrede_v8_DW.Integ4_DSTATE_a = 2.0833335E-6 *
    microrrede_v8_B.StateSpace_o1[43] + microrrede_v8_B.Integ4_ps;

  /* Update for S-Function (sfun_discreteVariableDelay): '<S544>/S-Function' incorporates:
   *  Constant: '<S543>/K1'
   */
  /* Level2 S-Function Block: '<S544>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[18];
    sfcnUpdate(rts,0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Update for UnitDelay: '<S543>/Unit Delay' */
  microrrede_v8_DW.UnitDelay_DSTATE_f = microrrede_v8_B.StateSpace_o1[43];

  /* Update for S-Function (sfun_discreteVariableDelay): '<S615>/S-Function' */
  /* Level2 S-Function Block: '<S615>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[19];
    sfcnUpdate(rts,0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Update for DiscreteIntegrator: '<S593>/Discrete-Time Integrator' */
  microrrede_v8_DW.DiscreteTimeIntegrator_DSTATE_l += 4.166667E-6 *
    rtb_RoundingFunction_jv;
  microrrede_v8_DW.DiscreteTimeIntegrator_PrevRe_j = (int8_T)
    rtb_RelationalOperator_nv;

  /* Update for DiscreteIntegrator: '<S576>/Integrator' incorporates:
   *  Gain: '<S573>/Integral Gain'
   */
  microrrede_v8_DW.Integrator_DSTATE_g += 200.0 * rtb_Gain3_m * 4.166667E-6;

  /* Update for DiscreteIntegrator: '<S652>/Integrator' incorporates:
   *  Gain: '<S649>/Integral Gain'
   */
  microrrede_v8_DW.Integrator_DSTATE_m[0] += 6.6 * rtb_RoundingFunction_je *
    4.166667E-6;
  microrrede_v8_DW.Integrator_DSTATE_m[1] += 6.6 * rtb_A21_p * 4.166667E-6;

  /* Update for DiscreteIntegrator: '<S537>/Integ4' incorporates:
   *  Product: '<S528>/Product1'
   */
  microrrede_v8_DW.Integ4_SYSTEM_ENABLE_eq = 0U;
  microrrede_v8_DW.Integ4_DSTATE_hc = 2.0833335E-6 * rtb_Integrator_bx_tmp +
    microrrede_v8_B.Integ4_c;

  /* Update for S-Function (sfun_discreteVariableDelay): '<S539>/S-Function' */
  /* Level2 S-Function Block: '<S539>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[20];
    sfcnUpdate(rts,0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Update for UnitDelay: '<S538>/Unit Delay' incorporates:
   *  Product: '<S528>/Product1'
   */
  microrrede_v8_DW.UnitDelay_DSTATE_al = rtb_Integrator_bx_tmp;

  /* Update for DiscreteIntegrator: '<S540>/Integ4' */
  microrrede_v8_DW.Integ4_SYSTEM_ENABLE_b = 0U;
  microrrede_v8_DW.Integ4_DSTATE_lt = 2.0833335E-6 *
    rtb_Numberofsamplespercycle_lo + microrrede_v8_B.Integ4_g;

  /* Update for S-Function (sfun_discreteVariableDelay): '<S542>/S-Function' */
  /* Level2 S-Function Block: '<S542>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[21];
    sfcnUpdate(rts,0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Update for UnitDelay: '<S541>/Unit Delay' */
  microrrede_v8_DW.UnitDelay_DSTATE_o = rtb_Numberofsamplespercycle_lo;

  /* Update for DiscreteIntegrator: '<S607>/Integ4' */
  microrrede_v8_DW.Integ4_SYSTEM_ENABLE_c = 0U;
  microrrede_v8_DW.Integ4_DSTATE_h5 = 2.0833335E-6 *
    rtb_Numberofsamplespercycle_ej + microrrede_v8_B.Integ4_l;

  /* Update for S-Function (sfun_discreteVariableDelay): '<S609>/S-Function' */
  /* Level2 S-Function Block: '<S609>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[22];
    sfcnUpdate(rts,0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Update for UnitDelay: '<S608>/Unit Delay' */
  microrrede_v8_DW.UnitDelay_DSTATE_hk = rtb_Numberofsamplespercycle_ej;

  /* Update for DiscreteTransferFcn: '<S595>/Discrete Derivative ' */
  microrrede_v8_DW.DiscreteDerivative_states_o = rtb_RoundingFunction_m;

  /* Update for DiscreteIntegrator: '<S595>/Discrete-Time Integrator' */
  microrrede_v8_DW.DiscreteTimeIntegrator_DSTATE_m += 0.0133333344 * rtb_Sum5_ij;
  if (microrrede_v8_DW.DiscreteTimeIntegrator_DSTATE_m < 0.0) {
    microrrede_v8_DW.DiscreteTimeIntegrator_DSTATE_m = 0.0;
  }

  /* End of Update for DiscreteIntegrator: '<S595>/Discrete-Time Integrator' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++microrrede_v8_M->Timing.clockTick0)) {
    ++microrrede_v8_M->Timing.clockTickH0;
  }

  microrrede_v8_M->Timing.t[0] = microrrede_v8_M->Timing.clockTick0 *
    microrrede_v8_M->Timing.stepSize0 + microrrede_v8_M->Timing.clockTickH0 *
    microrrede_v8_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void microrrede_v8_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtsiSetSolverName(&microrrede_v8_M->solverInfo,"FixedStepDiscrete");
  microrrede_v8_M->solverInfoPtr = (&microrrede_v8_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = microrrede_v8_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "microrrede_v8_M points to
       static memory which is guaranteed to be non-NULL" */
    microrrede_v8_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    microrrede_v8_M->Timing.sampleTimes =
      (&microrrede_v8_M->Timing.sampleTimesArray[0]);
    microrrede_v8_M->Timing.offsetTimes =
      (&microrrede_v8_M->Timing.offsetTimesArray[0]);

    /* task periods */
    microrrede_v8_M->Timing.sampleTimes[0] = (4.166667E-6);

    /* task offsets */
    microrrede_v8_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(microrrede_v8_M, &microrrede_v8_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = microrrede_v8_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    microrrede_v8_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(microrrede_v8_M, -1);
  microrrede_v8_M->Timing.stepSize0 = 4.166667E-6;
  microrrede_v8_M->solverInfoPtr = (&microrrede_v8_M->solverInfo);
  microrrede_v8_M->Timing.stepSize = (4.166667E-6);
  rtsiSetFixedStepSize(&microrrede_v8_M->solverInfo, 4.166667E-6);
  rtsiSetSolverMode(&microrrede_v8_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &microrrede_v8_M->NonInlinedSFcns.sfcnInfo;
    microrrede_v8_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(microrrede_v8_M)));
    microrrede_v8_M->Sizes.numSampTimes = (1);
    rtssSetNumRootSampTimesPtr(sfcnInfo, &microrrede_v8_M->Sizes.numSampTimes);
    microrrede_v8_M->NonInlinedSFcns.taskTimePtrs[0] = (&rtmGetTPtr
      (microrrede_v8_M)[0]);
    rtssSetTPtrPtr(sfcnInfo,microrrede_v8_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(microrrede_v8_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(microrrede_v8_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(microrrede_v8_M));
    rtssSetStepSizePtr(sfcnInfo, &microrrede_v8_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(microrrede_v8_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &microrrede_v8_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &microrrede_v8_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &microrrede_v8_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo, &microrrede_v8_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &microrrede_v8_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &microrrede_v8_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &microrrede_v8_M->solverInfoPtr);
  }

  microrrede_v8_M->Sizes.numSFcns = (23);

  /* register each child */
  {
    (void) memset((void *)&microrrede_v8_M->NonInlinedSFcns.childSFunctions[0],
                  0,
                  23*sizeof(SimStruct));
    microrrede_v8_M->childSfunctions =
      (&microrrede_v8_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 23; i++) {
        microrrede_v8_M->childSfunctions[i] =
          (&microrrede_v8_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: microrrede_v8/<S301>/S-Function (sfun_discreteVariableDelay) */
    {
      SimStruct *rts = microrrede_v8_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = microrrede_v8_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = microrrede_v8_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = microrrede_v8_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &microrrede_v8_M->NonInlinedSFcns.blkInfo2[0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &microrrede_v8_M->NonInlinedSFcns.inputOutputPortInfo2[0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, microrrede_v8_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &microrrede_v8_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &microrrede_v8_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &microrrede_v8_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &microrrede_v8_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &microrrede_v8_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn0.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn0.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &microrrede_v8_M->NonInlinedSFcns.Sfcn0.UPtrs0;
          sfcnUPtrs[0] = &microrrede_v8_B.Integ4_jd;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &microrrede_v8_M->NonInlinedSFcns.Sfcn0.UPtrs1;
          sfcnUPtrs[0] = &microrrede_v8_B.Delay_du;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidthAsInt(rts, 1, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn0.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn0.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &microrrede_v8_B.SFunction_pp));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PLL/Model/Automatic Gain Control/Fundamental (PLL-Driven)/Mean (Variable Frequency)1/Model/Discrete Variable Time Delay/S-Function");
      ssSetRTModel(rts,microrrede_v8_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)microrrede_v8_ConstP.SFunction_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)microrrede_v8_ConstP.SFunction_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)microrrede_v8_ConstP.SFunction_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)microrrede_v8_ConstP.SFunction_P4_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &microrrede_v8_DW.SFunction_RWORK_jd);
      ssSetPWork(rts, (void **) &microrrede_v8_DW.SFunction_PWORK_d[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 2);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &microrrede_v8_DW.SFunction_RWORK_jd);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 1, 2);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &microrrede_v8_DW.SFunction_PWORK_d[0]);
      }

      /* registration */
      sfun_discreteVariableDelay(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 4.166667E-6);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidthAsInt(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetInputPortUnit(rts, 0, 0);
      ssSetInputPortIsContinuousQuantity(rts, 0, 0);
      ssSetInputPortWidthAsInt(rts, 1, 1);
      ssSetInputPortDataType(rts, 1, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 1, 0);
      ssSetInputPortFrameData(rts, 1, 0);
      ssSetInputPortUnit(rts, 1, 0);
      ssSetInputPortIsContinuousQuantity(rts, 1, 0);
      ssSetOutputPortWidthAsInt(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetOutputPortUnit(rts, 0, 0);
      ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: microrrede_v8/<S304>/S-Function (sfun_discreteVariableDelay) */
    {
      SimStruct *rts = microrrede_v8_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = microrrede_v8_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = microrrede_v8_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = microrrede_v8_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &microrrede_v8_M->NonInlinedSFcns.blkInfo2[1]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &microrrede_v8_M->NonInlinedSFcns.inputOutputPortInfo2[1]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, microrrede_v8_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &microrrede_v8_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &microrrede_v8_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &microrrede_v8_M->NonInlinedSFcns.methods4[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &microrrede_v8_M->NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts,
          &microrrede_v8_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn1.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn1.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &microrrede_v8_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = &microrrede_v8_B.Integ4_i3;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &microrrede_v8_M->NonInlinedSFcns.Sfcn1.UPtrs1;
          sfcnUPtrs[0] = &microrrede_v8_B.Delay_b;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidthAsInt(rts, 1, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn1.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn1.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &microrrede_v8_B.SFunction_f0));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PLL/Model/Automatic Gain Control/Fundamental (PLL-Driven)/Mean (Variable Frequency)2/Model/Discrete Variable Time Delay/S-Function");
      ssSetRTModel(rts,microrrede_v8_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)microrrede_v8_ConstP.SFunction_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)microrrede_v8_ConstP.SFunction_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)microrrede_v8_ConstP.SFunction_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)microrrede_v8_ConstP.SFunction_P4_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &microrrede_v8_DW.SFunction_RWORK_hd);
      ssSetPWork(rts, (void **) &microrrede_v8_DW.SFunction_PWORK_ej[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 2);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &microrrede_v8_DW.SFunction_RWORK_hd);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 1, 2);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &microrrede_v8_DW.SFunction_PWORK_ej[0]);
      }

      /* registration */
      sfun_discreteVariableDelay(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 4.166667E-6);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidthAsInt(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetInputPortUnit(rts, 0, 0);
      ssSetInputPortIsContinuousQuantity(rts, 0, 0);
      ssSetInputPortWidthAsInt(rts, 1, 1);
      ssSetInputPortDataType(rts, 1, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 1, 0);
      ssSetInputPortFrameData(rts, 1, 0);
      ssSetInputPortUnit(rts, 1, 0);
      ssSetInputPortIsContinuousQuantity(rts, 1, 0);
      ssSetOutputPortWidthAsInt(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetOutputPortUnit(rts, 0, 0);
      ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: microrrede_v8/<S603>/S-Function (sfun_discreteVariableDelay) */
    {
      SimStruct *rts = microrrede_v8_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = microrrede_v8_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = microrrede_v8_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = microrrede_v8_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &microrrede_v8_M->NonInlinedSFcns.blkInfo2[2]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &microrrede_v8_M->NonInlinedSFcns.inputOutputPortInfo2[2]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, microrrede_v8_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &microrrede_v8_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &microrrede_v8_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &microrrede_v8_M->NonInlinedSFcns.methods4[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &microrrede_v8_M->NonInlinedSFcns.statesInfo2[2]);
        ssSetPeriodicStatesInfo(rts,
          &microrrede_v8_M->NonInlinedSFcns.periodicStatesInfo[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn2.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn2.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &microrrede_v8_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = &microrrede_v8_B.Integ4_mt;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &microrrede_v8_M->NonInlinedSFcns.Sfcn2.UPtrs1;
          sfcnUPtrs[0] = &microrrede_v8_B.Delay_le;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidthAsInt(rts, 1, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn2.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn2.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &microrrede_v8_B.SFunction_h));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PLL/Model/Automatic Gain Control/Fundamental (PLL-Driven)/Mean (Variable Frequency)1/Model/Discrete Variable Time Delay/S-Function");
      ssSetRTModel(rts,microrrede_v8_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)microrrede_v8_ConstP.SFunction_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)microrrede_v8_ConstP.SFunction_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)microrrede_v8_ConstP.SFunction_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)microrrede_v8_ConstP.SFunction_P4_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &microrrede_v8_DW.SFunction_RWORK_hu);
      ssSetPWork(rts, (void **) &microrrede_v8_DW.SFunction_PWORK_ae[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 2);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &microrrede_v8_DW.SFunction_RWORK_hu);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 1, 2);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &microrrede_v8_DW.SFunction_PWORK_ae[0]);
      }

      /* registration */
      sfun_discreteVariableDelay(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 4.166667E-6);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidthAsInt(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetInputPortUnit(rts, 0, 0);
      ssSetInputPortIsContinuousQuantity(rts, 0, 0);
      ssSetInputPortWidthAsInt(rts, 1, 1);
      ssSetInputPortDataType(rts, 1, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 1, 0);
      ssSetInputPortFrameData(rts, 1, 0);
      ssSetInputPortUnit(rts, 1, 0);
      ssSetInputPortIsContinuousQuantity(rts, 1, 0);
      ssSetOutputPortWidthAsInt(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetOutputPortUnit(rts, 0, 0);
      ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: microrrede_v8/<S606>/S-Function (sfun_discreteVariableDelay) */
    {
      SimStruct *rts = microrrede_v8_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = microrrede_v8_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = microrrede_v8_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = microrrede_v8_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &microrrede_v8_M->NonInlinedSFcns.blkInfo2[3]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &microrrede_v8_M->NonInlinedSFcns.inputOutputPortInfo2[3]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, microrrede_v8_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &microrrede_v8_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &microrrede_v8_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &microrrede_v8_M->NonInlinedSFcns.methods4[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &microrrede_v8_M->NonInlinedSFcns.statesInfo2[3]);
        ssSetPeriodicStatesInfo(rts,
          &microrrede_v8_M->NonInlinedSFcns.periodicStatesInfo[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn3.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn3.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &microrrede_v8_M->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = &microrrede_v8_B.Integ4_i;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &microrrede_v8_M->NonInlinedSFcns.Sfcn3.UPtrs1;
          sfcnUPtrs[0] = &microrrede_v8_B.Delay_ja;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidthAsInt(rts, 1, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn3.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn3.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &microrrede_v8_B.SFunction_pe));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PLL/Model/Automatic Gain Control/Fundamental (PLL-Driven)/Mean (Variable Frequency)2/Model/Discrete Variable Time Delay/S-Function");
      ssSetRTModel(rts,microrrede_v8_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)microrrede_v8_ConstP.SFunction_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)microrrede_v8_ConstP.SFunction_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)microrrede_v8_ConstP.SFunction_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)microrrede_v8_ConstP.SFunction_P4_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &microrrede_v8_DW.SFunction_RWORK_as);
      ssSetPWork(rts, (void **) &microrrede_v8_DW.SFunction_PWORK_iz[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn3.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn3.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 2);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &microrrede_v8_DW.SFunction_RWORK_as);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 1, 2);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &microrrede_v8_DW.SFunction_PWORK_iz[0]);
      }

      /* registration */
      sfun_discreteVariableDelay(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 4.166667E-6);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidthAsInt(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetInputPortUnit(rts, 0, 0);
      ssSetInputPortIsContinuousQuantity(rts, 0, 0);
      ssSetInputPortWidthAsInt(rts, 1, 1);
      ssSetInputPortDataType(rts, 1, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 1, 0);
      ssSetInputPortFrameData(rts, 1, 0);
      ssSetInputPortUnit(rts, 1, 0);
      ssSetInputPortIsContinuousQuantity(rts, 1, 0);
      ssSetOutputPortWidthAsInt(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetOutputPortUnit(rts, 0, 0);
      ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: microrrede_v8/<S921>/S-Function (sfun_discreteVariableDelay) */
    {
      SimStruct *rts = microrrede_v8_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = microrrede_v8_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = microrrede_v8_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = microrrede_v8_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &microrrede_v8_M->NonInlinedSFcns.blkInfo2[4]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &microrrede_v8_M->NonInlinedSFcns.inputOutputPortInfo2[4]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, microrrede_v8_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &microrrede_v8_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &microrrede_v8_M->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &microrrede_v8_M->NonInlinedSFcns.methods4[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &microrrede_v8_M->NonInlinedSFcns.statesInfo2[4]);
        ssSetPeriodicStatesInfo(rts,
          &microrrede_v8_M->NonInlinedSFcns.periodicStatesInfo[4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn4.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn4.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn4.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn4.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &microrrede_v8_M->NonInlinedSFcns.Sfcn4.UPtrs0;
          sfcnUPtrs[0] = &microrrede_v8_B.Integ4_m;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &microrrede_v8_M->NonInlinedSFcns.Sfcn4.UPtrs1;
          sfcnUPtrs[0] = &microrrede_v8_B.Delay_h;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidthAsInt(rts, 1, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn4.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn4.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &microrrede_v8_B.SFunction_ip));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PLL/Model/Automatic Gain Control/Fundamental (PLL-Driven)/Mean (Variable Frequency)1/Model/Discrete Variable Time Delay/S-Function");
      ssSetRTModel(rts,microrrede_v8_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)microrrede_v8_ConstP.SFunction_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)microrrede_v8_ConstP.SFunction_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)microrrede_v8_ConstP.SFunction_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)microrrede_v8_ConstP.SFunction_P4_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &microrrede_v8_DW.SFunction_RWORK_n);
      ssSetPWork(rts, (void **) &microrrede_v8_DW.SFunction_PWORK_m[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn4.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn4.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 2);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &microrrede_v8_DW.SFunction_RWORK_n);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 1, 2);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &microrrede_v8_DW.SFunction_PWORK_m[0]);
      }

      /* registration */
      sfun_discreteVariableDelay(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 4.166667E-6);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidthAsInt(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetInputPortUnit(rts, 0, 0);
      ssSetInputPortIsContinuousQuantity(rts, 0, 0);
      ssSetInputPortWidthAsInt(rts, 1, 1);
      ssSetInputPortDataType(rts, 1, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 1, 0);
      ssSetInputPortFrameData(rts, 1, 0);
      ssSetInputPortUnit(rts, 1, 0);
      ssSetInputPortIsContinuousQuantity(rts, 1, 0);
      ssSetOutputPortWidthAsInt(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetOutputPortUnit(rts, 0, 0);
      ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: microrrede_v8/<S924>/S-Function (sfun_discreteVariableDelay) */
    {
      SimStruct *rts = microrrede_v8_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod = microrrede_v8_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset = microrrede_v8_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = microrrede_v8_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &microrrede_v8_M->NonInlinedSFcns.blkInfo2[5]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &microrrede_v8_M->NonInlinedSFcns.inputOutputPortInfo2[5]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, microrrede_v8_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &microrrede_v8_M->NonInlinedSFcns.methods2[5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &microrrede_v8_M->NonInlinedSFcns.methods3[5]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &microrrede_v8_M->NonInlinedSFcns.methods4[5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &microrrede_v8_M->NonInlinedSFcns.statesInfo2[5]);
        ssSetPeriodicStatesInfo(rts,
          &microrrede_v8_M->NonInlinedSFcns.periodicStatesInfo[5]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn5.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn5.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn5.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn5.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &microrrede_v8_M->NonInlinedSFcns.Sfcn5.UPtrs0;
          sfcnUPtrs[0] = &microrrede_v8_B.Integ4_je;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &microrrede_v8_M->NonInlinedSFcns.Sfcn5.UPtrs1;
          sfcnUPtrs[0] = &microrrede_v8_B.Delay_j;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidthAsInt(rts, 1, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn5.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn5.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &microrrede_v8_B.SFunction_a));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PLL/Model/Automatic Gain Control/Fundamental (PLL-Driven)/Mean (Variable Frequency)2/Model/Discrete Variable Time Delay/S-Function");
      ssSetRTModel(rts,microrrede_v8_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)microrrede_v8_ConstP.SFunction_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)microrrede_v8_ConstP.SFunction_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)microrrede_v8_ConstP.SFunction_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)microrrede_v8_ConstP.SFunction_P4_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &microrrede_v8_DW.SFunction_RWORK_pf);
      ssSetPWork(rts, (void **) &microrrede_v8_DW.SFunction_PWORK_e5[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn5.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn5.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 2);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &microrrede_v8_DW.SFunction_RWORK_pf);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 1, 2);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &microrrede_v8_DW.SFunction_PWORK_e5[0]);
      }

      /* registration */
      sfun_discreteVariableDelay(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 4.166667E-6);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidthAsInt(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetInputPortUnit(rts, 0, 0);
      ssSetInputPortIsContinuousQuantity(rts, 0, 0);
      ssSetInputPortWidthAsInt(rts, 1, 1);
      ssSetInputPortDataType(rts, 1, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 1, 0);
      ssSetInputPortFrameData(rts, 1, 0);
      ssSetInputPortUnit(rts, 1, 0);
      ssSetInputPortIsContinuousQuantity(rts, 1, 0);
      ssSetOutputPortWidthAsInt(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetOutputPortUnit(rts, 0, 0);
      ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: microrrede_v8/<S998>/State-Space (sfun_spssw_discc_DSS) */
    {
      SimStruct *rts = microrrede_v8_M->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod = microrrede_v8_M->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset = microrrede_v8_M->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = microrrede_v8_M->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &microrrede_v8_M->NonInlinedSFcns.blkInfo2[6]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &microrrede_v8_M->NonInlinedSFcns.inputOutputPortInfo2[6]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, microrrede_v8_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &microrrede_v8_M->NonInlinedSFcns.methods2[6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &microrrede_v8_M->NonInlinedSFcns.methods3[6]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &microrrede_v8_M->NonInlinedSFcns.methods4[6]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &microrrede_v8_M->NonInlinedSFcns.statesInfo2[6]);
        ssSetPeriodicStatesInfo(rts,
          &microrrede_v8_M->NonInlinedSFcns.periodicStatesInfo[6]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 3);
        ssSetPortInfoForInputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn6.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn6.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn6.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        ssSetInputPortUnit(rts, 2, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn6.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);
        ssSetInputPortIsContinuousQuantity(rts, 2, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &microrrede_v8_M->NonInlinedSFcns.Sfcn6.UPtrs0;

          {
            int_T i1;
            const real_T *u0 = microrrede_v8_ConstP.SwitchCurrents_Value;
            for (i1=0; i1 < 25; i1++) {
              sfcnUPtrs[i1] = &u0[i1];
            }

            sfcnUPtrs[25] = ((const real_T*) &microrrede_v8_RGND);
            sfcnUPtrs[26] = ((const real_T*) &microrrede_v8_RGND);
            sfcnUPtrs[27] = ((const real_T*) &microrrede_v8_RGND);
            sfcnUPtrs[28] = ((const real_T*) &microrrede_v8_RGND);
            sfcnUPtrs[29] = ((const real_T*) &microrrede_v8_RGND);
            sfcnUPtrs[30] = ((const real_T*) &microrrede_v8_RGND);
            sfcnUPtrs[31] = ((const real_T*) &microrrede_v8_RGND);
            sfcnUPtrs[32] = ((const real_T*) &microrrede_v8_RGND);
            sfcnUPtrs[33] = ((const real_T*) &microrrede_v8_RGND);
            sfcnUPtrs[34] = ((const real_T*) &microrrede_v8_RGND);
            sfcnUPtrs[35] = ((const real_T*) &microrrede_v8_RGND);
            sfcnUPtrs[36] = ((const real_T*) &microrrede_v8_RGND);
            sfcnUPtrs[37] = ((const real_T*) &microrrede_v8_RGND);
            sfcnUPtrs[38] = ((const real_T*) &microrrede_v8_RGND);
            sfcnUPtrs[39] = ((const real_T*) &microrrede_v8_RGND);
            sfcnUPtrs[40] = ((const real_T*) &microrrede_v8_RGND);
            sfcnUPtrs[41] = &microrrede_v8_B.Switch2;
            sfcnUPtrs[42] = &microrrede_v8_B.UnitDelay;
            sfcnUPtrs[43] = &microrrede_v8_B.IL;
            sfcnUPtrs[44] = &microrrede_v8_B.UnitDelay_i;
            sfcnUPtrs[45] = &microrrede_v8_B.IL_f;
            sfcnUPtrs[46] = &microrrede_v8_B.UnitDelay_f;
            sfcnUPtrs[47] = &microrrede_v8_B.IL_b;
            sfcnUPtrs[48] = &microrrede_v8_B.SineWaveA;
            sfcnUPtrs[49] = &microrrede_v8_B.SineWaveB;
            sfcnUPtrs[50] = &microrrede_v8_B.SineWaveC;
            sfcnUPtrs[51] = &microrrede_v8_ConstP.pooled19;
            sfcnUPtrs[52] = &microrrede_v8_ConstP.pooled19;
            sfcnUPtrs[53] = &microrrede_v8_ConstP.pooled19;
            sfcnUPtrs[54] = ((const real_T*) &microrrede_v8_RGND);
            sfcnUPtrs[55] = ((const real_T*) &microrrede_v8_RGND);
            sfcnUPtrs[56] = ((const real_T*) &microrrede_v8_RGND);
          }

          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 57);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &microrrede_v8_M->NonInlinedSFcns.Sfcn6.UPtrs1;
          sfcnUPtrs[0] = &microrrede_v8_U.XCBR_CC_1_in;
          sfcnUPtrs[1] = &microrrede_v8_U.XCBR_CC_2_in;
          sfcnUPtrs[2] = &microrrede_v8_U.XCBR_CC_3_in;
          sfcnUPtrs[3] = &microrrede_v8_U.XCBR_CC_1_in;
          sfcnUPtrs[4] = &microrrede_v8_U.XCBR_CC_2_in;
          sfcnUPtrs[5] = &microrrede_v8_U.XCBR_CC_3_in;
          sfcnUPtrs[6] = &microrrede_v8_B.DataTypeConversion_h;
          sfcnUPtrs[7] = &microrrede_v8_B.DataTypeConversion_hq;
          sfcnUPtrs[8] = &microrrede_v8_B.Switch3_b;
          sfcnUPtrs[9] = &microrrede_v8_B.Switch3_p;
          sfcnUPtrs[10] = &microrrede_v8_B.Switch3_kf;
          sfcnUPtrs[11] = &microrrede_v8_B.Switch3_e;
          sfcnUPtrs[12] = &microrrede_v8_B.Switch3_bx;
          sfcnUPtrs[13] = &microrrede_v8_B.Switch3;
          sfcnUPtrs[14] = &microrrede_v8_B.Switch3_d;
          sfcnUPtrs[15] = &microrrede_v8_B.Switch3_k;
          sfcnUPtrs[16] = &microrrede_v8_B.Switch3_g;
          sfcnUPtrs[17] = ((const real_T*) &microrrede_v8_RGND);
          sfcnUPtrs[18] = ((const real_T*) &microrrede_v8_RGND);
          sfcnUPtrs[19] = ((const real_T*) &microrrede_v8_RGND);
          sfcnUPtrs[20] = ((const real_T*) &microrrede_v8_RGND);
          sfcnUPtrs[21] = ((const real_T*) &microrrede_v8_RGND);
          sfcnUPtrs[22] = &microrrede_v8_B.DataTypeConversion;
          sfcnUPtrs[23] = &microrrede_v8_B.DataTypeConversion_f;
          sfcnUPtrs[24] = &microrrede_v8_B.DataTypeConversion_a;
          sfcnUPtrs[25] = &microrrede_v8_B.DataTypeConversion_i[0];
          sfcnUPtrs[26] = &microrrede_v8_B.DataTypeConversion_i[1];
          sfcnUPtrs[27] = &microrrede_v8_B.DataTypeConversion_i[2];
          sfcnUPtrs[28] = &microrrede_v8_B.DataTypeConversion_i[3];
          sfcnUPtrs[29] = &microrrede_v8_B.DataTypeConversion_g[0];
          sfcnUPtrs[30] = &microrrede_v8_B.DataTypeConversion_g[1];
          sfcnUPtrs[31] = &microrrede_v8_B.DataTypeConversion_g[2];
          sfcnUPtrs[32] = &microrrede_v8_B.DataTypeConversion_g[3];
          sfcnUPtrs[33] = &microrrede_v8_B.DataTypeConversion_m[0];
          sfcnUPtrs[34] = &microrrede_v8_B.DataTypeConversion_m[1];
          sfcnUPtrs[35] = &microrrede_v8_B.DataTypeConversion_m[2];
          sfcnUPtrs[36] = &microrrede_v8_B.DataTypeConversion_m[3];
          sfcnUPtrs[37] = &microrrede_v8_B.DataTypeConversion_ad[0];
          sfcnUPtrs[38] = &microrrede_v8_B.DataTypeConversion_ad[1];
          sfcnUPtrs[39] = &microrrede_v8_B.DataTypeConversion_ad[2];
          sfcnUPtrs[40] = &microrrede_v8_B.DataTypeConversion_ad[3];
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidthAsInt(rts, 1, 41);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &microrrede_v8_M->NonInlinedSFcns.Sfcn6.UPtrs2;
          sfcnUPtrs[0] = microrrede_v8_B.Sum;
          sfcnUPtrs[1] = &microrrede_v8_B.Sum[1];
          sfcnUPtrs[2] = &microrrede_v8_B.Sum[2];
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidthAsInt(rts, 2, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 3);
        _ssSetPortInfo2ForOutputUnits(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn6.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        ssSetOutputPortUnit(rts, 1, 0);
        ssSetOutputPortUnit(rts, 2, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn6.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 1, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 2, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 85);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            microrrede_v8_B.StateSpace_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidthAsInt(rts, 1, 41);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            microrrede_v8_B.StateSpace_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidthAsInt(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *)
            &microrrede_v8_B.StateSpace_o3));
        }
      }

      /* states */
      ssSetDiscStates(rts, (real_T *) &microrrede_v8_DW.StateSpace_DSTATE[0]);

      /* path info */
      ssSetModelName(rts, "State-Space");
      ssSetPath(rts, "microrrede_v8/powergui/EquivalentModel1/State-Space");
      ssSetRTModel(rts,microrrede_v8_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 24);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)microrrede_v8_ConstP.SFunction_P2_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)microrrede_v8_ConstP.StateSpace_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)microrrede_v8_ConstP.StateSpace_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)microrrede_v8_ConstP.StateSpace_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)microrrede_v8_ConstP.StateSpace_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)microrrede_v8_ConstP.StateSpace_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)microrrede_v8_ConstP.SFunction_P3_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)microrrede_v8_ConstP.StateSpace_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)
                       microrrede_v8_ConstInitP.StateSpace_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)
                       microrrede_v8_ConstP.StateSpace_P10_Size);
        ssSetSFcnParam(rts, 10, (mxArray*)
                       microrrede_v8_ConstP.StateSpace_P11_Size);
        ssSetSFcnParam(rts, 11, (mxArray*)
                       microrrede_v8_ConstInitP.StateSpace_P9_Size);
        ssSetSFcnParam(rts, 12, (mxArray*)
                       microrrede_v8_ConstP.StateSpace_P13_Size);
        ssSetSFcnParam(rts, 13, (mxArray*)
                       microrrede_v8_ConstP.StateSpace_P13_Size);
        ssSetSFcnParam(rts, 14, (mxArray*)
                       microrrede_v8_ConstInitP.StateSpace_P9_Size);
        ssSetSFcnParam(rts, 15, (mxArray*)
                       microrrede_v8_ConstP.StateSpace_P16_Size);
        ssSetSFcnParam(rts, 16, (mxArray*)
                       microrrede_v8_ConstP.StateSpace_P17_Size);
        ssSetSFcnParam(rts, 17, (mxArray*)
                       microrrede_v8_ConstP.StateSpace_P18_Size);
        ssSetSFcnParam(rts, 18, (mxArray*)microrrede_v8_ConstP.SFunction_P3_Size);
        ssSetSFcnParam(rts, 19, (mxArray*)
                       microrrede_v8_ConstP.StateSpace_P20_Size);
        ssSetSFcnParam(rts, 20, (mxArray*)
                       microrrede_v8_ConstP.StateSpace_P21_Size);
        ssSetSFcnParam(rts, 21, (mxArray*)
                       microrrede_v8_ConstP.StateSpace_P22_Size);
        ssSetSFcnParam(rts, 22, (mxArray*)
                       microrrede_v8_ConstP.StateSpace_P23_Size);
        ssSetSFcnParam(rts, 23, (mxArray*)microrrede_v8_ConstP.SFunction_P4_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &microrrede_v8_DW.StateSpace_RWORK);
      ssSetIWork(rts, (int_T *) &microrrede_v8_DW.StateSpace_IWORK[0]);
      ssSetPWork(rts, (void **) &microrrede_v8_DW.StateSpace_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn6.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn6.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 4);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &microrrede_v8_DW.StateSpace_RWORK);

        /* IWORK */
        ssSetDWorkWidthAsInt(rts, 1, 12);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &microrrede_v8_DW.StateSpace_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 2, 65);
        ssSetDWorkDataType(rts, 2,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 2, 0);
        ssSetDWork(rts, 2, &microrrede_v8_DW.StateSpace_PWORK[0]);

        /* DSTATE */
        ssSetDWorkWidthAsInt(rts, 3, 28);
        ssSetDWorkDataType(rts, 3,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 3, 0);
        ssSetDWorkUsedAsDState(rts, 3, 1);
        ssSetDWork(rts, 3, &microrrede_v8_DW.StateSpace_DSTATE[0]);
      }

      /* registration */
      sfun_spssw_discc_DSS(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 4.166667E-6);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetInputPortConnected(rts, 2, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 2, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
      ssSetInputPortBufferDstPort(rts, 2, -1);
    }

    /* Level2 S-Function Block: microrrede_v8/<S242>/S-Function (sfun_discreteVariableDelay) */
    {
      SimStruct *rts = microrrede_v8_M->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod = microrrede_v8_M->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset = microrrede_v8_M->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap = microrrede_v8_M->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &microrrede_v8_M->NonInlinedSFcns.blkInfo2[7]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &microrrede_v8_M->NonInlinedSFcns.inputOutputPortInfo2[7]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, microrrede_v8_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &microrrede_v8_M->NonInlinedSFcns.methods2[7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &microrrede_v8_M->NonInlinedSFcns.methods3[7]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &microrrede_v8_M->NonInlinedSFcns.methods4[7]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &microrrede_v8_M->NonInlinedSFcns.statesInfo2[7]);
        ssSetPeriodicStatesInfo(rts,
          &microrrede_v8_M->NonInlinedSFcns.periodicStatesInfo[7]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn7.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn7.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn7.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn7.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &microrrede_v8_M->NonInlinedSFcns.Sfcn7.UPtrs0;
          sfcnUPtrs[0] = &microrrede_v8_B.Integ4;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &microrrede_v8_M->NonInlinedSFcns.Sfcn7.UPtrs1;
          sfcnUPtrs[0] = &microrrede_v8_ConstP.pooled59;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidthAsInt(rts, 1, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn7.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn7.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &microrrede_v8_B.SFunction));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/Mean/Model/Discrete Variable Time Delay/S-Function");
      ssSetRTModel(rts,microrrede_v8_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       microrrede_v8_ConstP.SFunction_P1_Size_e);
        ssSetSFcnParam(rts, 1, (mxArray*)microrrede_v8_ConstP.SFunction_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)microrrede_v8_ConstP.SFunction_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)microrrede_v8_ConstP.SFunction_P4_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &microrrede_v8_DW.SFunction_RWORK);
      ssSetPWork(rts, (void **) &microrrede_v8_DW.SFunction_PWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn7.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn7.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 2);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &microrrede_v8_DW.SFunction_RWORK);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 1, 2);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &microrrede_v8_DW.SFunction_PWORK[0]);
      }

      /* registration */
      sfun_discreteVariableDelay(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 4.166667E-6);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidthAsInt(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetInputPortUnit(rts, 0, 0);
      ssSetInputPortIsContinuousQuantity(rts, 0, 0);
      ssSetInputPortWidthAsInt(rts, 1, 1);
      ssSetInputPortDataType(rts, 1, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 1, 0);
      ssSetInputPortFrameData(rts, 1, 0);
      ssSetInputPortUnit(rts, 1, 0);
      ssSetInputPortIsContinuousQuantity(rts, 1, 0);
      ssSetOutputPortWidthAsInt(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetOutputPortUnit(rts, 0, 0);
      ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: microrrede_v8/<S313>/S-Function (sfun_discreteVariableDelay) */
    {
      SimStruct *rts = microrrede_v8_M->childSfunctions[8];

      /* timing info */
      time_T *sfcnPeriod = microrrede_v8_M->NonInlinedSFcns.Sfcn8.sfcnPeriod;
      time_T *sfcnOffset = microrrede_v8_M->NonInlinedSFcns.Sfcn8.sfcnOffset;
      int_T *sfcnTsMap = microrrede_v8_M->NonInlinedSFcns.Sfcn8.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &microrrede_v8_M->NonInlinedSFcns.blkInfo2[8]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &microrrede_v8_M->NonInlinedSFcns.inputOutputPortInfo2[8]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, microrrede_v8_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &microrrede_v8_M->NonInlinedSFcns.methods2[8]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &microrrede_v8_M->NonInlinedSFcns.methods3[8]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &microrrede_v8_M->NonInlinedSFcns.methods4[8]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &microrrede_v8_M->NonInlinedSFcns.statesInfo2[8]);
        ssSetPeriodicStatesInfo(rts,
          &microrrede_v8_M->NonInlinedSFcns.periodicStatesInfo[8]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn8.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn8.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn8.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn8.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &microrrede_v8_M->NonInlinedSFcns.Sfcn8.UPtrs0;
          sfcnUPtrs[0] = (real_T*)&microrrede_v8_ConstB.Gain2;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &microrrede_v8_M->NonInlinedSFcns.Sfcn8.UPtrs1;
          sfcnUPtrs[0] = &microrrede_v8_B.Gain;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidthAsInt(rts, 1, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn8.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn8.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn8.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn8.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &microrrede_v8_B.SFunction_f));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/Subsystem/Discrete Variable Time Delay/S-Function");
      ssSetRTModel(rts,microrrede_v8_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn8.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)microrrede_v8_ConstP.SFunction_P4_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)microrrede_v8_ConstP.SFunction_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)microrrede_v8_ConstP.SFunction_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)microrrede_v8_ConstP.SFunction_P4_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &microrrede_v8_DW.SFunction_RWORK_d);
      ssSetPWork(rts, (void **) &microrrede_v8_DW.SFunction_PWORK_g[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn8.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn8.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 2);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &microrrede_v8_DW.SFunction_RWORK_d);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 1, 2);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &microrrede_v8_DW.SFunction_PWORK_g[0]);
      }

      /* registration */
      sfun_discreteVariableDelay(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 4.166667E-6);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidthAsInt(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetInputPortUnit(rts, 0, 0);
      ssSetInputPortIsContinuousQuantity(rts, 0, 0);
      ssSetInputPortWidthAsInt(rts, 1, 1);
      ssSetInputPortDataType(rts, 1, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 1, 0);
      ssSetInputPortFrameData(rts, 1, 0);
      ssSetInputPortUnit(rts, 1, 0);
      ssSetInputPortIsContinuousQuantity(rts, 1, 0);
      ssSetOutputPortWidthAsInt(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetOutputPortUnit(rts, 0, 0);
      ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: microrrede_v8/<S237>/S-Function (sfun_discreteVariableDelay) */
    {
      SimStruct *rts = microrrede_v8_M->childSfunctions[9];

      /* timing info */
      time_T *sfcnPeriod = microrrede_v8_M->NonInlinedSFcns.Sfcn9.sfcnPeriod;
      time_T *sfcnOffset = microrrede_v8_M->NonInlinedSFcns.Sfcn9.sfcnOffset;
      int_T *sfcnTsMap = microrrede_v8_M->NonInlinedSFcns.Sfcn9.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &microrrede_v8_M->NonInlinedSFcns.blkInfo2[9]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &microrrede_v8_M->NonInlinedSFcns.inputOutputPortInfo2[9]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, microrrede_v8_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &microrrede_v8_M->NonInlinedSFcns.methods2[9]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &microrrede_v8_M->NonInlinedSFcns.methods3[9]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &microrrede_v8_M->NonInlinedSFcns.methods4[9]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &microrrede_v8_M->NonInlinedSFcns.statesInfo2[9]);
        ssSetPeriodicStatesInfo(rts,
          &microrrede_v8_M->NonInlinedSFcns.periodicStatesInfo[9]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn9.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn9.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn9.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn9.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &microrrede_v8_M->NonInlinedSFcns.Sfcn9.UPtrs0;
          sfcnUPtrs[0] = &microrrede_v8_B.Integ4_p;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &microrrede_v8_M->NonInlinedSFcns.Sfcn9.UPtrs1;
          sfcnUPtrs[0] = &microrrede_v8_B.Delay;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidthAsInt(rts, 1, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn9.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn9.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn9.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn9.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &microrrede_v8_B.SFunction_o));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/Fundamental (PLL-Driven)/Mean (Variable Frequency)1/Model/Discrete Variable Time Delay/S-Function");
      ssSetRTModel(rts,microrrede_v8_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn9.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)microrrede_v8_ConstP.SFunction_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)microrrede_v8_ConstP.SFunction_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)microrrede_v8_ConstP.SFunction_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)microrrede_v8_ConstP.SFunction_P4_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &microrrede_v8_DW.SFunction_RWORK_l);
      ssSetPWork(rts, (void **) &microrrede_v8_DW.SFunction_PWORK_j[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn9.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn9.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 2);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &microrrede_v8_DW.SFunction_RWORK_l);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 1, 2);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &microrrede_v8_DW.SFunction_PWORK_j[0]);
      }

      /* registration */
      sfun_discreteVariableDelay(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 4.166667E-6);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidthAsInt(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetInputPortUnit(rts, 0, 0);
      ssSetInputPortIsContinuousQuantity(rts, 0, 0);
      ssSetInputPortWidthAsInt(rts, 1, 1);
      ssSetInputPortDataType(rts, 1, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 1, 0);
      ssSetInputPortFrameData(rts, 1, 0);
      ssSetInputPortUnit(rts, 1, 0);
      ssSetInputPortIsContinuousQuantity(rts, 1, 0);
      ssSetOutputPortWidthAsInt(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetOutputPortUnit(rts, 0, 0);
      ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: microrrede_v8/<S240>/S-Function (sfun_discreteVariableDelay) */
    {
      SimStruct *rts = microrrede_v8_M->childSfunctions[10];

      /* timing info */
      time_T *sfcnPeriod = microrrede_v8_M->NonInlinedSFcns.Sfcn10.sfcnPeriod;
      time_T *sfcnOffset = microrrede_v8_M->NonInlinedSFcns.Sfcn10.sfcnOffset;
      int_T *sfcnTsMap = microrrede_v8_M->NonInlinedSFcns.Sfcn10.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &microrrede_v8_M->NonInlinedSFcns.blkInfo2[10]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &microrrede_v8_M->NonInlinedSFcns.inputOutputPortInfo2[10]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, microrrede_v8_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &microrrede_v8_M->NonInlinedSFcns.methods2[10]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &microrrede_v8_M->NonInlinedSFcns.methods3[10]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &microrrede_v8_M->NonInlinedSFcns.methods4[10]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &microrrede_v8_M->NonInlinedSFcns.statesInfo2[10]);
        ssSetPeriodicStatesInfo(rts,
          &microrrede_v8_M->NonInlinedSFcns.periodicStatesInfo[10]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn10.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn10.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn10.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn10.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &microrrede_v8_M->NonInlinedSFcns.Sfcn10.UPtrs0;
          sfcnUPtrs[0] = &microrrede_v8_B.Integ4_e;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &microrrede_v8_M->NonInlinedSFcns.Sfcn10.UPtrs1;
          sfcnUPtrs[0] = &microrrede_v8_B.Delay_g;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidthAsInt(rts, 1, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn10.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn10.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn10.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn10.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &microrrede_v8_B.SFunction_e));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/Fundamental (PLL-Driven)/Mean (Variable Frequency)2/Model/Discrete Variable Time Delay/S-Function");
      ssSetRTModel(rts,microrrede_v8_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn10.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)microrrede_v8_ConstP.SFunction_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)microrrede_v8_ConstP.SFunction_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)microrrede_v8_ConstP.SFunction_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)microrrede_v8_ConstP.SFunction_P4_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &microrrede_v8_DW.SFunction_RWORK_c);
      ssSetPWork(rts, (void **) &microrrede_v8_DW.SFunction_PWORK_e[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn10.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn10.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 2);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &microrrede_v8_DW.SFunction_RWORK_c);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 1, 2);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &microrrede_v8_DW.SFunction_PWORK_e[0]);
      }

      /* registration */
      sfun_discreteVariableDelay(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 4.166667E-6);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidthAsInt(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetInputPortUnit(rts, 0, 0);
      ssSetInputPortIsContinuousQuantity(rts, 0, 0);
      ssSetInputPortWidthAsInt(rts, 1, 1);
      ssSetInputPortDataType(rts, 1, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 1, 0);
      ssSetInputPortFrameData(rts, 1, 0);
      ssSetInputPortUnit(rts, 1, 0);
      ssSetInputPortIsContinuousQuantity(rts, 1, 0);
      ssSetOutputPortWidthAsInt(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetOutputPortUnit(rts, 0, 0);
      ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: microrrede_v8/<S307>/S-Function (sfun_discreteVariableDelay) */
    {
      SimStruct *rts = microrrede_v8_M->childSfunctions[11];

      /* timing info */
      time_T *sfcnPeriod = microrrede_v8_M->NonInlinedSFcns.Sfcn11.sfcnPeriod;
      time_T *sfcnOffset = microrrede_v8_M->NonInlinedSFcns.Sfcn11.sfcnOffset;
      int_T *sfcnTsMap = microrrede_v8_M->NonInlinedSFcns.Sfcn11.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &microrrede_v8_M->NonInlinedSFcns.blkInfo2[11]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &microrrede_v8_M->NonInlinedSFcns.inputOutputPortInfo2[11]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, microrrede_v8_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &microrrede_v8_M->NonInlinedSFcns.methods2[11]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &microrrede_v8_M->NonInlinedSFcns.methods3[11]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &microrrede_v8_M->NonInlinedSFcns.methods4[11]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &microrrede_v8_M->NonInlinedSFcns.statesInfo2[11]);
        ssSetPeriodicStatesInfo(rts,
          &microrrede_v8_M->NonInlinedSFcns.periodicStatesInfo[11]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn11.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn11.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn11.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn11.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &microrrede_v8_M->NonInlinedSFcns.Sfcn11.UPtrs0;
          sfcnUPtrs[0] = &microrrede_v8_B.Integ4_ep;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &microrrede_v8_M->NonInlinedSFcns.Sfcn11.UPtrs1;
          sfcnUPtrs[0] = &microrrede_v8_B.Delay_c;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidthAsInt(rts, 1, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn11.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn11.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn11.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn11.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &microrrede_v8_B.SFunction_m));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PLL/Model/Mean (Variable Frequency)/Model/Discrete Variable Time Delay/S-Function");
      ssSetRTModel(rts,microrrede_v8_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn11.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)microrrede_v8_ConstP.SFunction_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)microrrede_v8_ConstP.SFunction_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)microrrede_v8_ConstP.SFunction_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)microrrede_v8_ConstP.SFunction_P4_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &microrrede_v8_DW.SFunction_RWORK_j);
      ssSetPWork(rts, (void **) &microrrede_v8_DW.SFunction_PWORK_p[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn11.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn11.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 2);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &microrrede_v8_DW.SFunction_RWORK_j);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 1, 2);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &microrrede_v8_DW.SFunction_PWORK_p[0]);
      }

      /* registration */
      sfun_discreteVariableDelay(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 4.166667E-6);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidthAsInt(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetInputPortUnit(rts, 0, 0);
      ssSetInputPortIsContinuousQuantity(rts, 0, 0);
      ssSetInputPortWidthAsInt(rts, 1, 1);
      ssSetInputPortDataType(rts, 1, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 1, 0);
      ssSetInputPortFrameData(rts, 1, 0);
      ssSetInputPortUnit(rts, 1, 0);
      ssSetInputPortIsContinuousQuantity(rts, 1, 0);
      ssSetOutputPortWidthAsInt(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetOutputPortUnit(rts, 0, 0);
      ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: microrrede_v8/<S862>/S-Function (sfun_discreteVariableDelay) */
    {
      SimStruct *rts = microrrede_v8_M->childSfunctions[12];

      /* timing info */
      time_T *sfcnPeriod = microrrede_v8_M->NonInlinedSFcns.Sfcn12.sfcnPeriod;
      time_T *sfcnOffset = microrrede_v8_M->NonInlinedSFcns.Sfcn12.sfcnOffset;
      int_T *sfcnTsMap = microrrede_v8_M->NonInlinedSFcns.Sfcn12.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &microrrede_v8_M->NonInlinedSFcns.blkInfo2[12]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &microrrede_v8_M->NonInlinedSFcns.inputOutputPortInfo2[12]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, microrrede_v8_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &microrrede_v8_M->NonInlinedSFcns.methods2[12]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &microrrede_v8_M->NonInlinedSFcns.methods3[12]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &microrrede_v8_M->NonInlinedSFcns.methods4[12]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &microrrede_v8_M->NonInlinedSFcns.statesInfo2[12]);
        ssSetPeriodicStatesInfo(rts,
          &microrrede_v8_M->NonInlinedSFcns.periodicStatesInfo[12]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn12.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn12.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn12.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn12.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &microrrede_v8_M->NonInlinedSFcns.Sfcn12.UPtrs0;
          sfcnUPtrs[0] = &microrrede_v8_B.Integ4_b;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &microrrede_v8_M->NonInlinedSFcns.Sfcn12.UPtrs1;
          sfcnUPtrs[0] = &microrrede_v8_ConstP.pooled59;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidthAsInt(rts, 1, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn12.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn12.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn12.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn12.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &microrrede_v8_B.SFunction_j));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "microrrede_v8/inversor Replus/Controle Inversor /Subsystem/Mean/Model/Discrete Variable Time Delay/S-Function");
      ssSetRTModel(rts,microrrede_v8_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn12.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       microrrede_v8_ConstP.SFunction_P1_Size_e);
        ssSetSFcnParam(rts, 1, (mxArray*)microrrede_v8_ConstP.SFunction_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)microrrede_v8_ConstP.SFunction_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)microrrede_v8_ConstP.SFunction_P4_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &microrrede_v8_DW.SFunction_RWORK_f);
      ssSetPWork(rts, (void **) &microrrede_v8_DW.SFunction_PWORK_h[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn12.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn12.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 2);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &microrrede_v8_DW.SFunction_RWORK_f);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 1, 2);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &microrrede_v8_DW.SFunction_PWORK_h[0]);
      }

      /* registration */
      sfun_discreteVariableDelay(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 4.166667E-6);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidthAsInt(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetInputPortUnit(rts, 0, 0);
      ssSetInputPortIsContinuousQuantity(rts, 0, 0);
      ssSetInputPortWidthAsInt(rts, 1, 1);
      ssSetInputPortDataType(rts, 1, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 1, 0);
      ssSetInputPortFrameData(rts, 1, 0);
      ssSetInputPortUnit(rts, 1, 0);
      ssSetInputPortIsContinuousQuantity(rts, 1, 0);
      ssSetOutputPortWidthAsInt(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetOutputPortUnit(rts, 0, 0);
      ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: microrrede_v8/<S933>/S-Function (sfun_discreteVariableDelay) */
    {
      SimStruct *rts = microrrede_v8_M->childSfunctions[13];

      /* timing info */
      time_T *sfcnPeriod = microrrede_v8_M->NonInlinedSFcns.Sfcn13.sfcnPeriod;
      time_T *sfcnOffset = microrrede_v8_M->NonInlinedSFcns.Sfcn13.sfcnOffset;
      int_T *sfcnTsMap = microrrede_v8_M->NonInlinedSFcns.Sfcn13.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &microrrede_v8_M->NonInlinedSFcns.blkInfo2[13]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &microrrede_v8_M->NonInlinedSFcns.inputOutputPortInfo2[13]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, microrrede_v8_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &microrrede_v8_M->NonInlinedSFcns.methods2[13]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &microrrede_v8_M->NonInlinedSFcns.methods3[13]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &microrrede_v8_M->NonInlinedSFcns.methods4[13]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &microrrede_v8_M->NonInlinedSFcns.statesInfo2[13]);
        ssSetPeriodicStatesInfo(rts,
          &microrrede_v8_M->NonInlinedSFcns.periodicStatesInfo[13]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn13.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn13.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn13.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn13.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &microrrede_v8_M->NonInlinedSFcns.Sfcn13.UPtrs0;
          sfcnUPtrs[0] = (real_T*)&microrrede_v8_ConstB.Gain2_b;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &microrrede_v8_M->NonInlinedSFcns.Sfcn13.UPtrs1;
          sfcnUPtrs[0] = &microrrede_v8_B.Gain_m;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidthAsInt(rts, 1, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn13.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn13.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn13.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn13.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &microrrede_v8_B.SFunction_oz));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "microrrede_v8/inversor Replus/Controle Inversor /Subsystem/Subsystem/Discrete Variable Time Delay/S-Function");
      ssSetRTModel(rts,microrrede_v8_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn13.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)microrrede_v8_ConstP.SFunction_P4_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)microrrede_v8_ConstP.SFunction_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)microrrede_v8_ConstP.SFunction_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)microrrede_v8_ConstP.SFunction_P4_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &microrrede_v8_DW.SFunction_RWORK_p);
      ssSetPWork(rts, (void **) &microrrede_v8_DW.SFunction_PWORK_f[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn13.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn13.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 2);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &microrrede_v8_DW.SFunction_RWORK_p);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 1, 2);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &microrrede_v8_DW.SFunction_PWORK_f[0]);
      }

      /* registration */
      sfun_discreteVariableDelay(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 4.166667E-6);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidthAsInt(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetInputPortUnit(rts, 0, 0);
      ssSetInputPortIsContinuousQuantity(rts, 0, 0);
      ssSetInputPortWidthAsInt(rts, 1, 1);
      ssSetInputPortDataType(rts, 1, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 1, 0);
      ssSetInputPortFrameData(rts, 1, 0);
      ssSetInputPortUnit(rts, 1, 0);
      ssSetInputPortIsContinuousQuantity(rts, 1, 0);
      ssSetOutputPortWidthAsInt(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetOutputPortUnit(rts, 0, 0);
      ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: microrrede_v8/<S857>/S-Function (sfun_discreteVariableDelay) */
    {
      SimStruct *rts = microrrede_v8_M->childSfunctions[14];

      /* timing info */
      time_T *sfcnPeriod = microrrede_v8_M->NonInlinedSFcns.Sfcn14.sfcnPeriod;
      time_T *sfcnOffset = microrrede_v8_M->NonInlinedSFcns.Sfcn14.sfcnOffset;
      int_T *sfcnTsMap = microrrede_v8_M->NonInlinedSFcns.Sfcn14.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &microrrede_v8_M->NonInlinedSFcns.blkInfo2[14]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &microrrede_v8_M->NonInlinedSFcns.inputOutputPortInfo2[14]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, microrrede_v8_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &microrrede_v8_M->NonInlinedSFcns.methods2[14]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &microrrede_v8_M->NonInlinedSFcns.methods3[14]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &microrrede_v8_M->NonInlinedSFcns.methods4[14]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &microrrede_v8_M->NonInlinedSFcns.statesInfo2[14]);
        ssSetPeriodicStatesInfo(rts,
          &microrrede_v8_M->NonInlinedSFcns.periodicStatesInfo[14]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn14.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn14.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn14.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn14.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &microrrede_v8_M->NonInlinedSFcns.Sfcn14.UPtrs0;
          sfcnUPtrs[0] = &microrrede_v8_B.Integ4_j;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &microrrede_v8_M->NonInlinedSFcns.Sfcn14.UPtrs1;
          sfcnUPtrs[0] = &microrrede_v8_B.Delay_n;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidthAsInt(rts, 1, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn14.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn14.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn14.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn14.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &microrrede_v8_B.SFunction_g));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "microrrede_v8/inversor Replus/Controle Inversor /Subsystem/Fundamental (PLL-Driven)/Mean (Variable Frequency)1/Model/Discrete Variable Time Delay/S-Function");
      ssSetRTModel(rts,microrrede_v8_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn14.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)microrrede_v8_ConstP.SFunction_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)microrrede_v8_ConstP.SFunction_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)microrrede_v8_ConstP.SFunction_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)microrrede_v8_ConstP.SFunction_P4_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &microrrede_v8_DW.SFunction_RWORK_h);
      ssSetPWork(rts, (void **) &microrrede_v8_DW.SFunction_PWORK_n[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn14.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn14.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 2);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &microrrede_v8_DW.SFunction_RWORK_h);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 1, 2);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &microrrede_v8_DW.SFunction_PWORK_n[0]);
      }

      /* registration */
      sfun_discreteVariableDelay(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 4.166667E-6);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidthAsInt(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetInputPortUnit(rts, 0, 0);
      ssSetInputPortIsContinuousQuantity(rts, 0, 0);
      ssSetInputPortWidthAsInt(rts, 1, 1);
      ssSetInputPortDataType(rts, 1, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 1, 0);
      ssSetInputPortFrameData(rts, 1, 0);
      ssSetInputPortUnit(rts, 1, 0);
      ssSetInputPortIsContinuousQuantity(rts, 1, 0);
      ssSetOutputPortWidthAsInt(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetOutputPortUnit(rts, 0, 0);
      ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: microrrede_v8/<S860>/S-Function (sfun_discreteVariableDelay) */
    {
      SimStruct *rts = microrrede_v8_M->childSfunctions[15];

      /* timing info */
      time_T *sfcnPeriod = microrrede_v8_M->NonInlinedSFcns.Sfcn15.sfcnPeriod;
      time_T *sfcnOffset = microrrede_v8_M->NonInlinedSFcns.Sfcn15.sfcnOffset;
      int_T *sfcnTsMap = microrrede_v8_M->NonInlinedSFcns.Sfcn15.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &microrrede_v8_M->NonInlinedSFcns.blkInfo2[15]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &microrrede_v8_M->NonInlinedSFcns.inputOutputPortInfo2[15]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, microrrede_v8_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &microrrede_v8_M->NonInlinedSFcns.methods2[15]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &microrrede_v8_M->NonInlinedSFcns.methods3[15]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &microrrede_v8_M->NonInlinedSFcns.methods4[15]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &microrrede_v8_M->NonInlinedSFcns.statesInfo2[15]);
        ssSetPeriodicStatesInfo(rts,
          &microrrede_v8_M->NonInlinedSFcns.periodicStatesInfo[15]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn15.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn15.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn15.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn15.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &microrrede_v8_M->NonInlinedSFcns.Sfcn15.UPtrs0;
          sfcnUPtrs[0] = &microrrede_v8_B.Integ4_f;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &microrrede_v8_M->NonInlinedSFcns.Sfcn15.UPtrs1;
          sfcnUPtrs[0] = &microrrede_v8_B.Delay_i;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidthAsInt(rts, 1, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn15.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn15.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn15.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn15.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &microrrede_v8_B.SFunction_ed));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "microrrede_v8/inversor Replus/Controle Inversor /Subsystem/Fundamental (PLL-Driven)/Mean (Variable Frequency)2/Model/Discrete Variable Time Delay/S-Function");
      ssSetRTModel(rts,microrrede_v8_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn15.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)microrrede_v8_ConstP.SFunction_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)microrrede_v8_ConstP.SFunction_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)microrrede_v8_ConstP.SFunction_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)microrrede_v8_ConstP.SFunction_P4_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &microrrede_v8_DW.SFunction_RWORK_o);
      ssSetPWork(rts, (void **) &microrrede_v8_DW.SFunction_PWORK_fr[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn15.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn15.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 2);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &microrrede_v8_DW.SFunction_RWORK_o);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 1, 2);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &microrrede_v8_DW.SFunction_PWORK_fr[0]);
      }

      /* registration */
      sfun_discreteVariableDelay(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 4.166667E-6);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidthAsInt(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetInputPortUnit(rts, 0, 0);
      ssSetInputPortIsContinuousQuantity(rts, 0, 0);
      ssSetInputPortWidthAsInt(rts, 1, 1);
      ssSetInputPortDataType(rts, 1, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 1, 0);
      ssSetInputPortFrameData(rts, 1, 0);
      ssSetInputPortUnit(rts, 1, 0);
      ssSetInputPortIsContinuousQuantity(rts, 1, 0);
      ssSetOutputPortWidthAsInt(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetOutputPortUnit(rts, 0, 0);
      ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: microrrede_v8/<S927>/S-Function (sfun_discreteVariableDelay) */
    {
      SimStruct *rts = microrrede_v8_M->childSfunctions[16];

      /* timing info */
      time_T *sfcnPeriod = microrrede_v8_M->NonInlinedSFcns.Sfcn16.sfcnPeriod;
      time_T *sfcnOffset = microrrede_v8_M->NonInlinedSFcns.Sfcn16.sfcnOffset;
      int_T *sfcnTsMap = microrrede_v8_M->NonInlinedSFcns.Sfcn16.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &microrrede_v8_M->NonInlinedSFcns.blkInfo2[16]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &microrrede_v8_M->NonInlinedSFcns.inputOutputPortInfo2[16]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, microrrede_v8_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &microrrede_v8_M->NonInlinedSFcns.methods2[16]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &microrrede_v8_M->NonInlinedSFcns.methods3[16]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &microrrede_v8_M->NonInlinedSFcns.methods4[16]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &microrrede_v8_M->NonInlinedSFcns.statesInfo2[16]);
        ssSetPeriodicStatesInfo(rts,
          &microrrede_v8_M->NonInlinedSFcns.periodicStatesInfo[16]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn16.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn16.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn16.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn16.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &microrrede_v8_M->NonInlinedSFcns.Sfcn16.UPtrs0;
          sfcnUPtrs[0] = &microrrede_v8_B.Integ4_eu;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &microrrede_v8_M->NonInlinedSFcns.Sfcn16.UPtrs1;
          sfcnUPtrs[0] = &microrrede_v8_B.Delay_d;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidthAsInt(rts, 1, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn16.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn16.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn16.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn16.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &microrrede_v8_B.SFunction_gc));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PLL/Model/Mean (Variable Frequency)/Model/Discrete Variable Time Delay/S-Function");
      ssSetRTModel(rts,microrrede_v8_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn16.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)microrrede_v8_ConstP.SFunction_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)microrrede_v8_ConstP.SFunction_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)microrrede_v8_ConstP.SFunction_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)microrrede_v8_ConstP.SFunction_P4_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &microrrede_v8_DW.SFunction_RWORK_m);
      ssSetPWork(rts, (void **) &microrrede_v8_DW.SFunction_PWORK_b[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn16.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn16.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 2);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &microrrede_v8_DW.SFunction_RWORK_m);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 1, 2);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &microrrede_v8_DW.SFunction_PWORK_b[0]);
      }

      /* registration */
      sfun_discreteVariableDelay(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 4.166667E-6);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidthAsInt(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetInputPortUnit(rts, 0, 0);
      ssSetInputPortIsContinuousQuantity(rts, 0, 0);
      ssSetInputPortWidthAsInt(rts, 1, 1);
      ssSetInputPortDataType(rts, 1, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 1, 0);
      ssSetInputPortFrameData(rts, 1, 0);
      ssSetInputPortUnit(rts, 1, 0);
      ssSetInputPortIsContinuousQuantity(rts, 1, 0);
      ssSetOutputPortWidthAsInt(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetOutputPortUnit(rts, 0, 0);
      ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: microrrede_v8/<S671>/S-Function (sfun_discreteVariableDelay) */
    {
      SimStruct *rts = microrrede_v8_M->childSfunctions[17];

      /* timing info */
      time_T *sfcnPeriod = microrrede_v8_M->NonInlinedSFcns.Sfcn17.sfcnPeriod;
      time_T *sfcnOffset = microrrede_v8_M->NonInlinedSFcns.Sfcn17.sfcnOffset;
      int_T *sfcnTsMap = microrrede_v8_M->NonInlinedSFcns.Sfcn17.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &microrrede_v8_M->NonInlinedSFcns.blkInfo2[17]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &microrrede_v8_M->NonInlinedSFcns.inputOutputPortInfo2[17]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, microrrede_v8_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &microrrede_v8_M->NonInlinedSFcns.methods2[17]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &microrrede_v8_M->NonInlinedSFcns.methods3[17]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &microrrede_v8_M->NonInlinedSFcns.methods4[17]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &microrrede_v8_M->NonInlinedSFcns.statesInfo2[17]);
        ssSetPeriodicStatesInfo(rts,
          &microrrede_v8_M->NonInlinedSFcns.periodicStatesInfo[17]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn17.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn17.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn17.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn17.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &microrrede_v8_M->NonInlinedSFcns.Sfcn17.UPtrs0;
          sfcnUPtrs[0] = &microrrede_v8_B.Integ4_b5;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &microrrede_v8_M->NonInlinedSFcns.Sfcn17.UPtrs1;
          sfcnUPtrs[0] = &microrrede_v8_ConstP.pooled59;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidthAsInt(rts, 1, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn17.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn17.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn17.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn17.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &microrrede_v8_B.SFunction_mo));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "microrrede_v8/Inversor SMA ongrid/Mean1/Model/Discrete Variable Time Delay/S-Function");
      ssSetRTModel(rts,microrrede_v8_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn17.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       microrrede_v8_ConstP.SFunction_P1_Size_e);
        ssSetSFcnParam(rts, 1, (mxArray*)microrrede_v8_ConstP.SFunction_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)microrrede_v8_ConstP.SFunction_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)microrrede_v8_ConstP.SFunction_P4_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &microrrede_v8_DW.SFunction_RWORK_f5);
      ssSetPWork(rts, (void **) &microrrede_v8_DW.SFunction_PWORK_o[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn17.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn17.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 2);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &microrrede_v8_DW.SFunction_RWORK_f5);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 1, 2);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &microrrede_v8_DW.SFunction_PWORK_o[0]);
      }

      /* registration */
      sfun_discreteVariableDelay(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 4.166667E-6);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidthAsInt(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetInputPortUnit(rts, 0, 0);
      ssSetInputPortIsContinuousQuantity(rts, 0, 0);
      ssSetInputPortWidthAsInt(rts, 1, 1);
      ssSetInputPortDataType(rts, 1, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 1, 0);
      ssSetInputPortFrameData(rts, 1, 0);
      ssSetInputPortUnit(rts, 1, 0);
      ssSetInputPortIsContinuousQuantity(rts, 1, 0);
      ssSetOutputPortWidthAsInt(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetOutputPortUnit(rts, 0, 0);
      ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: microrrede_v8/<S544>/S-Function (sfun_discreteVariableDelay) */
    {
      SimStruct *rts = microrrede_v8_M->childSfunctions[18];

      /* timing info */
      time_T *sfcnPeriod = microrrede_v8_M->NonInlinedSFcns.Sfcn18.sfcnPeriod;
      time_T *sfcnOffset = microrrede_v8_M->NonInlinedSFcns.Sfcn18.sfcnOffset;
      int_T *sfcnTsMap = microrrede_v8_M->NonInlinedSFcns.Sfcn18.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &microrrede_v8_M->NonInlinedSFcns.blkInfo2[18]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &microrrede_v8_M->NonInlinedSFcns.inputOutputPortInfo2[18]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, microrrede_v8_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &microrrede_v8_M->NonInlinedSFcns.methods2[18]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &microrrede_v8_M->NonInlinedSFcns.methods3[18]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &microrrede_v8_M->NonInlinedSFcns.methods4[18]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &microrrede_v8_M->NonInlinedSFcns.statesInfo2[18]);
        ssSetPeriodicStatesInfo(rts,
          &microrrede_v8_M->NonInlinedSFcns.periodicStatesInfo[18]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn18.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn18.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn18.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn18.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &microrrede_v8_M->NonInlinedSFcns.Sfcn18.UPtrs0;
          sfcnUPtrs[0] = &microrrede_v8_B.Integ4_ps;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &microrrede_v8_M->NonInlinedSFcns.Sfcn18.UPtrs1;
          sfcnUPtrs[0] = &microrrede_v8_ConstP.pooled59;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidthAsInt(rts, 1, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn18.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn18.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn18.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn18.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &microrrede_v8_B.SFunction_k));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/Mean/Model/Discrete Variable Time Delay/S-Function");
      ssSetRTModel(rts,microrrede_v8_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn18.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       microrrede_v8_ConstP.SFunction_P1_Size_e);
        ssSetSFcnParam(rts, 1, (mxArray*)microrrede_v8_ConstP.SFunction_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)microrrede_v8_ConstP.SFunction_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)microrrede_v8_ConstP.SFunction_P4_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &microrrede_v8_DW.SFunction_RWORK_a);
      ssSetPWork(rts, (void **) &microrrede_v8_DW.SFunction_PWORK_c[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn18.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn18.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 2);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &microrrede_v8_DW.SFunction_RWORK_a);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 1, 2);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &microrrede_v8_DW.SFunction_PWORK_c[0]);
      }

      /* registration */
      sfun_discreteVariableDelay(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 4.166667E-6);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidthAsInt(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetInputPortUnit(rts, 0, 0);
      ssSetInputPortIsContinuousQuantity(rts, 0, 0);
      ssSetInputPortWidthAsInt(rts, 1, 1);
      ssSetInputPortDataType(rts, 1, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 1, 0);
      ssSetInputPortFrameData(rts, 1, 0);
      ssSetInputPortUnit(rts, 1, 0);
      ssSetInputPortIsContinuousQuantity(rts, 1, 0);
      ssSetOutputPortWidthAsInt(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetOutputPortUnit(rts, 0, 0);
      ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: microrrede_v8/<S615>/S-Function (sfun_discreteVariableDelay) */
    {
      SimStruct *rts = microrrede_v8_M->childSfunctions[19];

      /* timing info */
      time_T *sfcnPeriod = microrrede_v8_M->NonInlinedSFcns.Sfcn19.sfcnPeriod;
      time_T *sfcnOffset = microrrede_v8_M->NonInlinedSFcns.Sfcn19.sfcnOffset;
      int_T *sfcnTsMap = microrrede_v8_M->NonInlinedSFcns.Sfcn19.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &microrrede_v8_M->NonInlinedSFcns.blkInfo2[19]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &microrrede_v8_M->NonInlinedSFcns.inputOutputPortInfo2[19]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, microrrede_v8_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &microrrede_v8_M->NonInlinedSFcns.methods2[19]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &microrrede_v8_M->NonInlinedSFcns.methods3[19]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &microrrede_v8_M->NonInlinedSFcns.methods4[19]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &microrrede_v8_M->NonInlinedSFcns.statesInfo2[19]);
        ssSetPeriodicStatesInfo(rts,
          &microrrede_v8_M->NonInlinedSFcns.periodicStatesInfo[19]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn19.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn19.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn19.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn19.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &microrrede_v8_M->NonInlinedSFcns.Sfcn19.UPtrs0;
          sfcnUPtrs[0] = (real_T*)&microrrede_v8_ConstB.Gain2_f;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &microrrede_v8_M->NonInlinedSFcns.Sfcn19.UPtrs1;
          sfcnUPtrs[0] = &microrrede_v8_B.Gain_a;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidthAsInt(rts, 1, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn19.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn19.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn19.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn19.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &microrrede_v8_B.SFunction_gq));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/Subsystem/Discrete Variable Time Delay/S-Function");
      ssSetRTModel(rts,microrrede_v8_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn19.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)microrrede_v8_ConstP.SFunction_P4_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)microrrede_v8_ConstP.SFunction_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)microrrede_v8_ConstP.SFunction_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)microrrede_v8_ConstP.SFunction_P4_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &microrrede_v8_DW.SFunction_RWORK_g);
      ssSetPWork(rts, (void **) &microrrede_v8_DW.SFunction_PWORK_a[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn19.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn19.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 2);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &microrrede_v8_DW.SFunction_RWORK_g);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 1, 2);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &microrrede_v8_DW.SFunction_PWORK_a[0]);
      }

      /* registration */
      sfun_discreteVariableDelay(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 4.166667E-6);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidthAsInt(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetInputPortUnit(rts, 0, 0);
      ssSetInputPortIsContinuousQuantity(rts, 0, 0);
      ssSetInputPortWidthAsInt(rts, 1, 1);
      ssSetInputPortDataType(rts, 1, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 1, 0);
      ssSetInputPortFrameData(rts, 1, 0);
      ssSetInputPortUnit(rts, 1, 0);
      ssSetInputPortIsContinuousQuantity(rts, 1, 0);
      ssSetOutputPortWidthAsInt(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetOutputPortUnit(rts, 0, 0);
      ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: microrrede_v8/<S539>/S-Function (sfun_discreteVariableDelay) */
    {
      SimStruct *rts = microrrede_v8_M->childSfunctions[20];

      /* timing info */
      time_T *sfcnPeriod = microrrede_v8_M->NonInlinedSFcns.Sfcn20.sfcnPeriod;
      time_T *sfcnOffset = microrrede_v8_M->NonInlinedSFcns.Sfcn20.sfcnOffset;
      int_T *sfcnTsMap = microrrede_v8_M->NonInlinedSFcns.Sfcn20.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &microrrede_v8_M->NonInlinedSFcns.blkInfo2[20]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &microrrede_v8_M->NonInlinedSFcns.inputOutputPortInfo2[20]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, microrrede_v8_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &microrrede_v8_M->NonInlinedSFcns.methods2[20]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &microrrede_v8_M->NonInlinedSFcns.methods3[20]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &microrrede_v8_M->NonInlinedSFcns.methods4[20]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &microrrede_v8_M->NonInlinedSFcns.statesInfo2[20]);
        ssSetPeriodicStatesInfo(rts,
          &microrrede_v8_M->NonInlinedSFcns.periodicStatesInfo[20]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn20.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn20.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn20.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn20.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &microrrede_v8_M->NonInlinedSFcns.Sfcn20.UPtrs0;
          sfcnUPtrs[0] = &microrrede_v8_B.Integ4_c;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &microrrede_v8_M->NonInlinedSFcns.Sfcn20.UPtrs1;
          sfcnUPtrs[0] = &microrrede_v8_B.Delay_go;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidthAsInt(rts, 1, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn20.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn20.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn20.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn20.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &microrrede_v8_B.SFunction_o4));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/Fundamental (PLL-Driven)/Mean (Variable Frequency)1/Model/Discrete Variable Time Delay/S-Function");
      ssSetRTModel(rts,microrrede_v8_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn20.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)microrrede_v8_ConstP.SFunction_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)microrrede_v8_ConstP.SFunction_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)microrrede_v8_ConstP.SFunction_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)microrrede_v8_ConstP.SFunction_P4_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &microrrede_v8_DW.SFunction_RWORK_f0);
      ssSetPWork(rts, (void **) &microrrede_v8_DW.SFunction_PWORK_k[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn20.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn20.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 2);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &microrrede_v8_DW.SFunction_RWORK_f0);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 1, 2);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &microrrede_v8_DW.SFunction_PWORK_k[0]);
      }

      /* registration */
      sfun_discreteVariableDelay(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 4.166667E-6);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidthAsInt(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetInputPortUnit(rts, 0, 0);
      ssSetInputPortIsContinuousQuantity(rts, 0, 0);
      ssSetInputPortWidthAsInt(rts, 1, 1);
      ssSetInputPortDataType(rts, 1, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 1, 0);
      ssSetInputPortFrameData(rts, 1, 0);
      ssSetInputPortUnit(rts, 1, 0);
      ssSetInputPortIsContinuousQuantity(rts, 1, 0);
      ssSetOutputPortWidthAsInt(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetOutputPortUnit(rts, 0, 0);
      ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: microrrede_v8/<S542>/S-Function (sfun_discreteVariableDelay) */
    {
      SimStruct *rts = microrrede_v8_M->childSfunctions[21];

      /* timing info */
      time_T *sfcnPeriod = microrrede_v8_M->NonInlinedSFcns.Sfcn21.sfcnPeriod;
      time_T *sfcnOffset = microrrede_v8_M->NonInlinedSFcns.Sfcn21.sfcnOffset;
      int_T *sfcnTsMap = microrrede_v8_M->NonInlinedSFcns.Sfcn21.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &microrrede_v8_M->NonInlinedSFcns.blkInfo2[21]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &microrrede_v8_M->NonInlinedSFcns.inputOutputPortInfo2[21]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, microrrede_v8_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &microrrede_v8_M->NonInlinedSFcns.methods2[21]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &microrrede_v8_M->NonInlinedSFcns.methods3[21]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &microrrede_v8_M->NonInlinedSFcns.methods4[21]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &microrrede_v8_M->NonInlinedSFcns.statesInfo2[21]);
        ssSetPeriodicStatesInfo(rts,
          &microrrede_v8_M->NonInlinedSFcns.periodicStatesInfo[21]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn21.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn21.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn21.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn21.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &microrrede_v8_M->NonInlinedSFcns.Sfcn21.UPtrs0;
          sfcnUPtrs[0] = &microrrede_v8_B.Integ4_g;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &microrrede_v8_M->NonInlinedSFcns.Sfcn21.UPtrs1;
          sfcnUPtrs[0] = &microrrede_v8_B.Delay_n4;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidthAsInt(rts, 1, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn21.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn21.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn21.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn21.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &microrrede_v8_B.SFunction_p));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/Fundamental (PLL-Driven)/Mean (Variable Frequency)2/Model/Discrete Variable Time Delay/S-Function");
      ssSetRTModel(rts,microrrede_v8_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn21.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)microrrede_v8_ConstP.SFunction_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)microrrede_v8_ConstP.SFunction_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)microrrede_v8_ConstP.SFunction_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)microrrede_v8_ConstP.SFunction_P4_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &microrrede_v8_DW.SFunction_RWORK_ay);
      ssSetPWork(rts, (void **) &microrrede_v8_DW.SFunction_PWORK_ac[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn21.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn21.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 2);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &microrrede_v8_DW.SFunction_RWORK_ay);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 1, 2);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &microrrede_v8_DW.SFunction_PWORK_ac[0]);
      }

      /* registration */
      sfun_discreteVariableDelay(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 4.166667E-6);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidthAsInt(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetInputPortUnit(rts, 0, 0);
      ssSetInputPortIsContinuousQuantity(rts, 0, 0);
      ssSetInputPortWidthAsInt(rts, 1, 1);
      ssSetInputPortDataType(rts, 1, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 1, 0);
      ssSetInputPortFrameData(rts, 1, 0);
      ssSetInputPortUnit(rts, 1, 0);
      ssSetInputPortIsContinuousQuantity(rts, 1, 0);
      ssSetOutputPortWidthAsInt(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetOutputPortUnit(rts, 0, 0);
      ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: microrrede_v8/<S609>/S-Function (sfun_discreteVariableDelay) */
    {
      SimStruct *rts = microrrede_v8_M->childSfunctions[22];

      /* timing info */
      time_T *sfcnPeriod = microrrede_v8_M->NonInlinedSFcns.Sfcn22.sfcnPeriod;
      time_T *sfcnOffset = microrrede_v8_M->NonInlinedSFcns.Sfcn22.sfcnOffset;
      int_T *sfcnTsMap = microrrede_v8_M->NonInlinedSFcns.Sfcn22.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &microrrede_v8_M->NonInlinedSFcns.blkInfo2[22]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &microrrede_v8_M->NonInlinedSFcns.inputOutputPortInfo2[22]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, microrrede_v8_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &microrrede_v8_M->NonInlinedSFcns.methods2[22]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &microrrede_v8_M->NonInlinedSFcns.methods3[22]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &microrrede_v8_M->NonInlinedSFcns.methods4[22]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &microrrede_v8_M->NonInlinedSFcns.statesInfo2[22]);
        ssSetPeriodicStatesInfo(rts,
          &microrrede_v8_M->NonInlinedSFcns.periodicStatesInfo[22]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn22.inputPortInfo[0]);
        ssSetPortInfoForInputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn22.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn22.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn22.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &microrrede_v8_M->NonInlinedSFcns.Sfcn22.UPtrs0;
          sfcnUPtrs[0] = &microrrede_v8_B.Integ4_l;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &microrrede_v8_M->NonInlinedSFcns.Sfcn22.UPtrs1;
          sfcnUPtrs[0] = &microrrede_v8_B.Delay_l;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidthAsInt(rts, 1, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn22.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn22.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn22.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &microrrede_v8_M->NonInlinedSFcns.Sfcn22.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &microrrede_v8_B.SFunction_i));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PLL/Model/Mean (Variable Frequency)/Model/Discrete Variable Time Delay/S-Function");
      ssSetRTModel(rts,microrrede_v8_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn22.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)microrrede_v8_ConstP.SFunction_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)microrrede_v8_ConstP.SFunction_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)microrrede_v8_ConstP.SFunction_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)microrrede_v8_ConstP.SFunction_P4_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &microrrede_v8_DW.SFunction_RWORK_p0);
      ssSetPWork(rts, (void **) &microrrede_v8_DW.SFunction_PWORK_i[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn22.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &microrrede_v8_M->NonInlinedSFcns.Sfcn22.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 2);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &microrrede_v8_DW.SFunction_RWORK_p0);

        /* PWORK */
        ssSetDWorkWidthAsInt(rts, 1, 2);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &microrrede_v8_DW.SFunction_PWORK_i[0]);
      }

      /* registration */
      sfun_discreteVariableDelay(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 4.166667E-6);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidthAsInt(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetInputPortUnit(rts, 0, 0);
      ssSetInputPortIsContinuousQuantity(rts, 0, 0);
      ssSetInputPortWidthAsInt(rts, 1, 1);
      ssSetInputPortDataType(rts, 1, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 1, 0);
      ssSetInputPortFrameData(rts, 1, 0);
      ssSetInputPortUnit(rts, 1, 0);
      ssSetInputPortIsContinuousQuantity(rts, 1, 0);
      ssSetOutputPortWidthAsInt(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetOutputPortUnit(rts, 0, 0);
      ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }
  }

  /* Start for S-Function (sfun_spssw_discc_DSS): '<S998>/State-Space' incorporates:
   *  Constant: '<S1002>/SwitchCurrents'
   *  Constant: '<S105>/eee'
   *  Constant: '<S369>/eee'
   *  Constant: '<S989>/eee'
   *  Inport: '<Root>/XCBR_CC_1_in'
   *  Inport: '<Root>/XCBR_CC_2_in'
   *  Inport: '<Root>/XCBR_CC_3_in'
   */
  /* Level2 S-Function Block: '<S998>/State-Space' (sfun_spssw_discc_DSS) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[6];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (sfun_discreteVariableDelay): '<S242>/S-Function' incorporates:
   *  Constant: '<S241>/K1'
   */
  /* Level2 S-Function Block: '<S242>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[7];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (sfun_discreteVariableDelay): '<S313>/S-Function' */
  /* Level2 S-Function Block: '<S313>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[8];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for InitialCondition: '<S291>/Initial' */
  microrrede_v8_DW.Initial_FirstOutputTime = true;

  /* Start for S-Function (sfun_discreteVariableDelay): '<S237>/S-Function' */
  /* Level2 S-Function Block: '<S237>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[9];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (sfun_discreteVariableDelay): '<S240>/S-Function' */
  /* Level2 S-Function Block: '<S240>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[10];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (sfun_discreteVariableDelay): '<S307>/S-Function' */
  /* Level2 S-Function Block: '<S307>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[11];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (sfun_discreteVariableDelay): '<S862>/S-Function' incorporates:
   *  Constant: '<S861>/K1'
   */
  /* Level2 S-Function Block: '<S862>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[12];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (sfun_discreteVariableDelay): '<S933>/S-Function' */
  /* Level2 S-Function Block: '<S933>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[13];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for InitialCondition: '<S911>/Initial' */
  microrrede_v8_DW.Initial_FirstOutputTime_o = true;

  /* Start for S-Function (sfun_discreteVariableDelay): '<S857>/S-Function' */
  /* Level2 S-Function Block: '<S857>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[14];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (sfun_discreteVariableDelay): '<S860>/S-Function' */
  /* Level2 S-Function Block: '<S860>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[15];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (sfun_discreteVariableDelay): '<S927>/S-Function' */
  /* Level2 S-Function Block: '<S927>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[16];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (sfun_discreteVariableDelay): '<S671>/S-Function' incorporates:
   *  Constant: '<S670>/K1'
   */
  /* Level2 S-Function Block: '<S671>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[17];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (sfun_discreteVariableDelay): '<S544>/S-Function' incorporates:
   *  Constant: '<S543>/K1'
   */
  /* Level2 S-Function Block: '<S544>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[18];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (sfun_discreteVariableDelay): '<S615>/S-Function' */
  /* Level2 S-Function Block: '<S615>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[19];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for InitialCondition: '<S593>/Initial' */
  microrrede_v8_DW.Initial_FirstOutputTime_g = true;

  /* Start for S-Function (sfun_discreteVariableDelay): '<S539>/S-Function' */
  /* Level2 S-Function Block: '<S539>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[20];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (sfun_discreteVariableDelay): '<S542>/S-Function' */
  /* Level2 S-Function Block: '<S542>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[21];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (sfun_discreteVariableDelay): '<S609>/S-Function' */
  /* Level2 S-Function Block: '<S609>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[22];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for Memory: '<S39>/it init1' */
  microrrede_v8_DW.itinit1_PreviousInput = 210.41663300000002;

  /* InitializeConditions for Memory: '<S39>/it init' */
  microrrede_v8_DW.itinit_PreviousInput = 224999.96400000007;

  /* InitializeConditions for DiscreteIntegrator: '<S39>/int(i)' */
  microrrede_v8_DW.inti_PrevResetState = 2;
  microrrede_v8_DW.inti_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S44>/Discrete-Time Integrator' */
  microrrede_v8_DW.DiscreteTimeIntegrator_DSTATE = 6.3893550567661558E-123;

  /* InitializeConditions for S-Function (sfun_spssw_discc_DSS): '<S998>/State-Space' incorporates:
   *  Constant: '<S1002>/SwitchCurrents'
   *  Constant: '<S105>/eee'
   *  Constant: '<S369>/eee'
   *  Constant: '<S989>/eee'
   *  Inport: '<Root>/XCBR_CC_1_in'
   *  Inport: '<Root>/XCBR_CC_2_in'
   *  Inport: '<Root>/XCBR_CC_3_in'
   */
  /* Level2 S-Function Block: '<S998>/State-Space' (sfun_spssw_discc_DSS) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[6];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for S-Function (sfun_discreteVariableDelay): '<S242>/S-Function' incorporates:
   *  Constant: '<S241>/K1'
   */
  /* Level2 S-Function Block: '<S242>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[7];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for UnitDelay: '<S241>/Unit Delay1' */
  microrrede_v8_DW.UnitDelay1_DSTATE = 425.0;

  /* InitializeConditions for UnitDelay: '<S291>/Unit Delay' */
  microrrede_v8_DW.UnitDelay_DSTATE_i = 60.0;

  /* InitializeConditions for S-Function (sfun_discreteVariableDelay): '<S313>/S-Function' */
  /* Level2 S-Function Block: '<S313>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[8];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for DiscreteIntegrator: '<S291>/Discrete-Time Integrator' */
  microrrede_v8_DW.DiscreteTimeIntegrator_PrevRese = 2;

  /* InitializeConditions for S-Function (sfun_discreteVariableDelay): '<S237>/S-Function' */
  /* Level2 S-Function Block: '<S237>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[9];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for UnitDelay: '<S235>/Unit Delay1' */
  microrrede_v8_DW.UnitDelay1_DSTATE_p = 1.0;

  /* InitializeConditions for S-Function (sfun_discreteVariableDelay): '<S240>/S-Function' */
  /* Level2 S-Function Block: '<S240>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[10];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for S-Function (sfun_discreteVariableDelay): '<S307>/S-Function' */
  /* Level2 S-Function Block: '<S307>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[11];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for DiscreteIntegrator: '<S293>/Discrete-Time Integrator' */
  microrrede_v8_DW.DiscreteTimeIntegrator_DSTATE_n = 376.99111843077515;

  /* InitializeConditions for RateLimiter: '<S291>/Rate Limiter' */
  microrrede_v8_DW.PrevY = 60.0;

  /* InitializeConditions for UnitDelay: '<S308>/Delay_x1' */
  microrrede_v8_DW.Delay_x1_DSTATE = 583.60992942439839;

  /* InitializeConditions for UnitDelay: '<S308>/Delay_x2' */
  microrrede_v8_DW.Delay_x2_DSTATE = 3.5527136788005009E-15;

  /* InitializeConditions for S-Function (sfun_discreteVariableDelay): '<S862>/S-Function' incorporates:
   *  Constant: '<S861>/K1'
   */
  /* Level2 S-Function Block: '<S862>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[12];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for UnitDelay: '<S861>/Unit Delay1' */
  microrrede_v8_DW.UnitDelay1_DSTATE_ci = 425.0;

  /* InitializeConditions for UnitDelay: '<S911>/Unit Delay' */
  microrrede_v8_DW.UnitDelay_DSTATE_e = 60.0;

  /* InitializeConditions for S-Function (sfun_discreteVariableDelay): '<S933>/S-Function' */
  /* Level2 S-Function Block: '<S933>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[13];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for DiscreteIntegrator: '<S911>/Discrete-Time Integrator' */
  microrrede_v8_DW.DiscreteTimeIntegrator_PrevRe_g = 2;

  /* InitializeConditions for S-Function (sfun_discreteVariableDelay): '<S857>/S-Function' */
  /* Level2 S-Function Block: '<S857>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[14];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for UnitDelay: '<S855>/Unit Delay1' */
  microrrede_v8_DW.UnitDelay1_DSTATE_n = 1.0;

  /* InitializeConditions for S-Function (sfun_discreteVariableDelay): '<S860>/S-Function' */
  /* Level2 S-Function Block: '<S860>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[15];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for S-Function (sfun_discreteVariableDelay): '<S927>/S-Function' */
  /* Level2 S-Function Block: '<S927>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[16];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for DiscreteIntegrator: '<S913>/Discrete-Time Integrator' */
  microrrede_v8_DW.DiscreteTimeIntegrator_DSTAT_ht = 376.99111843077515;

  /* InitializeConditions for RateLimiter: '<S911>/Rate Limiter' */
  microrrede_v8_DW.PrevY_e = 60.0;

  /* InitializeConditions for UnitDelay: '<S928>/Delay_x1' */
  microrrede_v8_DW.Delay_x1_DSTATE_k = 583.60992942439839;

  /* InitializeConditions for UnitDelay: '<S928>/Delay_x2' */
  microrrede_v8_DW.Delay_x2_DSTATE_g = 3.5527136788005009E-15;

  /* InitializeConditions for S-Function (sfun_discreteVariableDelay): '<S671>/S-Function' incorporates:
   *  Constant: '<S670>/K1'
   */
  /* Level2 S-Function Block: '<S671>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[17];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for S-Function (sfun_discreteVariableDelay): '<S544>/S-Function' incorporates:
   *  Constant: '<S543>/K1'
   */
  /* Level2 S-Function Block: '<S544>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[18];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for UnitDelay: '<S543>/Unit Delay1' */
  microrrede_v8_DW.UnitDelay1_DSTATE_a = 425.0;

  /* InitializeConditions for UnitDelay: '<S593>/Unit Delay' */
  microrrede_v8_DW.UnitDelay_DSTATE_b = 60.0;

  /* InitializeConditions for S-Function (sfun_discreteVariableDelay): '<S615>/S-Function' */
  /* Level2 S-Function Block: '<S615>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[19];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for DiscreteIntegrator: '<S593>/Discrete-Time Integrator' */
  microrrede_v8_DW.DiscreteTimeIntegrator_PrevRe_j = 2;

  /* InitializeConditions for S-Function (sfun_discreteVariableDelay): '<S539>/S-Function' */
  /* Level2 S-Function Block: '<S539>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[20];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for UnitDelay: '<S537>/Unit Delay1' */
  microrrede_v8_DW.UnitDelay1_DSTATE_f = 1.0;

  /* InitializeConditions for S-Function (sfun_discreteVariableDelay): '<S542>/S-Function' */
  /* Level2 S-Function Block: '<S542>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[21];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for S-Function (sfun_discreteVariableDelay): '<S609>/S-Function' */
  /* Level2 S-Function Block: '<S609>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[22];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for DiscreteIntegrator: '<S595>/Discrete-Time Integrator' */
  microrrede_v8_DW.DiscreteTimeIntegrator_DSTATE_m = 376.99111843077515;

  /* InitializeConditions for RateLimiter: '<S593>/Rate Limiter' */
  microrrede_v8_DW.PrevY_j = 60.0;

  /* InitializeConditions for UnitDelay: '<S610>/Delay_x1' */
  microrrede_v8_DW.Delay_x1_DSTATE_a = 583.60992942439839;

  /* InitializeConditions for UnitDelay: '<S610>/Delay_x2' */
  microrrede_v8_DW.Delay_x2_DSTATE_b = 3.5527136788005009E-15;

  /* SystemInitialize for MATLAB Function: '<S2>/MATLAB Function' */
  microrrede__MATLABFunction_Init(&microrrede_v8_DW.sf_MATLABFunction);

  /* SystemInitialize for MATLAB Function: '<S153>/MATLAB Function' */
  microrrede__MATLABFunction_Init(&microrrede_v8_DW.sf_MATLABFunction_n);

  /* Start for S-Function (sfun_discreteVariableDelay): '<S301>/S-Function' */
  /* Level2 S-Function Block: '<S301>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (sfun_discreteVariableDelay): '<S304>/S-Function' */
  /* Level2 S-Function Block: '<S304>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for S-Function (sfun_discreteVariableDelay): '<S301>/S-Function' */
  /* Level2 S-Function Block: '<S301>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[0];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for UnitDelay: '<S299>/Unit Delay1' */
  microrrede_v8_DW.UnitDelay1_DSTATE_o = 1.0;

  /* InitializeConditions for S-Function (sfun_discreteVariableDelay): '<S304>/S-Function' */
  /* Level2 S-Function Block: '<S304>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[1];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* SystemInitialize for Math: '<S292>/Math Function' incorporates:
   *  Outport: '<S292>/Gain'
   *
   * About '<S292>/Math Function':
   *  Operator: reciprocal
   */
  microrrede_v8_B.MathFunction_c = 1.0;

  /* End of SystemInitialize for SubSystem: '<S291>/Automatic Gain Control' */

  /* SystemInitialize for MATLAB Function: '<S773>/MATLAB Function' */
  microrrede__MATLABFunction_Init(&microrrede_v8_DW.sf_MATLABFunction_c);

  /* Start for S-Function (sfun_discreteVariableDelay): '<S921>/S-Function' */
  /* Level2 S-Function Block: '<S921>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[4];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (sfun_discreteVariableDelay): '<S924>/S-Function' */
  /* Level2 S-Function Block: '<S924>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[5];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for S-Function (sfun_discreteVariableDelay): '<S921>/S-Function' */
  /* Level2 S-Function Block: '<S921>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[4];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for UnitDelay: '<S919>/Unit Delay1' */
  microrrede_v8_DW.UnitDelay1_DSTATE_k = 1.0;

  /* InitializeConditions for S-Function (sfun_discreteVariableDelay): '<S924>/S-Function' */
  /* Level2 S-Function Block: '<S924>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[5];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* SystemInitialize for Math: '<S912>/Math Function' incorporates:
   *  Outport: '<S912>/Gain'
   *
   * About '<S912>/Math Function':
   *  Operator: reciprocal
   */
  microrrede_v8_B.MathFunction = 1.0;

  /* End of SystemInitialize for SubSystem: '<S911>/Automatic Gain Control' */
  /* Start for S-Function (sfun_discreteVariableDelay): '<S603>/S-Function' */
  /* Level2 S-Function Block: '<S603>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[2];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (sfun_discreteVariableDelay): '<S606>/S-Function' */
  /* Level2 S-Function Block: '<S606>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[3];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for S-Function (sfun_discreteVariableDelay): '<S603>/S-Function' */
  /* Level2 S-Function Block: '<S603>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[2];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for UnitDelay: '<S601>/Unit Delay1' */
  microrrede_v8_DW.UnitDelay1_DSTATE_l = 1.0;

  /* InitializeConditions for S-Function (sfun_discreteVariableDelay): '<S606>/S-Function' */
  /* Level2 S-Function Block: '<S606>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[3];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* SystemInitialize for Math: '<S594>/Math Function' incorporates:
   *  Outport: '<S594>/Gain'
   *
   * About '<S594>/Math Function':
   *  Operator: reciprocal
   */
  microrrede_v8_B.MathFunction_l = 1.0;

  /* End of SystemInitialize for SubSystem: '<S593>/Automatic Gain Control' */

  /* Enable for Sin: '<S152>/Sine Wave A' */
  microrrede_v8_DW.systemEnable = 1;

  /* Enable for Sin: '<S152>/Sine Wave B' */
  microrrede_v8_DW.systemEnable_d = 1;

  /* Enable for Sin: '<S152>/Sine Wave C' */
  microrrede_v8_DW.systemEnable_d3 = 1;

  /* Enable for DiscreteIntegrator: '<S241>/Integ4' */
  microrrede_v8_DW.Integ4_SYSTEM_ENABLE = 1U;

  /* Enable for DiscreteIntegrator: '<S235>/Integ4' */
  microrrede_v8_DW.Integ4_SYSTEM_ENABLE_h = 1U;

  /* Enable for DiscreteIntegrator: '<S238>/Integ4' */
  microrrede_v8_DW.Integ4_SYSTEM_ENABLE_a = 1U;

  /* Enable for DiscreteIntegrator: '<S305>/Integ4' */
  microrrede_v8_DW.Integ4_SYSTEM_ENABLE_j = 1U;

  /* Enable for DiscreteIntegrator: '<S861>/Integ4' */
  microrrede_v8_DW.Integ4_SYSTEM_ENABLE_n = 1U;

  /* Enable for DiscreteIntegrator: '<S855>/Integ4' */
  microrrede_v8_DW.Integ4_SYSTEM_ENABLE_nm = 1U;

  /* Enable for DiscreteIntegrator: '<S858>/Integ4' */
  microrrede_v8_DW.Integ4_SYSTEM_ENABLE_i = 1U;

  /* Enable for DiscreteIntegrator: '<S925>/Integ4' */
  microrrede_v8_DW.Integ4_SYSTEM_ENABLE_p = 1U;

  /* Enable for DiscreteIntegrator: '<S670>/Integ4' */
  microrrede_v8_DW.Integ4_SYSTEM_ENABLE_e = 1U;

  /* Enable for Sin: '<S500>/Sine Wave' */
  microrrede_v8_DW.systemEnable_m = 1;

  /* Enable for DiscreteIntegrator: '<S543>/Integ4' */
  microrrede_v8_DW.Integ4_SYSTEM_ENABLE_pi = 1U;

  /* Enable for DiscreteIntegrator: '<S537>/Integ4' */
  microrrede_v8_DW.Integ4_SYSTEM_ENABLE_eq = 1U;

  /* Enable for DiscreteIntegrator: '<S540>/Integ4' */
  microrrede_v8_DW.Integ4_SYSTEM_ENABLE_b = 1U;

  /* Enable for DiscreteIntegrator: '<S607>/Integ4' */
  microrrede_v8_DW.Integ4_SYSTEM_ENABLE_c = 1U;
}

/* Model terminate function */
void microrrede_v8_terminate(void)
{
  /* Terminate for S-Function (sfun_spssw_discc_DSS): '<S998>/State-Space' incorporates:
   *  Constant: '<S1002>/SwitchCurrents'
   *  Constant: '<S105>/eee'
   *  Constant: '<S369>/eee'
   *  Constant: '<S989>/eee'
   *  Inport: '<Root>/XCBR_CC_1_in'
   *  Inport: '<Root>/XCBR_CC_2_in'
   *  Inport: '<Root>/XCBR_CC_3_in'
   */
  /* Level2 S-Function Block: '<S998>/State-Space' (sfun_spssw_discc_DSS) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sfun_discreteVariableDelay): '<S242>/S-Function' incorporates:
   *  Constant: '<S241>/K1'
   */
  /* Level2 S-Function Block: '<S242>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[7];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sfun_discreteVariableDelay): '<S313>/S-Function' */
  /* Level2 S-Function Block: '<S313>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[8];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sfun_discreteVariableDelay): '<S237>/S-Function' */
  /* Level2 S-Function Block: '<S237>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[9];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sfun_discreteVariableDelay): '<S240>/S-Function' */
  /* Level2 S-Function Block: '<S240>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[10];
    sfcnTerminate(rts);
  }

  /* Terminate for Enabled SubSystem: '<S291>/Automatic Gain Control' */

  /* Terminate for S-Function (sfun_discreteVariableDelay): '<S301>/S-Function' */
  /* Level2 S-Function Block: '<S301>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sfun_discreteVariableDelay): '<S304>/S-Function' */
  /* Level2 S-Function Block: '<S304>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* End of Terminate for SubSystem: '<S291>/Automatic Gain Control' */

  /* Terminate for S-Function (sfun_discreteVariableDelay): '<S307>/S-Function' */
  /* Level2 S-Function Block: '<S307>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[11];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sfun_discreteVariableDelay): '<S862>/S-Function' incorporates:
   *  Constant: '<S861>/K1'
   */
  /* Level2 S-Function Block: '<S862>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[12];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sfun_discreteVariableDelay): '<S933>/S-Function' */
  /* Level2 S-Function Block: '<S933>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[13];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sfun_discreteVariableDelay): '<S857>/S-Function' */
  /* Level2 S-Function Block: '<S857>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[14];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sfun_discreteVariableDelay): '<S860>/S-Function' */
  /* Level2 S-Function Block: '<S860>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[15];
    sfcnTerminate(rts);
  }

  /* Terminate for Enabled SubSystem: '<S911>/Automatic Gain Control' */

  /* Terminate for S-Function (sfun_discreteVariableDelay): '<S921>/S-Function' */
  /* Level2 S-Function Block: '<S921>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sfun_discreteVariableDelay): '<S924>/S-Function' */
  /* Level2 S-Function Block: '<S924>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* End of Terminate for SubSystem: '<S911>/Automatic Gain Control' */

  /* Terminate for S-Function (sfun_discreteVariableDelay): '<S927>/S-Function' */
  /* Level2 S-Function Block: '<S927>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[16];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sfun_discreteVariableDelay): '<S671>/S-Function' incorporates:
   *  Constant: '<S670>/K1'
   */
  /* Level2 S-Function Block: '<S671>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[17];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sfun_discreteVariableDelay): '<S544>/S-Function' incorporates:
   *  Constant: '<S543>/K1'
   */
  /* Level2 S-Function Block: '<S544>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[18];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sfun_discreteVariableDelay): '<S615>/S-Function' */
  /* Level2 S-Function Block: '<S615>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[19];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sfun_discreteVariableDelay): '<S539>/S-Function' */
  /* Level2 S-Function Block: '<S539>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[20];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sfun_discreteVariableDelay): '<S542>/S-Function' */
  /* Level2 S-Function Block: '<S542>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[21];
    sfcnTerminate(rts);
  }

  /* Terminate for Enabled SubSystem: '<S593>/Automatic Gain Control' */

  /* Terminate for S-Function (sfun_discreteVariableDelay): '<S603>/S-Function' */
  /* Level2 S-Function Block: '<S603>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (sfun_discreteVariableDelay): '<S606>/S-Function' */
  /* Level2 S-Function Block: '<S606>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* End of Terminate for SubSystem: '<S593>/Automatic Gain Control' */

  /* Terminate for S-Function (sfun_discreteVariableDelay): '<S609>/S-Function' */
  /* Level2 S-Function Block: '<S609>/S-Function' (sfun_discreteVariableDelay) */
  {
    SimStruct *rts = microrrede_v8_M->childSfunctions[22];
    sfcnTerminate(rts);
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
