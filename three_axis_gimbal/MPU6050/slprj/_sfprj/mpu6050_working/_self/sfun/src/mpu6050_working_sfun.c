/* Include files */

#include "mpu6050_working_sfun.h"
#include "mpu6050_working_sfun_debug_macros.h"
#include "c1_mpu6050_working.h"
#include "c2_mpu6050_working.h"
#include "c4_mpu6050_working.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _mpu6050_workingMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void mpu6050_working_initializer(void)
{
}

void mpu6050_working_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_mpu6050_working_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_mpu6050_working_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_mpu6050_working_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_mpu6050_working_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_mpu6050_working_process_testpoint_info_call( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char machineName[128];
  if (nrhs < 3 || !mxIsChar(prhs[0]) || !mxIsChar(prhs[1]))
    return 0;

  /* Possible call to get testpoint info. */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_testpoint_info"))
    return 0;
  mxGetString(prhs[1], machineName, sizeof(machineName)/sizeof(char));
  machineName[(sizeof(machineName)/sizeof(char)-1)] = '\0';
  if (!strcmp(machineName, "mpu6050_working")) {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
    switch (chartFileNumber) {
     case 1:
      {
        extern mxArray *sf_c1_mpu6050_working_get_testpoint_info(void);
        plhs[0] = sf_c1_mpu6050_working_get_testpoint_info();
        break;
      }

     case 2:
      {
        extern mxArray *sf_c2_mpu6050_working_get_testpoint_info(void);
        plhs[0] = sf_c2_mpu6050_working_get_testpoint_info();
        break;
      }

     case 4:
      {
        extern mxArray *sf_c4_mpu6050_working_get_testpoint_info(void);
        plhs[0] = sf_c4_mpu6050_working_get_testpoint_info();
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }

    return 1;
  }

  return 0;

#else

  return 0;

#endif

}

unsigned int sf_mpu6050_working_process_check_sum_call( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3872436303U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4255406447U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(386277651U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2794893875U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_mpu6050_working_get_check_sum(mxArray *plhs[]);
          sf_c1_mpu6050_working_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_mpu6050_working_get_check_sum(mxArray *plhs[]);
          sf_c2_mpu6050_working_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_mpu6050_working_get_check_sum(mxArray *plhs[]);
          sf_c4_mpu6050_working_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2705292628U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1815037026U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(902551036U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(350327927U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4000733878U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(791366385U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2113454332U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3144969262U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_mpu6050_working_autoinheritance_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "dAdxTL31PQVQ8SczbKMuRD") == 0) {
          extern mxArray *sf_c1_mpu6050_working_get_autoinheritance_info(void);
          plhs[0] = sf_c1_mpu6050_working_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "2TP1HyoU37MbJN8wzR0rCF") == 0) {
          extern mxArray *sf_c2_mpu6050_working_get_autoinheritance_info(void);
          plhs[0] = sf_c2_mpu6050_working_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "ajrkRtU7nUMEe2oUO8MAjG") == 0) {
          extern mxArray *sf_c4_mpu6050_working_get_autoinheritance_info(void);
          plhs[0] = sf_c4_mpu6050_working_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_mpu6050_working_get_eml_resolved_functions_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray
          *sf_c1_mpu6050_working_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_mpu6050_working_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_mpu6050_working_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_mpu6050_working_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_mpu6050_working_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_mpu6050_working_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_mpu6050_working_third_party_uses_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "sL7Kzb2O2xbfDBFrf91LzmG") == 0) {
          extern mxArray *sf_c1_mpu6050_working_third_party_uses_info(void);
          plhs[0] = sf_c1_mpu6050_working_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "skYyxnfK5pXpkOdtBIu4MSF") == 0) {
          extern mxArray *sf_c2_mpu6050_working_third_party_uses_info(void);
          plhs[0] = sf_c2_mpu6050_working_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "saF3GFwSNSFegVrf4WyxUhH") == 0) {
          extern mxArray *sf_c4_mpu6050_working_third_party_uses_info(void);
          plhs[0] = sf_c4_mpu6050_working_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_mpu6050_working_jit_fallback_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the jit_fallback_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_jit_fallback_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "sL7Kzb2O2xbfDBFrf91LzmG") == 0) {
          extern mxArray *sf_c1_mpu6050_working_jit_fallback_info(void);
          plhs[0] = sf_c1_mpu6050_working_jit_fallback_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "skYyxnfK5pXpkOdtBIu4MSF") == 0) {
          extern mxArray *sf_c2_mpu6050_working_jit_fallback_info(void);
          plhs[0] = sf_c2_mpu6050_working_jit_fallback_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "saF3GFwSNSFegVrf4WyxUhH") == 0) {
          extern mxArray *sf_c4_mpu6050_working_jit_fallback_info(void);
          plhs[0] = sf_c4_mpu6050_working_jit_fallback_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_mpu6050_working_updateBuildInfo_args_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the updateBuildInfo_args_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "sL7Kzb2O2xbfDBFrf91LzmG") == 0) {
          extern mxArray *sf_c1_mpu6050_working_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_mpu6050_working_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "skYyxnfK5pXpkOdtBIu4MSF") == 0) {
          extern mxArray *sf_c2_mpu6050_working_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_mpu6050_working_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "saF3GFwSNSFegVrf4WyxUhH") == 0) {
          extern mxArray *sf_c4_mpu6050_working_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_mpu6050_working_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void mpu6050_working_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _mpu6050_workingMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "mpu6050_working","sfun",0,6,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _mpu6050_workingMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _mpu6050_workingMachineNumber_,0);
}

void mpu6050_working_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
typedef struct SfOptimizationInfoFlagsTag {
  boolean_T isRtwGen;
  boolean_T isModelRef;
  boolean_T isExternal;
} SfOptimizationInfoFlags;

static SfOptimizationInfoFlags sOptimizationInfoFlags;
void unload_mpu6050_working_optimization_info(void);
mxArray* load_mpu6050_working_optimization_info(boolean_T isRtwGen, boolean_T
  isModelRef, boolean_T isExternal)
{
  if (sOptimizationInfoFlags.isRtwGen != isRtwGen ||
      sOptimizationInfoFlags.isModelRef != isModelRef ||
      sOptimizationInfoFlags.isExternal != isExternal) {
    unload_mpu6050_working_optimization_info();
  }

  sOptimizationInfoFlags.isRtwGen = isRtwGen;
  sOptimizationInfoFlags.isModelRef = isModelRef;
  sOptimizationInfoFlags.isExternal = isExternal;
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("mpu6050_working",
      "mpu6050_working");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_mpu6050_working_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
