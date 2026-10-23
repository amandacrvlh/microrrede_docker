/*
 * File: microrrede_v8.h
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

#ifndef RTW_HEADER_microrrede_v8_h_
#define RTW_HEADER_microrrede_v8_h_
#ifndef microrrede_v8_COMMON_INCLUDES_
#define microrrede_v8_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif                                 /* microrrede_v8_COMMON_INCLUDES_ */

#include "microrrede_v8_types.h"
#include <stddef.h>
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include <string.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetSampleHitArray
#define rtmGetSampleHitArray(rtm)      ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmGetStepSize
#define rtmGetStepSize(rtm)            ((rtm)->Timing.stepSize)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
#define rtmGet_TimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

#ifndef rtmGetTimeOfLastOutput
#define rtmGetTimeOfLastOutput(rtm)    ((rtm)->Timing.timeOfLastOutput)
#endif

/* Block states (default storage) for system '<S2>/MATLAB Function' */
typedef struct {
  real_T Vold;                         /* '<S2>/MATLAB Function' */
  real_T Pold;                         /* '<S2>/MATLAB Function' */
  real_T Dold;                         /* '<S2>/MATLAB Function' */
} DW_MATLABFunction_microrrede__T;

/* Block signals (default storage) */
typedef struct {
  real_T Switch2;                      /* '<S45>/Switch2' */
  real_T UnitDelay;                    /* '<S676>/Unit Delay' */
  real_T IL;                           /* '<S679>/Product1' */
  real_T UnitDelay_i;                  /* '<S688>/Unit Delay' */
  real_T IL_f;                         /* '<S691>/Product1' */
  real_T UnitDelay_f;                  /* '<S700>/Unit Delay' */
  real_T IL_b;                         /* '<S703>/Product1' */
  real_T SineWaveA;                    /* '<S152>/Sine Wave A' */
  real_T SineWaveB;                    /* '<S152>/Sine Wave B' */
  real_T SineWaveC;                    /* '<S152>/Sine Wave C' */
  real_T Sum[3];                       /* '<S998>/Sum' */
  real_T StateSpace_o1[85];            /* '<S998>/State-Space' */
  real_T StateSpace_o2[41];            /* '<S998>/State-Space' */
  real_T StateSpace_o3;                /* '<S998>/State-Space' */
  real_T Switch3;                      /* '<S131>/Switch3' */
  real_T Switch3_d;                    /* '<S133>/Switch3' */
  real_T Switch3_k;                    /* '<S135>/Switch3' */
  real_T Switch3_g;                    /* '<S138>/Switch3' */
  real_T I3;                           /* '<S6>/do not delete this gain' */
  real_T V3;                           /* '<S33>/do not delete this gain' */
  real_T I2;                           /* '<S5>/do not delete this gain' */
  real_T V2;                           /* '<S32>/do not delete this gain' */
  real_T I1;                           /* '<S4>/do not delete this gain' */
  real_T V1;                           /* '<S31>/do not delete this gain' */
  real_T Switch3_b;                    /* '<S116>/Switch3' */
  real_T Switch3_p;                    /* '<S118>/Switch3' */
  real_T Switch3_kf;                   /* '<S120>/Switch3' */
  real_T Switch3_bx;                   /* '<S125>/Switch3' */
  real_T DataTypeConversion;           /* '<S51>/Data Type Conversion' */
  real_T DataTypeConversion_f;         /* '<S162>/Data Type Conversion' */
  real_T Integ4;                       /* '<S241>/Integ4' */
  real_T SFunction;                    /* '<S242>/S-Function' */
  real_T Gain;                         /* '<S231>/Gain' */
  real_T SFunction_f;                  /* '<S313>/S-Function' */
  real_T Integ4_p;                     /* '<S235>/Integ4' */
  real_T Delay;                        /* '<S235>/Gain' */
  real_T SFunction_o;                  /* '<S237>/S-Function' */
  real_T Integ4_e;                     /* '<S238>/Integ4' */
  real_T Delay_g;                      /* '<S238>/Gain' */
  real_T SFunction_e;                  /* '<S240>/S-Function' */
  real_T DataTypeConversion_m[4];      /* '<S214>/Data Type Conversion' */
  real_T Integ4_ep;                    /* '<S305>/Integ4' */
  real_T Delay_c;                      /* '<S305>/Gain' */
  real_T SFunction_m;                  /* '<S307>/S-Function' */
  real_T DataTypeConversion_a;         /* '<S782>/Data Type Conversion' */
  real_T Integ4_b;                     /* '<S861>/Integ4' */
  real_T SFunction_j;                  /* '<S862>/S-Function' */
  real_T Gain_m;                       /* '<S851>/Gain' */
  real_T SFunction_oz;                 /* '<S933>/S-Function' */
  real_T Integ4_j;                     /* '<S855>/Integ4' */
  real_T Delay_n;                      /* '<S855>/Gain' */
  real_T SFunction_g;                  /* '<S857>/S-Function' */
  real_T Integ4_f;                     /* '<S858>/Integ4' */
  real_T Delay_i;                      /* '<S858>/Gain' */
  real_T SFunction_ed;                 /* '<S860>/S-Function' */
  real_T DataTypeConversion_i[4];      /* '<S834>/Data Type Conversion' */
  real_T Integ4_eu;                    /* '<S925>/Integ4' */
  real_T Delay_d;                      /* '<S925>/Gain' */
  real_T SFunction_gc;                 /* '<S927>/S-Function' */
  real_T Switch3_e;                    /* '<S123>/Switch3' */
  real_T Integ4_b5;                    /* '<S670>/Integ4' */
  real_T SFunction_mo;                 /* '<S671>/S-Function' */
  real_T DataTypeConversion_h;         /* '<S383>/Data Type Conversion' */
  real_T DataTypeConversion_hq;        /* '<S397>/Data Type Conversion' */
  real_T DataTypeConversion_ad[4];     /* '<S382>/Data Type Conversion' */
  real_T Integ4_ps;                    /* '<S543>/Integ4' */
  real_T SFunction_k;                  /* '<S544>/S-Function' */
  real_T Gain_a;                       /* '<S533>/Gain' */
  real_T SFunction_gq;                 /* '<S615>/S-Function' */
  real_T Integ4_c;                     /* '<S537>/Integ4' */
  real_T Delay_go;                     /* '<S537>/Gain' */
  real_T SFunction_o4;                 /* '<S539>/S-Function' */
  real_T Integ4_g;                     /* '<S540>/Integ4' */
  real_T Delay_n4;                     /* '<S540>/Gain' */
  real_T SFunction_p;                  /* '<S542>/S-Function' */
  real_T DataTypeConversion_g[4];      /* '<S516>/Data Type Conversion' */
  real_T Integ4_l;                     /* '<S607>/Integ4' */
  real_T Delay_l;                      /* '<S607>/Gain' */
  real_T SFunction_i;                  /* '<S609>/S-Function' */
  real_T Fcn;                          /* '<S937>/Fcn' */
  real_T Fcn1;                         /* '<S937>/Fcn1' */
  real_T Fcn_g;                        /* '<S936>/Fcn' */
  real_T Fcn1_c;                       /* '<S936>/Fcn1' */
  real_T Integ4_m;                     /* '<S919>/Integ4' */
  real_T Delay_h;                      /* '<S919>/Gain' */
  real_T SFunction_ip;                 /* '<S921>/S-Function' */
  real_T Integ4_je;                    /* '<S922>/Integ4' */
  real_T Delay_j;                      /* '<S922>/Gain' */
  real_T SFunction_a;                  /* '<S924>/S-Function' */
  real_T MathFunction;                 /* '<S912>/Math Function' */
  real_T Fcn_p;                        /* '<S619>/Fcn' */
  real_T Fcn1_n;                       /* '<S619>/Fcn1' */
  real_T Fcn_f;                        /* '<S618>/Fcn' */
  real_T Fcn1_f;                       /* '<S618>/Fcn1' */
  real_T Integ4_mt;                    /* '<S601>/Integ4' */
  real_T Delay_le;                     /* '<S601>/Gain' */
  real_T SFunction_h;                  /* '<S603>/S-Function' */
  real_T Integ4_i;                     /* '<S604>/Integ4' */
  real_T Delay_ja;                     /* '<S604>/Gain' */
  real_T SFunction_pe;                 /* '<S606>/S-Function' */
  real_T MathFunction_l;               /* '<S594>/Math Function' */
  real_T Fcn_n;                        /* '<S317>/Fcn' */
  real_T Fcn1_j;                       /* '<S317>/Fcn1' */
  real_T Fcn_l;                        /* '<S316>/Fcn' */
  real_T Fcn1_f1;                      /* '<S316>/Fcn1' */
  real_T Integ4_jd;                    /* '<S299>/Integ4' */
  real_T Delay_du;                     /* '<S299>/Gain' */
  real_T SFunction_pp;                 /* '<S301>/S-Function' */
  real_T Integ4_i3;                    /* '<S302>/Integ4' */
  real_T Delay_b;                      /* '<S302>/Gain' */
  real_T SFunction_f0;                 /* '<S304>/S-Function' */
  real_T MathFunction_c;               /* '<S292>/Math Function' */
} B_microrrede_v8_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Currentfilter_states;         /* '<S39>/Current filter' */
  real_T inti_DSTATE;                  /* '<S39>/int(i)' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S44>/Discrete-Time Integrator' */
  real_T UnitDelay_DSTATE;             /* '<S676>/Unit Delay' */
  real_T UnitDelay_DSTATE_c;           /* '<S688>/Unit Delay' */
  real_T UnitDelay_DSTATE_d;           /* '<S700>/Unit Delay' */
  real_T UnitDelay_DSTATE_g[3];        /* '<S998>/Unit Delay' */
  real_T StateSpace_DSTATE[28];        /* '<S998>/State-Space' */
  real_T Integrator_DSTATE;            /* '<S83>/Integrator' */
  real_T Integrator_DSTATE_f;          /* '<S194>/Integrator' */
  real_T Integ4_DSTATE;                /* '<S241>/Integ4' */
  real_T UnitDelay_DSTATE_cn;          /* '<S241>/Unit Delay' */
  real_T UnitDelay1_DSTATE;            /* '<S241>/Unit Delay1' */
  real_T UnitDelay_DSTATE_i;           /* '<S291>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTATE_k;/* '<S291>/Discrete-Time Integrator' */
  real_T Integrator_DSTATE_n;          /* '<S274>/Integrator' */
  real_T Integrator_DSTATE_k[2];       /* '<S350>/Integrator' */
  real_T Integ4_DSTATE_l;              /* '<S235>/Integ4' */
  real_T UnitDelay_DSTATE_dc;          /* '<S236>/Unit Delay' */
  real_T UnitDelay1_DSTATE_p;          /* '<S235>/Unit Delay1' */
  real_T Integ4_DSTATE_h;              /* '<S238>/Integ4' */
  real_T UnitDelay_DSTATE_m;           /* '<S239>/Unit Delay' */
  real_T UnitDelay1_DSTATE_c;          /* '<S238>/Unit Delay1' */
  real_T Integ4_DSTATE_o;              /* '<S305>/Integ4' */
  real_T UnitDelay_DSTATE_cm;          /* '<S306>/Unit Delay' */
  real_T UnitDelay1_DSTATE_h;          /* '<S305>/Unit Delay1' */
  real_T DiscreteDerivative_states;    /* '<S293>/Discrete Derivative ' */
  real_T DiscreteTimeIntegrator_DSTATE_n;/* '<S293>/Discrete-Time Integrator' */
  real_T Delay_x1_DSTATE;              /* '<S308>/Delay_x1' */
  real_T Delay_x2_DSTATE;              /* '<S308>/Delay_x2' */
  real_T Integrator_DSTATE_p;          /* '<S814>/Integrator' */
  real_T Integ4_DSTATE_f;              /* '<S861>/Integ4' */
  real_T UnitDelay_DSTATE_gf;          /* '<S861>/Unit Delay' */
  real_T UnitDelay1_DSTATE_ci;         /* '<S861>/Unit Delay1' */
  real_T UnitDelay_DSTATE_e;           /* '<S911>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTATE_h;/* '<S911>/Discrete-Time Integrator' */
  real_T Integrator_DSTATE_h;          /* '<S894>/Integrator' */
  real_T Integrator_DSTATE_f5[2];      /* '<S970>/Integrator' */
  real_T Integ4_DSTATE_fu;             /* '<S855>/Integ4' */
  real_T UnitDelay_DSTATE_h;           /* '<S856>/Unit Delay' */
  real_T UnitDelay1_DSTATE_n;          /* '<S855>/Unit Delay1' */
  real_T Integ4_DSTATE_d;              /* '<S858>/Integ4' */
  real_T UnitDelay_DSTATE_ds;          /* '<S859>/Unit Delay' */
  real_T UnitDelay1_DSTATE_e;          /* '<S858>/Unit Delay1' */
  real_T Integ4_DSTATE_fb;             /* '<S925>/Integ4' */
  real_T UnitDelay_DSTATE_a;           /* '<S926>/Unit Delay' */
  real_T UnitDelay1_DSTATE_j;          /* '<S925>/Unit Delay1' */
  real_T DiscreteDerivative_states_h;  /* '<S913>/Discrete Derivative ' */
  real_T DiscreteTimeIntegrator_DSTAT_ht;/* '<S913>/Discrete-Time Integrator' */
  real_T Delay_x1_DSTATE_k;            /* '<S928>/Delay_x1' */
  real_T Delay_x2_DSTATE_g;            /* '<S928>/Delay_x2' */
  real_T Integ4_DSTATE_p;              /* '<S670>/Integ4' */
  real_T UnitDelay_DSTATE_n;           /* '<S670>/Unit Delay' */
  real_T UnitDelay1_DSTATE_g;          /* '<S670>/Unit Delay1' */
  real_T Integrator_DSTATE_j;          /* '<S430>/Integrator' */
  real_T Integrator_DSTATE_kn;         /* '<S478>/Integrator' */
  real_T Integ4_DSTATE_a;              /* '<S543>/Integ4' */
  real_T UnitDelay_DSTATE_f;           /* '<S543>/Unit Delay' */
  real_T UnitDelay1_DSTATE_a;          /* '<S543>/Unit Delay1' */
  real_T UnitDelay_DSTATE_b;           /* '<S593>/Unit Delay' */
  real_T DiscreteTimeIntegrator_DSTATE_l;/* '<S593>/Discrete-Time Integrator' */
  real_T Integrator_DSTATE_g;          /* '<S576>/Integrator' */
  real_T Integrator_DSTATE_m[2];       /* '<S652>/Integrator' */
  real_T Integ4_DSTATE_hc;             /* '<S537>/Integ4' */
  real_T UnitDelay_DSTATE_al;          /* '<S538>/Unit Delay' */
  real_T UnitDelay1_DSTATE_f;          /* '<S537>/Unit Delay1' */
  real_T Integ4_DSTATE_lt;             /* '<S540>/Integ4' */
  real_T UnitDelay_DSTATE_o;           /* '<S541>/Unit Delay' */
  real_T UnitDelay1_DSTATE_cr;         /* '<S540>/Unit Delay1' */
  real_T Integ4_DSTATE_h5;             /* '<S607>/Integ4' */
  real_T UnitDelay_DSTATE_hk;          /* '<S608>/Unit Delay' */
  real_T UnitDelay1_DSTATE_em;         /* '<S607>/Unit Delay1' */
  real_T DiscreteDerivative_states_o;  /* '<S595>/Discrete Derivative ' */
  real_T DiscreteTimeIntegrator_DSTATE_m;/* '<S595>/Discrete-Time Integrator' */
  real_T Delay_x1_DSTATE_a;            /* '<S610>/Delay_x1' */
  real_T Delay_x2_DSTATE_b;            /* '<S610>/Delay_x2' */
  real_T Integ4_DSTATE_e;              /* '<S919>/Integ4' */
  real_T UnitDelay_DSTATE_j;           /* '<S920>/Unit Delay' */
  real_T UnitDelay1_DSTATE_k;          /* '<S919>/Unit Delay1' */
  real_T Integ4_DSTATE_aa;             /* '<S922>/Integ4' */
  real_T UnitDelay_DSTATE_ar;          /* '<S923>/Unit Delay' */
  real_T UnitDelay1_DSTATE_b;          /* '<S922>/Unit Delay1' */
  real_T Integ4_DSTATE_hi;             /* '<S601>/Integ4' */
  real_T UnitDelay_DSTATE_fx;          /* '<S602>/Unit Delay' */
  real_T UnitDelay1_DSTATE_l;          /* '<S601>/Unit Delay1' */
  real_T Integ4_DSTATE_c;              /* '<S604>/Integ4' */
  real_T UnitDelay_DSTATE_nt;          /* '<S605>/Unit Delay' */
  real_T UnitDelay1_DSTATE_fb;         /* '<S604>/Unit Delay1' */
  real_T Integ4_DSTATE_f5;             /* '<S299>/Integ4' */
  real_T UnitDelay_DSTATE_ne;          /* '<S300>/Unit Delay' */
  real_T UnitDelay1_DSTATE_o;          /* '<S299>/Unit Delay1' */
  real_T Integ4_DSTATE_hw;             /* '<S302>/Integ4' */
  real_T UnitDelay_DSTATE_l;           /* '<S303>/Unit Delay' */
  real_T UnitDelay1_DSTATE_gn;         /* '<S302>/Unit Delay1' */
  real_T itinit1_PreviousInput;        /* '<S39>/it init1' */
  real_T itinit_PreviousInput;         /* '<S39>/it init' */
  real_T Memory2_PreviousInput;        /* '<S39>/Memory2' */
  real_T lastSin;                      /* '<S152>/Sine Wave A' */
  real_T lastCos;                      /* '<S152>/Sine Wave A' */
  real_T lastSin_c;                    /* '<S152>/Sine Wave B' */
  real_T lastCos_l;                    /* '<S152>/Sine Wave B' */
  real_T lastSin_cr;                   /* '<S152>/Sine Wave C' */
  real_T lastCos_f;                    /* '<S152>/Sine Wave C' */
  real_T PrevY;                        /* '<S291>/Rate Limiter' */
  real_T PrevY_e;                      /* '<S911>/Rate Limiter' */
  real_T lastSin_h;                    /* '<S500>/Sine Wave' */
  real_T lastCos_m;                    /* '<S500>/Sine Wave' */
  real_T PrevY_j;                      /* '<S593>/Rate Limiter' */
  real_T StateSpace_RWORK;             /* '<S998>/State-Space' */
  real_T SFunction_RWORK;              /* '<S242>/S-Function' */
  real_T SFunction_RWORK_d;            /* '<S313>/S-Function' */
  real_T SFunction_RWORK_l;            /* '<S237>/S-Function' */
  real_T SFunction_RWORK_c;            /* '<S240>/S-Function' */
  real_T SFunction_RWORK_j;            /* '<S307>/S-Function' */
  real_T SFunction_RWORK_f;            /* '<S862>/S-Function' */
  real_T SFunction_RWORK_p;            /* '<S933>/S-Function' */
  real_T SFunction_RWORK_h;            /* '<S857>/S-Function' */
  real_T SFunction_RWORK_o;            /* '<S860>/S-Function' */
  real_T SFunction_RWORK_m;            /* '<S927>/S-Function' */
  real_T SFunction_RWORK_f5;           /* '<S671>/S-Function' */
  real_T SFunction_RWORK_a;            /* '<S544>/S-Function' */
  real_T SFunction_RWORK_g;            /* '<S615>/S-Function' */
  real_T SFunction_RWORK_f0;           /* '<S539>/S-Function' */
  real_T SFunction_RWORK_ay;           /* '<S542>/S-Function' */
  real_T SFunction_RWORK_p0;           /* '<S609>/S-Function' */
  real_T SFunction_RWORK_n;            /* '<S921>/S-Function' */
  real_T SFunction_RWORK_pf;           /* '<S924>/S-Function' */
  real_T SFunction_RWORK_hu;           /* '<S603>/S-Function' */
  real_T SFunction_RWORK_as;           /* '<S606>/S-Function' */
  real_T SFunction_RWORK_jd;           /* '<S301>/S-Function' */
  real_T SFunction_RWORK_hd;           /* '<S304>/S-Function' */
  void *StateSpace_PWORK[65];          /* '<S998>/State-Space' */
  void *SFunction_PWORK[2];            /* '<S242>/S-Function' */
  void *SFunction_PWORK_g[2];          /* '<S313>/S-Function' */
  void *SFunction_PWORK_j[2];          /* '<S237>/S-Function' */
  void *SFunction_PWORK_e[2];          /* '<S240>/S-Function' */
  void *SFunction_PWORK_p[2];          /* '<S307>/S-Function' */
  void *SFunction_PWORK_h[2];          /* '<S862>/S-Function' */
  void *SFunction_PWORK_f[2];          /* '<S933>/S-Function' */
  void *SFunction_PWORK_n[2];          /* '<S857>/S-Function' */
  void *SFunction_PWORK_fr[2];         /* '<S860>/S-Function' */
  void *SFunction_PWORK_b[2];          /* '<S927>/S-Function' */
  void *SFunction_PWORK_o[2];          /* '<S671>/S-Function' */
  void *SFunction_PWORK_c[2];          /* '<S544>/S-Function' */
  void *SFunction_PWORK_a[2];          /* '<S615>/S-Function' */
  void *SFunction_PWORK_k[2];          /* '<S539>/S-Function' */
  void *SFunction_PWORK_ac[2];         /* '<S542>/S-Function' */
  void *SFunction_PWORK_i[2];          /* '<S609>/S-Function' */
  void *SFunction_PWORK_m[2];          /* '<S921>/S-Function' */
  void *SFunction_PWORK_e5[2];         /* '<S924>/S-Function' */
  void *SFunction_PWORK_ae[2];         /* '<S603>/S-Function' */
  void *SFunction_PWORK_iz[2];         /* '<S606>/S-Function' */
  void *SFunction_PWORK_d[2];          /* '<S301>/S-Function' */
  void *SFunction_PWORK_ej[2];         /* '<S304>/S-Function' */
  int32_T systemEnable;                /* '<S152>/Sine Wave A' */
  int32_T systemEnable_d;              /* '<S152>/Sine Wave B' */
  int32_T systemEnable_d3;             /* '<S152>/Sine Wave C' */
  int32_T systemEnable_m;              /* '<S500>/Sine Wave' */
  uint32_T m_bpIndex;                  /* '<S225>/1-D Lookup Table' */
  uint32_T m_bpIndex_e;                /* '<S845>/1-D Lookup Table' */
  uint32_T m_bpIndex_d;                /* '<S504>/1-D Lookup Table' */
  uint32_T m_bpIndex_b;                /* '<S527>/1-D Lookup Table' */
  int_T StateSpace_IWORK[12];          /* '<S998>/State-Space' */
  int8_T inti_PrevResetState;          /* '<S39>/int(i)' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S291>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_g;/* '<S911>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevRe_j;/* '<S593>/Discrete-Time Integrator' */
  uint8_T inti_IC_LOADING;             /* '<S39>/int(i)' */
  uint8_T Integ4_SYSTEM_ENABLE;        /* '<S241>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_h;      /* '<S235>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_a;      /* '<S238>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_j;      /* '<S305>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_n;      /* '<S861>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_nm;     /* '<S855>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_i;      /* '<S858>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_p;      /* '<S925>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_e;      /* '<S670>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_pi;     /* '<S543>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_eq;     /* '<S537>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_b;      /* '<S540>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_c;      /* '<S607>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_g;      /* '<S919>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_gv;     /* '<S922>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_k;      /* '<S601>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_bq;     /* '<S604>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_l;      /* '<S299>/Integ4' */
  uint8_T Integ4_SYSTEM_ENABLE_iz;     /* '<S302>/Integ4' */
  boolean_T Initial_FirstOutputTime;   /* '<S291>/Initial' */
  boolean_T Initial_FirstOutputTime_o; /* '<S911>/Initial' */
  boolean_T Initial_FirstOutputTime_g; /* '<S593>/Initial' */
  boolean_T AutomaticGainControl_MODE; /* '<S911>/Automatic Gain Control' */
  boolean_T AutomaticGainControl_MODE_o;/* '<S593>/Automatic Gain Control' */
  boolean_T AutomaticGainControl_MODE_ow;/* '<S291>/Automatic Gain Control' */
  DW_MATLABFunction_microrrede__T sf_MATLABFunction_c;/* '<S773>/MATLAB Function' */
  DW_MATLABFunction_microrrede__T sf_MATLABFunction_n;/* '<S153>/MATLAB Function' */
  DW_MATLABFunction_microrrede__T sf_MATLABFunction;/* '<S2>/MATLAB Function' */
} DW_microrrede_v8_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Tcell_K;                /* '<S679>/Add2' */
  const real_T Add3;                   /* '<S679>/Add3' */
  const real_T alpha_Isc;              /* '<S679>/alpha_Isc' */
  const real_T Add;                    /* '<S679>/Add' */
  const real_T Add4;                   /* '<S676>/Add4' */
  const real_T dEgdT;                  /* '<S676>/dEgdT' */
  const real_T Add3_j;                 /* '<S676>/Add3' */
  const real_T E_g;                    /* '<S676>/EgRef' */
  const real_T Tcell_KTref_K;          /* '<S676>/Product3' */
  const real_T Fcn;                    /* '<S676>/Fcn' */
  const real_T I0_array;               /* '<S676>/I0_array' */
  const real_T k1;                     /* '<S685>/k1' */
  const real_T Product;                /* '<S685>/Product' */
  const real_T Add_k;                  /* '<S685>/Add' */
  const real_T MathFunction;           /* '<S685>/Math Function' */
  const real_T Product4;               /* '<S676>/Product4' */
  const real_T VT;                     /* '<S676>/VT_ref_array' */
  const real_T Add3_m;                 /* '<S216>/Add3' */
  const real_T Gain1;                  /* '<S216>/Gain1' */
  const real_T Gain;                   /* '<S215>/Gain' */
  const real_T Gain2;                  /* '<S215>/Gain2' */
  const real_T Gain1_g;                /* '<S232>/Gain1' */
  const real_T Gain3;                  /* '<S232>/Gain3' */
  const real_T Tcell_K_a;              /* '<S691>/Add2' */
  const real_T Add3_g;                 /* '<S691>/Add3' */
  const real_T alpha_Isc_f;            /* '<S691>/alpha_Isc' */
  const real_T Add_ko;                 /* '<S691>/Add' */
  const real_T Add4_b;                 /* '<S688>/Add4' */
  const real_T dEgdT_l;                /* '<S688>/dEgdT' */
  const real_T Add3_ms;                /* '<S688>/Add3' */
  const real_T E_g_e;                  /* '<S688>/EgRef' */
  const real_T Tcell_KTref_K_i;        /* '<S688>/Product3' */
  const real_T Fcn_e;                  /* '<S688>/Fcn' */
  const real_T I0_array_g;             /* '<S688>/I0_array' */
  const real_T k1_b;                   /* '<S697>/k1' */
  const real_T Product_b;              /* '<S697>/Product' */
  const real_T Add_h;                  /* '<S697>/Add' */
  const real_T MathFunction_k;         /* '<S697>/Math Function' */
  const real_T Product4_i;             /* '<S688>/Product4' */
  const real_T VT_p;                   /* '<S688>/VT_ref_array' */
  const real_T Add3_mb;                /* '<S836>/Add3' */
  const real_T Gain1_d;                /* '<S836>/Gain1' */
  const real_T Gain_n;                 /* '<S835>/Gain' */
  const real_T Gain2_b;                /* '<S835>/Gain2' */
  const real_T Gain1_e;                /* '<S852>/Gain1' */
  const real_T Gain3_p;                /* '<S852>/Gain3' */
  const real_T Tcell_K_i;              /* '<S703>/Add2' */
  const real_T Add3_l;                 /* '<S703>/Add3' */
  const real_T alpha_Isc_a;            /* '<S703>/alpha_Isc' */
  const real_T Add_n;                  /* '<S703>/Add' */
  const real_T Add4_e;                 /* '<S700>/Add4' */
  const real_T dEgdT_o;                /* '<S700>/dEgdT' */
  const real_T Add3_i;                 /* '<S700>/Add3' */
  const real_T E_g_l;                  /* '<S700>/EgRef' */
  const real_T Tcell_KTref_K_m;        /* '<S700>/Product3' */
  const real_T Fcn_j;                  /* '<S700>/Fcn' */
  const real_T I0_array_d;             /* '<S700>/I0_array' */
  const real_T k1_h;                   /* '<S709>/k1' */
  const real_T Product_g;              /* '<S709>/Product' */
  const real_T Add_b;                  /* '<S709>/Add' */
  const real_T MathFunction_a;         /* '<S709>/Math Function' */
  const real_T Product4_a;             /* '<S700>/Product4' */
  const real_T VT_d;                   /* '<S700>/VT_ref_array' */
  const real_T Add3_a;                 /* '<S495>/Add3' */
  const real_T Gain1_j;                /* '<S495>/Gain1' */
  const real_T Add3_gj;                /* '<S518>/Add3' */
  const real_T Gain1_c;                /* '<S518>/Gain1' */
  const real_T Gain_m;                 /* '<S517>/Gain' */
  const real_T Gain2_f;                /* '<S517>/Gain2' */
  const real_T Gain1_m;                /* '<S534>/Gain1' */
  const real_T Gain3_o;                /* '<S534>/Gain3' */
  const uint8_T Compare;               /* '<S314>/Compare' */
  const uint8_T Compare_e;             /* '<S315>/Compare' */
  const uint8_T Compare_m;             /* '<S934>/Compare' */
  const uint8_T Compare_h;             /* '<S935>/Compare' */
  const uint8_T Compare_b;             /* '<S616>/Compare' */
  const uint8_T Compare_b0;            /* '<S617>/Compare' */
} ConstB_microrrede_v8_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S237>/S-Function'
   *   '<S240>/S-Function'
   *   '<S539>/S-Function'
   *   '<S542>/S-Function'
   *   '<S857>/S-Function'
   *   '<S860>/S-Function'
   *   '<S307>/S-Function'
   *   '<S609>/S-Function'
   *   '<S927>/S-Function'
   *   '<S301>/S-Function'
   *   '<S304>/S-Function'
   *   '<S603>/S-Function'
   *   '<S606>/S-Function'
   *   '<S921>/S-Function'
   *   '<S924>/S-Function'
   */
  real_T SFunction_P1_Size[2];

  /* Pooled Parameter (Expression: MaxDelay)
   * Referenced by:
   *   '<S237>/S-Function'
   *   '<S240>/S-Function'
   *   '<S539>/S-Function'
   *   '<S542>/S-Function'
   *   '<S857>/S-Function'
   *   '<S860>/S-Function'
   *   '<S307>/S-Function'
   *   '<S609>/S-Function'
   *   '<S927>/S-Function'
   *   '<S301>/S-Function'
   *   '<S304>/S-Function'
   *   '<S603>/S-Function'
   *   '<S606>/S-Function'
   *   '<S921>/S-Function'
   *   '<S924>/S-Function'
   */
  real_T pooled13;

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S998>/State-Space'
   *   '<S671>/S-Function'
   *   '<S313>/S-Function'
   *   '<S615>/S-Function'
   *   '<S933>/S-Function'
   *   '<S242>/S-Function'
   *   '<S544>/S-Function'
   *   '<S862>/S-Function'
   *   '<S237>/S-Function'
   *   '<S240>/S-Function'
   *   '<S539>/S-Function'
   *   '<S542>/S-Function'
   *   '<S857>/S-Function'
   *   '<S860>/S-Function'
   *   '<S307>/S-Function'
   *   '<S609>/S-Function'
   *   '<S927>/S-Function'
   *   '<S301>/S-Function'
   *   '<S304>/S-Function'
   *   '<S603>/S-Function'
   *   '<S606>/S-Function'
   *   '<S921>/S-Function'
   *   '<S924>/S-Function'
   */
  real_T SFunction_P2_Size[2];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S998>/State-Space'
   *   '<S671>/S-Function'
   *   '<S313>/S-Function'
   *   '<S615>/S-Function'
   *   '<S933>/S-Function'
   *   '<S242>/S-Function'
   *   '<S544>/S-Function'
   *   '<S862>/S-Function'
   *   '<S237>/S-Function'
   *   '<S240>/S-Function'
   *   '<S539>/S-Function'
   *   '<S542>/S-Function'
   *   '<S857>/S-Function'
   *   '<S860>/S-Function'
   *   '<S307>/S-Function'
   *   '<S609>/S-Function'
   *   '<S927>/S-Function'
   *   '<S301>/S-Function'
   *   '<S304>/S-Function'
   *   '<S603>/S-Function'
   *   '<S606>/S-Function'
   *   '<S921>/S-Function'
   *   '<S924>/S-Function'
   */
  real_T pooled14;

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S998>/State-Space'
   *   '<S671>/S-Function'
   *   '<S313>/S-Function'
   *   '<S615>/S-Function'
   *   '<S933>/S-Function'
   *   '<S242>/S-Function'
   *   '<S544>/S-Function'
   *   '<S862>/S-Function'
   *   '<S237>/S-Function'
   *   '<S240>/S-Function'
   *   '<S539>/S-Function'
   *   '<S542>/S-Function'
   *   '<S857>/S-Function'
   *   '<S860>/S-Function'
   *   '<S307>/S-Function'
   *   '<S609>/S-Function'
   *   '<S927>/S-Function'
   *   '<S301>/S-Function'
   *   '<S304>/S-Function'
   *   '<S603>/S-Function'
   *   '<S606>/S-Function'
   *   '<S921>/S-Function'
   *   '<S924>/S-Function'
   */
  real_T SFunction_P3_Size[2];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S998>/State-Space'
   *   '<S671>/S-Function'
   *   '<S313>/S-Function'
   *   '<S615>/S-Function'
   *   '<S933>/S-Function'
   *   '<S242>/S-Function'
   *   '<S544>/S-Function'
   *   '<S862>/S-Function'
   *   '<S237>/S-Function'
   *   '<S240>/S-Function'
   *   '<S539>/S-Function'
   *   '<S542>/S-Function'
   *   '<S857>/S-Function'
   *   '<S860>/S-Function'
   *   '<S307>/S-Function'
   *   '<S609>/S-Function'
   *   '<S927>/S-Function'
   *   '<S301>/S-Function'
   *   '<S304>/S-Function'
   *   '<S603>/S-Function'
   *   '<S606>/S-Function'
   *   '<S921>/S-Function'
   *   '<S924>/S-Function'
   */
  real_T pooled15;

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S998>/State-Space'
   *   '<S671>/S-Function'
   *   '<S313>/S-Function'
   *   '<S615>/S-Function'
   *   '<S933>/S-Function'
   *   '<S242>/S-Function'
   *   '<S544>/S-Function'
   *   '<S862>/S-Function'
   *   '<S237>/S-Function'
   *   '<S240>/S-Function'
   *   '<S539>/S-Function'
   *   '<S542>/S-Function'
   *   '<S857>/S-Function'
   *   '<S860>/S-Function'
   *   '<S307>/S-Function'
   *   '<S609>/S-Function'
   *   '<S927>/S-Function'
   *   '<S301>/S-Function'
   *   '<S304>/S-Function'
   *   '<S603>/S-Function'
   *   '<S606>/S-Function'
   *   '<S921>/S-Function'
   *   '<S924>/S-Function'
   */
  real_T SFunction_P4_Size[2];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S998>/State-Space'
   *   '<S671>/S-Function'
   *   '<S313>/S-Function'
   *   '<S615>/S-Function'
   *   '<S933>/S-Function'
   *   '<S242>/S-Function'
   *   '<S544>/S-Function'
   *   '<S862>/S-Function'
   *   '<S237>/S-Function'
   *   '<S240>/S-Function'
   *   '<S539>/S-Function'
   *   '<S542>/S-Function'
   *   '<S857>/S-Function'
   *   '<S860>/S-Function'
   *   '<S307>/S-Function'
   *   '<S609>/S-Function'
   *   '<S927>/S-Function'
   *   '<S301>/S-Function'
   *   '<S304>/S-Function'
   *   '<S603>/S-Function'
   *   '<S606>/S-Function'
   *   '<S921>/S-Function'
   *   '<S924>/S-Function'
   */
  real_T pooled16;

  /* Expression: zeros(25,1)
   * Referenced by: '<S1002>/SwitchCurrents'
   */
  real_T SwitchCurrents_Value[25];

  /* Pooled Parameter (Expression: Vf)
   * Referenced by:
   *   '<S105>/eee'
   *   '<S369>/eee'
   *   '<S989>/eee'
   */
  real_T pooled19;

  /* Computed Parameter: StateSpace_P2_Size
   * Referenced by: '<S998>/State-Space'
   */
  real_T StateSpace_P2_Size[2];

  /* Expression: S.A
   * Referenced by: '<S998>/State-Space'
   */
  real_T StateSpace_P2[784];

  /* Computed Parameter: StateSpace_P3_Size
   * Referenced by: '<S998>/State-Space'
   */
  real_T StateSpace_P3_Size[2];

  /* Expression: S.B
   * Referenced by: '<S998>/State-Space'
   */
  real_T StateSpace_P3[1596];

  /* Computed Parameter: StateSpace_P4_Size
   * Referenced by: '<S998>/State-Space'
   */
  real_T StateSpace_P4_Size[2];

  /* Expression: S.C
   * Referenced by: '<S998>/State-Space'
   */
  real_T StateSpace_P4[2380];

  /* Computed Parameter: StateSpace_P5_Size
   * Referenced by: '<S998>/State-Space'
   */
  real_T StateSpace_P5_Size[2];

  /* Expression: S.D
   * Referenced by: '<S998>/State-Space'
   */
  real_T StateSpace_P5[4845];

  /* Computed Parameter: StateSpace_P6_Size
   * Referenced by: '<S998>/State-Space'
   */
  real_T StateSpace_P6_Size[2];

  /* Expression: S.x0
   * Referenced by: '<S998>/State-Space'
   */
  real_T StateSpace_P6[28];

  /* Computed Parameter: StateSpace_P8_Size
   * Referenced by: '<S998>/State-Space'
   */
  real_T StateSpace_P8_Size[2];

  /* Expression: S.NonLinearDim
   * Referenced by: '<S998>/State-Space'
   */
  real_T StateSpace_P8[9];

  /* Computed Parameter: StateSpace_P10_Size
   * Referenced by: '<S998>/State-Space'
   */
  real_T StateSpace_P10_Size[2];

  /* Expression: S.NonLinear_Inputs
   * Referenced by: '<S998>/State-Space'
   */
  real_T StateSpace_P10[3];

  /* Computed Parameter: StateSpace_P11_Size
   * Referenced by: '<S998>/State-Space'
   */
  real_T StateSpace_P11_Size[2];

  /* Expression: S.NonLinear_Outputs
   * Referenced by: '<S998>/State-Space'
   */
  real_T StateSpace_P11[3];

  /* Pooled Parameter (Expression: )
   * Referenced by: '<S998>/State-Space'
   */
  real_T StateSpace_P13_Size[2];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by: '<S998>/State-Space'
   */
  real_T pooled50[3];

  /* Computed Parameter: StateSpace_P16_Size
   * Referenced by: '<S998>/State-Space'
   */
  real_T StateSpace_P16_Size[2];

  /* Expression: S.NonLinear_Method
   * Referenced by: '<S998>/State-Space'
   */
  real_T StateSpace_P16[3];

  /* Computed Parameter: StateSpace_P17_Size
   * Referenced by: '<S998>/State-Space'
   */
  real_T StateSpace_P17_Size[2];

  /* Expression: S.Nonlinear_Tolerance
   * Referenced by: '<S998>/State-Space'
   */
  real_T StateSpace_P17;

  /* Computed Parameter: StateSpace_P18_Size
   * Referenced by: '<S998>/State-Space'
   */
  real_T StateSpace_P18_Size[2];

  /* Expression: double(nMaxIteration)
   * Referenced by: '<S998>/State-Space'
   */
  real_T StateSpace_P18;

  /* Computed Parameter: StateSpace_P20_Size
   * Referenced by: '<S998>/State-Space'
   */
  real_T StateSpace_P20_Size[2];

  /* Expression: S.SwitchResistance
   * Referenced by: '<S998>/State-Space'
   */
  real_T StateSpace_P20[41];

  /* Computed Parameter: StateSpace_P21_Size
   * Referenced by: '<S998>/State-Space'
   */
  real_T StateSpace_P21_Size[2];

  /* Expression: S.SwitchType
   * Referenced by: '<S998>/State-Space'
   */
  real_T StateSpace_P21[41];

  /* Computed Parameter: StateSpace_P22_Size
   * Referenced by: '<S998>/State-Space'
   */
  real_T StateSpace_P22_Size[2];

  /* Expression: S.SwitchGateInitialValue
   * Referenced by: '<S998>/State-Space'
   */
  real_T StateSpace_P22[41];

  /* Computed Parameter: StateSpace_P23_Size
   * Referenced by: '<S998>/State-Space'
   */
  real_T StateSpace_P23_Size[2];

  /* Expression: S.OutputsToResetToZero
   * Referenced by: '<S998>/State-Space'
   */
  real_T StateSpace_P23[41];

  /* Pooled Parameter (Expression: [0 2 0])
   * Referenced by:
   *   '<S504>/1-D Lookup Table'
   *   '<S225>/1-D Lookup Table'
   *   '<S527>/1-D Lookup Table'
   *   '<S845>/1-D Lookup Table'
   */
  real_T pooled57[3];

  /* Pooled Parameter (Expression: [0 .5 1])
   * Referenced by:
   *   '<S504>/1-D Lookup Table'
   *   '<S225>/1-D Lookup Table'
   *   '<S527>/1-D Lookup Table'
   *   '<S845>/1-D Lookup Table'
   */
  real_T pooled58[3];

  /* Pooled Parameter (Expression: sps.Delay)
   * Referenced by:
   *   '<S670>/K1'
   *   '<S241>/K1'
   *   '<S543>/K1'
   *   '<S861>/K1'
   */
  real_T pooled59;

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S671>/S-Function'
   *   '<S242>/S-Function'
   *   '<S544>/S-Function'
   *   '<S862>/S-Function'
   */
  real_T SFunction_P1_Size_e[2];

  /* Pooled Parameter (Expression: MaxDelay)
   * Referenced by:
   *   '<S671>/S-Function'
   *   '<S242>/S-Function'
   *   '<S544>/S-Function'
   *   '<S862>/S-Function'
   */
  real_T pooled60;
} ConstP_microrrede_v8_T;

