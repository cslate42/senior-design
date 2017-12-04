/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * File: gm_mpu6050_working_interface.h
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

#ifndef RTW_HEADER_gm_mpu6050_working_interface_h_
#define RTW_HEADER_gm_mpu6050_working_interface_h_
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef gm_mpu6050_working_interface_COMMON_INCLUDES_
# define gm_mpu6050_working_interface_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "dt_info.h"
#include "ext_work.h"
#include "axi_lct.h"
#endif                                 /* gm_mpu6050_working_interface_COMMON_INCLUDES_ */

#include "gm_mpu6050_working_interface_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T angle;                        /* '<S3>/MATLAB Function1' */
  real_T angle_e;                      /* '<S2>/MATLAB Function1' */
  real_T angle_i;                      /* '<S1>/MATLAB Function1' */
  int16_T AXI4Lite_Read_GyroX_DTC;     /* '<S12>/AXI4Lite_Read_GyroX_DTC' */
  int16_T AXI4Lite_Read_GyroY_DTC;     /* '<S12>/AXI4Lite_Read_GyroY_DTC' */
  int16_T AXI4Lite_Read_GyroZ_DTC;     /* '<S12>/AXI4Lite_Read_GyroZ_DTC' */
  uint8_T AXI4Lite_Read_deviceID_DTC;  /* '<S12>/AXI4Lite_Read_deviceID_DTC' */
  uint8_T AXI4Lite_Read_RegData_DTC;   /* '<S12>/AXI4Lite_Read_RegData_DTC' */
} B_gm_mpu6050_working_interfac_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay3_DSTATE;            /* '<S1>/Unit Delay3' */
  real_T UnitDelay3_DSTATE_i;          /* '<S2>/Unit Delay3' */
  real_T UnitDelay3_DSTATE_m;          /* '<S3>/Unit Delay3' */
  zynq_AXIRead_gm_mpu6050_worki_T obj; /* '<S23>/AXI4-Interface Read' */
  zynq_AXIRead_gm_mpu6050_worki_T obj_f;/* '<S22>/AXI4-Interface Read' */
  zynq_AXIRead_gm_mpu6050_worki_T obj_a;/* '<S21>/AXI4-Interface Read' */
  zynq_AXIRead_gm_mpu6050_worki_T obj_o;/* '<S20>/AXI4-Interface Read' */
  zynq_AXIRead_gm_mpu6050_worki_T obj_i;/* '<S19>/AXI4-Interface Read' */
  zynq_AXIRead_gm_mpu6050_worki_T obj_av;/* '<S18>/AXI4-Interface Read' */
  zynq_AXIRead_gm_mpu6050_worki_T obj_j;/* '<S17>/AXI4-Interface Read' */
  zynq_AXIRead_gm_mpu6050_worki_T obj_n;/* '<S16>/AXI4-Interface Read' */
  zynq_AXIRead_gm_mpu6050_worki_T obj_b;/* '<S15>/AXI4-Interface Read' */
  zynq_AXIRead_gm_mpu6050_worki_T obj_o0;/* '<S14>/AXI4-Interface Read' */
  zynq_AXIWrite_gm_mpu6050_work_T obj_k;/* '<S25>/AXI4-Interface Write' */
  zynq_AXIWrite_gm_mpu6050_work_T obj_p;/* '<S24>/AXI4-Interface Write' */
  struct {
    void *LoggedData[6];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  void *AXI4InterfaceWrite_PWORK;      /* '<S25>/AXI4-Interface Write' */
  void *AXI4InterfaceWrite_PWORK_p;    /* '<S24>/AXI4-Interface Write' */
  void *AXI4InterfaceRead_PWORK;       /* '<S23>/AXI4-Interface Read' */
  void *AXI4InterfaceRead_PWORK_b;     /* '<S22>/AXI4-Interface Read' */
  void *AXI4InterfaceRead_PWORK_m;     /* '<S21>/AXI4-Interface Read' */
  void *AXI4InterfaceRead_PWORK_j;     /* '<S20>/AXI4-Interface Read' */
  void *AXI4InterfaceRead_PWORK_i;     /* '<S19>/AXI4-Interface Read' */
  void *AXI4InterfaceRead_PWORK_h;     /* '<S18>/AXI4-Interface Read' */
  void *AXI4InterfaceRead_PWORK_c;     /* '<S17>/AXI4-Interface Read' */
  void *AXI4InterfaceRead_PWORK_e;     /* '<S16>/AXI4-Interface Read' */
  void *AXI4InterfaceRead_PWORK_j4;    /* '<S15>/AXI4-Interface Read' */
  void *AXI4InterfaceRead_PWORK_ma;    /* '<S14>/AXI4-Interface Read' */
} DW_gm_mpu6050_working_interfa_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T gyroX;                        /* '<Root>/gyroX' */
  real_T gyroY;                        /* '<Root>/gyroY' */
  real_T gyroZ;                        /* '<Root>/gyroZ' */
} ExtY_gm_mpu6050_working_inter_T;

