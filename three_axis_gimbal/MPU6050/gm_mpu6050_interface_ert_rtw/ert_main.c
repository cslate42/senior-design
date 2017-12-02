/*
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'gm_mpu6050_interface'.
 *
 * Model version                  : 1.170
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Thu Nov 30 12:20:20 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include <stdio.h>
#include <stdlib.h>
#include "gm_mpu6050_interface.h"
#include "gm_mpu6050_interface_private.h"
#include "rtwtypes.h"
#include "limits.h"
#include "linuxinitialize.h"
#define UNUSED(x)                      x = x

/* Function prototype declaration*/
void exitFcn(int sig);
void *terminateTask(void *arg);
void *baseRateTask(void *arg);
void *subrateTask(void *arg);
volatile boolean_T runModel = true;
sem_t stopSem;
sem_t baserateTaskSem;
pthread_t schedulerThread;
pthread_t baseRateThread;
unsigned long threadJoinStatus[8];
int terminatingmodel = 0;
void *baseRateTask(void *arg)
{
  runModel = (rtmGetErrorStatus(gm_mpu6050_interface_M) == (NULL));
  while (runModel) {
    sem_wait(&baserateTaskSem);
    gm_mpu6050_interface_step();

    /* Get model outputs here */
    runModel = (rtmGetErrorStatus(gm_mpu6050_interface_M) == (NULL));
  }

  runModel = 0;
  terminateTask(arg);
  pthread_exit((void *)0);
  return NULL;
}

void exitFcn(int sig)
{
  UNUSED(sig);
  rtmSetErrorStatus(gm_mpu6050_interface_M, "stopping the model");
}

void *terminateTask(void *arg)
{
  UNUSED(arg);
  terminatingmodel = 1;

  {
    runModel = 0;
  }

  /* Disable rt_OneStep() here */

  /* Terminate model */
  gm_mpu6050_interface_terminate();
  sem_post(&stopSem);
  return NULL;
}

int main(int argc, char **argv)
{
  UNUSED(argc);
  UNUSED(argv);
  rtmSetErrorStatus(gm_mpu6050_interface_M, 0);

  /* Initialize model */
  gm_mpu6050_interface_initialize();

  /* Call RTOS Initialization function */
  myRTOSInit(0.2, 0);

  /* Wait for stop semaphore */
  sem_wait(&stopSem);
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
