/*
 * Copyright 2004-2008 The MathWorks, Inc.
 *
 * File: rtw_capi_examples.c     
 *
 * Abstract:
 *   Provides utility functions to traverse and access RTW generated C-API
 *   structures. The C-API structure types are provided in following 2 files.
 *
 *       matlabroot/rtw/c/src/rtw_capi.h & rtw_modelmap.h
 *
 *   The actual data structures arrays are generated by code generator in 
 *   <MODEL>_capi.c, where <MODEL> is the name of the model.
 * 
 *   The functions provided in this file are
 *       capi_PrintModelParameter - Prints a model parameter value to STDOUT
 */

#include "rtw_capi_examples.h"
#include <stddef.h>

/* Function capi_PrintModelParameter ======================================= */
/* Abstract:
 *   This function takes in ModelMappingInfo structure prints the value of 
 *   ModelParameter - rtModelParameters[paramIdx] to STDOUT
 *     capiMap  - Pointer to the ModelMappingInfo structure in Real-Time model.
 *                Map of all C-API arrays and structures. 
 *     paramIdx - Index of the Parameter in the rtModelParameters array 
 *                generated by RTW in <MODEL>_capi.c
 */
void capi_PrintModelParameter(rtwCAPI_ModelMappingInfo* capiMap,
                              uint_T                    paramIdx) {
    
    const rtwCAPI_ModelParameters* modelParams;
    const rtwCAPI_DataTypeMap*     dataTypeMap;
    const rtwCAPI_DimensionMap*    dimMap;
    const rtwCAPI_FixPtMap*        fxpMap;
    const uint_T*                  dimArray;
    void**                         dataAddrMap;

    const char_T* paramName;
    uint_T        addrIdx;
    uint16_T      dataTypeIdx;
    uint16_T      dimIndex;
    uint16_T      fxpMapIdx;
    uint8_T       slDataID;

    void*                paramAddress;
    const char_T*        cDataName;
    unsigned short       isComplex;
    uint8_T              numDims;
    uint_T               dimArrayIdx;
    rtwCAPI_Orientation  orientation;
    uint_T*              actualDimensions;

    int    idx;
    real_T slope = 1.0;
    real_T bias  = 0.0;
    unsigned short modParamFlag = 0; 

    /* Assert the parameter index is less than total number of parameters */
    assert(paramIdx < rtwCAPI_GetNumModelParameters(capiMap));

    /* Get modelParams, an array of rtwCAPI_ModelParameters structure  */
    modelParams = rtwCAPI_GetModelParameters(capiMap);
    if (modelParams == NULL) return;
    
    /* Get Parameter Name */
    paramName   = rtwCAPI_GetModelParameterName(modelParams, paramIdx); 

    /* Get Data Type attributes of the Model Parameter                       */
    /* Accessing the data type information from capiMap is a 3 step process  *
     * 1) Get the dataTypeMap Array from capiMap.                            *
     * 2) Get the index into the above array, dataTypeIdx, from ModelParameter*
     *    structure. The index will point to a rtwCAPI_DataTypeMap structure.*
     * 3) From the structure, get the member values of the structure, namely *
     *       o Simulink Data ID, can be one of the enumerated value          *
     *           SS_DOUBLE, SS_SINGLE, SS_INT8, SS_UINT8, SS_INT16, SS_UINT16*
     *            , SS_INT32, SS_UINT32, SS_BOOLEAN                          *
     *       o Complexity                                                    *
     *       o Data Size                                                     *
     *    For complete structure see matlabroot/rtw/c/src/rtw_capi.h         */

    dataTypeMap = rtwCAPI_GetDataTypeMap(capiMap);
    if (dataTypeMap == NULL) return;
    
    dataTypeIdx = rtwCAPI_GetModelParameterDataTypeIdx(modelParams, paramIdx);
    slDataID    = rtwCAPI_GetDataTypeSLId(dataTypeMap, dataTypeIdx);
    cDataName   = rtwCAPI_GetDataTypeCName(dataTypeMap,dataTypeIdx);
    isComplex   = rtwCAPI_GetDataIsComplex(dataTypeMap,dataTypeIdx);

    /* Get Dimensions of the Model Parameter                                 */
    /* Accessing the dimension from capiMap is a 4 step process              *
     * 1) Get the dimMap array, an array of CAPI_DimensionMap struct         *
     * 2) Get the dimArray array, an array of all the dimensions in the Map  *
     * 3) Get the index into the dimMap array (dimIdx) from ModelParameter   *
     *    structure. the index will point to rtwCAPI_Dimension structure     *
     * 4) From the rtwCAPI_Dimension structure, get the following information*
     *       o orientation (scalar | vector | matrix)                        *
     *       o Number of dimensions (numDims)                                *
     *       o index into the dimArray (dimArrayIdx)                         *
     * 5) Using numDims and the dimArrayIdx, get the actual dimensions from  *
     *    the dimArray                                                       *
     *       uint_T ActualDims[numDims] = {dimArray[dimArrayIdx],            *
     *                                     dimArray[dimArrayIdx+1],          *
     *				       ...                                   *
     *				       dimArray[dimArrayIdx+(numDims-1)]}    *
     *    For e.g, scalar and 2-D parameters will have numDims = 2, So       *
     *       uint_T ActualDims[2] = {dimArray[dimArrayIdx],                  *
     *                               dimArray[dimArrayIdx +1]}               */
    
    dimMap   = rtwCAPI_GetDimensionMap(capiMap);
    dimArray = rtwCAPI_GetDimensionArray(capiMap);

    if ((dimMap == NULL) || (dimArray == NULL)) return;

    dimIndex    = rtwCAPI_GetModelParameterDimensionIdx(modelParams, paramIdx);
    numDims     = rtwCAPI_GetNumDims(dimMap, dimIndex); 
    dimArrayIdx = rtwCAPI_GetDimArrayIndex(dimMap, dimIndex);
    orientation = rtwCAPI_GetOrientation(dimMap, dimIndex);

    actualDimensions = (uint_T *) malloc(numDims*sizeof(uint_T));
    for(idx=0; idx < numDims; idx++) {
        actualDimensions[idx] = dimArray[dimArrayIdx + idx];
    }
    
    /* Get fixed-point information of the parameter */
    fxpMap = rtwCAPI_GetFixPtMap(capiMap);
    if (fxpMap == NULL) return;
    
    fxpMapIdx = rtwCAPI_GetModelParameterFixPtIdx(modelParams, paramIdx);
    if(fxpMapIdx > 0) {
        /* Only Fixed-point parameters have fxpMapIdx > 0 */
        real_T fracslope = rtwCAPI_GetFxpFracSlope(fxpMap,fxpMapIdx);
        int8_T expt      = rtwCAPI_GetFxpExponent(fxpMap,fxpMapIdx);
        
        /* slope = fractional slope * 2^exponent 
         * fractional slope is also called Slope Adjustment Factor. 
         * Type "help fixdt" in MATLAB command window for more information
         * on fixed point data types  
         */
        
        slope = fracslope*pow(2.0,expt);
        bias  = rtwCAPI_GetFxpBias(fxpMap,fxpMapIdx);
    }

    /* Get the address to this parameter                                     */
    dataAddrMap = rtwCAPI_GetDataAddressMap(capiMap);
    addrIdx     = rtwCAPI_GetModelParameterAddrIdx(modelParams,paramIdx);
    paramAddress= (void *) rtwCAPI_GetDataAddress(dataAddrMap,addrIdx); 

    if (paramAddress == NULL) return;
    
    /* Print the parameter value */
    capi_PrintParameter(paramName, paramAddress, slDataID, isComplex,
                        actualDimensions, numDims, slope, bias);

    /* Modify parameter with itself */
    /* modParamflag is used as a flag to indicate whether you want to modify
     * the parameter after you print the value. Set flag to 1 to modify    */
    
    if(modParamFlag &&
       capi_ModifyParameter(paramAddress, paramAddress, orientation,
                            actualDimensions, numDims, slDataID, isComplex)) {
                                printf("Parameter modified with itself\n");
                            }
    free(actualDimensions);
    return;
}

