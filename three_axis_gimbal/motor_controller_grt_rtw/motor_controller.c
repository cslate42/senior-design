/*
 * motor_controller.c
 *
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * Code generation for model "motor_controller".
 *
 * Model version              : 1.24
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Tue Nov 07 15:34:50 2017
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ASIC/FPGA->ASIC/FPGA
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "motor_controller.h"
#include "motor_controller_private.h"

/* Named constants for Chart: '<S2>/Chart' */
#define motor_controller_IN_off        ((uint8_T)1U)
#define motor_controller_IN_on         ((uint8_T)2U)

/* Block states (auto storage) */
DW_motor_controller_T motor_controller_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_motor_controller_T motor_controller_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_motor_controller_T motor_controller_Y;

/* Real-time model */
RT_MODEL_motor_controller_T motor_controller_M_;
RT_MODEL_motor_controller_T *const motor_controller_M = &motor_controller_M_;
void mul_wide_u32(uint32_T in0, uint32_T in1, uint32_T *ptrOutBitsHi, uint32_T
                  *ptrOutBitsLo)
{
  uint32_T outBitsLo;
  uint32_T in0Lo;
  uint32_T in0Hi;
  uint32_T in1Lo;
  uint32_T in1Hi;
  uint32_T productHiLo;
  uint32_T productLoHi;
  in0Hi = in0 >> 16U;
  in0Lo = in0 & 65535U;
  in1Hi = in1 >> 16U;
  in1Lo = in1 & 65535U;
  productHiLo = in0Hi * in1Lo;
  productLoHi = in0Lo * in1Hi;
  in0Lo *= in1Lo;
  in1Lo = 0U;
  outBitsLo = (productLoHi << 16U) + in0Lo;
  if (outBitsLo < in0Lo) {
    in1Lo = 1U;
  }

  in0Lo = outBitsLo;
  outBitsLo += productHiLo << 16U;
  if (outBitsLo < in0Lo) {
    in1Lo++;
  }

  *ptrOutBitsHi = (((productLoHi >> 16U) + (productHiLo >> 16U)) + in0Hi * in1Hi)
    + in1Lo;
  *ptrOutBitsLo = outBitsLo;
}

uint32_T mul_u32_loSR(uint32_T a, uint32_T b, uint32_T aShift)
{
  uint32_T result;
  uint32_T u32_chi;
  mul_wide_u32(a, b, &u32_chi, &result);
  return u32_chi << (32U - aShift) | result >> aShift;
}

/* Model step function */
void motor_controller_step(void)
{
  uint32_T qY;

  /* Chart: '<S2>/Chart' incorporates:
   *  Constant: '<S2>/ESCPeriod'
   *  Gain: '<S2>/Gain'
   *  Inport: '<Root>/freq'
   */
  /* Gateway: Subsystem/Motor Controller/Chart */
  /* During: Subsystem/Motor Controller/Chart */
  if (motor_controller_DW.is_c1_motor_controller == motor_controller_IN_off) {
    /* Outport: '<Root>/PWM' */
    motor_controller_Y.PWM = false;

    /* During 'off': '<S3>:3' */
    if (motor_controller_DW.cnt >= 125000U) {
      /* Transition: '<S3>:5' */
      motor_controller_DW.is_c1_motor_controller = motor_controller_IN_on;

      /* Entry 'on': '<S3>:1' */
      motor_controller_DW.cnt = 0U;

      /* Outport: '<Root>/PWM' */
      motor_controller_Y.PWM = true;
    } else {
      qY = motor_controller_DW.cnt + 1U;
      if (qY < motor_controller_DW.cnt) {
        qY = MAX_uint32_T;
      }

      motor_controller_DW.cnt = qY;
    }
  } else {
    /* Outport: '<Root>/PWM' */
    motor_controller_Y.PWM = true;

    /* During 'on': '<S3>:1' */
    if (motor_controller_DW.cnt > mul_u32_loSR(3355443200U,
         motor_controller_U.freq, 26U)) {
      /* Transition: '<S3>:4' */
      motor_controller_DW.is_c1_motor_controller = motor_controller_IN_off;

      /* Outport: '<Root>/PWM' */
      /* Entry 'off': '<S3>:3' */
      motor_controller_Y.PWM = false;
    } else {
      qY = motor_controller_DW.cnt + 1U;
      if (qY < motor_controller_DW.cnt) {
        qY = MAX_uint32_T;
      }

      motor_controller_DW.cnt = qY;
    }
  }

  /* End of Chart: '<S2>/Chart' */

  /* Matfile logging */
  rt_UpdateTXYLogVars(motor_controller_M->rtwLogInfo,
                      (&motor_controller_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.2s, 0.0s] */
    if ((rtmGetTFinal(motor_controller_M)!=-1) &&
        !((rtmGetTFinal(motor_controller_M)-motor_controller_M->Timing.taskTime0)
          > motor_controller_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(motor_controller_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++motor_controller_M->Timing.clockTick0)) {
    ++motor_controller_M->Timing.clockTickH0;
  }

  motor_controller_M->Timing.taskTime0 = motor_controller_M->Timing.clockTick0 *
    motor_controller_M->Timing.stepSize0 +
    motor_controller_M->Timing.clockTickH0 *
    motor_controller_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void motor_controller_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)motor_controller_M, 0,
                sizeof(RT_MODEL_motor_controller_T));
  rtmSetTFinal(motor_controller_M, 10.0);
  motor_controller_M->Timing.stepSize0 = 0.2;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    motor_controller_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(motor_controller_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(motor_controller_M->rtwLogInfo, (NULL));
    rtliSetLogT(motor_controller_M->rtwLogInfo, "");
    rtliSetLogX(motor_controller_M->rtwLogInfo, "");
    rtliSetLogXFinal(motor_controller_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(motor_controller_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(motor_controller_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(motor_controller_M->rtwLogInfo, 0);
    rtliSetLogDecimation(motor_controller_M->rtwLogInfo, 1);
    rtliSetLogY(motor_controller_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(motor_controller_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(motor_controller_M->rtwLogInfo, (NULL));
  }

  /* states (dwork) */
  (void) memset((void *)&motor_controller_DW, 0,
                sizeof(DW_motor_controller_T));

  /* external inputs */
  motor_controller_U.freq = 0U;

  /* external outputs */
  motor_controller_Y.PWM = false;

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(motor_controller_M->rtwLogInfo, 0.0,
    rtmGetTFinal(motor_controller_M), motor_controller_M->Timing.stepSize0,
    (&rtmGetErrorStatus(motor_controller_M)));

  /* SystemInitialize for Chart: '<S2>/Chart' */
  /* Entry: Subsystem/Motor Controller/Chart */
  /* Entry Internal: Subsystem/Motor Controller/Chart */
  /* Transition: '<S3>:16' */
  motor_controller_DW.is_c1_motor_controller = motor_controller_IN_on;

  /* Entry 'on': '<S3>:1' */
  motor_controller_DW.cnt = 0U;

  /* SystemInitialize for Outport: '<Root>/PWM' incorporates:
   *  SystemInitialize for Chart: '<S2>/Chart'
   */
  motor_controller_Y.PWM = true;
}

/* Model terminate function */
void motor_controller_terminate(void)
{
  /* (no terminate code required) */
}
