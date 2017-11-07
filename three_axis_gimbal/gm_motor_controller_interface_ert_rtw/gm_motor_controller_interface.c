/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * File: gm_motor_controller_interface.c
 *
 * Code generated for Simulink model 'gm_motor_controller_interface'.
 *
 * Model version                  : 1.21
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Tue Nov 07 15:26:28 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "gm_motor_controller_interface.h"
#include "gm_motor_controller_interface_private.h"

/* user code (top of source file) */
/* System '<Root>/motor_controller' */
#include "axi_lct.h"

/* External outputs (root outports fed by signals with auto storage) */
ExtY_gm_motor_controller_inte_T gm_motor_controller_interface_Y;

/* Real-time model */
RT_MODEL_gm_motor_controller__T gm_motor_controller_interfac_M_;
RT_MODEL_gm_motor_controller__T *const gm_motor_controller_interfac_M =
  &gm_motor_controller_interfac_M_;

/* Model step function */
void gm_motor_controller_interface_step(void)
{
  /* Outport: '<Root>/PWM' */
  gm_motor_controller_interface_Y.PWM = false;
}

/* Model initialize function */
void gm_motor_controller_interface_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(gm_motor_controller_interfac_M, (NULL));

  /* external outputs */
  gm_motor_controller_interface_Y.PWM = false;

  {
    /* user code (Start function Header) */

    /* System '<Root>/motor_controller' */
    AXI4LITE_RESET_IPCORE("/dev/mwipcore");
  }
}

/* Model terminate function */
void gm_motor_controller_interface_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