/* Function capi_PrintParameter ============================================
 * Abstract: 
 *   Prints the name and value of the parameter.
 *   Scalar, Vector and matrix parameters are supported. 
 *   N-Dimensional paramaters, where N > 2, are not supported.
 *
 * Note: The printing format assumes that the parameter is COLUMN-MAJOR  
 *       indexing.
 */
void capi_PrintParameter(const char_T*  paramName,
                         void*          paramAddress,
                         uint8_T        slDataID,
                         unsigned short isComplex,
                         uint_T*        actualDims,
                         uint_T         numDims,
                         real_T         slope,
                         real_T         bias) {

    uint_T numRows  = actualDims[0];
    uint_T numCols  = actualDims[1];
    uint_T numPages = 0;
    int rowIdx;
    int colIdx;
    int pageIdx;
    if (numDims == 3) numPages = actualDims[2];

        
    printf("%s = \n", paramName);
    switch(slDataID) {
      case SS_DOUBLE :
        if (isComplex) {
            /* If is Complex and SS_DOUBLE, the data is of type creal_T */
            creal_T* paramVal = (creal_T *) paramAddress;
            for(rowIdx = 0; rowIdx < numRows; rowIdx++) {
                for(colIdx = 0; colIdx < numCols; colIdx++) {
                    printf("\t%.4g + %.4g*i", 
                           paramVal[colIdx*numRows + rowIdx].re,
                           paramVal[colIdx*numRows + rowIdx].im);
                }
                putchar('\n');
            }
        } else {
            real_T* paramVal = (real_T *) paramAddress;
            if (numDims == 3) {
                for (pageIdx = 0; pageIdx < numPages; pageIdx++) {
                    printf("ans(:,:,%d) =\n", pageIdx+1); 
                    for (rowIdx = 0; rowIdx < numRows; rowIdx++) {
                        for (colIdx = 0; colIdx < numCols; colIdx++) {
                            uint_T idx = rowIdx + numRows * colIdx +
                                numRows * numCols * pageIdx;
                            printf("\t%.4g", paramVal[idx]);
                        }
                        putchar('\n');
                    }
                    putchar('\n');
                }
            } else {
                for(rowIdx = 0; rowIdx < numRows; rowIdx++) {
                    for(colIdx = 0; colIdx < numCols; colIdx++) {
                        printf("\t%.4g", paramVal[colIdx*numRows + rowIdx]);
                    }
                    putchar('\n');
                }
            }
        }
        break;
      case SS_INT32 :
        if (isComplex) {
            cint32_T* paramVal = (cint32_T *) paramAddress;
            for(rowIdx = 0; rowIdx < numRows; rowIdx++) {
                for(colIdx = 0; colIdx < numCols; colIdx++) {
                    printf("\t%d + %d*i", 
                           paramVal[colIdx*numRows + rowIdx].re,
                           paramVal[colIdx*numRows + rowIdx].im);
                }						
                putchar('\n');
            }
        } else {
            int32_T* paramVal = (int32_T *) paramAddress;
            for(rowIdx = 0; rowIdx < numRows; rowIdx++) {
                for(colIdx = 0; colIdx < numCols; colIdx++) {
                    int32_T intVal  = paramVal[colIdx*numRows + rowIdx];
                    /* Real world value = (slope * stored integer) + bias */
                    real_T  realVal = slope*(intVal) + bias;
                    printf("\t%.4g", realVal);
                }
                putchar('\n');
            }
        }
        break;
      default :
        /* You can extend the switch-case to other Simulink DataIds
         * case SS_SINGLE:
         * case SS_UINT32:
         * case SS_INT16:
         * case SS_UINT16:
         * case SS_INT8:
         * case SS_UINT8:
         * case SS_BOOLEAN
         *
         * This function skips other data types. */
        printf("Unhandled Data Type: %s is skipped\n", paramName);
        break;
    }
    return;
}


