/*
 * motor_controller.h
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

#ifndef RTW_HEADER_motor_controller_h_
#define RTW_HEADER_motor_controller_h_
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef motor_controller_COMMON_INCLUDES_
# define motor_controller_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* motor_controller_COMMON_INCLUDES_ */

#include "motor_controller_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
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

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  uint32_T cnt;                        /* '<S2>/Chart' */
  uint8_T is_c1_motor_controller;      /* '<S2>/Chart' */
} DW_motor_controller_T;

/* Invariant block signals (auto storage) */
typedef struct {
  const real_T Constant;               /* '<Root>/Constant' */
} ConstB_motor_controller_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  uint32_T freq;                       /* '<Root>/freq' */
} ExtU_motor_controller_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  boolean_T PWM;                       /* '<Root>/PWM' */
} ExtY_motor_controller_T;

/* Real-time Model Data Structure */
struct tag_RTM_motor_controller_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block states (auto storage) */
extern DW_motor_controller_T motor_controller_DW;

/* External inputs (root inport signals with auto storage) */
extern ExtU_motor_controller_T motor_controller_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_motor_controller_T motor_controller_Y;
extern const ConstB_motor_controller_T motor_controller_ConstB;/* constant block i/o */

/* Model entry point functions */
extern void motor_controller_initialize(void);
extern void motor_controller_step(void);
extern void motor_controller_terminate(void);

/* Real-time Model object */
extern RT_MODEL_motor_controller_T *const motor_controller_M;

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
 * '<Root>' : 'motor_controller'
 * '<S1>'   : 'motor_controller/Subsystem'
 * '<S2>'   : 'motor_controller/Subsystem/Motor Controller'
 * '<S3>'   : 'motor_controller/Subsystem/Motor Controller/Chart'
 */
#endif                                 /* RTW_HEADER_motor_controller_h_ */