/* Constant parameters with dynamic initialization (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: )
   * Referenced by: '<S998>/State-Space'
   */
  real_T StateSpace_P9_Size[2];
} ConstInitP_microrrede_v8_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Irr1;                         /* '<Root>/Irr1' */
  real_T Irr2;                         /* '<Root>/Irr2' */
  real_T Irr3;                         /* '<Root>/Irr3' */
  real_T XCBR_PCC_in;                  /* '<Root>/XCBR_PCC_in' */
  real_T LoadA;                        /* '<Root>/LoadA' */
  real_T LoadB;                        /* '<Root>/LoadB' */
  real_T LoadC;                        /* '<Root>/LoadC' */
  real_T Fator1;                       /* '<Root>/Fator1' */
  real_T Fator2;                       /* '<Root>/Fator2' */
  real_T Fator3;                       /* '<Root>/Fator3' */
  real_T XCBR_N_in;                    /* '<Root>/XCBR_N_in' */
  real_T XCBR_CC_3_in;                 /* '<Root>/XCBR_CC_3_in' */
  real_T XCBR_CC_2_in;                 /* '<Root>/XCBR_CC_2_in' */
  real_T XCBR_CC_1_in;                 /* '<Root>/XCBR_CC_1_in' */
  real_T XCBR_banco3p_in;              /* '<Root>/XCBR_banco3p_in' */
  real_T XCBR_banco1p_in;              /* '<Root>/XCBR_banco1p_in' */
} ExtU_microrrede_v8_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T VPCC1[3];                     /* '<Root>/V PCC 1' */
  real_T IPCC1[3];                     /* '<Root>/I PCC 1' */
  real_T VPCC2[3];                     /* '<Root>/V PCC 2' */
  real_T IPCC2[3];                     /* '<Root>/I PCC 2' */
  real_T XCBR_PCC_out;                 /* '<Root>/XCBR_PCC_out' */
  real_T Vload3[3];                    /* '<Root>/Vload3' */
  real_T Iload3[3];                    /* '<Root>/Iload3' */
  real_T XCBR_N_out;                   /* '<Root>/XCBR_N_out' */
  real_T XCBR_CC_3_out;                /* '<Root>/XCBR_CC_3_out' */
  real_T XCBR_CC_2_out;                /* '<Root>/XCBR_CC_2_out' */
  real_T XCBR_CC_1_out;                /* '<Root>/XCBR_CC_1_out' */
  real_T I3;                           /* '<Root>/I3' */
  real_T V3;                           /* '<Root>/V3' */
  real_T I2;                           /* '<Root>/I2' */
  real_T V2;                           /* '<Root>/V2' */
  real_T I1;                           /* '<Root>/I1' */
  real_T V1;                           /* '<Root>/V1' */
  real_T XCBR_banco3p_out;             /* '<Root>/XCBR_banco3p_out' */
  real_T XCBR_banco1p_out;             /* '<Root>/XCBR_banco1p_out' */
} ExtY_microrrede_v8_T;

