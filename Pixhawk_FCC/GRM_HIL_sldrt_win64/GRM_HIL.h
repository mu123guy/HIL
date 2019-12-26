/*
 * GRM_HIL.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "GRM_HIL".
 *
 * Model version              : 1.71
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Thu Dec 12 15:00:53 2019
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_GRM_HIL_h_
#define RTW_HEADER_GRM_HIL_h_
#include <math.h>
#include <string.h>
#ifndef GRM_HIL_COMMON_INCLUDES_
# define GRM_HIL_COMMON_INCLUDES_
#include "ToAsyncQueueTgtAppSvc/ToAsyncQueueTgtAppSvcCIntrf.h"
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "dt_info.h"
#include "ext_work.h"
#include "sldrtdef.h"
#endif                                 /* GRM_HIL_COMMON_INCLUDES_ */

#include "GRM_HIL_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include "rt_zcfcn.h"
#include "rt_assert.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetCtrlRateMdlRefTiming
# define rtmGetCtrlRateMdlRefTiming(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTiming
# define rtmSetCtrlRateMdlRefTiming(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateMdlRefTimingPtr
# define rtmGetCtrlRateMdlRefTimingPtr(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTimingPtr
# define rtmSetCtrlRateMdlRefTimingPtr(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateNumTicksToNextHit
# define rtmGetCtrlRateNumTicksToNextHit(rtm) ()
#endif

#ifndef rtmSetCtrlRateNumTicksToNextHit
# define rtmSetCtrlRateNumTicksToNextHit(rtm, val) ()
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ()
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ()
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ()
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ()
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
# define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
# define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->odeY = (val))
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ()
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ()
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSelf
# define rtmGetSelf(rtm)               ()
#endif

#ifndef rtmSetSelf
# define rtmSetSelf(rtm, val)          ()
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ((rtm)->Timing.TaskCounters)
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ((rtm)->Timing.TaskCounters = (val))
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGettimingBridge
# define rtmGettimingBridge(rtm)       ()
#endif

#ifndef rtmSettimingBridge
# define rtmSettimingBridge(rtm, val)  ()
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
# define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
# define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmSetFirstInitCond
# define rtmSetFirstInitCond(rtm, val) ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmIsFirstInitCond
# define rtmIsFirstInitCond(rtm)       ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define GRM_HIL_rtModel                RT_MODEL_GRM_HIL_T

/* Block signals for system '<S26>/Counter_with_external_limit' */
typedef struct {
  real_T value;                        /* '<S26>/Counter_with_external_limit' */
} B_Counter_with_external_limit_GRM_HIL_T;

/* Block signals for system '<S125>/Limiting_Acceleration' */
typedef struct {
  real_T dd_siB_l;                     /* '<S125>/Limiting_Acceleration' */
} B_Limiting_Acceleration_GRM_HIL_T;

/* Block signals for system '<S125>/Limiting_Rate' */
typedef struct {
  real_T d_siB_l;                      /* '<S125>/Limiting_Rate' */
} B_Limiting_Rate_GRM_HIL_T;

/* Block signals (default storage) */
typedef struct {
  real_T Constant[13];                 /* '<S182>/Constant' */
  real_T POS_z_NED_m;                  /* '<S49>/Gain17' */
  real_T Fin_1_Pos_rad;                /* '<S12>/Gain' */
  real_T Fin_2_Pos_rad;                /* '<S12>/Gain1' */
  real_T Fin_3_Pos_rad;                /* '<S12>/Gain2' */
  real_T Fin_4_Pos_rad;                /* '<S12>/Gain3' */
  real_T A;                            /* '<S10>/Constant' */
  real_T B;                            /* '<S10>/Constant1' */
  real_T Z;                            /* '<S10>/Constant2' */
  real_T A_i;                          /* '<S10>/Constant3' */
  real_T B_d;                          /* '<S10>/Constant4' */
  real_T Z_d;                          /* '<S10>/Constant5' */
  real_T A_m;                          /* '<S10>/Constant6' */
  real_T B_c;                          /* '<S10>/Constant7' */
  real_T Z_h;                          /* '<S10>/Constant8' */
  real_T A_f;                          /* '<S10>/Constant9' */
  real_T B_n;                          /* '<S10>/Constant10' */
  real_T Z_l;                          /* '<S10>/Constant11' */
  real_T Receive_from_FTHWICC_o1;      /* '<S34>/Receive_from_FTHWICC' */
  real_T Receive_from_FTHWICC_o2;      /* '<S34>/Receive_from_FTHWICC' */
  real_T Receive_from_FTHWICC_o3;      /* '<S34>/Receive_from_FTHWICC' */
  real_T Receive_from_FTHWICC_o4;      /* '<S34>/Receive_from_FTHWICC' */
  real_T Receive_from_FTHWICC_o5;      /* '<S34>/Receive_from_FTHWICC' */
  real_T Receive_from_FTHWICC_o6;      /* '<S34>/Receive_from_FTHWICC' */
  real_T Receive_from_FTHWICC_o7;      /* '<S34>/Receive_from_FTHWICC' */
  real_T Receive_from_FTHWICC_o9;      /* '<S34>/Receive_from_FTHWICC' */
  real_T VEL_u_K_R_E_B_mDs;            /* '<S49>/Gain' */
  real_T VEL_v_K_R_E_B_mDs;            /* '<S49>/Gain1' */
  real_T VEL_w_K_R_E_B_mDs;            /* '<S49>/Gain2' */
  real_T Constant8[4];                 /* '<S157>/Constant8' */
  real_T wIEE[3];                      /* '<S156>/Switch' */
  real_T Constant8_h[4];               /* '<S158>/Constant8' */
  real_T vec2[3];                      /* '<S209>/Product' */
  real_T Tmp_ref;                      /* '<S122>/Subtract1' */
  real_T Product;                      /* '<S187>/Product' */
  real_T Divide;                       /* '<S187>/Divide' */
  real_T Subtract1;                    /* '<S187>/Subtract1' */
  real_T Subtract;                     /* '<S186>/Subtract' */
  real_T Switch[3];                    /* '<S183>/Switch' */
  real_T sat;                          /* '<S125>/Integrator1' */
  real_T Gain3;                        /* '<S125>/Gain3' */
  real_T sat_c;                        /* '<S126>/Integrator1' */
  real_T Gain3_m;                      /* '<S126>/Gain3' */
  real_T sat_a;                        /* '<S127>/Integrator1' */
  real_T Gain3_b;                      /* '<S127>/Gain3' */
  real_T sat_o;                        /* '<S128>/Integrator1' */
  real_T Gain3_h;                      /* '<S128>/Gain3' */
  real_T Sqrt;                         /* '<S96>/Sqrt' */
  real_T pa_ref;                       /* '<S122>/Subtract2' */
  real_T hBE_0;                        /* '<S81>/Switch1' */
  real_T VectorConcatenate[3];         /* '<S79>/Vector Concatenate' */
  real_T e2;                           /* '<S117>/Divide' */
  real_T Add1;                         /* '<S115>/Add1' */
  real_T hBE_0_l;                      /* '<S139>/Switch1' */
  real_T VectorConcatenate_f[3];       /* '<S138>/Vector Concatenate' */
  real_T T12[9];                       /* '<S170>/3. Rotation' */
  real_T VectorConcatenate_b[4];       /* '<S195>/Vector Concatenate' */
  real_T ACC_x_B_mDs2;                 /* '<S49>/Gain3' */
  real_T ACC_y_B_mDs2;                 /* '<S49>/Gain4' */
  real_T ACC_z_B_mDs2;                 /* '<S49>/Gain5' */
  real_T w_x_K_IB_B_radDs;             /* '<S49>/Gain6' */
  real_T w_y_K_IB_B_radDs;             /* '<S49>/Gain7' */
  real_T w_z_K_IB_B_radDs;             /* '<S49>/Gain8' */
  real_T ATT_Phi_rad;                  /* '<S49>/Gain9' */
  real_T ATT_Theta_rad;                /* '<S49>/Gain10' */
  real_T ATT_Psi_rad;                  /* '<S49>/Gain11' */
  real_T q0;                           /* '<S65>/q0' */
  real_T q1;                           /* '<S65>/q1' */
  real_T q2;                           /* '<S65>/q2' */
  real_T q3;                           /* '<S65>/q3' */
  real_T POS_lambda_WGS84_rad;         /* '<S49>/Gain12' */
  real_T POS_mue_WGS84_rad;            /* '<S49>/Gain13' */
  real_T POS_h_WGS84_m;                /* '<S49>/Gain14' */
  real_T POS_x_NED_m;                  /* '<S49>/Gain15' */
  real_T POS_y_NED_m;                  /* '<S49>/Gain16' */
  real_T motor_state_perc;             /* '<S49>/Gain18' */
  real_T mass_kg;                      /* '<S49>/Gain22' */
  real_T VEL_u_Wind_A_E_O_mDs;         /* '<S49>/Gain19' */
  real_T VEL_v_Wind_A_E_O_mDs;         /* '<S49>/Gain20' */
  real_T VEL_w_Wind_A_E_O_mDs;         /* '<S49>/Gain21' */
  real_T Saturation;                   /* '<S13>/Saturation' */
  real_T Saturation_c;                 /* '<S14>/Saturation' */
  real_T Saturation_j;                 /* '<S15>/Saturation' */
  real_T Saturation_a;                 /* '<S16>/Saturation' */
  real_T enable_gimbal_ctrl_flg;       /* '<S7>/Constant7' */
  real_T stop_gimbal_flg;              /* '<S7>/Constant8' */
  real_T Gimbal_Phi_Cmd_deg;           /* '<S46>/rad2deg' */
  real_T Gimbal_Theta_Cmd_deg;         /* '<S46>/rad2deg1' */
  real_T Gimbal_Psi_Cmd_deg;           /* '<S46>/rad2deg2' */
  real_T Constant_i;                   /* '<S34>/Constant' */
  real_T siB_cmd[4];                   /* '<S69>/Product' */
  real_T Product_a;                    /* '<S214>/Product' */
  real_T Product2;                     /* '<S214>/Product2' */
  real_T Product4;                     /* '<S214>/Product4' */
  real_T hBE_0_h;                      /* '<S85>/Switch1' */
  real_T VectorConcatenate_e[3];       /* '<S80>/Vector Concatenate' */
  real_T Add[16];                      /* '<S160>/Add' */
  real_T VectorConcatenate_m[4];       /* '<S163>/Vector Concatenate' */
  real_T wEGG[3];                      /* '<S159>/Vector Concatenate1' */
  real_T VectorConcatenate_a[4];       /* '<S164>/Vector Concatenate' */
  real_T VectorConcatenate_k[4];       /* '<S167>/Vector Concatenate' */
  real_T VectorConcatenate_p[4];       /* '<S193>/Vector Concatenate' */
  real_T T12_o[9];                     /* '<S225>/3. Rotation' */
  real_T Subtract_d[9];                /* '<S220>/Subtract' */
  real_T Subtract4;                    /* '<S220>/Subtract4' */
  real_T MathFunction[9];              /* '<S221>/Math Function' */
  real_T d_x[13];                      /* '<S189>/Vector Concatenate' */
  real_T VectorConcatenate1[3];        /* '<S183>/Vector Concatenate1' */
  real_T Gimbal_operational_flg;
               /* '<S36>/BusConversion_InsertedFor_Gimbal_Status_at_inport_0' */
  real_T Gimbal_Ramp_flg;
               /* '<S36>/BusConversion_InsertedFor_Gimbal_Status_at_inport_0' */
  real_T Gimbal_Limit_flg;
               /* '<S36>/BusConversion_InsertedFor_Gimbal_Status_at_inport_0' */
  real_T Gimbal_StopSim_flg;
               /* '<S36>/BusConversion_InsertedFor_Gimbal_Status_at_inport_0' */
  real_T Data_plus;                    /* '<S40>/Constant' */
  real_T Data_minus;                   /* '<S40>/Constant1' */
  real_T Clock_plus;                   /* '<S40>/Constant2' */
  real_T Clock_minus;                  /* '<S40>/Constant3' */
  real_T Data_minus_j;                /* '<S40>/TmpBufferAtConstant1Outport1' */
  real_T Clock_plus_j;                /* '<S40>/TmpBufferAtConstant2Outport1' */
  real_T Clock_minus_d;               /* '<S40>/TmpBufferAtConstant3Outport1' */
  real_T Data_plus_p;                  /* '<S40>/TmpBufferAtConstantOutport1' */
  real_T Data_plus_pq;                 /* '<S40>/Constant4' */
  real_T Data_minus_b;                 /* '<S40>/Constant5' */
  real_T Clock_plus_l;                 /* '<S40>/Constant6' */
  real_T Clock_minus_c;                /* '<S40>/Constant7' */
  real_T Data_plus_pe;                /* '<S40>/TmpBufferAtConstant4Outport1' */
  real_T Data_minus_jy;               /* '<S40>/TmpBufferAtConstant5Outport1' */
  real_T Clock_plus_jb;               /* '<S40>/TmpBufferAtConstant6Outport1' */
  real_T Clock_minus_d1;              /* '<S40>/TmpBufferAtConstant7Outport1' */
  real_T Clock_plus_a;                 /* '<S40>/Constant10' */
  real_T Clock_minus_h;                /* '<S40>/Constant11' */
  real_T Data_plus_n;                  /* '<S40>/Constant8' */
  real_T Data_minus_g;                 /* '<S40>/Constant9' */
  real_T Clock_plus_jbf;             /* '<S40>/TmpBufferAtConstant10Outport1' */
  real_T Clock_minus_d1h;            /* '<S40>/TmpBufferAtConstant11Outport1' */
  real_T Data_plus_pek;               /* '<S40>/TmpBufferAtConstant8Outport1' */
  real_T Data_minus_jye;              /* '<S40>/TmpBufferAtConstant9Outport1' */
  real_T ATT_Psi_rad_e;                /* '<S39>/Shaft2radYaw' */
  real_T ATT_Theta_rad_e;              /* '<S39>/Shaft2radPitch' */
  real_T ATT_Phi_rad_p;                /* '<S39>/Shaft2radRoll' */
  real_T q0_d;                         /* '<S42>/q0' */
  real_T q1_o;                         /* '<S42>/q1' */
  real_T q2_i;                         /* '<S42>/q2' */
  real_T q3_o;                         /* '<S42>/q3' */
  real_T Gimbal_yaw_sns;
          /* '<S36>/BusConversion_InsertedFor_Gimbal_Pos_Encoder_at_inport_0' */
  real_T Gimbal_pitch_sns;
          /* '<S36>/BusConversion_InsertedFor_Gimbal_Pos_Encoder_at_inport_0' */
  real_T Gimbal_roll_sns;
          /* '<S36>/BusConversion_InsertedFor_Gimbal_Pos_Encoder_at_inport_0' */
  real32_T DataTypeConversion3;        /* '<S20>/Data Type Conversion3' */
  real32_T DataTypeConversion1;        /* '<S20>/Data Type Conversion1' */
  real32_T DataTypeConversion2;        /* '<S20>/Data Type Conversion2' */
  real32_T ServoCMD_update[4];         /* '<S25>/ServoCMD_update' */
  real32_T SensorACC_update[3];        /* '<S25>/SensorACC_update' */
  real32_T SensorROT_update[3];        /* '<S25>/SensorROT_update' */
  real32_T quaternion_update[4];       /* '<S25>/quaternion_update' */
  uint16_T Receive_from_FTHWICC_o8;    /* '<S34>/Receive_from_FTHWICC' */
  uint16_T DataTypeConversion1_p;      /* '<S238>/Data Type Conversion1' */
  uint16_T FixPtSwitch;                /* '<S241>/FixPt Switch' */
  uint8_T message[128];                /* '<S32>/message' */
  uint8_T PacketInput_o1[78];          /* '<S21>/Packet Input' */
  boolean_T Compare;                   /* '<S242>/Compare' */
  boolean_T OR;                        /* '<S26>/OR' */
  boolean_T run;                       /* '<S7>/Constant' */
  boolean_T reset;                     /* '<S7>/Constant2' */
  boolean_T Compare_k;                 /* '<S112>/Compare' */
  boolean_T AND;                       /* '<S113>/AND' */
  boolean_T AND_i;                     /* '<S114>/AND' */
  boolean_T NOT;                       /* '<S28>/NOT' */
  boolean_T AND_h;                     /* '<S21>/AND' */
  B_Limiting_Rate_GRM_HIL_T sf_Limiting_Rate_d;/* '<S128>/Limiting_Rate' */
  B_Limiting_Acceleration_GRM_HIL_T sf_Limiting_Acceleration_h;/* '<S128>/Limiting_Acceleration' */
  B_Limiting_Rate_GRM_HIL_T sf_Limiting_Rate_g;/* '<S127>/Limiting_Rate' */
  B_Limiting_Acceleration_GRM_HIL_T sf_Limiting_Acceleration_p;/* '<S127>/Limiting_Acceleration' */
  B_Limiting_Rate_GRM_HIL_T sf_Limiting_Rate_o;/* '<S126>/Limiting_Rate' */
  B_Limiting_Acceleration_GRM_HIL_T sf_Limiting_Acceleration_i;/* '<S126>/Limiting_Acceleration' */
  B_Limiting_Rate_GRM_HIL_T sf_Limiting_Rate;/* '<S125>/Limiting_Rate' */
  B_Limiting_Acceleration_GRM_HIL_T sf_Limiting_Acceleration;/* '<S125>/Limiting_Acceleration' */
  B_Counter_with_external_limit_GRM_HIL_T sf_Counter_with_external_limit_j;/* '<S35>/Counter_with_external_limit' */
  B_Counter_with_external_limit_GRM_HIL_T sf_Counter_with_external_limit;/* '<S26>/Counter_with_external_limit' */
} B_GRM_HIL_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Memory_PreviousInput;         /* '<S26>/Memory' */
  real_T Memory_PreviousInput_d;       /* '<S35>/Memory' */
  real_T TimeStampA;                   /* '<S159>/Derivative1' */
  real_T LastUAtTimeA;                 /* '<S159>/Derivative1' */
  real_T TimeStampB;                   /* '<S159>/Derivative1' */
  real_T LastUAtTimeB;                 /* '<S159>/Derivative1' */
  real_T TimeStampA_b;                 /* '<S159>/Derivative' */
  real_T LastUAtTimeA_b;               /* '<S159>/Derivative' */
  real_T TimeStampB_j;                 /* '<S159>/Derivative' */
  real_T LastUAtTimeB_p;               /* '<S159>/Derivative' */
  struct {
    void *AQHandles[16];
    void *SlioLTF;
  } TAQSigLogging_InsertedFor_Actuators_at_outport_0_1_PWORK;/* synthesized block */

  void *Receive_from_FTHWICC_PWORK;    /* '<S34>/Receive_from_FTHWICC' */
  struct {
    void *AQHandles[26];
    void *SlioLTF;
  } TAQSigLogging_InsertedFor_Gimbal_at_outport_0_1_PWORK;/* synthesized block */

  struct {
    void *AQHandles[27];
    void *SlioLTF;
  } TAQSigLogging_InsertedFor_Simulation_at_outport_0_1_PWORK;/* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } TAQSigLogging_InsertedFor_Serial_Recieve_from_Pixhawk_at_outport_6_PWORK;/* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } TAQSigLogging_InsertedFor_Serial_Recieve_from_Pixhawk_at_outport_7_PWORK;/* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } TAQSigLogging_InsertedFor_Serial_Recieve_from_Pixhawk_at_outport_8_PWORK;/* synthesized block */

  void* Assertion_slioAccessor;        /* '<S109>/Assertion' */
  void* Assertion1_slioAccessor;       /* '<S109>/Assertion1' */
  void* Assertion2_slioAccessor;       /* '<S109>/Assertion2' */
  void *RealTimeSynchronization_PWORK; /* '<S237>/Real-Time Synchronization' */
  void *Send_to_FTHWICC_PWORK[2];      /* '<S37>/Send_to_FTHWICC' */
  struct {
    void *AQHandles;
    void *SlioLTF;
  } TAQSigLogging_InsertedFor_Gimbal_Phi_Cmd_deg_at_outport_0_PWORK;/* synthesized block */

  void *PacketOutput_PWORK[2];         /* '<S31>/Packet Output' */
  void *PacketInput_PWORK;             /* '<S21>/Packet Input' */
  struct {
    void *AQHandles;
    void *SlioLTF;
  } TAQSigLogging_InsertedFor_PacketInput_at_outport_0_PWORK;/* synthesized block */

  int32_T clockTickCounter;            /* '<S17>/Pulse Generator1' */
  int32_T clockTickCounter_d;          /* '<S17>/Pulse Generator' */
  int32_T clockTickCounter_d3;         /* '<S17>/Pulse Generator4' */
  int32_T clockTickCounter_e;          /* '<S17>/Pulse Generator3' */
  int32_T clockTickCounter_o;          /* '<S17>/Pulse Generator7' */
  int32_T clockTickCounter_l;          /* '<S17>/Pulse Generator6' */
  int32_T SFunction_DIMS2[2];          /* '<S22>/ExtractMessage' */
  int_T integration_eom_IWORK;         /* '<S189>/integration_eom' */
  int_T integration_eom_IWORK_g;       /* '<S157>/integration_eom' */
  int_T integration_eom_IWORK_l;       /* '<S158>/integration_eom' */
  uint16_T Output_DSTATE;              /* '<S239>/Output' */
  int8_T Synchronize_to_realtime_SubsysRanBC;/* '<S7>/Synchronize_to_realtime' */
  int8_T Send_to_FTHWICC_SubsysRanBC;  /* '<S34>/Send_to_FTHWICC' */
  int8_T Construct_Bus_SubsysRanBC;    /* '<S34>/Construct_Bus' */
  int8_T send_to_pix_SubsysRanBC;      /* '<S20>/send_to_pix' */
  int8_T no_CRC_SubsysRanBC;           /* '<S28>/no_CRC' */
  int8_T Send_ExternalMode_SubsysRanBC;/* '<S28>/Send_ExternalMode' */
  int8_T input_hold_SubsysRanBC;       /* '<S19>/input_hold' */
  int8_T hold_SubsysRanBC;             /* '<S22>/hold' */
  int8_T Receive_ExternalMode_SubsysRanBC;/* '<S19>/Receive_ExternalMode' */
  boolean_T Send_to_FTHWICC_MODE;      /* '<S34>/Send_to_FTHWICC' */
  boolean_T send_to_pix_MODE;          /* '<S20>/send_to_pix' */
  boolean_T no_CRC_MODE;               /* '<S28>/no_CRC' */
  boolean_T Send_ExternalMode_MODE;    /* '<S28>/Send_ExternalMode' */
} DW_GRM_HIL_T;

