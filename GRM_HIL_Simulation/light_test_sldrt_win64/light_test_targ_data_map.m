  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 5;
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
    ;% Auto data (light_test_P)
    ;%
      section.nData     = 15;
      section.data(15)  = dumData; %prealloc
      
	  ;% light_test_P.Ramp1_InitialOutput
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% light_test_P.Ramp2_InitialOutput
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 1;
	
	  ;% light_test_P.Ramp_InitialOutput
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 2;
	
	  ;% light_test_P.Receive_from_FTHWICC_MaxMissedTicks
	  section.data(4).logicalSrcIdx = 5;
	  section.data(4).dtTransOffset = 3;
	
	  ;% light_test_P.Send_to_FTHWICC_MaxMissedTicks
	  section.data(5).logicalSrcIdx = 6;
	  section.data(5).dtTransOffset = 4;
	
	  ;% light_test_P.RealTimeSynchronization_MaxMissedTicks
	  section.data(6).logicalSrcIdx = 7;
	  section.data(6).dtTransOffset = 5;
	
	  ;% light_test_P.Receive_from_FTHWICC_YieldWhenWaiting
	  section.data(7).logicalSrcIdx = 8;
	  section.data(7).dtTransOffset = 6;
	
	  ;% light_test_P.Send_to_FTHWICC_YieldWhenWaiting
	  section.data(8).logicalSrcIdx = 9;
	  section.data(8).dtTransOffset = 7;
	
	  ;% light_test_P.RealTimeSynchronization_YieldWhenWaiting
	  section.data(9).logicalSrcIdx = 10;
	  section.data(9).dtTransOffset = 8;
	
	  ;% light_test_P.Ramp1_slope
	  section.data(10).logicalSrcIdx = 11;
	  section.data(10).dtTransOffset = 9;
	
	  ;% light_test_P.Ramp2_slope
	  section.data(11).logicalSrcIdx = 12;
	  section.data(11).dtTransOffset = 10;
	
	  ;% light_test_P.Ramp_slope
	  section.data(12).logicalSrcIdx = 13;
	  section.data(12).dtTransOffset = 11;
	
	  ;% light_test_P.Ramp1_start
	  section.data(13).logicalSrcIdx = 14;
	  section.data(13).dtTransOffset = 12;
	
	  ;% light_test_P.Ramp2_start
	  section.data(14).logicalSrcIdx = 15;
	  section.data(14).dtTransOffset = 13;
	
	  ;% light_test_P.Ramp_start
	  section.data(15).logicalSrcIdx = 16;
	  section.data(15).dtTransOffset = 14;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% light_test_P.Receive_from_FTHWICC_PacketID
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
	  ;% light_test_P.Send_to_FTHWICC_PacketID
	  section.data(2).logicalSrcIdx = 18;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% light_test_P.WrapToZero_Threshold
	  section.data(1).logicalSrcIdx = 19;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% light_test_P.Step_Y0
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
	  ;% light_test_P.Shaft2radPitch_Gain
	  section.data(2).logicalSrcIdx = 21;
	  section.data(2).dtTransOffset = 1;
	
	  ;% light_test_P.Gain_Gain
	  section.data(3).logicalSrcIdx = 22;
	  section.data(3).dtTransOffset = 2;
	
	  ;% light_test_P.Step_Y0_l
	  section.data(4).logicalSrcIdx = 23;
	  section.data(4).dtTransOffset = 3;
	
	  ;% light_test_P.Shaft2radYaw1_Gain
	  section.data(5).logicalSrcIdx = 24;
	  section.data(5).dtTransOffset = 4;
	
	  ;% light_test_P.Gain_Gain_b
	  section.data(6).logicalSrcIdx = 25;
	  section.data(6).dtTransOffset = 5;
	
	  ;% light_test_P.Step_Y0_a
	  section.data(7).logicalSrcIdx = 26;
	  section.data(7).dtTransOffset = 6;
	
	  ;% light_test_P.Shaft2radRoll1_Gain
	  section.data(8).logicalSrcIdx = 27;
	  section.data(8).dtTransOffset = 7;
	
	  ;% light_test_P.Gain_Gain_j
	  section.data(9).logicalSrcIdx = 28;
	  section.data(9).dtTransOffset = 8;
	
	  ;% light_test_P.Constant_Value
	  section.data(10).logicalSrcIdx = 29;
	  section.data(10).dtTransOffset = 9;
	
	  ;% light_test_P.Zero_Value
	  section.data(11).logicalSrcIdx = 30;
	  section.data(11).dtTransOffset = 10;
	
	  ;% light_test_P.Zero1_Value
	  section.data(12).logicalSrcIdx = 31;
	  section.data(12).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% light_test_P.Constant_Value_b
	  section.data(1).logicalSrcIdx = 32;
	  section.data(1).dtTransOffset = 0;
	
	  ;% light_test_P.Output_InitialCondition
	  section.data(2).logicalSrcIdx = 33;
	  section.data(2).dtTransOffset = 1;
	
	  ;% light_test_P.FixPtConstant_Value
	  section.data(3).logicalSrcIdx = 34;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
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
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (light_test_B)
    ;%
      section.nData     = 14;
      section.data(14)  = dumData; %prealloc
      
	  ;% light_test_B.Receive_from_FTHWICC_o1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% light_test_B.Receive_from_FTHWICC_o2
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% light_test_B.Receive_from_FTHWICC_o3
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% light_test_B.Receive_from_FTHWICC_o4
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% light_test_B.Receive_from_FTHWICC_o5
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% light_test_B.Receive_from_FTHWICC_o6
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% light_test_B.Receive_from_FTHWICC_o7
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% light_test_B.Receive_from_FTHWICC_o9
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% light_test_B.CastToDouble1
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% light_test_B.Gain
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% light_test_B.CastToDouble2
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% light_test_B.Gain_d
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% light_test_B.CastToDouble
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% light_test_B.Gain_o
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% light_test_B.Receive_from_FTHWICC_o12
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
	  ;% light_test_B.Send_to_FTHWICC
	  section.data(2).logicalSrcIdx = 15;
	  section.data(2).dtTransOffset = 1;
	
	  ;% light_test_B.RealTimeSynchronization
	  section.data(3).logicalSrcIdx = 16;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% light_test_B.Receive_from_FTHWICC_o8
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
	  ;% light_test_B.Output
	  section.data(2).logicalSrcIdx = 18;
	  section.data(2).dtTransOffset = 1;
	
	  ;% light_test_B.FixPtSwitch
	  section.data(3).logicalSrcIdx = 19;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% light_test_B.CastToBoolean
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
	  ;% light_test_B.NOT
	  section.data(2).logicalSrcIdx = 21;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
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
    nTotSects     = 2;
    sectIdxOffset = 4;
    
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
    ;% Auto data (light_test_DW)
    ;%
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% light_test_DW.Receive_from_FTHWICC_PWORK
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% light_test_DW.Send_to_FTHWICC_PWORK
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% light_test_DW.Scope1_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 3;
	
	  ;% light_test_DW.Scope2_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 5;
	
	  ;% light_test_DW.Scope3_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 7;
	
	  ;% light_test_DW.roll_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 9;
	
	  ;% light_test_DW.RealTimeSynchronization_PWORK
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% light_test_DW.Output_DSTATE
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
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


  targMap.checksum0 = 1187337891;
  targMap.checksum1 = 1598118462;
  targMap.checksum2 = 1050237216;
  targMap.checksum3 = 3807657381;

