/*
 * File: microrrede_v8_private.h
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

#ifndef RTW_HEADER_microrrede_v8_private_h_
#define RTW_HEADER_microrrede_v8_private_h_
#include "rtwtypes.h"
#include "microrrede_v8.h"
#include "microrrede_v8_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

extern real_T rt_remd_snf(real_T u0, real_T u1);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern real_T rt_hypotd_snf(real_T u0, real_T u1);
extern real_T look1_pbinlxpw(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T prevIndex[], uint32_T maxIndex);
extern void sfun_discreteVariableDelay(SimStruct *rts);
extern void sfun_spssw_discc_DSS(SimStruct *rts);
extern void microrrede__MATLABFunction_Init(DW_MATLABFunction_microrrede__T
  *localDW);
extern void microrrede_v8_MATLABFunction(real_T rtu_V, real_T rtu_I, real_T
  *rty_D, DW_MATLABFunction_microrrede__T *localDW);
extern void microrrede_v8_Subsystempi2delay(uint8_T rtu_Enable, real_T
  rtu_alpha_beta, real_T rtu_alpha_beta_c, real_T rtu_wt, real_T *rty_dq, real_T
  *rty_dq_a);
extern void microrrede_v8_Subsystem1(uint8_T rtu_Enable, real_T rtu_alpha_beta,
  real_T rtu_alpha_beta_k, real_T rtu_wt, real_T *rty_dq, real_T *rty_dq_k);

#endif                                 /* RTW_HEADER_microrrede_v8_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
