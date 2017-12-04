/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * File: gm_mpu6050_working_interface.c
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

#include "gm_mpu6050_working_interface.h"
#include "gm_mpu6050_working_interface_private.h"
#include "gm_mpu6050_working_interface_dt.h"
#define gm_m_RegisterOffset_mhzprckztiy (276U)
#define gm_mp_RegisterOffset_mhzprckzti (260U)
#define gm_mpu6050_RegisterOffset_mhzpr (300U)
#define gm_mpu6050__RegisterOffset_mhzp (296U)
#define gm_mpu6050_w_RegisterOffset_mhz (292U)
#define gm_mpu6050_wo_RegisterOffset_mh (272U)
#define gm_mpu6050_wor_RegisterOffset_m (268U)
#define gm_mpu6050_worki_RegisterOffset (264U)
#define gm_mpu605_RegisterOffset_mhzprc (288U)
#define gm_mpu60_RegisterOffset_mhzprck (284U)
#define gm_mpu6_RegisterOffset_mhzprckz (256U)
#define gm_mpu_RegisterOffset_mhzprckzt (280U)

/* user code (top of source file) */
/* System '<Root>/I2C_MPU6050_IP' */
#include "axi_lct.h"

/* Block signals (auto storage) */
B_gm_mpu6050_working_interfac_T gm_mpu6050_working_interface_B;

/* Block states (auto storage) */
DW_gm_mpu6050_working_interfa_T gm_mpu6050_working_interface_DW;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_gm_mpu6050_working_inter_T gm_mpu6050_working_interface_Y;

/* Real-time model */
RT_MODEL_gm_mpu6050_working_i_T gm_mpu6050_working_interface_M_;
RT_MODEL_gm_mpu6050_working_i_T *const gm_mpu6050_working_interface_M =
  &gm_mpu6050_working_interface_M_;

/*
 * Output and update for atomic system:
 *    '<S1>/MATLAB Function1'
 *    '<S2>/MATLAB Function1'
 *    '<S3>/MATLAB Function1'
 */
void gm_mpu6050_work_MATLABFunction1(real_T rtu_inAngle, boolean_T
  rtu_isDeviceSetup, real_T *rty_angle)
{
  /* MATLAB Function 'AngleConverterX/MATLAB Function1': '<S7>:1' */
  /* '<S7>:1:2' if isDeviceSetup == true */
  if (rtu_isDeviceSetup) {
    /* '<S7>:1:3' angle = inAngle; */
    *rty_angle = rtu_inAngle;
  } else {
    /* '<S7>:1:4' else */
    /* '<S7>:1:5' angle = 0; */
    *rty_angle = 0.0;
  }
}

