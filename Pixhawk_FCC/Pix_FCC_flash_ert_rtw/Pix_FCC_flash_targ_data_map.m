  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 13;
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
    ;% Auto data (Pix_FCC_flash_P)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_P.FCC_PIX_Data
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_P.CompareToConstant_const
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_P.Out1_Y0
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_P.Constant_Value
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_P.Out1_Y0_f
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_P.Constant_Value_e
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_P.Out1_Y0_a
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_P.Constant_Value_l
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_P.ReceiveData_SampleTime
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Pix_FCC_flash_P.Constant_Value_n
	  section.data(2).logicalSrcIdx = 11;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Pix_FCC_flash_P.Constant_Value_m
	  section.data(3).logicalSrcIdx = 12;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Pix_FCC_flash_P.Zero_Value
	  section.data(4).logicalSrcIdx = 13;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Pix_FCC_flash_P.Kp_Gain
	  section.data(5).logicalSrcIdx = 14;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Pix_FCC_flash_P.Gain5_Gain
	  section.data(6).logicalSrcIdx = 15;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Pix_FCC_flash_P.Constant_Value_h
	  section.data(7).logicalSrcIdx = 16;
	  section.data(7).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(9) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_P.CMD_Y0
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Pix_FCC_flash_P.ACC_Y0
	  section.data(2).logicalSrcIdx = 18;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Pix_FCC_flash_P.ROT_Y0
	  section.data(3).logicalSrcIdx = 19;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Pix_FCC_flash_P.ATT_Y0
	  section.data(4).logicalSrcIdx = 20;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Pix_FCC_flash_P.TestSignal_Y0
	  section.data(5).logicalSrcIdx = 21;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Pix_FCC_flash_P.ServoCMD_Y0
	  section.data(6).logicalSrcIdx = 22;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Pix_FCC_flash_P.SensorACC_Y0
	  section.data(7).logicalSrcIdx = 23;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Pix_FCC_flash_P.SensorROT_Y0
	  section.data(8).logicalSrcIdx = 24;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Pix_FCC_flash_P.quaternion_Y0
	  section.data(9).logicalSrcIdx = 25;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Pix_FCC_flash_P.TestSignal_feedback_Y0
	  section.data(10).logicalSrcIdx = 26;
	  section.data(10).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(10) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_P.ms2us_1_Gain
	  section.data(1).logicalSrcIdx = 27;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Pix_FCC_flash_P.ms2us_2_Gain
	  section.data(2).logicalSrcIdx = 28;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Pix_FCC_flash_P.ms2us_3_Gain
	  section.data(3).logicalSrcIdx = 29;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Pix_FCC_flash_P.ms2us_4_Gain
	  section.data(4).logicalSrcIdx = 30;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Pix_FCC_flash_P.heartbeat_Y0
	  section.data(5).logicalSrcIdx = 31;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Pix_FCC_flash_P.SimHeartbeat_Y0
	  section.data(6).logicalSrcIdx = 32;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Pix_FCC_flash_P.Recovery_activation_flg_Value
	  section.data(7).logicalSrcIdx = 33;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Pix_FCC_flash_P.HIL_detect_flg_Value
	  section.data(8).logicalSrcIdx = 34;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(11) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_P.cmd_found_flg_Y0
	  section.data(1).logicalSrcIdx = 35;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Pix_FCC_flash_P.packetfound_flg_Y0
	  section.data(2).logicalSrcIdx = 36;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Pix_FCC_flash_P.PWM_arm_flg_Value
	  section.data(3).logicalSrcIdx = 37;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Pix_FCC_flash_P.Constant_Value_i
	  section.data(4).logicalSrcIdx = 38;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(12) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_P.SimStatus_Y0
	  section.data(1).logicalSrcIdx = 39;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Pix_FCC_flash_P.SimRCStatus_Y0
	  section.data(2).logicalSrcIdx = 40;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Pix_FCC_flash_P.PixStatus_Y0
	  section.data(3).logicalSrcIdx = 41;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Pix_FCC_flash_P.RCStatus_Y0
	  section.data(4).logicalSrcIdx = 42;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Pix_FCC_flash_P.Header_Value
	  section.data(5).logicalSrcIdx = 43;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Pix_FCC_flash_P.Header1_Value
	  section.data(6).logicalSrcIdx = 44;
	  section.data(6).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(13) = section;
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
    nTotSects     = 10;
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
    ;% Auto data (Pix_FCC_flash_B)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_B.In1_j
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_B.In1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_B.In1_c
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_B.VectorConcatenate
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_B.Zero
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Pix_FCC_flash_B.phi_dot_cmd
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Pix_FCC_flash_B.phi_dot_err
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Pix_FCC_flash_B.Phi_Cmd_rad
	  section.data(4).logicalSrcIdx = 7;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Pix_FCC_flash_B.Fin_1_Cmd_rad
	  section.data(5).logicalSrcIdx = 8;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Pix_FCC_flash_B.Fin_2_Cmd_rad
	  section.data(6).logicalSrcIdx = 9;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Pix_FCC_flash_B.Fin_3_Cmd_rad
	  section.data(7).logicalSrcIdx = 10;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Pix_FCC_flash_B.Fin_4_Cmd_rad
	  section.data(8).logicalSrcIdx = 11;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_B.Estimator
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Pix_FCC_flash_B.Switch
	  section.data(2).logicalSrcIdx = 14;
	  section.data(2).dtTransOffset = 7;
	
	  ;% Pix_FCC_flash_B.Switch1
	  section.data(3).logicalSrcIdx = 15;
	  section.data(3).dtTransOffset = 10;
	
	  ;% Pix_FCC_flash_B.CMD_update
	  section.data(4).logicalSrcIdx = 19;
	  section.data(4).dtTransOffset = 13;
	
	  ;% Pix_FCC_flash_B.ACC_update
	  section.data(5).logicalSrcIdx = 20;
	  section.data(5).dtTransOffset = 16;
	
	  ;% Pix_FCC_flash_B.ROT_update
	  section.data(6).logicalSrcIdx = 21;
	  section.data(6).dtTransOffset = 19;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_B.TestSignal_update
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_B.update
	  section.data(1).logicalSrcIdx = 26;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Pix_FCC_flash_B.cmd
	  section.data(2).logicalSrcIdx = 27;
	  section.data(2).dtTransOffset = 4;
	
	  ;% Pix_FCC_flash_B.ReceiveData_o1
	  section.data(3).logicalSrcIdx = 28;
	  section.data(3).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_B.SimHeartbeat_update
	  section.data(1).logicalSrcIdx = 23;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(9) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_B.packetfound
	  section.data(1).logicalSrcIdx = 29;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Pix_FCC_flash_B.cmd_found_flg
	  section.data(2).logicalSrcIdx = 30;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(10) = section;
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
    nTotSects     = 7;
    sectIdxOffset = 10;
    
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
    ;% Auto data (Pix_FCC_flash_DW)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_DW.obj
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_DW.obj_j
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_DW.obj_i
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_DW.obj_c
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Pix_FCC_flash_DW.obj_f
	  section.data(2).logicalSrcIdx = 4;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Pix_FCC_flash_DW.obj_d
	  section.data(3).logicalSrcIdx = 5;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_DW.ToWorkspace_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Pix_FCC_flash_DW.Scope_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 7;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Pix_FCC_flash_DW.Scope_PWORK_p.LoggedData
	  section.data(3).logicalSrcIdx = 8;
	  section.data(3).dtTransOffset = 6;
	
	  ;% Pix_FCC_flash_DW.Scope1_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 9;
	  section.data(4).dtTransOffset = 7;
	
	  ;% Pix_FCC_flash_DW.Scope_PWORK_e.LoggedData
	  section.data(5).logicalSrcIdx = 10;
	  section.data(5).dtTransOffset = 8;
	
	  ;% Pix_FCC_flash_DW.Scope2_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 11;
	  section.data(6).dtTransOffset = 11;
	
	  ;% Pix_FCC_flash_DW.Scope_PWORK_h.LoggedData
	  section.data(7).logicalSrcIdx = 12;
	  section.data(7).dtTransOffset = 12;
	
	  ;% Pix_FCC_flash_DW.Scope1_PWORK_m.LoggedData
	  section.data(8).logicalSrcIdx = 13;
	  section.data(8).dtTransOffset = 13;
	
	  ;% Pix_FCC_flash_DW.Cmd_PWORK.LoggedData
	  section.data(9).logicalSrcIdx = 14;
	  section.data(9).dtTransOffset = 14;
	
	  ;% Pix_FCC_flash_DW.Messagefound_PWORK.LoggedData
	  section.data(10).logicalSrcIdx = 15;
	  section.data(10).dtTransOffset = 15;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_DW.SFunction_DIMS2
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Pix_FCC_flash_DW.update_DIMS1
	  section.data(2).logicalSrcIdx = 17;
	  section.data(2).dtTransOffset = 2;
	
	  ;% Pix_FCC_flash_DW.SFunction_DIMS2_f
	  section.data(3).logicalSrcIdx = 18;
	  section.data(3).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 17;
      section.data(17)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_DW.EnabledSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 19;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Pix_FCC_flash_DW.EnabledSubsystem_SubsysRanBC_a
	  section.data(2).logicalSrcIdx = 20;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Pix_FCC_flash_DW.EnabledSubsystem_SubsysRanBC_o
	  section.data(3).logicalSrcIdx = 21;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Pix_FCC_flash_DW.ExecutionCycle_SubsysRanBC
	  section.data(4).logicalSrcIdx = 22;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Pix_FCC_flash_DW.OUTPUT_SubsysRanBC
	  section.data(5).logicalSrcIdx = 23;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Pix_FCC_flash_DW.ACTION_SubsysRanBC
	  section.data(6).logicalSrcIdx = 24;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Pix_FCC_flash_DW.IfActionSubsystem2_SubsysRanBC
	  section.data(7).logicalSrcIdx = 25;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Pix_FCC_flash_DW.IfActionSubsystem1_SubsysRanBC
	  section.data(8).logicalSrcIdx = 26;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Pix_FCC_flash_DW.IfActionSubsystem_SubsysRanBC
	  section.data(9).logicalSrcIdx = 27;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Pix_FCC_flash_DW.Saturate_SubsysRanBC
	  section.data(10).logicalSrcIdx = 28;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Pix_FCC_flash_DW.Pass_SubsysRanBC
	  section.data(11).logicalSrcIdx = 29;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Pix_FCC_flash_DW.process_received_data_SubsysRan
	  section.data(12).logicalSrcIdx = 30;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Pix_FCC_flash_DW.input_hold_SubsysRanBC
	  section.data(13).logicalSrcIdx = 31;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Pix_FCC_flash_DW.hold_SubsysRanBC
	  section.data(14).logicalSrcIdx = 32;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Pix_FCC_flash_DW.heartbeat_SubsysRanBC
	  section.data(15).logicalSrcIdx = 33;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Pix_FCC_flash_DW.memory_SubsysRanBC
	  section.data(16).logicalSrcIdx = 34;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Pix_FCC_flash_DW.DecodeCommand_SubsysRanBC
	  section.data(17).logicalSrcIdx = 35;
	  section.data(17).dtTransOffset = 16;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
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


  targMap.checksum0 = 3018308781;
  targMap.checksum1 = 1082835541;
  targMap.checksum2 = 3368418047;
  targMap.checksum3 = 2378301634;

