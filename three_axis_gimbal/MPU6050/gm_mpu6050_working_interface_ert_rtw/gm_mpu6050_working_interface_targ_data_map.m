  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 4;
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
    ;% Auto data (gm_mpu6050_working_interface_P)
    ;%
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% gm_mpu6050_working_interface_P.UnitDelay3_InitialCondition
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% gm_mpu6050_working_interface_P.UnitDelay3_InitialCondition_c
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% gm_mpu6050_working_interface_P.UnitDelay3_InitialCondition_g
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% gm_mpu6050_working_interface_P.Constant3_Value
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
	  ;% gm_mpu6050_working_interface_P.Constant4_Value
	  section.data(2).logicalSrcIdx = 4;
	  section.data(2).dtTransOffset = 1;
	
	  ;% gm_mpu6050_working_interface_P.Constant5_Value
	  section.data(3).logicalSrcIdx = 5;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% gm_mpu6050_working_interface_P.Constant2_Value
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
	  ;% gm_mpu6050_working_interface_P.ManualSwitch_CurrentSetting
	  section.data(2).logicalSrcIdx = 7;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% gm_mpu6050_working_interface_P.Constant_Value
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
	  ;% gm_mpu6050_working_interface_P.Constant1_Value
	  section.data(2).logicalSrcIdx = 9;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
    
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
    ;% Auto data (gm_mpu6050_working_interface_B)
    ;%
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% gm_mpu6050_working_interface_B.angle
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% gm_mpu6050_working_interface_B.angle_e
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% gm_mpu6050_working_interface_B.angle_i
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% gm_mpu6050_working_interface_B.AXI4Lite_Read_GyroX_DTC
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
	  ;% gm_mpu6050_working_interface_B.AXI4Lite_Read_GyroY_DTC
	  section.data(2).logicalSrcIdx = 4;
	  section.data(2).dtTransOffset = 1;
	
	  ;% gm_mpu6050_working_interface_B.AXI4Lite_Read_GyroZ_DTC
	  section.data(3).logicalSrcIdx = 5;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% gm_mpu6050_working_interface_B.AXI4Lite_Read_deviceID_DTC
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
	  ;% gm_mpu6050_working_interface_B.AXI4Lite_Read_RegData_DTC
	  section.data(2).logicalSrcIdx = 7;
	  section.data(2).dtTransOffset = 1;
	
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
    nTotSects     = 4;
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
    ;% Auto data (gm_mpu6050_working_interface_DW)
    ;%
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% gm_mpu6050_working_interface_DW.UnitDelay3_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% gm_mpu6050_working_interface_DW.UnitDelay3_DSTATE_i
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% gm_mpu6050_working_interface_DW.UnitDelay3_DSTATE_m
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% gm_mpu6050_working_interface_DW.obj
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
	  ;% gm_mpu6050_working_interface_DW.obj_f
	  section.data(2).logicalSrcIdx = 4;
	  section.data(2).dtTransOffset = 1;
	
	  ;% gm_mpu6050_working_interface_DW.obj_a
	  section.data(3).logicalSrcIdx = 5;
	  section.data(3).dtTransOffset = 2;
	
	  ;% gm_mpu6050_working_interface_DW.obj_o
	  section.data(4).logicalSrcIdx = 6;
	  section.data(4).dtTransOffset = 3;
	
	  ;% gm_mpu6050_working_interface_DW.obj_i
	  section.data(5).logicalSrcIdx = 7;
	  section.data(5).dtTransOffset = 4;
	
	  ;% gm_mpu6050_working_interface_DW.obj_av
	  section.data(6).logicalSrcIdx = 8;
	  section.data(6).dtTransOffset = 5;
	
	  ;% gm_mpu6050_working_interface_DW.obj_j
	  section.data(7).logicalSrcIdx = 9;
	  section.data(7).dtTransOffset = 6;
	
	  ;% gm_mpu6050_working_interface_DW.obj_n
	  section.data(8).logicalSrcIdx = 10;
	  section.data(8).dtTransOffset = 7;
	
	  ;% gm_mpu6050_working_interface_DW.obj_b
	  section.data(9).logicalSrcIdx = 11;
	  section.data(9).dtTransOffset = 8;
	
	  ;% gm_mpu6050_working_interface_DW.obj_o0
	  section.data(10).logicalSrcIdx = 12;
	  section.data(10).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% gm_mpu6050_working_interface_DW.obj_k
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
	  ;% gm_mpu6050_working_interface_DW.obj_p
	  section.data(2).logicalSrcIdx = 14;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 13;
      section.data(13)  = dumData; %prealloc
      
	  ;% gm_mpu6050_working_interface_DW.Scope_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 15;
	  section.data(1).dtTransOffset = 0;
	
	  ;% gm_mpu6050_working_interface_DW.AXI4InterfaceWrite_PWORK
	  section.data(2).logicalSrcIdx = 16;
	  section.data(2).dtTransOffset = 6;
	
	  ;% gm_mpu6050_working_interface_DW.AXI4InterfaceWrite_PWORK_p
	  section.data(3).logicalSrcIdx = 17;
	  section.data(3).dtTransOffset = 7;
	
	  ;% gm_mpu6050_working_interface_DW.AXI4InterfaceRead_PWORK
	  section.data(4).logicalSrcIdx = 18;
	  section.data(4).dtTransOffset = 8;
	
	  ;% gm_mpu6050_working_interface_DW.AXI4InterfaceRead_PWORK_b
	  section.data(5).logicalSrcIdx = 19;
	  section.data(5).dtTransOffset = 9;
	
	  ;% gm_mpu6050_working_interface_DW.AXI4InterfaceRead_PWORK_m
	  section.data(6).logicalSrcIdx = 20;
	  section.data(6).dtTransOffset = 10;
	
	  ;% gm_mpu6050_working_interface_DW.AXI4InterfaceRead_PWORK_j
	  section.data(7).logicalSrcIdx = 21;
	  section.data(7).dtTransOffset = 11;
	
	  ;% gm_mpu6050_working_interface_DW.AXI4InterfaceRead_PWORK_i
	  section.data(8).logicalSrcIdx = 22;
	  section.data(8).dtTransOffset = 12;
	
	  ;% gm_mpu6050_working_interface_DW.AXI4InterfaceRead_PWORK_h
	  section.data(9).logicalSrcIdx = 23;
	  section.data(9).dtTransOffset = 13;
	
	  ;% gm_mpu6050_working_interface_DW.AXI4InterfaceRead_PWORK_c
	  section.data(10).logicalSrcIdx = 24;
	  section.data(10).dtTransOffset = 14;
	
	  ;% gm_mpu6050_working_interface_DW.AXI4InterfaceRead_PWORK_e
	  section.data(11).logicalSrcIdx = 25;
	  section.data(11).dtTransOffset = 15;
	
	  ;% gm_mpu6050_working_interface_DW.AXI4InterfaceRead_PWORK_j4
	  section.data(12).logicalSrcIdx = 26;
	  section.data(12).dtTransOffset = 16;
	
	  ;% gm_mpu6050_working_interface_DW.AXI4InterfaceRead_PWORK_ma
	  section.data(13).logicalSrcIdx = 27;
	  section.data(13).dtTransOffset = 17;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
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


  targMap.checksum0 = 2525469790;
  targMap.checksum1 = 1758073227;
  targMap.checksum2 = 381188171;
  targMap.checksum3 = 2149187991;