/* Function capi_ModifyModelParameter ====================================== */
/* Abstract:
 *   This function takes in ModelMappingInfo structure modifies the value of 
 *   ModelParameter - rtModelParameters[paramIdx] with the newValue.
 *     capiMap  - Pointer to the ModelMappingInfo structure in Real-Time model.
 *                Map of all C-API arrays and structures. 
 *     paramIdx - Index of the Parameter in the rtModelParameters array 
 *                generated by RTW in <MODEL>_capi.c
 *     newParam - Pointer tot he new value of the parameter
 */
int_T capi_ModifyModelParameter(rtwCAPI_ModelMappingInfo* capiMap,
                                uint_T                    paramIdx,
                                void*                     newParam) {

    const rtwCAPI_ModelParameters* modelParams;
    const rtwCAPI_DataTypeMap*     dataTypeMap;
    const rtwCAPI_DimensionMap*    dimMap;
    const uint_T*                  dimArray;
    void**                         dataAddrMap;

    uint_T        addrIdx;
    uint16_T      dataTypeIdx;
    uint16_T      dimIndex;
    uint8_T       slDataID;

    void*                paramAddress;
    unsigned short       isComplex;
    uint8_T              numDims;
    uint_T               dimArrayIdx;
    rtwCAPI_Orientation  orientation;
    uint_T*              actualDimensions;

    int    idx;
    int_T  retVal = 0; 
    
    /* Get modelParams, an array of rtwCAPI_ModelParameters structure  */
    modelParams = rtwCAPI_GetModelParameters(capiMap);
    if (modelParams == NULL) return 0;

    /* Assert the parameter index is less than total number of parameters */
    assert(paramIdx < rtwCAPI_GetNumModelParameters(capiMap));

    /* Accessing the data type information from capiMap                   */
    dataTypeMap = rtwCAPI_GetDataTypeMap(capiMap);
    if (dataTypeMap == NULL) return 0;
    
    dataTypeIdx = rtwCAPI_GetModelParameterDataTypeIdx(modelParams, paramIdx);
    slDataID    = rtwCAPI_GetDataTypeSLId(dataTypeMap, dataTypeIdx);
    isComplex   = rtwCAPI_GetDataIsComplex(dataTypeMap, dataTypeIdx);

    /* Get Dimensions of the Model Parameter */
    dimMap = rtwCAPI_GetDimensionMap(capiMap);
    dimArray = rtwCAPI_GetDimensionArray(capiMap);
    if ((dimMap == NULL) || (dimArray == NULL)) return 0;

    dimIndex    = rtwCAPI_GetModelParameterDimensionIdx(modelParams, paramIdx);
    orientation = rtwCAPI_GetOrientation(dimMap, dimIndex);
    numDims     = rtwCAPI_GetNumDims(dimMap, dimIndex); 
    dimArrayIdx = rtwCAPI_GetDimArrayIndex(dimMap, dimIndex);

    actualDimensions = (uint_T *) malloc(numDims*sizeof(uint_T));
    for(idx=0; idx < numDims; idx++) {
        actualDimensions[idx] = dimArray[dimArrayIdx + idx];
    }

    /* Get the address to this parameter */
    dataAddrMap  = rtwCAPI_GetDataAddressMap(capiMap);
    addrIdx      = rtwCAPI_GetModelParameterAddrIdx(modelParams, paramIdx);
    paramAddress = (void *) rtwCAPI_GetDataAddress(dataAddrMap,addrIdx); 
    if (paramAddress == NULL) return 0;
    
    
    retVal = capi_ModifyParameter(paramAddress, newParam,
                                  orientation, actualDimensions, numDims,
                                  slDataID, isComplex);
    free(actualDimensions);
    return retVal;
}

