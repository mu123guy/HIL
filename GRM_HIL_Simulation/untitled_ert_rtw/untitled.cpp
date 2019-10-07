//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: untitled.cpp
//
// Code generated for Simulink model 'untitled'.
//
// Model version                  : 1.0
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Sun Oct  6 19:40:43 2019
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "untitled.h"
#include "untitled_private.h"
#include "untitled_dt.h"

// Block signals (default storage)
B_untitled_T untitled_B;

// Block states (default storage)
DW_untitled_T untitled_DW;

// Real-time model
RT_MODEL_untitled_T untitled_M_ = RT_MODEL_untitled_T();
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;

// Forward declaration for local functions
static void untitled_SystemCore_release(const px4_internal_block_Subscriber_T
  *obj);
static void untitled_SystemCore_delete(const px4_internal_block_Subscriber_T
  *obj);
static void matlabCodegenHandle_matlabCodeg(px4_internal_block_Subscriber_T *obj);
static void untitled_SystemCore_release(const px4_internal_block_Subscriber_T
  *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    uORB_read_terminate(&obj->eventStructObj);
  }
}

static void untitled_SystemCore_delete(const px4_internal_block_Subscriber_T
  *obj)
{
  untitled_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(px4_internal_block_Subscriber_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    untitled_SystemCore_delete(obj);
  }
}

// Model step function
void untitled_step(void)
{
  boolean_T b_varargout_1;
  px4_Bus_vehicle_attitude b_varargout_2;

  // Reset subsysRan breadcrumbs
  srClearBC(untitled_DW.EnabledSubsystem_SubsysRanBC_p);

  // Reset subsysRan breadcrumbs
  srClearBC(untitled_DW.EnabledSubsystem_SubsysRanBC);

  // MATLABSystem: '<S3>/SourceBlock' incorporates:
  //   Inport: '<S4>/In1'

  b_varargout_1 = uORB_read_step(untitled_DW.obj_g.orbMetadataObj,
    &untitled_DW.obj_g.eventStructObj, &untitled_B.b_varargout_2, false, 1.0);

  // Outputs for Enabled SubSystem: '<S3>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S4>/Enable'

  if (b_varargout_1) {
    untitled_B.In1 = untitled_B.b_varargout_2;
    srUpdateBC(untitled_DW.EnabledSubsystem_SubsysRanBC_p);
  }

  // End of MATLABSystem: '<S3>/SourceBlock'
  // End of Outputs for SubSystem: '<S3>/Enabled Subsystem'

  // SignalConversion generated from: '<S1>/Bus Selector'
  untitled_B.x = untitled_B.In1.x;

  // SignalConversion generated from: '<S1>/Bus Selector'
  untitled_B.y = untitled_B.In1.y;

  // SignalConversion generated from: '<S1>/Bus Selector'
  untitled_B.z = untitled_B.In1.z;

  // MATLABSystem: '<S5>/SourceBlock'
  b_varargout_1 = uORB_read_step(untitled_DW.obj.orbMetadataObj,
    &untitled_DW.obj.eventStructObj, &b_varargout_2, false, 1.0);

  // Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S6>/Enable'

  if (b_varargout_1) {
    srUpdateBC(untitled_DW.EnabledSubsystem_SubsysRanBC);
  }

  // End of MATLABSystem: '<S5>/SourceBlock'
  // End of Outputs for SubSystem: '<S5>/Enabled Subsystem'

  // External mode
  rtExtModeUploadCheckTrigger(1);

  {                                    // Sample time: [0.001s, 0.0s]
    rtExtModeUpload(0, (real_T)untitled_M->Timing.taskTime0);
  }

  // signal main to stop simulation
  {                                    // Sample time: [0.001s, 0.0s]
    if ((rtmGetTFinal(untitled_M)!=-1) &&
        !((rtmGetTFinal(untitled_M)-untitled_M->Timing.taskTime0) >
          untitled_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(untitled_M, "Simulation finished");
    }

    if (rtmGetStopRequested(untitled_M)) {
      rtmSetErrorStatus(untitled_M, "Simulation finished");
    }
  }

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  untitled_M->Timing.taskTime0 =
    (++untitled_M->Timing.clockTick0) * untitled_M->Timing.stepSize0;
}

// Model initialize function
void untitled_initialize(void)
{
  // Registration code
  rtmSetTFinal(untitled_M, -1);
  untitled_M->Timing.stepSize0 = 0.001;

  // External mode info
  untitled_M->Sizes.checksums[0] = (2056437001U);
  untitled_M->Sizes.checksums[1] = (3189159351U);
  untitled_M->Sizes.checksums[2] = (4275693920U);
  untitled_M->Sizes.checksums[3] = (115166199U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    untitled_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)&untitled_DW.EnabledSubsystem_SubsysRanBC_p;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = (sysRanDType *)&untitled_DW.EnabledSubsystem_SubsysRanBC;
    rteiSetModelMappingInfoPtr(untitled_M->extModeInfo,
      &untitled_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled_M->extModeInfo, untitled_M->Sizes.checksums);
    rteiSetTPtr(untitled_M->extModeInfo, rtmGetTPtr(untitled_M));
  }

  // data type transition information
  {
    static DataTypeTransInfo dtInfo;
    untitled_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 20;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    // Block I/O transition table
    dtInfo.BTransTable = &rtBTransTable;

    // Parameters transition table
    dtInfo.PTransTable = &rtPTransTable;
  }

  // Start for MATLABSystem: '<S3>/SourceBlock'
  untitled_DW.obj_g.matlabCodegenIsDeleted = false;
  untitled_DW.obj_g.isSetupComplete = false;
  untitled_DW.obj_g.isInitialized = 1;
  untitled_DW.obj_g.orbMetadataObj = ORB_ID(sensor_mag);
  uORB_read_initialize(untitled_DW.obj_g.orbMetadataObj,
                       &untitled_DW.obj_g.eventStructObj);
  untitled_DW.obj_g.isSetupComplete = true;

  // Start for MATLABSystem: '<S5>/SourceBlock'
  untitled_DW.obj.matlabCodegenIsDeleted = false;
  untitled_DW.obj.isSetupComplete = false;
  untitled_DW.obj.isInitialized = 1;
  untitled_DW.obj.orbMetadataObj = ORB_ID(vehicle_attitude);
  uORB_read_initialize(untitled_DW.obj.orbMetadataObj,
                       &untitled_DW.obj.eventStructObj);
  untitled_DW.obj.isSetupComplete = true;

  // SystemInitialize for Enabled SubSystem: '<S3>/Enabled Subsystem'
  // SystemInitialize for Outport: '<S4>/Out1'
  untitled_B.In1 = untitled_P.Out1_Y0;

  // End of SystemInitialize for SubSystem: '<S3>/Enabled Subsystem'
}

// Model terminate function
void untitled_terminate(void)
{
  // Terminate for MATLABSystem: '<S3>/SourceBlock'
  matlabCodegenHandle_matlabCodeg(&untitled_DW.obj_g);

  // Terminate for MATLABSystem: '<S5>/SourceBlock'
  matlabCodegenHandle_matlabCodeg(&untitled_DW.obj);
}

//
// File trailer for generated code.
//
// [EOF]
//
