  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 29;
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
    ;% Auto data (GRM_HIL_P)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_P.HIL_Sample_Time
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_P.FDM_Linear_FDM
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_P.Gimbel_Ctrl_Gimbal_Ctrl
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_P.FDM_Linear_TF
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_P.Gimbal_TransferFunctions_TF
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_P.External_Inputs_External_Inputs
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_P.Initial_States_Rigid_Body
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_P.FlightController_FCC
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_P.Servo_TF
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_P.Servo_Cmd_PWM
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_P.Servo_PWM
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_P.ReverseFinDeflection_Control_Surfaces
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_P.FinDeflection_Control_Surfaces
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_P.Servo_Cmd_Control_Surfaces
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_P.Initial_States_Airframe
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(15) = section;
      clear section
      
      section.nData     = 15;
      section.data(15)  = dumData; %prealloc
      
	  ;% GRM_HIL_P.PIDController_InitialConditionForFilter
	  section.data(1).logicalSrcIdx = 15;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GRM_HIL_P.PIDController1_InitialConditionForFilter
	  section.data(2).logicalSrcIdx = 16;
	  section.data(2).dtTransOffset = 1;
	
	  ;% GRM_HIL_P.PIDController_InitialConditionForIntegrator
	  section.data(3).logicalSrcIdx = 17;
	  section.data(3).dtTransOffset = 2;
	
	  ;% GRM_HIL_P.PIDController1_InitialConditionForIntegrator
	  section.data(4).logicalSrcIdx = 18;
	  section.data(4).dtTransOffset = 3;
	
	  ;% GRM_HIL_P.PIDController_Kb
	  section.data(5).logicalSrcIdx = 19;
	  section.data(5).dtTransOffset = 4;
	
	  ;% GRM_HIL_P.PIDController1_Kb
	  section.data(6).logicalSrcIdx = 20;
	  section.data(6).dtTransOffset = 5;
	
	  ;% GRM_HIL_P.PIDController_LowerSaturationLimit
	  section.data(7).logicalSrcIdx = 21;
	  section.data(7).dtTransOffset = 6;
	
	  ;% GRM_HIL_P.PIDController1_LowerSaturationLimit
	  section.data(8).logicalSrcIdx = 22;
	  section.data(8).dtTransOffset = 7;
	
	  ;% GRM_HIL_P.RealTimeSynchronization_MaxMissedTicks
	  section.data(9).logicalSrcIdx = 23;
	  section.data(9).dtTransOffset = 8;
	
	  ;% GRM_HIL_P.PIDController_N
	  section.data(10).logicalSrcIdx = 24;
	  section.data(10).dtTransOffset = 9;
	
	  ;% GRM_HIL_P.PIDController1_N
	  section.data(11).logicalSrcIdx = 25;
	  section.data(11).dtTransOffset = 10;
	
	  ;% GRM_HIL_P.PIDController_UpperSaturationLimit
	  section.data(12).logicalSrcIdx = 26;
	  section.data(12).dtTransOffset = 11;
	
	  ;% GRM_HIL_P.PIDController1_UpperSaturationLimit
	  section.data(13).logicalSrcIdx = 27;
	  section.data(13).dtTransOffset = 12;
	
	  ;% GRM_HIL_P.RealTimeSynchronization_YieldWhenWaiting
	  section.data(14).logicalSrcIdx = 28;
	  section.data(14).dtTransOffset = 13;
	
	  ;% GRM_HIL_P.CompareToConstant_const
	  section.data(15).logicalSrcIdx = 29;
	  section.data(15).dtTransOffset = 14;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(16) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_P.States_hold_Y0
	  section.data(1).logicalSrcIdx = 30;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(17) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_P.Gimbal_State_hold_Y0
	  section.data(1).logicalSrcIdx = 31;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(18) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_P.hold_Y0
	  section.data(1).logicalSrcIdx = 32;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(19) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_P.Simulation_Control_hold_Y0
	  section.data(1).logicalSrcIdx = 33;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(20) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_P.External_Inputs_hold_Y0
	  section.data(1).logicalSrcIdx = 34;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(21) = section;
      clear section
      
      section.nData     = 153;
      section.data(153)  = dumData; %prealloc
      
	  ;% GRM_HIL_P.Constant11_Value
	  section.data(1).logicalSrcIdx = 35;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GRM_HIL_P.Constant14_Value
	  section.data(2).logicalSrcIdx = 36;
	  section.data(2).dtTransOffset = 1;
	
	  ;% GRM_HIL_P.Constant7_Value
	  section.data(3).logicalSrcIdx = 37;
	  section.data(3).dtTransOffset = 2;
	
	  ;% GRM_HIL_P.Constant12_Value
	  section.data(4).logicalSrcIdx = 38;
	  section.data(4).dtTransOffset = 3;
	
	  ;% GRM_HIL_P.Constant9_Value
	  section.data(5).logicalSrcIdx = 39;
	  section.data(5).dtTransOffset = 4;
	
	  ;% GRM_HIL_P.Constant13_Value
	  section.data(6).logicalSrcIdx = 40;
	  section.data(6).dtTransOffset = 5;
	
	  ;% GRM_HIL_P.Constant_Value
	  section.data(7).logicalSrcIdx = 41;
	  section.data(7).dtTransOffset = 6;
	
	  ;% GRM_HIL_P.Constant3_Value
	  section.data(8).logicalSrcIdx = 42;
	  section.data(8).dtTransOffset = 7;
	
	  ;% GRM_HIL_P.Gain2_Gain
	  section.data(9).logicalSrcIdx = 43;
	  section.data(9).dtTransOffset = 8;
	
	  ;% GRM_HIL_P.Gain3_Gain
	  section.data(10).logicalSrcIdx = 44;
	  section.data(10).dtTransOffset = 9;
	
	  ;% GRM_HIL_P.acc_x_drag_mDs2_Y0
	  section.data(11).logicalSrcIdx = 45;
	  section.data(11).dtTransOffset = 10;
	
	  ;% GRM_HIL_P.acc_y_drag_mDs2_Y0
	  section.data(12).logicalSrcIdx = 46;
	  section.data(12).dtTransOffset = 11;
	
	  ;% GRM_HIL_P.acc_z_drag_mDs2_Y0
	  section.data(13).logicalSrcIdx = 47;
	  section.data(13).dtTransOffset = 12;
	
	  ;% GRM_HIL_P.Constant_Value_d
	  section.data(14).logicalSrcIdx = 48;
	  section.data(14).dtTransOffset = 13;
	
	  ;% GRM_HIL_P.Constant1_Value
	  section.data(15).logicalSrcIdx = 49;
	  section.data(15).dtTransOffset = 14;
	
	  ;% GRM_HIL_P.Constant2_Value
	  section.data(16).logicalSrcIdx = 50;
	  section.data(16).dtTransOffset = 15;
	
	  ;% GRM_HIL_P.acc_x_grav_mDs_Y0
	  section.data(17).logicalSrcIdx = 51;
	  section.data(17).dtTransOffset = 16;
	
	  ;% GRM_HIL_P.acc_y_grav_mDs_Y0
	  section.data(18).logicalSrcIdx = 52;
	  section.data(18).dtTransOffset = 17;
	
	  ;% GRM_HIL_P.acc_z_grav_mDs_Y0
	  section.data(19).logicalSrcIdx = 53;
	  section.data(19).dtTransOffset = 18;
	
	  ;% GRM_HIL_P.thrust_Y0
	  section.data(20).logicalSrcIdx = 54;
	  section.data(20).dtTransOffset = 19;
	
	  ;% GRM_HIL_P.state_percentage_change_Y0
	  section.data(21).logicalSrcIdx = 55;
	  section.data(21).dtTransOffset = 20;
	
	  ;% GRM_HIL_P.Constant2_Value_d
	  section.data(22).logicalSrcIdx = 56;
	  section.data(22).dtTransOffset = 21;
	
	  ;% GRM_HIL_P.exec_time_hold_s_Y0
	  section.data(23).logicalSrcIdx = 57;
	  section.data(23).dtTransOffset = 22;
	
	  ;% GRM_HIL_P.motor_state_perc_dot_Y0
	  section.data(24).logicalSrcIdx = 58;
	  section.data(24).dtTransOffset = 23;
	
	  ;% GRM_HIL_P.Step_Y0
	  section.data(25).logicalSrcIdx = 59;
	  section.data(25).dtTransOffset = 24;
	
	  ;% GRM_HIL_P.Step_YFinal
	  section.data(26).logicalSrcIdx = 60;
	  section.data(26).dtTransOffset = 25;
	
	  ;% GRM_HIL_P.Gain18_Gain
	  section.data(27).logicalSrcIdx = 61;
	  section.data(27).dtTransOffset = 26;
	
	  ;% GRM_HIL_P.Gain9_Gain
	  section.data(28).logicalSrcIdx = 62;
	  section.data(28).dtTransOffset = 27;
	
	  ;% GRM_HIL_P.Gain10_Gain
	  section.data(29).logicalSrcIdx = 63;
	  section.data(29).dtTransOffset = 28;
	
	  ;% GRM_HIL_P.Gain11_Gain
	  section.data(30).logicalSrcIdx = 64;
	  section.data(30).dtTransOffset = 29;
	
	  ;% GRM_HIL_P.Gain3_Gain_n
	  section.data(31).logicalSrcIdx = 65;
	  section.data(31).dtTransOffset = 30;
	
	  ;% GRM_HIL_P.Gain_Gain
	  section.data(32).logicalSrcIdx = 66;
	  section.data(32).dtTransOffset = 31;
	
	  ;% GRM_HIL_P.Gain1_Gain
	  section.data(33).logicalSrcIdx = 67;
	  section.data(33).dtTransOffset = 32;
	
	  ;% GRM_HIL_P.Gain2_Gain_g
	  section.data(34).logicalSrcIdx = 68;
	  section.data(34).dtTransOffset = 33;
	
	  ;% GRM_HIL_P.Gain3_Gain_d
	  section.data(35).logicalSrcIdx = 69;
	  section.data(35).dtTransOffset = 34;
	
	  ;% GRM_HIL_P.Gain2_Gain_a
	  section.data(36).logicalSrcIdx = 70;
	  section.data(36).dtTransOffset = 35;
	
	  ;% GRM_HIL_P.Gain4_Gain
	  section.data(37).logicalSrcIdx = 71;
	  section.data(37).dtTransOffset = 36;
	
	  ;% GRM_HIL_P.Gain1_Gain_n
	  section.data(38).logicalSrcIdx = 72;
	  section.data(38).dtTransOffset = 37;
	
	  ;% GRM_HIL_P.Gain5_Gain
	  section.data(39).logicalSrcIdx = 73;
	  section.data(39).dtTransOffset = 38;
	
	  ;% GRM_HIL_P.Gain9_Gain_b
	  section.data(40).logicalSrcIdx = 74;
	  section.data(40).dtTransOffset = 39;
	
	  ;% GRM_HIL_P.Gain10_Gain_f
	  section.data(41).logicalSrcIdx = 75;
	  section.data(41).dtTransOffset = 40;
	
	  ;% GRM_HIL_P.Gain11_Gain_d
	  section.data(42).logicalSrcIdx = 76;
	  section.data(42).dtTransOffset = 41;
	
	  ;% GRM_HIL_P.PulseGenerator1_Amp
	  section.data(43).logicalSrcIdx = 77;
	  section.data(43).dtTransOffset = 42;
	
	  ;% GRM_HIL_P.PulseGenerator1_Period
	  section.data(44).logicalSrcIdx = 78;
	  section.data(44).dtTransOffset = 43;
	
	  ;% GRM_HIL_P.PulseGenerator1_Duty
	  section.data(45).logicalSrcIdx = 79;
	  section.data(45).dtTransOffset = 44;
	
	  ;% GRM_HIL_P.PulseGenerator1_PhaseDelay
	  section.data(46).logicalSrcIdx = 80;
	  section.data(46).dtTransOffset = 45;
	
	  ;% GRM_HIL_P.PulseGenerator_Period
	  section.data(47).logicalSrcIdx = 81;
	  section.data(47).dtTransOffset = 46;
	
	  ;% GRM_HIL_P.PulseGenerator_Duty
	  section.data(48).logicalSrcIdx = 82;
	  section.data(48).dtTransOffset = 47;
	
	  ;% GRM_HIL_P.PulseGenerator_PhaseDelay
	  section.data(49).logicalSrcIdx = 83;
	  section.data(49).dtTransOffset = 48;
	
	  ;% GRM_HIL_P.Switch1_Threshold
	  section.data(50).logicalSrcIdx = 84;
	  section.data(50).dtTransOffset = 49;
	
	  ;% GRM_HIL_P.PulseGenerator4_Amp
	  section.data(51).logicalSrcIdx = 85;
	  section.data(51).dtTransOffset = 50;
	
	  ;% GRM_HIL_P.PulseGenerator4_Period
	  section.data(52).logicalSrcIdx = 86;
	  section.data(52).dtTransOffset = 51;
	
	  ;% GRM_HIL_P.PulseGenerator4_Duty
	  section.data(53).logicalSrcIdx = 87;
	  section.data(53).dtTransOffset = 52;
	
	  ;% GRM_HIL_P.PulseGenerator4_PhaseDelay
	  section.data(54).logicalSrcIdx = 88;
	  section.data(54).dtTransOffset = 53;
	
	  ;% GRM_HIL_P.PulseGenerator3_Period
	  section.data(55).logicalSrcIdx = 89;
	  section.data(55).dtTransOffset = 54;
	
	  ;% GRM_HIL_P.PulseGenerator3_Duty
	  section.data(56).logicalSrcIdx = 90;
	  section.data(56).dtTransOffset = 55;
	
	  ;% GRM_HIL_P.PulseGenerator3_PhaseDelay
	  section.data(57).logicalSrcIdx = 91;
	  section.data(57).dtTransOffset = 56;
	
	  ;% GRM_HIL_P.Switch_Threshold
	  section.data(58).logicalSrcIdx = 92;
	  section.data(58).dtTransOffset = 57;
	
	  ;% GRM_HIL_P.PulseGenerator7_Amp
	  section.data(59).logicalSrcIdx = 93;
	  section.data(59).dtTransOffset = 58;
	
	  ;% GRM_HIL_P.PulseGenerator7_Period
	  section.data(60).logicalSrcIdx = 94;
	  section.data(60).dtTransOffset = 59;
	
	  ;% GRM_HIL_P.PulseGenerator7_Duty
	  section.data(61).logicalSrcIdx = 95;
	  section.data(61).dtTransOffset = 60;
	
	  ;% GRM_HIL_P.PulseGenerator7_PhaseDelay
	  section.data(62).logicalSrcIdx = 96;
	  section.data(62).dtTransOffset = 61;
	
	  ;% GRM_HIL_P.PulseGenerator6_Period
	  section.data(63).logicalSrcIdx = 97;
	  section.data(63).dtTransOffset = 62;
	
	  ;% GRM_HIL_P.PulseGenerator6_Duty
	  section.data(64).logicalSrcIdx = 98;
	  section.data(64).dtTransOffset = 63;
	
	  ;% GRM_HIL_P.PulseGenerator6_PhaseDelay
	  section.data(65).logicalSrcIdx = 99;
	  section.data(65).dtTransOffset = 64;
	
	  ;% GRM_HIL_P.Switch2_Threshold
	  section.data(66).logicalSrcIdx = 100;
	  section.data(66).dtTransOffset = 65;
	
	  ;% GRM_HIL_P.Gain6_Gain
	  section.data(67).logicalSrcIdx = 101;
	  section.data(67).dtTransOffset = 66;
	
	  ;% GRM_HIL_P.Gain7_Gain
	  section.data(68).logicalSrcIdx = 102;
	  section.data(68).dtTransOffset = 67;
	
	  ;% GRM_HIL_P.Gain8_Gain
	  section.data(69).logicalSrcIdx = 103;
	  section.data(69).dtTransOffset = 68;
	
	  ;% GRM_HIL_P.TransferFcn1_A
	  section.data(70).logicalSrcIdx = 104;
	  section.data(70).dtTransOffset = 69;
	
	  ;% GRM_HIL_P.TransferFcn1_C
	  section.data(71).logicalSrcIdx = 105;
	  section.data(71).dtTransOffset = 71;
	
	  ;% GRM_HIL_P.Constant2_Value_h
	  section.data(72).logicalSrcIdx = 106;
	  section.data(72).dtTransOffset = 73;
	
	  ;% GRM_HIL_P.Constant1_Value_b
	  section.data(73).logicalSrcIdx = 107;
	  section.data(73).dtTransOffset = 74;
	
	  ;% GRM_HIL_P.Constant2_Value_c
	  section.data(74).logicalSrcIdx = 108;
	  section.data(74).dtTransOffset = 75;
	
	  ;% GRM_HIL_P.Memory1_1_InitialCondition
	  section.data(75).logicalSrcIdx = 109;
	  section.data(75).dtTransOffset = 76;
	
	  ;% GRM_HIL_P.Shaft2degYaw_Gain
	  section.data(76).logicalSrcIdx = 110;
	  section.data(76).dtTransOffset = 77;
	
	  ;% GRM_HIL_P.TransportDelay_InitOutput
	  section.data(77).logicalSrcIdx = 111;
	  section.data(77).dtTransOffset = 78;
	
	  ;% GRM_HIL_P.Memory1_2_InitialCondition
	  section.data(78).logicalSrcIdx = 112;
	  section.data(78).dtTransOffset = 79;
	
	  ;% GRM_HIL_P.Shaft2degPitch_Gain
	  section.data(79).logicalSrcIdx = 113;
	  section.data(79).dtTransOffset = 80;
	
	  ;% GRM_HIL_P.TransportDelay_InitOutput_j
	  section.data(80).logicalSrcIdx = 114;
	  section.data(80).dtTransOffset = 81;
	
	  ;% GRM_HIL_P.Memory1_3_InitialCondition
	  section.data(81).logicalSrcIdx = 115;
	  section.data(81).dtTransOffset = 82;
	
	  ;% GRM_HIL_P.Shaft2degRoll_Gain
	  section.data(82).logicalSrcIdx = 116;
	  section.data(82).dtTransOffset = 83;
	
	  ;% GRM_HIL_P.TransportDelay_InitOutput_g
	  section.data(83).logicalSrcIdx = 117;
	  section.data(83).dtTransOffset = 84;
	
	  ;% GRM_HIL_P.Constant2_Value_o
	  section.data(84).logicalSrcIdx = 118;
	  section.data(84).dtTransOffset = 85;
	
	  ;% GRM_HIL_P.Switch2_Threshold_l
	  section.data(85).logicalSrcIdx = 119;
	  section.data(85).dtTransOffset = 86;
	
	  ;% GRM_HIL_P.Gain_Gain_a
	  section.data(86).logicalSrcIdx = 120;
	  section.data(86).dtTransOffset = 87;
	
	  ;% GRM_HIL_P.Switch1_Threshold_k
	  section.data(87).logicalSrcIdx = 121;
	  section.data(87).dtTransOffset = 88;
	
	  ;% GRM_HIL_P.rad2deg_Gain
	  section.data(88).logicalSrcIdx = 122;
	  section.data(88).dtTransOffset = 89;
	
	  ;% GRM_HIL_P.Integrator_IC
	  section.data(89).logicalSrcIdx = 123;
	  section.data(89).dtTransOffset = 90;
	
	  ;% GRM_HIL_P.Filter_IC
	  section.data(90).logicalSrcIdx = 124;
	  section.data(90).dtTransOffset = 91;
	
	  ;% GRM_HIL_P.Merge_InitialOutput
	  section.data(91).logicalSrcIdx = 125;
	  section.data(91).dtTransOffset = 92;
	
	  ;% GRM_HIL_P.Merge_InitialOutput_d
	  section.data(92).logicalSrcIdx = 126;
	  section.data(92).dtTransOffset = 93;
	
	  ;% GRM_HIL_P.Constant2_Value_h5
	  section.data(93).logicalSrcIdx = 127;
	  section.data(93).dtTransOffset = 94;
	
	  ;% GRM_HIL_P.Switch2_Threshold_k
	  section.data(94).logicalSrcIdx = 128;
	  section.data(94).dtTransOffset = 95;
	
	  ;% GRM_HIL_P.Gain_Gain_g
	  section.data(95).logicalSrcIdx = 129;
	  section.data(95).dtTransOffset = 96;
	
	  ;% GRM_HIL_P.Switch1_Threshold_g
	  section.data(96).logicalSrcIdx = 130;
	  section.data(96).dtTransOffset = 97;
	
	  ;% GRM_HIL_P.rad2deg1_Gain
	  section.data(97).logicalSrcIdx = 131;
	  section.data(97).dtTransOffset = 98;
	
	  ;% GRM_HIL_P.Integrator_IC_c
	  section.data(98).logicalSrcIdx = 132;
	  section.data(98).dtTransOffset = 99;
	
	  ;% GRM_HIL_P.Filter_IC_c
	  section.data(99).logicalSrcIdx = 133;
	  section.data(99).dtTransOffset = 100;
	
	  ;% GRM_HIL_P.Merge_InitialOutput_a
	  section.data(100).logicalSrcIdx = 134;
	  section.data(100).dtTransOffset = 101;
	
	  ;% GRM_HIL_P.Constant2_Value_ht
	  section.data(101).logicalSrcIdx = 135;
	  section.data(101).dtTransOffset = 102;
	
	  ;% GRM_HIL_P.Switch2_Threshold_i
	  section.data(102).logicalSrcIdx = 136;
	  section.data(102).dtTransOffset = 103;
	
	  ;% GRM_HIL_P.Gain_Gain_p
	  section.data(103).logicalSrcIdx = 137;
	  section.data(103).dtTransOffset = 104;
	
	  ;% GRM_HIL_P.Switch1_Threshold_m
	  section.data(104).logicalSrcIdx = 138;
	  section.data(104).dtTransOffset = 105;
	
	  ;% GRM_HIL_P.rad2deg2_Gain
	  section.data(105).logicalSrcIdx = 139;
	  section.data(105).dtTransOffset = 106;
	
	  ;% GRM_HIL_P.Integrator_IC_m
	  section.data(106).logicalSrcIdx = 140;
	  section.data(106).dtTransOffset = 107;
	
	  ;% GRM_HIL_P.Filter_IC_d
	  section.data(107).logicalSrcIdx = 141;
	  section.data(107).dtTransOffset = 108;
	
	  ;% GRM_HIL_P.Merge_InitialOutput_j
	  section.data(108).logicalSrcIdx = 142;
	  section.data(108).dtTransOffset = 109;
	
	  ;% GRM_HIL_P.Merge_InitialOutput_a0
	  section.data(109).logicalSrcIdx = 143;
	  section.data(109).dtTransOffset = 110;
	
	  ;% GRM_HIL_P.Merge1_InitialOutput
	  section.data(110).logicalSrcIdx = 144;
	  section.data(110).dtTransOffset = 111;
	
	  ;% GRM_HIL_P.Shaft2radRoll_Gain
	  section.data(111).logicalSrcIdx = 145;
	  section.data(111).dtTransOffset = 112;
	
	  ;% GRM_HIL_P.Merge2_InitialOutput
	  section.data(112).logicalSrcIdx = 146;
	  section.data(112).dtTransOffset = 113;
	
	  ;% GRM_HIL_P.Shaft2radPitch_Gain
	  section.data(113).logicalSrcIdx = 147;
	  section.data(113).dtTransOffset = 114;
	
	  ;% GRM_HIL_P.Shaft2radYaw_Gain
	  section.data(114).logicalSrcIdx = 148;
	  section.data(114).dtTransOffset = 115;
	
	  ;% GRM_HIL_P.u2_Gain
	  section.data(115).logicalSrcIdx = 149;
	  section.data(115).dtTransOffset = 116;
	
	  ;% GRM_HIL_P.Constant_Value_k
	  section.data(116).logicalSrcIdx = 150;
	  section.data(116).dtTransOffset = 117;
	
	  ;% GRM_HIL_P.Constant1_Value_h
	  section.data(117).logicalSrcIdx = 151;
	  section.data(117).dtTransOffset = 118;
	
	  ;% GRM_HIL_P.Constant2_Value_e
	  section.data(118).logicalSrcIdx = 152;
	  section.data(118).dtTransOffset = 119;
	
	  ;% GRM_HIL_P.Constant3_Value_p
	  section.data(119).logicalSrcIdx = 153;
	  section.data(119).dtTransOffset = 120;
	
	  ;% GRM_HIL_P.Constant4_Value
	  section.data(120).logicalSrcIdx = 154;
	  section.data(120).dtTransOffset = 121;
	
	  ;% GRM_HIL_P.Constant5_Value
	  section.data(121).logicalSrcIdx = 155;
	  section.data(121).dtTransOffset = 122;
	
	  ;% GRM_HIL_P.Constant6_Value
	  section.data(122).logicalSrcIdx = 156;
	  section.data(122).dtTransOffset = 123;
	
	  ;% GRM_HIL_P.Constant7_Value_e
	  section.data(123).logicalSrcIdx = 157;
	  section.data(123).dtTransOffset = 124;
	
	  ;% GRM_HIL_P.Constant8_Value
	  section.data(124).logicalSrcIdx = 158;
	  section.data(124).dtTransOffset = 125;
	
	  ;% GRM_HIL_P.Constant9_Value_g
	  section.data(125).logicalSrcIdx = 159;
	  section.data(125).dtTransOffset = 126;
	
	  ;% GRM_HIL_P.Constant10_Value
	  section.data(126).logicalSrcIdx = 160;
	  section.data(126).dtTransOffset = 127;
	
	  ;% GRM_HIL_P.Constant11_Value_c
	  section.data(127).logicalSrcIdx = 161;
	  section.data(127).dtTransOffset = 128;
	
	  ;% GRM_HIL_P.Constant1_Value_a
	  section.data(128).logicalSrcIdx = 162;
	  section.data(128).dtTransOffset = 129;
	
	  ;% GRM_HIL_P.Constant10_Value_l
	  section.data(129).logicalSrcIdx = 163;
	  section.data(129).dtTransOffset = 130;
	
	  ;% GRM_HIL_P.Constant2_Value_a
	  section.data(130).logicalSrcIdx = 164;
	  section.data(130).dtTransOffset = 131;
	
	  ;% GRM_HIL_P.Memory_InitialCondition
	  section.data(131).logicalSrcIdx = 165;
	  section.data(131).dtTransOffset = 132;
	
	  ;% GRM_HIL_P.Gain2_Gain_b
	  section.data(132).logicalSrcIdx = 166;
	  section.data(132).dtTransOffset = 133;
	
	  ;% GRM_HIL_P.Gain_Gain_e
	  section.data(133).logicalSrcIdx = 167;
	  section.data(133).dtTransOffset = 134;
	
	  ;% GRM_HIL_P.Gain1_Gain_c
	  section.data(134).logicalSrcIdx = 168;
	  section.data(134).dtTransOffset = 135;
	
	  ;% GRM_HIL_P.Gain_Gain_d
	  section.data(135).logicalSrcIdx = 169;
	  section.data(135).dtTransOffset = 136;
	
	  ;% GRM_HIL_P.Gain_Gain_k
	  section.data(136).logicalSrcIdx = 170;
	  section.data(136).dtTransOffset = 137;
	
	  ;% GRM_HIL_P.Gain1_Gain_i
	  section.data(137).logicalSrcIdx = 171;
	  section.data(137).dtTransOffset = 138;
	
	  ;% GRM_HIL_P.Gain1_Gain_b
	  section.data(138).logicalSrcIdx = 172;
	  section.data(138).dtTransOffset = 139;
	
	  ;% GRM_HIL_P.Gain2_Gain_l
	  section.data(139).logicalSrcIdx = 173;
	  section.data(139).dtTransOffset = 140;
	
	  ;% GRM_HIL_P.Gain2_Gain_e
	  section.data(140).logicalSrcIdx = 174;
	  section.data(140).dtTransOffset = 141;
	
	  ;% GRM_HIL_P.Constant_Value_n
	  section.data(141).logicalSrcIdx = 175;
	  section.data(141).dtTransOffset = 142;
	
	  ;% GRM_HIL_P.Constant7_Value_e5
	  section.data(142).logicalSrcIdx = 176;
	  section.data(142).dtTransOffset = 143;
	
	  ;% GRM_HIL_P.Gain_Gain_o
	  section.data(143).logicalSrcIdx = 177;
	  section.data(143).dtTransOffset = 144;
	
	  ;% GRM_HIL_P.Constant_Value_p
	  section.data(144).logicalSrcIdx = 178;
	  section.data(144).dtTransOffset = 145;
	
	  ;% GRM_HIL_P.Constant_Value_l
	  section.data(145).logicalSrcIdx = 179;
	  section.data(145).dtTransOffset = 146;
	
	  ;% GRM_HIL_P.Constant_Value_lt
	  section.data(146).logicalSrcIdx = 180;
	  section.data(146).dtTransOffset = 147;
	
	  ;% GRM_HIL_P.Gain12_Gain
	  section.data(147).logicalSrcIdx = 181;
	  section.data(147).dtTransOffset = 148;
	
	  ;% GRM_HIL_P.Gain13_Gain
	  section.data(148).logicalSrcIdx = 182;
	  section.data(148).dtTransOffset = 149;
	
	  ;% GRM_HIL_P.Gain14_Gain
	  section.data(149).logicalSrcIdx = 183;
	  section.data(149).dtTransOffset = 150;
	
	  ;% GRM_HIL_P.Gain15_Gain
	  section.data(150).logicalSrcIdx = 184;
	  section.data(150).dtTransOffset = 151;
	
	  ;% GRM_HIL_P.Gain16_Gain
	  section.data(151).logicalSrcIdx = 185;
	  section.data(151).dtTransOffset = 152;
	
	  ;% GRM_HIL_P.Gain17_Gain
	  section.data(152).logicalSrcIdx = 186;
	  section.data(152).dtTransOffset = 153;
	
	  ;% GRM_HIL_P.Gain_Gain_kk
	  section.data(153).logicalSrcIdx = 187;
	  section.data(153).dtTransOffset = 154;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(22) = section;
      clear section
      
      section.nData     = 17;
      section.data(17)  = dumData; %prealloc
      
	  ;% GRM_HIL_P.Constant10_Value_c
	  section.data(1).logicalSrcIdx = 188;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GRM_HIL_P.Constant6_Value_b
	  section.data(2).logicalSrcIdx = 189;
	  section.data(2).dtTransOffset = 1;
	
	  ;% GRM_HIL_P.Constant8_Value_e
	  section.data(3).logicalSrcIdx = 190;
	  section.data(3).dtTransOffset = 2;
	
	  ;% GRM_HIL_P.lock_InitialCondition
	  section.data(4).logicalSrcIdx = 191;
	  section.data(4).dtTransOffset = 3;
	
	  ;% GRM_HIL_P.Constant4_Value_g
	  section.data(5).logicalSrcIdx = 192;
	  section.data(5).dtTransOffset = 4;
	
	  ;% GRM_HIL_P.Constant2_Value_f
	  section.data(6).logicalSrcIdx = 193;
	  section.data(6).dtTransOffset = 5;
	
	  ;% GRM_HIL_P.Constant6_Value_k
	  section.data(7).logicalSrcIdx = 194;
	  section.data(7).dtTransOffset = 6;
	
	  ;% GRM_HIL_P.Constant5_Value_k
	  section.data(8).logicalSrcIdx = 195;
	  section.data(8).dtTransOffset = 7;
	
	  ;% GRM_HIL_P.Memory_1_InitialCondition
	  section.data(9).logicalSrcIdx = 196;
	  section.data(9).dtTransOffset = 8;
	
	  ;% GRM_HIL_P.Memory_2_InitialCondition
	  section.data(10).logicalSrcIdx = 197;
	  section.data(10).dtTransOffset = 9;
	
	  ;% GRM_HIL_P.Constant1_Value_f
	  section.data(11).logicalSrcIdx = 198;
	  section.data(11).dtTransOffset = 10;
	
	  ;% GRM_HIL_P.Constant1_Value_m
	  section.data(12).logicalSrcIdx = 199;
	  section.data(12).dtTransOffset = 11;
	
	  ;% GRM_HIL_P.Constant1_Value_j
	  section.data(13).logicalSrcIdx = 200;
	  section.data(13).dtTransOffset = 12;
	
	  ;% GRM_HIL_P.Constant_Value_g
	  section.data(14).logicalSrcIdx = 201;
	  section.data(14).dtTransOffset = 13;
	
	  ;% GRM_HIL_P.Constant1_Value_c
	  section.data(15).logicalSrcIdx = 202;
	  section.data(15).dtTransOffset = 14;
	
	  ;% GRM_HIL_P.Constant9_Value_b
	  section.data(16).logicalSrcIdx = 203;
	  section.data(16).dtTransOffset = 15;
	
	  ;% GRM_HIL_P.Constant3_Value_i
	  section.data(17).logicalSrcIdx = 204;
	  section.data(17).dtTransOffset = 16;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(23) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_P.IfActionSubsystem_m.Out1_Y0
	  section.data(1).logicalSrcIdx = 205;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(24) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_P.IfActionSubsystem1_e.Out1_Y0
	  section.data(1).logicalSrcIdx = 206;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(25) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_P.IfActionSubsystem_p.Out1_Y0
	  section.data(1).logicalSrcIdx = 207;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(26) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_P.IfActionSubsystem1_j.Out1_Y0
	  section.data(1).logicalSrcIdx = 208;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(27) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_P.IfActionSubsystem.Out1_Y0
	  section.data(1).logicalSrcIdx = 209;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(28) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_P.IfActionSubsystem1.Out1_Y0
	  section.data(1).logicalSrcIdx = 210;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(29) = section;
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
    nTotSects     = 8;
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
    ;% Auto data (GRM_HIL_B)
    ;%
      section.nData     = 189;
      section.data(189)  = dumData; %prealloc
      
	  ;% GRM_HIL_B.motor_state_perc
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GRM_HIL_B.ATT_Phi_rad
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% GRM_HIL_B.ATT_Theta_rad
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% GRM_HIL_B.ATT_Psi_rad
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% GRM_HIL_B.ACC_x_B_mDs2
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% GRM_HIL_B.Gain2
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% GRM_HIL_B.ACC_y_B_mDs2
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% GRM_HIL_B.Gain1
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% GRM_HIL_B.ACC_z_B_mDs2
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% GRM_HIL_B.ATT_Phi_rad_l
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% GRM_HIL_B.ATT_Theta_rad_k
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% GRM_HIL_B.ATT_Psi_rad_j
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% GRM_HIL_B.Switch1
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% GRM_HIL_B.Switch
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% GRM_HIL_B.Switch2
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% GRM_HIL_B.w_x_K_IB_B_radDs
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% GRM_HIL_B.w_y_K_IB_B_radDs
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% GRM_HIL_B.w_z_K_IB_B_radDs
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% GRM_HIL_B.Gimbal_operational_flg
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% GRM_HIL_B.Gimbal_Ramp_flg
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% GRM_HIL_B.Gimbal_Limit_flg
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 20;
	
	  ;% GRM_HIL_B.Gimbal_StopSim_flg
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 21;
	
	  ;% GRM_HIL_B.yaw_deg
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 22;
	
	  ;% GRM_HIL_B.Gain
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 23;
	
	  ;% GRM_HIL_B.pitch_deg
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 24;
	
	  ;% GRM_HIL_B.Gain_h
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 25;
	
	  ;% GRM_HIL_B.roll_deg
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 26;
	
	  ;% GRM_HIL_B.Gain_j
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 27;
	
	  ;% GRM_HIL_B.Merge
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 28;
	
	  ;% GRM_HIL_B.Switch2_p
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 29;
	
	  ;% GRM_HIL_B.Gain_e
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 30;
	
	  ;% GRM_HIL_B.Merge1
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 31;
	
	  ;% GRM_HIL_B.Switch1_h
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 32;
	
	  ;% GRM_HIL_B.Gimbal_Phi_Cmd_deg
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 33;
	
	  ;% GRM_HIL_B.Product
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 34;
	
	  ;% GRM_HIL_B.Yaw_err
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 35;
	
	  ;% GRM_HIL_B.Integrator
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 36;
	
	  ;% GRM_HIL_B.Filter
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 37;
	
	  ;% GRM_HIL_B.FilterCoefficient
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 38;
	
	  ;% GRM_HIL_B.Merge_f
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 39;
	
	  ;% GRM_HIL_B.Merge_a
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 40;
	
	  ;% GRM_HIL_B.Merge_m
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 41;
	
	  ;% GRM_HIL_B.Switch2_h
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 42;
	
	  ;% GRM_HIL_B.Gain_hi
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 43;
	
	  ;% GRM_HIL_B.Merge1_j
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 44;
	
	  ;% GRM_HIL_B.Switch1_f
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 45;
	
	  ;% GRM_HIL_B.Gimbal_Theta_Cmd_deg
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 46;
	
	  ;% GRM_HIL_B.pitch_cmd
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 47;
	
	  ;% GRM_HIL_B.pitch_err
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 48;
	
	  ;% GRM_HIL_B.Integrator_o
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 49;
	
	  ;% GRM_HIL_B.Filter_m
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 50;
	
	  ;% GRM_HIL_B.FilterCoefficient_a
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 51;
	
	  ;% GRM_HIL_B.Merge_fu
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 52;
	
	  ;% GRM_HIL_B.Merge_h
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 53;
	
	  ;% GRM_HIL_B.Switch2_i
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 54;
	
	  ;% GRM_HIL_B.Gain_l
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 55;
	
	  ;% GRM_HIL_B.Merge1_k
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 56;
	
	  ;% GRM_HIL_B.Switch1_l
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 57;
	
	  ;% GRM_HIL_B.Gimbal_Psi_Cmd_deg
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 58;
	
	  ;% GRM_HIL_B.Product1
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 59;
	
	  ;% GRM_HIL_B.Roll_err
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 60;
	
	  ;% GRM_HIL_B.Integrator_a
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 61;
	
	  ;% GRM_HIL_B.Filter_n
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 62;
	
	  ;% GRM_HIL_B.FilterCoefficient_l
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 63;
	
	  ;% GRM_HIL_B.Merge_c
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 64;
	
	  ;% GRM_HIL_B.Merge_o
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 65;
	
	  ;% GRM_HIL_B.Merge1_o
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 66;
	
	  ;% GRM_HIL_B.Sum2
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 67;
	
	  ;% GRM_HIL_B.ATT_Phi_rad_a
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 68;
	
	  ;% GRM_HIL_B.Merge2
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 69;
	
	  ;% GRM_HIL_B.Sum1
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 70;
	
	  ;% GRM_HIL_B.ATT_Theta_rad_i
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 71;
	
	  ;% GRM_HIL_B.Sum
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 72;
	
	  ;% GRM_HIL_B.ATT_Psi_rad_g
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 73;
	
	  ;% GRM_HIL_B.q0
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 74;
	
	  ;% GRM_HIL_B.q1
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 75;
	
	  ;% GRM_HIL_B.q2
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 76;
	
	  ;% GRM_HIL_B.q3
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 77;
	
	  ;% GRM_HIL_B.Data_plus
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 78;
	
	  ;% GRM_HIL_B.Data_minus
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 79;
	
	  ;% GRM_HIL_B.Clock_plus
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 80;
	
	  ;% GRM_HIL_B.Clock_minus
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 81;
	
	  ;% GRM_HIL_B.Data_plus_a
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 82;
	
	  ;% GRM_HIL_B.Data_minus_k
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 83;
	
	  ;% GRM_HIL_B.Clock_plus_c
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 84;
	
	  ;% GRM_HIL_B.Clock_minus_i
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 85;
	
	  ;% GRM_HIL_B.Data_plus_k
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 86;
	
	  ;% GRM_HIL_B.Data_minus_kw
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 87;
	
	  ;% GRM_HIL_B.Clock_plus_b
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 88;
	
	  ;% GRM_HIL_B.Clock_minus_g
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 89;
	
	  ;% GRM_HIL_B.phi_rad
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 90;
	
	  ;% GRM_HIL_B.Gain_a
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 91;
	
	  ;% GRM_HIL_B.Phi_Cmd_rad
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 92;
	
	  ;% GRM_HIL_B.acc_y_mDs2
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 93;
	
	  ;% GRM_HIL_B.Sum3
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 94;
	
	  ;% GRM_HIL_B.Psi_Cmd_rad
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 95;
	
	  ;% GRM_HIL_B.acc_z_mDs2
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 96;
	
	  ;% GRM_HIL_B.Sum1_d
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 97;
	
	  ;% GRM_HIL_B.Theta_Cmd_rad
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 98;
	
	  ;% GRM_HIL_B.Merge3
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 99;
	
	  ;% GRM_HIL_B.Fin_4_Cmd_rad
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 100;
	
	  ;% GRM_HIL_B.pulse_width_ms
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 101;
	
	  ;% GRM_HIL_B.Merge2_i
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 102;
	
	  ;% GRM_HIL_B.Fin_3_Cmd_rad
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 103;
	
	  ;% GRM_HIL_B.pulse_width_ms_e
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 104;
	
	  ;% GRM_HIL_B.Merge1_n
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 105;
	
	  ;% GRM_HIL_B.Fin_2_Cmd_rad
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 106;
	
	  ;% GRM_HIL_B.pulse_width_ms_c
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 107;
	
	  ;% GRM_HIL_B.Merge_n
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 108;
	
	  ;% GRM_HIL_B.Fin_1_Cmd_rad
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 109;
	
	  ;% GRM_HIL_B.pulse_width_ms_p
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 110;
	
	  ;% GRM_HIL_B.VEL_u_K_R_E_B_mDs
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 111;
	
	  ;% GRM_HIL_B.VEL_u_K_R_E_B_mDs_e
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 112;
	
	  ;% GRM_HIL_B.VEL_v_K_R_E_B_mDs
	  section.data(114).logicalSrcIdx = 113;
	  section.data(114).dtTransOffset = 113;
	
	  ;% GRM_HIL_B.VEL_v_K_R_E_B_mDs_e
	  section.data(115).logicalSrcIdx = 114;
	  section.data(115).dtTransOffset = 114;
	
	  ;% GRM_HIL_B.VEL_w_K_R_E_B_mDs
	  section.data(116).logicalSrcIdx = 115;
	  section.data(116).dtTransOffset = 115;
	
	  ;% GRM_HIL_B.VEL_w_K_R_E_B_mDs_d
	  section.data(117).logicalSrcIdx = 116;
	  section.data(117).dtTransOffset = 116;
	
	  ;% GRM_HIL_B.Saturation_o
	  section.data(118).logicalSrcIdx = 117;
	  section.data(118).dtTransOffset = 117;
	
	  ;% GRM_HIL_B.Saturation_c
	  section.data(119).logicalSrcIdx = 118;
	  section.data(119).dtTransOffset = 118;
	
	  ;% GRM_HIL_B.Saturation_jy
	  section.data(120).logicalSrcIdx = 119;
	  section.data(120).dtTransOffset = 119;
	
	  ;% GRM_HIL_B.Saturation_a
	  section.data(121).logicalSrcIdx = 120;
	  section.data(121).dtTransOffset = 120;
	
	  ;% GRM_HIL_B.SumI1
	  section.data(122).logicalSrcIdx = 121;
	  section.data(122).dtTransOffset = 121;
	
	  ;% GRM_HIL_B.SumI1_n
	  section.data(123).logicalSrcIdx = 122;
	  section.data(123).dtTransOffset = 122;
	
	  ;% GRM_HIL_B.SumI1_i
	  section.data(124).logicalSrcIdx = 123;
	  section.data(124).dtTransOffset = 123;
	
	  ;% GRM_HIL_B.DataTypeConversion
	  section.data(125).logicalSrcIdx = 124;
	  section.data(125).dtTransOffset = 124;
	
	  ;% GRM_HIL_B.Samp_freq
	  section.data(126).logicalSrcIdx = 125;
	  section.data(126).dtTransOffset = 125;
	
	  ;% GRM_HIL_B.POS_lambda_WGS84_rad
	  section.data(127).logicalSrcIdx = 126;
	  section.data(127).dtTransOffset = 126;
	
	  ;% GRM_HIL_B.POS_mue_WGS84_rad
	  section.data(128).logicalSrcIdx = 127;
	  section.data(128).dtTransOffset = 127;
	
	  ;% GRM_HIL_B.POS_h_WGS84_m
	  section.data(129).logicalSrcIdx = 128;
	  section.data(129).dtTransOffset = 128;
	
	  ;% GRM_HIL_B.POS_x_NED_m
	  section.data(130).logicalSrcIdx = 129;
	  section.data(130).dtTransOffset = 129;
	
	  ;% GRM_HIL_B.POS_y_NED_m
	  section.data(131).logicalSrcIdx = 130;
	  section.data(131).dtTransOffset = 130;
	
	  ;% GRM_HIL_B.POS_z_NED_m
	  section.data(132).logicalSrcIdx = 131;
	  section.data(132).dtTransOffset = 131;
	
	  ;% GRM_HIL_B.Gain_o
	  section.data(133).logicalSrcIdx = 132;
	  section.data(133).dtTransOffset = 132;
	
	  ;% GRM_HIL_B.DataTypeConversion_i
	  section.data(134).logicalSrcIdx = 133;
	  section.data(134).dtTransOffset = 133;
	
	  ;% GRM_HIL_B.Product_f
	  section.data(135).logicalSrcIdx = 134;
	  section.data(135).dtTransOffset = 134;
	
	  ;% GRM_HIL_B.Product1_j
	  section.data(136).logicalSrcIdx = 135;
	  section.data(136).dtTransOffset = 135;
	
	  ;% GRM_HIL_B.Product2
	  section.data(137).logicalSrcIdx = 136;
	  section.data(137).dtTransOffset = 136;
	
	  ;% GRM_HIL_B.DataTypeConversion_d
	  section.data(138).logicalSrcIdx = 137;
	  section.data(138).dtTransOffset = 137;
	
	  ;% GRM_HIL_B.Multiply
	  section.data(139).logicalSrcIdx = 138;
	  section.data(139).dtTransOffset = 138;
	
	  ;% GRM_HIL_B.DataTypeConversion_n
	  section.data(140).logicalSrcIdx = 139;
	  section.data(140).dtTransOffset = 139;
	
	  ;% GRM_HIL_B.Product_b
	  section.data(141).logicalSrcIdx = 140;
	  section.data(141).dtTransOffset = 140;
	
	  ;% GRM_HIL_B.Product1_f
	  section.data(142).logicalSrcIdx = 141;
	  section.data(142).dtTransOffset = 141;
	
	  ;% GRM_HIL_B.Product2_d
	  section.data(143).logicalSrcIdx = 142;
	  section.data(143).dtTransOffset = 142;
	
	  ;% GRM_HIL_B.DataTypeConversion_k
	  section.data(144).logicalSrcIdx = 143;
	  section.data(144).dtTransOffset = 143;
	
	  ;% GRM_HIL_B.Product_g
	  section.data(145).logicalSrcIdx = 144;
	  section.data(145).dtTransOffset = 144;
	
	  ;% GRM_HIL_B.Product1_g
	  section.data(146).logicalSrcIdx = 145;
	  section.data(146).dtTransOffset = 145;
	
	  ;% GRM_HIL_B.Product2_d1
	  section.data(147).logicalSrcIdx = 146;
	  section.data(147).dtTransOffset = 146;
	
	  ;% GRM_HIL_B.DataTypeConversion_e
	  section.data(148).logicalSrcIdx = 147;
	  section.data(148).dtTransOffset = 147;
	
	  ;% GRM_HIL_B.Product_p
	  section.data(149).logicalSrcIdx = 148;
	  section.data(149).dtTransOffset = 148;
	
	  ;% GRM_HIL_B.Product1_o
	  section.data(150).logicalSrcIdx = 149;
	  section.data(150).dtTransOffset = 149;
	
	  ;% GRM_HIL_B.Product2_n
	  section.data(151).logicalSrcIdx = 150;
	  section.data(151).dtTransOffset = 150;
	
	  ;% GRM_HIL_B.OutportBufferFormotor_state_perc_dot
	  section.data(152).logicalSrcIdx = 151;
	  section.data(152).dtTransOffset = 151;
	
	  ;% GRM_HIL_B.Clock
	  section.data(153).logicalSrcIdx = 152;
	  section.data(153).dtTransOffset = 152;
	
	  ;% GRM_HIL_B.OutportBufferForthrust
	  section.data(154).logicalSrcIdx = 153;
	  section.data(154).dtTransOffset = 153;
	
	  ;% GRM_HIL_B.Add1
	  section.data(155).logicalSrcIdx = 154;
	  section.data(155).dtTransOffset = 154;
	
	  ;% GRM_HIL_B.acc_x
	  section.data(156).logicalSrcIdx = 155;
	  section.data(156).dtTransOffset = 155;
	
	  ;% GRM_HIL_B.acc_y
	  section.data(157).logicalSrcIdx = 156;
	  section.data(157).dtTransOffset = 156;
	
	  ;% GRM_HIL_B.acc_z
	  section.data(158).logicalSrcIdx = 157;
	  section.data(158).dtTransOffset = 157;
	
	  ;% GRM_HIL_B.OutportBufferForacc_x_drag_mDs2
	  section.data(159).logicalSrcIdx = 158;
	  section.data(159).dtTransOffset = 158;
	
	  ;% GRM_HIL_B.OutportBufferForacc_y_drag_mDs2
	  section.data(160).logicalSrcIdx = 159;
	  section.data(160).dtTransOffset = 159;
	
	  ;% GRM_HIL_B.OutportBufferForacc_z_drag_mDs2
	  section.data(161).logicalSrcIdx = 160;
	  section.data(161).dtTransOffset = 160;
	
	  ;% GRM_HIL_B.Abs1
	  section.data(162).logicalSrcIdx = 161;
	  section.data(162).dtTransOffset = 161;
	
	  ;% GRM_HIL_B.Abs3
	  section.data(163).logicalSrcIdx = 162;
	  section.data(163).dtTransOffset = 162;
	
	  ;% GRM_HIL_B.Abs5
	  section.data(164).logicalSrcIdx = 163;
	  section.data(164).dtTransOffset = 163;
	
	  ;% GRM_HIL_B.Abs
	  section.data(165).logicalSrcIdx = 164;
	  section.data(165).dtTransOffset = 164;
	
	  ;% GRM_HIL_B.FilterCoefficient_f
	  section.data(166).logicalSrcIdx = 165;
	  section.data(166).dtTransOffset = 165;
	
	  ;% GRM_HIL_B.FilterCoefficient_j
	  section.data(167).logicalSrcIdx = 166;
	  section.data(167).dtTransOffset = 166;
	
	  ;% GRM_HIL_B.SumI4
	  section.data(168).logicalSrcIdx = 167;
	  section.data(168).dtTransOffset = 167;
	
	  ;% GRM_HIL_B.SumI4_c
	  section.data(169).logicalSrcIdx = 168;
	  section.data(169).dtTransOffset = 168;
	
	  ;% GRM_HIL_B.Abs_j
	  section.data(170).logicalSrcIdx = 169;
	  section.data(170).dtTransOffset = 169;
	
	  ;% GRM_HIL_B.Abs_b
	  section.data(171).logicalSrcIdx = 170;
	  section.data(171).dtTransOffset = 170;
	
	  ;% GRM_HIL_B.Fin_3_Cmd_rad_o
	  section.data(172).logicalSrcIdx = 171;
	  section.data(172).dtTransOffset = 171;
	
	  ;% GRM_HIL_B.Fin_4_Cmd_rad_c
	  section.data(173).logicalSrcIdx = 172;
	  section.data(173).dtTransOffset = 172;
	
	  ;% GRM_HIL_B.pulse_width_ms_p2
	  section.data(174).logicalSrcIdx = 173;
	  section.data(174).dtTransOffset = 173;
	
	  ;% GRM_HIL_B.pulse_width_ms_p2d
	  section.data(175).logicalSrcIdx = 174;
	  section.data(175).dtTransOffset = 174;
	
	  ;% GRM_HIL_B.pulse_width_ms_p2de
	  section.data(176).logicalSrcIdx = 175;
	  section.data(176).dtTransOffset = 175;
	
	  ;% GRM_HIL_B.pulse_width_ms_p2dee
	  section.data(177).logicalSrcIdx = 176;
	  section.data(177).dtTransOffset = 176;
	
	  ;% GRM_HIL_B.Fin_1_Cmd_rad_l
	  section.data(178).logicalSrcIdx = 177;
	  section.data(178).dtTransOffset = 177;
	
	  ;% GRM_HIL_B.Fin_2_Cmd_rad_e
	  section.data(179).logicalSrcIdx = 178;
	  section.data(179).dtTransOffset = 178;
	
	  ;% GRM_HIL_B.ATT_Phi_rad_f
	  section.data(180).logicalSrcIdx = 179;
	  section.data(180).dtTransOffset = 179;
	
	  ;% GRM_HIL_B.ACC_y_B_mDs2_o
	  section.data(181).logicalSrcIdx = 180;
	  section.data(181).dtTransOffset = 180;
	
	  ;% GRM_HIL_B.ACC_z_B_mDs2_e
	  section.data(182).logicalSrcIdx = 181;
	  section.data(182).dtTransOffset = 181;
	
	  ;% GRM_HIL_B.w_x_K_IB_B_radDs_f
	  section.data(183).logicalSrcIdx = 182;
	  section.data(183).dtTransOffset = 182;
	
	  ;% GRM_HIL_B.w_y_K_IB_B_radDs_e
	  section.data(184).logicalSrcIdx = 183;
	  section.data(184).dtTransOffset = 183;
	
	  ;% GRM_HIL_B.w_z_K_IB_B_radDs_n
	  section.data(185).logicalSrcIdx = 184;
	  section.data(185).dtTransOffset = 184;
	
	  ;% GRM_HIL_B.CMD_phi_rad
	  section.data(186).logicalSrcIdx = 185;
	  section.data(186).dtTransOffset = 185;
	
	  ;% GRM_HIL_B.CMD_acc_z_mDs2
	  section.data(187).logicalSrcIdx = 186;
	  section.data(187).dtTransOffset = 186;
	
	  ;% GRM_HIL_B.CMD_acc_y_mDs2
	  section.data(188).logicalSrcIdx = 187;
	  section.data(188).dtTransOffset = 187;
	
	  ;% GRM_HIL_B.value
	  section.data(189).logicalSrcIdx = 188;
	  section.data(189).dtTransOffset = 188;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 33;
      section.data(33)  = dumData; %prealloc
      
	  ;% GRM_HIL_B.LogicalOperator
	  section.data(1).logicalSrcIdx = 189;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GRM_HIL_B.HiddenBuf_InsertedFor_Enabledadapt_at_inport_3
	  section.data(2).logicalSrcIdx = 190;
	  section.data(2).dtTransOffset = 1;
	
	  ;% GRM_HIL_B.LogicalOperator1
	  section.data(3).logicalSrcIdx = 191;
	  section.data(3).dtTransOffset = 2;
	
	  ;% GRM_HIL_B.Switch_g
	  section.data(4).logicalSrcIdx = 192;
	  section.data(4).dtTransOffset = 3;
	
	  ;% GRM_HIL_B.HiddenBuf_InsertedFor_Saturation_at_inport_3
	  section.data(5).logicalSrcIdx = 193;
	  section.data(5).dtTransOffset = 4;
	
	  ;% GRM_HIL_B.LogicalOperator_o
	  section.data(6).logicalSrcIdx = 194;
	  section.data(6).dtTransOffset = 5;
	
	  ;% GRM_HIL_B.LogicalOperator_a
	  section.data(7).logicalSrcIdx = 196;
	  section.data(7).dtTransOffset = 6;
	
	  ;% GRM_HIL_B.HiddenBuf_InsertedFor_Enabledadapt_at_inport_3_h
	  section.data(8).logicalSrcIdx = 197;
	  section.data(8).dtTransOffset = 7;
	
	  ;% GRM_HIL_B.LogicalOperator1_i
	  section.data(9).logicalSrcIdx = 198;
	  section.data(9).dtTransOffset = 8;
	
	  ;% GRM_HIL_B.Switch_a
	  section.data(10).logicalSrcIdx = 199;
	  section.data(10).dtTransOffset = 9;
	
	  ;% GRM_HIL_B.HiddenBuf_InsertedFor_Saturation_at_inport_3_k
	  section.data(11).logicalSrcIdx = 200;
	  section.data(11).dtTransOffset = 10;
	
	  ;% GRM_HIL_B.LogicalOperator_n
	  section.data(12).logicalSrcIdx = 201;
	  section.data(12).dtTransOffset = 11;
	
	  ;% GRM_HIL_B.LogicalOperator_b
	  section.data(13).logicalSrcIdx = 202;
	  section.data(13).dtTransOffset = 12;
	
	  ;% GRM_HIL_B.HiddenBuf_InsertedFor_Enabledadapt_at_inport_3_hn
	  section.data(14).logicalSrcIdx = 203;
	  section.data(14).dtTransOffset = 13;
	
	  ;% GRM_HIL_B.LogicalOperator1_k
	  section.data(15).logicalSrcIdx = 204;
	  section.data(15).dtTransOffset = 14;
	
	  ;% GRM_HIL_B.Switch_p
	  section.data(16).logicalSrcIdx = 205;
	  section.data(16).dtTransOffset = 15;
	
	  ;% GRM_HIL_B.HiddenBuf_InsertedFor_Saturation_at_inport_3_kk
	  section.data(17).logicalSrcIdx = 206;
	  section.data(17).dtTransOffset = 16;
	
	  ;% GRM_HIL_B.LogicalOperator_p
	  section.data(18).logicalSrcIdx = 207;
	  section.data(18).dtTransOffset = 17;
	
	  ;% GRM_HIL_B.LogicalOperator_c
	  section.data(19).logicalSrcIdx = 208;
	  section.data(19).dtTransOffset = 18;
	
	  ;% GRM_HIL_B.Equal
	  section.data(20).logicalSrcIdx = 209;
	  section.data(20).dtTransOffset = 19;
	
	  ;% GRM_HIL_B.OR
	  section.data(21).logicalSrcIdx = 210;
	  section.data(21).dtTransOffset = 20;
	
	  ;% GRM_HIL_B.LogicalOperator_at
	  section.data(22).logicalSrcIdx = 211;
	  section.data(22).dtTransOffset = 21;
	
	  ;% GRM_HIL_B.HiddenBuf_InsertedFor_Pass_at_inport_4
	  section.data(23).logicalSrcIdx = 212;
	  section.data(23).dtTransOffset = 22;
	
	  ;% GRM_HIL_B.HiddenBuf_InsertedFor_Saturate_at_inport_5
	  section.data(24).logicalSrcIdx = 213;
	  section.data(24).dtTransOffset = 23;
	
	  ;% GRM_HIL_B.cmd_pass_enable_flg
	  section.data(25).logicalSrcIdx = 214;
	  section.data(25).dtTransOffset = 24;
	
	  ;% GRM_HIL_B.emergency_stop_flg
	  section.data(26).logicalSrcIdx = 215;
	  section.data(26).dtTransOffset = 25;
	
	  ;% GRM_HIL_B.LogicalOperator2
	  section.data(27).logicalSrcIdx = 216;
	  section.data(27).dtTransOffset = 26;
	
	  ;% GRM_HIL_B.lock
	  section.data(28).logicalSrcIdx = 218;
	  section.data(28).dtTransOffset = 27;
	
	  ;% GRM_HIL_B.LogicalOperator1_ii
	  section.data(29).logicalSrcIdx = 219;
	  section.data(29).dtTransOffset = 28;
	
	  ;% GRM_HIL_B.LogicalOperator_h
	  section.data(30).logicalSrcIdx = 220;
	  section.data(30).dtTransOffset = 29;
	
	  ;% GRM_HIL_B.HiddenBuf_InsertedFor_hold_time_at_inport_0
	  section.data(31).logicalSrcIdx = 221;
	  section.data(31).dtTransOffset = 30;
	
	  ;% GRM_HIL_B.LogicalOperator2_m
	  section.data(32).logicalSrcIdx = 222;
	  section.data(32).dtTransOffset = 31;
	
	  ;% GRM_HIL_B.HiddenBuf_InsertedFor_Subsystem_at_inport_1
	  section.data(33).logicalSrcIdx = 223;
	  section.data(33).dtTransOffset = 32;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_B.IfActionSubsystem_m.In1
	  section.data(1).logicalSrcIdx = 224;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_B.IfActionSubsystem1_e.In1
	  section.data(1).logicalSrcIdx = 225;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_B.IfActionSubsystem_p.In1
	  section.data(1).logicalSrcIdx = 226;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_B.IfActionSubsystem1_j.In1
	  section.data(1).logicalSrcIdx = 227;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_B.IfActionSubsystem.In1
	  section.data(1).logicalSrcIdx = 228;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_B.IfActionSubsystem1.In1
	  section.data(1).logicalSrcIdx = 229;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(8) = section;
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
    nTotSects     = 27;
    sectIdxOffset = 8;
    
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
    ;% Auto data (GRM_HIL_DW)
    ;%
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% GRM_HIL_DW.Memory1_1_PreviousInput
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GRM_HIL_DW.Memory1_2_PreviousInput
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% GRM_HIL_DW.Memory1_3_PreviousInput
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% GRM_HIL_DW.Memory_PreviousInput
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% GRM_HIL_DW.TransportDelay_RWORK.modelTStart
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% GRM_HIL_DW.TransportDelay_RWORK_l.modelTStart
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% GRM_HIL_DW.TransportDelay_RWORK_b.modelTStart
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 19;
      section.data(19)  = dumData; %prealloc
      
	  ;% GRM_HIL_DW.ACC_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GRM_HIL_DW.ATT_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 8;
	  section.data(2).dtTransOffset = 3;
	
	  ;% GRM_HIL_DW.CMD_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 9;
	  section.data(3).dtTransOffset = 6;
	
	  ;% GRM_HIL_DW.ROT_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 10;
	  section.data(4).dtTransOffset = 9;
	
	  ;% GRM_HIL_DW.TransportDelay_PWORK.TUbufferPtrs
	  section.data(5).logicalSrcIdx = 11;
	  section.data(5).dtTransOffset = 12;
	
	  ;% GRM_HIL_DW.TransportDelay_PWORK_j.TUbufferPtrs
	  section.data(6).logicalSrcIdx = 12;
	  section.data(6).dtTransOffset = 14;
	
	  ;% GRM_HIL_DW.TransportDelay_PWORK_l.TUbufferPtrs
	  section.data(7).logicalSrcIdx = 13;
	  section.data(7).dtTransOffset = 16;
	
	  ;% GRM_HIL_DW.Scope_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 14;
	  section.data(8).dtTransOffset = 18;
	
	  ;% GRM_HIL_DW.Scope1_PWORK.LoggedData
	  section.data(9).logicalSrcIdx = 15;
	  section.data(9).dtTransOffset = 19;
	
	  ;% GRM_HIL_DW.Scope2_PWORK.LoggedData
	  section.data(10).logicalSrcIdx = 16;
	  section.data(10).dtTransOffset = 20;
	
	  ;% GRM_HIL_DW.VEL_PWORK.LoggedData
	  section.data(11).logicalSrcIdx = 17;
	  section.data(11).dtTransOffset = 24;
	
	  ;% GRM_HIL_DW.Roll_PWORK.LoggedData
	  section.data(12).logicalSrcIdx = 18;
	  section.data(12).dtTransOffset = 27;
	
	  ;% GRM_HIL_DW.pitch_PWORK.LoggedData
	  section.data(13).logicalSrcIdx = 19;
	  section.data(13).dtTransOffset = 28;
	
	  ;% GRM_HIL_DW.scopeyawpitchroll_PWORK.LoggedData
	  section.data(14).logicalSrcIdx = 20;
	  section.data(14).dtTransOffset = 29;
	
	  ;% GRM_HIL_DW.yaw_PWORK.LoggedData
	  section.data(15).logicalSrcIdx = 21;
	  section.data(15).dtTransOffset = 30;
	
	  ;% GRM_HIL_DW.Velocity_pitch_PWORK.LoggedData
	  section.data(16).logicalSrcIdx = 22;
	  section.data(16).dtTransOffset = 31;
	
	  ;% GRM_HIL_DW.Velocity_roll_PWORK.LoggedData
	  section.data(17).logicalSrcIdx = 23;
	  section.data(17).dtTransOffset = 32;
	
	  ;% GRM_HIL_DW.velocity_yaw_PWORK.LoggedData
	  section.data(18).logicalSrcIdx = 24;
	  section.data(18).dtTransOffset = 33;
	
	  ;% GRM_HIL_DW.RealTimeSynchronization_PWORK
	  section.data(19).logicalSrcIdx = 25;
	  section.data(19).dtTransOffset = 34;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% GRM_HIL_DW.clockTickCounter
	  section.data(1).logicalSrcIdx = 26;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GRM_HIL_DW.clockTickCounter_d
	  section.data(2).logicalSrcIdx = 27;
	  section.data(2).dtTransOffset = 1;
	
	  ;% GRM_HIL_DW.clockTickCounter_d3
	  section.data(3).logicalSrcIdx = 28;
	  section.data(3).dtTransOffset = 2;
	
	  ;% GRM_HIL_DW.clockTickCounter_e
	  section.data(4).logicalSrcIdx = 29;
	  section.data(4).dtTransOffset = 3;
	
	  ;% GRM_HIL_DW.clockTickCounter_o
	  section.data(5).logicalSrcIdx = 30;
	  section.data(5).dtTransOffset = 4;
	
	  ;% GRM_HIL_DW.clockTickCounter_l
	  section.data(6).logicalSrcIdx = 31;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 16;
      section.data(16)  = dumData; %prealloc
      
	  ;% GRM_HIL_DW.Integrator_IWORK
	  section.data(1).logicalSrcIdx = 32;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GRM_HIL_DW.Integrator_IWORK_i
	  section.data(2).logicalSrcIdx = 33;
	  section.data(2).dtTransOffset = 1;
	
	  ;% GRM_HIL_DW.Integrator1_IWORK
	  section.data(3).logicalSrcIdx = 34;
	  section.data(3).dtTransOffset = 2;
	
	  ;% GRM_HIL_DW.Integrator2_IWORK
	  section.data(4).logicalSrcIdx = 35;
	  section.data(4).dtTransOffset = 3;
	
	  ;% GRM_HIL_DW.TransportDelay_IWORK.Tail
	  section.data(5).logicalSrcIdx = 36;
	  section.data(5).dtTransOffset = 4;
	
	  ;% GRM_HIL_DW.TransportDelay_IWORK_i.Tail
	  section.data(6).logicalSrcIdx = 37;
	  section.data(6).dtTransOffset = 5;
	
	  ;% GRM_HIL_DW.TransportDelay_IWORK_k.Tail
	  section.data(7).logicalSrcIdx = 38;
	  section.data(7).dtTransOffset = 6;
	
	  ;% GRM_HIL_DW.Integrator_IWORK_ic
	  section.data(8).logicalSrcIdx = 39;
	  section.data(8).dtTransOffset = 7;
	
	  ;% GRM_HIL_DW.Integrator1_IWORK_g
	  section.data(9).logicalSrcIdx = 40;
	  section.data(9).dtTransOffset = 8;
	
	  ;% GRM_HIL_DW.Integrator2_IWORK_m
	  section.data(10).logicalSrcIdx = 41;
	  section.data(10).dtTransOffset = 9;
	
	  ;% GRM_HIL_DW.Integrator1_IWORK_n
	  section.data(11).logicalSrcIdx = 42;
	  section.data(11).dtTransOffset = 10;
	
	  ;% GRM_HIL_DW.Integrator2_IWORK_e
	  section.data(12).logicalSrcIdx = 43;
	  section.data(12).dtTransOffset = 11;
	
	  ;% GRM_HIL_DW.Integrator_IWORK_m
	  section.data(13).logicalSrcIdx = 44;
	  section.data(13).dtTransOffset = 12;
	
	  ;% GRM_HIL_DW.Integrator1_IWORK_m
	  section.data(14).logicalSrcIdx = 45;
	  section.data(14).dtTransOffset = 13;
	
	  ;% GRM_HIL_DW.Integrator2_IWORK_c
	  section.data(15).logicalSrcIdx = 46;
	  section.data(15).dtTransOffset = 14;
	
	  ;% GRM_HIL_DW.Integrator_IWORK_l
	  section.data(16).logicalSrcIdx = 47;
	  section.data(16).dtTransOffset = 15;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 26;
      section.data(26)  = dumData; %prealloc
      
	  ;% GRM_HIL_DW.If_ActiveSubsystem
	  section.data(1).logicalSrcIdx = 48;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GRM_HIL_DW.If_ActiveSubsystem_l
	  section.data(2).logicalSrcIdx = 49;
	  section.data(2).dtTransOffset = 1;
	
	  ;% GRM_HIL_DW.If_ActiveSubsystem_g
	  section.data(3).logicalSrcIdx = 50;
	  section.data(3).dtTransOffset = 2;
	
	  ;% GRM_HIL_DW.Synchronize_to_realtime_SubsysRanBC
	  section.data(4).logicalSrcIdx = 51;
	  section.data(4).dtTransOffset = 3;
	
	  ;% GRM_HIL_DW.Propulsion_SubsysRanBC
	  section.data(5).logicalSrcIdx = 52;
	  section.data(5).dtTransOffset = 4;
	
	  ;% GRM_HIL_DW.hold_time_SubsysRanBC
	  section.data(6).logicalSrcIdx = 53;
	  section.data(6).dtTransOffset = 5;
	
	  ;% GRM_HIL_DW.Subsystem_SubsysRanBC
	  section.data(7).logicalSrcIdx = 54;
	  section.data(7).dtTransOffset = 6;
	
	  ;% GRM_HIL_DW.Gravity_SubsysRanBC
	  section.data(8).logicalSrcIdx = 55;
	  section.data(8).dtTransOffset = 7;
	
	  ;% GRM_HIL_DW.Drag_SubsysRanBC
	  section.data(9).logicalSrcIdx = 56;
	  section.data(9).dtTransOffset = 8;
	
	  ;% GRM_HIL_DW.Voltage_Limitations_SubsysRanBC
	  section.data(10).logicalSrcIdx = 57;
	  section.data(10).dtTransOffset = 9;
	
	  ;% GRM_HIL_DW.If_ActiveSubsystem_a
	  section.data(11).logicalSrcIdx = 58;
	  section.data(11).dtTransOffset = 10;
	
	  ;% GRM_HIL_DW.If1_ActiveSubsystem
	  section.data(12).logicalSrcIdx = 59;
	  section.data(12).dtTransOffset = 11;
	
	  ;% GRM_HIL_DW.If2_ActiveSubsystem
	  section.data(13).logicalSrcIdx = 60;
	  section.data(13).dtTransOffset = 12;
	
	  ;% GRM_HIL_DW.IfActionlimit_roll_SubsysRanBC
	  section.data(14).logicalSrcIdx = 61;
	  section.data(14).dtTransOffset = 13;
	
	  ;% GRM_HIL_DW.IfActionlimit_pitch_SubsysRanBC
	  section.data(15).logicalSrcIdx = 62;
	  section.data(15).dtTransOffset = 14;
	
	  ;% GRM_HIL_DW.IfActionlimit_yaw_SubsysRanBC
	  section.data(16).logicalSrcIdx = 63;
	  section.data(16).dtTransOffset = 15;
	
	  ;% GRM_HIL_DW.IfActionPass_SubsysRanBC
	  section.data(17).logicalSrcIdx = 64;
	  section.data(17).dtTransOffset = 16;
	
	  ;% GRM_HIL_DW.Enabledadapt_SubsysRanBC
	  section.data(18).logicalSrcIdx = 65;
	  section.data(18).dtTransOffset = 17;
	
	  ;% GRM_HIL_DW.pass_SubsysRanBC
	  section.data(19).logicalSrcIdx = 66;
	  section.data(19).dtTransOffset = 18;
	
	  ;% GRM_HIL_DW.Control_Limits_SubsysRanBC
	  section.data(20).logicalSrcIdx = 67;
	  section.data(20).dtTransOffset = 19;
	
	  ;% GRM_HIL_DW.Enabledadapt_SubsysRanBC_b
	  section.data(21).logicalSrcIdx = 68;
	  section.data(21).dtTransOffset = 20;
	
	  ;% GRM_HIL_DW.Enabledadapt_SubsysRanBC_g
	  section.data(22).logicalSrcIdx = 69;
	  section.data(22).dtTransOffset = 21;
	
	  ;% GRM_HIL_DW.FB_Com_freq_emul_SubsysRanBC
	  section.data(23).logicalSrcIdx = 70;
	  section.data(23).dtTransOffset = 22;
	
	  ;% GRM_HIL_DW.Saturate_SubsysRanBC
	  section.data(24).logicalSrcIdx = 71;
	  section.data(24).dtTransOffset = 23;
	
	  ;% GRM_HIL_DW.Pass_SubsysRanBC
	  section.data(25).logicalSrcIdx = 72;
	  section.data(25).dtTransOffset = 24;
	
	  ;% GRM_HIL_DW.Com_to_FCC_emul_SubsysRanBC
	  section.data(26).logicalSrcIdx = 73;
	  section.data(26).dtTransOffset = 25;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 17;
      section.data(17)  = dumData; %prealloc
      
	  ;% GRM_HIL_DW.Memory_1_PreviousInput
	  section.data(1).logicalSrcIdx = 74;
	  section.data(1).dtTransOffset = 0;
	
	  ;% GRM_HIL_DW.Memory_2_PreviousInput
	  section.data(2).logicalSrcIdx = 75;
	  section.data(2).dtTransOffset = 1;
	
	  ;% GRM_HIL_DW.lock_PreviousInput
	  section.data(3).logicalSrcIdx = 76;
	  section.data(3).dtTransOffset = 2;
	
	  ;% GRM_HIL_DW.Propulsion_MODE
	  section.data(4).logicalSrcIdx = 77;
	  section.data(4).dtTransOffset = 3;
	
	  ;% GRM_HIL_DW.hold_time_MODE
	  section.data(5).logicalSrcIdx = 78;
	  section.data(5).dtTransOffset = 4;
	
	  ;% GRM_HIL_DW.Subsystem_MODE
	  section.data(6).logicalSrcIdx = 79;
	  section.data(6).dtTransOffset = 5;
	
	  ;% GRM_HIL_DW.Gravity_MODE
	  section.data(7).logicalSrcIdx = 80;
	  section.data(7).dtTransOffset = 6;
	
	  ;% GRM_HIL_DW.Drag_MODE
	  section.data(8).logicalSrcIdx = 81;
	  section.data(8).dtTransOffset = 7;
	
	  ;% GRM_HIL_DW.Voltage_Limitations_MODE
	  section.data(9).logicalSrcIdx = 82;
	  section.data(9).dtTransOffset = 8;
	
	  ;% GRM_HIL_DW.IfActionPass_MODE
	  section.data(10).logicalSrcIdx = 83;
	  section.data(10).dtTransOffset = 9;
	
	  ;% GRM_HIL_DW.Enabledadapt_MODE
	  section.data(11).logicalSrcIdx = 84;
	  section.data(11).dtTransOffset = 10;
	
	  ;% GRM_HIL_DW.Control_Limits_MODE
	  section.data(12).logicalSrcIdx = 85;
	  section.data(12).dtTransOffset = 11;
	
	  ;% GRM_HIL_DW.Enabledadapt_MODE_h
	  section.data(13).logicalSrcIdx = 86;
	  section.data(13).dtTransOffset = 12;
	
	  ;% GRM_HIL_DW.Enabledadapt_MODE_n
	  section.data(14).logicalSrcIdx = 87;
	  section.data(14).dtTransOffset = 13;
	
	  ;% GRM_HIL_DW.Saturate_MODE
	  section.data(15).logicalSrcIdx = 88;
	  section.data(15).dtTransOffset = 14;
	
	  ;% GRM_HIL_DW.Pass_MODE
	  section.data(16).logicalSrcIdx = 89;
	  section.data(16).dtTransOffset = 15;
	
	  ;% GRM_HIL_DW.Com_to_FCC_emul_MODE
	  section.data(17).logicalSrcIdx = 90;
	  section.data(17).dtTransOffset = 16;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_DW.IfActionpass_roll.IfActionpass_yaw_SubsysRanBC
	  section.data(1).logicalSrcIdx = 91;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_DW.IfActionpass_pitch.IfActionpass_yaw_SubsysRanBC
	  section.data(1).logicalSrcIdx = 92;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_DW.IfActionpass_yaw.IfActionpass_yaw_SubsysRanBC
	  section.data(1).logicalSrcIdx = 93;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_DW.IfActionSubsystem_m.IfActionSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 94;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_DW.IfActionSubsystem1_e.IfActionSubsystem1_SubsysRanBC
	  section.data(1).logicalSrcIdx = 95;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_DW.IfActionSubsystem_p.IfActionSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 96;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_DW.IfActionSubsystem1_j.IfActionSubsystem1_SubsysRanBC
	  section.data(1).logicalSrcIdx = 97;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_DW.IfActionSubsystem.IfActionSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 98;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_DW.IfActionSubsystem1.IfActionSubsystem1_SubsysRanBC
	  section.data(1).logicalSrcIdx = 99;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_DW.pass_l.pass_SubsysRanBC
	  section.data(1).logicalSrcIdx = 100;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(16) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_DW.Saturation_e.Saturation_SubsysRanBC
	  section.data(1).logicalSrcIdx = 101;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(17) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_DW.Enabledpass_a.Enabledpass_SubsysRanBC
	  section.data(1).logicalSrcIdx = 102;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(18) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_DW.Enabledpass_a.Enabledpass_MODE
	  section.data(1).logicalSrcIdx = 103;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(19) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_DW.pass_c.pass_SubsysRanBC
	  section.data(1).logicalSrcIdx = 104;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(20) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_DW.Saturation_j.Saturation_SubsysRanBC
	  section.data(1).logicalSrcIdx = 105;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(21) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_DW.Enabledpass_j.Enabledpass_SubsysRanBC
	  section.data(1).logicalSrcIdx = 106;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(22) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_DW.Enabledpass_j.Enabledpass_MODE
	  section.data(1).logicalSrcIdx = 107;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(23) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_DW.pass.pass_SubsysRanBC
	  section.data(1).logicalSrcIdx = 108;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(24) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_DW.Saturation.Saturation_SubsysRanBC
	  section.data(1).logicalSrcIdx = 109;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(25) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_DW.Enabledpass.Enabledpass_SubsysRanBC
	  section.data(1).logicalSrcIdx = 110;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(26) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% GRM_HIL_DW.Enabledpass.Enabledpass_MODE
	  section.data(1).logicalSrcIdx = 111;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(27) = section;
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


  targMap.checksum0 = 143544100;
  targMap.checksum1 = 3447471112;
  targMap.checksum2 = 588967388;
  targMap.checksum3 = 529766825;