/* Model step function */
void gm_mpu6050_working_interface_step(void)
{
  AXI4_struct * p_state;
  uint32_T rtb_AXI4Lite_Write_RegAddr_DTC;
  boolean_T rtb_ManualSwitch;

  /* ManualSwitch: '<Root>/Manual Switch' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   */
  if (gm_mpu6050_working_interface_P.ManualSwitch_CurrentSetting == 1) {
    rtb_ManualSwitch = gm_mpu6050_working_interface_P.Constant_Value;
  } else {
    rtb_ManualSwitch = gm_mpu6050_working_interface_P.Constant1_Value;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */

  /* Outputs for Atomic SubSystem: '<Root>/I2C_MPU6050_IP' */

  /* DataTypeConversion: '<S13>/AXI4Lite_Write_RegAddr_DTC' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  rtb_AXI4Lite_Write_RegAddr_DTC =
    gm_mpu6050_working_interface_P.Constant2_Value;

  /* Start for MATLABSystem: '<S25>/AXI4-Interface Write' incorporates:
   *  MATLABSystem: '<S25>/AXI4-Interface Write'
   */
  p_state = (AXI4_struct *)(gm_mpu6050_working_interface_DW.obj_k.DeviceState);
  AXI4LITE_WRITE(p_state, &rtb_AXI4Lite_Write_RegAddr_DTC,
                 gm_m_RegisterOffset_mhzprckztiy, 4U);

  /* DataTypeConversion: '<S13>/AXI4Lite_Write_ConfigDevice_DTC' */
  rtb_AXI4Lite_Write_RegAddr_DTC = rtb_ManualSwitch;

  /* Start for MATLABSystem: '<S24>/AXI4-Interface Write' incorporates:
   *  MATLABSystem: '<S24>/AXI4-Interface Write'
   */
  p_state = (AXI4_struct *)(gm_mpu6050_working_interface_DW.obj_p.DeviceState);
  AXI4LITE_WRITE(p_state, &rtb_AXI4Lite_Write_RegAddr_DTC,
                 gm_mp_RegisterOffset_mhzprckzti, 4U);

  /* Start for MATLABSystem: '<S14>/AXI4-Interface Read' incorporates:
   *  MATLABSystem: '<S14>/AXI4-Interface Read'
   */
  p_state = (AXI4_struct *)(gm_mpu6050_working_interface_DW.obj_o0.DeviceState);
  AXI4LITE_READ(p_state, &rtb_AXI4Lite_Write_RegAddr_DTC,
                gm_mpu6050_worki_RegisterOffset, 4U);

  /* Start for MATLABSystem: '<S15>/AXI4-Interface Read' incorporates:
   *  MATLABSystem: '<S15>/AXI4-Interface Read'
   */
  p_state = (AXI4_struct *)(gm_mpu6050_working_interface_DW.obj_b.DeviceState);
  AXI4LITE_READ(p_state, &rtb_AXI4Lite_Write_RegAddr_DTC,
                gm_mpu6050_wor_RegisterOffset_m, 4U);

  /* Start for MATLABSystem: '<S16>/AXI4-Interface Read' incorporates:
   *  MATLABSystem: '<S16>/AXI4-Interface Read'
   */
  p_state = (AXI4_struct *)(gm_mpu6050_working_interface_DW.obj_n.DeviceState);
  AXI4LITE_READ(p_state, &rtb_AXI4Lite_Write_RegAddr_DTC,
                gm_mpu6050_wo_RegisterOffset_mh, 4U);

  /* Start for MATLABSystem: '<S23>/AXI4-Interface Read' incorporates:
   *  MATLABSystem: '<S23>/AXI4-Interface Read'
   */
  p_state = (AXI4_struct *)(gm_mpu6050_working_interface_DW.obj.DeviceState);
  AXI4LITE_READ(p_state, &rtb_AXI4Lite_Write_RegAddr_DTC,
                gm_mpu_RegisterOffset_mhzprckzt, 4U);

  /* Start for MATLABSystem: '<S21>/AXI4-Interface Read' incorporates:
   *  MATLABSystem: '<S21>/AXI4-Interface Read'
   */
  p_state = (AXI4_struct *)(gm_mpu6050_working_interface_DW.obj_a.DeviceState);
  AXI4LITE_READ(p_state, &rtb_AXI4Lite_Write_RegAddr_DTC,
                gm_mpu60_RegisterOffset_mhzprck, 4U);

  /* DataTypeConversion: '<S12>/AXI4Lite_Read_deviceID_DTC' incorporates:
   *  MATLABSystem: '<S21>/AXI4-Interface Read'
   */
  gm_mpu6050_working_interface_B.AXI4Lite_Read_deviceID_DTC = (uint8_T)
    rtb_AXI4Lite_Write_RegAddr_DTC;

  /* Start for MATLABSystem: '<S20>/AXI4-Interface Read' incorporates:
   *  MATLABSystem: '<S20>/AXI4-Interface Read'
   */
  p_state = (AXI4_struct *)(gm_mpu6050_working_interface_DW.obj_o.DeviceState);
  AXI4LITE_READ(p_state, &rtb_AXI4Lite_Write_RegAddr_DTC,
                gm_mpu605_RegisterOffset_mhzprc, 4U);

  /* DataTypeConversion: '<S12>/AXI4Lite_Read_RegData_DTC' incorporates:
   *  MATLABSystem: '<S20>/AXI4-Interface Read'
   */
  gm_mpu6050_working_interface_B.AXI4Lite_Read_RegData_DTC = (uint8_T)
    rtb_AXI4Lite_Write_RegAddr_DTC;

  /* Start for MATLABSystem: '<S17>/AXI4-Interface Read' incorporates:
   *  MATLABSystem: '<S17>/AXI4-Interface Read'
   */
  p_state = (AXI4_struct *)(gm_mpu6050_working_interface_DW.obj_j.DeviceState);
  AXI4LITE_READ(p_state, &rtb_AXI4Lite_Write_RegAddr_DTC,
                gm_mpu6050_w_RegisterOffset_mhz, 4U);

  /* DataTypeConversion: '<S12>/AXI4Lite_Read_GyroX_DTC' incorporates:
   *  MATLABSystem: '<S17>/AXI4-Interface Read'
   */
  gm_mpu6050_working_interface_B.AXI4Lite_Read_GyroX_DTC = (int16_T)
    rtb_AXI4Lite_Write_RegAddr_DTC;

  /* Start for MATLABSystem: '<S18>/AXI4-Interface Read' incorporates:
   *  MATLABSystem: '<S18>/AXI4-Interface Read'
   */
  p_state = (AXI4_struct *)(gm_mpu6050_working_interface_DW.obj_av.DeviceState);
  AXI4LITE_READ(p_state, &rtb_AXI4Lite_Write_RegAddr_DTC,
                gm_mpu6050__RegisterOffset_mhzp, 4U);

  /* DataTypeConversion: '<S12>/AXI4Lite_Read_GyroY_DTC' incorporates:
   *  MATLABSystem: '<S18>/AXI4-Interface Read'
   */
  gm_mpu6050_working_interface_B.AXI4Lite_Read_GyroY_DTC = (int16_T)
    rtb_AXI4Lite_Write_RegAddr_DTC;

  /* Start for MATLABSystem: '<S19>/AXI4-Interface Read' incorporates:
   *  MATLABSystem: '<S19>/AXI4-Interface Read'
   */
  p_state = (AXI4_struct *)(gm_mpu6050_working_interface_DW.obj_i.DeviceState);
  AXI4LITE_READ(p_state, &rtb_AXI4Lite_Write_RegAddr_DTC,
                gm_mpu6050_RegisterOffset_mhzpr, 4U);

  /* DataTypeConversion: '<S12>/AXI4Lite_Read_GyroZ_DTC' incorporates:
   *  MATLABSystem: '<S19>/AXI4-Interface Read'
   */
  gm_mpu6050_working_interface_B.AXI4Lite_Read_GyroZ_DTC = (int16_T)
    rtb_AXI4Lite_Write_RegAddr_DTC;

  /* Start for MATLABSystem: '<S22>/AXI4-Interface Read' incorporates:
   *  MATLABSystem: '<S22>/AXI4-Interface Read'
   */
  p_state = (AXI4_struct *)(gm_mpu6050_working_interface_DW.obj_f.DeviceState);
  AXI4LITE_READ(p_state, &rtb_AXI4Lite_Write_RegAddr_DTC,
                gm_mpu6_RegisterOffset_mhzprckz, 4U);

  /* DataTypeConversion: '<S12>/AXI4Lite_Read_isDeviceSetup_DTC' incorporates:
   *  MATLABSystem: '<S22>/AXI4-Interface Read'
   */
  rtb_ManualSwitch = (rtb_AXI4Lite_Write_RegAddr_DTC != 0U);

  /* End of Outputs for SubSystem: '<Root>/I2C_MPU6050_IP' */

  /* MATLAB Function: '<S1>/MATLAB Function1' incorporates:
   *  Constant: '<Root>/Constant3'
   *  DataTypeConversion: '<S6>/Data Type Conversion'
   *  Fcn: '<S6>/Fcn'
   *  Sum: '<S1>/Subtract'
   *  Sum: '<S1>/Sum1'
   *  UnitDelay: '<S1>/Unit Delay3'
   */
  gm_mpu6050_work_MATLABFunction1(0.030518509475997192 * (real_T)(int16_T)
    (gm_mpu6050_working_interface_B.AXI4Lite_Read_GyroX_DTC -
     gm_mpu6050_working_interface_P.Constant3_Value) / 32.8 +
    gm_mpu6050_working_interface_DW.UnitDelay3_DSTATE, rtb_ManualSwitch,
    &gm_mpu6050_working_interface_B.angle_i);

  /* Outport: '<Root>/gyroX' */
  gm_mpu6050_working_interface_Y.gyroX = gm_mpu6050_working_interface_B.angle_i;

  /* MATLAB Function: '<S2>/MATLAB Function1' incorporates:
   *  Constant: '<Root>/Constant4'
   *  DataTypeConversion: '<S8>/Data Type Conversion'
   *  Fcn: '<S8>/Fcn'
   *  Sum: '<S2>/Subtract'
   *  Sum: '<S2>/Sum1'
   *  UnitDelay: '<S2>/Unit Delay3'
   */
  gm_mpu6050_work_MATLABFunction1(0.030518509475997192 * (real_T)(int16_T)
    (gm_mpu6050_working_interface_B.AXI4Lite_Read_GyroY_DTC -
     gm_mpu6050_working_interface_P.Constant4_Value) +
    gm_mpu6050_working_interface_DW.UnitDelay3_DSTATE_i, rtb_ManualSwitch,
    &gm_mpu6050_working_interface_B.angle_e);

  /* Outport: '<Root>/gyroY' */
  gm_mpu6050_working_interface_Y.gyroY = gm_mpu6050_working_interface_B.angle_e;

  /* MATLAB Function: '<S3>/MATLAB Function1' incorporates:
   *  Constant: '<Root>/Constant5'
   *  DataTypeConversion: '<S10>/Data Type Conversion'
   *  Fcn: '<S10>/Fcn'
   *  Sum: '<S3>/Subtract'
   *  Sum: '<S3>/Sum1'
   *  UnitDelay: '<S3>/Unit Delay3'
   */
  gm_mpu6050_work_MATLABFunction1(0.030518509475997192 * (real_T)(int16_T)
    (gm_mpu6050_working_interface_B.AXI4Lite_Read_GyroZ_DTC -
     gm_mpu6050_working_interface_P.Constant5_Value) +
    gm_mpu6050_working_interface_DW.UnitDelay3_DSTATE_m, rtb_ManualSwitch,
    &gm_mpu6050_working_interface_B.angle);

  /* Outport: '<Root>/gyroZ' */
  gm_mpu6050_working_interface_Y.gyroZ = gm_mpu6050_working_interface_B.angle;

  /* Update for UnitDelay: '<S1>/Unit Delay3' */
  gm_mpu6050_working_interface_DW.UnitDelay3_DSTATE =
    gm_mpu6050_working_interface_B.angle_i;

  /* Update for UnitDelay: '<S2>/Unit Delay3' */
  gm_mpu6050_working_interface_DW.UnitDelay3_DSTATE_i =
    gm_mpu6050_working_interface_B.angle_e;

  /* Update for UnitDelay: '<S3>/Unit Delay3' */
  gm_mpu6050_working_interface_DW.UnitDelay3_DSTATE_m =
    gm_mpu6050_working_interface_B.angle;

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.2s, 0.0s] */
    rtExtModeUpload(0, gm_mpu6050_working_interface_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.2s, 0.0s] */
    if ((rtmGetTFinal(gm_mpu6050_working_interface_M)!=-1) &&
        !((rtmGetTFinal(gm_mpu6050_working_interface_M)-
           gm_mpu6050_working_interface_M->Timing.taskTime0) >
          gm_mpu6050_working_interface_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(gm_mpu6050_working_interface_M, "Simulation finished");
    }

    if (rtmGetStopRequested(gm_mpu6050_working_interface_M)) {
      rtmSetErrorStatus(gm_mpu6050_working_interface_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  gm_mpu6050_working_interface_M->Timing.taskTime0 =
    (++gm_mpu6050_working_interface_M->Timing.clockTick0) *
    gm_mpu6050_working_interface_M->Timing.stepSize0;
}

/* Model initialize function */
void gm_mpu6050_working_interface_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)gm_mpu6050_working_interface_M, 0,
                sizeof(RT_MODEL_gm_mpu6050_working_i_T));
  rtmSetTFinal(gm_mpu6050_working_interface_M, -1);
  gm_mpu6050_working_interface_M->Timing.stepSize0 = 0.2;

  /* External mode info */
  gm_mpu6050_working_interface_M->Sizes.checksums[0] = (2525469790U);
  gm_mpu6050_working_interface_M->Sizes.checksums[1] = (1758073227U);
  gm_mpu6050_working_interface_M->Sizes.checksums[2] = (381188171U);
  gm_mpu6050_working_interface_M->Sizes.checksums[3] = (2149187991U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[17];
    gm_mpu6050_working_interface_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(gm_mpu6050_working_interface_M->extModeInfo,
      &gm_mpu6050_working_interface_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(gm_mpu6050_working_interface_M->extModeInfo,
                        gm_mpu6050_working_interface_M->Sizes.checksums);
    rteiSetTPtr(gm_mpu6050_working_interface_M->extModeInfo, rtmGetTPtr
                (gm_mpu6050_working_interface_M));
  }

  /* block I/O */
  (void) memset(((void *) &gm_mpu6050_working_interface_B), 0,
                sizeof(B_gm_mpu6050_working_interfac_T));

  /* states (dwork) */
  (void) memset((void *)&gm_mpu6050_working_interface_DW, 0,
                sizeof(DW_gm_mpu6050_working_interfa_T));

  /* external outputs */
  (void) memset((void *)&gm_mpu6050_working_interface_Y, 0,
                sizeof(ExtY_gm_mpu6050_working_inter_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    gm_mpu6050_working_interface_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    AXI4_struct * p_state;
    static const char_T tmp[14] = { '/', 'd', 'e', 'v', '/', 'm', 'w', 'i', 'p',
      'c', 'o', 'r', 'e', '\x00' };

    char_T tmp_0[14];
    int32_T i;

    {
      /* user code (Start function Header) */

      /* System '<Root>/I2C_MPU6050_IP' */
      AXI4LITE_RESET_IPCORE("/dev/mwipcore");

      /* Start for Atomic SubSystem: '<Root>/I2C_MPU6050_IP' */

      /* Start for MATLABSystem: '<S25>/AXI4-Interface Write' */
      gm_mpu6050_working_interface_DW.obj_k.isInitialized = 0;
      gm_mpu6050_working_interface_DW.obj_k.isInitialized = 1;
      gm_mpu6050_working_interface_DW.obj_k.DeviceState = 0U;
      for (i = 0; i < 14; i++) {
        tmp_0[i] = tmp[i];
      }

      p_state = AXI4LITE_INIT(tmp_0);
      gm_mpu6050_working_interface_DW.obj_k.DeviceState = (uint32_T)p_state;

      /* End of Start for MATLABSystem: '<S25>/AXI4-Interface Write' */

      /* Start for MATLABSystem: '<S24>/AXI4-Interface Write' */
      gm_mpu6050_working_interface_DW.obj_p.isInitialized = 0;
      gm_mpu6050_working_interface_DW.obj_p.isInitialized = 1;
      gm_mpu6050_working_interface_DW.obj_p.DeviceState = 0U;
      for (i = 0; i < 14; i++) {
        tmp_0[i] = tmp[i];
      }

      p_state = AXI4LITE_INIT(tmp_0);
      gm_mpu6050_working_interface_DW.obj_p.DeviceState = (uint32_T)p_state;

      /* End of Start for MATLABSystem: '<S24>/AXI4-Interface Write' */

      /* Start for MATLABSystem: '<S14>/AXI4-Interface Read' */
      gm_mpu6050_working_interface_DW.obj_o0.isInitialized = 0;
      gm_mpu6050_working_interface_DW.obj_o0.isInitialized = 1;
      gm_mpu6050_working_interface_DW.obj_o0.DeviceState = 0U;
      for (i = 0; i < 14; i++) {
        tmp_0[i] = tmp[i];
      }

      p_state = AXI4LITE_INIT(tmp_0);
      gm_mpu6050_working_interface_DW.obj_o0.DeviceState = (uint32_T)p_state;

      /* End of Start for MATLABSystem: '<S14>/AXI4-Interface Read' */

      /* Start for MATLABSystem: '<S15>/AXI4-Interface Read' */
      gm_mpu6050_working_interface_DW.obj_b.isInitialized = 0;
      gm_mpu6050_working_interface_DW.obj_b.isInitialized = 1;
      gm_mpu6050_working_interface_DW.obj_b.DeviceState = 0U;
      for (i = 0; i < 14; i++) {
        tmp_0[i] = tmp[i];
      }

      p_state = AXI4LITE_INIT(tmp_0);
      gm_mpu6050_working_interface_DW.obj_b.DeviceState = (uint32_T)p_state;

      /* End of Start for MATLABSystem: '<S15>/AXI4-Interface Read' */

      /* Start for MATLABSystem: '<S16>/AXI4-Interface Read' */
      gm_mpu6050_working_interface_DW.obj_n.isInitialized = 0;
      gm_mpu6050_working_interface_DW.obj_n.isInitialized = 1;
      gm_mpu6050_working_interface_DW.obj_n.DeviceState = 0U;
      for (i = 0; i < 14; i++) {
        tmp_0[i] = tmp[i];
      }

      p_state = AXI4LITE_INIT(tmp_0);
      gm_mpu6050_working_interface_DW.obj_n.DeviceState = (uint32_T)p_state;

      /* End of Start for MATLABSystem: '<S16>/AXI4-Interface Read' */

      /* Start for MATLABSystem: '<S23>/AXI4-Interface Read' */
      gm_mpu6050_working_interface_DW.obj.isInitialized = 0;
      gm_mpu6050_working_interface_DW.obj.isInitialized = 1;
      gm_mpu6050_working_interface_DW.obj.DeviceState = 0U;
      for (i = 0; i < 14; i++) {
        tmp_0[i] = tmp[i];
      }

      p_state = AXI4LITE_INIT(tmp_0);
      gm_mpu6050_working_interface_DW.obj.DeviceState = (uint32_T)p_state;

      /* End of Start for MATLABSystem: '<S23>/AXI4-Interface Read' */

      /* Start for MATLABSystem: '<S21>/AXI4-Interface Read' */
      gm_mpu6050_working_interface_DW.obj_a.isInitialized = 0;
      gm_mpu6050_working_interface_DW.obj_a.isInitialized = 1;
      gm_mpu6050_working_interface_DW.obj_a.DeviceState = 0U;
      for (i = 0; i < 14; i++) {
        tmp_0[i] = tmp[i];
      }

      p_state = AXI4LITE_INIT(tmp_0);
      gm_mpu6050_working_interface_DW.obj_a.DeviceState = (uint32_T)p_state;

      /* End of Start for MATLABSystem: '<S21>/AXI4-Interface Read' */

      /* Start for MATLABSystem: '<S20>/AXI4-Interface Read' */
      gm_mpu6050_working_interface_DW.obj_o.isInitialized = 0;
      gm_mpu6050_working_interface_DW.obj_o.isInitialized = 1;
      gm_mpu6050_working_interface_DW.obj_o.DeviceState = 0U;
      for (i = 0; i < 14; i++) {
        tmp_0[i] = tmp[i];
      }

      p_state = AXI4LITE_INIT(tmp_0);
      gm_mpu6050_working_interface_DW.obj_o.DeviceState = (uint32_T)p_state;

      /* End of Start for MATLABSystem: '<S20>/AXI4-Interface Read' */

      /* Start for MATLABSystem: '<S17>/AXI4-Interface Read' */
      gm_mpu6050_working_interface_DW.obj_j.isInitialized = 0;
      gm_mpu6050_working_interface_DW.obj_j.isInitialized = 1;
      gm_mpu6050_working_interface_DW.obj_j.DeviceState = 0U;
      for (i = 0; i < 14; i++) {
        tmp_0[i] = tmp[i];
      }

      p_state = AXI4LITE_INIT(tmp_0);
      gm_mpu6050_working_interface_DW.obj_j.DeviceState = (uint32_T)p_state;

      /* End of Start for MATLABSystem: '<S17>/AXI4-Interface Read' */

      /* Start for MATLABSystem: '<S18>/AXI4-Interface Read' */
      gm_mpu6050_working_interface_DW.obj_av.isInitialized = 0;
      gm_mpu6050_working_interface_DW.obj_av.isInitialized = 1;
      gm_mpu6050_working_interface_DW.obj_av.DeviceState = 0U;
      for (i = 0; i < 14; i++) {
        tmp_0[i] = tmp[i];
      }

      p_state = AXI4LITE_INIT(tmp_0);
      gm_mpu6050_working_interface_DW.obj_av.DeviceState = (uint32_T)p_state;

      /* End of Start for MATLABSystem: '<S18>/AXI4-Interface Read' */

      /* Start for MATLABSystem: '<S19>/AXI4-Interface Read' */
      gm_mpu6050_working_interface_DW.obj_i.isInitialized = 0;
      gm_mpu6050_working_interface_DW.obj_i.isInitialized = 1;
      gm_mpu6050_working_interface_DW.obj_i.DeviceState = 0U;
      for (i = 0; i < 14; i++) {
        tmp_0[i] = tmp[i];
      }

      p_state = AXI4LITE_INIT(tmp_0);
      gm_mpu6050_working_interface_DW.obj_i.DeviceState = (uint32_T)p_state;

      /* End of Start for MATLABSystem: '<S19>/AXI4-Interface Read' */

      /* Start for MATLABSystem: '<S22>/AXI4-Interface Read' */
      gm_mpu6050_working_interface_DW.obj_f.isInitialized = 0;
      gm_mpu6050_working_interface_DW.obj_f.isInitialized = 1;
      gm_mpu6050_working_interface_DW.obj_f.DeviceState = 0U;
      for (i = 0; i < 14; i++) {
        tmp_0[i] = tmp[i];
      }

      p_state = AXI4LITE_INIT(tmp_0);
      gm_mpu6050_working_interface_DW.obj_f.DeviceState = (uint32_T)p_state;

      /* End of Start for MATLABSystem: '<S22>/AXI4-Interface Read' */

      /* End of Start for SubSystem: '<Root>/I2C_MPU6050_IP' */
    }

    /* InitializeConditions for UnitDelay: '<S1>/Unit Delay3' */
    gm_mpu6050_working_interface_DW.UnitDelay3_DSTATE =
      gm_mpu6050_working_interface_P.UnitDelay3_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S2>/Unit Delay3' */
    gm_mpu6050_working_interface_DW.UnitDelay3_DSTATE_i =
      gm_mpu6050_working_interface_P.UnitDelay3_InitialCondition_c;

    /* InitializeConditions for UnitDelay: '<S3>/Unit Delay3' */
    gm_mpu6050_working_interface_DW.UnitDelay3_DSTATE_m =
      gm_mpu6050_working_interface_P.UnitDelay3_InitialCondition_g;
  }
}

/* Model terminate function */
void gm_mpu6050_working_interface_terminate(void)
{
  AXI4_struct * p_state;

  /* Terminate for Atomic SubSystem: '<Root>/I2C_MPU6050_IP' */

  /* Start for MATLABSystem: '<S25>/AXI4-Interface Write' incorporates:
   *  Terminate for MATLABSystem: '<S25>/AXI4-Interface Write'
   */
  if (gm_mpu6050_working_interface_DW.obj_k.isInitialized == 1) {
    gm_mpu6050_working_interface_DW.obj_k.isInitialized = 2;
    p_state = (AXI4_struct *)(gm_mpu6050_working_interface_DW.obj_k.DeviceState);
    AXI4LITE_TERMINATE(p_state);
  }

  /* End of Start for MATLABSystem: '<S25>/AXI4-Interface Write' */

  /* Start for MATLABSystem: '<S24>/AXI4-Interface Write' incorporates:
   *  Terminate for MATLABSystem: '<S24>/AXI4-Interface Write'
   */
  if (gm_mpu6050_working_interface_DW.obj_p.isInitialized == 1) {
    gm_mpu6050_working_interface_DW.obj_p.isInitialized = 2;
    p_state = (AXI4_struct *)(gm_mpu6050_working_interface_DW.obj_p.DeviceState);
    AXI4LITE_TERMINATE(p_state);
  }

  /* End of Start for MATLABSystem: '<S24>/AXI4-Interface Write' */

  /* Start for MATLABSystem: '<S14>/AXI4-Interface Read' incorporates:
   *  Terminate for MATLABSystem: '<S14>/AXI4-Interface Read'
   */
  if (gm_mpu6050_working_interface_DW.obj_o0.isInitialized == 1) {
    gm_mpu6050_working_interface_DW.obj_o0.isInitialized = 2;
    p_state = (AXI4_struct *)(gm_mpu6050_working_interface_DW.obj_o0.DeviceState);
    AXI4LITE_TERMINATE(p_state);
  }

  /* End of Start for MATLABSystem: '<S14>/AXI4-Interface Read' */

  /* Start for MATLABSystem: '<S15>/AXI4-Interface Read' incorporates:
   *  Terminate for MATLABSystem: '<S15>/AXI4-Interface Read'
   */
  if (gm_mpu6050_working_interface_DW.obj_b.isInitialized == 1) {
    gm_mpu6050_working_interface_DW.obj_b.isInitialized = 2;
    p_state = (AXI4_struct *)(gm_mpu6050_working_interface_DW.obj_b.DeviceState);
    AXI4LITE_TERMINATE(p_state);
  }

  /* End of Start for MATLABSystem: '<S15>/AXI4-Interface Read' */

  /* Start for MATLABSystem: '<S16>/AXI4-Interface Read' incorporates:
   *  Terminate for MATLABSystem: '<S16>/AXI4-Interface Read'
   */
  if (gm_mpu6050_working_interface_DW.obj_n.isInitialized == 1) {
    gm_mpu6050_working_interface_DW.obj_n.isInitialized = 2;
    p_state = (AXI4_struct *)(gm_mpu6050_working_interface_DW.obj_n.DeviceState);
    AXI4LITE_TERMINATE(p_state);
  }

  /* End of Start for MATLABSystem: '<S16>/AXI4-Interface Read' */

  /* Start for MATLABSystem: '<S23>/AXI4-Interface Read' incorporates:
   *  Terminate for MATLABSystem: '<S23>/AXI4-Interface Read'
   */
  if (gm_mpu6050_working_interface_DW.obj.isInitialized == 1) {
    gm_mpu6050_working_interface_DW.obj.isInitialized = 2;
    p_state = (AXI4_struct *)(gm_mpu6050_working_interface_DW.obj.DeviceState);
    AXI4LITE_TERMINATE(p_state);
  }

  /* End of Start for MATLABSystem: '<S23>/AXI4-Interface Read' */

  /* Start for MATLABSystem: '<S21>/AXI4-Interface Read' incorporates:
   *  Terminate for MATLABSystem: '<S21>/AXI4-Interface Read'
   */
  if (gm_mpu6050_working_interface_DW.obj_a.isInitialized == 1) {
    gm_mpu6050_working_interface_DW.obj_a.isInitialized = 2;
    p_state = (AXI4_struct *)(gm_mpu6050_working_interface_DW.obj_a.DeviceState);
    AXI4LITE_TERMINATE(p_state);
  }

  /* End of Start for MATLABSystem: '<S21>/AXI4-Interface Read' */

  /* Start for MATLABSystem: '<S20>/AXI4-Interface Read' incorporates:
   *  Terminate for MATLABSystem: '<S20>/AXI4-Interface Read'
   */
  if (gm_mpu6050_working_interface_DW.obj_o.isInitialized == 1) {
    gm_mpu6050_working_interface_DW.obj_o.isInitialized = 2;
    p_state = (AXI4_struct *)(gm_mpu6050_working_interface_DW.obj_o.DeviceState);
    AXI4LITE_TERMINATE(p_state);
  }

  /* End of Start for MATLABSystem: '<S20>/AXI4-Interface Read' */

  /* Start for MATLABSystem: '<S17>/AXI4-Interface Read' incorporates:
   *  Terminate for MATLABSystem: '<S17>/AXI4-Interface Read'
   */
  if (gm_mpu6050_working_interface_DW.obj_j.isInitialized == 1) {
    gm_mpu6050_working_interface_DW.obj_j.isInitialized = 2;
    p_state = (AXI4_struct *)(gm_mpu6050_working_interface_DW.obj_j.DeviceState);
    AXI4LITE_TERMINATE(p_state);
  }

  /* End of Start for MATLABSystem: '<S17>/AXI4-Interface Read' */

  /* Start for MATLABSystem: '<S18>/AXI4-Interface Read' incorporates:
   *  Terminate for MATLABSystem: '<S18>/AXI4-Interface Read'
   */
  if (gm_mpu6050_working_interface_DW.obj_av.isInitialized == 1) {
    gm_mpu6050_working_interface_DW.obj_av.isInitialized = 2;
    p_state = (AXI4_struct *)(gm_mpu6050_working_interface_DW.obj_av.DeviceState);
    AXI4LITE_TERMINATE(p_state);
  }

  /* End of Start for MATLABSystem: '<S18>/AXI4-Interface Read' */

  /* Start for MATLABSystem: '<S19>/AXI4-Interface Read' incorporates:
   *  Terminate for MATLABSystem: '<S19>/AXI4-Interface Read'
   */
  if (gm_mpu6050_working_interface_DW.obj_i.isInitialized == 1) {
    gm_mpu6050_working_interface_DW.obj_i.isInitialized = 2;
    p_state = (AXI4_struct *)(gm_mpu6050_working_interface_DW.obj_i.DeviceState);
    AXI4LITE_TERMINATE(p_state);
  }

  /* End of Start for MATLABSystem: '<S19>/AXI4-Interface Read' */

  /* Start for MATLABSystem: '<S22>/AXI4-Interface Read' incorporates:
   *  Terminate for MATLABSystem: '<S22>/AXI4-Interface Read'
   */
  if (gm_mpu6050_working_interface_DW.obj_f.isInitialized == 1) {
    gm_mpu6050_working_interface_DW.obj_f.isInitialized = 2;
    p_state = (AXI4_struct *)(gm_mpu6050_working_interface_DW.obj_f.DeviceState);
    AXI4LITE_TERMINATE(p_state);
  }

  /* End of Start for MATLABSystem: '<S22>/AXI4-Interface Read' */

  /* End of Terminate for SubSystem: '<Root>/I2C_MPU6050_IP' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
