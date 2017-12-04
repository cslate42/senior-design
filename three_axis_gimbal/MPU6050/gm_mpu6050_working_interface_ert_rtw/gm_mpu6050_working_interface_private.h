/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * File: gm_mpu6050_working_interface_private.h
 *
 * Code generated for Simulink model 'gm_mpu6050_working_interface'.
 *
 * Model version                  : 1.304
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Mon Dec 04 00:39:38 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_gm_mpu6050_working_interface_private_h_
#define RTW_HEADER_gm_mpu6050_working_interface_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "gm_mpu6050_working_interface.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

extern void gm_mpu6050_work_MATLABFunction1(real_T rtu_inAngle, boolean_T
  rtu_isDeviceSetup, real_T *rty_angle);

#endif                                 /* RTW_HEADER_gm_mpu6050_working_interface_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