/* Continuous states (default storage) */
typedef struct {
  real_T integration_eom_CSTATE[13];   /* '<S189>/integration_eom' */
  real_T TransferFcn_CSTATE[2];        /* '<S11>/Transfer Fcn' */
  real_T TransferFcn1_CSTATE[2];       /* '<S11>/Transfer Fcn1' */
  real_T TransferFcn2_CSTATE[2];       /* '<S11>/Transfer Fcn2' */
  real_T TransferFcn3_CSTATE[2];       /* '<S11>/Transfer Fcn3' */
  real_T integration_eom_CSTATE_b[4];  /* '<S157>/integration_eom' */
  real_T integration_eom_CSTATE_f[4];  /* '<S158>/integration_eom' */
  real_T Integrator1_CSTATE;           /* '<S125>/Integrator1' */
  real_T Integrator1_CSTATE_g;         /* '<S126>/Integrator1' */
  real_T Integrator1_CSTATE_a;         /* '<S127>/Integrator1' */
  real_T Integrator1_CSTATE_i;         /* '<S128>/Integrator1' */
  real_T Integrator_CSTATE;            /* '<S125>/Integrator' */
  real_T Integrator_CSTATE_e;          /* '<S126>/Integrator' */
  real_T Integrator_CSTATE_f;          /* '<S127>/Integrator' */
  real_T Integrator_CSTATE_g;          /* '<S128>/Integrator' */
} X_GRM_HIL_T;

/* State derivatives (default storage) */
typedef struct {
  real_T integration_eom_CSTATE[13];   /* '<S189>/integration_eom' */
  real_T TransferFcn_CSTATE[2];        /* '<S11>/Transfer Fcn' */
  real_T TransferFcn1_CSTATE[2];       /* '<S11>/Transfer Fcn1' */
  real_T TransferFcn2_CSTATE[2];       /* '<S11>/Transfer Fcn2' */
  real_T TransferFcn3_CSTATE[2];       /* '<S11>/Transfer Fcn3' */
  real_T integration_eom_CSTATE_b[4];  /* '<S157>/integration_eom' */
  real_T integration_eom_CSTATE_f[4];  /* '<S158>/integration_eom' */
  real_T Integrator1_CSTATE;           /* '<S125>/Integrator1' */
  real_T Integrator1_CSTATE_g;         /* '<S126>/Integrator1' */
  real_T Integrator1_CSTATE_a;         /* '<S127>/Integrator1' */
  real_T Integrator1_CSTATE_i;         /* '<S128>/Integrator1' */
  real_T Integrator_CSTATE;            /* '<S125>/Integrator' */
  real_T Integrator_CSTATE_e;          /* '<S126>/Integrator' */
  real_T Integrator_CSTATE_f;          /* '<S127>/Integrator' */
  real_T Integrator_CSTATE_g;          /* '<S128>/Integrator' */
} XDot_GRM_HIL_T;

/* State disabled  */
typedef struct {
  boolean_T integration_eom_CSTATE[13];/* '<S189>/integration_eom' */
  boolean_T TransferFcn_CSTATE[2];     /* '<S11>/Transfer Fcn' */
  boolean_T TransferFcn1_CSTATE[2];    /* '<S11>/Transfer Fcn1' */
  boolean_T TransferFcn2_CSTATE[2];    /* '<S11>/Transfer Fcn2' */
  boolean_T TransferFcn3_CSTATE[2];    /* '<S11>/Transfer Fcn3' */
  boolean_T integration_eom_CSTATE_b[4];/* '<S157>/integration_eom' */
  boolean_T integration_eom_CSTATE_f[4];/* '<S158>/integration_eom' */
  boolean_T Integrator1_CSTATE;        /* '<S125>/Integrator1' */
  boolean_T Integrator1_CSTATE_g;      /* '<S126>/Integrator1' */
  boolean_T Integrator1_CSTATE_a;      /* '<S127>/Integrator1' */
  boolean_T Integrator1_CSTATE_i;      /* '<S128>/Integrator1' */
  boolean_T Integrator_CSTATE;         /* '<S125>/Integrator' */
  boolean_T Integrator_CSTATE_e;       /* '<S126>/Integrator' */
  boolean_T Integrator_CSTATE_f;       /* '<S127>/Integrator' */
  boolean_T Integrator_CSTATE_g;       /* '<S128>/Integrator' */
} XDis_GRM_HIL_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Integrator_Reset_ZCE;     /* '<S125>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_h;   /* '<S126>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_k;   /* '<S127>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_n;   /* '<S128>/Integrator' */
} PrevZCX_GRM_HIL_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            GRM_HIL_B
#define BlockIO                        B_GRM_HIL_T
#define rtX                            GRM_HIL_X
#define ContinuousStates               X_GRM_HIL_T
#define rtXdot                         GRM_HIL_XDot
#define StateDerivatives               XDot_GRM_HIL_T
#define tXdis                          GRM_HIL_XDis
#define StateDisabled                  XDis_GRM_HIL_T
#define rtP                            GRM_HIL_P
#define Parameters                     P_GRM_HIL_T
#define rtDWork                        GRM_HIL_DW
#define D_Work                         DW_GRM_HIL_T
#define rtPrevZCSigState               GRM_HIL_PrevZCX
#define PrevZCSigStates                PrevZCX_GRM_HIL_T

