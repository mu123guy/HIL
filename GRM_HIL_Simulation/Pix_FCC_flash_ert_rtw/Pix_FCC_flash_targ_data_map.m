  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 21;
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
      
      section.nData     = 13;
      section.data(13)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_P.ReceiveData_SampleTime
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Pix_FCC_flash_P.SineWave_Amp
	  section.data(2).logicalSrcIdx = 9;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Pix_FCC_flash_P.SineWave_Bias
	  section.data(3).logicalSrcIdx = 10;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Pix_FCC_flash_P.SineWave_Freq
	  section.data(4).logicalSrcIdx = 11;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Pix_FCC_flash_P.SineWave_Hsin
	  section.data(5).logicalSrcIdx = 12;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Pix_FCC_flash_P.SineWave_HCos
	  section.data(6).logicalSrcIdx = 13;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Pix_FCC_flash_P.SineWave_PSin
	  section.data(7).logicalSrcIdx = 14;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Pix_FCC_flash_P.SineWave_PCos
	  section.data(8).logicalSrcIdx = 15;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Pix_FCC_flash_P.SineWave_Amp_e
	  section.data(9).logicalSrcIdx = 18;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Pix_FCC_flash_P.SineWave_Bias_o
	  section.data(10).logicalSrcIdx = 19;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Pix_FCC_flash_P.SineWave_Freq_j
	  section.data(11).logicalSrcIdx = 20;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Pix_FCC_flash_P.SineWave_Phase
	  section.data(12).logicalSrcIdx = 21;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Pix_FCC_flash_P.Constant_Value_h
	  section.data(13).logicalSrcIdx = 22;
	  section.data(13).dtTransOffset = 12;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(9) = section;
      clear section
      
      section.nData     = 26;
      section.data(26)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_P.CMD_Y0
	  section.data(1).logicalSrcIdx = 23;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Pix_FCC_flash_P.ACC_Y0
	  section.data(2).logicalSrcIdx = 24;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Pix_FCC_flash_P.ROT_Y0
	  section.data(3).logicalSrcIdx = 25;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Pix_FCC_flash_P.ATT_Y0
	  section.data(4).logicalSrcIdx = 26;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Pix_FCC_flash_P.TestSignal_Y0
	  section.data(5).logicalSrcIdx = 27;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Pix_FCC_flash_P.ServoCMD_Y0
	  section.data(6).logicalSrcIdx = 28;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Pix_FCC_flash_P.SensorACC_Y0
	  section.data(7).logicalSrcIdx = 29;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Pix_FCC_flash_P.SensorROT_Y0
	  section.data(8).logicalSrcIdx = 30;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Pix_FCC_flash_P.quaternion_Y0
	  section.data(9).logicalSrcIdx = 31;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Pix_FCC_flash_P.TestSignal_feedback_Y0
	  section.data(10).logicalSrcIdx = 32;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Pix_FCC_flash_P.DiscreteTransferFcn2_NumCoef
	  section.data(11).logicalSrcIdx = 33;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Pix_FCC_flash_P.DiscreteTransferFcn2_DenCoef
	  section.data(12).logicalSrcIdx = 34;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Pix_FCC_flash_P.DiscreteTransferFcn2_InitialSta
	  section.data(13).logicalSrcIdx = 35;
	  section.data(13).dtTransOffset = 13;
	
	  ;% Pix_FCC_flash_P.Gain4_Gain
	  section.data(14).logicalSrcIdx = 36;
	  section.data(14).dtTransOffset = 14;
	
	  ;% Pix_FCC_flash_P.Gain2_Gain
	  section.data(15).logicalSrcIdx = 37;
	  section.data(15).dtTransOffset = 15;
	
	  ;% Pix_FCC_flash_P.DiscreteTransferFcn1_NumCoef
	  section.data(16).logicalSrcIdx = 38;
	  section.data(16).dtTransOffset = 16;
	
	  ;% Pix_FCC_flash_P.DiscreteTransferFcn1_DenCoef
	  section.data(17).logicalSrcIdx = 39;
	  section.data(17).dtTransOffset = 17;
	
	  ;% Pix_FCC_flash_P.DiscreteTransferFcn1_InitialSta
	  section.data(18).logicalSrcIdx = 40;
	  section.data(18).dtTransOffset = 19;
	
	  ;% Pix_FCC_flash_P.Gain3_Gain
	  section.data(19).logicalSrcIdx = 41;
	  section.data(19).dtTransOffset = 20;
	
	  ;% Pix_FCC_flash_P.Gain1_Gain
	  section.data(20).logicalSrcIdx = 42;
	  section.data(20).dtTransOffset = 21;
	
	  ;% Pix_FCC_flash_P.Gain_Gain
	  section.data(21).logicalSrcIdx = 43;
	  section.data(21).dtTransOffset = 22;
	
	  ;% Pix_FCC_flash_P.DiscreteTransferFcn_NumCoef
	  section.data(22).logicalSrcIdx = 44;
	  section.data(22).dtTransOffset = 23;
	
	  ;% Pix_FCC_flash_P.DiscreteTransferFcn_DenCoef
	  section.data(23).logicalSrcIdx = 45;
	  section.data(23).dtTransOffset = 25;
	
	  ;% Pix_FCC_flash_P.DiscreteTransferFcn_InitialStat
	  section.data(24).logicalSrcIdx = 46;
	  section.data(24).dtTransOffset = 27;
	
	  ;% Pix_FCC_flash_P.Limit2maxDeflection_UpperSat
	  section.data(25).logicalSrcIdx = 47;
	  section.data(25).dtTransOffset = 28;
	
	  ;% Pix_FCC_flash_P.Limit2maxDeflection_LowerSat
	  section.data(26).logicalSrcIdx = 48;
	  section.data(26).dtTransOffset = 29;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(10) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_P.ms2us_1_Gain
	  section.data(1).logicalSrcIdx = 49;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Pix_FCC_flash_P.ms2us_2_Gain
	  section.data(2).logicalSrcIdx = 50;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Pix_FCC_flash_P.ms2us_3_Gain
	  section.data(3).logicalSrcIdx = 51;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Pix_FCC_flash_P.ms2us_4_Gain
	  section.data(4).logicalSrcIdx = 52;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Pix_FCC_flash_P.heartbeat_Y0
	  section.data(5).logicalSrcIdx = 53;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Pix_FCC_flash_P.SimHeartbeat_Y0
	  section.data(6).logicalSrcIdx = 54;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Pix_FCC_flash_P.Recovery_activation_flg_Value
	  section.data(7).logicalSrcIdx = 55;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Pix_FCC_flash_P.HIL_detect_flg_Value
	  section.data(8).logicalSrcIdx = 56;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(11) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_P.cmd_found_flg_Y0
	  section.data(1).logicalSrcIdx = 57;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Pix_FCC_flash_P.packetfound_flg_Y0
	  section.data(2).logicalSrcIdx = 58;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Pix_FCC_flash_P.PWM_arm_flg_Value
	  section.data(3).logicalSrcIdx = 59;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Pix_FCC_flash_P.Constant_Value_i
	  section.data(4).logicalSrcIdx = 60;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(12) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_P.Header_Value
	  section.data(1).logicalSrcIdx = 61;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Pix_FCC_flash_P.SimStatus_Y0
	  section.data(2).logicalSrcIdx = 62;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Pix_FCC_flash_P.SimRCStatus_Y0
	  section.data(3).logicalSrcIdx = 63;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Pix_FCC_flash_P.PixStatus_Y0
	  section.data(4).logicalSrcIdx = 64;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Pix_FCC_flash_P.RCStatus_Y0
	  section.data(5).logicalSrcIdx = 65;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_P.SendWhiteNoiseEnd_a.Header_Value
	  section.data(1).logicalSrcIdx = 66;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_P.SendTerminator_g.Header_Value
	  section.data(1).logicalSrcIdx = 67;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_P.SendHeader_k.Header_Value
	  section.data(1).logicalSrcIdx = 68;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(16) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_P.SendWhiteNoiseBeginning_p.Header_Value
	  section.data(1).logicalSrcIdx = 69;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(17) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_P.SendWhiteNoiseEnd.Header_Value
	  section.data(1).logicalSrcIdx = 70;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(18) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_P.SendTerminator.Header_Value
	  section.data(1).logicalSrcIdx = 71;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(19) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_P.SendHeader.Header_Value
	  section.data(1).logicalSrcIdx = 72;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(20) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_P.SendWhiteNoiseBeginning.Header_Value
	  section.data(1).logicalSrcIdx = 73;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(21) = section;
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
    nTotSects     = 11;
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
      
	  ;% Pix_FCC_flash_B.In1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_B.In1_j
	  section.data(1).logicalSrcIdx = 1;
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
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_B.Cast1
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Pix_FCC_flash_B.CMD_update
	  section.data(2).logicalSrcIdx = 13;
	  section.data(2).dtTransOffset = 4;
	
	  ;% Pix_FCC_flash_B.ACC_update
	  section.data(3).logicalSrcIdx = 14;
	  section.data(3).dtTransOffset = 7;
	
	  ;% Pix_FCC_flash_B.ROT_update
	  section.data(4).logicalSrcIdx = 15;
	  section.data(4).dtTransOffset = 10;
	
	  ;% Pix_FCC_flash_B.ATT_update
	  section.data(5).logicalSrcIdx = 16;
	  section.data(5).dtTransOffset = 13;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_B.msgOut
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_B.SineWave
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Pix_FCC_flash_B.SineWave_j
	  section.data(2).logicalSrcIdx = 4;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_B.TestSignal_update
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_B.Cast
	  section.data(1).logicalSrcIdx = 18;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(8) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_B.update
	  section.data(1).logicalSrcIdx = 23;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Pix_FCC_flash_B.cmd
	  section.data(2).logicalSrcIdx = 24;
	  section.data(2).dtTransOffset = 4;
	
	  ;% Pix_FCC_flash_B.ReceiveData_o1
	  section.data(3).logicalSrcIdx = 25;
	  section.data(3).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_B.SimHeartbeat_update
	  section.data(1).logicalSrcIdx = 19;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(10) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_B.packetfound
	  section.data(1).logicalSrcIdx = 26;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Pix_FCC_flash_B.cmd_found_flg
	  section.data(2).logicalSrcIdx = 27;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(11) = section;
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
    nTotSects     = 34;
    sectIdxOffset = 11;
    
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
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_DW.obj_h
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Pix_FCC_flash_DW.obj_b
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Pix_FCC_flash_DW.obj_k
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_DW.obj_j
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_DW.obj_c
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Pix_FCC_flash_DW.obj_f
	  section.data(2).logicalSrcIdx = 6;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Pix_FCC_flash_DW.obj_d
	  section.data(3).logicalSrcIdx = 7;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_DW.lastSin
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Pix_FCC_flash_DW.lastCos
	  section.data(2).logicalSrcIdx = 9;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_DW.ToWorkspace_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Pix_FCC_flash_DW.Scope_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 11;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Pix_FCC_flash_DW.Acc_x_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 12;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Pix_FCC_flash_DW.Heartbeat_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 13;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Pix_FCC_flash_DW.Scope1_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 14;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Pix_FCC_flash_DW.Scope_PWORK_h.LoggedData
	  section.data(6).logicalSrcIdx = 15;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Pix_FCC_flash_DW.Scope1_PWORK_m.LoggedData
	  section.data(7).logicalSrcIdx = 16;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Pix_FCC_flash_DW.Cmd_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 17;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Pix_FCC_flash_DW.Messagefound_PWORK.LoggedData
	  section.data(9).logicalSrcIdx = 18;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Pix_FCC_flash_DW.Scope_PWORK_i.LoggedData
	  section.data(10).logicalSrcIdx = 19;
	  section.data(10).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_DW.DiscreteTransferFcn2_states
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Pix_FCC_flash_DW.DiscreteTransferFcn1_states
	  section.data(2).logicalSrcIdx = 21;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Pix_FCC_flash_DW.DiscreteTransferFcn_states
	  section.data(3).logicalSrcIdx = 22;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_DW.SFunction_DIMS2
	  section.data(1).logicalSrcIdx = 24;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Pix_FCC_flash_DW.update_DIMS1
	  section.data(2).logicalSrcIdx = 25;
	  section.data(2).dtTransOffset = 2;
	
	  ;% Pix_FCC_flash_DW.SFunction_DIMS2_f
	  section.data(3).logicalSrcIdx = 26;
	  section.data(3).dtTransOffset = 4;
	
	  ;% Pix_FCC_flash_DW.systemEnable
	  section.data(4).logicalSrcIdx = 27;
	  section.data(4).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 18;
      section.data(18)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_DW.EnabledSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 28;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Pix_FCC_flash_DW.EnabledSubsystem_SubsysRanBC_a
	  section.data(2).logicalSrcIdx = 29;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Pix_FCC_flash_DW.EnabledSubsystem_SubsysRanBC_o
	  section.data(3).logicalSrcIdx = 30;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Pix_FCC_flash_DW.ExecutionCycle_SubsysRanBC
	  section.data(4).logicalSrcIdx = 31;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Pix_FCC_flash_DW.OUTPUT_SubsysRanBC
	  section.data(5).logicalSrcIdx = 32;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Pix_FCC_flash_DW.SendData_SubsysRanBC
	  section.data(6).logicalSrcIdx = 33;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Pix_FCC_flash_DW.ACTION_SubsysRanBC
	  section.data(7).logicalSrcIdx = 34;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Pix_FCC_flash_DW.Saturate_SubsysRanBC
	  section.data(8).logicalSrcIdx = 35;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Pix_FCC_flash_DW.Pass_SubsysRanBC
	  section.data(9).logicalSrcIdx = 36;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Pix_FCC_flash_DW.process_received_data_SubsysRan
	  section.data(10).logicalSrcIdx = 37;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Pix_FCC_flash_DW.input_hold_SubsysRanBC
	  section.data(11).logicalSrcIdx = 38;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Pix_FCC_flash_DW.hold_SubsysRanBC
	  section.data(12).logicalSrcIdx = 39;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Pix_FCC_flash_DW.heartbeat_SubsysRanBC
	  section.data(13).logicalSrcIdx = 40;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Pix_FCC_flash_DW.memory_SubsysRanBC
	  section.data(14).logicalSrcIdx = 41;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Pix_FCC_flash_DW.DecodeCommand_SubsysRanBC
	  section.data(15).logicalSrcIdx = 42;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Pix_FCC_flash_DW.ConfirmCommand_SubsysRanBC
	  section.data(16).logicalSrcIdx = 43;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Pix_FCC_flash_DW.SendData_SubsysRanBC_b
	  section.data(17).logicalSrcIdx = 44;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Pix_FCC_flash_DW.SendRCConfrimation_SubsysRanBC
	  section.data(18).logicalSrcIdx = 45;
	  section.data(18).dtTransOffset = 17;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_DW.DecodeCommand_MODE
	  section.data(1).logicalSrcIdx = 55;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Pix_FCC_flash_DW.ConfirmCommand_MODE
	  section.data(2).logicalSrcIdx = 56;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_DW.SendWhiteNoiseEnd_a.obj
	  section.data(1).logicalSrcIdx = 57;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_DW.SendWhiteNoiseEnd_a.SendWhiteNoiseBeginning_SubsysR
	  section.data(1).logicalSrcIdx = 58;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_DW.SendWhiteNoiseEnd_a.objisempty
	  section.data(1).logicalSrcIdx = 59;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_DW.SendTerminator_g.obj
	  section.data(1).logicalSrcIdx = 60;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_DW.SendTerminator_g.SendHeader_SubsysRanBC
	  section.data(1).logicalSrcIdx = 61;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_DW.SendTerminator_g.objisempty
	  section.data(1).logicalSrcIdx = 62;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(16) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_DW.SendHeader_k.obj
	  section.data(1).logicalSrcIdx = 63;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(17) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_DW.SendHeader_k.SendHeader_SubsysRanBC
	  section.data(1).logicalSrcIdx = 64;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(18) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_DW.SendHeader_k.objisempty
	  section.data(1).logicalSrcIdx = 65;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(19) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_DW.SendWhiteNoiseBeginning_p.obj
	  section.data(1).logicalSrcIdx = 66;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(20) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_DW.SendWhiteNoiseBeginning_p.SendWhiteNoiseBeginning_SubsysR
	  section.data(1).logicalSrcIdx = 67;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(21) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_DW.SendWhiteNoiseBeginning_p.objisempty
	  section.data(1).logicalSrcIdx = 68;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(22) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_DW.SendWhiteNoiseEnd.obj
	  section.data(1).logicalSrcIdx = 69;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(23) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_DW.SendWhiteNoiseEnd.SendWhiteNoiseBeginning_SubsysR
	  section.data(1).logicalSrcIdx = 70;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(24) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_DW.SendWhiteNoiseEnd.objisempty
	  section.data(1).logicalSrcIdx = 71;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(25) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_DW.SendTerminator.obj
	  section.data(1).logicalSrcIdx = 72;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(26) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_DW.SendTerminator.SendHeader_SubsysRanBC
	  section.data(1).logicalSrcIdx = 73;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(27) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_DW.SendTerminator.objisempty
	  section.data(1).logicalSrcIdx = 74;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(28) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_DW.SendHeader.obj
	  section.data(1).logicalSrcIdx = 75;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(29) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_DW.SendHeader.SendHeader_SubsysRanBC
	  section.data(1).logicalSrcIdx = 76;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(30) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_DW.SendHeader.objisempty
	  section.data(1).logicalSrcIdx = 77;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(31) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_DW.SendWhiteNoiseBeginning.obj
	  section.data(1).logicalSrcIdx = 78;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(32) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_DW.SendWhiteNoiseBeginning.SendWhiteNoiseBeginning_SubsysR
	  section.data(1).logicalSrcIdx = 79;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(33) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Pix_FCC_flash_DW.SendWhiteNoiseBeginning.objisempty
	  section.data(1).logicalSrcIdx = 80;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(34) = section;
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


  targMap.checksum0 = 3795466782;
  targMap.checksum1 = 423616159;
  targMap.checksum2 = 402338265;
  targMap.checksum3 = 4240942605;

