  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
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
    ;% Auto data (UDPcomTest_Host_P)
    ;%
      section.nData     = 39;
      section.data(39)  = dumData; %prealloc
      
	  ;% UDPcomTest_Host_P.RealTimeSynchronization_MaxMissedTicks
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% UDPcomTest_Host_P.RealTimeSynchronization_YieldWhenWaiting
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% UDPcomTest_Host_P.UDPConfigure_P1_Size
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% UDPcomTest_Host_P.UDPConfigure_P1
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 4;
	
	  ;% UDPcomTest_Host_P.UDPConfigure_P2_Size
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 8;
	
	  ;% UDPcomTest_Host_P.UDPConfigure_P2
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 10;
	
	  ;% UDPcomTest_Host_P.UDPConfigure_P3_Size
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 14;
	
	  ;% UDPcomTest_Host_P.UDPConfigure_P3
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 16;
	
	  ;% UDPcomTest_Host_P.UDPConfigure_P4_Size
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 20;
	
	  ;% UDPcomTest_Host_P.UDPConfigure_P5_Size
	  section.data(10).logicalSrcIdx = 10;
	  section.data(10).dtTransOffset = 22;
	
	  ;% UDPcomTest_Host_P.UDPConfigure_P5
	  section.data(11).logicalSrcIdx = 11;
	  section.data(11).dtTransOffset = 24;
	
	  ;% UDPcomTest_Host_P.UDPConfigure_P6_Size
	  section.data(12).logicalSrcIdx = 12;
	  section.data(12).dtTransOffset = 25;
	
	  ;% UDPcomTest_Host_P.UDPConfigure_P7_Size
	  section.data(13).logicalSrcIdx = 14;
	  section.data(13).dtTransOffset = 27;
	
	  ;% UDPcomTest_Host_P.UDPConfigure_P8_Size
	  section.data(14).logicalSrcIdx = 16;
	  section.data(14).dtTransOffset = 29;
	
	  ;% UDPcomTest_Host_P.UDPConfigure_P8
	  section.data(15).logicalSrcIdx = 17;
	  section.data(15).dtTransOffset = 31;
	
	  ;% UDPcomTest_Host_P.UDPConfigure_P9_Size
	  section.data(16).logicalSrcIdx = 18;
	  section.data(16).dtTransOffset = 32;
	
	  ;% UDPcomTest_Host_P.UDPConfigure_P9
	  section.data(17).logicalSrcIdx = 19;
	  section.data(17).dtTransOffset = 34;
	
	  ;% UDPcomTest_Host_P.UDPConfigure_P10_Size
	  section.data(18).logicalSrcIdx = 20;
	  section.data(18).dtTransOffset = 35;
	
	  ;% UDPcomTest_Host_P.UDPConfigure_P10
	  section.data(19).logicalSrcIdx = 21;
	  section.data(19).dtTransOffset = 37;
	
	  ;% UDPcomTest_Host_P.UDPConfigure_P11_Size
	  section.data(20).logicalSrcIdx = 22;
	  section.data(20).dtTransOffset = 38;
	
	  ;% UDPcomTest_Host_P.UDPConfigure_P11
	  section.data(21).logicalSrcIdx = 23;
	  section.data(21).dtTransOffset = 40;
	
	  ;% UDPcomTest_Host_P.UDPConfigure_P12_Size
	  section.data(22).logicalSrcIdx = 24;
	  section.data(22).dtTransOffset = 41;
	
	  ;% UDPcomTest_Host_P.UDPConfigure_P12
	  section.data(23).logicalSrcIdx = 25;
	  section.data(23).dtTransOffset = 43;
	
	  ;% UDPcomTest_Host_P.Constant_Value
	  section.data(24).logicalSrcIdx = 26;
	  section.data(24).dtTransOffset = 44;
	
	  ;% UDPcomTest_Host_P.Zero_Value
	  section.data(25).logicalSrcIdx = 27;
	  section.data(25).dtTransOffset = 45;
	
	  ;% UDPcomTest_Host_P.SignalGenerator_Amplitude
	  section.data(26).logicalSrcIdx = 28;
	  section.data(26).dtTransOffset = 46;
	
	  ;% UDPcomTest_Host_P.SignalGenerator_Frequency
	  section.data(27).logicalSrcIdx = 29;
	  section.data(27).dtTransOffset = 47;
	
	  ;% UDPcomTest_Host_P.UDPSend2_P1_Size
	  section.data(28).logicalSrcIdx = 30;
	  section.data(28).dtTransOffset = 48;
	
	  ;% UDPcomTest_Host_P.UDPSend2_P1
	  section.data(29).logicalSrcIdx = 31;
	  section.data(29).dtTransOffset = 50;
	
	  ;% UDPcomTest_Host_P.UDPSend2_P2_Size
	  section.data(30).logicalSrcIdx = 32;
	  section.data(30).dtTransOffset = 76;
	
	  ;% UDPcomTest_Host_P.UDPSend2_P2
	  section.data(31).logicalSrcIdx = 33;
	  section.data(31).dtTransOffset = 78;
	
	  ;% UDPcomTest_Host_P.UDPSend2_P3_Size
	  section.data(32).logicalSrcIdx = 34;
	  section.data(32).dtTransOffset = 79;
	
	  ;% UDPcomTest_Host_P.UDPSend2_P3
	  section.data(33).logicalSrcIdx = 35;
	  section.data(33).dtTransOffset = 81;
	
	  ;% UDPcomTest_Host_P.UDPSend2_P4_Size
	  section.data(34).logicalSrcIdx = 36;
	  section.data(34).dtTransOffset = 94;
	
	  ;% UDPcomTest_Host_P.UDPSend2_P4
	  section.data(35).logicalSrcIdx = 37;
	  section.data(35).dtTransOffset = 96;
	
	  ;% UDPcomTest_Host_P.UDPSend2_P5_Size
	  section.data(36).logicalSrcIdx = 38;
	  section.data(36).dtTransOffset = 97;
	
	  ;% UDPcomTest_Host_P.UDPSend2_P5
	  section.data(37).logicalSrcIdx = 39;
	  section.data(37).dtTransOffset = 99;
	
	  ;% UDPcomTest_Host_P.UDPSend2_P6_Size
	  section.data(38).logicalSrcIdx = 40;
	  section.data(38).dtTransOffset = 100;
	
	  ;% UDPcomTest_Host_P.UDPSend2_P6
	  section.data(39).logicalSrcIdx = 41;
	  section.data(39).dtTransOffset = 102;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
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
    ;% Auto data (UDPcomTest_Host_B)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% UDPcomTest_Host_B.SignalGenerator
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% UDPcomTest_Host_B.Cast
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% UDPcomTest_Host_B.BytePacking
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% UDPcomTest_Host_B.CastToBoolean
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
	  ;% UDPcomTest_Host_B.CastToBoolean1
	  section.data(2).logicalSrcIdx = 4;
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
    ;% Auto data (UDPcomTest_Host_DW)
    ;%
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% UDPcomTest_Host_DW.UDPConfigure_PWORK
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% UDPcomTest_Host_DW.UDPSend2_PWORK
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 5;
	
	  ;% UDPcomTest_Host_DW.sendingsignal_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 6;
	
	  ;% UDPcomTest_Host_DW.RealTimeSynchronization_PWORK
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% UDPcomTest_Host_DW.UDPConfigure_IWORK
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% UDPcomTest_Host_DW.BytePacking_IWORK
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 6;
	
	  ;% UDPcomTest_Host_DW.UDPSend2_IWORK
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 24;
	
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


  targMap.checksum0 = 459204029;
  targMap.checksum1 = 1669563769;
  targMap.checksum2 = 351877745;
  targMap.checksum3 = 3211230390;