/* Parameters (auto storage) */
struct P_gm_mpu6050_working_interfac_T_ {
  real_T UnitDelay3_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S1>/Unit Delay3'
                                        */
  real_T UnitDelay3_InitialCondition_c;/* Expression: 0
                                        * Referenced by: '<S2>/Unit Delay3'
                                        */
  real_T UnitDelay3_InitialCondition_g;/* Expression: 0
                                        * Referenced by: '<S3>/Unit Delay3'
                                        */
  int16_T Constant3_Value;             /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<Root>/Constant3'
                                        */
  int16_T Constant4_Value;             /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<Root>/Constant4'
                                        */
  int16_T Constant5_Value;             /* Computed Parameter: Constant5_Value
                                        * Referenced by: '<Root>/Constant5'
                                        */
  uint8_T Constant2_Value;             /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<Root>/Constant2'
                                        */
  uint8_T ManualSwitch_CurrentSetting; /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch'
                                        */
  boolean_T Constant_Value;            /* Computed Parameter: Constant_Value
                                        * Referenced by: '<Root>/Constant'
                                        */
  boolean_T Constant1_Value;           /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<Root>/Constant1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_gm_mpu6050_working_in_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_gm_mpu6050_working_interfac_T gm_mpu6050_working_interface_P;

/* Block signals (auto storage) */
extern B_gm_mpu6050_working_interfac_T gm_mpu6050_working_interface_B;

/* Block states (auto storage) */
extern DW_gm_mpu6050_working_interfa_T gm_mpu6050_working_interface_DW;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_gm_mpu6050_working_inter_T gm_mpu6050_working_interface_Y;

/* Model entry point functions */
extern void gm_mpu6050_working_interface_initialize(void);
extern void gm_mpu6050_working_interface_step(void);
extern void gm_mpu6050_working_interface_terminate(void);

/* Real-time Model object */
extern RT_MODEL_gm_mpu6050_working_i_T *const gm_mpu6050_working_interface_M;

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
 * '<Root>' : 'gm_mpu6050_working_interface'
 * '<S1>'   : 'gm_mpu6050_working_interface/AngleConverterX'
 * '<S2>'   : 'gm_mpu6050_working_interface/AngleConverterY'
 * '<S3>'   : 'gm_mpu6050_working_interface/AngleConverterZ'
 * '<S4>'   : 'gm_mpu6050_working_interface/I2C_MPU6050_IP'
 * '<S5>'   : 'gm_mpu6050_working_interface/Subsystem'
 * '<S6>'   : 'gm_mpu6050_working_interface/AngleConverterX/GyroConverter'
 * '<S7>'   : 'gm_mpu6050_working_interface/AngleConverterX/MATLAB Function1'
 * '<S8>'   : 'gm_mpu6050_working_interface/AngleConverterY/GyroConverter'
 * '<S9>'   : 'gm_mpu6050_working_interface/AngleConverterY/MATLAB Function1'
 * '<S10>'  : 'gm_mpu6050_working_interface/AngleConverterZ/GyroConverter'
 * '<S11>'  : 'gm_mpu6050_working_interface/AngleConverterZ/MATLAB Function1'
 * '<S12>'  : 'gm_mpu6050_working_interface/I2C_MPU6050_IP/AXI4LiteRead'
 * '<S13>'  : 'gm_mpu6050_working_interface/I2C_MPU6050_IP/AXI4LiteWrite'
 * '<S14>'  : 'gm_mpu6050_working_interface/I2C_MPU6050_IP/AXI4LiteRead/AXI4Lite_Read_AccelX'
 * '<S15>'  : 'gm_mpu6050_working_interface/I2C_MPU6050_IP/AXI4LiteRead/AXI4Lite_Read_AccelY'
 * '<S16>'  : 'gm_mpu6050_working_interface/I2C_MPU6050_IP/AXI4LiteRead/AXI4Lite_Read_AccelZ'
 * '<S17>'  : 'gm_mpu6050_working_interface/I2C_MPU6050_IP/AXI4LiteRead/AXI4Lite_Read_GyroX'
 * '<S18>'  : 'gm_mpu6050_working_interface/I2C_MPU6050_IP/AXI4LiteRead/AXI4Lite_Read_GyroY'
 * '<S19>'  : 'gm_mpu6050_working_interface/I2C_MPU6050_IP/AXI4LiteRead/AXI4Lite_Read_GyroZ'
 * '<S20>'  : 'gm_mpu6050_working_interface/I2C_MPU6050_IP/AXI4LiteRead/AXI4Lite_Read_RegData'
 * '<S21>'  : 'gm_mpu6050_working_interface/I2C_MPU6050_IP/AXI4LiteRead/AXI4Lite_Read_deviceID'
 * '<S22>'  : 'gm_mpu6050_working_interface/I2C_MPU6050_IP/AXI4LiteRead/AXI4Lite_Read_isDeviceSetup'
 * '<S23>'  : 'gm_mpu6050_working_interface/I2C_MPU6050_IP/AXI4LiteRead/AXI4Lite_Read_validout'
 * '<S24>'  : 'gm_mpu6050_working_interface/I2C_MPU6050_IP/AXI4LiteWrite/AXI4Lite_Write_ConfigDevice'
 * '<S25>'  : 'gm_mpu6050_working_interface/I2C_MPU6050_IP/AXI4LiteWrite/AXI4Lite_Write_RegAddr'
 * '<S26>'  : 'gm_mpu6050_working_interface/Subsystem/Chart'
 * '<S27>'  : 'gm_mpu6050_working_interface/Subsystem/Subsystem'
 * '<S28>'  : 'gm_mpu6050_working_interface/Subsystem/Subsystem/MATLAB Function'
 * '<S29>'  : 'gm_mpu6050_working_interface/Subsystem/Subsystem/MATLAB Function1'
 * '<S30>'  : 'gm_mpu6050_working_interface/Subsystem/Subsystem/PID Controller'
 */
#endif                                 /* RTW_HEADER_gm_mpu6050_working_interface_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