/* Real-time Model Data Structure */
struct tag_RTM_microrrede_v8_T {
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    time_T *taskTimePtrs[1];
    SimStruct childSFunctions[23];
    SimStruct *childSFunctionPtrs[23];
    struct _ssBlkInfo2 blkInfo2[23];
    struct _ssSFcnModelMethods2 methods2[23];
    struct _ssSFcnModelMethods3 methods3[23];
    struct _ssSFcnModelMethods4 methods4[23];
    struct _ssStatesInfo2 statesInfo2[23];
    ssPeriodicStatesInfo periodicStatesInfo[23];
    struct _ssPortInfo2 inputOutputPortInfo2[23];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      struct _ssInPortUnit inputPortUnits[2];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[2];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn0;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      struct _ssInPortUnit inputPortUnits[2];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[2];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn1;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      struct _ssInPortUnit inputPortUnits[2];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[2];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn2;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      struct _ssInPortUnit inputPortUnits[2];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[2];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn3;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      struct _ssInPortUnit inputPortUnits[2];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[2];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn4;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      struct _ssInPortUnit inputPortUnits[2];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[2];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn5;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[3];
      struct _ssInPortUnit inputPortUnits[3];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[3];
      real_T const *UPtrs0[57];
      real_T const *UPtrs1[41];
      real_T const *UPtrs2[3];
      struct _ssPortOutputs outputPortInfo[3];
      struct _ssOutPortUnit outputPortUnits[3];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[3];
      uint_T attribs[24];
      mxArray *params[24];
      struct _ssDWorkRecord dWork[4];
      struct _ssDWorkAuxRecord dWorkAux[4];
    } Sfcn6;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      struct _ssInPortUnit inputPortUnits[2];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[2];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn7;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      struct _ssInPortUnit inputPortUnits[2];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[2];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn8;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      struct _ssInPortUnit inputPortUnits[2];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[2];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn9;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      struct _ssInPortUnit inputPortUnits[2];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[2];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn10;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      struct _ssInPortUnit inputPortUnits[2];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[2];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn11;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      struct _ssInPortUnit inputPortUnits[2];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[2];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn12;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      struct _ssInPortUnit inputPortUnits[2];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[2];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn13;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      struct _ssInPortUnit inputPortUnits[2];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[2];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn14;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      struct _ssInPortUnit inputPortUnits[2];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[2];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn15;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      struct _ssInPortUnit inputPortUnits[2];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[2];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn16;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      struct _ssInPortUnit inputPortUnits[2];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[2];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn17;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      struct _ssInPortUnit inputPortUnits[2];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[2];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn18;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      struct _ssInPortUnit inputPortUnits[2];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[2];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn19;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      struct _ssInPortUnit inputPortUnits[2];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[2];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn20;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      struct _ssInPortUnit inputPortUnits[2];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[2];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn21;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      struct _ssInPortUnit inputPortUnits[2];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[2];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn22;
  } NonInlinedSFcns;

  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T options;
    int_T numContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[1];
    time_T offsetTimesArray[1];
    int_T sampleTimeTaskIDArray[1];
    int_T sampleHitArray[1];
    int_T perTaskSampleHitsArray[1];
    time_T tArray[1];
  } Timing;
};

/* Block signals (default storage) */
extern B_microrrede_v8_T microrrede_v8_B;

/* Block states (default storage) */
extern DW_microrrede_v8_T microrrede_v8_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_microrrede_v8_T microrrede_v8_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_microrrede_v8_T microrrede_v8_Y;

/* External data declarations for dependent source files */
extern const real_T microrrede_v8_RGND;/* real_T ground */
extern const ConstB_microrrede_v8_T microrrede_v8_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_microrrede_v8_T microrrede_v8_ConstP;

/* Constant parameters with dynamic initialization (default storage) */
extern ConstInitP_microrrede_v8_T microrrede_v8_ConstInitP;/* constant parameters */

/* Model entry point functions */
extern void microrrede_v8_initialize(void);
extern void microrrede_v8_step(void);
extern void microrrede_v8_terminate(void);

