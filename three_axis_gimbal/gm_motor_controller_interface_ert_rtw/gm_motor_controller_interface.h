/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * File: gm_motor_controller_interface.h
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

#ifndef RTW_HEADER_gm_motor_controller_interface_h_
#define RTW_HEADER_gm_motor_controller_interface_h_
#include <stddef.h>
#ifndef gm_motor_controller_interface_COMMON_INCLUDES_
# define gm_motor_controller_interface_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* gm_motor_controller_interface_COMMON_INCLUDES_ */

#include "gm_motor_controller_interface_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#define gm_motor_controller_interface_M (gm_motor_controller_interfac_M)

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  boolean_T PWM;                       /* '<Root>/PWM' */
} ExtY_gm_motor_controller_inte_T;

/* Real-time Model Data Structure */
struct tag_RTM_gm_motor_controller_i_T {
  const char_T *errorStatus;
};

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_gm_motor_controller_inte_T gm_motor_controller_interface_Y;

/* Model entry point functions */
extern void gm_motor_controller_interface_initialize(void);
extern void gm_motor_controller_interface_step(void);
extern void gm_motor_controller_interface_terminate(void);

/* Real-time Model object */
extern RT_MODEL_gm_motor_controller__T *const gm_motor_controller_interfac_M;

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
 * '<Root>' : 'gm_motor_controller_interface'
 * '<S1>'   : 'gm_motor_controller_interface/motor_controller'
 * '<S2>'   : 'gm_motor_controller_interface/motor_controller/AXI4LiteRead'
 */
#endif                                 /* RTW_HEADER_gm_motor_controller_interface_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
