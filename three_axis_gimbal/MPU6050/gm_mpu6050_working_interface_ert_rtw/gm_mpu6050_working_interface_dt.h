/*
 * gm_mpu6050_working_interface_dt.h
 *
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * Code generation for model "gm_mpu6050_working_interface".
 *
 * Model version              : 1.304
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Mon Dec 04 00:39:38 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(zynq_AXIRead_gm_mpu6050_worki_T),
  sizeof(zynq_AXIWrite_gm_mpu6050_work_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "zynq_AXIRead_gm_mpu6050_worki_T",
  "zynq_AXIWrite_gm_mpu6050_work_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&gm_mpu6050_working_interface_B.angle), 0, 0, 3 },

  { (char_T *)(&gm_mpu6050_working_interface_B.AXI4Lite_Read_GyroX_DTC), 4, 0, 3
  },

  { (char_T *)(&gm_mpu6050_working_interface_B.AXI4Lite_Read_deviceID_DTC), 3, 0,
    2 }
  ,

  { (char_T *)(&gm_mpu6050_working_interface_DW.UnitDelay3_DSTATE), 0, 0, 3 },

  { (char_T *)(&gm_mpu6050_working_interface_DW.obj), 14, 0, 10 },

  { (char_T *)(&gm_mpu6050_working_interface_DW.obj_k), 15, 0, 2 },

  { (char_T *)(&gm_mpu6050_working_interface_DW.Scope_PWORK.LoggedData[0]), 11,
    0, 18 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  7U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&gm_mpu6050_working_interface_P.UnitDelay3_InitialCondition), 0,
    0, 3 },

  { (char_T *)(&gm_mpu6050_working_interface_P.Constant3_Value), 4, 0, 3 },

  { (char_T *)(&gm_mpu6050_working_interface_P.Constant2_Value), 3, 0, 2 },

  { (char_T *)(&gm_mpu6050_working_interface_P.Constant_Value), 8, 0, 2 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  4U,
  rtPTransitions
};

/* [EOF] gm_mpu6050_working_interface_dt.h */