/* Parameters (default storage) */
struct P_GRM_HIL_T_ {
  real_T HIL_Sample_Time;              /* Variable: HIL_Sample_Time
                                        * Referenced by:
                                        *   '<S26>/Constant'
                                        *   '<S35>/Constant'
                                        */
  struct_Y7PS1rxhiw1TKkxrPVqWqG External_Inputs_External_Inputs;
                              /* Mask Parameter: External_Inputs_External_Inputs
                               * Referenced by:
                               *   '<S17>/Constant'
                               *   '<S17>/Constant1'
                               *   '<S17>/Constant2'
                               *   '<S17>/Constant3'
                               *   '<S17>/Constant4'
                               *   '<S17>/Constant5'
                               *   '<S17>/Pulse Generator'
                               *   '<S17>/Pulse Generator3'
                               *   '<S17>/Pulse Generator6'
                               */
  struct_fqhbejXln8QRylaPqhUyTF Servo_TF;/* Mask Parameter: Servo_TF
                                          * Referenced by:
                                          *   '<S11>/Transfer Fcn'
                                          *   '<S11>/Transfer Fcn1'
                                          *   '<S11>/Transfer Fcn2'
                                          *   '<S11>/Transfer Fcn3'
                                          */
  struct_7SrGNOW0Gr039ZOMvXVVTD Servo_PWM;/* Mask Parameter: Servo_PWM
                                           * Referenced by:
                                           *   '<S13>/Constant'
                                           *   '<S13>/Constant1'
                                           *   '<S13>/Constant2'
                                           *   '<S13>/Saturation'
                                           *   '<S14>/Constant'
                                           *   '<S14>/Constant1'
                                           *   '<S14>/Constant2'
                                           *   '<S14>/Saturation'
                                           *   '<S15>/Constant'
                                           *   '<S15>/Constant1'
                                           *   '<S15>/Constant2'
                                           *   '<S15>/Saturation'
                                           *   '<S16>/Constant'
                                           *   '<S16>/Constant1'
                                           *   '<S16>/Constant2'
                                           *   '<S16>/Saturation'
                                           */
  struct_o6lBeR5a4wCQZKjH0CEd8D Serial_Recieve_from_Pixhawk_Serial;
                           /* Mask Parameter: Serial_Recieve_from_Pixhawk_Serial
                            * Referenced by: '<S21>/Packet Input'
                            */
  struct_o6lBeR5a4wCQZKjH0CEd8D Serial_Send_to_Pixhawk_Serial;
                                /* Mask Parameter: Serial_Send_to_Pixhawk_Serial
                                 * Referenced by: '<S31>/Packet Output'
                                 */
  struct_RIcaXENoLMkyG3vAzx3LrF Communication_FT_HWI_ControlComputer_HW;
                      /* Mask Parameter: Communication_FT_HWI_ControlComputer_HW
                       * Referenced by:
                       *   '<S34>/Receive_from_FTHWICC'
                       *   '<S37>/Send_to_FTHWICC'
                       */
  real_T RealTimeSynchronization_MaxMissedTicks;
                       /* Mask Parameter: RealTimeSynchronization_MaxMissedTicks
                        * Referenced by: '<S237>/Real-Time Synchronization'
                        */
  real_T PacketInput_YieldWhenWaiting;
                                 /* Mask Parameter: PacketInput_YieldWhenWaiting
                                  * Referenced by: '<S21>/Packet Input'
                                  */
  real_T PacketOutput_YieldWhenWaiting;
                                /* Mask Parameter: PacketOutput_YieldWhenWaiting
                                 * Referenced by: '<S31>/Packet Output'
                                 */
  real_T Send_to_FTHWICC_YieldWhenWaiting;
                             /* Mask Parameter: Send_to_FTHWICC_YieldWhenWaiting
                              * Referenced by: '<S37>/Send_to_FTHWICC'
                              */
  real_T RealTimeSynchronization_YieldWhenWaiting;
                     /* Mask Parameter: RealTimeSynchronization_YieldWhenWaiting
                      * Referenced by: '<S237>/Real-Time Synchronization'
                      */
  real_T Receive_from_FTHWICC_YieldWhenWaiting;
                        /* Mask Parameter: Receive_from_FTHWICC_YieldWhenWaiting
                         * Referenced by: '<S34>/Receive_from_FTHWICC'
                         */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S242>/Constant'
                                       */
  real_T CompareToConstant_const_i; /* Mask Parameter: CompareToConstant_const_i
                                     * Referenced by: '<S112>/Constant'
                                     */
  real_T Rudder_d_siB_0;               /* Mask Parameter: Rudder_d_siB_0
                                        * Referenced by: '<S125>/Integrator'
                                        */
  real_T Rudder1_d_siB_0;              /* Mask Parameter: Rudder1_d_siB_0
                                        * Referenced by: '<S126>/Integrator'
                                        */
  real_T Rudder2_d_siB_0;              /* Mask Parameter: Rudder2_d_siB_0
                                        * Referenced by: '<S127>/Integrator'
                                        */
  real_T Rudder3_d_siB_0;              /* Mask Parameter: Rudder3_d_siB_0
                                        * Referenced by: '<S128>/Integrator'
                                        */
  real_T Rudder_d_siB_max;             /* Mask Parameter: Rudder_d_siB_max
                                        * Referenced by:
                                        *   '<S125>/Limiting_Acceleration'
                                        *   '<S125>/Limiting_Rate'
                                        */
  real_T Rudder1_d_siB_max;            /* Mask Parameter: Rudder1_d_siB_max
                                        * Referenced by:
                                        *   '<S126>/Limiting_Acceleration'
                                        *   '<S126>/Limiting_Rate'
                                        */
  real_T Rudder2_d_siB_max;            /* Mask Parameter: Rudder2_d_siB_max
                                        * Referenced by:
                                        *   '<S127>/Limiting_Acceleration'
                                        *   '<S127>/Limiting_Rate'
                                        */
  real_T Rudder3_d_siB_max;            /* Mask Parameter: Rudder3_d_siB_max
                                        * Referenced by:
                                        *   '<S128>/Limiting_Acceleration'
                                        *   '<S128>/Limiting_Rate'
                                        */
  real_T Rudder_d_siB_min;             /* Mask Parameter: Rudder_d_siB_min
                                        * Referenced by:
                                        *   '<S125>/Limiting_Acceleration'
                                        *   '<S125>/Limiting_Rate'
                                        */
  real_T Rudder1_d_siB_min;            /* Mask Parameter: Rudder1_d_siB_min
                                        * Referenced by:
                                        *   '<S126>/Limiting_Acceleration'
                                        *   '<S126>/Limiting_Rate'
                                        */
  real_T Rudder2_d_siB_min;            /* Mask Parameter: Rudder2_d_siB_min
                                        * Referenced by:
                                        *   '<S127>/Limiting_Acceleration'
                                        *   '<S127>/Limiting_Rate'
                                        */
  real_T Rudder3_d_siB_min;            /* Mask Parameter: Rudder3_d_siB_min
                                        * Referenced by:
                                        *   '<S128>/Limiting_Acceleration'
                                        *   '<S128>/Limiting_Rate'
                                        */
  real_T Rudder_dd_siB_max;            /* Mask Parameter: Rudder_dd_siB_max
                                        * Referenced by: '<S125>/Limiting_Acceleration'
                                        */
  real_T Rudder1_dd_siB_max;           /* Mask Parameter: Rudder1_dd_siB_max
                                        * Referenced by: '<S126>/Limiting_Acceleration'
                                        */
  real_T Rudder2_dd_siB_max;           /* Mask Parameter: Rudder2_dd_siB_max
                                        * Referenced by: '<S127>/Limiting_Acceleration'
                                        */
  real_T Rudder3_dd_siB_max;           /* Mask Parameter: Rudder3_dd_siB_max
                                        * Referenced by: '<S128>/Limiting_Acceleration'
                                        */
  real_T Rudder_dd_siB_min;            /* Mask Parameter: Rudder_dd_siB_min
                                        * Referenced by: '<S125>/Limiting_Acceleration'
                                        */
  real_T Rudder1_dd_siB_min;           /* Mask Parameter: Rudder1_dd_siB_min
                                        * Referenced by: '<S126>/Limiting_Acceleration'
                                        */
  real_T Rudder2_dd_siB_min;           /* Mask Parameter: Rudder2_dd_siB_min
                                        * Referenced by: '<S127>/Limiting_Acceleration'
                                        */
  real_T Rudder3_dd_siB_min;           /* Mask Parameter: Rudder3_dd_siB_min
                                        * Referenced by: '<S128>/Limiting_Acceleration'
                                        */
  real_T Rudder_dmp;                   /* Mask Parameter: Rudder_dmp
                                        * Referenced by: '<S125>/Gain2'
                                        */
  real_T Rudder1_dmp;                  /* Mask Parameter: Rudder1_dmp
                                        * Referenced by: '<S126>/Gain2'
                                        */
  real_T Rudder2_dmp;                  /* Mask Parameter: Rudder2_dmp
                                        * Referenced by: '<S127>/Gain2'
                                        */
  real_T Rudder3_dmp;                  /* Mask Parameter: Rudder3_dmp
                                        * Referenced by: '<S128>/Gain2'
                                        */
  real_T Rigid_Body_EOM_6_DOF_flag_Kraft;
                              /* Mask Parameter: Rigid_Body_EOM_6_DOF_flag_Kraft
                               * Referenced by: '<S188>/Constant'
                               */
  real_T WGS84_Gravitation_flg_omega_enabled;
                          /* Mask Parameter: WGS84_Gravitation_flg_omega_enabled
                           * Referenced by: '<S109>/WGS84_Gravity_Implementation'
                           */
  real_T IntervalTest_lowlimit;        /* Mask Parameter: IntervalTest_lowlimit
                                        * Referenced by: '<S113>/Lower Limit'
                                        */
  real_T IntervalTest1_lowlimit;       /* Mask Parameter: IntervalTest1_lowlimit
                                        * Referenced by: '<S114>/Lower Limit'
                                        */
  real_T geopot_height_mean_earth_radius;
                              /* Mask Parameter: geopot_height_mean_earth_radius
                               * Referenced by: '<S120>/mean_earth_radius'
                               */
  real_T Rudder_omega;                 /* Mask Parameter: Rudder_omega
                                        * Referenced by: '<S125>/Gain2'
                                        */
  real_T Rudder1_omega;                /* Mask Parameter: Rudder1_omega
                                        * Referenced by: '<S126>/Gain2'
                                        */
  real_T Rudder2_omega;                /* Mask Parameter: Rudder2_omega
                                        * Referenced by: '<S127>/Gain2'
                                        */
  real_T Rudder3_omega;                /* Mask Parameter: Rudder3_omega
                                        * Referenced by: '<S128>/Gain2'
                                        */
  real_T u_rot_mat_rot_1;              /* Mask Parameter: u_rot_mat_rot_1
                                        * Referenced by: '<S210>/Constant'
                                        */
  real_T u_rot_mat_rot_1_m;            /* Mask Parameter: u_rot_mat_rot_1_m
                                        * Referenced by: '<S170>/Constant'
                                        */
  real_T u_rot_mat_rot_1_md;           /* Mask Parameter: u_rot_mat_rot_1_md
                                        * Referenced by: '<S225>/Constant'
                                        */
  real_T u_rot_mat_rot_2;              /* Mask Parameter: u_rot_mat_rot_2
                                        * Referenced by: '<S170>/Constant1'
                                        */
  real_T u_rot_mat_rot_2_h;            /* Mask Parameter: u_rot_mat_rot_2_h
                                        * Referenced by: '<S225>/Constant1'
                                        */
  real_T u_rot_mat_rot_3;              /* Mask Parameter: u_rot_mat_rot_3
                                        * Referenced by: '<S170>/Constant2'
                                        */
  real_T u_rot_mat_rot_3_m;            /* Mask Parameter: u_rot_mat_rot_3_m
                                        * Referenced by: '<S225>/Constant2'
                                        */
  real_T Rudder_siB_0;                 /* Mask Parameter: Rudder_siB_0
                                        * Referenced by: '<S125>/Integrator1'
                                        */
  real_T Rudder1_siB_0;                /* Mask Parameter: Rudder1_siB_0
                                        * Referenced by: '<S126>/Integrator1'
                                        */
  real_T Rudder2_siB_0;                /* Mask Parameter: Rudder2_siB_0
                                        * Referenced by: '<S127>/Integrator1'
                                        */
  real_T Rudder3_siB_0;                /* Mask Parameter: Rudder3_siB_0
                                        * Referenced by: '<S128>/Integrator1'
                                        */
  real_T Rudder_siB_max;               /* Mask Parameter: Rudder_siB_max
                                        * Referenced by:
                                        *   '<S125>/Limiting_Acceleration'
                                        *   '<S125>/Limiting_Rate'
                                        *   '<S125>/Integrator1'
                                        *   '<S125>/Saturation'
                                        *   '<S125>/Saturation1'
                                        */
  real_T Rudder1_siB_max;              /* Mask Parameter: Rudder1_siB_max
                                        * Referenced by:
                                        *   '<S126>/Limiting_Acceleration'
                                        *   '<S126>/Limiting_Rate'
                                        *   '<S126>/Integrator1'
                                        *   '<S126>/Saturation'
                                        *   '<S126>/Saturation1'
                                        */
  real_T Rudder2_siB_max;              /* Mask Parameter: Rudder2_siB_max
                                        * Referenced by:
                                        *   '<S127>/Limiting_Acceleration'
                                        *   '<S127>/Limiting_Rate'
                                        *   '<S127>/Integrator1'
                                        *   '<S127>/Saturation'
                                        *   '<S127>/Saturation1'
                                        */
  real_T Rudder3_siB_max;              /* Mask Parameter: Rudder3_siB_max
                                        * Referenced by:
                                        *   '<S128>/Limiting_Acceleration'
                                        *   '<S128>/Limiting_Rate'
                                        *   '<S128>/Integrator1'
                                        *   '<S128>/Saturation'
                                        *   '<S128>/Saturation1'
                                        */
  real_T Rudder_siB_min;               /* Mask Parameter: Rudder_siB_min
                                        * Referenced by:
                                        *   '<S125>/Limiting_Acceleration'
                                        *   '<S125>/Limiting_Rate'
                                        *   '<S125>/Integrator1'
                                        *   '<S125>/Saturation'
                                        *   '<S125>/Saturation1'
                                        */
  real_T Rudder1_siB_min;              /* Mask Parameter: Rudder1_siB_min
                                        * Referenced by:
                                        *   '<S126>/Limiting_Acceleration'
                                        *   '<S126>/Limiting_Rate'
                                        *   '<S126>/Integrator1'
                                        *   '<S126>/Saturation'
                                        *   '<S126>/Saturation1'
                                        */
  real_T Rudder2_siB_min;              /* Mask Parameter: Rudder2_siB_min
                                        * Referenced by:
                                        *   '<S127>/Limiting_Acceleration'
                                        *   '<S127>/Limiting_Rate'
                                        *   '<S127>/Integrator1'
                                        *   '<S127>/Saturation'
                                        *   '<S127>/Saturation1'
                                        */
  real_T Rudder3_siB_min;              /* Mask Parameter: Rudder3_siB_min
                                        * Referenced by:
                                        *   '<S128>/Limiting_Acceleration'
                                        *   '<S128>/Limiting_Rate'
                                        *   '<S128>/Integrator1'
                                        *   '<S128>/Saturation'
                                        *   '<S128>/Saturation1'
                                        */
  real_T Rudder_unc_bl;                /* Mask Parameter: Rudder_unc_bl
                                        * Referenced by: '<S125>/Gain3'
                                        */
  real_T Rudder1_unc_bl;               /* Mask Parameter: Rudder1_unc_bl
                                        * Referenced by: '<S126>/Gain3'
                                        */
  real_T Rudder2_unc_bl;               /* Mask Parameter: Rudder2_unc_bl
                                        * Referenced by: '<S127>/Gain3'
                                        */
  real_T Rudder3_unc_bl;               /* Mask Parameter: Rudder3_unc_bl
                                        * Referenced by: '<S128>/Gain3'
                                        */
  real_T Rudder_unc_off;               /* Mask Parameter: Rudder_unc_off
                                        * Referenced by: '<S125>/Constant'
                                        */
  real_T Rudder1_unc_off;              /* Mask Parameter: Rudder1_unc_off
                                        * Referenced by: '<S126>/Constant'
                                        */
  real_T Rudder2_unc_off;              /* Mask Parameter: Rudder2_unc_off
                                        * Referenced by: '<S127>/Constant'
                                        */
  real_T Rudder3_unc_off;              /* Mask Parameter: Rudder3_unc_off
                                        * Referenced by: '<S128>/Constant'
                                        */
  real_T Rudder_unc_scale;             /* Mask Parameter: Rudder_unc_scale
                                        * Referenced by: '<S125>/Gain1'
                                        */
  real_T Rudder1_unc_scale;            /* Mask Parameter: Rudder1_unc_scale
                                        * Referenced by: '<S126>/Gain1'
                                        */
  real_T Rudder2_unc_scale;            /* Mask Parameter: Rudder2_unc_scale
                                        * Referenced by: '<S127>/Gain1'
                                        */
  real_T Rudder3_unc_scale;            /* Mask Parameter: Rudder3_unc_scale
                                        * Referenced by: '<S128>/Gain1'
                                        */
  real_T IntervalTest_uplimit;         /* Mask Parameter: IntervalTest_uplimit
                                        * Referenced by: '<S113>/Upper Limit'
                                        */
  real_T IntervalTest1_uplimit;        /* Mask Parameter: IntervalTest1_uplimit
                                        * Referenced by: '<S114>/Upper Limit'
                                        */
  int32_T PacketInput_PacketID;        /* Mask Parameter: PacketInput_PacketID
                                        * Referenced by: '<S21>/Packet Input'
                                        */
  int32_T PacketOutput_PacketID;       /* Mask Parameter: PacketOutput_PacketID
                                        * Referenced by: '<S31>/Packet Output'
                                        */
  int32_T Send_to_FTHWICC_PacketID;  /* Mask Parameter: Send_to_FTHWICC_PacketID
                                      * Referenced by: '<S37>/Send_to_FTHWICC'
                                      */
  int32_T Receive_from_FTHWICC_PacketID;
                                /* Mask Parameter: Receive_from_FTHWICC_PacketID
                                 * Referenced by: '<S34>/Receive_from_FTHWICC'
                                 */
  uint16_T WrapToZero_Threshold;       /* Mask Parameter: WrapToZero_Threshold
                                        * Referenced by: '<S241>/FixPt Switch'
                                        */
  struct_VkUZsEuPLDWiHwBdN4zERD Gimbal_Pos_Encoder_Y0;
                                    /* Computed Parameter: Gimbal_Pos_Encoder_Y0
                                     * Referenced by: '<S36>/Gimbal_Pos_Encoder'
                                     */
  struct_mYS1N2caX135AIcTArxUzD Gimbal_Pos_Y0;/* Computed Parameter: Gimbal_Pos_Y0
                                               * Referenced by: '<S36>/Gimbal_Pos'
                                               */
  Gimbal_Status_Bus Gimbal_Status_Y0;  /* Computed Parameter: Gimbal_Status_Y0
                                        * Referenced by: '<S36>/Gimbal_Status'
                                        */
  real_T Constant11_Value;             /* Expression: 1
                                        * Referenced by: '<S17>/Constant11'
                                        */
  real_T Constant14_Value;             /* Expression: 1
                                        * Referenced by: '<S17>/Constant14'
                                        */
  real_T Constant7_Value;              /* Expression: 1
                                        * Referenced by: '<S17>/Constant7'
                                        */
  real_T Constant12_Value;             /* Expression: 1
                                        * Referenced by: '<S17>/Constant12'
                                        */
  real_T Constant9_Value;              /* Expression: 1
                                        * Referenced by: '<S17>/Constant9'
                                        */
  real_T Constant13_Value;             /* Expression: 1
                                        * Referenced by: '<S17>/Constant13'
                                        */
  real_T status_Y0;                    /* Computed Parameter: status_Y0
                                        * Referenced by: '<S28>/status'
                                        */
  real_T One_Value;                    /* Expression: 1
                                        * Referenced by: '<S28>/One'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S28>/Constant'
                                        */
  real_T ComCheck_Y0;                  /* Computed Parameter: ComCheck_Y0
                                        * Referenced by: '<S36>/ComCheck'
                                        */
  real_T Constant_Value_n;             /* Expression: -1
                                        * Referenced by: '<S40>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: -1
                                        * Referenced by: '<S40>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: -1
                                        * Referenced by: '<S40>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: -1
                                        * Referenced by: '<S40>/Constant3'
                                        */
  real_T Constant4_Value;              /* Expression: -1
                                        * Referenced by: '<S40>/Constant4'
                                        */
  real_T Constant5_Value;              /* Expression: -1
                                        * Referenced by: '<S40>/Constant5'
                                        */
  real_T Constant6_Value;              /* Expression: -1
                                        * Referenced by: '<S40>/Constant6'
                                        */
  real_T Constant7_Value_a;            /* Expression: -1
                                        * Referenced by: '<S40>/Constant7'
                                        */
  real_T Constant10_Value;             /* Expression: -1
                                        * Referenced by: '<S40>/Constant10'
                                        */
  real_T Constant11_Value_c;           /* Expression: -1
                                        * Referenced by: '<S40>/Constant11'
                                        */
  real_T Constant8_Value;              /* Expression: -1
                                        * Referenced by: '<S40>/Constant8'
                                        */
  real_T Constant9_Value_m;            /* Expression: -1
                                        * Referenced by: '<S40>/Constant9'
                                        */
  real_T Shaft2radYaw_Gain;            /* Expression: (2*pi)/(65536)
                                        * Referenced by: '<S39>/Shaft2radYaw'
                                        */
  real_T Shaft2radPitch_Gain;          /* Expression: -(2*pi)/(65536)
                                        * Referenced by: '<S39>/Shaft2radPitch'
                                        */
  real_T Shaft2radRoll_Gain;           /* Expression: -(2*pi)/(65536)
                                        * Referenced by: '<S39>/Shaft2radRoll'
                                        */
  real_T u2_Gain;                      /* Expression: 0.5
                                        * Referenced by: '<S42>/1//2'
                                        */
  real_T c_flat_Value;                 /* Expression: c_flat
                                        * Referenced by: '<S82>/c_flat'
                                        */
  real_T Gain_Gain;                    /* Expression: 2
                                        * Referenced by: '<S83>/Gain'
                                        */
  real_T Constant_Value_g;             /* Expression: 1
                                        * Referenced by: '<S84>/Constant'
                                        */
  real_T c_rsma_Value;                 /* Expression: c_rsma
                                        * Referenced by: '<S82>/c_rsma'
                                        */
  real_T Gain_Gain_c;                  /* Expression: 2
                                        * Referenced by: '<S84>/Gain'
                                        */
  real_T Constant_Value_j;             /* Expression: 1
                                        * Referenced by: '<S83>/Constant'
                                        */
  real_T Gain_Gain_i;                  /* Expression: -1
                                        * Referenced by: '<S81>/Gain'
                                        */
  real_T Cn_delta_n_Interpolation_Table[2601];
                           /* Expression: HIL_Data.FDM.soph.bus1.aero.Cn_delta_n
                            * Referenced by: '<S91>/Cn_delta_n_Interpolation'
                            */
  real_T Cn_delta_m_Interpolation_Table[2601];
                           /* Expression: HIL_Data.FDM.soph.bus1.aero.Cn_delta_m
                            * Referenced by: '<S91>/Cn_delta_m_Interpolation'
                            */
  real_T Cn_delta_l_Interpolation_Table[2601];
                           /* Expression: HIL_Data.FDM.soph.bus1.aero.Cn_delta_l
                            * Referenced by: '<S91>/Cn_delta_l_Interpolation'
                            */
  real_T Cnr_Interpolation_Table[2601];
                                  /* Expression: HIL_Data.FDM.soph.bus1.aero.Cnr
                                   * Referenced by: '<S91>/Cnr_Interpolation'
                                   */
  real_T Cnq_Interpolation_Table[2601];
                                  /* Expression: HIL_Data.FDM.soph.bus1.aero.Cnq
                                   * Referenced by: '<S91>/Cnq_Interpolation'
                                   */
  real_T Cnp_Interpolation_Table[2601];
                                  /* Expression: HIL_Data.FDM.soph.bus1.aero.Cnp
                                   * Referenced by: '<S91>/Cnp_Interpolation'
                                   */
  real_T Cn_Interpolation_Table[2601];
                                   /* Expression: HIL_Data.FDM.soph.bus1.aero.Cn
                                    * Referenced by: '<S91>/Cn_Interpolation'
                                    */
  real_T Cm_delta_n_Interpolation_Table[2601];
                           /* Expression: HIL_Data.FDM.soph.bus1.aero.Cm_delta_n
                            * Referenced by: '<S90>/Cm_delta_n_Interpolation'
                            */
  real_T Cm_delta_m_Interpolation_Table[2601];
                           /* Expression: HIL_Data.FDM.soph.bus1.aero.Cm_delta_m
                            * Referenced by: '<S90>/Cm_delta_m_Interpolation'
                            */
  real_T Cm_delta_l_Interpolation_Table[2601];
                           /* Expression: HIL_Data.FDM.soph.bus1.aero.Cm_delta_l
                            * Referenced by: '<S90>/Cm_delta_l_Interpolation'
                            */
  real_T Cmr_Interpolation_Table[2601];
                                  /* Expression: HIL_Data.FDM.soph.bus1.aero.Cmr
                                   * Referenced by: '<S90>/Cmr_Interpolation'
                                   */
  real_T Cmq_Interpolation_Table[2601];
                                  /* Expression: HIL_Data.FDM.soph.bus1.aero.Cmq
                                   * Referenced by: '<S90>/Cmq_Interpolation'
                                   */
  real_T Cmp_Interpolation_Table[2601];
                                  /* Expression: HIL_Data.FDM.soph.bus1.aero.Cmp
                                   * Referenced by: '<S90>/Cmp_Interpolation'
                                   */
  real_T Cm_Interpolation_Table[2601];
                                   /* Expression: HIL_Data.FDM.soph.bus1.aero.Cm
                                    * Referenced by: '<S90>/Cm_Interpolation'
                                    */
  real_T Cl_delta_n_Interpolation_Table[2601];
                           /* Expression: HIL_Data.FDM.soph.bus1.aero.Cl_delta_n
                            * Referenced by: '<S89>/Cl_delta_n_Interpolation'
                            */
  real_T Cl_delta_m_Interpolation_Table[2601];
                           /* Expression: HIL_Data.FDM.soph.bus1.aero.Cl_delta_m
                            * Referenced by: '<S89>/Cl_delta_m_Interpolation'
                            */
  real_T Cl_delta_l_Interpolation_Table[2601];
                           /* Expression: HIL_Data.FDM.soph.bus1.aero.Cl_delta_l
                            * Referenced by: '<S89>/Cl_delta_l_Interpolation'
                            */
  real_T Clr_Interpolation_Table[2601];
                                  /* Expression: HIL_Data.FDM.soph.bus1.aero.Clr
                                   * Referenced by: '<S89>/Clr_Interpolation'
                                   */
  real_T Clq_Interpolation_Table[2601];
                                  /* Expression: HIL_Data.FDM.soph.bus1.aero.Clq
                                   * Referenced by: '<S89>/Clq_Interpolation'
                                   */
  real_T Clp_Interpolation_Table[2601];
                                  /* Expression: HIL_Data.FDM.soph.bus1.aero.Clp
                                   * Referenced by: '<S89>/Clp_Interpolation'
                                   */
  real_T Cl_Interpolation_Table[2601];
                                   /* Expression: HIL_Data.FDM.soph.bus1.aero.Cl
                                    * Referenced by: '<S89>/Cl_Interpolation'
                                    */
  real_T c_flat_Value_f;               /* Expression: c_flat
                                        * Referenced by: '<S86>/c_flat'
                                        */
  real_T Gain_Gain_a;                  /* Expression: 2
                                        * Referenced by: '<S87>/Gain'
                                        */
  real_T Constant_Value_f;             /* Expression: 1
                                        * Referenced by: '<S88>/Constant'
                                        */
  real_T c_rsma_Value_b;               /* Expression: c_rsma
                                        * Referenced by: '<S86>/c_rsma'
                                        */
  real_T Gain_Gain_o;                  /* Expression: 2
                                        * Referenced by: '<S88>/Gain'
                                        */
  real_T Constant_Value_m;             /* Expression: 1
                                        * Referenced by: '<S87>/Constant'
                                        */
  real_T Gain_Gain_f;                  /* Expression: -1
                                        * Referenced by: '<S85>/Gain'
                                        */
  real_T WGS84_Gravity_Implementation_c_b_WGS;/* Expression: c_b_WGS
                                               * Referenced by: '<S109>/WGS84_Gravity_Implementation'
                                               */
  real_T WGS84_Gravity_Implementation_c_grav;/* Expression: c_grav
                                              * Referenced by: '<S109>/WGS84_Gravity_Implementation'
                                              */
  real_T WGS84_Gravity_Implementation_c_rot;/* Expression: c_rot
                                             * Referenced by: '<S109>/WGS84_Gravity_Implementation'
                                             */
  real_T WGS84_Gravity_Implementation_c_rsma;/* Expression: c_rsma
                                              * Referenced by: '<S109>/WGS84_Gravity_Implementation'
                                              */
  real_T c_flat_Value_c;               /* Expression: c_flat
                                        * Referenced by: '<S140>/c_flat'
                                        */
  real_T Gain_Gain_l;                  /* Expression: 2
                                        * Referenced by: '<S141>/Gain'
                                        */
  real_T Constant_Value_e;             /* Expression: 1
                                        * Referenced by: '<S142>/Constant'
                                        */
  real_T c_rsma_Value_m;               /* Expression: c_rsma
                                        * Referenced by: '<S140>/c_rsma'
                                        */
  real_T Gain_Gain_j;                  /* Expression: 2
                                        * Referenced by: '<S142>/Gain'
                                        */
  real_T Constant_Value_o;             /* Expression: 1
                                        * Referenced by: '<S141>/Constant'
                                        */
  real_T Gain_Gain_g;                  /* Expression: -1
                                        * Referenced by: '<S139>/Gain'
                                        */
  real_T Constant8_Value_b;            /* Expression: 0
                                        * Referenced by: '<S156>/Constant8'
                                        */
  real_T Constant7_Value_i;          /* Expression: HIL_Data.FDM.soph.bus2.c_rot
                                      * Referenced by: '<S156>/Constant7'
                                      */
  real_T Constant6_Value_j;            /* Expression: 0
                                        * Referenced by: '<S156>/Constant6'
                                        */
  real_T Gain2_Gain;                   /* Expression: -1
                                        * Referenced by: '<S159>/Gain2'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S159>/Gain1'
                                        */
  real_T Saturation_UpperSat;  /* Expression: HIL_Data.FDM.soph.bus1.t_prp1(end)
                                * Referenced by: '<S168>/Saturation'
                                */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S168>/Saturation'
                                        */
  real_T thrust_lookup_tableData[12];/* Expression: HIL_Data.FDM.soph.bus1.F_prp
                                      * Referenced by: '<S168>/thrust_lookup'
                                      */
  real_T thrust_lookup_bp01Data[12];/* Expression: HIL_Data.FDM.soph.bus1.t_prp1
                                     * Referenced by: '<S168>/thrust_lookup'
                                     */
  real_T Constant11_Value_o;           /* Expression: 1
                                        * Referenced by: '<S180>/Constant11'
                                        */
  real_T Constant10_Value_f;           /* Expression: 0
                                        * Referenced by: '<S180>/Constant10'
                                        */
  real_T Constant4_Value_b;            /* Expression: 0
                                        * Referenced by: '<S180>/Constant4'
                                        */
  real_T Constant7_Value_is;           /* Expression: 0
                                        * Referenced by: '<S180>/Constant7'
                                        */
  real_T Constant8_Value_d;            /* Expression: 0
                                        * Referenced by: '<S180>/Constant8'
                                        */
  real_T Gain_Gain_e;                  /* Expression: -1
                                        * Referenced by: '<S180>/Gain'
                                        */
  real_T Constant7_Value_a5;           /* Expression: 0
                                        * Referenced by: '<S179>/Constant7'
                                        */
  real_T Gain1_Gain_d;                 /* Expression: -1
                                        * Referenced by: '<S179>/Gain1'
                                        */
  real_T Constant2_Value_f;            /* Expression: 0
                                        * Referenced by: '<S179>/Constant2'
                                        */
  real_T Constant1_Value_k;            /* Expression: 1
                                        * Referenced by: '<S179>/Constant1'
                                        */
  real_T Constant_Value_ek;            /* Expression: 0
                                        * Referenced by: '<S179>/Constant'
                                        */
  real_T Constant8_Value_k;            /* Expression: 0
                                        * Referenced by: '<S179>/Constant8'
                                        */
  real_T Constant7_Value_k;            /* Expression: 0
                                        * Referenced by: '<S178>/Constant7'
                                        */
  real_T Gain_Gain_h;                  /* Expression: -1
                                        * Referenced by: '<S178>/Gain'
                                        */
  real_T Constant8_Value_a;            /* Expression: 0
                                        * Referenced by: '<S178>/Constant8'
                                        */
  real_T Constant2_Value_j;            /* Expression: 0
                                        * Referenced by: '<S178>/Constant2'
                                        */
  real_T Constant1_Value_j;            /* Expression: 0
                                        * Referenced by: '<S178>/Constant1'
                                        */
  real_T Constant_Value_d;             /* Expression: 1
                                        * Referenced by: '<S178>/Constant'
                                        */
  real_T Constant11_Value_p;           /* Expression: 1
                                        * Referenced by: '<S177>/Constant11'
                                        */
  real_T Constant10_Value_fw;          /* Expression: 0
                                        * Referenced by: '<S177>/Constant10'
                                        */
  real_T Constant4_Value_h;            /* Expression: 0
                                        * Referenced by: '<S177>/Constant4'
                                        */
  real_T Constant7_Value_d;            /* Expression: 0
                                        * Referenced by: '<S177>/Constant7'
                                        */
  real_T Constant8_Value_o;            /* Expression: 0
                                        * Referenced by: '<S177>/Constant8'
                                        */
  real_T Gain_Gain_hf;                 /* Expression: -1
                                        * Referenced by: '<S177>/Gain'
                                        */
  real_T Constant7_Value_ib;           /* Expression: 0
                                        * Referenced by: '<S176>/Constant7'
                                        */
  real_T Gain1_Gain_h;                 /* Expression: -1
                                        * Referenced by: '<S176>/Gain1'
                                        */
  real_T Constant2_Value_m;            /* Expression: 0
                                        * Referenced by: '<S176>/Constant2'
                                        */
  real_T Constant1_Value_l;            /* Expression: 1
                                        * Referenced by: '<S176>/Constant1'
                                        */
  real_T Constant_Value_dk;            /* Expression: 0
                                        * Referenced by: '<S176>/Constant'
                                        */
  real_T Constant8_Value_bs;           /* Expression: 0
                                        * Referenced by: '<S176>/Constant8'
                                        */
  real_T Constant7_Value_f;            /* Expression: 0
                                        * Referenced by: '<S175>/Constant7'
                                        */
  real_T Gain_Gain_jq;                 /* Expression: -1
                                        * Referenced by: '<S175>/Gain'
                                        */
  real_T Constant8_Value_e;            /* Expression: 0
                                        * Referenced by: '<S175>/Constant8'
                                        */
  real_T Constant2_Value_e;            /* Expression: 0
                                        * Referenced by: '<S175>/Constant2'
                                        */
  real_T Constant1_Value_n;            /* Expression: 0
                                        * Referenced by: '<S175>/Constant1'
                                        */
  real_T Constant_Value_a;             /* Expression: 1
                                        * Referenced by: '<S175>/Constant'
                                        */
  real_T Constant11_Value_l;           /* Expression: 1
                                        * Referenced by: '<S174>/Constant11'
                                        */
  real_T Constant10_Value_l;           /* Expression: 0
                                        * Referenced by: '<S174>/Constant10'
                                        */
  real_T Constant4_Value_l;            /* Expression: 0
                                        * Referenced by: '<S174>/Constant4'
                                        */
  real_T Constant7_Value_c;            /* Expression: 0
                                        * Referenced by: '<S174>/Constant7'
                                        */
  real_T Constant8_Value_f;            /* Expression: 0
                                        * Referenced by: '<S174>/Constant8'
                                        */
  real_T Gain_Gain_k;                  /* Expression: -1
                                        * Referenced by: '<S174>/Gain'
                                        */
  real_T Constant7_Value_f2;           /* Expression: 0
                                        * Referenced by: '<S173>/Constant7'
                                        */
  real_T Gain1_Gain_hx;                /* Expression: -1
                                        * Referenced by: '<S173>/Gain1'
                                        */
  real_T Constant2_Value_d;            /* Expression: 0
                                        * Referenced by: '<S173>/Constant2'
                                        */
  real_T Constant1_Value_b;            /* Expression: 1
                                        * Referenced by: '<S173>/Constant1'
                                        */
  real_T Constant_Value_nd;            /* Expression: 0
                                        * Referenced by: '<S173>/Constant'
                                        */
  real_T Constant8_Value_g;            /* Expression: 0
                                        * Referenced by: '<S173>/Constant8'
                                        */
  real_T Constant7_Value_b;            /* Expression: 0
                                        * Referenced by: '<S172>/Constant7'
                                        */
  real_T Gain_Gain_lj;                 /* Expression: -1
                                        * Referenced by: '<S172>/Gain'
                                        */
  real_T Constant8_Value_ks;           /* Expression: 0
                                        * Referenced by: '<S172>/Constant8'
                                        */
  real_T Constant2_Value_fh;           /* Expression: 0
                                        * Referenced by: '<S172>/Constant2'
                                        */
  real_T Constant1_Value_o;            /* Expression: 0
                                        * Referenced by: '<S172>/Constant1'
                                        */
  real_T Constant_Value_l;             /* Expression: 1
                                        * Referenced by: '<S172>/Constant'
                                        */
  real_T Gain_Gain_p;                  /* Expression: -1
                                        * Referenced by: '<S183>/Gain'
                                        */
  real_T Gain12_Gain;                  /* Expression: 2
                                        * Referenced by: '<S190>/Gain12'
                                        */
  real_T Gain11_Gain;                  /* Expression: 2
                                        * Referenced by: '<S190>/Gain11'
                                        */
  real_T Gain6_Gain;                   /* Expression: 2
                                        * Referenced by: '<S190>/Gain6'
                                        */
  real_T Gain5_Gain;                   /* Expression: 2
                                        * Referenced by: '<S190>/Gain5'
                                        */
  real_T Gain4_Gain;                   /* Expression: 2
                                        * Referenced by: '<S190>/Gain4'
                                        */
  real_T Gain3_Gain;                   /* Expression: 2
                                        * Referenced by: '<S190>/Gain3'
                                        */
  real_T Gain8_Gain;                   /* Expression: 2
                                        * Referenced by: '<S190>/Gain8'
                                        */
  real_T Gain7_Gain;                   /* Expression: 2
                                        * Referenced by: '<S190>/Gain7'
                                        */
  real_T Gain10_Gain;                  /* Expression: 2
                                        * Referenced by: '<S190>/Gain10'
                                        */
  real_T Gain9_Gain;                   /* Expression: 2
                                        * Referenced by: '<S190>/Gain9'
                                        */
  real_T Gain2_Gain_i;                 /* Expression: 2
                                        * Referenced by: '<S190>/Gain2'
                                        */
  real_T Gain1_Gain_m;                 /* Expression: 2
                                        * Referenced by: '<S190>/Gain1'
                                        */
  real_T Constant11_Value_a;           /* Expression: 1
                                        * Referenced by: '<S213>/Constant11'
                                        */
  real_T Constant10_Value_d;           /* Expression: 0
                                        * Referenced by: '<S213>/Constant10'
                                        */
  real_T Constant4_Value_o;            /* Expression: 0
                                        * Referenced by: '<S213>/Constant4'
                                        */
  real_T Constant7_Value_g;            /* Expression: 0
                                        * Referenced by: '<S213>/Constant7'
                                        */
  real_T Constant8_Value_gg;           /* Expression: 0
                                        * Referenced by: '<S213>/Constant8'
                                        */
  real_T Gain_Gain_jn;                 /* Expression: -1
                                        * Referenced by: '<S213>/Gain'
                                        */
  real_T Constant7_Value_d1;           /* Expression: 0
                                        * Referenced by: '<S212>/Constant7'
                                        */
  real_T Gain1_Gain_j;                 /* Expression: -1
                                        * Referenced by: '<S212>/Gain1'
                                        */
  real_T Constant2_Value_g;            /* Expression: 0
                                        * Referenced by: '<S212>/Constant2'
                                        */
  real_T Constant1_Value_i;            /* Expression: 1
                                        * Referenced by: '<S212>/Constant1'
                                        */
  real_T Constant_Value_ob;            /* Expression: 0
                                        * Referenced by: '<S212>/Constant'
                                        */
  real_T Constant8_Value_ky;           /* Expression: 0
                                        * Referenced by: '<S212>/Constant8'
                                        */
  real_T Constant7_Value_j;            /* Expression: 0
                                        * Referenced by: '<S211>/Constant7'
                                        */
  real_T Gain_Gain_kj;                 /* Expression: -1
                                        * Referenced by: '<S211>/Gain'
                                        */
  real_T Constant8_Value_af;           /* Expression: 0
                                        * Referenced by: '<S211>/Constant8'
                                        */
  real_T Constant2_Value_b;            /* Expression: 0
                                        * Referenced by: '<S211>/Constant2'
                                        */
  real_T Constant1_Value_c;            /* Expression: 0
                                        * Referenced by: '<S211>/Constant1'
                                        */
  real_T Constant_Value_h;             /* Expression: 1
                                        * Referenced by: '<S211>/Constant'
                                        */
  real_T Saturation_UpperSat_c;/* Expression: HIL_Data.FDM.soph.bus1.t_prp2(end)
                                * Referenced by: '<S216>/Saturation'
                                */
  real_T Saturation_LowerSat_h;        /* Expression: 0
                                        * Referenced by: '<S216>/Saturation'
                                        */
  real_T uDLookupTable_tableData[17];
                             /* Expression: HIL_Data.FDM.soph.bus1.m_fuel_lookup
                              * Referenced by: '<S216>/1-D Lookup Table'
                              */
  real_T uDLookupTable_bp01Data[17];/* Expression: HIL_Data.FDM.soph.bus1.t_prp2
                                     * Referenced by: '<S216>/1-D Lookup Table'
                                     */
  real_T Constant11_Value_h;           /* Expression: 1
                                        * Referenced by: '<S234>/Constant11'
                                        */
  real_T Constant10_Value_g;           /* Expression: 0
                                        * Referenced by: '<S234>/Constant10'
                                        */
  real_T Constant4_Value_a;            /* Expression: 0
                                        * Referenced by: '<S234>/Constant4'
                                        */
  real_T Constant7_Value_cr;           /* Expression: 0
                                        * Referenced by: '<S234>/Constant7'
                                        */
  real_T Constant8_Value_os;           /* Expression: 0
                                        * Referenced by: '<S234>/Constant8'
                                        */
  real_T Gain_Gain_ow;                 /* Expression: -1
                                        * Referenced by: '<S234>/Gain'
                                        */
  real_T Constant7_Value_jt;           /* Expression: 0
                                        * Referenced by: '<S233>/Constant7'
                                        */
  real_T Gain1_Gain_n;                 /* Expression: -1
                                        * Referenced by: '<S233>/Gain1'
                                        */
  real_T Constant2_Value_jp;           /* Expression: 0
                                        * Referenced by: '<S233>/Constant2'
                                        */
  real_T Constant1_Value_c4;           /* Expression: 1
                                        * Referenced by: '<S233>/Constant1'
                                        */
  real_T Constant_Value_p;             /* Expression: 0
                                        * Referenced by: '<S233>/Constant'
                                        */
  real_T Constant8_Value_c;            /* Expression: 0
                                        * Referenced by: '<S233>/Constant8'
                                        */
  real_T Constant7_Value_p;            /* Expression: 0
                                        * Referenced by: '<S232>/Constant7'
                                        */
  real_T Gain_Gain_pk;                 /* Expression: -1
                                        * Referenced by: '<S232>/Gain'
                                        */
  real_T Constant8_Value_cs;           /* Expression: 0
                                        * Referenced by: '<S232>/Constant8'
                                        */
  real_T Constant2_Value_bt;           /* Expression: 0
                                        * Referenced by: '<S232>/Constant2'
                                        */
  real_T Constant1_Value_f;            /* Expression: 0
                                        * Referenced by: '<S232>/Constant1'
                                        */
  real_T Constant_Value_i;             /* Expression: 1
                                        * Referenced by: '<S232>/Constant'
                                        */
  real_T Constant11_Value_l2;          /* Expression: 1
                                        * Referenced by: '<S231>/Constant11'
                                        */
  real_T Constant10_Value_m;           /* Expression: 0
                                        * Referenced by: '<S231>/Constant10'
                                        */
  real_T Constant4_Value_bq;           /* Expression: 0
                                        * Referenced by: '<S231>/Constant4'
                                        */
  real_T Constant7_Value_ch;           /* Expression: 0
                                        * Referenced by: '<S231>/Constant7'
                                        */
  real_T Constant8_Value_ke;           /* Expression: 0
                                        * Referenced by: '<S231>/Constant8'
                                        */
  real_T Gain_Gain_n;                  /* Expression: -1
                                        * Referenced by: '<S231>/Gain'
                                        */
  real_T Constant7_Value_fv;           /* Expression: 0
                                        * Referenced by: '<S230>/Constant7'
                                        */
  real_T Gain1_Gain_j0;                /* Expression: -1
                                        * Referenced by: '<S230>/Gain1'
                                        */
  real_T Constant2_Value_js;           /* Expression: 0
                                        * Referenced by: '<S230>/Constant2'
                                        */
  real_T Constant1_Value_a;            /* Expression: 1
                                        * Referenced by: '<S230>/Constant1'
                                        */
  real_T Constant_Value_c;             /* Expression: 0
                                        * Referenced by: '<S230>/Constant'
                                        */
  real_T Constant8_Value_dg;           /* Expression: 0
                                        * Referenced by: '<S230>/Constant8'
                                        */
  real_T Constant7_Value_n;            /* Expression: 0
                                        * Referenced by: '<S229>/Constant7'
                                        */
  real_T Gain_Gain_ax;                 /* Expression: -1
                                        * Referenced by: '<S229>/Gain'
                                        */
  real_T Constant8_Value_n;            /* Expression: 0
                                        * Referenced by: '<S229>/Constant8'
                                        */
  real_T Constant2_Value_c;            /* Expression: 0
                                        * Referenced by: '<S229>/Constant2'
                                        */
  real_T Constant1_Value_nq;           /* Expression: 0
                                        * Referenced by: '<S229>/Constant1'
                                        */
  real_T Constant_Value_lx;            /* Expression: 1
                                        * Referenced by: '<S229>/Constant'
                                        */
  real_T Constant11_Value_h1;          /* Expression: 1
                                        * Referenced by: '<S228>/Constant11'
                                        */
  real_T Constant10_Value_c;           /* Expression: 0
                                        * Referenced by: '<S228>/Constant10'
                                        */
  real_T Constant4_Value_l5;           /* Expression: 0
                                        * Referenced by: '<S228>/Constant4'
                                        */
  real_T Constant7_Value_p5;           /* Expression: 0
                                        * Referenced by: '<S228>/Constant7'
                                        */
  real_T Constant8_Value_gw;           /* Expression: 0
                                        * Referenced by: '<S228>/Constant8'
                                        */
  real_T Gain_Gain_f0;                 /* Expression: -1
                                        * Referenced by: '<S228>/Gain'
                                        */
  real_T Constant7_Value_je;           /* Expression: 0
                                        * Referenced by: '<S227>/Constant7'
                                        */
  real_T Gain1_Gain_hv;                /* Expression: -1
                                        * Referenced by: '<S227>/Gain1'
                                        */
  real_T Constant2_Value_i;            /* Expression: 0
                                        * Referenced by: '<S227>/Constant2'
                                        */
  real_T Constant1_Value_k0;           /* Expression: 1
                                        * Referenced by: '<S227>/Constant1'
                                        */
  real_T Constant_Value_hw;            /* Expression: 0
                                        * Referenced by: '<S227>/Constant'
                                        */
  real_T Constant8_Value_l;            /* Expression: 0
                                        * Referenced by: '<S227>/Constant8'
                                        */
  real_T Constant7_Value_gi;           /* Expression: 0
                                        * Referenced by: '<S226>/Constant7'
                                        */
  real_T Gain_Gain_cy;                 /* Expression: -1
                                        * Referenced by: '<S226>/Gain'
                                        */
  real_T Constant8_Value_j;            /* Expression: 0
                                        * Referenced by: '<S226>/Constant8'
                                        */
  real_T Constant2_Value_a;            /* Expression: 0
                                        * Referenced by: '<S226>/Constant2'
                                        */
  real_T Constant1_Value_g;            /* Expression: 0
                                        * Referenced by: '<S226>/Constant1'
                                        */
  real_T Constant_Value_of;            /* Expression: 1
                                        * Referenced by: '<S226>/Constant'
                                        */
  real_T Constant_Value_pl[13];
  /* Expression: [HIL_Data.FDM.soph.bus2.pBII_0; HIL_Data.FDM.soph.bus2.vBII_0; HIL_Data.FDM.soph.bus2.qIB_0; HIL_Data.FDM.soph.bus2.wBIB_0]
   * Referenced by: '<S182>/Constant'
   */
  real_T Gain17_Gain;                  /* Expression: 1
                                        * Referenced by: '<S49>/Gain17'
                                        */
  real_T Gain_Gain_pl;                 /* Expression: 1
                                        * Referenced by: '<S12>/Gain'
                                        */
  real_T Gain1_Gain_j5;                /* Expression: 1
                                        * Referenced by: '<S12>/Gain1'
                                        */
  real_T Gain2_Gain_g;                 /* Expression: 1
                                        * Referenced by: '<S12>/Gain2'
                                        */
  real_T Gain3_Gain_d;                 /* Expression: 1
                                        * Referenced by: '<S12>/Gain3'
                                        */
  real_T Constant_Value_ei;            /* Expression: -1
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Constant1_Value_d;            /* Expression: -1
                                        * Referenced by: '<S10>/Constant1'
                                        */
  real_T Constant2_Value_h;            /* Expression: -1
                                        * Referenced by: '<S10>/Constant2'
                                        */
  real_T Constant3_Value_o;            /* Expression: -1
                                        * Referenced by: '<S10>/Constant3'
                                        */
  real_T Constant4_Value_om;           /* Expression: -1
                                        * Referenced by: '<S10>/Constant4'
                                        */
  real_T Constant5_Value_m;            /* Expression: -1
                                        * Referenced by: '<S10>/Constant5'
                                        */
  real_T Constant6_Value_d;            /* Expression: -1
                                        * Referenced by: '<S10>/Constant6'
                                        */
  real_T Constant7_Value_ny;           /* Expression: -1
                                        * Referenced by: '<S10>/Constant7'
                                        */
  real_T Constant8_Value_lk;           /* Expression: -1
                                        * Referenced by: '<S10>/Constant8'
                                        */
  real_T Constant9_Value_e;            /* Expression: -1
                                        * Referenced by: '<S10>/Constant9'
                                        */
  real_T Constant10_Value_j;           /* Expression: -1
                                        * Referenced by: '<S10>/Constant10'
                                        */
  real_T Constant11_Value_i;           /* Expression: -1
                                        * Referenced by: '<S10>/Constant11'
                                        */
  real_T Gain1_Gain_c;                 /* Expression: 2
                                        * Referenced by: '<S147>/Gain1'
                                        */
  real_T Gain2_Gain_c;                 /* Expression: 2
                                        * Referenced by: '<S147>/Gain2'
                                        */
  real_T Gain9_Gain_c;                 /* Expression: 2
                                        * Referenced by: '<S147>/Gain9'
                                        */
  real_T Gain10_Gain_g;                /* Expression: 2
                                        * Referenced by: '<S147>/Gain10'
                                        */
  real_T Gain7_Gain_c;                 /* Expression: 2
                                        * Referenced by: '<S147>/Gain7'
                                        */
  real_T Gain8_Gain_b;                 /* Expression: 2
                                        * Referenced by: '<S147>/Gain8'
                                        */
  real_T Gain3_Gain_p;                 /* Expression: 2
                                        * Referenced by: '<S147>/Gain3'
                                        */
  real_T Gain4_Gain_o;                 /* Expression: 2
                                        * Referenced by: '<S147>/Gain4'
                                        */
  real_T Gain5_Gain_l;                 /* Expression: 2
                                        * Referenced by: '<S147>/Gain5'
                                        */
  real_T Gain6_Gain_p;                 /* Expression: 2
                                        * Referenced by: '<S147>/Gain6'
                                        */
  real_T Gain11_Gain_d;                /* Expression: 2
                                        * Referenced by: '<S147>/Gain11'
                                        */
  real_T Gain12_Gain_g;                /* Expression: 2
                                        * Referenced by: '<S147>/Gain12'
                                        */
  real_T Gain_Gain_k1;                 /* Expression: 1
                                        * Referenced by: '<S49>/Gain'
                                        */
  real_T Gain1_Gain_mm;                /* Expression: 1
                                        * Referenced by: '<S49>/Gain1'
                                        */
  real_T Gain2_Gain_e;                 /* Expression: 1
                                        * Referenced by: '<S49>/Gain2'
                                        */
  real_T Q_1_Value[16];    /* Expression: [0 0 0 1; 0 0 -1 0; 0 1 0 0; -1 0 0 0]
                            * Referenced by: '<S195>/Q~_1'
                            */
  real_T Q_2_Value[16];    /* Expression: [0 0 1 0; 0 0 0 1; -1 0 0 0; 0 -1 0 0]
                            * Referenced by: '<S195>/Q~_2'
                            */
  real_T Q_3_Value[16];    /* Expression: [0 -1 0 0; 1 0 0 0; 0 0 0 1; 0 0 -1 0]
                            * Referenced by: '<S195>/Q~_3'
                            */
  real_T Q_4_Value[16];      /* Expression: [1 0 0 0; 0 1 0 0; 0 0 1 0; 0 0 0 1]
                              * Referenced by: '<S195>/Q~_4'
                              */
  real_T Q_1_Value_i[16];  /* Expression: [0 0 0 1; 0 0 1 0; 0 -1 0 0; -1 0 0 0]
                            * Referenced by: '<S195>/Q_1'
                            */
  real_T Q_2_Value_n[16];  /* Expression: [0 0 -1 0; 0 0 0 1; 1 0 0 0; 0 -1 0 0]
                            * Referenced by: '<S195>/Q_2'
                            */
  real_T Q_3_Value_m[16];  /* Expression: [0 1 0 0; -1 0 0 0; 0 0 0 1; 0 0 -1 0]
                            * Referenced by: '<S195>/Q_3'
                            */
  real_T Q_4_Value_f[16];    /* Expression: [1 0 0 0; 0 1 0 0; 0 0 1 0; 0 0 0 1]
                              * Referenced by: '<S195>/Q_4'
                              */
  real_T Constant_Value_i3;
                         /* Expression: HIL_Data.FDM.soph.bus1.unc_aero_Cx_scale
                          * Referenced by: '<S92>/Constant'
                          */
  real_T Constant8_Value_i[4];       /* Expression: HIL_Data.FDM.soph.bus2.qIE_0
                                      * Referenced by: '<S157>/Constant8'
                                      */
  real_T Gain1_Gain_i;                 /* Expression: 2
                                        * Referenced by: '<S161>/Gain1'
                                        */
  real_T Gain2_Gain_iy;                /* Expression: 2
                                        * Referenced by: '<S161>/Gain2'
                                        */
  real_T Gain9_Gain_g;                 /* Expression: 2
                                        * Referenced by: '<S161>/Gain9'
                                        */
  real_T Gain10_Gain_h;                /* Expression: 2
                                        * Referenced by: '<S161>/Gain10'
                                        */
  real_T Gain7_Gain_i;                 /* Expression: 2
                                        * Referenced by: '<S161>/Gain7'
                                        */
  real_T Gain8_Gain_d;                 /* Expression: 2
                                        * Referenced by: '<S161>/Gain8'
                                        */
  real_T Gain3_Gain_i;                 /* Expression: 2
                                        * Referenced by: '<S161>/Gain3'
                                        */
  real_T Gain4_Gain_f;                 /* Expression: 2
                                        * Referenced by: '<S161>/Gain4'
                                        */
  real_T Gain5_Gain_i;                 /* Expression: 2
                                        * Referenced by: '<S161>/Gain5'
                                        */
  real_T Gain6_Gain_n;                 /* Expression: 2
                                        * Referenced by: '<S161>/Gain6'
                                        */
  real_T Gain11_Gain_n;                /* Expression: 2
                                        * Referenced by: '<S161>/Gain11'
                                        */
  real_T Gain12_Gain_h;                /* Expression: 2
                                        * Referenced by: '<S161>/Gain12'
                                        */
  real_T Constant9_Value_p;     /* Expression: HIL_Data.FDM.soph.bus2.flag_I_rot
                                 * Referenced by: '<S156>/Constant9'
                                 */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S156>/Switch'
                                        */
  real_T Q_1_Value_k[16];  /* Expression: [0 0 0 1; 0 0 1 0; 0 -1 0 0; -1 0 0 0]
                            * Referenced by: '<S150>/Q_1'
                            */
  real_T Q_1_Value_d[16];  /* Expression: [0 0 0 1; 0 0 1 0; 0 -1 0 0; -1 0 0 0]
                            * Referenced by: '<S152>/Q_1'
                            */
  real_T Q_2_Value_nt[16]; /* Expression: [0 0 -1 0; 0 0 0 1; 1 0 0 0; 0 -1 0 0]
                            * Referenced by: '<S152>/Q_2'
                            */
  real_T Q_3_Value_o[16];  /* Expression: [0 1 0 0; -1 0 0 0; 0 0 0 1; 0 0 -1 0]
                            * Referenced by: '<S152>/Q_3'
                            */
  real_T Q_4_Value_n[16];    /* Expression: [1 0 0 0; 0 1 0 0; 0 0 1 0; 0 0 0 1]
                              * Referenced by: '<S152>/Q_4'
                              */
  real_T Constant8_Value_oz[4];      /* Expression: HIL_Data.FDM.soph.bus2.qEG_0
                                      * Referenced by: '<S158>/Constant8'
                                      */
  real_T Constant_Value_gc;            /* Expression: 1
                                        * Referenced by: '<S152>/Constant'
                                        */
  real_T Constant1_Value_ja;           /* Expression: -1
                                        * Referenced by: '<S152>/Constant1'
                                        */
  real_T Switch_Threshold_g;           /* Expression: 0
                                        * Referenced by: '<S152>/Switch'
                                        */
  real_T Gain1_Gain_p;                 /* Expression: -1
                                        * Referenced by: '<S149>/Gain1'
                                        */
  real_T Q_2_Value_c[16];  /* Expression: [0 0 -1 0; 0 0 0 1; 1 0 0 0; 0 -1 0 0]
                            * Referenced by: '<S150>/Q_2'
                            */
  real_T Q_3_Value_f[16];  /* Expression: [0 1 0 0; -1 0 0 0; 0 0 0 1; 0 0 -1 0]
                            * Referenced by: '<S150>/Q_3'
                            */
  real_T Q_4_Value_e[16];    /* Expression: [1 0 0 0; 0 1 0 0; 0 0 1 0; 0 0 0 1]
                              * Referenced by: '<S150>/Q_4'
                              */
  real_T Constant_Value_ie;            /* Expression: 1
                                        * Referenced by: '<S150>/Constant'
                                        */
  real_T Constant1_Value_m;            /* Expression: -1
                                        * Referenced by: '<S150>/Constant1'
                                        */
  real_T Switch_Threshold_h;           /* Expression: 0
                                        * Referenced by: '<S150>/Switch'
                                        */
  real_T Gain1_Gain_e;                 /* Expression: 2
                                        * Referenced by: '<S148>/Gain1'
                                        */
  real_T Gain2_Gain_j;                 /* Expression: 2
                                        * Referenced by: '<S148>/Gain2'
                                        */
  real_T Gain9_Gain_m;                 /* Expression: 2
                                        * Referenced by: '<S148>/Gain9'
                                        */
  real_T Gain10_Gain_d;                /* Expression: 2
                                        * Referenced by: '<S148>/Gain10'
                                        */
  real_T Gain7_Gain_h;                 /* Expression: 2
                                        * Referenced by: '<S148>/Gain7'
                                        */
  real_T Gain8_Gain_l;                 /* Expression: 2
                                        * Referenced by: '<S148>/Gain8'
                                        */
  real_T Gain3_Gain_e;                 /* Expression: 2
                                        * Referenced by: '<S148>/Gain3'
                                        */
  real_T Gain4_Gain_c;                 /* Expression: 2
                                        * Referenced by: '<S148>/Gain4'
                                        */
  real_T Gain5_Gain_c;                 /* Expression: 2
                                        * Referenced by: '<S148>/Gain5'
                                        */
  real_T Gain6_Gain_b;                 /* Expression: 2
                                        * Referenced by: '<S148>/Gain6'
                                        */
  real_T Gain11_Gain_g;                /* Expression: 2
                                        * Referenced by: '<S148>/Gain11'
                                        */
  real_T Gain12_Gain_j;                /* Expression: 2
                                        * Referenced by: '<S148>/Gain12'
                                        */
  real_T course_angle_wind_Value;      /* Expression: HIL_Data.FDM.soph.bus2.chW
                                        * Referenced by: '<S208>/course_angle_wind'
                                        */
  real_T course_angle_uncertainty_Value;
                                /* Expression: HIL_Data.FDM.soph.bus1.unc_chW_bl
                                 * Referenced by: '<S208>/course_angle_uncertainty'
                                 */
  real_T vWW_uncertainty_Value;
                             /* Expression: HIL_Data.FDM.soph.bus1.unc_a_vBEW_bl
                              * Referenced by: '<S208>/vWW_uncertainty'
                              */
  real_T vWW_Value;                 /* Expression: HIL_Data.FDM.soph.bus2.a_vBEW
                                     * Referenced by: '<S208>/vWW'
                                     */
  real_T Constant1_Value_fr;           /* Expression: 0
                                        * Referenced by: '<S208>/Constant1'
                                        */
  real_T specific_gas_constant_Value;  /* Expression: HIL_Data.FDM.soph.bus2.sgc
                                        * Referenced by: '<S121>/specific_gas_constant'
                                        */
  real_T heat_capacity_ratio_Value;    /* Expression: HIL_Data.FDM.soph.bus2.hcr
                                        * Referenced by: '<S121>/heat_capacity_ratio'
                                        */
  real_T deviation_Tmp_Value;        /* Expression: HIL_Data.FDM.soph.bus2.e_Tmp
                                      * Referenced by: '<S207>/deviation_Tmp'
                                      */
  real_T Tmp_norm_msl_Value;        /* Expression: HIL_Data.FDM.soph.bus2.c_Tmp0
                                     * Referenced by: '<S122>/Tmp_norm_msl'
                                     */
  real_T Tmp_gradient_tropo_Value;    /* Expression: HIL_Data.FDM.soph.bus2.c_be
                                       * Referenced by: '<S123>/Tmp_gradient_tropo'
                                       */
  real_T Constant_Value_b;           /* Expression: HIL_Data.FDM.soph.bus2.lon_0
                                      * Referenced by: '<S183>/Constant'
                                      */
  real_T Constant2_Value_e5;         /* Expression: HIL_Data.FDM.soph.bus2.lat_0
                                      * Referenced by: '<S183>/Constant2'
                                      */
  real_T Constant1_Value_bt;   /* Expression: HIL_Data.FDM.soph.bus2.flag_I_flat
                                * Referenced by: '<S183>/Constant1'
                                */
  real_T c_rsma_Value_j;               /* Expression: c_rsma
                                        * Referenced by: '<S185>/c_rsma'
                                        */
  real_T Constant_Value_ne;            /* Expression: 1
                                        * Referenced by: '<S187>/Constant'
                                        */
  real_T c_flat_Value_e;               /* Expression: c_flat
                                        * Referenced by: '<S185>/c_flat'
                                        */
  real_T Gain_Gain_le;                 /* Expression: 2
                                        * Referenced by: '<S187>/Gain'
                                        */
  real_T Constant_Value_nr;            /* Expression: 1
                                        * Referenced by: '<S186>/Constant'
                                        */
  real_T Gain_Gain_iy;                 /* Expression: 2
                                        * Referenced by: '<S186>/Gain'
                                        */
  real_T Switch_Threshold_c;           /* Expression: 0
                                        * Referenced by: '<S183>/Switch'
                                        */
  real_T Saturation_UpperSat_h;  /* Expression: HIL_Data.FDM.soph.bus2.c_h_geope
                                  * Referenced by: '<S110>/Saturation'
                                  */
  real_T Saturation_LowerSat_k;  /* Expression: HIL_Data.FDM.soph.bus2.c_h_geop0
                                  * Referenced by: '<S110>/Saturation'
                                  */
  real_T geopotential_height_ref_Value;
                                 /* Expression: HIL_Data.FDM.soph.bus2.c_h_geop0
                                  * Referenced by: '<S122>/geopotential_height_ref'
                                  */
  real_T Prelookup_Mach_BreakpointsData[9];
                                   /* Expression: HIL_Data.FDM.soph.bus1.aero.Ma
                                    * Referenced by: '<S95>/Prelookup_Mach'
                                    */
  real_T Constant_Value_jc[4];         /* Expression: [1; 0; 0; 1]
                                        * Referenced by: '<S201>/Constant'
                                        */
  real_T Gain_Gain_nn;                 /* Expression: 180/pi
                                        * Referenced by: '<S100>/Gain'
                                        */
  real_T Prelookup_alB_BreakpointsData[17];
                                /* Expression: HIL_Data.FDM.soph.bus1.aero.alpha
                                 * Referenced by: '<S95>/Prelookup_alB'
                                 */
  real_T Gain_Gain_kz;                 /* Expression: 180/pi
                                        * Referenced by: '<S101>/Gain'
                                        */
  real_T Prelookup_beB_BreakpointsData[17];
                                 /* Expression: HIL_Data.FDM.soph.bus1.aero.beta
                                  * Referenced by: '<S95>/Prelookup_beB'
                                  */
  real_T Cx_Interpolation_Table[2601];
                                   /* Expression: HIL_Data.FDM.soph.bus1.aero.Cx
                                    * Referenced by: '<S92>/Cx_Interpolation'
                                    */
  real_T Saturation1_UpperSat;         /* Expression: inf
                                        * Referenced by: '<S202>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 100*eps
                                        * Referenced by: '<S202>/Saturation1'
                                        */
  real_T Constant1_Value_is;     /* Expression: HIL_Data.FDM.soph.bus1.aero.lref
                                  * Referenced by: '<S202>/Constant1'
                                  */
  real_T Gain_Gain_b;                  /* Expression: 180/pi
                                        * Referenced by: '<S105>/Gain'
                                        */
  real_T Cxp_Interpolation_Table[2601];
                                  /* Expression: HIL_Data.FDM.soph.bus1.aero.Cxp
                                   * Referenced by: '<S92>/Cxp_Interpolation'
                                   */
  real_T Gain_Gain_hp;                 /* Expression: 180/pi
                                        * Referenced by: '<S106>/Gain'
                                        */
  real_T Cxq_Interpolation_Table[2601];
                                  /* Expression: HIL_Data.FDM.soph.bus1.aero.Cxq
                                   * Referenced by: '<S92>/Cxq_Interpolation'
                                   */
  real_T Gain_Gain_bz;                 /* Expression: 180/pi
                                        * Referenced by: '<S107>/Gain'
                                        */
  real_T Cxr_Interpolation_Table[2601];
                                  /* Expression: HIL_Data.FDM.soph.bus1.aero.Cxr
                                   * Referenced by: '<S92>/Cxr_Interpolation'
                                   */
  real_T Constant8_Value_g2[12];     /* Expression: HIL_Data.FDM.soph.bus1.Tr3r4
                                      * Referenced by: '<S129>/Constant8'
                                      */
  real_T Constant7_Value_dr;          /* Expression: HIL_Data.FDM.soph.bus1.tRRR
                                       * Referenced by: '<S54>/Constant7'
                                       */
  real_T Gain_Gain_aj;                 /* Expression: 180/pi
                                        * Referenced by: '<S102>/Gain'
                                        */
  real_T Cx_delta_l_Interpolation_Table[2601];
                           /* Expression: HIL_Data.FDM.soph.bus1.aero.Cx_delta_l
                            * Referenced by: '<S92>/Cx_delta_l_Interpolation'
                            */
  real_T Gain_Gain_l4;                 /* Expression: 180/pi
                                        * Referenced by: '<S103>/Gain'
                                        */
  real_T Cx_delta_m_Interpolation_Table[2601];
                           /* Expression: HIL_Data.FDM.soph.bus1.aero.Cx_delta_m
                            * Referenced by: '<S92>/Cx_delta_m_Interpolation'
                            */
  real_T Gain_Gain_pr;                 /* Expression: 180/pi
                                        * Referenced by: '<S104>/Gain'
                                        */
  real_T Cx_delta_n_Interpolation_Table[2601];
                           /* Expression: HIL_Data.FDM.soph.bus1.aero.Cx_delta_n
                            * Referenced by: '<S92>/Cx_delta_n_Interpolation'
                            */
  real_T Prelookup_altitude_BreakpointsData[20];
                                /* Expression: HIL_Data.FDM.soph.bus1.aero.hoehe
                                 * Referenced by: '<S92>/Prelookup_altitude'
                                 */
  real_T Cx_alt_Interpolation_Table[3060];
                               /* Expression: HIL_Data.FDM.soph.bus1.aero.Cx_alt
                                * Referenced by: '<S92>/Cx_alt_Interpolation'
                                */
  real_T Constant3_Value_f;            /* Expression: 2
                                        * Referenced by: '<S96>/Constant3'
                                        */
  real_T Gain1_Gain_b;                 /* Expression: pi/180
                                        * Referenced by: '<S97>/Gain1'
                                        */
  real_T Gain1_Gain_e2;                /* Expression: pi/180
                                        * Referenced by: '<S98>/Gain1'
                                        */
  real_T Gain_Gain_if;                 /* Expression: 180/pi
                                        * Referenced by: '<S99>/Gain'
                                        */
  real_T Saturation_UpperSat_f;        /* Expression: inf
                                        * Referenced by: '<S96>/Saturation'
                                        */
  real_T Saturation_LowerSat_g;        /* Expression: 100*eps
                                        * Referenced by: '<S96>/Saturation'
                                        */
  real_T Prelookup_delta_t_BreakpointsData[9];
                              /* Expression: HIL_Data.FDM.soph.bus1.aero.delta_t
                               * Referenced by: '<S92>/Prelookup_delta_t'
                               */
  real_T Cx_delta_t_Interpolation_Table[1377];
                           /* Expression: HIL_Data.FDM.soph.bus1.aero.Cx_delta_t
                            * Referenced by: '<S92>/Cx_delta_t_Interpolation'
                            */
  real_T Cx_base_Interpolation_Table[2601];
                              /* Expression: HIL_Data.FDM.soph.bus1.aero.Cx_base
                               * Referenced by: '<S92>/Cx_base_Interpolation'
                               */
  real_T Constant6_Value_i;     /* Expression: HIL_Data.FDM.soph.bus2.T_sim_lnch
                                 * Referenced by: '<S206>/Constant6'
                                 */
  real_T Constant_Value_ok;    /* Expression: HIL_Data.FDM.soph.bus1.t_prp2(end)
                                * Referenced by: '<S71>/Constant'
                                */
  real_T Constant_Value_oz;
                         /* Expression: HIL_Data.FDM.soph.bus1.unc_aero_Cy_scale
                          * Referenced by: '<S93>/Constant'
                          */
  real_T Cy_Interpolation_Table[2601];
                                   /* Expression: HIL_Data.FDM.soph.bus1.aero.Cy
                                    * Referenced by: '<S93>/Cy_Interpolation'
                                    */
  real_T Cyp_Interpolation_Table[2601];
                                  /* Expression: HIL_Data.FDM.soph.bus1.aero.Cyp
                                   * Referenced by: '<S93>/Cyp_Interpolation'
                                   */
  real_T Cyq_Interpolation_Table[2601];
                                  /* Expression: HIL_Data.FDM.soph.bus1.aero.Cyq
                                   * Referenced by: '<S93>/Cyq_Interpolation'
                                   */
  real_T Cyr_Interpolation_Table[2601];
                                  /* Expression: HIL_Data.FDM.soph.bus1.aero.Cyr
                                   * Referenced by: '<S93>/Cyr_Interpolation'
                                   */
  real_T Cy_delta_l_Interpolation_Table[2601];
                           /* Expression: HIL_Data.FDM.soph.bus1.aero.Cy_delta_l
                            * Referenced by: '<S93>/Cy_delta_l_Interpolation'
                            */
  real_T Cy_delta_m_Interpolation_Table[2601];
                           /* Expression: HIL_Data.FDM.soph.bus1.aero.Cy_delta_m
                            * Referenced by: '<S93>/Cy_delta_m_Interpolation'
                            */
  real_T Cy_delta_n_Interpolation_Table[2601];
                           /* Expression: HIL_Data.FDM.soph.bus1.aero.Cy_delta_n
                            * Referenced by: '<S93>/Cy_delta_n_Interpolation'
                            */
  real_T Constant_Value_gw;
                         /* Expression: HIL_Data.FDM.soph.bus1.unc_aero_Cz_scale
                          * Referenced by: '<S94>/Constant'
                          */
  real_T Cz_Interpolation_Table[2601];
                                   /* Expression: HIL_Data.FDM.soph.bus1.aero.Cz
                                    * Referenced by: '<S94>/Cz_Interpolation'
                                    */
  real_T Czp_Interpolation_Table[2601];
                                  /* Expression: HIL_Data.FDM.soph.bus1.aero.Czp
                                   * Referenced by: '<S94>/Czp_Interpolation'
                                   */
  real_T Czq_Interpolation_Table[2601];
                                  /* Expression: HIL_Data.FDM.soph.bus1.aero.Czq
                                   * Referenced by: '<S94>/Czq_Interpolation'
                                   */
  real_T Czr_Interpolation_Table[2601];
                                  /* Expression: HIL_Data.FDM.soph.bus1.aero.Czr
                                   * Referenced by: '<S94>/Czr_Interpolation'
                                   */
  real_T Cz_delta_l_Interpolation_Table[2601];
                           /* Expression: HIL_Data.FDM.soph.bus1.aero.Cz_delta_l
                            * Referenced by: '<S94>/Cz_delta_l_Interpolation'
                            */
  real_T Cz_delta_m_Interpolation_Table[2601];
                           /* Expression: HIL_Data.FDM.soph.bus1.aero.Cz_delta_m
                            * Referenced by: '<S94>/Cz_delta_m_Interpolation'
                            */
  real_T Cz_delta_n_Interpolation_Table[2601];
                           /* Expression: HIL_Data.FDM.soph.bus1.aero.Cz_delta_n
                            * Referenced by: '<S94>/Cz_delta_n_Interpolation'
                            */
  real_T Constant2_Value_a2;     /* Expression: HIL_Data.FDM.soph.bus1.aero.sref
                                  * Referenced by: '<S73>/Constant2'
                                  */
  real_T Constant_Value_ii;            /* Expression: 0.5
                                        * Referenced by: '<S199>/Constant'
                                        */
  real_T Constant1_Value_mh;           /* Expression: 1
                                        * Referenced by: '<S124>/Constant1'
                                        */
  real_T Tmp_gradient_tropo_Value_l;  /* Expression: HIL_Data.FDM.soph.bus2.c_be
                                       * Referenced by: '<S124>/Tmp_gradient_tropo'
                                       */
  real_T pressure_exponent_Value;     /* Expression: HIL_Data.FDM.soph.bus2.c_pe
                                       * Referenced by: '<S124>/pressure_exponent'
                                       */
  real_T deviation_pa_QFH_Value;      /* Expression: HIL_Data.FDM.soph.bus2.e_pa
                                       * Referenced by: '<S207>/deviation_pa_QFH'
                                       */
  real_T pa_norm_msl_Value;          /* Expression: HIL_Data.FDM.soph.bus2.c_pa0
                                      * Referenced by: '<S122>/pa_norm_msl'
                                      */
  real_T specific_gas_constant_Value_c;/* Expression: HIL_Data.FDM.soph.bus2.sgc
                                        * Referenced by: '<S119>/specific_gas_constant'
                                        */
  real_T Constant1_Value_lx;
                        /* Expression: HIL_Data.FDM.soph.bus2.flag_I_aero_switch
                         * Referenced by: '<S79>/Constant1'
                         */
  real_T Constant_Value_iu[3];      /* Expression: HIL_Data.FDM.soph.bus2.pBII_0
                                     * Referenced by: '<S81>/Constant'
                                     */
  real_T Constant2_Value_o;    /* Expression: HIL_Data.FDM.soph.bus2.flag_I_flat
                                * Referenced by: '<S81>/Constant2'
                                */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S81>/Switch1'
                                        */
  real_T Constant3_Value_f4;           /* Expression: 0
                                        * Referenced by: '<S79>/Constant3'
                                        */
  real_T Switch_Threshold_f;           /* Expression: 0.05
                                        * Referenced by: '<S79>/Switch'
                                        */
  real_T Constant1_Value_cj;           /* Expression: 0
                                        * Referenced by: '<S111>/Constant1'
                                        */
  real_T Saturation_UpperSat_d;        /* Expression: inf
                                        * Referenced by: '<S53>/Saturation'
                                        */
  real_T Saturation_LowerSat_j;        /* Expression: eps
                                        * Referenced by: '<S53>/Saturation'
                                        */
  real_T a3_Value;                     /* Expression: 1
                                        * Referenced by: '<S117>/a3'
                                        */
  real_T a2_Value;                     /* Expression: 2
                                        * Referenced by: '<S118>/a2'
                                        */
  real_T WGS84SemiminorAxism_Value;    /* Expression: c_b_WGS
                                        * Referenced by: '<S117>/WGS84 Semi-minor Axis, [m]'
                                        */
  real_T WGS84SemimajorAxism_Value;    /* Expression: c_rsma
                                        * Referenced by: '<S117>/WGS84 Semi-major Axis, [m]'
                                        */
  real_T Constant_Value_ov;            /* Expression: 1
                                        * Referenced by: '<S115>/Constant'
                                        */
  real_T Constant1_Value_mm;
                     /* Expression: HIL_Data.FDM.soph.bus2.flag_I_gravity_switch
                      * Referenced by: '<S138>/Constant1'
                      */
  real_T Constant_Value_g4[3];      /* Expression: HIL_Data.FDM.soph.bus2.pBII_0
                                     * Referenced by: '<S139>/Constant'
                                     */
  real_T Constant2_Value_id;   /* Expression: HIL_Data.FDM.soph.bus2.flag_I_flat
                                * Referenced by: '<S139>/Constant2'
                                */
  real_T Switch1_Threshold_d;          /* Expression: 0
                                        * Referenced by: '<S139>/Switch1'
                                        */
  real_T Constant3_Value_j;            /* Expression: 0
                                        * Referenced by: '<S138>/Constant3'
                                        */
  real_T Switch_Threshold_gn;          /* Expression: 0.05
                                        * Referenced by: '<S138>/Switch'
                                        */
  real_T Constant_Value_bs;      /* Expression: HIL_Data.FDM.soph.bus1.unc_mB_bl
                                  * Referenced by: '<S217>/Constant'
                                  */
  real_T Constant1_Value_iw;          /* Expression: HIL_Data.FDM.soph.bus1.mB_0
                                       * Referenced by: '<S216>/Constant1'
                                       */
  real_T Constant_Value_k;             /* Expression: 0
                                        * Referenced by: '<S216>/Constant'
                                        */
  real_T Switch_Threshold_fo;          /* Expression: 0
                                        * Referenced by: '<S216>/Switch'
                                        */
  real_T Switch1_Threshold_f;          /* Expression: 0
                                        * Referenced by: '<S216>/Switch1'
                                        */
  real_T Constant2_Value_p;           /* Expression: HIL_Data.FDM.soph.bus1.mM_0
                                       * Referenced by: '<S216>/Constant2'
                                       */
  real_T Constant1_Value_mo;  /* Expression: HIL_Data.FDM.soph.bus1.unc_mB_scale
                               * Referenced by: '<S217>/Constant1'
                               */
  real_T thrust_rot_x_Value;     /* Expression: HIL_Data.FDM.soph.bus1.unc_prp_x
                                  * Referenced by: '<S169>/thrust_rot_x'
                                  */
  real_T thrust_rot_y_Value;     /* Expression: HIL_Data.FDM.soph.bus1.unc_prp_y
                                  * Referenced by: '<S169>/thrust_rot_y'
                                  */
  real_T Thrust_rot_z_Value;     /* Expression: HIL_Data.FDM.soph.bus1.unc_prp_z
                                  * Referenced by: '<S169>/Thrust_rot_z'
                                  */
  real_T Constant_Value_a0;            /* Expression: 0
                                        * Referenced by: '<S168>/Constant'
                                        */
  real_T Switch_Threshold_n;           /* Expression: 0
                                        * Referenced by: '<S168>/Switch'
                                        */
  real_T Switch1_Threshold_a;          /* Expression: 0
                                        * Referenced by: '<S168>/Switch1'
                                        */
  real_T Constant1_Value_h;            /* Expression: 0
                                        * Referenced by: '<S168>/Constant1'
                                        */
  real_T uncert_thrust_Value;/* Expression: HIL_Data.FDM.soph.bus1.unc_prp_scale
                              * Referenced by: '<S169>/uncert_thrust'
                              */
  real_T ExternalForce_Time;           /* Expression: 0
                                        * Referenced by: '<Root>/External Force'
                                        */
  real_T ExternalForce_Y0;             /* Expression: 0
                                        * Referenced by: '<Root>/External Force'
                                        */
  real_T ExternalForce_YFinal;         /* Expression: 1
                                        * Referenced by: '<Root>/External Force'
                                        */
  real_T Step_Time;                    /* Expression: 3
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: -1
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Gain_Gain_pd;                 /* Expression: 0
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Constant1_Value_fp;           /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Switch_Threshold_j;           /* Expression: 1
                                        * Referenced by: '<S188>/Switch'
                                        */
  real_T Saturation_UpperSat_m;        /* Expression: Inf
                                        * Referenced by: '<S191>/Saturation'
                                        */
  real_T Saturation_LowerSat_a;        /* Expression: 1e-6
                                        * Referenced by: '<S191>/Saturation'
                                        */
  real_T Constant_Value_eq;            /* Expression: 0
                                        * Referenced by: '<S195>/Constant'
                                        */
  real_T Gain3_Gain_df;                /* Expression: 1
                                        * Referenced by: '<S49>/Gain3'
                                        */
  real_T Gain4_Gain_g;                 /* Expression: 1
                                        * Referenced by: '<S49>/Gain4'
                                        */
  real_T Gain5_Gain_n;                 /* Expression: 1
                                        * Referenced by: '<S49>/Gain5'
                                        */
  real_T Gain6_Gain_a;                 /* Expression: 1
                                        * Referenced by: '<S49>/Gain6'
                                        */
  real_T Gain7_Gain_ia;                /* Expression: 1
                                        * Referenced by: '<S49>/Gain7'
                                        */
  real_T Gain8_Gain_l1;                /* Expression: 1
                                        * Referenced by: '<S49>/Gain8'
                                        */
  real_T Constant_Value_pf;            /* Expression: 0.5
                                        * Referenced by: '<S60>/Constant'
                                        */
  real_T Gain_Gain_m;                  /* Expression: 2
                                        * Referenced by: '<S60>/Gain'
                                        */
  real_T Saturation_UpperSat_g;        /* Expression: 1
                                        * Referenced by: '<S60>/Saturation'
                                        */
  real_T Saturation_LowerSat_ku;       /* Expression: -1
                                        * Referenced by: '<S60>/Saturation'
                                        */
  real_T Constant1_Value_jl;           /* Expression: 0.5
                                        * Referenced by: '<S60>/Constant1'
                                        */
  real_T Gain9_Gain_f;                 /* Expression: 1
                                        * Referenced by: '<S49>/Gain9'
                                        */
  real_T Gain10_Gain_k;                /* Expression: 1
                                        * Referenced by: '<S49>/Gain10'
                                        */
  real_T Gain11_Gain_o;                /* Expression: 1
                                        * Referenced by: '<S49>/Gain11'
                                        */
  real_T u2_Gain_f;                    /* Expression: 0.5
                                        * Referenced by: '<S65>/1//2'
                                        */
  real_T Constant5_Value_k;            /* Expression: -1
                                        * Referenced by: '<S48>/Constant5'
                                        */
  real_T Gain12_Gain_b;                /* Expression: 1
                                        * Referenced by: '<S49>/Gain12'
                                        */
  real_T Constant4_Value_d;            /* Expression: -1
                                        * Referenced by: '<S48>/Constant4'
                                        */
  real_T Gain13_Gain;                  /* Expression: 1
                                        * Referenced by: '<S49>/Gain13'
                                        */
  real_T Gain14_Gain;                  /* Expression: 1
                                        * Referenced by: '<S49>/Gain14'
                                        */
  real_T Gain15_Gain;                  /* Expression: 1
                                        * Referenced by: '<S49>/Gain15'
                                        */
  real_T Gain16_Gain;                  /* Expression: 1
                                        * Referenced by: '<S49>/Gain16'
                                        */
  real_T Constant7_Value_l;            /* Expression: -1
                                        * Referenced by: '<S48>/Constant7'
                                        */
  real_T Gain18_Gain;                  /* Expression: 1
                                        * Referenced by: '<S49>/Gain18'
                                        */
  real_T Gain22_Gain;                  /* Expression: 1
                                        * Referenced by: '<S49>/Gain22'
                                        */
  real_T Constant3_Value_i;            /* Expression: -1
                                        * Referenced by: '<S48>/Constant3'
                                        */
  real_T Gain19_Gain;                  /* Expression: 1
                                        * Referenced by: '<S49>/Gain19'
                                        */
  real_T Constant2_Value_pm;           /* Expression: -1
                                        * Referenced by: '<S48>/Constant2'
                                        */
  real_T Gain20_Gain;                  /* Expression: 1
                                        * Referenced by: '<S49>/Gain20'
                                        */
  real_T Constant1_Value_ay;           /* Expression: -1
                                        * Referenced by: '<S48>/Constant1'
                                        */
  real_T Gain21_Gain;                  /* Expression: 1
                                        * Referenced by: '<S49>/Gain21'
                                        */
  real_T One_Value_g;                  /* Expression: 1
                                        * Referenced by: '<S19>/One'
                                        */
  real_T Constant_Value_ko;            /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T ExternalMoment_Time;          /* Expression: 5
                                        * Referenced by: '<Root>/External Moment'
                                        */
  real_T ExternalMoment_Y0;            /* Expression: 0
                                        * Referenced by: '<Root>/External Moment'
                                        */
  real_T ExternalMoment_YFinal;        /* Expression: 1
                                        * Referenced by: '<Root>/External Moment'
                                        */
  real_T PulseGenerator1_Amp;          /* Expression: -2
                                        * Referenced by: '<S17>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Period;   /* Computed Parameter: PulseGenerator1_Period
                                    * Referenced by: '<S17>/Pulse Generator1'
                                    */
  real_T PulseGenerator1_Duty;       /* Computed Parameter: PulseGenerator1_Duty
                                      * Referenced by: '<S17>/Pulse Generator1'
                                      */
  real_T PulseGenerator1_PhaseDelay;
  /* Expression: External_Inputs.FCC.CMD.roll.pulse.delay_s+External_Inputs.FCC.CMD.roll.pulse.period_s
   * Referenced by: '<S17>/Pulse Generator1'
   */
  real_T PulseGenerator_Period;     /* Computed Parameter: PulseGenerator_Period
                                     * Referenced by: '<S17>/Pulse Generator'
                                     */
  real_T PulseGenerator_Duty;         /* Computed Parameter: PulseGenerator_Duty
                                       * Referenced by: '<S17>/Pulse Generator'
                                       */
  real_T PulseGenerator_PhaseDelay;
                       /* Expression: External_Inputs.FCC.CMD.roll.pulse.delay_s
                        * Referenced by: '<S17>/Pulse Generator'
                        */
  real_T Switch1_Threshold_m;          /* Expression: 0
                                        * Referenced by: '<S17>/Switch1'
                                        */
  real_T PulseGenerator4_Amp;          /* Expression: -2
                                        * Referenced by: '<S17>/Pulse Generator4'
                                        */
  real_T PulseGenerator4_Period;   /* Computed Parameter: PulseGenerator4_Period
                                    * Referenced by: '<S17>/Pulse Generator4'
                                    */
  real_T PulseGenerator4_Duty;       /* Computed Parameter: PulseGenerator4_Duty
                                      * Referenced by: '<S17>/Pulse Generator4'
                                      */
  real_T PulseGenerator4_PhaseDelay;
  /* Expression: External_Inputs.FCC.CMD.pitch.pulse.delay_s+External_Inputs.FCC.CMD.pitch.pulse.period_s
   * Referenced by: '<S17>/Pulse Generator4'
   */
  real_T PulseGenerator3_Period;   /* Computed Parameter: PulseGenerator3_Period
                                    * Referenced by: '<S17>/Pulse Generator3'
                                    */
  real_T PulseGenerator3_Duty;       /* Computed Parameter: PulseGenerator3_Duty
                                      * Referenced by: '<S17>/Pulse Generator3'
                                      */
  real_T PulseGenerator3_PhaseDelay;
                      /* Expression: External_Inputs.FCC.CMD.pitch.pulse.delay_s
                       * Referenced by: '<S17>/Pulse Generator3'
                       */
  real_T Switch_Threshold_p;           /* Expression: 0
                                        * Referenced by: '<S17>/Switch'
                                        */
  real_T PulseGenerator7_Amp;          /* Expression: -2
                                        * Referenced by: '<S17>/Pulse Generator7'
                                        */
  real_T PulseGenerator7_Period;   /* Computed Parameter: PulseGenerator7_Period
                                    * Referenced by: '<S17>/Pulse Generator7'
                                    */
  real_T PulseGenerator7_Duty;       /* Computed Parameter: PulseGenerator7_Duty
                                      * Referenced by: '<S17>/Pulse Generator7'
                                      */
  real_T PulseGenerator7_PhaseDelay;
  /* Expression: External_Inputs.FCC.CMD.yaw.pulse.delay_s+External_Inputs.FCC.CMD.yaw.pulse.period_s
   * Referenced by: '<S17>/Pulse Generator7'
   */
  real_T PulseGenerator6_Period;   /* Computed Parameter: PulseGenerator6_Period
                                    * Referenced by: '<S17>/Pulse Generator6'
                                    */
  real_T PulseGenerator6_Duty;       /* Computed Parameter: PulseGenerator6_Duty
                                      * Referenced by: '<S17>/Pulse Generator6'
                                      */
  real_T PulseGenerator6_PhaseDelay;
                        /* Expression: External_Inputs.FCC.CMD.yaw.pulse.delay_s
                         * Referenced by: '<S17>/Pulse Generator6'
                         */
  real_T Switch2_Threshold;            /* Expression: 0
                                        * Referenced by: '<S17>/Switch2'
                                        */
  real_T Constant1_Value_bx;           /* Expression: 1
                                        * Referenced by: '<S26>/Constant1'
                                        */
  real_T Constant10_Value_ly;
                /* Expression: HIL_Data.Simulation_Ctrl.Com_Ctrl.Pix.Com_freq_Hz
                 * Referenced by: '<S7>/Constant10'
                 */
  real_T Constant2_Value_d1;           /* Expression: 1
                                        * Referenced by: '<S26>/Constant2'
                                        */
  real_T Memory_InitialCondition;      /* Expression: -1
                                        * Referenced by: '<S26>/Memory'
                                        */
  real_T Step1_Time;                   /* Expression: 6
                                        * Referenced by: '<Root>/Step1'
                                        */
  real_T Step1_Y0;                     /* Expression: 0
                                        * Referenced by: '<Root>/Step1'
                                        */
  real_T Step1_YFinal;                 /* Expression: -1
                                        * Referenced by: '<Root>/Step1'
                                        */
  real_T Gain1_Gain_j2;                /* Expression: 6
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Constant7_Value_e;
          /* Expression: HIL_Data.Simulation_Ctrl.HW_Ctrl.enable_gimbal_ctrl_flg
           * Referenced by: '<S7>/Constant7'
           */
  real_T Constant8_Value_lr;
                 /* Expression: HIL_Data.Simulation_Ctrl.HW_Ctrl.stop_gimbal_flg
                  * Referenced by: '<S7>/Constant8'
                  */
  real_T rad2deg_Gain;                 /* Expression: 360/(2*pi)
                                        * Referenced by: '<S46>/rad2deg'
                                        */
  real_T rad2deg1_Gain;                /* Expression: 360/(2*pi)
                                        * Referenced by: '<S46>/rad2deg1'
                                        */
  real_T rad2deg2_Gain;                /* Expression: 360/(2*pi)
                                        * Referenced by: '<S46>/rad2deg2'
                                        */
  real_T Constant_Value_p3;            /* Expression: 0
                                        * Referenced by: '<S34>/Constant'
                                        */
  real_T Constant1_Value_e;            /* Expression: 1
                                        * Referenced by: '<S35>/Constant1'
                                        */
  real_T Constant11_Value_p3;
                 /* Expression: HIL_Data.Simulation_Ctrl.Com_Ctrl.FT.Com_freq_Hz
                  * Referenced by: '<S7>/Constant11'
                  */
  real_T Constant2_Value_ik;           /* Expression: 1
                                        * Referenced by: '<S35>/Constant2'
                                        */
  real_T Memory_InitialCondition_i;    /* Expression: -1
                                        * Referenced by: '<S35>/Memory'
                                        */
  real_T Constant1_Value_lj;
                          /* Expression: HIL_Data.FDM.soph.bus1.unc_fin_def_roll
                           * Referenced by: '<S51>/Constant1'
                           */
  real_T Constant2_Value_ff;
                         /* Expression: HIL_Data.FDM.soph.bus1.unc_fin_def_pitch
                          * Referenced by: '<S51>/Constant2'
                          */
  real_T Constant3_Value_i5;
                           /* Expression: HIL_Data.FDM.soph.bus1.unc_fin_def_yaw
                            * Referenced by: '<S51>/Constant3'
                            */
  real_T Gain1_Gain_ps;                /* Expression: pi/180
                                        * Referenced by: '<S66>/Gain1'
                                        */
  real_T Gain1_Gain_n3;                /* Expression: pi/180
                                        * Referenced by: '<S67>/Gain1'
                                        */
  real_T Gain1_Gain_g;                 /* Expression: pi/180
                                        * Referenced by: '<S68>/Gain1'
                                        */
  real_T Constant7_Value_aa[12];     /* Expression: HIL_Data.FDM.soph.bus1.Tr4r3
                                      * Referenced by: '<S69>/Constant7'
                                      */
  real_T Constant_Value_e0;
                         /* Expression: HIL_Data.FDM.soph.bus1.unc_aero_Cl_scale
                          * Referenced by: '<S89>/Constant'
                          */
  real_T Constant_Value_jm;
                         /* Expression: HIL_Data.FDM.soph.bus1.unc_aero_Cm_scale
                          * Referenced by: '<S90>/Constant'
                          */
  real_T Constant_Value_ml;
                         /* Expression: HIL_Data.FDM.soph.bus1.unc_aero_Cn_scale
                          * Referenced by: '<S91>/Constant'
                          */
  real_T Constant4_Value_p;           /* Expression: HIL_Data.FDM.soph.bus1.xMPB
                                       * Referenced by: '<S214>/Constant4'
                                       */
  real_T Constant_Value_l1;            /* Expression: HIL_Data.FDM.soph.bus1.m0
                                        * Referenced by: '<S214>/Constant'
                                        */
  real_T Constant6_Value_d5;          /* Expression: HIL_Data.FDM.soph.bus1.x0PB
                                       * Referenced by: '<S214>/Constant6'
                                       */
  real_T Constant3_Value_fn;      /* Expression: HIL_Data.FDM.soph.bus1.unc_cg_x
                                   * Referenced by: '<S214>/Constant3'
                                   */
  real_T Constant7_Value_jc;          /* Expression: HIL_Data.FDM.soph.bus1.yMPB
                                       * Referenced by: '<S214>/Constant7'
                                       */
  real_T Constant5_Value_e;           /* Expression: HIL_Data.FDM.soph.bus1.y0PB
                                       * Referenced by: '<S214>/Constant5'
                                       */
  real_T Constant1_Value_in;      /* Expression: HIL_Data.FDM.soph.bus1.unc_cg_y
                                   * Referenced by: '<S214>/Constant1'
                                   */
  real_T Constant9_Value_c;           /* Expression: HIL_Data.FDM.soph.bus1.zMPB
                                       * Referenced by: '<S214>/Constant9'
                                       */
  real_T Constant8_Value_l5;          /* Expression: HIL_Data.FDM.soph.bus1.z0PB
                                       * Referenced by: '<S214>/Constant8'
                                       */
  real_T Constant2_Value_mg;      /* Expression: HIL_Data.FDM.soph.bus1.unc_cg_z
                                   * Referenced by: '<S214>/Constant2'
                                   */
  real_T Constant1_Value_bk;     /* Expression: HIL_Data.FDM.soph.bus1.aero.lref
                                  * Referenced by: '<S73>/Constant1'
                                  */
  real_T Constant3_Value_m;            /* Expression: 0
                                        * Referenced by: '<S80>/Constant3'
                                        */
  real_T Constant1_Value_p;
                        /* Expression: HIL_Data.FDM.soph.bus2.flag_I_aero_switch
                         * Referenced by: '<S80>/Constant1'
                         */
  real_T Constant_Value_iee[3];     /* Expression: HIL_Data.FDM.soph.bus2.pBII_0
                                     * Referenced by: '<S85>/Constant'
                                     */
  real_T Constant2_Value_ad;   /* Expression: HIL_Data.FDM.soph.bus2.flag_I_flat
                                * Referenced by: '<S85>/Constant2'
                                */
  real_T Switch1_Threshold_n;          /* Expression: 0
                                        * Referenced by: '<S85>/Switch1'
                                        */
  real_T Switch_Threshold_j0;          /* Expression: 0.05
                                        * Referenced by: '<S80>/Switch'
                                        */
  real_T Gain_Gain_oz;                 /* Expression: omega^2
                                        * Referenced by: '<S125>/Gain'
                                        */
  real_T Gain_Gain_a3;                 /* Expression: omega^2
                                        * Referenced by: '<S126>/Gain'
                                        */
  real_T Gain_Gain_hm;                 /* Expression: omega^2
                                        * Referenced by: '<S127>/Gain'
                                        */
  real_T Gain_Gain_d;                  /* Expression: omega^2
                                        * Referenced by: '<S128>/Gain'
                                        */
  real_T pNPB_Value[3];               /* Expression: HIL_Data.FDM.soph.bus1.pNPB
                                       * Referenced by: '<S169>/pNPB'
                                       */
  real_T SineWave_Amp;                 /* Expression: 5
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Freq;                /* Expression: 10
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Phase;               /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T Q_1_Value_e[16];  /* Expression: [0 0 0 1; 0 0 1 0; 0 -1 0 0; -1 0 0 0]
                            * Referenced by: '<S151>/Q_1'
                            */
  real_T Q_2_Value_l[16];  /* Expression: [0 0 -1 0; 0 0 0 1; 1 0 0 0; 0 -1 0 0]
                            * Referenced by: '<S151>/Q_2'
                            */
  real_T Q_3_Value_o5[16]; /* Expression: [0 1 0 0; -1 0 0 0; 0 0 0 1; 0 0 -1 0]
                            * Referenced by: '<S151>/Q_3'
                            */
  real_T Q_4_Value_nu[16];   /* Expression: [1 0 0 0; 0 1 0 0; 0 0 1 0; 0 0 0 1]
                              * Referenced by: '<S151>/Q_4'
                              */
  real_T Constant_Value_ek0;           /* Expression: 1
                                        * Referenced by: '<S151>/Constant'
                                        */
  real_T Constant1_Value_ll;           /* Expression: -1
                                        * Referenced by: '<S151>/Constant1'
                                        */
  real_T Switch_Threshold_k;           /* Expression: 0
                                        * Referenced by: '<S151>/Switch'
                                        */
  real_T Gain1_Gain_b2;                /* Expression: 2
                                        * Referenced by: '<S146>/Gain1'
                                        */
  real_T Gain2_Gain_iv;                /* Expression: 2
                                        * Referenced by: '<S146>/Gain2'
                                        */
  real_T Gain3_Gain_a;                 /* Expression: 2
                                        * Referenced by: '<S146>/Gain3'
                                        */
  real_T Gain4_Gain_cb;                /* Expression: 2
                                        * Referenced by: '<S146>/Gain4'
                                        */
  real_T Gain5_Gain_k;                 /* Expression: 2
                                        * Referenced by: '<S146>/Gain5'
                                        */
  real_T Gain6_Gain_g;                 /* Expression: 2
                                        * Referenced by: '<S146>/Gain6'
                                        */
  real_T Gain7_Gain_k;                 /* Expression: 2
                                        * Referenced by: '<S146>/Gain7'
                                        */
  real_T Gain8_Gain_e;                 /* Expression: 2
                                        * Referenced by: '<S146>/Gain8'
                                        */
  real_T Gain9_Gain_i;                 /* Expression: 2
                                        * Referenced by: '<S146>/Gain9'
                                        */
  real_T Gain10_Gain_j;                /* Expression: 2
                                        * Referenced by: '<S146>/Gain10'
                                        */
  real_T Gain11_Gain_i;                /* Expression: 2
                                        * Referenced by: '<S146>/Gain11'
                                        */
  real_T Gain12_Gain_h5;               /* Expression: 2
                                        * Referenced by: '<S146>/Gain12'
                                        */
  real_T Gain_Gain_jo;                 /* Expression: -1
                                        * Referenced by: '<S145>/Gain'
                                        */
  real_T Q_1_Value_o[16];  /* Expression: [0 0 0 1; 0 0 1 0; 0 -1 0 0; -1 0 0 0]
                            * Referenced by: '<S160>/Q_1'
                            */
  real_T Constant8_Value_h;            /* Expression: 0
                                        * Referenced by: '<S160>/Constant8'
                                        */
  real_T Q_2_Value_b[16];  /* Expression: [0 0 -1 0; 0 0 0 1; 1 0 0 0; 0 -1 0 0]
                            * Referenced by: '<S160>/Q_2'
                            */
  real_T Q_3_Value_j[16];  /* Expression: [0 1 0 0; -1 0 0 0; 0 0 0 1; 0 0 -1 0]
                            * Referenced by: '<S160>/Q_3'
                            */
  real_T Q_4_Value_d[16];    /* Expression: [1 0 0 0; 0 1 0 0; 0 0 1 0; 0 0 0 1]
                              * Referenced by: '<S160>/Q_4'
                              */
  real_T Gain1_Gain_c5;                /* Expression: -1
                                        * Referenced by: '<S162>/Gain1'
                                        */
  real_T Gain_Gain_e4;                 /* Expression: 0.5
                                        * Referenced by: '<S160>/Gain'
                                        */
  real_T Gain1_Gain_in;                /* Expression: -1
                                        * Referenced by: '<S163>/Gain1'
                                        */
  real_T Constant8_Value_ck;           /* Expression: 0
                                        * Referenced by: '<S159>/Constant8'
                                        */
  real_T Constant9_Value_l;    /* Expression: HIL_Data.FDM.soph.bus2.flag_I_flat
                                * Referenced by: '<S159>/Constant9'
                                */
  real_T Switch_Threshold_m;           /* Expression: 0
                                        * Referenced by: '<S159>/Switch'
                                        */
  real_T Gain1_Gain_k;                 /* Expression: -1
                                        * Referenced by: '<S145>/Gain1'
                                        */
  real_T Q_1_Value_h[16];  /* Expression: [0 0 0 1; 0 0 1 0; 0 -1 0 0; -1 0 0 0]
                            * Referenced by: '<S164>/Q_1'
                            */
  real_T Constant8_Value_p;            /* Expression: 0
                                        * Referenced by: '<S164>/Constant8'
                                        */
  real_T Q_2_Value_g[16];  /* Expression: [0 0 -1 0; 0 0 0 1; 1 0 0 0; 0 -1 0 0]
                            * Referenced by: '<S164>/Q_2'
                            */
  real_T Q_3_Value_oc[16]; /* Expression: [0 1 0 0; -1 0 0 0; 0 0 0 1; 0 0 -1 0]
                            * Referenced by: '<S164>/Q_3'
                            */
  real_T Q_4_Value_ea[16];   /* Expression: [1 0 0 0; 0 1 0 0; 0 0 1 0; 0 0 0 1]
                              * Referenced by: '<S164>/Q_4'
                              */
  real_T Gain1_Gain_a;                 /* Expression: -1
                                        * Referenced by: '<S166>/Gain1'
                                        */
  real_T Gain_Gain_ba;                 /* Expression: 0.5
                                        * Referenced by: '<S164>/Gain'
                                        */
  real_T Gain1_Gain_mc;                /* Expression: -1
                                        * Referenced by: '<S167>/Gain1'
                                        */
  real_T Gain1_Gain_at;                /* Expression: 2
                                        * Referenced by: '<S165>/Gain1'
                                        */
  real_T Gain2_Gain_m;                 /* Expression: 2
                                        * Referenced by: '<S165>/Gain2'
                                        */
  real_T Gain3_Gain_f;                 /* Expression: 2
                                        * Referenced by: '<S165>/Gain3'
                                        */
  real_T Gain4_Gain_n;                 /* Expression: 2
                                        * Referenced by: '<S165>/Gain4'
                                        */
  real_T Gain5_Gain_n4;                /* Expression: 2
                                        * Referenced by: '<S165>/Gain5'
                                        */
  real_T Gain6_Gain_f;                 /* Expression: 2
                                        * Referenced by: '<S165>/Gain6'
                                        */
  real_T Gain7_Gain_j;                 /* Expression: 2
                                        * Referenced by: '<S165>/Gain7'
                                        */
  real_T Gain8_Gain_eu;                /* Expression: 2
                                        * Referenced by: '<S165>/Gain8'
                                        */
  real_T Gain9_Gain_gr;                /* Expression: 2
                                        * Referenced by: '<S165>/Gain9'
                                        */
  real_T Gain10_Gain_j0;               /* Expression: 2
                                        * Referenced by: '<S165>/Gain10'
                                        */
  real_T Gain11_Gain_nh;               /* Expression: 2
                                        * Referenced by: '<S165>/Gain11'
                                        */
  real_T Gain12_Gain_c;                /* Expression: 2
                                        * Referenced by: '<S165>/Gain12'
                                        */
  real_T Constant_Value_j3;            /* Expression: 0.5
                                        * Referenced by: '<S184>/Constant'
                                        */
  real_T Constant1_Value_ot;           /* Expression: 0.5
                                        * Referenced by: '<S184>/Constant1'
                                        */
  real_T Gain_Gain_pu;                 /* Expression: 2
                                        * Referenced by: '<S184>/Gain'
                                        */
  real_T Saturation_UpperSat_f4;       /* Expression: 1
                                        * Referenced by: '<S184>/Saturation'
                                        */
  real_T Saturation_LowerSat_l;        /* Expression: -1
                                        * Referenced by: '<S184>/Saturation'
                                        */
  real_T Constant9_Value_cv[9];        /* Expression: [0 0 0; 0 0 0; 0 0 0]
                                        * Referenced by: '<S182>/Constant9'
                                        */
  real_T Q_1_Value_f[16];  /* Expression: [0 0 0 1; 0 0 1 0; 0 -1 0 0; -1 0 0 0]
                            * Referenced by: '<S193>/Q_1'
                            */
  real_T Constant_Value_lp;            /* Expression: 0
                                        * Referenced by: '<S193>/Constant'
                                        */
  real_T Q_2_Value_n1[16]; /* Expression: [0 0 -1 0; 0 0 0 1; 1 0 0 0; 0 -1 0 0]
                            * Referenced by: '<S193>/Q_2'
                            */
  real_T Q_3_Value_a[16];  /* Expression: [0 1 0 0; -1 0 0 0; 0 0 0 1; 0 0 -1 0]
                            * Referenced by: '<S193>/Q_3'
                            */
  real_T Q_4_Value_b[16];    /* Expression: [1 0 0 0; 0 1 0 0; 0 0 1 0; 0 0 0 1]
                              * Referenced by: '<S193>/Q_4'
                              */
  real_T Gain1_Gain_o;                 /* Expression: -1
                                        * Referenced by: '<S196>/Gain1'
                                        */
  real_T Gain_Gain_pq;                 /* Expression: 0.5
                                        * Referenced by: '<S193>/Gain'
                                        */
  real_T Gain1_Gain_jq;                /* Expression: -1
                                        * Referenced by: '<S197>/Gain1'
                                        */
  real_T Constant15_Value[9];       /* Expression: HIL_Data.FDM.soph.bus1.J0PB_e
                                     * Referenced by: '<S218>/Constant15'
                                     */
  real_T Constant_Value_bk;           /* Expression: HIL_Data.FDM.soph.bus1.mB_0
                                       * Referenced by: '<S223>/Constant'
                                       */
  real_T Constant17_Value[3];         /* Expression: HIL_Data.FDM.soph.bus1.p0PB
                                       * Referenced by: '<S223>/Constant17'
                                       */
  real_T Gain_Gain_ky;                 /* Expression: -1
                                        * Referenced by: '<S235>/Gain'
                                        */
  real_T Gain1_Gain_oe;                /* Expression: -1
                                        * Referenced by: '<S235>/Gain1'
                                        */
  real_T Gain3_Gain_c;                 /* Expression: -1
                                        * Referenced by: '<S235>/Gain3'
                                        */
  real_T Constant16_Value[3];         /* Expression: HIL_Data.FDM.soph.bus1.pMPB
                                       * Referenced by: '<S224>/Constant16'
                                       */
  real_T Gain_Gain_lt;                 /* Expression: -1
                                        * Referenced by: '<S236>/Gain'
                                        */
  real_T Gain1_Gain_iq;                /* Expression: -1
                                        * Referenced by: '<S236>/Gain1'
                                        */
  real_T Gain3_Gain_fm;                /* Expression: -1
                                        * Referenced by: '<S236>/Gain3'
                                        */
  real_T thrust_rot_x_Value_b;   /* Expression: HIL_Data.FDM.soph.bus1.unc_prp_x
                                  * Referenced by: '<S221>/thrust_rot_x'
                                  */
  real_T thrust_rot_y_Value_j;   /* Expression: HIL_Data.FDM.soph.bus1.unc_prp_y
                                  * Referenced by: '<S221>/thrust_rot_y'
                                  */
  real_T Thrust_rot_z_Value_l;   /* Expression: HIL_Data.FDM.soph.bus1.unc_prp_z
                                  * Referenced by: '<S221>/Thrust_rot_z'
                                  */
  real_T Constant21_Value[9];       /* Expression: HIL_Data.FDM.soph.bus1.JMMM_0
                                     * Referenced by: '<S220>/Constant21'
                                     */
  real_T Constant20_Value;            /* Expression: HIL_Data.FDM.soph.bus1.mM_0
                                       * Referenced by: '<S220>/Constant20'
                                       */
  real_T Constant17_Value_j[9];     /* Expression: HIL_Data.FDM.soph.bus1.JMMM_e
                                     * Referenced by: '<S220>/Constant17'
                                     */
  real_T Constant16_Value_i[9];     /* Expression: HIL_Data.FDM.soph.bus1.JMMM_0
                                     * Referenced by: '<S220>/Constant16'
                                     */
  real_T Constant19_Value;            /* Expression: HIL_Data.FDM.soph.bus1.mM_e
                                       * Referenced by: '<S220>/Constant19'
                                       */
  real_T Constant18_Value;            /* Expression: HIL_Data.FDM.soph.bus1.mM_0
                                       * Referenced by: '<S220>/Constant18'
                                       */
  real_T Constant16_Value_c[9];
  /* Expression: [HIL_Data.FDM.soph.bus1.unc_moi_Jxx,0,0;0,HIL_Data.FDM.soph.bus1.unc_moi_Jyy,0;0,0,HIL_Data.FDM.soph.bus1.unc_moi_Jzz]
   * Referenced by: '<S222>/Constant16'
   */
  real_T Constant_Value_et;     /* Expression: HIL_Data.FDM.soph.bus1.de_JBBB_zz
                                 * Referenced by: '<S215>/Constant'
                                 */
  real_T Constant1_Value_lm;    /* Expression: HIL_Data.FDM.soph.bus1.de_JBBB_xx
                                 * Referenced by: '<S215>/Constant1'
                                 */
  real_T Constant2_Value_j2;    /* Expression: HIL_Data.FDM.soph.bus1.de_JBBB_yy
                                 * Referenced by: '<S215>/Constant2'
                                 */
  real_T Constant5_Value_p;          /* Expression: HIL_Data.FDM.soph.bus1.de_mM
                                      * Referenced by: '<S215>/Constant5'
                                      */
  real_T Constant6_Value_l;            /* Expression: 0
                                        * Referenced by: '<S219>/Constant6'
                                        */
  real32_T ServoCMD_Y0;                /* Computed Parameter: ServoCMD_Y0
                                        * Referenced by: '<S25>/ServoCMD'
                                        */
  real32_T SensorACC_Y0;               /* Computed Parameter: SensorACC_Y0
                                        * Referenced by: '<S25>/SensorACC'
                                        */
  real32_T SensorROT_Y0;               /* Computed Parameter: SensorROT_Y0
                                        * Referenced by: '<S25>/SensorROT'
                                        */
  real32_T quaternion_Y0;              /* Computed Parameter: quaternion_Y0
                                        * Referenced by: '<S25>/quaternion'
                                        */
  real32_T TestSignal_Y0;              /* Computed Parameter: TestSignal_Y0
                                        * Referenced by: '<S25>/TestSignal'
                                        */
  real32_T Constant6_Value_c;          /* Computed Parameter: Constant6_Value_c
                                        * Referenced by: '<S18>/Constant6'
                                        */
  uint32_T Cn_delta_n_Interpolation_dimSize[3];
                         /* Computed Parameter: Cn_delta_n_Interpolation_dimSize
                          * Referenced by: '<S91>/Cn_delta_n_Interpolation'
                          */
  uint32_T Cn_delta_m_Interpolation_dimSize[3];
                         /* Computed Parameter: Cn_delta_m_Interpolation_dimSize
                          * Referenced by: '<S91>/Cn_delta_m_Interpolation'
                          */
  uint32_T Cn_delta_l_Interpolation_dimSize[3];
                         /* Computed Parameter: Cn_delta_l_Interpolation_dimSize
                          * Referenced by: '<S91>/Cn_delta_l_Interpolation'
                          */
  uint32_T Cnr_Interpolation_dimSize[3];
                                /* Computed Parameter: Cnr_Interpolation_dimSize
                                 * Referenced by: '<S91>/Cnr_Interpolation'
                                 */
  uint32_T Cnq_Interpolation_dimSize[3];
                                /* Computed Parameter: Cnq_Interpolation_dimSize
                                 * Referenced by: '<S91>/Cnq_Interpolation'
                                 */
  uint32_T Cnp_Interpolation_dimSize[3];
                                /* Computed Parameter: Cnp_Interpolation_dimSize
                                 * Referenced by: '<S91>/Cnp_Interpolation'
                                 */
  uint32_T Cn_Interpolation_dimSize[3];
                                 /* Computed Parameter: Cn_Interpolation_dimSize
                                  * Referenced by: '<S91>/Cn_Interpolation'
                                  */
  uint32_T Cm_delta_n_Interpolation_dimSize[3];
                         /* Computed Parameter: Cm_delta_n_Interpolation_dimSize
                          * Referenced by: '<S90>/Cm_delta_n_Interpolation'
                          */
  uint32_T Cm_delta_m_Interpolation_dimSize[3];
                         /* Computed Parameter: Cm_delta_m_Interpolation_dimSize
                          * Referenced by: '<S90>/Cm_delta_m_Interpolation'
                          */
  uint32_T Cm_delta_l_Interpolation_dimSize[3];
                         /* Computed Parameter: Cm_delta_l_Interpolation_dimSize
                          * Referenced by: '<S90>/Cm_delta_l_Interpolation'
                          */
  uint32_T Cmr_Interpolation_dimSize[3];
                                /* Computed Parameter: Cmr_Interpolation_dimSize
                                 * Referenced by: '<S90>/Cmr_Interpolation'
                                 */
  uint32_T Cmq_Interpolation_dimSize[3];
                                /* Computed Parameter: Cmq_Interpolation_dimSize
                                 * Referenced by: '<S90>/Cmq_Interpolation'
                                 */
  uint32_T Cmp_Interpolation_dimSize[3];
                                /* Computed Parameter: Cmp_Interpolation_dimSize
                                 * Referenced by: '<S90>/Cmp_Interpolation'
                                 */
  uint32_T Cm_Interpolation_dimSize[3];
                                 /* Computed Parameter: Cm_Interpolation_dimSize
                                  * Referenced by: '<S90>/Cm_Interpolation'
                                  */
  uint32_T Cl_delta_n_Interpolation_dimSize[3];
                         /* Computed Parameter: Cl_delta_n_Interpolation_dimSize
                          * Referenced by: '<S89>/Cl_delta_n_Interpolation'
                          */
  uint32_T Cl_delta_m_Interpolation_dimSize[3];
                         /* Computed Parameter: Cl_delta_m_Interpolation_dimSize
                          * Referenced by: '<S89>/Cl_delta_m_Interpolation'
                          */
  uint32_T Cl_delta_l_Interpolation_dimSize[3];
                         /* Computed Parameter: Cl_delta_l_Interpolation_dimSize
                          * Referenced by: '<S89>/Cl_delta_l_Interpolation'
                          */
  uint32_T Clr_Interpolation_dimSize[3];
                                /* Computed Parameter: Clr_Interpolation_dimSize
                                 * Referenced by: '<S89>/Clr_Interpolation'
                                 */
  uint32_T Clq_Interpolation_dimSize[3];
                                /* Computed Parameter: Clq_Interpolation_dimSize
                                 * Referenced by: '<S89>/Clq_Interpolation'
                                 */
  uint32_T Clp_Interpolation_dimSize[3];
                                /* Computed Parameter: Clp_Interpolation_dimSize
                                 * Referenced by: '<S89>/Clp_Interpolation'
                                 */
  uint32_T Cl_Interpolation_dimSize[3];
                                 /* Computed Parameter: Cl_Interpolation_dimSize
                                  * Referenced by: '<S89>/Cl_Interpolation'
                                  */
  uint32_T Cx_Interpolation_dimSize[3];
                                 /* Computed Parameter: Cx_Interpolation_dimSize
                                  * Referenced by: '<S92>/Cx_Interpolation'
                                  */
  uint32_T Cxp_Interpolation_dimSize[3];
                                /* Computed Parameter: Cxp_Interpolation_dimSize
                                 * Referenced by: '<S92>/Cxp_Interpolation'
                                 */
  uint32_T Cxq_Interpolation_dimSize[3];
                                /* Computed Parameter: Cxq_Interpolation_dimSize
                                 * Referenced by: '<S92>/Cxq_Interpolation'
                                 */
  uint32_T Cxr_Interpolation_dimSize[3];
                                /* Computed Parameter: Cxr_Interpolation_dimSize
                                 * Referenced by: '<S92>/Cxr_Interpolation'
                                 */
  uint32_T Cx_delta_l_Interpolation_dimSize[3];
                         /* Computed Parameter: Cx_delta_l_Interpolation_dimSize
                          * Referenced by: '<S92>/Cx_delta_l_Interpolation'
                          */
  uint32_T Cx_delta_m_Interpolation_dimSize[3];
                         /* Computed Parameter: Cx_delta_m_Interpolation_dimSize
                          * Referenced by: '<S92>/Cx_delta_m_Interpolation'
                          */
  uint32_T Cx_delta_n_Interpolation_dimSize[3];
                         /* Computed Parameter: Cx_delta_n_Interpolation_dimSize
                          * Referenced by: '<S92>/Cx_delta_n_Interpolation'
                          */
  uint32_T Cx_alt_Interpolation_dimSize[3];
                             /* Computed Parameter: Cx_alt_Interpolation_dimSize
                              * Referenced by: '<S92>/Cx_alt_Interpolation'
                              */
  uint32_T Cx_delta_t_Interpolation_dimSize[3];
                         /* Computed Parameter: Cx_delta_t_Interpolation_dimSize
                          * Referenced by: '<S92>/Cx_delta_t_Interpolation'
                          */
  uint32_T Cx_base_Interpolation_dimSize[3];
                            /* Computed Parameter: Cx_base_Interpolation_dimSize
                             * Referenced by: '<S92>/Cx_base_Interpolation'
                             */
  uint32_T Cy_Interpolation_dimSize[3];
                                 /* Computed Parameter: Cy_Interpolation_dimSize
                                  * Referenced by: '<S93>/Cy_Interpolation'
                                  */
  uint32_T Cyp_Interpolation_dimSize[3];
                                /* Computed Parameter: Cyp_Interpolation_dimSize
                                 * Referenced by: '<S93>/Cyp_Interpolation'
                                 */
  uint32_T Cyq_Interpolation_dimSize[3];
                                /* Computed Parameter: Cyq_Interpolation_dimSize
                                 * Referenced by: '<S93>/Cyq_Interpolation'
                                 */
  uint32_T Cyr_Interpolation_dimSize[3];
                                /* Computed Parameter: Cyr_Interpolation_dimSize
                                 * Referenced by: '<S93>/Cyr_Interpolation'
                                 */
  uint32_T Cy_delta_l_Interpolation_dimSize[3];
                         /* Computed Parameter: Cy_delta_l_Interpolation_dimSize
                          * Referenced by: '<S93>/Cy_delta_l_Interpolation'
                          */
  uint32_T Cy_delta_m_Interpolation_dimSize[3];
                         /* Computed Parameter: Cy_delta_m_Interpolation_dimSize
                          * Referenced by: '<S93>/Cy_delta_m_Interpolation'
                          */
  uint32_T Cy_delta_n_Interpolation_dimSize[3];
                         /* Computed Parameter: Cy_delta_n_Interpolation_dimSize
                          * Referenced by: '<S93>/Cy_delta_n_Interpolation'
                          */
  uint32_T Cz_Interpolation_dimSize[3];
                                 /* Computed Parameter: Cz_Interpolation_dimSize
                                  * Referenced by: '<S94>/Cz_Interpolation'
                                  */
  uint32_T Czp_Interpolation_dimSize[3];
                                /* Computed Parameter: Czp_Interpolation_dimSize
                                 * Referenced by: '<S94>/Czp_Interpolation'
                                 */
  uint32_T Czq_Interpolation_dimSize[3];
                                /* Computed Parameter: Czq_Interpolation_dimSize
                                 * Referenced by: '<S94>/Czq_Interpolation'
                                 */
  uint32_T Czr_Interpolation_dimSize[3];
                                /* Computed Parameter: Czr_Interpolation_dimSize
                                 * Referenced by: '<S94>/Czr_Interpolation'
                                 */
  uint32_T Cz_delta_l_Interpolation_dimSize[3];
                         /* Computed Parameter: Cz_delta_l_Interpolation_dimSize
                          * Referenced by: '<S94>/Cz_delta_l_Interpolation'
                          */
  uint32_T Cz_delta_m_Interpolation_dimSize[3];
                         /* Computed Parameter: Cz_delta_m_Interpolation_dimSize
                          * Referenced by: '<S94>/Cz_delta_m_Interpolation'
                          */
  uint32_T Cz_delta_n_Interpolation_dimSize[3];
                         /* Computed Parameter: Cz_delta_n_Interpolation_dimSize
                          * Referenced by: '<S94>/Cz_delta_n_Interpolation'
                          */
  uint16_T PixHeartbeat_Y0;            /* Computed Parameter: PixHeartbeat_Y0
                                        * Referenced by: '<S25>/PixHeartbeat'
                                        */
  uint16_T FCC_heartbeat_Y0;           /* Computed Parameter: FCC_heartbeat_Y0
                                        * Referenced by: '<S36>/FCC_heartbeat'
                                        */
  uint16_T Constant_Value_lk;          /* Computed Parameter: Constant_Value_lk
                                        * Referenced by: '<S241>/Constant'
                                        */
  uint16_T Constant2_Value_l;          /* Computed Parameter: Constant2_Value_l
                                        * Referenced by: '<S20>/Constant2'
                                        */
  uint16_T Output_InitialCondition;
                                  /* Computed Parameter: Output_InitialCondition
                                   * Referenced by: '<S239>/Output'
                                   */
  uint16_T FixPtConstant_Value;       /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S240>/FixPt Constant'
                                       */
  boolean_T Constant10_Value_ca;
                /* Expression: External_Inputs.FCC.CMD.yaw.pulse.alternating_flg
                 * Referenced by: '<S17>/Constant10'
                 */
  boolean_T Constant6_Value_b;
               /* Expression: External_Inputs.FCC.CMD.roll.pulse.alternating_flg
                * Referenced by: '<S17>/Constant6'
                */
  boolean_T Constant8_Value_ej;
              /* Expression: External_Inputs.FCC.CMD.pitch.pulse.alternating_flg
               * Referenced by: '<S17>/Constant8'
               */
  boolean_T Status_Y0;                 /* Computed Parameter: Status_Y0
                                        * Referenced by: '<S21>/Status'
                                        */
  boolean_T packetfound_flg_Y0;        /* Computed Parameter: packetfound_flg_Y0
                                        * Referenced by: '<S22>/packetfound_flg'
                                        */
  boolean_T Constant9_Value_b;         /* Computed Parameter: Constant9_Value_b
                                        * Referenced by: '<S7>/Constant9'
                                        */
  boolean_T Constant12_Value_e;        /* Computed Parameter: Constant12_Value_e
                                        * Referenced by: '<S7>/Constant12'
                                        */
  boolean_T Constant_Value_gt;         /* Computed Parameter: Constant_Value_gt
                                        * Referenced by: '<S7>/Constant'
                                        */
  boolean_T Constant2_Value_f5;        /* Computed Parameter: Constant2_Value_f5
                                        * Referenced by: '<S7>/Constant2'
                                        */
  boolean_T Constant3_Value_k;         /* Computed Parameter: Constant3_Value_k
                                        * Referenced by: '<S35>/Constant3'
                                        */
  boolean_T Constant1_Value_c3;        /* Computed Parameter: Constant1_Value_c3
                                        * Referenced by: '<S7>/Constant1'
                                        */
  boolean_T Constant3_Value_it;
                             /* Expression: HIL_Data.Simulation_Ctrl.offline_flg
                              * Referenced by: '<S7>/Constant3'
                              */
  uint8_T Data_Y0;                     /* Computed Parameter: Data_Y0
                                        * Referenced by: '<S21>/Data'
                                        */
  uint8_T PixStatus_Y0;                /* Computed Parameter: PixStatus_Y0
                                        * Referenced by: '<S25>/PixStatus'
                                        */
  uint8_T PixRCStatus_Y0;              /* Computed Parameter: PixRCStatus_Y0
                                        * Referenced by: '<S25>/PixRCStatus'
                                        */
  uint8_T message_pass_Y0;             /* Computed Parameter: message_pass_Y0
                                        * Referenced by: '<S32>/message_pass'
                                        */
  uint8_T Constant_Value_jh;           /* Computed Parameter: Constant_Value_jh
                                        * Referenced by: '<S20>/Constant'
                                        */
  uint8_T Constant1_Value_ec;          /* Computed Parameter: Constant1_Value_ec
                                        * Referenced by: '<S20>/Constant1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_GRM_HIL_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;
  void *blockIO;
  const void *constBlockIO;
  void *defaultParam;
  ZCSigState *prevZCSigState;
  real_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  void *zcSignalValues;
  void *inputs;
  void *outputs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[37];
  real_T odeF[3][37];
  ODE3_IntgData intgData;
  void *dwork;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    uint32_T clockTick2;
    uint32_T clockTickH2;
    time_T stepSize2;
    uint32_T clockTick3;
    uint32_T clockTickH3;
    time_T stepSize3;
    boolean_T firstInitCondFlag;
    struct {
      uint8_T TID[4];
    } TaskCounters;

    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[4];
    time_T offsetTimesArray[4];
    int_T sampleTimeTaskIDArray[4];
    int_T sampleHitArray[4];
    int_T perTaskSampleHitsArray[16];
    time_T tArray[4];
  } Timing;
};

/* Block parameters (default storage) */
extern P_GRM_HIL_T GRM_HIL_P;

/* Block signals (default storage) */
extern B_GRM_HIL_T GRM_HIL_B;

/* Continuous states (default storage) */
extern X_GRM_HIL_T GRM_HIL_X;

/* Block states (default storage) */
extern DW_GRM_HIL_T GRM_HIL_DW;

/* External data declarations for dependent source files */

/* Zero-crossing (trigger) state */
extern PrevZCX_GRM_HIL_T GRM_HIL_PrevZCX;

/* Model entry point functions */
extern void GRM_HIL_initialize(void);
extern void GRM_HIL_output(void);
extern void GRM_HIL_update(void);
extern void GRM_HIL_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern GRM_HIL_rtModel *GRM_HIL(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_GRM_HIL_T *const GRM_HIL_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'GRM_HIL'
 * '<S1>'   : 'GRM_HIL/Actuators'
 * '<S2>'   : 'GRM_HIL/External_Inputs'
 * '<S3>'   : 'GRM_HIL/FCC'
 * '<S4>'   : 'GRM_HIL/Gimbal'
 * '<S5>'   : 'GRM_HIL/Initial_States'
 * '<S6>'   : 'GRM_HIL/Simulation'
 * '<S7>'   : 'GRM_HIL/Simulation_Ctrl'
 * '<S8>'   : 'GRM_HIL/Stop Simulation'
 * '<S9>'   : 'GRM_HIL/Actuators/Emulate_Actuators'
 * '<S10>'  : 'GRM_HIL/Actuators/Emulate_Actuators/Encoder'
 * '<S11>'  : 'GRM_HIL/Actuators/Emulate_Actuators/Servo'
 * '<S12>'  : 'GRM_HIL/Actuators/Emulate_Actuators/Servo2Control_Surfaces'
 * '<S13>'  : 'GRM_HIL/Actuators/Emulate_Actuators/Servo/Servo_1'
 * '<S14>'  : 'GRM_HIL/Actuators/Emulate_Actuators/Servo/Servo_2'
 * '<S15>'  : 'GRM_HIL/Actuators/Emulate_Actuators/Servo/Servo_3'
 * '<S16>'  : 'GRM_HIL/Actuators/Emulate_Actuators/Servo/Servo_4'
 * '<S17>'  : 'GRM_HIL/External_Inputs/Commands_Generator'
 * '<S18>'  : 'GRM_HIL/FCC/Use_FCC'
 * '<S19>'  : 'GRM_HIL/FCC/Use_FCC/Serial_Recieve_from_Pixhawk'
 * '<S20>'  : 'GRM_HIL/FCC/Use_FCC/Serial_Send_to_Pixhawk'
 * '<S21>'  : 'GRM_HIL/FCC/Use_FCC/Serial_Recieve_from_Pixhawk/Receive_ExternalMode'
 * '<S22>'  : 'GRM_HIL/FCC/Use_FCC/Serial_Recieve_from_Pixhawk/input_hold'
 * '<S23>'  : 'GRM_HIL/FCC/Use_FCC/Serial_Recieve_from_Pixhawk/input_hold/ByteUnpack'
 * '<S24>'  : 'GRM_HIL/FCC/Use_FCC/Serial_Recieve_from_Pixhawk/input_hold/ExtractMessage'
 * '<S25>'  : 'GRM_HIL/FCC/Use_FCC/Serial_Recieve_from_Pixhawk/input_hold/hold'
 * '<S26>'  : 'GRM_HIL/FCC/Use_FCC/Serial_Send_to_Pixhawk/Com_Sync'
 * '<S27>'  : 'GRM_HIL/FCC/Use_FCC/Serial_Send_to_Pixhawk/CreateVector'
 * '<S28>'  : 'GRM_HIL/FCC/Use_FCC/Serial_Send_to_Pixhawk/send_to_pix'
 * '<S29>'  : 'GRM_HIL/FCC/Use_FCC/Serial_Send_to_Pixhawk/Com_Sync/Counter_with_external_limit'
 * '<S30>'  : 'GRM_HIL/FCC/Use_FCC/Serial_Send_to_Pixhawk/send_to_pix/MessageAssembly'
 * '<S31>'  : 'GRM_HIL/FCC/Use_FCC/Serial_Send_to_Pixhawk/send_to_pix/Send_ExternalMode'
 * '<S32>'  : 'GRM_HIL/FCC/Use_FCC/Serial_Send_to_Pixhawk/send_to_pix/no_CRC'
 * '<S33>'  : 'GRM_HIL/Gimbal/Use_Gimbal_HWInterface_CC'
 * '<S34>'  : 'GRM_HIL/Gimbal/Use_Gimbal_HWInterface_CC/Communication_FT_HWI_ControlComputer'
 * '<S35>'  : 'GRM_HIL/Gimbal/Use_Gimbal_HWInterface_CC/Communication_FT_HWI_ControlComputer/Com_Sync'
 * '<S36>'  : 'GRM_HIL/Gimbal/Use_Gimbal_HWInterface_CC/Communication_FT_HWI_ControlComputer/Construct_Bus'
 * '<S37>'  : 'GRM_HIL/Gimbal/Use_Gimbal_HWInterface_CC/Communication_FT_HWI_ControlComputer/Send_to_FTHWICC'
 * '<S38>'  : 'GRM_HIL/Gimbal/Use_Gimbal_HWInterface_CC/Communication_FT_HWI_ControlComputer/Com_Sync/Counter_with_external_limit'
 * '<S39>'  : 'GRM_HIL/Gimbal/Use_Gimbal_HWInterface_CC/Communication_FT_HWI_ControlComputer/Construct_Bus/Assemble_Gimbal_Subbusses'
 * '<S40>'  : 'GRM_HIL/Gimbal/Use_Gimbal_HWInterface_CC/Communication_FT_HWI_ControlComputer/Construct_Bus/Assemble_Gimbal_Subbusses/Emulate_Encoder_Signals'
 * '<S41>'  : 'GRM_HIL/Gimbal/Use_Gimbal_HWInterface_CC/Communication_FT_HWI_ControlComputer/Construct_Bus/Assemble_Gimbal_Subbusses/Eul2Quat'
 * '<S42>'  : 'GRM_HIL/Gimbal/Use_Gimbal_HWInterface_CC/Communication_FT_HWI_ControlComputer/Construct_Bus/Assemble_Gimbal_Subbusses/Eul2Quat/Rotation Angles to Quaternions'
 * '<S43>'  : 'GRM_HIL/Initial_States/Assemble_States_Bus'
 * '<S44>'  : 'GRM_HIL/Initial_States/Assemble_States_Bus/Rotation Angles to Quaternions'
 * '<S45>'  : 'GRM_HIL/Simulation/FDM'
 * '<S46>'  : 'GRM_HIL/Simulation/Gimbel_Cmd'
 * '<S47>'  : 'GRM_HIL/Simulation/IMU_GPS_Emulator'
 * '<S48>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated'
 * '<S49>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/Assemble_States_Bus'
 * '<S50>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/MATLAB Function'
 * '<S51>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/Subsystem'
 * '<S52>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics'
 * '<S53>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/environment'
 * '<S54>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/fin_actuators'
 * '<S55>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/forces_moments'
 * '<S56>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/gravity'
 * '<S57>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/input'
 * '<S58>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics'
 * '<S59>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/propulsion'
 * '<S60>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/quaternion_to_euler_angles'
 * '<S61>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/rb_eom'
 * '<S62>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/stream_flow'
 * '<S63>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/tmp'
 * '<S64>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/weight_and_balance'
 * '<S65>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/Assemble_States_Bus/Rotation Angles to Quaternions'
 * '<S66>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/Subsystem/Degrees to Radians'
 * '<S67>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/Subsystem/Degrees to Radians1'
 * '<S68>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/Subsystem/Degrees to Radians2'
 * '<S69>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/Subsystem/control_allocation'
 * '<S70>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup'
 * '<S71>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/logic_base_drag'
 * '<S72>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_aero_coefficients'
 * '<S73>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_aero_for_mom'
 * '<S74>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_derivatives'
 * '<S75>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/transform_rad2deg_al_be'
 * '<S76>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/transform_rad2deg_fin'
 * '<S77>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/transform_rad2deg_rates'
 * '<S78>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_aero_for_mom/cross_product'
 * '<S79>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_aero_for_mom/launch_rail'
 * '<S80>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_aero_for_mom/launch_rail1'
 * '<S81>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_aero_for_mom/launch_rail/initial_altitude'
 * '<S82>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_aero_for_mom/launch_rail/initial_altitude/trafo_E_to_geodetic'
 * '<S83>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_aero_for_mom/launch_rail/initial_altitude/trafo_E_to_geodetic/Geodetic_altitude'
 * '<S84>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_aero_for_mom/launch_rail/initial_altitude/trafo_E_to_geodetic/Geodetic_latitude'
 * '<S85>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_aero_for_mom/launch_rail1/initial_altitude'
 * '<S86>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_aero_for_mom/launch_rail1/initial_altitude/trafo_E_to_geodetic'
 * '<S87>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_aero_for_mom/launch_rail1/initial_altitude/trafo_E_to_geodetic/Geodetic_altitude'
 * '<S88>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_aero_for_mom/launch_rail1/initial_altitude/trafo_E_to_geodetic/Geodetic_latitude'
 * '<S89>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_derivatives/Cl_derivatives_lookup'
 * '<S90>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_derivatives/Cm_derivatives_lookup'
 * '<S91>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_derivatives/Cn_derivatives_lookup'
 * '<S92>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_derivatives/Cx_derivatives_lookup'
 * '<S93>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_derivatives/Cy_derivatives_lookup'
 * '<S94>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_derivatives/Cz_derivatives_lookup'
 * '<S95>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_derivatives/aerodynamics_pre_lookup'
 * '<S96>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_derivatives/calc_total_deflection_angle'
 * '<S97>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_derivatives/calc_total_deflection_angle/Degrees to Radians'
 * '<S98>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_derivatives/calc_total_deflection_angle/Degrees to Radians1'
 * '<S99>'  : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_derivatives/calc_total_deflection_angle/Radians to Degrees1'
 * '<S100>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/transform_rad2deg_al_be/Radians to Degrees'
 * '<S101>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/transform_rad2deg_al_be/Radians to Degrees1'
 * '<S102>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/transform_rad2deg_fin/Radians to Degrees'
 * '<S103>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/transform_rad2deg_fin/Radians to Degrees1'
 * '<S104>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/transform_rad2deg_fin/Radians to Degrees2'
 * '<S105>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/transform_rad2deg_rates/Radians to Degrees'
 * '<S106>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/transform_rad2deg_rates/Radians to Degrees1'
 * '<S107>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/transform_rad2deg_rates/Radians to Degrees2'
 * '<S108>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/logic_base_drag/MATLAB Function'
 * '<S109>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/environment/WGS84_Gravitation'
 * '<S110>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/environment/atmosphere_static_ISO_2533'
 * '<S111>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/environment/convert_to_local_frame'
 * '<S112>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/environment/WGS84_Gravitation/Compare To Constant'
 * '<S113>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/environment/WGS84_Gravitation/Interval Test'
 * '<S114>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/environment/WGS84_Gravitation/Interval Test1'
 * '<S115>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/environment/WGS84_Gravitation/WGS84_2_ECEF'
 * '<S116>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/environment/WGS84_Gravitation/WGS84_Gravity_Implementation'
 * '<S117>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/environment/WGS84_Gravitation/WGS84_2_ECEF/WGS84 Transformation Parameter '
 * '<S118>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/environment/WGS84_Gravitation/WGS84_2_ECEF/WGS84 Transformation Parameter /Subsystem'
 * '<S119>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/environment/atmosphere_static_ISO_2533/density'
 * '<S120>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/environment/atmosphere_static_ISO_2533/geopot_height'
 * '<S121>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/environment/atmosphere_static_ISO_2533/speed_of_sound'
 * '<S122>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/environment/atmosphere_static_ISO_2533/tmp_and_pressure_ISO_2533'
 * '<S123>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/environment/atmosphere_static_ISO_2533/tmp_and_pressure_ISO_2533/static_Temperature'
 * '<S124>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/environment/atmosphere_static_ISO_2533/tmp_and_pressure_ISO_2533/static_pressure'
 * '<S125>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/fin_actuators/Rudder'
 * '<S126>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/fin_actuators/Rudder1'
 * '<S127>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/fin_actuators/Rudder2'
 * '<S128>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/fin_actuators/Rudder3'
 * '<S129>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/fin_actuators/control_allocation'
 * '<S130>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/fin_actuators/Rudder/Limiting_Acceleration'
 * '<S131>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/fin_actuators/Rudder/Limiting_Rate'
 * '<S132>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/fin_actuators/Rudder1/Limiting_Acceleration'
 * '<S133>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/fin_actuators/Rudder1/Limiting_Rate'
 * '<S134>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/fin_actuators/Rudder2/Limiting_Acceleration'
 * '<S135>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/fin_actuators/Rudder2/Limiting_Rate'
 * '<S136>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/fin_actuators/Rudder3/Limiting_Acceleration'
 * '<S137>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/fin_actuators/Rudder3/Limiting_Rate'
 * '<S138>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/gravity/launch_rail'
 * '<S139>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/gravity/launch_rail/initial_altitude'
 * '<S140>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/gravity/launch_rail/initial_altitude/trafo_E_to_geodetic'
 * '<S141>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/gravity/launch_rail/initial_altitude/trafo_E_to_geodetic/Geodetic_altitude'
 * '<S142>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/gravity/launch_rail/initial_altitude/trafo_E_to_geodetic/Geodetic_latitude'
 * '<S143>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics'
 * '<S144>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics/calc_transformation_matrix'
 * '<S145>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics/earth_rotation'
 * '<S146>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics/calc_transformation_matrix/T12_from_q1'
 * '<S147>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics/calc_transformation_matrix/T12_from_q12'
 * '<S148>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics/calc_transformation_matrix/T12_from_q2'
 * '<S149>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics/calc_transformation_matrix/conjugate_quaternion'
 * '<S150>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics/calc_transformation_matrix/q31_from_q32_mul_q1'
 * '<S151>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics/calc_transformation_matrix/q31_from_q32_mul_q2'
 * '<S152>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics/calc_transformation_matrix/q31_from_q32_mul_q21'
 * '<S153>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics/calc_transformation_matrix/q31_from_q32_mul_q1/normalize_quaternion'
 * '<S154>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics/calc_transformation_matrix/q31_from_q32_mul_q2/normalize_quaternion'
 * '<S155>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics/calc_transformation_matrix/q31_from_q32_mul_q21/normalize_quaternion'
 * '<S156>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics/earth_rotation/earth_rotation_rate'
 * '<S157>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics/earth_rotation/quaternion_integration'
 * '<S158>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics/earth_rotation/quaternion_integration1'
 * '<S159>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics/earth_rotation/transport_rate'
 * '<S160>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics/earth_rotation/quaternion_integration/Subsystem1'
 * '<S161>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics/earth_rotation/quaternion_integration/T12_from_q12'
 * '<S162>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics/earth_rotation/quaternion_integration/Subsystem1/conjugate_quaternion1'
 * '<S163>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics/earth_rotation/quaternion_integration/Subsystem1/conjugate_quaternion2'
 * '<S164>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics/earth_rotation/quaternion_integration1/Subsystem1'
 * '<S165>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics/earth_rotation/quaternion_integration1/T12_from_q12'
 * '<S166>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics/earth_rotation/quaternion_integration1/Subsystem1/conjugate_quaternion1'
 * '<S167>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics/earth_rotation/quaternion_integration1/Subsystem1/conjugate_quaternion2'
 * '<S168>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/propulsion/prp_look_up'
 * '<S169>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/propulsion/prp_uncertainty'
 * '<S170>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/propulsion/prp_uncertainty/3_rot_mat'
 * '<S171>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/propulsion/prp_uncertainty/cross_product'
 * '<S172>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/propulsion/prp_uncertainty/3_rot_mat/1. Rotation x-Achse'
 * '<S173>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/propulsion/prp_uncertainty/3_rot_mat/1. Rotation y-Achse'
 * '<S174>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/propulsion/prp_uncertainty/3_rot_mat/1. Rotation z-Achse'
 * '<S175>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/propulsion/prp_uncertainty/3_rot_mat/2. Rotation x-Achse'
 * '<S176>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/propulsion/prp_uncertainty/3_rot_mat/2. Rotation y-Achse'
 * '<S177>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/propulsion/prp_uncertainty/3_rot_mat/2. Rotation z-Achse'
 * '<S178>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/propulsion/prp_uncertainty/3_rot_mat/3. Rotation x-Achse'
 * '<S179>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/propulsion/prp_uncertainty/3_rot_mat/3. Rotation y-Achse'
 * '<S180>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/propulsion/prp_uncertainty/3_rot_mat/3. Rotation z-Achse'
 * '<S181>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/rb_eom/calc_bus_flight_dyn_bus_entries'
 * '<S182>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/rb_eom/eom_6dof'
 * '<S183>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/rb_eom/calc_bus_flight_dyn_bus_entries/Subsystem2'
 * '<S184>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/rb_eom/calc_bus_flight_dyn_bus_entries/quaternion_to_euler_angles'
 * '<S185>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/rb_eom/calc_bus_flight_dyn_bus_entries/Subsystem2/trafo_E_to_geodetic'
 * '<S186>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/rb_eom/calc_bus_flight_dyn_bus_entries/Subsystem2/trafo_E_to_geodetic/Geodetic_altitude'
 * '<S187>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/rb_eom/calc_bus_flight_dyn_bus_entries/Subsystem2/trafo_E_to_geodetic/Geodetic_latitude'
 * '<S188>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/rb_eom/eom_6dof/Rigid_Body_EOM_6_DOF'
 * '<S189>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/rb_eom/eom_6dof/Rigid_Body_EOM_6_DOF/Integration'
 * '<S190>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/rb_eom/eom_6dof/Rigid_Body_EOM_6_DOF/T12_from_q12'
 * '<S191>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/rb_eom/eom_6dof/Rigid_Body_EOM_6_DOF/rb_eom_6dof'
 * '<S192>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/rb_eom/eom_6dof/Rigid_Body_EOM_6_DOF/Integration/normalize_quaternion'
 * '<S193>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/rb_eom/eom_6dof/Rigid_Body_EOM_6_DOF/rb_eom_6dof/calc_d_qIB'
 * '<S194>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/rb_eom/eom_6dof/Rigid_Body_EOM_6_DOF/rb_eom_6dof/cross_product'
 * '<S195>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/rb_eom/eom_6dof/Rigid_Body_EOM_6_DOF/rb_eom_6dof/r2_from_r1_trans_q21'
 * '<S196>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/rb_eom/eom_6dof/Rigid_Body_EOM_6_DOF/rb_eom_6dof/calc_d_qIB/conjugate_quaternion'
 * '<S197>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/rb_eom/eom_6dof/Rigid_Body_EOM_6_DOF/rb_eom_6dof/calc_d_qIB/conjugate_quaternion1'
 * '<S198>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/stream_flow/calc_stream_flow'
 * '<S199>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/stream_flow/calc_stream_flow/Subsystem1'
 * '<S200>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/stream_flow/calc_stream_flow/velocity_vector_transformation'
 * '<S201>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/stream_flow/calc_stream_flow/Subsystem1/AoA_Sideslip_Alphatot_Phi'
 * '<S202>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/stream_flow/calc_stream_flow/Subsystem1/calc_nondimensional_rates'
 * '<S203>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/stream_flow/calc_stream_flow/Subsystem1/norm_of_vector'
 * '<S204>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/stream_flow/calc_stream_flow/Subsystem1/AoA_Sideslip_Alphatot_Phi/norm_of_vector'
 * '<S205>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/stream_flow/calc_stream_flow/velocity_vector_transformation/cross_product'
 * '<S206>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/tmp/Time'
 * '<S207>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/tmp/weather'
 * '<S208>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/tmp/weather/atm_dynamic'
 * '<S209>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/tmp/weather/atm_dynamic/trafo_around_z_axis'
 * '<S210>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/tmp/weather/atm_dynamic/trafo_around_z_axis/1_rot_mat'
 * '<S211>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/tmp/weather/atm_dynamic/trafo_around_z_axis/1_rot_mat/1. Rotation x-Achse'
 * '<S212>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/tmp/weather/atm_dynamic/trafo_around_z_axis/1_rot_mat/1. Rotation y-Achse'
 * '<S213>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/tmp/weather/atm_dynamic/trafo_around_z_axis/1_rot_mat/1. Rotation z-Achse'
 * '<S214>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/weight_and_balance/center_of_gravity'
 * '<S215>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/weight_and_balance/d_moi'
 * '<S216>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/weight_and_balance/mass'
 * '<S217>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/weight_and_balance/mass_uncertainty'
 * '<S218>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/weight_and_balance/moi'
 * '<S219>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/weight_and_balance/d_moi/vector2diagonal_matrix'
 * '<S220>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/weight_and_balance/moi/JMMM_linear_interpolation'
 * '<S221>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/weight_and_balance/moi/moi_coordinate_transformation'
 * '<S222>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/weight_and_balance/moi/moi_uncertainty'
 * '<S223>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/weight_and_balance/moi/steiners_theorem_missile'
 * '<S224>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/weight_and_balance/moi/steiners_theorem_motor'
 * '<S225>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/weight_and_balance/moi/moi_coordinate_transformation/3_rot_mat'
 * '<S226>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/weight_and_balance/moi/moi_coordinate_transformation/3_rot_mat/1. Rotation x-Achse'
 * '<S227>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/weight_and_balance/moi/moi_coordinate_transformation/3_rot_mat/1. Rotation y-Achse'
 * '<S228>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/weight_and_balance/moi/moi_coordinate_transformation/3_rot_mat/1. Rotation z-Achse'
 * '<S229>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/weight_and_balance/moi/moi_coordinate_transformation/3_rot_mat/2. Rotation x-Achse'
 * '<S230>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/weight_and_balance/moi/moi_coordinate_transformation/3_rot_mat/2. Rotation y-Achse'
 * '<S231>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/weight_and_balance/moi/moi_coordinate_transformation/3_rot_mat/2. Rotation z-Achse'
 * '<S232>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/weight_and_balance/moi/moi_coordinate_transformation/3_rot_mat/3. Rotation x-Achse'
 * '<S233>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/weight_and_balance/moi/moi_coordinate_transformation/3_rot_mat/3. Rotation y-Achse'
 * '<S234>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/weight_and_balance/moi/moi_coordinate_transformation/3_rot_mat/3. Rotation z-Achse'
 * '<S235>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/weight_and_balance/moi/steiners_theorem_missile/create_deviation_matrix'
 * '<S236>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/weight_and_balance/moi/steiners_theorem_motor/create_deviation_matrix1'
 * '<S237>' : 'GRM_HIL/Simulation_Ctrl/Synchronize_to_realtime'
 * '<S238>' : 'GRM_HIL/Simulation_Ctrl/hearbeat_SIM'
 * '<S239>' : 'GRM_HIL/Simulation_Ctrl/hearbeat_SIM/Counter Free-Running'
 * '<S240>' : 'GRM_HIL/Simulation_Ctrl/hearbeat_SIM/Counter Free-Running/Increment Real World'
 * '<S241>' : 'GRM_HIL/Simulation_Ctrl/hearbeat_SIM/Counter Free-Running/Wrap To Zero'
 * '<S242>' : 'GRM_HIL/Stop Simulation/Compare To Constant'
 */
#endif                                 /* RTW_HEADER_GRM_HIL_h_ */
