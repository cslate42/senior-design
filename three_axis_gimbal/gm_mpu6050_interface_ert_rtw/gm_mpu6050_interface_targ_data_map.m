  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
<<<<<<< HEAD
    nTotSects     = 2;
=======
    nTotSects     = 1;
>>>>>>> 4c498d00033ba8e3c1028dad581483e8536e1362
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (gm_mpu6050_interface_P)
    ;%
<<<<<<< HEAD
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
=======
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
>>>>>>> 4c498d00033ba8e3c1028dad581483e8536e1362
      
	  ;% gm_mpu6050_interface_P.Constant2_Value
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
<<<<<<< HEAD
	  ;% gm_mpu6050_interface_P.ManualSwitch_CurrentSetting
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
=======
>>>>>>> 4c498d00033ba8e3c1028dad581483e8536e1362
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
<<<<<<< HEAD
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% gm_mpu6050_interface_P.Constant_Value
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% gm_mpu6050_interface_P.Constant1_Value
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
=======
>>>>>>> 4c498d00033ba8e3c1028dad581483e8536e1362
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (gm_mpu6050_interface_B)
    ;%
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% gm_mpu6050_interface_B.AXI4Lite_Read_AccelX_DTC
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% gm_mpu6050_interface_B.AXI4Lite_Read_AccelY_DTC
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% gm_mpu6050_interface_B.AXI4Lite_Read_AccelZ_DTC
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% gm_mpu6050_interface_B.AXI4Lite_Read_GyroX_DTC
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% gm_mpu6050_interface_B.AXI4Lite_Read_GyroY_DTC
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% gm_mpu6050_interface_B.AXI4Lite_Read_GyroZ_DTC
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% gm_mpu6050_interface_B.AXI4Lite_Read_deviceID_DTC
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
	  ;% gm_mpu6050_interface_B.AXI4Lite_Read_RegData_DTC
	  section.data(2).logicalSrcIdx = 7;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% gm_mpu6050_interface_B.AXI4Lite_Read_validout_DTC
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
    sectIdxOffset = 3;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (gm_mpu6050_interface_DW)
    ;%
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% gm_mpu6050_interface_DW.obj
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
<<<<<<< HEAD
	  ;% gm_mpu6050_interface_DW.obj_f
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% gm_mpu6050_interface_DW.obj_d
=======
	  ;% gm_mpu6050_interface_DW.obj_k
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% gm_mpu6050_interface_DW.obj_f
>>>>>>> 4c498d00033ba8e3c1028dad581483e8536e1362
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% gm_mpu6050_interface_DW.obj_c
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
<<<<<<< HEAD
	  ;% gm_mpu6050_interface_DW.obj_i
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% gm_mpu6050_interface_DW.obj_g
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% gm_mpu6050_interface_DW.obj_fo
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% gm_mpu6050_interface_DW.obj_n
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% gm_mpu6050_interface_DW.obj_a
=======
	  ;% gm_mpu6050_interface_DW.obj_d
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% gm_mpu6050_interface_DW.obj_b
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% gm_mpu6050_interface_DW.obj_h
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% gm_mpu6050_interface_DW.obj_hs
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% gm_mpu6050_interface_DW.obj_bm
>>>>>>> 4c498d00033ba8e3c1028dad581483e8536e1362
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
<<<<<<< HEAD
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% gm_mpu6050_interface_DW.obj_aq
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
	  ;% gm_mpu6050_interface_DW.obj_p
	  section.data(2).logicalSrcIdx = 10;
	  section.data(2).dtTransOffset = 1;
	
