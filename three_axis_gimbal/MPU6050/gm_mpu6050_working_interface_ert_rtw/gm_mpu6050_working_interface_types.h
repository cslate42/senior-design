/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * File: gm_mpu6050_working_interface_types.h
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

#ifndef RTW_HEADER_gm_mpu6050_working_interface_types_h_
#define RTW_HEADER_gm_mpu6050_working_interface_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#ifndef typedef_zynq_AXIRead_gm_mpu6050_worki_T
#define typedef_zynq_AXIRead_gm_mpu6050_worki_T

typedef struct {
  int32_T isInitialized;
  uint32_T DeviceState;
} zynq_AXIRead_gm_mpu6050_worki_T;

#endif                                 /*typedef_zynq_AXIRead_gm_mpu6050_worki_T*/

#ifndef typedef_zynq_AXIWrite_gm_mpu6050_work_T
#define typedef_zynq_AXIWrite_gm_mpu6050_work_T

typedef struct {
  int32_T isInitialized;
  uint32_T DeviceState;
} zynq_AXIWrite_gm_mpu6050_work_T;

#endif                                 /*typedef_zynq_AXIWrite_gm_mpu6050_work_T*/

#ifndef typedef_struct_T_gm_mpu6050_working_i_T
#define typedef_struct_T_gm_mpu6050_working_i_T

typedef struct {
  char_T f1[4];
} struct_T_gm_mpu6050_working_i_T;

#endif                                 /*typedef_struct_T_gm_mpu6050_working_i_T*/

#ifndef typedef_struct_T_gm_mpu6050_working_m_T
#define typedef_struct_T_gm_mpu6050_working_m_T

typedef struct {
  char_T f1[8];
} struct_T_gm_mpu6050_working_m_T;

#endif                                 /*typedef_struct_T_gm_mpu6050_working_m_T*/

#ifndef typedef_struct_T_gm_mpu6050_workin_mh_T
#define typedef_struct_T_gm_mpu6050_workin_mh_T

typedef struct {
  char_T f1[7];
} struct_T_gm_mpu6050_workin_mh_T;

#endif                                 /*typedef_struct_T_gm_mpu6050_workin_mh_T*/

#ifndef typedef_struct_T_gm_mpu6050_worki_mhz_T
#define typedef_struct_T_gm_mpu6050_worki_mhz_T

typedef struct {
  char_T f1[11];
  char_T f2[7];
  char_T f3[6];
  char_T f4[2];
  real_T f5;
} struct_T_gm_mpu6050_worki_mhz_T;

#endif                                 /*typedef_struct_T_gm_mpu6050_worki_mhz_T*/

#ifndef typedef_struct_T_gm_mpu6050_work_mhzp_T
#define typedef_struct_T_gm_mpu6050_work_mhzp_T

typedef struct {
  char_T f1[8];
  char_T f2[7];
  char_T f3[6];
  char_T f4[2];
  uint32_T f5;
} struct_T_gm_mpu6050_work_mhzp_T;

#endif                                 /*typedef_struct_T_gm_mpu6050_work_mhzp_T*/

#ifndef typedef_struct_T_gm_mpu6050_wor_mhzpr_T
#define typedef_struct_T_gm_mpu6050_wor_mhzpr_T

typedef struct {
  real_T f1[2];
} struct_T_gm_mpu6050_wor_mhzpr_T;

#endif                                 /*typedef_struct_T_gm_mpu6050_wor_mhzpr_T*/

/* Parameters (auto storage) */
typedef struct P_gm_mpu6050_working_interfac_T_ P_gm_mpu6050_working_interfac_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_gm_mpu6050_working_in_T RT_MODEL_gm_mpu6050_working_i_T;

#endif                                 /* RTW_HEADER_gm_mpu6050_working_interface_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
