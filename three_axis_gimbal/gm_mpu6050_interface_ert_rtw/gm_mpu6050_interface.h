/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * File: gm_mpu6050_interface.h
 *
 * Code generated for Simulink model 'gm_mpu6050_interface'.
 *
 * Model version                  : 1.262
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Fri Dec 01 17:20:00 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_gm_mpu6050_interface_h_
#define RTW_HEADER_gm_mpu6050_interface_h_
#include <stddef.h>
#include <string.h>
#ifndef gm_mpu6050_interface_COMMON_INCLUDES_
# define gm_mpu6050_interface_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "axi_lct.h"
#endif                                 /* gm_mpu6050_interface_COMMON_INCLUDES_ */

#include "gm_mpu6050_interface_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  zynq_AXIRead_gm_mpu6050_inter_T obj; /* '<S13>/AXI4-Interface Read' */
  zynq_AXIRead_gm_mpu6050_inter_T obj_h;/* '<S12>/AXI4-Interface Read' */
  zynq_AXIRead_gm_mpu6050_inter_T obj_k;/* '<S11>/AXI4-Interface Read' */
  zynq_AXIRead_gm_mpu6050_inter_T obj_f;/* '<S10>/AXI4-Interface Read' */
  zynq_AXIRead_gm_mpu6050_inter_T obj_fp;/* '<S9>/AXI4-Interface Read' */
  zynq_AXIRead_gm_mpu6050_inter_T obj_km;/* '<S8>/AXI4-Interface Read' */
  zynq_AXIRead_gm_mpu6050_inter_T obj_fh;/* '<S7>/AXI4-Interface Read' */
  zynq_AXIRead_gm_mpu6050_inter_T obj_n;/* '<S6>/AXI4-Interface Read' */
  zynq_AXIRead_gm_mpu6050_inter_T obj_fu;/* '<S5>/AXI4-Interface Read' */
  zynq_AXIWrite_gm_mpu6050_inte_T obj_nw;/* '<S14>/AXI4-Interface Write' */
  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData[2];
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  void *AXI4InterfaceWrite_PWORK;      /* '<S14>/AXI4-Interface Write' */
  void *AXI4InterfaceRead_PWORK;       /* '<S13>/AXI4-Interface Read' */
  void *AXI4InterfaceRead_PWORK_e;     /* '<S12>/AXI4-Interface Read' */
  void *AXI4InterfaceRead_PWORK_d;     /* '<S11>/AXI4-Interface Read' */
  void *AXI4InterfaceRead_PWORK_i;     /* '<S10>/AXI4-Interface Read' */
  void *AXI4InterfaceRead_PWORK_g;     /* '<S9>/AXI4-Interface Read' */
  void *AXI4InterfaceRead_PWORK_e1;    /* '<S8>/AXI4-Interface Read' */
  void *AXI4InterfaceRead_PWORK_i5;    /* '<S7>/AXI4-Interface Read' */
  void *AXI4InterfaceRead_PWORK_c;     /* '<S6>/AXI4-Interface Read' */
  void *AXI4InterfaceRead_PWORK_ca;    /* '<S5>/AXI4-Interface Read' */
} DW_gm_mpu6050_interface_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  boolean_T TmpCnfDevice;              /* '<Root>/TmpCnfDevice' */
} ExtU_gm_mpu6050_interface_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  boolean_T SCL;                       /* '<Root>/SCL' */
  boolean_T SDA;                       /* '<Root>/SDA' */
  boolean_T CS;                        /* '<Root>/CS' */
  boolean_T AddrAlt;                   /* '<Root>/AddrAlt' */
} ExtY_gm_mpu6050_interface_T;

/* Parameters (auto storage) */
struct P_gm_mpu6050_interface_T_ {
  uint8_T Constant2_Value;             /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<Root>/Constant2'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_gm_mpu6050_interface_T {
  const char_T *errorStatus;
};

/* Block parameters (auto storage) */
extern P_gm_mpu6050_interface_T gm_mpu6050_interface_P;

/* Block states (auto storage) */
extern DW_gm_mpu6050_interface_T gm_mpu6050_interface_DW;

/* External inputs (root inport signals with auto storage) */
extern ExtU_gm_mpu6050_interface_T gm_mpu6050_interface_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_gm_mpu6050_interface_T gm_mpu6050_interface_Y;

/* Model entry point functions */
extern void gm_mpu6050_interface_initialize(void);
extern void gm_mpu6050_interface_step(void);
extern void gm_mpu6050_interface_terminate(void);

/* Real-time Model object */
extern RT_MODEL_gm_mpu6050_interface_T *const gm_mpu6050_interface_M;

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
 * '<Root>' : 'gm_mpu6050_interface'
 * '<S1>'   : 'gm_mpu6050_interface/I2C_MPU6050_IP'
 * '<S2>'   : 'gm_mpu6050_interface/MATLAB Function'
 * '<S3>'   : 'gm_mpu6050_interface/I2C_MPU6050_IP/AXI4LiteRead'
 * '<S4>'   : 'gm_mpu6050_interface/I2C_MPU6050_IP/AXI4LiteWrite'
 * '<S5>'   : 'gm_mpu6050_interface/I2C_MPU6050_IP/AXI4LiteRead/AXI4Lite_Read_AccelX'
 * '<S6>'   : 'gm_mpu6050_interface/I2C_MPU6050_IP/AXI4LiteRead/AXI4Lite_Read_AccelY'
 * '<S7>'   : 'gm_mpu6050_interface/I2C_MPU6050_IP/AXI4LiteRead/AXI4Lite_Read_AccelZ'
 * '<S8>'   : 'gm_mpu6050_interface/I2C_MPU6050_IP/AXI4LiteRead/AXI4Lite_Read_GyroX'
 * '<S9>'   : 'gm_mpu6050_interface/I2C_MPU6050_IP/AXI4LiteRead/AXI4Lite_Read_GyroY'
 * '<S10>'  : 'gm_mpu6050_interface/I2C_MPU6050_IP/AXI4LiteRead/AXI4Lite_Read_GyroZ'
 * '<S11>'  : 'gm_mpu6050_interface/I2C_MPU6050_IP/AXI4LiteRead/AXI4Lite_Read_RegData'
 * '<S12>'  : 'gm_mpu6050_interface/I2C_MPU6050_IP/AXI4LiteRead/AXI4Lite_Read_deviceID'
 * '<S13>'  : 'gm_mpu6050_interface/I2C_MPU6050_IP/AXI4LiteRead/AXI4Lite_Read_validout'
 * '<S14>'  : 'gm_mpu6050_interface/I2C_MPU6050_IP/AXI4LiteWrite/AXI4Lite_Write_RegAddr'
 */
#endif                                 /* RTW_HEADER_gm_mpu6050_interface_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