/* ============================================================================
 * Function: capi_ModifyParameter
 *
 * Abstract:
 *   This function modifies a parameter.
 *       _param      : Parameter address that needs to be modified
 *       _newParam   : Address of the new parameter value
 *       orientation : orientation of the parameter (scalar|vector|matrix)
 *       dims        : the dimensions vector (Num Rows    = dims[0],
 *                                            Num Columns = dims[1], 
 *                                            Num Pages   = dims[2] ...)
 *       nDims       : the number of dimesnions (for scalar, vector and 
 *                     2-D matrix, nDims=2. For n-D params nDims > 2)
 *       slDatatype  : the data type ID define in simstruc.h. can be one of 
 *                     the enumerated value
 *                     SS_DOUBLE, SS_SINGLE, SS_INT8, SS_UINT8, SS_INT16, 
 *                     SS_UINT16, SS_INT32, SS_UINT32, SS_BOOLEAN
 *       isComplex   : if the parameter is complex (isComplex = 1, if complex)
 */
 
int_T capi_ModifyParameter(void                 *_param,
                           void                 *_newParam,
                           rtwCAPI_Orientation  orientation,
                           uint_T               *dims,
                           uint8_T              nDims,
                           uint8_T              slDataType,
                           unsigned short       isComplex) {
    uint_T rowIdx;
    uint_T colIdx;
    uint_T pageIdx;

    /* Switch over the slDataType to assess data type of the parameter */
    switch (slDataType) {
      case SS_DOUBLE: {
          if(isComplex == 0) {
              /* Type cast address to real_T: Non-Complex and Double */
              real_T *param     = (real_T *) (_param);
              real_T *newParam  = (real_T *) (_newParam); 

              /* Based on the orientation, assign new value to the parameter */
              switch( orientation ) {
                case rtwCAPI_SCALAR:
                  *param = *newParam;
                  break;
                  
                case rtwCAPI_VECTOR:
                  /* Vector: NumRows = dims[0], NumColumns = 1 */
                  /* Loop through rows to assign new values    */
                  for(rowIdx = 0; rowIdx < dims[0]*dims[1]; rowIdx++) {
                      param[rowIdx] = newParam[rowIdx];
                  }
                  break;
                  
                case rtwCAPI_MATRIX_COL_MAJOR:
                  /* Matrix: NumRows = dims[0], NumColumns = dims[1]       *
                   * Loop through rows and columns to assign new values.   *
                   * Note: RTW declares a matrix data as column-major      *
                   * A column-major matrix is one in which indexing        *
                   * is column-wise instead of row-wise. For e.g           *
                   * A = | 1  |   2    3 |
                         |    |          |  
                         | 4  |   5    6 |
                         |    |          |
                         | 7 \|/  8    9 |     
                   
                     A[0]=1; A[1]=4; A[2]=7; A[3]=2; A[4]=5; and so on  
                  */
                  for(rowIdx = 0; rowIdx < dims[0]; rowIdx++) {
                      for(colIdx = 0; colIdx < dims[1]; colIdx++) {
                          param[colIdx*dims[0] + rowIdx] = 
                              newParam[colIdx*dims[0] + rowIdx];
                      }
                  }
                  break;
                  
                case rtwCAPI_MATRIX_ROW_MAJOR:
                  /* Matrix: NumRows = dims[0], NumColumns = dims[1]       *
                   * Loop through rows and columns to assign new values    *
                   * Note: RTW does not declare a matrix data as row       *
                   * major.                                                *
                   * A = | 1     2    3 |
                         |------------> |
                         | 4     5    6 |
                         |              |
                         | 7     8    9 |     
                    
                     A[0]=1; A[1]=2; A[2]=3; A[3]=4; A[4]=5; and so on  
                  */
                  for(rowIdx = 0; rowIdx < dims[0]; rowIdx++) {
                      for(colIdx = 0; colIdx < dims[1]; colIdx++) {
                          param[rowIdx*dims[1] + colIdx] =
                              newParam[rowIdx*dims[1] + colIdx];
                      }
                  }
                  break;
                  
                case rtwCAPI_MATRIX_COL_MAJOR_ND:
                  /* N-Dimensional Parameters                             *
                   * RTW always declares N-D Parameters as column-indexed */
                  if (nDims == 3) {
                      /* only handle 3-D parameters */
                      for (pageIdx = 0; pageIdx < dims[2]; pageIdx++) {
                          for (rowIdx = 0; rowIdx < dims[0]; rowIdx++) {
                              for (colIdx = 0; colIdx < dims[1]; colIdx++) {
                                  uint_T idx = rowIdx + dims[0] * colIdx +
                                    dims[0] * dims[1] * pageIdx;
                                  param[idx] = newParam[idx];
                              }
                          }
                      }
                  }
                  break;
                  
                default:
                  return(0);
              } /* end switch(orientation) */
          } /* end if(isComplex == 0) */
          else {
              /* Type cast address to creal_T: Complex and Double */
              creal_T *param    = (creal_T *) (_param);
              creal_T *newParam = (creal_T *) (_newParam);
              
              /* Based on the orientation, assign new value to the parameter */
              switch( orientation ) {
                case rtwCAPI_SCALAR:
                  /* Assign real and complex values */
                  param->re = newParam->re;
                  param->im = newParam->im;
                  break;
                  
                case rtwCAPI_VECTOR:
                  /* Vector: NumRows = dims[0], NumColumns = 1 */
                  /* Loop through rows to assign new values    */
                  for(rowIdx = 0; rowIdx < dims[0]*dims[1]; rowIdx++) {
                      param[rowIdx].re = newParam[rowIdx].re;
                      param[rowIdx].im = newParam[rowIdx].im;
                  }
                  break;
                  
                case rtwCAPI_MATRIX_COL_MAJOR:
                  /* Matrix: NumRows = dims[0], NumColumns = dims[1]       *
                   * Loop through rows and columns to assign new values.   *
                   * Note: MATLAB declares a matrix data as column-major   *
                   * major. A column-major matrix is one in which indexing *
                   * is column-wise instead of row-wise. For e.g           *
                   * A = | 1  |   2    3 |
                         |    |          |  
                         | 4  |   5    6 |
                         |    |          |
                         | 7 \|/  8    9 |     
                    
                     A[0]=1; A[1]=4; A[2]=7; A[3]=2; A[4]=5; and so on  
                  */
                  for(rowIdx = 0; rowIdx < dims[0]; rowIdx++) {
                      for(colIdx = 0; colIdx < dims[1]; colIdx++) {
                        param[colIdx*dims[0] + rowIdx].re = \
                            newParam[colIdx*dims[0] + rowIdx].re;
                        param[colIdx*dims[0] + rowIdx].im = \
                            newParam[colIdx*dims[0] + rowIdx].im;
                      }
                  }
                  break;
                  
                case rtwCAPI_MATRIX_ROW_MAJOR:
                  /* Matrix: NumRows = dims[0], NumColumns = dims[1]       *
                   * Loop through rows and columns to assign new values    *
                   * Note: MATLAB does not declare a matrix data as row    *
                   * major.                                                *
                   * A = | 1     2    3 |
                         |------------> |
                         | 4     5    6 |
                         |              |
                         | 7     8    9 |     
                    
                     A[0]=1; A[1]=2; A[2]=3; A[3]=4; A[4]=5; and so on
                  */
                  
                  for(rowIdx = 0; rowIdx < dims[0]; rowIdx++) {
                      for(colIdx = 0; colIdx < dims[1]; colIdx++) {
                          param[rowIdx*dims[1] + colIdx].re = \
                              newParam[rowIdx*dims[1] + colIdx].re;
                          param[rowIdx*dims[1] + colIdx].im = \
                              newParam[rowIdx*dims[1] + colIdx].im;
                      }
                  }
                  break;

                case rtwCAPI_MATRIX_COL_MAJOR_ND:
                  /* N-Dimensional Parameters                             *
                   * RTW always declares N-D Parameters as column-indexed */
                  if (nDims == 3) {
                      /* only handle 3-D parameters */
                      for (pageIdx = 0; pageIdx < dims[2]; pageIdx++) {
                          for (rowIdx = 0; rowIdx < dims[0]; rowIdx++) {
                              for (colIdx = 0; colIdx < dims[1]; colIdx++) {
                                  uint_T idx = rowIdx + dims[0] * colIdx +
                                      dims[0] * dims[1] * pageIdx;
                                  param[idx].re = newParam[idx].re;
                                  param[idx].im = newParam[idx].im;
                              }
                          }
                      }
                  }
                  break;
                  
                default:
                  return(0);
              } /* end switch(orientation) */
          } /* end else */
      } /* end case SS_DOUBLE*/
        break;

      case SS_INT32:  {
          /* Type cast address to int32_T: signed 32 bit integer     */
          /* Note: You could check for complexity here by using      *
           * isComplex == 1 (as done for case SS_DOUBLE).            */

          int32_T *param    = (int32_T *) (_param);
          int32_T *newParam = (int32_T *) (_newParam); /* param's new value */
          
          switch( orientation ) {
            case rtwCAPI_SCALAR:
              *param = *newParam;
              break;
              
            case rtwCAPI_VECTOR:
              for(rowIdx = 0; rowIdx < dims[0]*dims[1]; rowIdx++) {
                  param[rowIdx] = newParam[rowIdx];
              }
              break;
              
            case rtwCAPI_MATRIX_ROW_MAJOR:
              for(rowIdx = 0; rowIdx < dims[0]; rowIdx++) {
                  for(colIdx = 0; colIdx < dims[1]; colIdx++) {
                      param[rowIdx*dims[1] + colIdx] = \
                          newParam[rowIdx*dims[1] + colIdx];
                  }
              }
              break;
              
            case rtwCAPI_MATRIX_COL_MAJOR:
              for(rowIdx = 0; rowIdx < dims[0]; rowIdx++) {
                  for(colIdx = 0; colIdx < dims[1]; colIdx++) {
                      param[colIdx*dims[0] + rowIdx] = \
                          newParam[colIdx*dims[0] + rowIdx];
                  }
              }
              break;
              
            default:
              return(0);
          } /* end switch(orientation) */
      } /* end case SS_INT32 */
        break;
        
      default:
        /* You can extend the switch-case to other Simulink DataIds
         * case SS_SINGLE:
         * case SS_UINT32:
         * case SS_INT16:
         * case SS_UINT16:
         * case SS_INT8:
         * case SS_UINT8:
         * case SS_BOOLEAN
         *
         * This function skips other data types. */
        printf("Cannot handle parameter data type. \n");
        return(0);
    }
    return(1);
}

/* EOF - rtw_capi_examples.c */