/* Real-time Model object */
extern RT_MODEL_microrrede_v8_T *const microrrede_v8_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S39>/Add' : Unused code path elimination
 * Block '<S39>/Fcn1' : Unused code path elimination
 * Block '<S39>/R' : Unused code path elimination
 * Block '<S39>/R4' : Unused code path elimination
 * Block '<S39>/Saturation' : Unused code path elimination
 * Block '<S45>/Data Type Duplicate' : Unused code path elimination
 * Block '<S45>/Data Type Propagation' : Unused code path elimination
 * Block '<S46>/Data Type Duplicate' : Unused code path elimination
 * Block '<S46>/Data Type Propagation' : Unused code path elimination
 * Block '<S47>/Data Type Duplicate' : Unused code path elimination
 * Block '<S47>/Data Type Propagation' : Unused code path elimination
 * Block '<S1>/Ta' : Unused code path elimination
 * Block '<S2>/Display' : Unused code path elimination
 * Block '<S2>/Product1' : Unused code path elimination
 * Block '<S105>/0 1' : Unused code path elimination
 * Block '<S105>/Gain' : Unused code path elimination
 * Block '<S105>/Saturation' : Unused code path elimination
 * Block '<S105>/Sum' : Unused code path elimination
 * Block '<S105>/Switch' : Unused code path elimination
 * Block '<S107>/0 4' : Unused code path elimination
 * Block '<S107>/1//Rsw' : Unused code path elimination
 * Block '<S107>/Switch' : Unused code path elimination
 * Block '<S140>/0 1' : Unused code path elimination
 * Block '<S140>/1//Rsw' : Unused code path elimination
 * Block '<S140>/Switch' : Unused code path elimination
 * Block '<S142>/0 1' : Unused code path elimination
 * Block '<S142>/1//Rsw' : Unused code path elimination
 * Block '<S142>/Switch' : Unused code path elimination
 * Block '<S144>/0 1' : Unused code path elimination
 * Block '<S144>/1//Rsw' : Unused code path elimination
 * Block '<S144>/Switch' : Unused code path elimination
 * Block '<S146>/0 1' : Unused code path elimination
 * Block '<S146>/1//Rsw' : Unused code path elimination
 * Block '<S146>/Switch' : Unused code path elimination
 * Block '<S148>/0 1' : Unused code path elimination
 * Block '<S148>/1//Rsw' : Unused code path elimination
 * Block '<S148>/Switch' : Unused code path elimination
 * Block '<S150>/0 1' : Unused code path elimination
 * Block '<S150>/1//Rsw' : Unused code path elimination
 * Block '<S150>/Switch' : Unused code path elimination
 * Block '<S153>/Display' : Unused code path elimination
 * Block '<S153>/Product1' : Unused code path elimination
 * Block '<S296>/Rad->Deg.' : Unused code path elimination
 * Block '<S231>/Constant' : Unused code path elimination
 * Block '<S369>/0 1' : Unused code path elimination
 * Block '<S369>/Gain' : Unused code path elimination
 * Block '<S369>/Saturation' : Unused code path elimination
 * Block '<S369>/Sum' : Unused code path elimination
 * Block '<S369>/Switch' : Unused code path elimination
 * Block '<S371>/0 4' : Unused code path elimination
 * Block '<S371>/1//Rsw' : Unused code path elimination
 * Block '<S371>/Switch' : Unused code path elimination
 * Block '<S156>/do not delete this gain' : Unused code path elimination
 * Block '<S374>/0 4' : Unused code path elimination
 * Block '<S374>/1//Ron' : Unused code path elimination
 * Block '<S374>/Saturation' : Unused code path elimination
 * Block '<S374>/Switch' : Unused code path elimination
 * Block '<S374>/Unit Delay' : Unused code path elimination
 * Block '<S375>/Switch' : Unused code path elimination
 * Block '<S375>/Vf Devices & Clamping Diodes' : Unused code path elimination
 * Block '<S375>/Vf Diodes' : Unused code path elimination
 * Block '<S159>/do not delete this gain' : Unused code path elimination
 * Block '<S378>/Add' : Unused code path elimination
 * Block '<S388>/0 1' : Unused code path elimination
 * Block '<S388>/Gain' : Unused code path elimination
 * Block '<S388>/Saturation' : Unused code path elimination
 * Block '<S388>/Sum' : Unused code path elimination
 * Block '<S388>/Switch' : Unused code path elimination
 * Block '<S388>/eee' : Unused code path elimination
 * Block '<S390>/0 1' : Unused code path elimination
 * Block '<S390>/1//Rsw' : Unused code path elimination
 * Block '<S390>/Switch' : Unused code path elimination
 * Block '<S379>/Add' : Unused code path elimination
 * Block '<S395>/0 1' : Unused code path elimination
 * Block '<S395>/Gain' : Unused code path elimination
 * Block '<S395>/Saturation' : Unused code path elimination
 * Block '<S395>/Sum' : Unused code path elimination
 * Block '<S395>/Switch' : Unused code path elimination
 * Block '<S395>/eee' : Unused code path elimination
 * Block '<S397>/0 1' : Unused code path elimination
 * Block '<S397>/1//Rsw' : Unused code path elimination
 * Block '<S397>/Switch' : Unused code path elimination
 * Block '<S508>/0 4' : Unused code path elimination
 * Block '<S508>/1//Ron' : Unused code path elimination
 * Block '<S508>/Saturation' : Unused code path elimination
 * Block '<S508>/Switch' : Unused code path elimination
 * Block '<S508>/Unit Delay' : Unused code path elimination
 * Block '<S509>/Switch' : Unused code path elimination
 * Block '<S509>/Vf Devices & Clamping Diodes' : Unused code path elimination
 * Block '<S509>/Vf Diodes' : Unused code path elimination
 * Block '<S598>/Rad->Deg.' : Unused code path elimination
 * Block '<S533>/Constant' : Unused code path elimination
 * Block '<S511>/do not delete this gain' : Unused code path elimination
 * Block '<S672>/0 4' : Unused code path elimination
 * Block '<S672>/1//Ron' : Unused code path elimination
 * Block '<S672>/Saturation' : Unused code path elimination
 * Block '<S672>/Switch' : Unused code path elimination
 * Block '<S672>/Unit Delay' : Unused code path elimination
 * Block '<S673>/Switch' : Unused code path elimination
 * Block '<S673>/Vf Devices & Clamping Diodes' : Unused code path elimination
 * Block '<S673>/Vf Diodes' : Unused code path elimination
 * Block '<S21>/Scope8' : Unused code path elimination
 * Block '<S515>/do not delete this gain' : Unused code path elimination
 * Block '<Root>/Scope Baterias' : Unused code path elimination
 * Block '<Root>/Scope Ig3' : Unused code path elimination
 * Block '<Root>/Scope V offgrid' : Unused code path elimination
 * Block '<Root>/Scope Vdc' : Unused code path elimination
 * Block '<Root>/Scope Vg1' : Unused code path elimination
 * Block '<Root>/Scope Vg2' : Unused code path elimination
 * Block '<Root>/Scope load' : Unused code path elimination
 * Block '<S34>/do not delete this gain' : Unused code path elimination
 * Block '<S773>/Display' : Unused code path elimination
 * Block '<S773>/Product1' : Unused code path elimination
 * Block '<S916>/Rad->Deg.' : Unused code path elimination
 * Block '<S851>/Constant' : Unused code path elimination
 * Block '<S989>/0 1' : Unused code path elimination
 * Block '<S989>/Gain' : Unused code path elimination
 * Block '<S989>/Saturation' : Unused code path elimination
 * Block '<S989>/Sum' : Unused code path elimination
 * Block '<S989>/Switch' : Unused code path elimination
 * Block '<S991>/0 4' : Unused code path elimination
 * Block '<S991>/1//Rsw' : Unused code path elimination
 * Block '<S991>/Switch' : Unused code path elimination
 * Block '<S776>/do not delete this gain' : Unused code path elimination
 * Block '<S994>/0 4' : Unused code path elimination
 * Block '<S994>/1//Ron' : Unused code path elimination
 * Block '<S994>/Saturation' : Unused code path elimination
 * Block '<S994>/Switch' : Unused code path elimination
 * Block '<S994>/Unit Delay' : Unused code path elimination
 * Block '<S995>/Switch' : Unused code path elimination
 * Block '<S995>/Vf Devices & Clamping Diodes' : Unused code path elimination
 * Block '<S995>/Vf Diodes' : Unused code path elimination
 * Block '<S779>/do not delete this gain' : Unused code path elimination
 * Block '<S38>/do not delete this gain' : Eliminated nontunable gain of 1
 * Block '<S107>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S116>/Data Type  Conversion' : Eliminate redundant data type conversion
 * Block '<S118>/Data Type  Conversion' : Eliminate redundant data type conversion
 * Block '<S120>/Data Type  Conversion' : Eliminate redundant data type conversion
 * Block '<S123>/Data Type  Conversion' : Eliminate redundant data type conversion
 * Block '<S125>/Data Type  Conversion' : Eliminate redundant data type conversion
 * Block '<S131>/Data Type  Conversion' : Eliminate redundant data type conversion
 * Block '<S133>/Data Type  Conversion' : Eliminate redundant data type conversion
 * Block '<S135>/Data Type  Conversion' : Eliminate redundant data type conversion
 * Block '<S138>/Data Type  Conversion' : Eliminate redundant data type conversion
 * Block '<S140>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S142>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S144>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S146>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S148>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S150>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S371>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S374>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S158>/do not delete this gain' : Eliminated nontunable gain of 1
 * Block '<S390>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S435>/Proportional Gain' : Eliminated nontunable gain of 1
 * Block '<S508>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S672>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S514>/do not delete this gain' : Eliminated nontunable gain of 1
 * Block '<S679>/Npar' : Eliminated nontunable gain of 1
 * Block '<S680>/do not delete this gain' : Eliminated nontunable gain of 1
 * Block '<S682>/do not delete this gain' : Eliminated nontunable gain of 1
 * Block '<S691>/Npar' : Eliminated nontunable gain of 1
 * Block '<S692>/do not delete this gain' : Eliminated nontunable gain of 1
 * Block '<S694>/do not delete this gain' : Eliminated nontunable gain of 1
 * Block '<S703>/Npar' : Eliminated nontunable gain of 1
 * Block '<S704>/do not delete this gain' : Eliminated nontunable gain of 1
 * Block '<S706>/do not delete this gain' : Eliminated nontunable gain of 1
 * Block '<S25>/Kv' : Eliminated nontunable gain of 1
 * Block '<S25>/Kv1' : Eliminated nontunable gain of 1
 * Block '<S715>/do not delete this gain' : Eliminated nontunable gain of 1
 * Block '<S716>/do not delete this gain' : Eliminated nontunable gain of 1
 * Block '<S717>/do not delete this gain' : Eliminated nontunable gain of 1
 * Block '<S718>/do not delete this gain' : Eliminated nontunable gain of 1
 * Block '<S719>/do not delete this gain' : Eliminated nontunable gain of 1
 * Block '<S720>/do not delete this gain' : Eliminated nontunable gain of 1
 * Block '<S26>/Kv' : Eliminated nontunable gain of 1
 * Block '<S26>/Kv1' : Eliminated nontunable gain of 1
 * Block '<S730>/do not delete this gain' : Eliminated nontunable gain of 1
 * Block '<S731>/do not delete this gain' : Eliminated nontunable gain of 1
 * Block '<S732>/do not delete this gain' : Eliminated nontunable gain of 1
 * Block '<S733>/do not delete this gain' : Eliminated nontunable gain of 1
 * Block '<S734>/do not delete this gain' : Eliminated nontunable gain of 1
 * Block '<S735>/do not delete this gain' : Eliminated nontunable gain of 1
 * Block '<S27>/Kv' : Eliminated nontunable gain of 1
 * Block '<S27>/Kv1' : Eliminated nontunable gain of 1
 * Block '<S745>/do not delete this gain' : Eliminated nontunable gain of 1
 * Block '<S746>/do not delete this gain' : Eliminated nontunable gain of 1
 * Block '<S747>/do not delete this gain' : Eliminated nontunable gain of 1
 * Block '<S748>/do not delete this gain' : Eliminated nontunable gain of 1
 * Block '<S749>/do not delete this gain' : Eliminated nontunable gain of 1
 * Block '<S750>/do not delete this gain' : Eliminated nontunable gain of 1
 * Block '<S757>/Reshape' : Reshape block reduction
 * Block '<S761>/Reshape' : Reshape block reduction
 * Block '<S765>/Reshape' : Reshape block reduction
 * Block '<S991>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S994>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S778>/do not delete this gain' : Eliminated nontunable gain of 1
 * Block '<S116>/C4' : Unused code path elimination
 * Block '<S117>/Digital Clock' : Unused code path elimination
 * Block '<S117>/Look-Up Table' : Unused code path elimination
 * Block '<S118>/C4' : Unused code path elimination
 * Block '<S119>/Digital Clock' : Unused code path elimination
 * Block '<S119>/Look-Up Table' : Unused code path elimination
 * Block '<S120>/C4' : Unused code path elimination
 * Block '<S121>/Digital Clock' : Unused code path elimination
 * Block '<S121>/Look-Up Table' : Unused code path elimination
 * Block '<S7>/C4' : Unused code path elimination
 * Block '<S7>/Constant1' : Unused code path elimination
 * Block '<S7>/Constant2' : Unused code path elimination
 * Block '<S7>/Constant3' : Unused code path elimination
 * Block '<S122>/Digital Clock' : Unused code path elimination
 * Block '<S122>/Look-Up Table' : Unused code path elimination
 * Block '<S7>/Switch3' : Unused code path elimination
 * Block '<S123>/C4' : Unused code path elimination
 * Block '<S124>/Digital Clock' : Unused code path elimination
 * Block '<S124>/Look-Up Table' : Unused code path elimination
 * Block '<S125>/C4' : Unused code path elimination
 * Block '<S126>/Digital Clock' : Unused code path elimination
 * Block '<S126>/Look-Up Table' : Unused code path elimination
 * Block '<S131>/C4' : Unused code path elimination
 * Block '<S132>/Digital Clock' : Unused code path elimination
 * Block '<S132>/Look-Up Table' : Unused code path elimination
 * Block '<S133>/C4' : Unused code path elimination
 * Block '<S134>/Digital Clock' : Unused code path elimination
 * Block '<S134>/Look-Up Table' : Unused code path elimination
 * Block '<S135>/C4' : Unused code path elimination
 * Block '<S136>/Digital Clock' : Unused code path elimination
 * Block '<S136>/Look-Up Table' : Unused code path elimination
 * Block '<S10>/C4' : Unused code path elimination
 * Block '<S10>/Constant1' : Unused code path elimination
 * Block '<S10>/Constant2' : Unused code path elimination
 * Block '<S10>/Constant3' : Unused code path elimination
 * Block '<S137>/Digital Clock' : Unused code path elimination
 * Block '<S137>/Look-Up Table' : Unused code path elimination
 * Block '<S10>/Switch3' : Unused code path elimination
 * Block '<S138>/C4' : Unused code path elimination
 * Block '<S139>/Digital Clock' : Unused code path elimination
 * Block '<S139>/Look-Up Table' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'microrrede_v8'
 * '<S1>'   : 'microrrede_v8/Baterias'
 * '<S2>'   : 'microrrede_v8/Controle Boost com MPPT   '
 * '<S3>'   : 'microrrede_v8/Conversor boost SFV1'
 * '<S4>'   : 'microrrede_v8/Current Measurement I1'
 * '<S5>'   : 'microrrede_v8/Current Measurement I2'
 * '<S6>'   : 'microrrede_v8/Current Measurement I3'
 * '<S7>'   : 'microrrede_v8/Disjuntor Banco Trifásico'
 * '<S8>'   : 'microrrede_v8/Disjuntor CTA 1'
 * '<S9>'   : 'microrrede_v8/Disjuntor CTA 2'
 * '<S10>'  : 'microrrede_v8/Disjuntor PCC'
 * '<S11>'  : 'microrrede_v8/Disjuntor de neutro'
 * '<S12>'  : 'microrrede_v8/Disjuntor+1'
 * '<S13>'  : 'microrrede_v8/Disjuntor+2'
 * '<S14>'  : 'microrrede_v8/Disjuntor+3'
 * '<S15>'  : 'microrrede_v8/Disjuntor-1'
 * '<S16>'  : 'microrrede_v8/Disjuntor-2'
 * '<S17>'  : 'microrrede_v8/Disjuntor-3'
 * '<S18>'  : 'microrrede_v8/ENEL'
 * '<S19>'  : 'microrrede_v8/Inversor Fronius'
 * '<S20>'  : 'microrrede_v8/Inversor SMA offgrid'
 * '<S21>'  : 'microrrede_v8/Inversor SMA ongrid'
 * '<S22>'  : 'microrrede_v8/SFV1'
 * '<S23>'  : 'microrrede_v8/SFV2'
 * '<S24>'  : 'microrrede_v8/SFV3'
 * '<S25>'  : 'microrrede_v8/VI PCC 1'
 * '<S26>'  : 'microrrede_v8/VI PCC 2'
 * '<S27>'  : 'microrrede_v8/VI banco de cargas trifásico'
 * '<S28>'  : 'microrrede_v8/Variable Resistor'
 * '<S29>'  : 'microrrede_v8/Variable Resistor1'
 * '<S30>'  : 'microrrede_v8/Variable Resistor2'
 * '<S31>'  : 'microrrede_v8/Voltage Measurement V1'
 * '<S32>'  : 'microrrede_v8/Voltage Measurement V2'
 * '<S33>'  : 'microrrede_v8/Voltage Measurement V3'
 * '<S34>'  : 'microrrede_v8/Voltage Measurement Voffgrid'
 * '<S35>'  : 'microrrede_v8/inversor Replus'
 * '<S36>'  : 'microrrede_v8/powergui'
 * '<S37>'  : 'microrrede_v8/Baterias/Controlled Voltage Source'
 * '<S38>'  : 'microrrede_v8/Baterias/Current Measurement'
 * '<S39>'  : 'microrrede_v8/Baterias/Model'
 * '<S40>'  : 'microrrede_v8/Baterias/Current Measurement/Model'
 * '<S41>'  : 'microrrede_v8/Baterias/Model/Compare To Zero'
 * '<S42>'  : 'microrrede_v8/Baterias/Model/Compare To Zero2'
 * '<S43>'  : 'microrrede_v8/Baterias/Model/E_dyn Charge'
 * '<S44>'  : 'microrrede_v8/Baterias/Model/Exp'
 * '<S45>'  : 'microrrede_v8/Baterias/Model/Saturation Dynamic'
 * '<S46>'  : 'microrrede_v8/Baterias/Model/Saturation Dynamic1'
 * '<S47>'  : 'microrrede_v8/Baterias/Model/Saturation Dynamic2'
 * '<S48>'  : 'microrrede_v8/Baterias/Model/Exp/Compare To Zero2'
 * '<S49>'  : 'microrrede_v8/Controle Boost com MPPT   /MATLAB Function'
 * '<S50>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller'
 * '<S51>'  : 'microrrede_v8/Controle Boost com MPPT   /PWM Generator (DC-DC)'
 * '<S52>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller/Anti-windup'
 * '<S53>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller/D Gain'
 * '<S54>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller/Filter'
 * '<S55>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller/Filter ICs'
 * '<S56>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller/I Gain'
 * '<S57>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller/Ideal P Gain'
 * '<S58>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller/Ideal P Gain Fdbk'
 * '<S59>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller/Integrator'
 * '<S60>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller/Integrator ICs'
 * '<S61>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller/N Copy'
 * '<S62>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller/N Gain'
 * '<S63>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller/P Copy'
 * '<S64>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller/Parallel P Gain'
 * '<S65>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller/Reset Signal'
 * '<S66>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller/Saturation'
 * '<S67>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller/Saturation Fdbk'
 * '<S68>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller/Sum'
 * '<S69>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller/Sum Fdbk'
 * '<S70>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller/Tracking Mode'
 * '<S71>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller/Tracking Mode Sum'
 * '<S72>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller/Tsamp - Integral'
 * '<S73>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller/Tsamp - Ngain'
 * '<S74>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller/postSat Signal'
 * '<S75>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller/preSat Signal'
 * '<S76>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller/Anti-windup/Passthrough'
 * '<S77>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller/D Gain/Disabled'
 * '<S78>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller/Filter/Disabled'
 * '<S79>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller/Filter ICs/Disabled'
 * '<S80>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller/I Gain/Internal Parameters'
 * '<S81>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller/Ideal P Gain/Passthrough'
 * '<S82>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S83>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller/Integrator/Discrete'
 * '<S84>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller/Integrator ICs/Internal IC'
 * '<S85>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller/N Copy/Disabled wSignal Specification'
 * '<S86>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller/N Gain/Disabled'
 * '<S87>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller/P Copy/Disabled'
 * '<S88>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller/Parallel P Gain/Internal Parameters'
 * '<S89>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller/Reset Signal/Disabled'
 * '<S90>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller/Saturation/Passthrough'
 * '<S91>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller/Saturation Fdbk/Disabled'
 * '<S92>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller/Sum/Sum_PI'
 * '<S93>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller/Sum Fdbk/Disabled'
 * '<S94>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller/Tracking Mode/Disabled'
 * '<S95>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller/Tracking Mode Sum/Passthrough'
 * '<S96>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S97>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller/Tsamp - Ngain/Passthrough'
 * '<S98>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller/postSat Signal/Forward_Path'
 * '<S99>'  : 'microrrede_v8/Controle Boost com MPPT   /PID Controller/preSat Signal/Forward_Path'
 * '<S100>' : 'microrrede_v8/Controle Boost com MPPT   /PWM Generator (DC-DC)/Compare To Zero'
 * '<S101>' : 'microrrede_v8/Controle Boost com MPPT   /PWM Generator (DC-DC)/Sawtooth Generator'
 * '<S102>' : 'microrrede_v8/Controle Boost com MPPT   /PWM Generator (DC-DC)/Sawtooth Generator/Model'
 * '<S103>' : 'microrrede_v8/Conversor boost SFV1/Diode'
 * '<S104>' : 'microrrede_v8/Conversor boost SFV1/IGBT//Diode'
 * '<S105>' : 'microrrede_v8/Conversor boost SFV1/Diode/Model'
 * '<S106>' : 'microrrede_v8/Conversor boost SFV1/Diode/Model/Measurement list'
 * '<S107>' : 'microrrede_v8/Conversor boost SFV1/IGBT//Diode/Model'
 * '<S108>' : 'microrrede_v8/Conversor boost SFV1/IGBT//Diode/Model/Measurement list'
 * '<S109>' : 'microrrede_v8/Current Measurement I1/Model'
 * '<S110>' : 'microrrede_v8/Current Measurement I2/Model'
 * '<S111>' : 'microrrede_v8/Current Measurement I3/Model'
 * '<S112>' : 'microrrede_v8/Disjuntor Banco Trifásico/Breaker A'
 * '<S113>' : 'microrrede_v8/Disjuntor Banco Trifásico/Breaker B'
 * '<S114>' : 'microrrede_v8/Disjuntor Banco Trifásico/Breaker C'
 * '<S115>' : 'microrrede_v8/Disjuntor Banco Trifásico/Stair Generator'
 * '<S116>' : 'microrrede_v8/Disjuntor Banco Trifásico/Breaker A/Model'
 * '<S117>' : 'microrrede_v8/Disjuntor Banco Trifásico/Breaker A/Model/Timer'
 * '<S118>' : 'microrrede_v8/Disjuntor Banco Trifásico/Breaker B/Model'
 * '<S119>' : 'microrrede_v8/Disjuntor Banco Trifásico/Breaker B/Model/Timer'
 * '<S120>' : 'microrrede_v8/Disjuntor Banco Trifásico/Breaker C/Model'
 * '<S121>' : 'microrrede_v8/Disjuntor Banco Trifásico/Breaker C/Model/Timer'
 * '<S122>' : 'microrrede_v8/Disjuntor Banco Trifásico/Stair Generator/Model'
 * '<S123>' : 'microrrede_v8/Disjuntor CTA 1/Model'
 * '<S124>' : 'microrrede_v8/Disjuntor CTA 1/Model/Timer'
 * '<S125>' : 'microrrede_v8/Disjuntor CTA 2/Model'
 * '<S126>' : 'microrrede_v8/Disjuntor CTA 2/Model/Timer'
 * '<S127>' : 'microrrede_v8/Disjuntor PCC/Breaker A'
 * '<S128>' : 'microrrede_v8/Disjuntor PCC/Breaker B'
 * '<S129>' : 'microrrede_v8/Disjuntor PCC/Breaker C'
 * '<S130>' : 'microrrede_v8/Disjuntor PCC/Stair Generator'
 * '<S131>' : 'microrrede_v8/Disjuntor PCC/Breaker A/Model'
 * '<S132>' : 'microrrede_v8/Disjuntor PCC/Breaker A/Model/Timer'
 * '<S133>' : 'microrrede_v8/Disjuntor PCC/Breaker B/Model'
 * '<S134>' : 'microrrede_v8/Disjuntor PCC/Breaker B/Model/Timer'
 * '<S135>' : 'microrrede_v8/Disjuntor PCC/Breaker C/Model'
 * '<S136>' : 'microrrede_v8/Disjuntor PCC/Breaker C/Model/Timer'
 * '<S137>' : 'microrrede_v8/Disjuntor PCC/Stair Generator/Model'
 * '<S138>' : 'microrrede_v8/Disjuntor de neutro/Model'
 * '<S139>' : 'microrrede_v8/Disjuntor de neutro/Model/Timer'
 * '<S140>' : 'microrrede_v8/Disjuntor+1/Model'
 * '<S141>' : 'microrrede_v8/Disjuntor+1/Model/Measurement list'
 * '<S142>' : 'microrrede_v8/Disjuntor+2/Model'
 * '<S143>' : 'microrrede_v8/Disjuntor+2/Model/Measurement list'
 * '<S144>' : 'microrrede_v8/Disjuntor+3/Model'
 * '<S145>' : 'microrrede_v8/Disjuntor+3/Model/Measurement list'
 * '<S146>' : 'microrrede_v8/Disjuntor-1/Model'
 * '<S147>' : 'microrrede_v8/Disjuntor-1/Model/Measurement list'
 * '<S148>' : 'microrrede_v8/Disjuntor-2/Model'
 * '<S149>' : 'microrrede_v8/Disjuntor-2/Model/Measurement list'
 * '<S150>' : 'microrrede_v8/Disjuntor-3/Model'
 * '<S151>' : 'microrrede_v8/Disjuntor-3/Model/Measurement list'
 * '<S152>' : 'microrrede_v8/ENEL/Model'
 * '<S153>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  '
 * '<S154>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  '
 * '<S155>' : 'microrrede_v8/Inversor Fronius/Conversor boost1'
 * '<S156>' : 'microrrede_v8/Inversor Fronius/Current Measurement2'
 * '<S157>' : 'microrrede_v8/Inversor Fronius/Ponte inversora '
 * '<S158>' : 'microrrede_v8/Inversor Fronius/Voltage Measurement1'
 * '<S159>' : 'microrrede_v8/Inversor Fronius/Voltage Measurement3'
 * '<S160>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /MATLAB Function'
 * '<S161>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller'
 * '<S162>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PWM Generator (DC-DC)'
 * '<S163>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller/Anti-windup'
 * '<S164>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller/D Gain'
 * '<S165>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller/Filter'
 * '<S166>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller/Filter ICs'
 * '<S167>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller/I Gain'
 * '<S168>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller/Ideal P Gain'
 * '<S169>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller/Ideal P Gain Fdbk'
 * '<S170>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller/Integrator'
 * '<S171>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller/Integrator ICs'
 * '<S172>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller/N Copy'
 * '<S173>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller/N Gain'
 * '<S174>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller/P Copy'
 * '<S175>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller/Parallel P Gain'
 * '<S176>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller/Reset Signal'
 * '<S177>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller/Saturation'
 * '<S178>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller/Saturation Fdbk'
 * '<S179>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller/Sum'
 * '<S180>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller/Sum Fdbk'
 * '<S181>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller/Tracking Mode'
 * '<S182>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller/Tracking Mode Sum'
 * '<S183>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller/Tsamp - Integral'
 * '<S184>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller/Tsamp - Ngain'
 * '<S185>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller/postSat Signal'
 * '<S186>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller/preSat Signal'
 * '<S187>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller/Anti-windup/Passthrough'
 * '<S188>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller/D Gain/Disabled'
 * '<S189>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller/Filter/Disabled'
 * '<S190>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller/Filter ICs/Disabled'
 * '<S191>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller/I Gain/Internal Parameters'
 * '<S192>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller/Ideal P Gain/Passthrough'
 * '<S193>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S194>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller/Integrator/Discrete'
 * '<S195>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller/Integrator ICs/Internal IC'
 * '<S196>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller/N Copy/Disabled wSignal Specification'
 * '<S197>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller/N Gain/Disabled'
 * '<S198>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller/P Copy/Disabled'
 * '<S199>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller/Parallel P Gain/Internal Parameters'
 * '<S200>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller/Reset Signal/Disabled'
 * '<S201>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller/Saturation/Passthrough'
 * '<S202>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller/Saturation Fdbk/Disabled'
 * '<S203>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller/Sum/Sum_PI'
 * '<S204>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller/Sum Fdbk/Disabled'
 * '<S205>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller/Tracking Mode/Disabled'
 * '<S206>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller/Tracking Mode Sum/Passthrough'
 * '<S207>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S208>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller/Tsamp - Ngain/Passthrough'
 * '<S209>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller/postSat Signal/Forward_Path'
 * '<S210>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PID Controller/preSat Signal/Forward_Path'
 * '<S211>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PWM Generator (DC-DC)/Compare To Zero'
 * '<S212>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PWM Generator (DC-DC)/Sawtooth Generator'
 * '<S213>' : 'microrrede_v8/Inversor Fronius/Controle Boost com MPPT  /PWM Generator (DC-DC)/Sawtooth Generator/Model'
 * '<S214>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /PWM Generator (2-Level)'
 * '<S215>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem'
 * '<S216>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /PWM Generator (2-Level)/Cr_MinMax'
 * '<S217>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /PWM Generator (2-Level)/Modulator type'
 * '<S218>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /PWM Generator (2-Level)/Reference signal'
 * '<S219>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /PWM Generator (2-Level)/Sampling'
 * '<S220>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /PWM Generator (2-Level)/Modulator type/Full Bridge Unipolar'
 * '<S221>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /PWM Generator (2-Level)/Reference signal/External'
 * '<S222>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /PWM Generator (2-Level)/Sampling/Unsync Natural'
 * '<S223>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /PWM Generator (2-Level)/Sampling/Unsync Natural/Unsync_NaturalSampling'
 * '<S224>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /PWM Generator (2-Level)/Sampling/Unsync Natural/Unsync_NaturalSampling/Triangle Generator'
 * '<S225>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /PWM Generator (2-Level)/Sampling/Unsync Natural/Unsync_NaturalSampling/Triangle Generator/Model'
 * '<S226>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/Fundamental (PLL-Driven)'
 * '<S227>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/Mean'
 * '<S228>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller'
 * '<S229>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PLL'
 * '<S230>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/RelSignal'
 * '<S231>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/Subsystem'
 * '<S232>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente'
 * '<S233>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/Fundamental (PLL-Driven)/Mean (Variable Frequency)1'
 * '<S234>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/Fundamental (PLL-Driven)/Mean (Variable Frequency)2'
 * '<S235>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/Fundamental (PLL-Driven)/Mean (Variable Frequency)1/Model'
 * '<S236>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/Fundamental (PLL-Driven)/Mean (Variable Frequency)1/Model/Correction subsystem'
 * '<S237>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/Fundamental (PLL-Driven)/Mean (Variable Frequency)1/Model/Discrete Variable Time Delay'
 * '<S238>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/Fundamental (PLL-Driven)/Mean (Variable Frequency)2/Model'
 * '<S239>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/Fundamental (PLL-Driven)/Mean (Variable Frequency)2/Model/Correction subsystem'
 * '<S240>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/Fundamental (PLL-Driven)/Mean (Variable Frequency)2/Model/Discrete Variable Time Delay'
 * '<S241>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/Mean/Model'
 * '<S242>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/Mean/Model/Discrete Variable Time Delay'
 * '<S243>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller/Anti-windup'
 * '<S244>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller/D Gain'
 * '<S245>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller/Filter'
 * '<S246>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller/Filter ICs'
 * '<S247>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller/I Gain'
 * '<S248>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller/Ideal P Gain'
 * '<S249>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller/Ideal P Gain Fdbk'
 * '<S250>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller/Integrator'
 * '<S251>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller/Integrator ICs'
 * '<S252>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller/N Copy'
 * '<S253>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller/N Gain'
 * '<S254>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller/P Copy'
 * '<S255>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller/Parallel P Gain'
 * '<S256>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller/Reset Signal'
 * '<S257>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller/Saturation'
 * '<S258>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller/Saturation Fdbk'
 * '<S259>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller/Sum'
 * '<S260>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller/Sum Fdbk'
 * '<S261>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller/Tracking Mode'
 * '<S262>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller/Tracking Mode Sum'
 * '<S263>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller/Tsamp - Integral'
 * '<S264>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller/Tsamp - Ngain'
 * '<S265>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller/postSat Signal'
 * '<S266>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller/preSat Signal'
 * '<S267>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller/Anti-windup/Passthrough'
 * '<S268>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller/D Gain/Disabled'
 * '<S269>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller/Filter/Disabled'
 * '<S270>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller/Filter ICs/Disabled'
 * '<S271>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller/I Gain/Internal Parameters'
 * '<S272>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller/Ideal P Gain/Passthrough'
 * '<S273>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S274>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller/Integrator/Discrete'
 * '<S275>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller/Integrator ICs/Internal IC'
 * '<S276>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S277>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller/N Gain/Disabled'
 * '<S278>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller/P Copy/Disabled'
 * '<S279>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S280>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller/Reset Signal/Disabled'
 * '<S281>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller/Saturation/Enabled'
 * '<S282>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller/Saturation Fdbk/Disabled'
 * '<S283>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller/Sum/Sum_PI'
 * '<S284>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller/Sum Fdbk/Disabled'
 * '<S285>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller/Tracking Mode/Disabled'
 * '<S286>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S287>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S288>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S289>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller/postSat Signal/Forward_Path'
 * '<S290>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PID Controller/preSat Signal/Forward_Path'
 * '<S291>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PLL/Model'
 * '<S292>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PLL/Model/Automatic Gain Control'
 * '<S293>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PLL/Model/Discrete'
 * '<S294>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PLL/Model/Mean (Variable Frequency)'
 * '<S295>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PLL/Model/Second-Order Filter'
 * '<S296>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PLL/Model/Automatic Gain Control/Fundamental (PLL-Driven)'
 * '<S297>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PLL/Model/Automatic Gain Control/Fundamental (PLL-Driven)/Mean (Variable Frequency)1'
 * '<S298>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PLL/Model/Automatic Gain Control/Fundamental (PLL-Driven)/Mean (Variable Frequency)2'
 * '<S299>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PLL/Model/Automatic Gain Control/Fundamental (PLL-Driven)/Mean (Variable Frequency)1/Model'
 * '<S300>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PLL/Model/Automatic Gain Control/Fundamental (PLL-Driven)/Mean (Variable Frequency)1/Model/Correction subsystem'
 * '<S301>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PLL/Model/Automatic Gain Control/Fundamental (PLL-Driven)/Mean (Variable Frequency)1/Model/Discrete Variable Time Delay'
 * '<S302>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PLL/Model/Automatic Gain Control/Fundamental (PLL-Driven)/Mean (Variable Frequency)2/Model'
 * '<S303>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PLL/Model/Automatic Gain Control/Fundamental (PLL-Driven)/Mean (Variable Frequency)2/Model/Correction subsystem'
 * '<S304>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PLL/Model/Automatic Gain Control/Fundamental (PLL-Driven)/Mean (Variable Frequency)2/Model/Discrete Variable Time Delay'
 * '<S305>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PLL/Model/Mean (Variable Frequency)/Model'
 * '<S306>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PLL/Model/Mean (Variable Frequency)/Model/Correction subsystem'
 * '<S307>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PLL/Model/Mean (Variable Frequency)/Model/Discrete Variable Time Delay'
 * '<S308>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PLL/Model/Second-Order Filter/Model'
 * '<S309>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PLL/Model/Second-Order Filter/Model/A*k(k-1)'
 * '<S310>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PLL/Model/Second-Order Filter/Model/B*(u(k)+u(k-1))'
 * '<S311>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/PLL/Model/Second-Order Filter/Model/C*x(k)'
 * '<S312>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/Subsystem/Alpha-Beta-Zero to dq0'
 * '<S313>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/Subsystem/Discrete Variable Time Delay'
 * '<S314>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/Subsystem/Alpha-Beta-Zero to dq0/Compare To Constant'
 * '<S315>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/Subsystem/Alpha-Beta-Zero to dq0/Compare To Constant1'
 * '<S316>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/Subsystem/Alpha-Beta-Zero to dq0/Subsystem - pi//2 delay'
 * '<S317>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/Subsystem/Alpha-Beta-Zero to dq0/Subsystem1'
 * '<S318>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller'
 * '<S319>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller/Anti-windup'
 * '<S320>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller/D Gain'
 * '<S321>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller/Filter'
 * '<S322>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller/Filter ICs'
 * '<S323>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller/I Gain'
 * '<S324>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller/Ideal P Gain'
 * '<S325>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller/Ideal P Gain Fdbk'
 * '<S326>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller/Integrator'
 * '<S327>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller/Integrator ICs'
 * '<S328>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller/N Copy'
 * '<S329>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller/N Gain'
 * '<S330>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller/P Copy'
 * '<S331>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller/Parallel P Gain'
 * '<S332>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller/Reset Signal'
 * '<S333>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller/Saturation'
 * '<S334>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller/Saturation Fdbk'
 * '<S335>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller/Sum'
 * '<S336>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller/Sum Fdbk'
 * '<S337>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller/Tracking Mode'
 * '<S338>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller/Tracking Mode Sum'
 * '<S339>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller/Tsamp - Integral'
 * '<S340>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller/Tsamp - Ngain'
 * '<S341>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller/postSat Signal'
 * '<S342>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller/preSat Signal'
 * '<S343>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller/Anti-windup/Passthrough'
 * '<S344>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller/D Gain/Disabled'
 * '<S345>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller/Filter/Disabled'
 * '<S346>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller/Filter ICs/Disabled'
 * '<S347>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller/I Gain/Internal Parameters'
 * '<S348>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller/Ideal P Gain/Passthrough'
 * '<S349>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S350>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller/Integrator/Discrete'
 * '<S351>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller/Integrator ICs/Internal IC'
 * '<S352>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S353>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller/N Gain/Disabled'
 * '<S354>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller/P Copy/Disabled'
 * '<S355>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S356>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller/Reset Signal/Disabled'
 * '<S357>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller/Saturation/Enabled'
 * '<S358>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller/Saturation Fdbk/Disabled'
 * '<S359>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller/Sum/Sum_PI'
 * '<S360>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller/Sum Fdbk/Disabled'
 * '<S361>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller/Tracking Mode/Disabled'
 * '<S362>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S363>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S364>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S365>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller/postSat Signal/Forward_Path'
 * '<S366>' : 'microrrede_v8/Inversor Fronius/Controle Inversor  /Subsystem/corrente/PID Controller/preSat Signal/Forward_Path'
 * '<S367>' : 'microrrede_v8/Inversor Fronius/Conversor boost1/Diode'
 * '<S368>' : 'microrrede_v8/Inversor Fronius/Conversor boost1/IGBT//Diode'
 * '<S369>' : 'microrrede_v8/Inversor Fronius/Conversor boost1/Diode/Model'
 * '<S370>' : 'microrrede_v8/Inversor Fronius/Conversor boost1/Diode/Model/Measurement list'
 * '<S371>' : 'microrrede_v8/Inversor Fronius/Conversor boost1/IGBT//Diode/Model'
 * '<S372>' : 'microrrede_v8/Inversor Fronius/Conversor boost1/IGBT//Diode/Model/Measurement list'
 * '<S373>' : 'microrrede_v8/Inversor Fronius/Current Measurement2/Model'
 * '<S374>' : 'microrrede_v8/Inversor Fronius/Ponte inversora /Model'
 * '<S375>' : 'microrrede_v8/Inversor Fronius/Ponte inversora /Model/Vf 1'
 * '<S376>' : 'microrrede_v8/Inversor Fronius/Voltage Measurement1/Model'
 * '<S377>' : 'microrrede_v8/Inversor Fronius/Voltage Measurement3/Model'
 * '<S378>' : 'microrrede_v8/Inversor SMA offgrid/Mosfet1'
 * '<S379>' : 'microrrede_v8/Inversor SMA offgrid/Mosfet2'
 * '<S380>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1'
 * '<S381>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2'
 * '<S382>' : 'microrrede_v8/Inversor SMA offgrid/PWM Generator (2-Level)'
 * '<S383>' : 'microrrede_v8/Inversor SMA offgrid/PWM Generator (DC-DC)1'
 * '<S384>' : 'microrrede_v8/Inversor SMA offgrid/Universal Bridge'
 * '<S385>' : 'microrrede_v8/Inversor SMA offgrid/Mosfet1/Diode'
 * '<S386>' : 'microrrede_v8/Inversor SMA offgrid/Mosfet1/Ideal Switch'
 * '<S387>' : 'microrrede_v8/Inversor SMA offgrid/Mosfet1/Measurement list'
 * '<S388>' : 'microrrede_v8/Inversor SMA offgrid/Mosfet1/Diode/Model'
 * '<S389>' : 'microrrede_v8/Inversor SMA offgrid/Mosfet1/Diode/Model/Measurement list'
 * '<S390>' : 'microrrede_v8/Inversor SMA offgrid/Mosfet1/Ideal Switch/Model'
 * '<S391>' : 'microrrede_v8/Inversor SMA offgrid/Mosfet1/Ideal Switch/Model/Measurement list'
 * '<S392>' : 'microrrede_v8/Inversor SMA offgrid/Mosfet2/Diode'
 * '<S393>' : 'microrrede_v8/Inversor SMA offgrid/Mosfet2/Ideal Switch'
 * '<S394>' : 'microrrede_v8/Inversor SMA offgrid/Mosfet2/Measurement list'
 * '<S395>' : 'microrrede_v8/Inversor SMA offgrid/Mosfet2/Diode/Model'
 * '<S396>' : 'microrrede_v8/Inversor SMA offgrid/Mosfet2/Diode/Model/Measurement list'
 * '<S397>' : 'microrrede_v8/Inversor SMA offgrid/Mosfet2/Ideal Switch/Model'
 * '<S398>' : 'microrrede_v8/Inversor SMA offgrid/Mosfet2/Ideal Switch/Model/Measurement list'
 * '<S399>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1/Anti-windup'
 * '<S400>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1/D Gain'
 * '<S401>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1/Filter'
 * '<S402>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1/Filter ICs'
 * '<S403>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1/I Gain'
 * '<S404>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1/Ideal P Gain'
 * '<S405>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1/Ideal P Gain Fdbk'
 * '<S406>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1/Integrator'
 * '<S407>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1/Integrator ICs'
 * '<S408>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1/N Copy'
 * '<S409>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1/N Gain'
 * '<S410>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1/P Copy'
 * '<S411>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1/Parallel P Gain'
 * '<S412>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1/Reset Signal'
 * '<S413>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1/Saturation'
 * '<S414>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1/Saturation Fdbk'
 * '<S415>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1/Sum'
 * '<S416>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1/Sum Fdbk'
 * '<S417>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1/Tracking Mode'
 * '<S418>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1/Tracking Mode Sum'
 * '<S419>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1/Tsamp - Integral'
 * '<S420>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1/Tsamp - Ngain'
 * '<S421>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1/postSat Signal'
 * '<S422>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1/preSat Signal'
 * '<S423>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1/Anti-windup/Passthrough'
 * '<S424>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1/D Gain/Disabled'
 * '<S425>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1/Filter/Disabled'
 * '<S426>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1/Filter ICs/Disabled'
 * '<S427>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1/I Gain/Internal Parameters'
 * '<S428>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1/Ideal P Gain/Passthrough'
 * '<S429>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S430>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1/Integrator/Discrete'
 * '<S431>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1/Integrator ICs/Internal IC'
 * '<S432>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S433>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1/N Gain/Disabled'
 * '<S434>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1/P Copy/Disabled'
 * '<S435>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S436>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1/Reset Signal/Disabled'
 * '<S437>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1/Saturation/Enabled'
 * '<S438>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1/Saturation Fdbk/Disabled'
 * '<S439>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1/Sum/Sum_PI'
 * '<S440>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1/Sum Fdbk/Disabled'
 * '<S441>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1/Tracking Mode/Disabled'
 * '<S442>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S443>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S444>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S445>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1/postSat Signal/Forward_Path'
 * '<S446>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller1/preSat Signal/Forward_Path'
 * '<S447>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2/Anti-windup'
 * '<S448>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2/D Gain'
 * '<S449>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2/Filter'
 * '<S450>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2/Filter ICs'
 * '<S451>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2/I Gain'
 * '<S452>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2/Ideal P Gain'
 * '<S453>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2/Ideal P Gain Fdbk'
 * '<S454>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2/Integrator'
 * '<S455>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2/Integrator ICs'
 * '<S456>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2/N Copy'
 * '<S457>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2/N Gain'
 * '<S458>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2/P Copy'
 * '<S459>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2/Parallel P Gain'
 * '<S460>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2/Reset Signal'
 * '<S461>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2/Saturation'
 * '<S462>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2/Saturation Fdbk'
 * '<S463>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2/Sum'
 * '<S464>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2/Sum Fdbk'
 * '<S465>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2/Tracking Mode'
 * '<S466>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2/Tracking Mode Sum'
 * '<S467>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2/Tsamp - Integral'
 * '<S468>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2/Tsamp - Ngain'
 * '<S469>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2/postSat Signal'
 * '<S470>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2/preSat Signal'
 * '<S471>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2/Anti-windup/Passthrough'
 * '<S472>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2/D Gain/Disabled'
 * '<S473>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2/Filter/Disabled'
 * '<S474>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2/Filter ICs/Disabled'
 * '<S475>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2/I Gain/Internal Parameters'
 * '<S476>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2/Ideal P Gain/Passthrough'
 * '<S477>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S478>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2/Integrator/Discrete'
 * '<S479>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2/Integrator ICs/Internal IC'
 * '<S480>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2/N Copy/Disabled wSignal Specification'
 * '<S481>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2/N Gain/Disabled'
 * '<S482>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2/P Copy/Disabled'
 * '<S483>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2/Parallel P Gain/Internal Parameters'
 * '<S484>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2/Reset Signal/Disabled'
 * '<S485>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2/Saturation/Passthrough'
 * '<S486>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2/Saturation Fdbk/Disabled'
 * '<S487>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2/Sum/Sum_PI'
 * '<S488>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2/Sum Fdbk/Disabled'
 * '<S489>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2/Tracking Mode/Disabled'
 * '<S490>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S491>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2/Tsamp - Integral/TsSignalSpecification'
 * '<S492>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S493>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2/postSat Signal/Forward_Path'
 * '<S494>' : 'microrrede_v8/Inversor SMA offgrid/PID Controller2/preSat Signal/Forward_Path'
 * '<S495>' : 'microrrede_v8/Inversor SMA offgrid/PWM Generator (2-Level)/Cr_MinMax'
 * '<S496>' : 'microrrede_v8/Inversor SMA offgrid/PWM Generator (2-Level)/Modulator type'
 * '<S497>' : 'microrrede_v8/Inversor SMA offgrid/PWM Generator (2-Level)/Reference signal'
 * '<S498>' : 'microrrede_v8/Inversor SMA offgrid/PWM Generator (2-Level)/Sampling'
 * '<S499>' : 'microrrede_v8/Inversor SMA offgrid/PWM Generator (2-Level)/Modulator type/Full Bridge Unipolar'
 * '<S500>' : 'microrrede_v8/Inversor SMA offgrid/PWM Generator (2-Level)/Reference signal/Internal'
 * '<S501>' : 'microrrede_v8/Inversor SMA offgrid/PWM Generator (2-Level)/Sampling/Unsync Natural'
 * '<S502>' : 'microrrede_v8/Inversor SMA offgrid/PWM Generator (2-Level)/Sampling/Unsync Natural/Unsync_NaturalSampling'
 * '<S503>' : 'microrrede_v8/Inversor SMA offgrid/PWM Generator (2-Level)/Sampling/Unsync Natural/Unsync_NaturalSampling/Triangle Generator'
 * '<S504>' : 'microrrede_v8/Inversor SMA offgrid/PWM Generator (2-Level)/Sampling/Unsync Natural/Unsync_NaturalSampling/Triangle Generator/Model'
 * '<S505>' : 'microrrede_v8/Inversor SMA offgrid/PWM Generator (DC-DC)1/Compare To Zero'
 * '<S506>' : 'microrrede_v8/Inversor SMA offgrid/PWM Generator (DC-DC)1/Sawtooth Generator'
 * '<S507>' : 'microrrede_v8/Inversor SMA offgrid/PWM Generator (DC-DC)1/Sawtooth Generator/Model'
 * '<S508>' : 'microrrede_v8/Inversor SMA offgrid/Universal Bridge/Model'
 * '<S509>' : 'microrrede_v8/Inversor SMA offgrid/Universal Bridge/Model/Vf 1'
 * '<S510>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor'
 * '<S511>' : 'microrrede_v8/Inversor SMA ongrid/Current Measurement3'
 * '<S512>' : 'microrrede_v8/Inversor SMA ongrid/Mean1'
 * '<S513>' : 'microrrede_v8/Inversor SMA ongrid/Ponte inversora  '
 * '<S514>' : 'microrrede_v8/Inversor SMA ongrid/Voltage Measurement4'
 * '<S515>' : 'microrrede_v8/Inversor SMA ongrid/Voltage Measurement5'
 * '<S516>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/PWM Generator (2-Level)'
 * '<S517>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem'
 * '<S518>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/PWM Generator (2-Level)/Cr_MinMax'
 * '<S519>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/PWM Generator (2-Level)/Modulator type'
 * '<S520>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/PWM Generator (2-Level)/Reference signal'
 * '<S521>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/PWM Generator (2-Level)/Sampling'
 * '<S522>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/PWM Generator (2-Level)/Modulator type/Full Bridge Unipolar'
 * '<S523>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/PWM Generator (2-Level)/Reference signal/External'
 * '<S524>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/PWM Generator (2-Level)/Sampling/Unsync Natural'
 * '<S525>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/PWM Generator (2-Level)/Sampling/Unsync Natural/Unsync_NaturalSampling'
 * '<S526>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/PWM Generator (2-Level)/Sampling/Unsync Natural/Unsync_NaturalSampling/Triangle Generator'
 * '<S527>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/PWM Generator (2-Level)/Sampling/Unsync Natural/Unsync_NaturalSampling/Triangle Generator/Model'
 * '<S528>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/Fundamental (PLL-Driven)'
 * '<S529>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/Mean'
 * '<S530>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller'
 * '<S531>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PLL'
 * '<S532>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/RelSignal'
 * '<S533>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/Subsystem'
 * '<S534>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente'
 * '<S535>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/Fundamental (PLL-Driven)/Mean (Variable Frequency)1'
 * '<S536>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/Fundamental (PLL-Driven)/Mean (Variable Frequency)2'
 * '<S537>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/Fundamental (PLL-Driven)/Mean (Variable Frequency)1/Model'
 * '<S538>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/Fundamental (PLL-Driven)/Mean (Variable Frequency)1/Model/Correction subsystem'
 * '<S539>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/Fundamental (PLL-Driven)/Mean (Variable Frequency)1/Model/Discrete Variable Time Delay'
 * '<S540>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/Fundamental (PLL-Driven)/Mean (Variable Frequency)2/Model'
 * '<S541>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/Fundamental (PLL-Driven)/Mean (Variable Frequency)2/Model/Correction subsystem'
 * '<S542>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/Fundamental (PLL-Driven)/Mean (Variable Frequency)2/Model/Discrete Variable Time Delay'
 * '<S543>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/Mean/Model'
 * '<S544>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/Mean/Model/Discrete Variable Time Delay'
 * '<S545>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller/Anti-windup'
 * '<S546>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller/D Gain'
 * '<S547>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller/Filter'
 * '<S548>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller/Filter ICs'
 * '<S549>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller/I Gain'
 * '<S550>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller/Ideal P Gain'
 * '<S551>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller/Ideal P Gain Fdbk'
 * '<S552>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller/Integrator'
 * '<S553>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller/Integrator ICs'
 * '<S554>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller/N Copy'
 * '<S555>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller/N Gain'
 * '<S556>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller/P Copy'
 * '<S557>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller/Parallel P Gain'
 * '<S558>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller/Reset Signal'
 * '<S559>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller/Saturation'
 * '<S560>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller/Saturation Fdbk'
 * '<S561>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller/Sum'
 * '<S562>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller/Sum Fdbk'
 * '<S563>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller/Tracking Mode'
 * '<S564>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller/Tracking Mode Sum'
 * '<S565>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller/Tsamp - Integral'
 * '<S566>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller/Tsamp - Ngain'
 * '<S567>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller/postSat Signal'
 * '<S568>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller/preSat Signal'
 * '<S569>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller/Anti-windup/Passthrough'
 * '<S570>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller/D Gain/Disabled'
 * '<S571>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller/Filter/Disabled'
 * '<S572>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller/Filter ICs/Disabled'
 * '<S573>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller/I Gain/Internal Parameters'
 * '<S574>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller/Ideal P Gain/Passthrough'
 * '<S575>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S576>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller/Integrator/Discrete'
 * '<S577>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller/Integrator ICs/Internal IC'
 * '<S578>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S579>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller/N Gain/Disabled'
 * '<S580>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller/P Copy/Disabled'
 * '<S581>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S582>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller/Reset Signal/Disabled'
 * '<S583>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller/Saturation/Enabled'
 * '<S584>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller/Saturation Fdbk/Disabled'
 * '<S585>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller/Sum/Sum_PI'
 * '<S586>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller/Sum Fdbk/Disabled'
 * '<S587>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller/Tracking Mode/Disabled'
 * '<S588>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S589>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S590>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S591>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller/postSat Signal/Forward_Path'
 * '<S592>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PID Controller/preSat Signal/Forward_Path'
 * '<S593>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PLL/Model'
 * '<S594>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PLL/Model/Automatic Gain Control'
 * '<S595>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PLL/Model/Discrete'
 * '<S596>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PLL/Model/Mean (Variable Frequency)'
 * '<S597>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PLL/Model/Second-Order Filter'
 * '<S598>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PLL/Model/Automatic Gain Control/Fundamental (PLL-Driven)'
 * '<S599>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PLL/Model/Automatic Gain Control/Fundamental (PLL-Driven)/Mean (Variable Frequency)1'
 * '<S600>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PLL/Model/Automatic Gain Control/Fundamental (PLL-Driven)/Mean (Variable Frequency)2'
 * '<S601>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PLL/Model/Automatic Gain Control/Fundamental (PLL-Driven)/Mean (Variable Frequency)1/Model'
 * '<S602>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PLL/Model/Automatic Gain Control/Fundamental (PLL-Driven)/Mean (Variable Frequency)1/Model/Correction subsystem'
 * '<S603>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PLL/Model/Automatic Gain Control/Fundamental (PLL-Driven)/Mean (Variable Frequency)1/Model/Discrete Variable Time Delay'
 * '<S604>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PLL/Model/Automatic Gain Control/Fundamental (PLL-Driven)/Mean (Variable Frequency)2/Model'
 * '<S605>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PLL/Model/Automatic Gain Control/Fundamental (PLL-Driven)/Mean (Variable Frequency)2/Model/Correction subsystem'
 * '<S606>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PLL/Model/Automatic Gain Control/Fundamental (PLL-Driven)/Mean (Variable Frequency)2/Model/Discrete Variable Time Delay'
 * '<S607>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PLL/Model/Mean (Variable Frequency)/Model'
 * '<S608>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PLL/Model/Mean (Variable Frequency)/Model/Correction subsystem'
 * '<S609>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PLL/Model/Mean (Variable Frequency)/Model/Discrete Variable Time Delay'
 * '<S610>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PLL/Model/Second-Order Filter/Model'
 * '<S611>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PLL/Model/Second-Order Filter/Model/A*k(k-1)'
 * '<S612>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PLL/Model/Second-Order Filter/Model/B*(u(k)+u(k-1))'
 * '<S613>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/PLL/Model/Second-Order Filter/Model/C*x(k)'
 * '<S614>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/Subsystem/Alpha-Beta-Zero to dq0'
 * '<S615>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/Subsystem/Discrete Variable Time Delay'
 * '<S616>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/Subsystem/Alpha-Beta-Zero to dq0/Compare To Constant'
 * '<S617>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/Subsystem/Alpha-Beta-Zero to dq0/Compare To Constant1'
 * '<S618>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/Subsystem/Alpha-Beta-Zero to dq0/Subsystem - pi//2 delay'
 * '<S619>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/Subsystem/Alpha-Beta-Zero to dq0/Subsystem1'
 * '<S620>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller'
 * '<S621>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller/Anti-windup'
 * '<S622>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller/D Gain'
 * '<S623>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller/Filter'
 * '<S624>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller/Filter ICs'
 * '<S625>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller/I Gain'
 * '<S626>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller/Ideal P Gain'
 * '<S627>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller/Ideal P Gain Fdbk'
 * '<S628>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller/Integrator'
 * '<S629>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller/Integrator ICs'
 * '<S630>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller/N Copy'
 * '<S631>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller/N Gain'
 * '<S632>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller/P Copy'
 * '<S633>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller/Parallel P Gain'
 * '<S634>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller/Reset Signal'
 * '<S635>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller/Saturation'
 * '<S636>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller/Saturation Fdbk'
 * '<S637>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller/Sum'
 * '<S638>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller/Sum Fdbk'
 * '<S639>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller/Tracking Mode'
 * '<S640>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller/Tracking Mode Sum'
 * '<S641>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller/Tsamp - Integral'
 * '<S642>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller/Tsamp - Ngain'
 * '<S643>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller/postSat Signal'
 * '<S644>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller/preSat Signal'
 * '<S645>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller/Anti-windup/Passthrough'
 * '<S646>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller/D Gain/Disabled'
 * '<S647>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller/Filter/Disabled'
 * '<S648>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller/Filter ICs/Disabled'
 * '<S649>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller/I Gain/Internal Parameters'
 * '<S650>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller/Ideal P Gain/Passthrough'
 * '<S651>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S652>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller/Integrator/Discrete'
 * '<S653>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller/Integrator ICs/Internal IC'
 * '<S654>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S655>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller/N Gain/Disabled'
 * '<S656>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller/P Copy/Disabled'
 * '<S657>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S658>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller/Reset Signal/Disabled'
 * '<S659>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller/Saturation/Enabled'
 * '<S660>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller/Saturation Fdbk/Disabled'
 * '<S661>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller/Sum/Sum_PI'
 * '<S662>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller/Sum Fdbk/Disabled'
 * '<S663>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller/Tracking Mode/Disabled'
 * '<S664>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S665>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S666>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S667>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller/postSat Signal/Forward_Path'
 * '<S668>' : 'microrrede_v8/Inversor SMA ongrid/Controle Inversor/Subsystem/corrente/PID Controller/preSat Signal/Forward_Path'
 * '<S669>' : 'microrrede_v8/Inversor SMA ongrid/Current Measurement3/Model'
 * '<S670>' : 'microrrede_v8/Inversor SMA ongrid/Mean1/Model'
 * '<S671>' : 'microrrede_v8/Inversor SMA ongrid/Mean1/Model/Discrete Variable Time Delay'
 * '<S672>' : 'microrrede_v8/Inversor SMA ongrid/Ponte inversora  /Model'
 * '<S673>' : 'microrrede_v8/Inversor SMA ongrid/Ponte inversora  /Model/Vf 1'
 * '<S674>' : 'microrrede_v8/Inversor SMA ongrid/Voltage Measurement4/Model'
 * '<S675>' : 'microrrede_v8/Inversor SMA ongrid/Voltage Measurement5/Model'
 * '<S676>' : 'microrrede_v8/SFV1/Diode Rsh'
 * '<S677>' : 'microrrede_v8/SFV1/I Filter'
 * '<S678>' : 'microrrede_v8/SFV1/IL'
 * '<S679>' : 'microrrede_v8/SFV1/IL ctrl'
 * '<S680>' : 'microrrede_v8/SFV1/I_PV'
 * '<S681>' : 'microrrede_v8/SFV1/V Filter'
 * '<S682>' : 'microrrede_v8/SFV1/V_PV'
 * '<S683>' : 'microrrede_v8/SFV1/Vdiode'
 * '<S684>' : 'microrrede_v8/SFV1/Diode Rsh/Id+IRsh'
 * '<S685>' : 'microrrede_v8/SFV1/Diode Rsh/Subsystem'
 * '<S686>' : 'microrrede_v8/SFV1/I_PV/Model'
 * '<S687>' : 'microrrede_v8/SFV1/V_PV/Model'
 * '<S688>' : 'microrrede_v8/SFV2/Diode Rsh'
 * '<S689>' : 'microrrede_v8/SFV2/I Filter'
 * '<S690>' : 'microrrede_v8/SFV2/IL'
 * '<S691>' : 'microrrede_v8/SFV2/IL ctrl'
 * '<S692>' : 'microrrede_v8/SFV2/I_PV'
 * '<S693>' : 'microrrede_v8/SFV2/V Filter'
 * '<S694>' : 'microrrede_v8/SFV2/V_PV'
 * '<S695>' : 'microrrede_v8/SFV2/Vdiode'
 * '<S696>' : 'microrrede_v8/SFV2/Diode Rsh/Id+IRsh'
 * '<S697>' : 'microrrede_v8/SFV2/Diode Rsh/Subsystem'
 * '<S698>' : 'microrrede_v8/SFV2/I_PV/Model'
 * '<S699>' : 'microrrede_v8/SFV2/V_PV/Model'
 * '<S700>' : 'microrrede_v8/SFV3/Diode Rsh'
 * '<S701>' : 'microrrede_v8/SFV3/I Filter'
 * '<S702>' : 'microrrede_v8/SFV3/IL'
 * '<S703>' : 'microrrede_v8/SFV3/IL ctrl'
 * '<S704>' : 'microrrede_v8/SFV3/I_PV'
 * '<S705>' : 'microrrede_v8/SFV3/V Filter'
 * '<S706>' : 'microrrede_v8/SFV3/V_PV'
 * '<S707>' : 'microrrede_v8/SFV3/Vdiode'
 * '<S708>' : 'microrrede_v8/SFV3/Diode Rsh/Id+IRsh'
 * '<S709>' : 'microrrede_v8/SFV3/Diode Rsh/Subsystem'
 * '<S710>' : 'microrrede_v8/SFV3/I_PV/Model'
 * '<S711>' : 'microrrede_v8/SFV3/V_PV/Model'
 * '<S712>' : 'microrrede_v8/VI PCC 1/Mode I'
 * '<S713>' : 'microrrede_v8/VI PCC 1/Mode V'
 * '<S714>' : 'microrrede_v8/VI PCC 1/Model'
 * '<S715>' : 'microrrede_v8/VI PCC 1/Model/I A:'
 * '<S716>' : 'microrrede_v8/VI PCC 1/Model/I B:'
 * '<S717>' : 'microrrede_v8/VI PCC 1/Model/I C:'
 * '<S718>' : 'microrrede_v8/VI PCC 1/Model/U A:'
 * '<S719>' : 'microrrede_v8/VI PCC 1/Model/U B:'
 * '<S720>' : 'microrrede_v8/VI PCC 1/Model/U C:'
 * '<S721>' : 'microrrede_v8/VI PCC 1/Model/I A:/Model'
 * '<S722>' : 'microrrede_v8/VI PCC 1/Model/I B:/Model'
 * '<S723>' : 'microrrede_v8/VI PCC 1/Model/I C:/Model'
 * '<S724>' : 'microrrede_v8/VI PCC 1/Model/U A:/Model'
 * '<S725>' : 'microrrede_v8/VI PCC 1/Model/U B:/Model'
 * '<S726>' : 'microrrede_v8/VI PCC 1/Model/U C:/Model'
 * '<S727>' : 'microrrede_v8/VI PCC 2/Mode I'
 * '<S728>' : 'microrrede_v8/VI PCC 2/Mode V'
 * '<S729>' : 'microrrede_v8/VI PCC 2/Model'
 * '<S730>' : 'microrrede_v8/VI PCC 2/Model/I A:'
 * '<S731>' : 'microrrede_v8/VI PCC 2/Model/I B:'
 * '<S732>' : 'microrrede_v8/VI PCC 2/Model/I C:'
 * '<S733>' : 'microrrede_v8/VI PCC 2/Model/U A:'
 * '<S734>' : 'microrrede_v8/VI PCC 2/Model/U B:'
 * '<S735>' : 'microrrede_v8/VI PCC 2/Model/U C:'
 * '<S736>' : 'microrrede_v8/VI PCC 2/Model/I A:/Model'
 * '<S737>' : 'microrrede_v8/VI PCC 2/Model/I B:/Model'
 * '<S738>' : 'microrrede_v8/VI PCC 2/Model/I C:/Model'
 * '<S739>' : 'microrrede_v8/VI PCC 2/Model/U A:/Model'
 * '<S740>' : 'microrrede_v8/VI PCC 2/Model/U B:/Model'
 * '<S741>' : 'microrrede_v8/VI PCC 2/Model/U C:/Model'
 * '<S742>' : 'microrrede_v8/VI banco de cargas trifásico/Mode I'
 * '<S743>' : 'microrrede_v8/VI banco de cargas trifásico/Mode V'
 * '<S744>' : 'microrrede_v8/VI banco de cargas trifásico/Model'
 * '<S745>' : 'microrrede_v8/VI banco de cargas trifásico/Model/I A:'
 * '<S746>' : 'microrrede_v8/VI banco de cargas trifásico/Model/I B:'
 * '<S747>' : 'microrrede_v8/VI banco de cargas trifásico/Model/I C:'
 * '<S748>' : 'microrrede_v8/VI banco de cargas trifásico/Model/U AB:'
 * '<S749>' : 'microrrede_v8/VI banco de cargas trifásico/Model/U BC:'
 * '<S750>' : 'microrrede_v8/VI banco de cargas trifásico/Model/U CA:'
 * '<S751>' : 'microrrede_v8/VI banco de cargas trifásico/Model/I A:/Model'
 * '<S752>' : 'microrrede_v8/VI banco de cargas trifásico/Model/I B:/Model'
 * '<S753>' : 'microrrede_v8/VI banco de cargas trifásico/Model/I C:/Model'
 * '<S754>' : 'microrrede_v8/VI banco de cargas trifásico/Model/U AB:/Model'
 * '<S755>' : 'microrrede_v8/VI banco de cargas trifásico/Model/U BC:/Model'
 * '<S756>' : 'microrrede_v8/VI banco de cargas trifásico/Model/U CA:/Model'
 * '<S757>' : 'microrrede_v8/Variable Resistor/Dmatrix'
 * '<S758>' : 'microrrede_v8/Variable Resistor/Nearzero resistance'
 * '<S759>' : 'microrrede_v8/Variable Resistor/SrcI'
 * '<S760>' : 'microrrede_v8/Variable Resistor/Vmeas'
 * '<S761>' : 'microrrede_v8/Variable Resistor1/Dmatrix'
 * '<S762>' : 'microrrede_v8/Variable Resistor1/Nearzero resistance'
 * '<S763>' : 'microrrede_v8/Variable Resistor1/SrcI'
 * '<S764>' : 'microrrede_v8/Variable Resistor1/Vmeas'
 * '<S765>' : 'microrrede_v8/Variable Resistor2/Dmatrix'
 * '<S766>' : 'microrrede_v8/Variable Resistor2/Nearzero resistance'
 * '<S767>' : 'microrrede_v8/Variable Resistor2/SrcI'
 * '<S768>' : 'microrrede_v8/Variable Resistor2/Vmeas'
 * '<S769>' : 'microrrede_v8/Voltage Measurement V1/Model'
 * '<S770>' : 'microrrede_v8/Voltage Measurement V2/Model'
 * '<S771>' : 'microrrede_v8/Voltage Measurement V3/Model'
 * '<S772>' : 'microrrede_v8/Voltage Measurement Voffgrid/Model'
 * '<S773>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT '
 * '<S774>' : 'microrrede_v8/inversor Replus/Controle Inversor '
 * '<S775>' : 'microrrede_v8/inversor Replus/Conversor boost SFV3'
 * '<S776>' : 'microrrede_v8/inversor Replus/Current Measurement1'
 * '<S777>' : 'microrrede_v8/inversor Replus/Ponte inversora SFV3'
 * '<S778>' : 'microrrede_v8/inversor Replus/Voltage Measurement Vdc'
 * '<S779>' : 'microrrede_v8/inversor Replus/Voltage Measurement2'
 * '<S780>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /MATLAB Function'
 * '<S781>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller'
 * '<S782>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PWM Generator (DC-DC)'
 * '<S783>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller/Anti-windup'
 * '<S784>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller/D Gain'
 * '<S785>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller/Filter'
 * '<S786>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller/Filter ICs'
 * '<S787>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller/I Gain'
 * '<S788>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller/Ideal P Gain'
 * '<S789>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller/Ideal P Gain Fdbk'
 * '<S790>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller/Integrator'
 * '<S791>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller/Integrator ICs'
 * '<S792>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller/N Copy'
 * '<S793>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller/N Gain'
 * '<S794>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller/P Copy'
 * '<S795>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller/Parallel P Gain'
 * '<S796>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller/Reset Signal'
 * '<S797>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller/Saturation'
 * '<S798>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller/Saturation Fdbk'
 * '<S799>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller/Sum'
 * '<S800>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller/Sum Fdbk'
 * '<S801>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller/Tracking Mode'
 * '<S802>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller/Tracking Mode Sum'
 * '<S803>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller/Tsamp - Integral'
 * '<S804>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller/Tsamp - Ngain'
 * '<S805>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller/postSat Signal'
 * '<S806>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller/preSat Signal'
 * '<S807>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller/Anti-windup/Passthrough'
 * '<S808>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller/D Gain/Disabled'
 * '<S809>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller/Filter/Disabled'
 * '<S810>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller/Filter ICs/Disabled'
 * '<S811>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller/I Gain/Internal Parameters'
 * '<S812>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller/Ideal P Gain/Passthrough'
 * '<S813>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S814>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller/Integrator/Discrete'
 * '<S815>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller/Integrator ICs/Internal IC'
 * '<S816>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller/N Copy/Disabled wSignal Specification'
 * '<S817>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller/N Gain/Disabled'
 * '<S818>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller/P Copy/Disabled'
 * '<S819>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller/Parallel P Gain/Internal Parameters'
 * '<S820>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller/Reset Signal/Disabled'
 * '<S821>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller/Saturation/Passthrough'
 * '<S822>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller/Saturation Fdbk/Disabled'
 * '<S823>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller/Sum/Sum_PI'
 * '<S824>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller/Sum Fdbk/Disabled'
 * '<S825>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller/Tracking Mode/Disabled'
 * '<S826>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller/Tracking Mode Sum/Passthrough'
 * '<S827>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S828>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller/Tsamp - Ngain/Passthrough'
 * '<S829>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller/postSat Signal/Forward_Path'
 * '<S830>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PID Controller/preSat Signal/Forward_Path'
 * '<S831>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PWM Generator (DC-DC)/Compare To Zero'
 * '<S832>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PWM Generator (DC-DC)/Sawtooth Generator'
 * '<S833>' : 'microrrede_v8/inversor Replus/Controle Boost com MPPT /PWM Generator (DC-DC)/Sawtooth Generator/Model'
 * '<S834>' : 'microrrede_v8/inversor Replus/Controle Inversor /PWM Generator (2-Level)'
 * '<S835>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem'
 * '<S836>' : 'microrrede_v8/inversor Replus/Controle Inversor /PWM Generator (2-Level)/Cr_MinMax'
 * '<S837>' : 'microrrede_v8/inversor Replus/Controle Inversor /PWM Generator (2-Level)/Modulator type'
 * '<S838>' : 'microrrede_v8/inversor Replus/Controle Inversor /PWM Generator (2-Level)/Reference signal'
 * '<S839>' : 'microrrede_v8/inversor Replus/Controle Inversor /PWM Generator (2-Level)/Sampling'
 * '<S840>' : 'microrrede_v8/inversor Replus/Controle Inversor /PWM Generator (2-Level)/Modulator type/Full Bridge Unipolar'
 * '<S841>' : 'microrrede_v8/inversor Replus/Controle Inversor /PWM Generator (2-Level)/Reference signal/External'
 * '<S842>' : 'microrrede_v8/inversor Replus/Controle Inversor /PWM Generator (2-Level)/Sampling/Unsync Natural'
 * '<S843>' : 'microrrede_v8/inversor Replus/Controle Inversor /PWM Generator (2-Level)/Sampling/Unsync Natural/Unsync_NaturalSampling'
 * '<S844>' : 'microrrede_v8/inversor Replus/Controle Inversor /PWM Generator (2-Level)/Sampling/Unsync Natural/Unsync_NaturalSampling/Triangle Generator'
 * '<S845>' : 'microrrede_v8/inversor Replus/Controle Inversor /PWM Generator (2-Level)/Sampling/Unsync Natural/Unsync_NaturalSampling/Triangle Generator/Model'
 * '<S846>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/Fundamental (PLL-Driven)'
 * '<S847>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/Mean'
 * '<S848>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller'
 * '<S849>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PLL'
 * '<S850>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/RelSignal'
 * '<S851>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/Subsystem'
 * '<S852>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente'
 * '<S853>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/Fundamental (PLL-Driven)/Mean (Variable Frequency)1'
 * '<S854>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/Fundamental (PLL-Driven)/Mean (Variable Frequency)2'
 * '<S855>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/Fundamental (PLL-Driven)/Mean (Variable Frequency)1/Model'
 * '<S856>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/Fundamental (PLL-Driven)/Mean (Variable Frequency)1/Model/Correction subsystem'
 * '<S857>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/Fundamental (PLL-Driven)/Mean (Variable Frequency)1/Model/Discrete Variable Time Delay'
 * '<S858>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/Fundamental (PLL-Driven)/Mean (Variable Frequency)2/Model'
 * '<S859>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/Fundamental (PLL-Driven)/Mean (Variable Frequency)2/Model/Correction subsystem'
 * '<S860>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/Fundamental (PLL-Driven)/Mean (Variable Frequency)2/Model/Discrete Variable Time Delay'
 * '<S861>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/Mean/Model'
 * '<S862>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/Mean/Model/Discrete Variable Time Delay'
 * '<S863>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller/Anti-windup'
 * '<S864>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller/D Gain'
 * '<S865>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller/Filter'
 * '<S866>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller/Filter ICs'
 * '<S867>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller/I Gain'
 * '<S868>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller/Ideal P Gain'
 * '<S869>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller/Ideal P Gain Fdbk'
 * '<S870>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller/Integrator'
 * '<S871>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller/Integrator ICs'
 * '<S872>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller/N Copy'
 * '<S873>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller/N Gain'
 * '<S874>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller/P Copy'
 * '<S875>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller/Parallel P Gain'
 * '<S876>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller/Reset Signal'
 * '<S877>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller/Saturation'
 * '<S878>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller/Saturation Fdbk'
 * '<S879>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller/Sum'
 * '<S880>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller/Sum Fdbk'
 * '<S881>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller/Tracking Mode'
 * '<S882>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller/Tracking Mode Sum'
 * '<S883>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller/Tsamp - Integral'
 * '<S884>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller/Tsamp - Ngain'
 * '<S885>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller/postSat Signal'
 * '<S886>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller/preSat Signal'
 * '<S887>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller/Anti-windup/Passthrough'
 * '<S888>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller/D Gain/Disabled'
 * '<S889>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller/Filter/Disabled'
 * '<S890>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller/Filter ICs/Disabled'
 * '<S891>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller/I Gain/Internal Parameters'
 * '<S892>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller/Ideal P Gain/Passthrough'
 * '<S893>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S894>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller/Integrator/Discrete'
 * '<S895>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller/Integrator ICs/Internal IC'
 * '<S896>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S897>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller/N Gain/Disabled'
 * '<S898>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller/P Copy/Disabled'
 * '<S899>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S900>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller/Reset Signal/Disabled'
 * '<S901>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller/Saturation/Enabled'
 * '<S902>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller/Saturation Fdbk/Disabled'
 * '<S903>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller/Sum/Sum_PI'
 * '<S904>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller/Sum Fdbk/Disabled'
 * '<S905>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller/Tracking Mode/Disabled'
 * '<S906>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S907>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S908>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S909>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller/postSat Signal/Forward_Path'
 * '<S910>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PID Controller/preSat Signal/Forward_Path'
 * '<S911>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PLL/Model'
 * '<S912>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PLL/Model/Automatic Gain Control'
 * '<S913>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PLL/Model/Discrete'
 * '<S914>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PLL/Model/Mean (Variable Frequency)'
 * '<S915>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PLL/Model/Second-Order Filter'
 * '<S916>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PLL/Model/Automatic Gain Control/Fundamental (PLL-Driven)'
 * '<S917>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PLL/Model/Automatic Gain Control/Fundamental (PLL-Driven)/Mean (Variable Frequency)1'
 * '<S918>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PLL/Model/Automatic Gain Control/Fundamental (PLL-Driven)/Mean (Variable Frequency)2'
 * '<S919>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PLL/Model/Automatic Gain Control/Fundamental (PLL-Driven)/Mean (Variable Frequency)1/Model'
 * '<S920>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PLL/Model/Automatic Gain Control/Fundamental (PLL-Driven)/Mean (Variable Frequency)1/Model/Correction subsystem'
 * '<S921>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PLL/Model/Automatic Gain Control/Fundamental (PLL-Driven)/Mean (Variable Frequency)1/Model/Discrete Variable Time Delay'
 * '<S922>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PLL/Model/Automatic Gain Control/Fundamental (PLL-Driven)/Mean (Variable Frequency)2/Model'
 * '<S923>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PLL/Model/Automatic Gain Control/Fundamental (PLL-Driven)/Mean (Variable Frequency)2/Model/Correction subsystem'
 * '<S924>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PLL/Model/Automatic Gain Control/Fundamental (PLL-Driven)/Mean (Variable Frequency)2/Model/Discrete Variable Time Delay'
 * '<S925>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PLL/Model/Mean (Variable Frequency)/Model'
 * '<S926>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PLL/Model/Mean (Variable Frequency)/Model/Correction subsystem'
 * '<S927>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PLL/Model/Mean (Variable Frequency)/Model/Discrete Variable Time Delay'
 * '<S928>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PLL/Model/Second-Order Filter/Model'
 * '<S929>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PLL/Model/Second-Order Filter/Model/A*k(k-1)'
 * '<S930>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PLL/Model/Second-Order Filter/Model/B*(u(k)+u(k-1))'
 * '<S931>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/PLL/Model/Second-Order Filter/Model/C*x(k)'
 * '<S932>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/Subsystem/Alpha-Beta-Zero to dq0'
 * '<S933>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/Subsystem/Discrete Variable Time Delay'
 * '<S934>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/Subsystem/Alpha-Beta-Zero to dq0/Compare To Constant'
 * '<S935>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/Subsystem/Alpha-Beta-Zero to dq0/Compare To Constant1'
 * '<S936>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/Subsystem/Alpha-Beta-Zero to dq0/Subsystem - pi//2 delay'
 * '<S937>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/Subsystem/Alpha-Beta-Zero to dq0/Subsystem1'
 * '<S938>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller'
 * '<S939>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller/Anti-windup'
 * '<S940>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller/D Gain'
 * '<S941>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller/Filter'
 * '<S942>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller/Filter ICs'
 * '<S943>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller/I Gain'
 * '<S944>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller/Ideal P Gain'
 * '<S945>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller/Ideal P Gain Fdbk'
 * '<S946>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller/Integrator'
 * '<S947>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller/Integrator ICs'
 * '<S948>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller/N Copy'
 * '<S949>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller/N Gain'
 * '<S950>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller/P Copy'
 * '<S951>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller/Parallel P Gain'
 * '<S952>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller/Reset Signal'
 * '<S953>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller/Saturation'
 * '<S954>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller/Saturation Fdbk'
 * '<S955>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller/Sum'
 * '<S956>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller/Sum Fdbk'
 * '<S957>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller/Tracking Mode'
 * '<S958>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller/Tracking Mode Sum'
 * '<S959>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller/Tsamp - Integral'
 * '<S960>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller/Tsamp - Ngain'
 * '<S961>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller/postSat Signal'
 * '<S962>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller/preSat Signal'
 * '<S963>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller/Anti-windup/Passthrough'
 * '<S964>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller/D Gain/Disabled'
 * '<S965>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller/Filter/Disabled'
 * '<S966>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller/Filter ICs/Disabled'
 * '<S967>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller/I Gain/Internal Parameters'
 * '<S968>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller/Ideal P Gain/Passthrough'
 * '<S969>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S970>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller/Integrator/Discrete'
 * '<S971>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller/Integrator ICs/Internal IC'
 * '<S972>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S973>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller/N Gain/Disabled'
 * '<S974>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller/P Copy/Disabled'
 * '<S975>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S976>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller/Reset Signal/Disabled'
 * '<S977>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller/Saturation/Enabled'
 * '<S978>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller/Saturation Fdbk/Disabled'
 * '<S979>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller/Sum/Sum_PI'
 * '<S980>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller/Sum Fdbk/Disabled'
 * '<S981>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller/Tracking Mode/Disabled'
 * '<S982>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S983>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S984>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S985>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller/postSat Signal/Forward_Path'
 * '<S986>' : 'microrrede_v8/inversor Replus/Controle Inversor /Subsystem/corrente/PID Controller/preSat Signal/Forward_Path'
 * '<S987>' : 'microrrede_v8/inversor Replus/Conversor boost SFV3/Diode'
 * '<S988>' : 'microrrede_v8/inversor Replus/Conversor boost SFV3/IGBT//Diode'
 * '<S989>' : 'microrrede_v8/inversor Replus/Conversor boost SFV3/Diode/Model'
 * '<S990>' : 'microrrede_v8/inversor Replus/Conversor boost SFV3/Diode/Model/Measurement list'
 * '<S991>' : 'microrrede_v8/inversor Replus/Conversor boost SFV3/IGBT//Diode/Model'
 * '<S992>' : 'microrrede_v8/inversor Replus/Conversor boost SFV3/IGBT//Diode/Model/Measurement list'
 * '<S993>' : 'microrrede_v8/inversor Replus/Current Measurement1/Model'
 * '<S994>' : 'microrrede_v8/inversor Replus/Ponte inversora SFV3/Model'
 * '<S995>' : 'microrrede_v8/inversor Replus/Ponte inversora SFV3/Model/Vf 1'
 * '<S996>' : 'microrrede_v8/inversor Replus/Voltage Measurement Vdc/Model'
 * '<S997>' : 'microrrede_v8/inversor Replus/Voltage Measurement2/Model'
 * '<S998>' : 'microrrede_v8/powergui/EquivalentModel1'
 * '<S999>' : 'microrrede_v8/powergui/EquivalentModel1/DSS in'
 * '<S1000>' : 'microrrede_v8/powergui/EquivalentModel1/DSS out'
 * '<S1001>' : 'microrrede_v8/powergui/EquivalentModel1/Gates'
 * '<S1002>' : 'microrrede_v8/powergui/EquivalentModel1/Sources'
 * '<S1003>' : 'microrrede_v8/powergui/EquivalentModel1/Status'
 * '<S1004>' : 'microrrede_v8/powergui/EquivalentModel1/Yout'
 */
#endif                                 /* RTW_HEADER_microrrede_v8_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