=======
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% gm_mpu6050_interface_DW.obj_a
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
>>>>>>> 4c498d00033ba8e3c1028dad581483e8536e1362
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
<<<<<<< HEAD
      section.nData     = 13;
      section.data(13)  = dumData; %prealloc
      
	  ;% gm_mpu6050_interface_DW.Scope_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
	  ;% gm_mpu6050_interface_DW.Scope1_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 12;
	  section.data(2).dtTransOffset = 2;
	
	  ;% gm_mpu6050_interface_DW.AXI4InterfaceWrite_PWORK
	  section.data(3).logicalSrcIdx = 13;
	  section.data(3).dtTransOffset = 4;
	
	  ;% gm_mpu6050_interface_DW.AXI4InterfaceWrite_PWORK_i
	  section.data(4).logicalSrcIdx = 14;
	  section.data(4).dtTransOffset = 5;
	
	  ;% gm_mpu6050_interface_DW.AXI4InterfaceRead_PWORK
	  section.data(5).logicalSrcIdx = 15;
	  section.data(5).dtTransOffset = 6;
	
	  ;% gm_mpu6050_interface_DW.AXI4InterfaceRead_PWORK_c
	  section.data(6).logicalSrcIdx = 16;
	  section.data(6).dtTransOffset = 7;
	
	  ;% gm_mpu6050_interface_DW.AXI4InterfaceRead_PWORK_n
	  section.data(7).logicalSrcIdx = 17;
	  section.data(7).dtTransOffset = 8;
	
	  ;% gm_mpu6050_interface_DW.AXI4InterfaceRead_PWORK_no
	  section.data(8).logicalSrcIdx = 18;
	  section.data(8).dtTransOffset = 9;
	
	  ;% gm_mpu6050_interface_DW.AXI4InterfaceRead_PWORK_o
	  section.data(9).logicalSrcIdx = 19;
	  section.data(9).dtTransOffset = 10;
	
	  ;% gm_mpu6050_interface_DW.AXI4InterfaceRead_PWORK_p
	  section.data(10).logicalSrcIdx = 20;
	  section.data(10).dtTransOffset = 11;
	
	  ;% gm_mpu6050_interface_DW.AXI4InterfaceRead_PWORK_ns
	  section.data(11).logicalSrcIdx = 21;
	  section.data(11).dtTransOffset = 12;
	
	  ;% gm_mpu6050_interface_DW.AXI4InterfaceRead_PWORK_j
	  section.data(12).logicalSrcIdx = 22;
	  section.data(12).dtTransOffset = 13;
	
	  ;% gm_mpu6050_interface_DW.AXI4InterfaceRead_PWORK_f
	  section.data(13).logicalSrcIdx = 23;
	  section.data(13).dtTransOffset = 14;
	
=======
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% gm_mpu6050_interface_DW.Scope_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
	  ;% gm_mpu6050_interface_DW.Scope1_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 11;
	  section.data(2).dtTransOffset = 2;
	
	  ;% gm_mpu6050_interface_DW.AXI4InterfaceWrite_PWORK
	  section.data(3).logicalSrcIdx = 12;
	  section.data(3).dtTransOffset = 4;
	
	  ;% gm_mpu6050_interface_DW.AXI4InterfaceRead_PWORK
	  section.data(4).logicalSrcIdx = 13;
	  section.data(4).dtTransOffset = 5;
	
	  ;% gm_mpu6050_interface_DW.AXI4InterfaceRead_PWORK_d
	  section.data(5).logicalSrcIdx = 14;
	  section.data(5).dtTransOffset = 6;
	
	  ;% gm_mpu6050_interface_DW.AXI4InterfaceRead_PWORK_i
	  section.data(6).logicalSrcIdx = 15;
	  section.data(6).dtTransOffset = 7;
	
	  ;% gm_mpu6050_interface_DW.AXI4InterfaceRead_PWORK_g
	  section.data(7).logicalSrcIdx = 16;
	  section.data(7).dtTransOffset = 8;
	
	  ;% gm_mpu6050_interface_DW.AXI4InterfaceRead_PWORK_h
	  section.data(8).logicalSrcIdx = 17;
	  section.data(8).dtTransOffset = 9;
	
	  ;% gm_mpu6050_interface_DW.AXI4InterfaceRead_PWORK_c
	  section.data(9).logicalSrcIdx = 18;
	  section.data(9).dtTransOffset = 10;
	
	  ;% gm_mpu6050_interface_DW.AXI4InterfaceRead_PWORK_gy
	  section.data(10).logicalSrcIdx = 19;
	  section.data(10).dtTransOffset = 11;
	
	  ;% gm_mpu6050_interface_DW.AXI4InterfaceRead_PWORK_e
	  section.data(11).logicalSrcIdx = 20;
	  section.data(11).dtTransOffset = 12;
	
	  ;% gm_mpu6050_interface_DW.AXI4InterfaceRead_PWORK_k
	  section.data(12).logicalSrcIdx = 21;
	  section.data(12).dtTransOffset = 13;
	
>>>>>>> 4c498d00033ba8e3c1028dad581483e8536e1362
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


<<<<<<< HEAD
  targMap.checksum0 = 2989849312;
  targMap.checksum1 = 3796359318;
  targMap.checksum2 = 706944500;
  targMap.checksum3 = 169661232;
=======
  targMap.checksum0 = 3824400405;
  targMap.checksum1 = 3007023022;
  targMap.checksum2 = 1056273578;
  targMap.checksum3 = 3677805042;
>>>>>>> 4c498d00033ba8e3c1028dad581483e8536e1362

