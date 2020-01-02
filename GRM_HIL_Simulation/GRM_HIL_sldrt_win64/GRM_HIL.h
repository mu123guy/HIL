/*
 * GRM_HIL.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "GRM_HIL".
 *
 * Model version              : 1.89
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Fri Jan  3 00:14:15 2020
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_GRM_HIL_h_
#define RTW_HEADER_GRM_HIL_h_
#include <float.h>
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

/* Block states (default storage) for system '<S52>/Enabled pass' */
typedef struct {
  int8_T Enabledpass_SubsysRanBC;      /* '<S52>/Enabled pass' */
  boolean_T Enabledpass_MODE;          /* '<S52>/Enabled pass' */
} DW_Enabledpass_GRM_HIL_T;

/* Block states (default storage) for system '<S53>/Saturation' */
typedef struct {
  int8_T Saturation_SubsysRanBC;       /* '<S53>/Saturation' */
} DW_Saturation_GRM_HIL_T;

/* Block states (default storage) for system '<S53>/pass' */
typedef struct {
  int8_T pass_SubsysRanBC;             /* '<S53>/pass' */
} DW_pass_GRM_HIL_T;

/* Block signals for system '<S173>/If Action Subsystem1' */
typedef struct {
  real_T In1;                          /* '<S177>/In1' */
} B_IfActionSubsystem1_GRM_HIL_T;

/* Block states (default storage) for system '<S173>/If Action Subsystem1' */
typedef struct {
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S173>/If Action Subsystem1' */
} DW_IfActionSubsystem1_GRM_HIL_T;

/* Block signals for system '<S173>/If Action Subsystem' */
typedef struct {
  real_T In1;                          /* '<S176>/In1' */
} B_IfActionSubsystem_GRM_HIL_T;

/* Block states (default storage) for system '<S173>/If Action Subsystem' */
typedef struct {
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S173>/If Action Subsystem' */
} DW_IfActionSubsystem_GRM_HIL_T;

/* Block states (default storage) for system '<S51>/If Action pass_yaw' */
typedef struct {
  int8_T IfActionpass_yaw_SubsysRanBC; /* '<S51>/If Action pass_yaw' */
} DW_IfActionpass_yaw_GRM_HIL_T;

/* Block signals for system '<S270>/Limiting_Acceleration' */
typedef struct {
  real_T dd_siB_l;                     /* '<S270>/Limiting_Acceleration' */
} B_Limiting_Acceleration_GRM_HIL_T;

/* Block signals for system '<S270>/Limiting_Rate' */
typedef struct {
  real_T d_siB_l;                      /* '<S270>/Limiting_Rate' */
} B_Limiting_Rate_GRM_HIL_T;

/* Block signals (default storage) */
typedef struct {
  real_T Constant[13];                 /* '<S327>/Constant' */
  real_T VEL_u_K_R_E_B_mDs;            /* '<S194>/Gain' */
  real_T VEL_v_K_R_E_B_mDs;            /* '<S194>/Gain1' */
  real_T VEL_w_K_R_E_B_mDs;            /* '<S194>/Gain2' */
  real_T POS_z_NED_m;                  /* '<S194>/Gain17' */
  real_T Fin_1_Pos_rad;                /* '<S14>/Gain' */
  real_T Fin_2_Pos_rad;                /* '<S14>/Gain1' */
  real_T Fin_3_Pos_rad;                /* '<S14>/Gain2' */
  real_T Fin_4_Pos_rad;                /* '<S14>/Gain3' */
  real_T A;                            /* '<S12>/Constant' */
  real_T B;                            /* '<S12>/Constant1' */
  real_T Z;                            /* '<S12>/Constant2' */
  real_T A_i;                          /* '<S12>/Constant3' */
  real_T B_d;                          /* '<S12>/Constant4' */
  real_T Z_d;                          /* '<S12>/Constant5' */
  real_T A_m;                          /* '<S12>/Constant6' */
  real_T B_c;                          /* '<S12>/Constant7' */
  real_T Z_h;                          /* '<S12>/Constant8' */
  real_T A_f;                          /* '<S12>/Constant9' */
  real_T B_n;                          /* '<S12>/Constant10' */
  real_T Z_l;                          /* '<S12>/Constant11' */
  real_T Gimbal_operational_flg;       /* '<S37>/Data Type Conversion1' */
  real_T Gimbal_Ramp_flg;              /* '<S37>/Data Type Conversion' */
  real_T Gimbal_Limit_flg;             /* '<S37>/Constant1' */
  real_T Gimbal_StopSim_flg;           /* '<S37>/Constant2' */
  real_T yaw_deg;                      /* '<S44>/Shaft2degYaw' */
  real_T Gain;                         /* '<S175>/Gain' */
  real_T pitch_deg;                    /* '<S44>/Shaft2degPitch' */
  real_T Gain_a;                       /* '<S173>/Gain' */
  real_T roll_deg;                     /* '<S44>/Shaft2degRoll' */
  real_T Gain_d;                       /* '<S174>/Gain' */
  real_T Merge;                        /* '<S71>/Merge' */
  real_T Switch2;                      /* '<S71>/Switch2' */
  real_T Gain_c;                       /* '<S71>/Gain' */
  real_T Merge1;                       /* '<S71>/Merge1' */
  real_T Switch1;                      /* '<S71>/Switch1' */
  real_T ATT_Phi_rad;                  /* '<S194>/Gain9' */
  real_T Product;                      /* '<S47>/Product' */
  real_T Yaw_err;                      /* '<S47>/Sum' */
  real_T Integrator;                   /* '<S72>/Integrator' */
  real_T Filter;                       /* '<S72>/Filter' */
  real_T FilterCoefficient;            /* '<S72>/Filter Coefficient' */
  real_T Merge_l;                      /* '<S72>/Merge' */
  real_T Merge_f;                      /* '<S70>/Merge' */
  real_T Merge_lo;                     /* '<S52>/Merge' */
  real_T Switch2_m;                    /* '<S52>/Switch2' */
  real_T Gain_cg;                      /* '<S52>/Gain' */
  real_T Merge1_f;                     /* '<S52>/Merge1' */
  real_T Switch1_p;                    /* '<S52>/Switch1' */
  real_T ATT_Theta_rad;                /* '<S194>/Gain10' */
  real_T pitch_cmd;                    /* '<S45>/Product' */
  real_T pitch_err;                    /* '<S45>/Sum2' */
  real_T Integrator_e;                 /* '<S53>/Integrator' */
  real_T Filter_e;                     /* '<S53>/Filter' */
  real_T FilterCoefficient_a;          /* '<S53>/Filter Coefficient' */
  real_T Merge_p;                      /* '<S53>/Merge' */
  real_T Merge_g;                      /* '<S61>/Merge' */
  real_T Switch2_k;                    /* '<S61>/Switch2' */
  real_T Gain_m;                       /* '<S61>/Gain' */
  real_T Merge1_fu;                    /* '<S61>/Merge1' */
  real_T Switch1_j;                    /* '<S61>/Switch1' */
  real_T ATT_Psi_rad;                  /* '<S194>/Gain11' */
  real_T Product1;                     /* '<S46>/Product1' */
  real_T Roll_err;                     /* '<S46>/Sum1' */
  real_T Integrator_f;                 /* '<S62>/Integrator' */
  real_T Filter_f;                     /* '<S62>/Filter' */
  real_T FilterCoefficient_l;          /* '<S62>/Filter Coefficient' */
  real_T Merge_a;                      /* '<S62>/Merge' */
  real_T Merge_b;                      /* '<S44>/Merge' */
  real_T Merge1_f0;                    /* '<S44>/Merge1' */
  real_T Sum2;                         /* '<S38>/Sum2' */
  real_T ATT_Phi_rad_p;                /* '<S39>/Shaft2radRoll' */
  real_T Merge2;                       /* '<S44>/Merge2' */
  real_T Sum1;                         /* '<S38>/Sum1' */
  real_T ATT_Theta_rad_c;              /* '<S39>/Shaft2radPitch' */
  real_T Sum;                          /* '<S38>/Sum' */
  real_T ATT_Psi_rad_h;                /* '<S39>/Shaft2radYaw' */
  real_T q0;                           /* '<S42>/q0' */
  real_T q1;                           /* '<S42>/q1' */
  real_T q2;                           /* '<S42>/q2' */
  real_T q3;                           /* '<S42>/q3' */
  real_T Data_plus;                    /* '<S40>/Constant' */
  real_T Data_minus;                   /* '<S40>/Constant1' */
  real_T Clock_plus;                   /* '<S40>/Constant2' */
  real_T Clock_minus;                  /* '<S40>/Constant3' */
  real_T Data_plus_n;                  /* '<S40>/Constant4' */
  real_T Data_minus_l;                 /* '<S40>/Constant5' */
  real_T Clock_plus_b;                 /* '<S40>/Constant6' */
  real_T Clock_minus_b;                /* '<S40>/Constant7' */
  real_T Data_plus_nf;                 /* '<S40>/Constant8' */
  real_T Data_minus_g;                 /* '<S40>/Constant9' */
  real_T Clock_plus_g;                 /* '<S40>/Constant10' */
  real_T Clock_minus_d;                /* '<S40>/Constant11' */
  real_T Constant8[4];                 /* '<S302>/Constant8' */
  real_T wIEE[3];                      /* '<S301>/Switch' */
  real_T Constant8_h[4];               /* '<S303>/Constant8' */
  real_T vec2[3];                      /* '<S354>/Product' */
  real_T Tmp_ref;                      /* '<S267>/Subtract1' */
  real_T Product_m;                    /* '<S332>/Product' */
  real_T Divide;                       /* '<S332>/Divide' */
  real_T Subtract1;                    /* '<S332>/Subtract1' */
  real_T Subtract;                     /* '<S331>/Subtract' */
  real_T Switch[3];                    /* '<S328>/Switch' */
  real_T sat;                          /* '<S270>/Integrator1' */
  real_T Gain3;                        /* '<S270>/Gain3' */
  real_T sat_c;                        /* '<S271>/Integrator1' */
  real_T Gain3_m;                      /* '<S271>/Gain3' */
  real_T sat_a;                        /* '<S272>/Integrator1' */
  real_T Gain3_b;                      /* '<S272>/Gain3' */
  real_T sat_o;                        /* '<S273>/Integrator1' */
  real_T Gain3_h;                      /* '<S273>/Gain3' */
  real_T Sqrt;                         /* '<S241>/Sqrt' */
  real_T pa_ref;                       /* '<S267>/Subtract2' */
  real_T hBE_0;                        /* '<S226>/Switch1' */
  real_T VectorConcatenate[3];         /* '<S224>/Vector Concatenate' */
  real_T e2;                           /* '<S262>/Divide' */
  real_T Add1;                         /* '<S260>/Add1' */
  real_T hBE_0_l;                      /* '<S284>/Switch1' */
  real_T VectorConcatenate_f[3];       /* '<S283>/Vector Concatenate' */
  real_T T12[9];                       /* '<S315>/3. Rotation' */
  real_T VectorConcatenate_b[4];       /* '<S340>/Vector Concatenate' */
  real_T ACC_x_B_mDs2;                 /* '<S194>/Gain3' */
  real_T ACC_y_B_mDs2;                 /* '<S194>/Gain4' */
  real_T ACC_z_B_mDs2;                 /* '<S194>/Gain5' */
  real_T w_x_K_IB_B_radDs;             /* '<S194>/Gain6' */
  real_T w_y_K_IB_B_radDs;             /* '<S194>/Gain7' */
  real_T w_z_K_IB_B_radDs;             /* '<S194>/Gain8' */
  real_T w_x_dot_radDs2;               /* '<S194>/Gain23' */
  real_T w_y_dot_radDs2;               /* '<S194>/Gain24' */
  real_T w_z_dot_radDs2;               /* '<S194>/Gain25' */
  real_T q0_a;                         /* '<S210>/q0' */
  real_T q1_j;                         /* '<S210>/q1' */
  real_T q2_f;                         /* '<S210>/q2' */
  real_T q3_j;                         /* '<S210>/q3' */
  real_T POS_lambda_WGS84_rad;         /* '<S194>/Gain12' */
  real_T POS_mue_WGS84_rad;            /* '<S194>/Gain13' */
  real_T POS_h_WGS84_m;                /* '<S194>/Gain14' */
  real_T POS_x_NED_m;                  /* '<S194>/Gain15' */
  real_T POS_y_NED_m;                  /* '<S194>/Gain16' */
  real_T motor_state_perc;             /* '<S194>/Gain18' */
  real_T mass_kg;                      /* '<S194>/Gain22' */
  real_T VEL_u_Wind_A_E_O_mDs;         /* '<S194>/Gain19' */
  real_T VEL_v_Wind_A_E_O_mDs;         /* '<S194>/Gain20' */
  real_T VEL_w_Wind_A_E_O_mDs;         /* '<S194>/Gain21' */
  real_T Saturation_o;                 /* '<S15>/Saturation' */
  real_T Saturation_c;                 /* '<S16>/Saturation' */
  real_T Saturation_j;                 /* '<S17>/Saturation' */
  real_T Saturation_a;                 /* '<S18>/Saturation' */
  real_T SumI1;                        /* '<S53>/SumI1' */
  real_T SumI1_n;                      /* '<S62>/SumI1' */
  real_T SumI1_p;                      /* '<S72>/SumI1' */
  real_T DataTypeConversion;           /* '<S48>/Data Type Conversion' */
  real_T Samp_freq;                    /* '<S44>/Samp_Freq' */
  real_T siB_cmd[4];                   /* '<S214>/Product' */
  real_T Product_a;                    /* '<S359>/Product' */
  real_T Product2;                     /* '<S359>/Product2' */
  real_T Product4;                     /* '<S359>/Product4' */
  real_T hBE_0_h;                      /* '<S230>/Switch1' */
  real_T VectorConcatenate_e[3];       /* '<S225>/Vector Concatenate' */
  real_T Add[16];                      /* '<S305>/Add' */
  real_T VectorConcatenate_m[4];       /* '<S308>/Vector Concatenate' */
  real_T wEGG[3];                      /* '<S304>/Vector Concatenate1' */
  real_T VectorConcatenate_a[4];       /* '<S309>/Vector Concatenate' */
  real_T VectorConcatenate_k[4];       /* '<S312>/Vector Concatenate' */
  real_T VectorConcatenate_p[4];       /* '<S338>/Vector Concatenate' */
  real_T T12_o[9];                     /* '<S370>/3. Rotation' */
  real_T Subtract_d[9];                /* '<S365>/Subtract' */
  real_T Subtract4;                    /* '<S365>/Subtract4' */
  real_T MathFunction[9];              /* '<S366>/Math Function' */
  real_T d_x[13];                      /* '<S334>/Vector Concatenate' */
  real_T VectorConcatenate2[3];        /* '<S10>/Vector Concatenate2' */
  real_T Gain_p[3];                    /* '<S392>/Gain' */
  real_T Sum2_b[3];                    /* '<S399>/Sum2' */
  real_T Sum2_i[3];                    /* '<S411>/Sum2' */
  real_T VectorConcatenate1[3];        /* '<S328>/Vector Concatenate1' */
  real_T U0;                           /* '<Root>/MATLAB Function' */
  real_T Abs1;                         /* '<S51>/Abs1' */
  real_T Abs3;                         /* '<S51>/Abs3' */
  real_T Abs5;                         /* '<S51>/Abs5' */
  real_T Abs;                          /* '<S167>/Abs' */
  real_T FilterCoefficient_d;          /* '<S109>/Filter Coefficient' */
  real_T FilterCoefficient_g;          /* '<S153>/Filter Coefficient' */
  real_T SumI4;                        /* '<S99>/SumI4' */
  real_T SumI4_g;                      /* '<S143>/SumI4' */
  real_T Abs_l;                        /* '<S65>/Abs' */
  real_T Abs_j;                        /* '<S56>/Abs' */
  real_T One;                          /* '<S30>/One' */
  real_T SineWave;                     /* '<S33>/Sine Wave' */
  real_T value;                        /* '<S28>/Counter_with_external_limit' */
  real_T stage;                        /* '<S24>/ExtractMessage' */
  real_T SineWave_g;                   /* '<S23>/Sine Wave' */
  real32_T MathFunction1;              /* '<Root>/Math Function1' */
  real32_T DataTypeConversion3;        /* '<S22>/Data Type Conversion3' */
  real32_T DataTypeConversion1;        /* '<S22>/Data Type Conversion1' */
  real32_T DataTypeConversion2;        /* '<S22>/Data Type Conversion2' */
  real32_T ServoCMD_update[4];         /* '<S27>/ServoCMD_update' */
  real32_T SensorACC_update[3];        /* '<S27>/SensorACC_update' */
  real32_T SensorROT_update[3];        /* '<S27>/SensorROT_update' */
  uint16_T DataTypeConversion1_p;      /* '<S383>/Data Type Conversion1' */
  uint16_T FixPtSwitch;                /* '<S386>/FixPt Switch' */
  uint16_T PixHeartbeat;               /* '<S24>/ByteUnpack' */
  uint8_T message[128];                /* '<S34>/message' */
  uint8_T MessageToSend[128];          /* '<S30>/MessageAssembly' */
  uint8_T PacketInput_o1[78];          /* '<S23>/Packet Input' */
  boolean_T Compare;                   /* '<S387>/Compare' */
  boolean_T LogicalOperator;           /* '<S71>/Logical Operator' */
  boolean_T HiddenBuf_InsertedFor_Enabledadapt_at_inport_3;/* '<S71>/Logical Operator' */
  boolean_T LogicalOperator1;          /* '<S71>/Logical Operator1' */
  boolean_T Switch_m;                  /* '<S71>/Switch' */
  boolean_T HiddenBuf_InsertedFor_Saturation_at_inport_3;
  boolean_T LogicalOperator_c;         /* '<S72>/Logical Operator' */
  boolean_T LogicalOperator_l;         /* '<S52>/Logical Operator' */
  boolean_T HiddenBuf_InsertedFor_Enabledadapt_at_inport_3_n;/* '<S52>/Logical Operator' */
  boolean_T LogicalOperator1_o;        /* '<S52>/Logical Operator1' */
  boolean_T Switch_i;                  /* '<S52>/Switch' */
  boolean_T HiddenBuf_InsertedFor_Saturation_at_inport_3_m;
  boolean_T LogicalOperator_k;         /* '<S53>/Logical Operator' */
  boolean_T LogicalOperator_e;         /* '<S61>/Logical Operator' */
  boolean_T HiddenBuf_InsertedFor_Enabledadapt_at_inport_3_nw;/* '<S61>/Logical Operator' */
  boolean_T LogicalOperator1_i;        /* '<S61>/Logical Operator1' */
  boolean_T Switch_c;                  /* '<S61>/Switch' */
  boolean_T HiddenBuf_InsertedFor_Saturation_at_inport_3_m2;
  boolean_T LogicalOperator_b;         /* '<S62>/Logical Operator' */
  boolean_T LogicalOperator_fl;        /* '<S44>/Logical Operator' */
  boolean_T OR;                        /* '<S28>/OR' */
  boolean_T cmd_pass_enable_flg;       /* '<S38>/Data Type Conversion' */
  boolean_T emergency_stop_flg;        /* '<S38>/Data Type Conversion1' */
  boolean_T Compare_k;                 /* '<S257>/Compare' */
  boolean_T AND;                       /* '<S258>/AND' */
  boolean_T AND_i;                     /* '<S259>/AND' */
  boolean_T NOT;                       /* '<S30>/NOT' */
  boolean_T AND_h;                     /* '<S23>/AND' */
  B_Limiting_Rate_GRM_HIL_T sf_Limiting_Rate_d;/* '<S273>/Limiting_Rate' */
  B_Limiting_Acceleration_GRM_HIL_T sf_Limiting_Acceleration_h;/* '<S273>/Limiting_Acceleration' */
  B_Limiting_Rate_GRM_HIL_T sf_Limiting_Rate_g;/* '<S272>/Limiting_Rate' */
  B_Limiting_Acceleration_GRM_HIL_T sf_Limiting_Acceleration_p;/* '<S272>/Limiting_Acceleration' */
  B_Limiting_Rate_GRM_HIL_T sf_Limiting_Rate_o;/* '<S271>/Limiting_Rate' */
  B_Limiting_Acceleration_GRM_HIL_T sf_Limiting_Acceleration_i;/* '<S271>/Limiting_Acceleration' */
  B_Limiting_Rate_GRM_HIL_T sf_Limiting_Rate;/* '<S270>/Limiting_Rate' */
  B_Limiting_Acceleration_GRM_HIL_T sf_Limiting_Acceleration;/* '<S270>/Limiting_Acceleration' */
  B_IfActionSubsystem_GRM_HIL_T IfActionSubsystem_k;/* '<S175>/If Action Subsystem' */
  B_IfActionSubsystem1_GRM_HIL_T IfActionSubsystem1_l;/* '<S175>/If Action Subsystem1' */
  B_IfActionSubsystem_GRM_HIL_T IfActionSubsystem_f;/* '<S174>/If Action Subsystem' */
  B_IfActionSubsystem1_GRM_HIL_T IfActionSubsystem1_n;/* '<S174>/If Action Subsystem1' */
  B_IfActionSubsystem_GRM_HIL_T IfActionSubsystem;/* '<S173>/If Action Subsystem' */
  B_IfActionSubsystem1_GRM_HIL_T IfActionSubsystem1;/* '<S173>/If Action Subsystem1' */
} B_GRM_HIL_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Memory1_1_PreviousInput;      /* '<S35>/Memory1' */
  real_T Memory1_2_PreviousInput;      /* '<S35>/Memory1' */
  real_T Memory1_3_PreviousInput;      /* '<S35>/Memory1' */
  real_T Memory_PreviousInput;         /* '<S28>/Memory' */
  real_T TimeStampA;                   /* '<S304>/Derivative1' */
  real_T LastUAtTimeA;                 /* '<S304>/Derivative1' */
  real_T TimeStampB;                   /* '<S304>/Derivative1' */
  real_T LastUAtTimeB;                 /* '<S304>/Derivative1' */
  real_T TimeStampA_b;                 /* '<S304>/Derivative' */
  real_T LastUAtTimeA_b;               /* '<S304>/Derivative' */
  real_T TimeStampB_j;                 /* '<S304>/Derivative' */
  real_T LastUAtTimeB_p;               /* '<S304>/Derivative' */
  real_T lastSin;                      /* '<S33>/Sine Wave' */
  real_T lastCos;                      /* '<S33>/Sine Wave' */
  real_T lastSin_h;                    /* '<S23>/Sine Wave' */
  real_T lastCos_c;                    /* '<S23>/Sine Wave' */
  struct {
    real_T modelTStart;
    real_T TUbufferArea[2048];
  } TransportDelay_RWORK;              /* '<S175>/Transport Delay' */

  struct {
    real_T modelTStart;
    real_T TUbufferArea[2048];
  } TransportDelay_RWORK_j;            /* '<S173>/Transport Delay' */

  struct {
    real_T modelTStart;
    real_T TUbufferArea[2048];
  } TransportDelay_RWORK_i;            /* '<S174>/Transport Delay' */

  struct {
    void *LoggedData[2];
  } Accel_PWORK;                       /* '<Root>/Accel' */

  struct {
    void *LoggedData[2];
  } Gyro_PWORK;                        /* '<Root>/Gyro' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *AQHandles[16];
    void *SlioLTF;
  } TAQSigLogging_InsertedFor_Actuators_at_outport_0_1_PWORK;/* synthesized block */

  struct {
    void *TUbufferPtrs[2];
  } TransportDelay_PWORK;              /* '<S175>/Transport Delay' */

  struct {
    void *TUbufferPtrs[2];
  } TransportDelay_PWORK_i;            /* '<S173>/Transport Delay' */

  struct {
    void *TUbufferPtrs[2];
  } TransportDelay_PWORK_is;           /* '<S174>/Transport Delay' */

  struct {
    void *AQHandles[26];
    void *SlioLTF;
  } TAQSigLogging_InsertedFor_Gimbal_at_outport_0_1_PWORK;/* synthesized block */

  struct {
    void *AQHandles[30];
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
  } TAQSigLogging_InsertedFor_Receive_ExternalMode_at_outport_0_PWORK;/* synthesized block */

  struct {
    void *LoggedData;
  } Roll_PWORK;                        /* '<S44>/Roll' */

  struct {
    void *LoggedData;
  } pitch_PWORK;                       /* '<S44>/pitch' */

  struct {
    void *LoggedData;
  } scopeyawpitchroll_PWORK;           /* '<S44>/scope yaw,pitch,roll' */

  struct {
    void *LoggedData;
  } yaw_PWORK;                         /* '<S44>/yaw' */

  struct {
    void *LoggedData;
  } Velocity_pitch_PWORK;              /* '<S173>/Velocity_pitch' */

  struct {
    void *LoggedData;
  } Velocity_roll_PWORK;               /* '<S174>/Velocity_roll' */

  struct {
    void *LoggedData;
  } velocity_yaw_PWORK;                /* '<S175>/velocity_yaw' */

  void* Assertion_slioAccessor;        /* '<S254>/Assertion' */
  void* Assertion1_slioAccessor;       /* '<S254>/Assertion1' */
  void* Assertion2_slioAccessor;       /* '<S254>/Assertion2' */
  struct {
    void *AQHandles;
    void *SlioLTF;
  } TAQSigLogging_InsertedFor_VectorConcatenate2_at_outport_0_PWORK;/* synthesized block */

  void *RealTimeSynchronization_PWORK; /* '<S382>/Real-Time Synchronization' */
  struct {
    void *AQHandles;
    void *SlioLTF;
  } TAQSigLogging_InsertedFor_One_at_outport_0_PWORK;/* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } TAQSigLogging_InsertedFor_Selector1_at_outport_0_PWORK;/* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } TAQSigLogging_InsertedFor_Selector_at_outport_0_PWORK;/* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } TAQSigLogging_InsertedFor_SimHeartbeat_at_outport_0_PWORK;/* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } TAQSigLogging_InsertedFor_Selector1_at_outport_0_PWORK_o;/* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } TAQSigLogging_InsertedFor_message_to_send_at_outport_0_PWORK;/* synthesized block */

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<S33>/To Workspace' */

  void *PacketOutput_PWORK[2];         /* '<S33>/Packet Output' */
  struct {
    void *LoggedData;
  } Scope_PWORK_k;                     /* '<S33>/Scope' */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } TAQSigLogging_InsertedFor_ByteUnpack_at_outport_0_PWORK;/* synthesized block */

  struct {
    void *AQHandles;
    void *SlioLTF;
  } TAQSigLogging_InsertedFor_ExtractMessage_at_outport_2_PWORK;/* synthesized block */

  void *PacketInput_PWORK;             /* '<S23>/Packet Input' */
  struct {
    void *AQHandles;
    void *SlioLTF;
  } TAQSigLogging_InsertedFor_PacketInput_at_outport_0_PWORK;/* synthesized block */

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK_d;               /* '<S23>/To Workspace' */

  struct {
    void *LoggedData;
  } Scope_PWORK_m;                     /* '<S23>/Scope' */

  int32_T clockTickCounter;            /* '<S19>/Pulse Generator1' */
  int32_T clockTickCounter_d;          /* '<S19>/Pulse Generator' */
  int32_T clockTickCounter_d3;         /* '<S19>/Pulse Generator4' */
  int32_T clockTickCounter_e;          /* '<S19>/Pulse Generator3' */
  int32_T clockTickCounter_o;          /* '<S19>/Pulse Generator7' */
  int32_T clockTickCounter_l;          /* '<S19>/Pulse Generator6' */
  int32_T systemEnable;                /* '<S33>/Sine Wave' */
  int32_T SFunction_DIMS2[2];          /* '<S24>/ExtractMessage' */
  int32_T systemEnable_c;              /* '<S23>/Sine Wave' */
  int_T integration_eom_IWORK;         /* '<S334>/integration_eom' */
  struct {
    int_T Tail;
    int_T Head;
    int_T Last;
    int_T CircularBufSize;
  } TransportDelay_IWORK;              /* '<S175>/Transport Delay' */

  struct {
    int_T Tail;
    int_T Head;
    int_T Last;
    int_T CircularBufSize;
  } TransportDelay_IWORK_p;            /* '<S173>/Transport Delay' */

  struct {
    int_T Tail;
    int_T Head;
    int_T Last;
    int_T CircularBufSize;
  } TransportDelay_IWORK_f;            /* '<S174>/Transport Delay' */

  int_T integration_eom_IWORK_g;       /* '<S302>/integration_eom' */
  int_T integration_eom_IWORK_l;       /* '<S303>/integration_eom' */
  int_T IntegratorSecondOrderLimited_MODE[3];
                                 /* '<S399>/Integrator, Second-Order Limited' */
  int_T IntegratorSecondOrderLimited_MODE_i[3];
                                 /* '<S411>/Integrator, Second-Order Limited' */
  uint16_T Output_DSTATE;              /* '<S384>/Output' */
  int8_T If_ActiveSubsystem;           /* '<S175>/If' */
  int8_T If_ActiveSubsystem_l;         /* '<S173>/If' */
  int8_T If_ActiveSubsystem_g;         /* '<S174>/If' */
  int8_T Synchronize_to_realtime_SubsysRanBC;/* '<S8>/Synchronize_to_realtime' */
  int8_T Voltage_Limitations_SubsysRanBC;/* '<S44>/Voltage_Limitations' */
  int8_T If_ActiveSubsystem_d;         /* '<S51>/If' */
  int8_T If1_ActiveSubsystem;          /* '<S51>/If1' */
  int8_T If2_ActiveSubsystem;          /* '<S51>/If2' */
  int8_T IfActionlimit_roll_SubsysRanBC;/* '<S51>/If Action limit_roll' */
  int8_T IfActionlimit_pitch_SubsysRanBC;/* '<S51>/If Action limit_pitch' */
  int8_T IfActionlimit_yaw_SubsysRanBC;/* '<S51>/If Action limit_yaw' */
  int8_T IfActionPass_SubsysRanBC;     /* '<S44>/If Action Pass' */
  int8_T Enabledadapt_SubsysRanBC;     /* '<S71>/Enabled adapt' */
  int8_T pass_SubsysRanBC;             /* '<S70>/pass' */
  int8_T Control_Limits_SubsysRanBC;   /* '<S70>/Control_Limits' */
  int8_T Enabledadapt_SubsysRanBC_d;   /* '<S61>/Enabled adapt' */
  int8_T Enabledadapt_SubsysRanBC_e;   /* '<S52>/Enabled adapt' */
  int8_T send_to_pix_SubsysRanBC;      /* '<S22>/send_to_pix' */
  int8_T no_CRC_SubsysRanBC;           /* '<S30>/no_CRC' */
  int8_T Send_ExternalMode_SubsysRanBC;/* '<S30>/Send_ExternalMode' */
  int8_T input_hold_SubsysRanBC;       /* '<S21>/input_hold' */
  int8_T hold_SubsysRanBC;             /* '<S24>/hold' */
  int8_T Receive_ExternalMode_SubsysRanBC;/* '<S21>/Receive_ExternalMode' */
  boolean_T Memory_1_PreviousInput;    /* '<S35>/Memory' */
  boolean_T Memory_2_PreviousInput;    /* '<S35>/Memory' */
  boolean_T IntegratorSecondOrderLimited_DWORK1;
                                 /* '<S399>/Integrator, Second-Order Limited' */
  boolean_T IntegratorSecondOrderLimited_DWORK1_a;
                                 /* '<S411>/Integrator, Second-Order Limited' */
  boolean_T Voltage_Limitations_MODE;  /* '<S44>/Voltage_Limitations' */
  boolean_T IfActionPass_MODE;         /* '<S44>/If Action Pass' */
  boolean_T Enabledadapt_MODE;         /* '<S71>/Enabled adapt' */
  boolean_T Control_Limits_MODE;       /* '<S70>/Control_Limits' */
  boolean_T Enabledadapt_MODE_g;       /* '<S61>/Enabled adapt' */
  boolean_T Enabledadapt_MODE_l;       /* '<S52>/Enabled adapt' */
  boolean_T send_to_pix_MODE;          /* '<S22>/send_to_pix' */
  boolean_T no_CRC_MODE;               /* '<S30>/no_CRC' */
  boolean_T Send_ExternalMode_MODE;    /* '<S30>/Send_ExternalMode' */
  boolean_T Receive_ExternalMode_MODE; /* '<S21>/Receive_ExternalMode' */
  DW_IfActionpass_yaw_GRM_HIL_T IfActionpass_roll;/* '<S51>/If Action pass_roll' */
  DW_IfActionpass_yaw_GRM_HIL_T IfActionpass_pitch;/* '<S51>/If Action pass_pitch' */
  DW_IfActionpass_yaw_GRM_HIL_T IfActionpass_yaw;/* '<S51>/If Action pass_yaw' */
  DW_IfActionSubsystem_GRM_HIL_T IfActionSubsystem_k;/* '<S175>/If Action Subsystem' */
  DW_IfActionSubsystem1_GRM_HIL_T IfActionSubsystem1_l;/* '<S175>/If Action Subsystem1' */
  DW_IfActionSubsystem_GRM_HIL_T IfActionSubsystem_f;/* '<S174>/If Action Subsystem' */
  DW_IfActionSubsystem1_GRM_HIL_T IfActionSubsystem1_n;/* '<S174>/If Action Subsystem1' */
  DW_IfActionSubsystem_GRM_HIL_T IfActionSubsystem;/* '<S173>/If Action Subsystem' */
  DW_IfActionSubsystem1_GRM_HIL_T IfActionSubsystem1;/* '<S173>/If Action Subsystem1' */
  DW_pass_GRM_HIL_T pass_k;            /* '<S72>/pass' */
  DW_Saturation_GRM_HIL_T Saturation_h4;/* '<S72>/Saturation' */
  DW_Enabledpass_GRM_HIL_T Enabledpass_e;/* '<S71>/Enabled pass' */
  DW_pass_GRM_HIL_T pass_c;            /* '<S62>/pass' */
  DW_Saturation_GRM_HIL_T Saturation_h;/* '<S62>/Saturation' */
  DW_Enabledpass_GRM_HIL_T Enabledpass_l;/* '<S61>/Enabled pass' */
  DW_pass_GRM_HIL_T pass;              /* '<S53>/pass' */
  DW_Saturation_GRM_HIL_T Saturation;  /* '<S53>/Saturation' */
  DW_Enabledpass_GRM_HIL_T Enabledpass;/* '<S52>/Enabled pass' */
} DW_GRM_HIL_T;

/* Continuous states (default storage) */
typedef struct {
  real_T integration_eom_CSTATE[13];   /* '<S334>/integration_eom' */
  real_T TransferFcn_CSTATE[2];        /* '<S13>/Transfer Fcn' */
  real_T TransferFcn1_CSTATE[2];       /* '<S13>/Transfer Fcn1' */
  real_T TransferFcn2_CSTATE[2];       /* '<S13>/Transfer Fcn2' */
  real_T TransferFcn3_CSTATE[2];       /* '<S13>/Transfer Fcn3' */
  real_T TransferFcn1_CSTATE_k[2];     /* '<S48>/Transfer Fcn1' */
  real_T Integrator_CSTATE;            /* '<S72>/Integrator' */
  real_T Filter_CSTATE;                /* '<S72>/Filter' */
  real_T Integrator_CSTATE_e;          /* '<S53>/Integrator' */
  real_T Filter_CSTATE_h;              /* '<S53>/Filter' */
  real_T Integrator_CSTATE_g;          /* '<S62>/Integrator' */
  real_T Filter_CSTATE_e;              /* '<S62>/Filter' */
  real_T Phi2MotorRoll_CSTATE[3];      /* '<S38>/Phi2Motor -> Roll' */
  real_T Theta2MotorPitch_CSTATE[5];   /* '<S38>/Theta2Motor -> Pitch' */
  real_T Psi2MotorYaw_CSTATE[2];       /* '<S38>/Psi2Motor -> Yaw' */
  real_T integration_eom_CSTATE_b[4];  /* '<S302>/integration_eom' */
  real_T integration_eom_CSTATE_f[4];  /* '<S303>/integration_eom' */
  real_T Integrator1_CSTATE;           /* '<S270>/Integrator1' */
  real_T Integrator1_CSTATE_g;         /* '<S271>/Integrator1' */
  real_T Integrator1_CSTATE_a;         /* '<S272>/Integrator1' */
  real_T Integrator1_CSTATE_i;         /* '<S273>/Integrator1' */
  real_T Integrator_CSTATE_h;          /* '<S270>/Integrator' */
  real_T Integrator_CSTATE_ep;         /* '<S271>/Integrator' */
  real_T Integrator_CSTATE_f;          /* '<S272>/Integrator' */
  real_T Integrator_CSTATE_gp;         /* '<S273>/Integrator' */
  real_T IntegratorSecondOrderLimited_CSTATE[6];
                                 /* '<S399>/Integrator, Second-Order Limited' */
  real_T IntegratorSecondOrderLimited_CSTATE_a[6];
                                 /* '<S411>/Integrator, Second-Order Limited' */
  real_T Integrator_CSTATE_l;          /* '<S106>/Integrator' */
  real_T Filter_CSTATE_l;              /* '<S101>/Filter' */
  real_T Integrator_CSTATE_i;          /* '<S150>/Integrator' */
  real_T Filter_CSTATE_b;              /* '<S145>/Filter' */
} X_GRM_HIL_T;

/* State derivatives (default storage) */
typedef struct {
  real_T integration_eom_CSTATE[13];   /* '<S334>/integration_eom' */
  real_T TransferFcn_CSTATE[2];        /* '<S13>/Transfer Fcn' */
  real_T TransferFcn1_CSTATE[2];       /* '<S13>/Transfer Fcn1' */
  real_T TransferFcn2_CSTATE[2];       /* '<S13>/Transfer Fcn2' */
  real_T TransferFcn3_CSTATE[2];       /* '<S13>/Transfer Fcn3' */
  real_T TransferFcn1_CSTATE_k[2];     /* '<S48>/Transfer Fcn1' */
  real_T Integrator_CSTATE;            /* '<S72>/Integrator' */
  real_T Filter_CSTATE;                /* '<S72>/Filter' */
  real_T Integrator_CSTATE_e;          /* '<S53>/Integrator' */
  real_T Filter_CSTATE_h;              /* '<S53>/Filter' */
  real_T Integrator_CSTATE_g;          /* '<S62>/Integrator' */
  real_T Filter_CSTATE_e;              /* '<S62>/Filter' */
  real_T Phi2MotorRoll_CSTATE[3];      /* '<S38>/Phi2Motor -> Roll' */
  real_T Theta2MotorPitch_CSTATE[5];   /* '<S38>/Theta2Motor -> Pitch' */
  real_T Psi2MotorYaw_CSTATE[2];       /* '<S38>/Psi2Motor -> Yaw' */
  real_T integration_eom_CSTATE_b[4];  /* '<S302>/integration_eom' */
  real_T integration_eom_CSTATE_f[4];  /* '<S303>/integration_eom' */
  real_T Integrator1_CSTATE;           /* '<S270>/Integrator1' */
  real_T Integrator1_CSTATE_g;         /* '<S271>/Integrator1' */
  real_T Integrator1_CSTATE_a;         /* '<S272>/Integrator1' */
  real_T Integrator1_CSTATE_i;         /* '<S273>/Integrator1' */
  real_T Integrator_CSTATE_h;          /* '<S270>/Integrator' */
  real_T Integrator_CSTATE_ep;         /* '<S271>/Integrator' */
  real_T Integrator_CSTATE_f;          /* '<S272>/Integrator' */
  real_T Integrator_CSTATE_gp;         /* '<S273>/Integrator' */
  real_T IntegratorSecondOrderLimited_CSTATE[6];
                                 /* '<S399>/Integrator, Second-Order Limited' */
  real_T IntegratorSecondOrderLimited_CSTATE_a[6];
                                 /* '<S411>/Integrator, Second-Order Limited' */
  real_T Integrator_CSTATE_l;          /* '<S106>/Integrator' */
  real_T Filter_CSTATE_l;              /* '<S101>/Filter' */
  real_T Integrator_CSTATE_i;          /* '<S150>/Integrator' */
  real_T Filter_CSTATE_b;              /* '<S145>/Filter' */
} XDot_GRM_HIL_T;

/* State disabled  */
typedef struct {
  boolean_T integration_eom_CSTATE[13];/* '<S334>/integration_eom' */
  boolean_T TransferFcn_CSTATE[2];     /* '<S13>/Transfer Fcn' */
  boolean_T TransferFcn1_CSTATE[2];    /* '<S13>/Transfer Fcn1' */
  boolean_T TransferFcn2_CSTATE[2];    /* '<S13>/Transfer Fcn2' */
  boolean_T TransferFcn3_CSTATE[2];    /* '<S13>/Transfer Fcn3' */
  boolean_T TransferFcn1_CSTATE_k[2];  /* '<S48>/Transfer Fcn1' */
  boolean_T Integrator_CSTATE;         /* '<S72>/Integrator' */
  boolean_T Filter_CSTATE;             /* '<S72>/Filter' */
  boolean_T Integrator_CSTATE_e;       /* '<S53>/Integrator' */
  boolean_T Filter_CSTATE_h;           /* '<S53>/Filter' */
  boolean_T Integrator_CSTATE_g;       /* '<S62>/Integrator' */
  boolean_T Filter_CSTATE_e;           /* '<S62>/Filter' */
  boolean_T Phi2MotorRoll_CSTATE[3];   /* '<S38>/Phi2Motor -> Roll' */
  boolean_T Theta2MotorPitch_CSTATE[5];/* '<S38>/Theta2Motor -> Pitch' */
  boolean_T Psi2MotorYaw_CSTATE[2];    /* '<S38>/Psi2Motor -> Yaw' */
  boolean_T integration_eom_CSTATE_b[4];/* '<S302>/integration_eom' */
  boolean_T integration_eom_CSTATE_f[4];/* '<S303>/integration_eom' */
  boolean_T Integrator1_CSTATE;        /* '<S270>/Integrator1' */
  boolean_T Integrator1_CSTATE_g;      /* '<S271>/Integrator1' */
  boolean_T Integrator1_CSTATE_a;      /* '<S272>/Integrator1' */
  boolean_T Integrator1_CSTATE_i;      /* '<S273>/Integrator1' */
  boolean_T Integrator_CSTATE_h;       /* '<S270>/Integrator' */
  boolean_T Integrator_CSTATE_ep;      /* '<S271>/Integrator' */
  boolean_T Integrator_CSTATE_f;       /* '<S272>/Integrator' */
  boolean_T Integrator_CSTATE_gp;      /* '<S273>/Integrator' */
  boolean_T IntegratorSecondOrderLimited_CSTATE[6];
                                 /* '<S399>/Integrator, Second-Order Limited' */
  boolean_T IntegratorSecondOrderLimited_CSTATE_a[6];
                                 /* '<S411>/Integrator, Second-Order Limited' */
  boolean_T Integrator_CSTATE_l;       /* '<S106>/Integrator' */
  boolean_T Filter_CSTATE_l;           /* '<S101>/Filter' */
  boolean_T Integrator_CSTATE_i;       /* '<S150>/Integrator' */
  boolean_T Filter_CSTATE_b;           /* '<S145>/Filter' */
} XDis_GRM_HIL_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Integrator_Reset_ZCE;     /* '<S270>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_h;   /* '<S271>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_k;   /* '<S272>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_n;   /* '<S273>/Integrator' */
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

/* Parameters for system: '<S173>/If Action Subsystem1' */
struct P_IfActionSubsystem1_GRM_HIL_T_ {
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S177>/Out1'
                                        */
};

/* Parameters for system: '<S173>/If Action Subsystem' */
struct P_IfActionSubsystem_GRM_HIL_T_ {
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S176>/Out1'
                                        */
};

/* Parameters (default storage) */
struct P_GRM_HIL_T_ {
  real_T HIL_Sample_Time;              /* Variable: HIL_Sample_Time
                                        * Referenced by: '<S28>/Constant'
                                        */
  struct_t5lid3aqguggysQaotuOhC Gimbel_Ctrl_Gimbal_Ctrl;
                                      /* Mask Parameter: Gimbel_Ctrl_Gimbal_Ctrl
                                       * Referenced by:
                                       *   '<S44>/Constant2'
                                       *   '<S44>/Samp_Freq'
                                       *   '<S51>/max_vel_pitch'
                                       *   '<S51>/max_vel_roll'
                                       *   '<S51>/max_vel_yaw'
                                       *   '<S52>/Constant'
                                       *   '<S52>/const_lower_limit'
                                       *   '<S52>/const_upper_limit'
                                       *   '<S53>/Derivative Gain'
                                       *   '<S53>/Filter Coefficient'
                                       *   '<S53>/Integral Gain'
                                       *   '<S53>/Kb'
                                       *   '<S53>/Proportional Gain'
                                       *   '<S61>/Constant'
                                       *   '<S61>/const_lower_limit'
                                       *   '<S61>/const_upper_limit'
                                       *   '<S62>/Derivative Gain'
                                       *   '<S62>/Filter Coefficient'
                                       *   '<S62>/Integral Gain'
                                       *   '<S62>/Kb'
                                       *   '<S62>/Proportional Gain'
                                       *   '<S70>/Constant'
                                       *   '<S71>/Constant'
                                       *   '<S71>/const_lower_limit'
                                       *   '<S71>/const_upper_limit'
                                       *   '<S72>/Derivative Gain'
                                       *   '<S72>/Filter Coefficient'
                                       *   '<S72>/Integral Gain'
                                       *   '<S72>/Kb'
                                       *   '<S72>/Proportional Gain'
                                       *   '<S173>/Constant1'
                                       *   '<S173>/Gain'
                                       *   '<S173>/Transport Delay'
                                       *   '<S174>/Constant1'
                                       *   '<S174>/Gain'
                                       *   '<S174>/Transport Delay'
                                       *   '<S175>/Constant1'
                                       *   '<S175>/Gain'
                                       *   '<S175>/Transport Delay'
                                       *   '<S182>/Limit_Voltage_Pitch'
                                       *   '<S183>/Limit_Voltage_Roll'
                                       *   '<S184>/Limit_Voltage_Yaw'
                                       *   '<S54>/Constant'
                                       *   '<S55>/Constant'
                                       *   '<S56>/Constant'
                                       *   '<S56>/Constant1'
                                       *   '<S56>/Gain'
                                       *   '<S63>/Constant'
                                       *   '<S64>/Constant'
                                       *   '<S65>/Constant'
                                       *   '<S65>/Constant1'
                                       *   '<S65>/Gain'
                                       *   '<S73>/Constant1'
                                       *   '<S73>/Constant2'
                                       *   '<S73>/Gain'
                                       *   '<S73>/Gain1'
                                       *   '<S165>/Constant'
                                       *   '<S166>/Constant'
                                       *   '<S167>/Constant'
                                       *   '<S167>/Constant1'
                                       *   '<S167>/Gain'
                                       *   '<S100>/Derivative Gain'
                                       *   '<S103>/Integral Gain'
                                       *   '<S111>/Proportional Gain'
                                       *   '<S144>/Derivative Gain'
                                       *   '<S147>/Integral Gain'
                                       *   '<S155>/Proportional Gain'
                                       */
  struct_X0z48mq1MJmnXMBjrHYvYC Gimbal_TransferFunctions_TF;
                                  /* Mask Parameter: Gimbal_TransferFunctions_TF
                                   * Referenced by:
                                   *   '<S38>/Phi2Motor -> Pitch'
                                   *   '<S38>/Phi2Motor -> Roll'
                                   *   '<S38>/Phi2Motor -> Yaw'
                                   *   '<S38>/Psi2Motor -> Pitch'
                                   *   '<S38>/Psi2Motor -> Roll'
                                   *   '<S38>/Psi2Motor -> Yaw'
                                   *   '<S38>/Theta2Motor -> Pitch'
                                   *   '<S38>/Theta2Motor -> Roll'
                                   *   '<S38>/Theta2Motor -> Yaw'
                                   */
  struct_Y7PS1rxhiw1TKkxrPVqWqG External_Inputs_External_Inputs;
                              /* Mask Parameter: External_Inputs_External_Inputs
                               * Referenced by:
                               *   '<S19>/Constant'
                               *   '<S19>/Constant1'
                               *   '<S19>/Constant2'
                               *   '<S19>/Constant3'
                               *   '<S19>/Constant4'
                               *   '<S19>/Constant5'
                               *   '<S19>/Pulse Generator'
                               *   '<S19>/Pulse Generator3'
                               *   '<S19>/Pulse Generator6'
                               */
  struct_fqhbejXln8QRylaPqhUyTF Servo_TF;/* Mask Parameter: Servo_TF
                                          * Referenced by:
                                          *   '<S13>/Transfer Fcn'
                                          *   '<S13>/Transfer Fcn1'
                                          *   '<S13>/Transfer Fcn2'
                                          *   '<S13>/Transfer Fcn3'
                                          */
  struct_7SrGNOW0Gr039ZOMvXVVTD Servo_PWM;/* Mask Parameter: Servo_PWM
                                           * Referenced by:
                                           *   '<S15>/Constant'
                                           *   '<S15>/Constant1'
                                           *   '<S15>/Constant2'
                                           *   '<S15>/Saturation'
                                           *   '<S16>/Constant'
                                           *   '<S16>/Constant1'
                                           *   '<S16>/Constant2'
                                           *   '<S16>/Saturation'
                                           *   '<S17>/Constant'
                                           *   '<S17>/Constant1'
                                           *   '<S17>/Constant2'
                                           *   '<S17>/Saturation'
                                           *   '<S18>/Constant'
                                           *   '<S18>/Constant1'
                                           *   '<S18>/Constant2'
                                           *   '<S18>/Saturation'
                                           */
  struct_o6lBeR5a4wCQZKjH0CEd8D Serial_Recieve_from_Pixhawk_Serial;
                           /* Mask Parameter: Serial_Recieve_from_Pixhawk_Serial
                            * Referenced by: '<S23>/Packet Input'
                            */
  struct_o6lBeR5a4wCQZKjH0CEd8D Serial_Send_to_Pixhawk_Serial;
                                /* Mask Parameter: Serial_Send_to_Pixhawk_Serial
                                 * Referenced by: '<S33>/Packet Output'
                                 */
  real_T PIDController_InitialConditionForFilter;
                      /* Mask Parameter: PIDController_InitialConditionForFilter
                       * Referenced by: '<S101>/Filter'
                       */
  real_T PIDController1_InitialConditionForFilter;
                     /* Mask Parameter: PIDController1_InitialConditionForFilter
                      * Referenced by: '<S145>/Filter'
                      */
  real_T PIDController_InitialConditionForIntegrator;
                  /* Mask Parameter: PIDController_InitialConditionForIntegrator
                   * Referenced by: '<S106>/Integrator'
                   */
  real_T PIDController1_InitialConditionForIntegrator;
                 /* Mask Parameter: PIDController1_InitialConditionForIntegrator
                  * Referenced by: '<S150>/Integrator'
                  */
  real_T PIDController_Kb;             /* Mask Parameter: PIDController_Kb
                                        * Referenced by: '<S99>/Kb'
                                        */
  real_T PIDController1_Kb;            /* Mask Parameter: PIDController1_Kb
                                        * Referenced by: '<S143>/Kb'
                                        */
  real_T PIDController_LowerSaturationLimit;
                           /* Mask Parameter: PIDController_LowerSaturationLimit
                            * Referenced by: '<S113>/Saturation'
                            */
  real_T PIDController1_LowerSaturationLimit;
                          /* Mask Parameter: PIDController1_LowerSaturationLimit
                           * Referenced by: '<S157>/Saturation'
                           */
  real_T RealTimeSynchronization_MaxMissedTicks;
                       /* Mask Parameter: RealTimeSynchronization_MaxMissedTicks
                        * Referenced by: '<S382>/Real-Time Synchronization'
                        */
  real_T PIDController_N;              /* Mask Parameter: PIDController_N
                                        * Referenced by: '<S109>/Filter Coefficient'
                                        */
  real_T PIDController1_N;             /* Mask Parameter: PIDController1_N
                                        * Referenced by: '<S153>/Filter Coefficient'
                                        */
  real_T PIDController_UpperSaturationLimit;
                           /* Mask Parameter: PIDController_UpperSaturationLimit
                            * Referenced by: '<S113>/Saturation'
                            */
  real_T PIDController1_UpperSaturationLimit;
                          /* Mask Parameter: PIDController1_UpperSaturationLimit
                           * Referenced by: '<S157>/Saturation'
                           */
  real_T PacketInput_YieldWhenWaiting;
                                 /* Mask Parameter: PacketInput_YieldWhenWaiting
                                  * Referenced by: '<S23>/Packet Input'
                                  */
  real_T PacketOutput_YieldWhenWaiting;
                                /* Mask Parameter: PacketOutput_YieldWhenWaiting
                                 * Referenced by: '<S33>/Packet Output'
                                 */
  real_T RealTimeSynchronization_YieldWhenWaiting;
                     /* Mask Parameter: RealTimeSynchronization_YieldWhenWaiting
                      * Referenced by: '<S382>/Real-Time Synchronization'
                      */
  real_T ThreeaxisInertialMeasurementUnit_a_bias[3];
                      /* Mask Parameter: ThreeaxisInertialMeasurementUnit_a_bias
                       * Referenced by: '<S392>/Measurement bias'
                       */
  real_T ThreeaxisInertialMeasurementUnit_a_sf_cc[9];
                     /* Mask Parameter: ThreeaxisInertialMeasurementUnit_a_sf_cc
                      * Referenced by: '<S392>/Scale factors & Cross-coupling  errors'
                      */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S387>/Constant'
                                       */
  real_T CompareToConstant_const_h; /* Mask Parameter: CompareToConstant_const_h
                                     * Referenced by: '<S172>/Constant'
                                     */
  real_T CompareToConstant_const_i; /* Mask Parameter: CompareToConstant_const_i
                                     * Referenced by: '<S257>/Constant'
                                     */
  real_T Rudder_d_siB_0;               /* Mask Parameter: Rudder_d_siB_0
                                        * Referenced by: '<S270>/Integrator'
                                        */
  real_T Rudder1_d_siB_0;              /* Mask Parameter: Rudder1_d_siB_0
                                        * Referenced by: '<S271>/Integrator'
                                        */
  real_T Rudder2_d_siB_0;              /* Mask Parameter: Rudder2_d_siB_0
                                        * Referenced by: '<S272>/Integrator'
                                        */
  real_T Rudder3_d_siB_0;              /* Mask Parameter: Rudder3_d_siB_0
                                        * Referenced by: '<S273>/Integrator'
                                        */
  real_T Rudder_d_siB_max;             /* Mask Parameter: Rudder_d_siB_max
                                        * Referenced by:
                                        *   '<S270>/Limiting_Acceleration'
                                        *   '<S270>/Limiting_Rate'
                                        */
  real_T Rudder1_d_siB_max;            /* Mask Parameter: Rudder1_d_siB_max
                                        * Referenced by:
                                        *   '<S271>/Limiting_Acceleration'
                                        *   '<S271>/Limiting_Rate'
                                        */
  real_T Rudder2_d_siB_max;            /* Mask Parameter: Rudder2_d_siB_max
                                        * Referenced by:
                                        *   '<S272>/Limiting_Acceleration'
                                        *   '<S272>/Limiting_Rate'
                                        */
  real_T Rudder3_d_siB_max;            /* Mask Parameter: Rudder3_d_siB_max
                                        * Referenced by:
                                        *   '<S273>/Limiting_Acceleration'
                                        *   '<S273>/Limiting_Rate'
                                        */
  real_T Rudder_d_siB_min;             /* Mask Parameter: Rudder_d_siB_min
                                        * Referenced by:
                                        *   '<S270>/Limiting_Acceleration'
                                        *   '<S270>/Limiting_Rate'
                                        */
  real_T Rudder1_d_siB_min;            /* Mask Parameter: Rudder1_d_siB_min
                                        * Referenced by:
                                        *   '<S271>/Limiting_Acceleration'
                                        *   '<S271>/Limiting_Rate'
                                        */
  real_T Rudder2_d_siB_min;            /* Mask Parameter: Rudder2_d_siB_min
                                        * Referenced by:
                                        *   '<S272>/Limiting_Acceleration'
                                        *   '<S272>/Limiting_Rate'
                                        */
  real_T Rudder3_d_siB_min;            /* Mask Parameter: Rudder3_d_siB_min
                                        * Referenced by:
                                        *   '<S273>/Limiting_Acceleration'
                                        *   '<S273>/Limiting_Rate'
                                        */
  real_T Rudder_dd_siB_max;            /* Mask Parameter: Rudder_dd_siB_max
                                        * Referenced by: '<S270>/Limiting_Acceleration'
                                        */
  real_T Rudder1_dd_siB_max;           /* Mask Parameter: Rudder1_dd_siB_max
                                        * Referenced by: '<S271>/Limiting_Acceleration'
                                        */
  real_T Rudder2_dd_siB_max;           /* Mask Parameter: Rudder2_dd_siB_max
                                        * Referenced by: '<S272>/Limiting_Acceleration'
                                        */
  real_T Rudder3_dd_siB_max;           /* Mask Parameter: Rudder3_dd_siB_max
                                        * Referenced by: '<S273>/Limiting_Acceleration'
                                        */
  real_T Rudder_dd_siB_min;            /* Mask Parameter: Rudder_dd_siB_min
                                        * Referenced by: '<S270>/Limiting_Acceleration'
                                        */
  real_T Rudder1_dd_siB_min;           /* Mask Parameter: Rudder1_dd_siB_min
                                        * Referenced by: '<S271>/Limiting_Acceleration'
                                        */
  real_T Rudder2_dd_siB_min;           /* Mask Parameter: Rudder2_dd_siB_min
                                        * Referenced by: '<S272>/Limiting_Acceleration'
                                        */
  real_T Rudder3_dd_siB_min;           /* Mask Parameter: Rudder3_dd_siB_min
                                        * Referenced by: '<S273>/Limiting_Acceleration'
                                        */
  real_T Rudder_dmp;                   /* Mask Parameter: Rudder_dmp
                                        * Referenced by: '<S270>/Gain2'
                                        */
  real_T Rudder1_dmp;                  /* Mask Parameter: Rudder1_dmp
                                        * Referenced by: '<S271>/Gain2'
                                        */
  real_T Rudder2_dmp;                  /* Mask Parameter: Rudder2_dmp
                                        * Referenced by: '<S272>/Gain2'
                                        */
  real_T Rudder3_dmp;                  /* Mask Parameter: Rudder3_dmp
                                        * Referenced by: '<S273>/Gain2'
                                        */
  real_T Rigid_Body_EOM_6_DOF_flag_Kraft;
                              /* Mask Parameter: Rigid_Body_EOM_6_DOF_flag_Kraft
                               * Referenced by: '<S333>/Constant'
                               */
  real_T WGS84_Gravitation_flg_omega_enabled;
                          /* Mask Parameter: WGS84_Gravitation_flg_omega_enabled
                           * Referenced by: '<S254>/WGS84_Gravity_Implementation'
                           */
  real_T ThreeaxisInertialMeasurementUnit_g_bias[3];
                      /* Mask Parameter: ThreeaxisInertialMeasurementUnit_g_bias
                       * Referenced by: '<S393>/Measurement bias'
                       */
  real_T ThreeaxisInertialMeasurementUnit_g_sens[3];
                      /* Mask Parameter: ThreeaxisInertialMeasurementUnit_g_sens
                       * Referenced by: '<S393>/g-sensitive bias'
                       */
  real_T ThreeaxisInertialMeasurementUnit_g_sf_cc[9];
                     /* Mask Parameter: ThreeaxisInertialMeasurementUnit_g_sf_cc
                      * Referenced by: '<S393>/Scale factors & Cross-coupling  errors '
                      */
  real_T ThreeaxisInertialMeasurementUnit_imu[3];
                         /* Mask Parameter: ThreeaxisInertialMeasurementUnit_imu
                          * Referenced by: '<S392>/wl_ins'
                          */
  real_T IntervalTest_lowlimit;        /* Mask Parameter: IntervalTest_lowlimit
                                        * Referenced by: '<S258>/Lower Limit'
                                        */
  real_T IntervalTest1_lowlimit;       /* Mask Parameter: IntervalTest1_lowlimit
                                        * Referenced by: '<S259>/Lower Limit'
                                        */
  real_T geopot_height_mean_earth_radius;
                              /* Mask Parameter: geopot_height_mean_earth_radius
                               * Referenced by: '<S265>/mean_earth_radius'
                               */
  real_T Rudder_omega;                 /* Mask Parameter: Rudder_omega
                                        * Referenced by: '<S270>/Gain2'
                                        */
  real_T Rudder1_omega;                /* Mask Parameter: Rudder1_omega
                                        * Referenced by: '<S271>/Gain2'
                                        */
  real_T Rudder2_omega;                /* Mask Parameter: Rudder2_omega
                                        * Referenced by: '<S272>/Gain2'
                                        */
  real_T Rudder3_omega;                /* Mask Parameter: Rudder3_omega
                                        * Referenced by: '<S273>/Gain2'
                                        */
  real_T u_rot_mat_rot_1;              /* Mask Parameter: u_rot_mat_rot_1
                                        * Referenced by: '<S355>/Constant'
                                        */
  real_T u_rot_mat_rot_1_m;            /* Mask Parameter: u_rot_mat_rot_1_m
                                        * Referenced by: '<S315>/Constant'
                                        */
  real_T u_rot_mat_rot_1_md;           /* Mask Parameter: u_rot_mat_rot_1_md
                                        * Referenced by: '<S370>/Constant'
                                        */
  real_T u_rot_mat_rot_2;              /* Mask Parameter: u_rot_mat_rot_2
                                        * Referenced by: '<S315>/Constant1'
                                        */
  real_T u_rot_mat_rot_2_h;            /* Mask Parameter: u_rot_mat_rot_2_h
                                        * Referenced by: '<S370>/Constant1'
                                        */
  real_T u_rot_mat_rot_3;              /* Mask Parameter: u_rot_mat_rot_3
                                        * Referenced by: '<S315>/Constant2'
                                        */
  real_T u_rot_mat_rot_3_m;            /* Mask Parameter: u_rot_mat_rot_3_m
                                        * Referenced by: '<S370>/Constant2'
                                        */
  real_T Rudder_siB_0;                 /* Mask Parameter: Rudder_siB_0
                                        * Referenced by: '<S270>/Integrator1'
                                        */
  real_T Rudder1_siB_0;                /* Mask Parameter: Rudder1_siB_0
                                        * Referenced by: '<S271>/Integrator1'
                                        */
  real_T Rudder2_siB_0;                /* Mask Parameter: Rudder2_siB_0
                                        * Referenced by: '<S272>/Integrator1'
                                        */
  real_T Rudder3_siB_0;                /* Mask Parameter: Rudder3_siB_0
                                        * Referenced by: '<S273>/Integrator1'
                                        */
  real_T Rudder_siB_max;               /* Mask Parameter: Rudder_siB_max
                                        * Referenced by:
                                        *   '<S270>/Limiting_Acceleration'
                                        *   '<S270>/Limiting_Rate'
                                        *   '<S270>/Integrator1'
                                        *   '<S270>/Saturation'
                                        *   '<S270>/Saturation1'
                                        */
  real_T Rudder1_siB_max;              /* Mask Parameter: Rudder1_siB_max
                                        * Referenced by:
                                        *   '<S271>/Limiting_Acceleration'
                                        *   '<S271>/Limiting_Rate'
                                        *   '<S271>/Integrator1'
                                        *   '<S271>/Saturation'
                                        *   '<S271>/Saturation1'
                                        */
  real_T Rudder2_siB_max;              /* Mask Parameter: Rudder2_siB_max
                                        * Referenced by:
                                        *   '<S272>/Limiting_Acceleration'
                                        *   '<S272>/Limiting_Rate'
                                        *   '<S272>/Integrator1'
                                        *   '<S272>/Saturation'
                                        *   '<S272>/Saturation1'
                                        */
  real_T Rudder3_siB_max;              /* Mask Parameter: Rudder3_siB_max
                                        * Referenced by:
                                        *   '<S273>/Limiting_Acceleration'
                                        *   '<S273>/Limiting_Rate'
                                        *   '<S273>/Integrator1'
                                        *   '<S273>/Saturation'
                                        *   '<S273>/Saturation1'
                                        */
  real_T Rudder_siB_min;               /* Mask Parameter: Rudder_siB_min
                                        * Referenced by:
                                        *   '<S270>/Limiting_Acceleration'
                                        *   '<S270>/Limiting_Rate'
                                        *   '<S270>/Integrator1'
                                        *   '<S270>/Saturation'
                                        *   '<S270>/Saturation1'
                                        */
  real_T Rudder1_siB_min;              /* Mask Parameter: Rudder1_siB_min
                                        * Referenced by:
                                        *   '<S271>/Limiting_Acceleration'
                                        *   '<S271>/Limiting_Rate'
                                        *   '<S271>/Integrator1'
                                        *   '<S271>/Saturation'
                                        *   '<S271>/Saturation1'
                                        */
  real_T Rudder2_siB_min;              /* Mask Parameter: Rudder2_siB_min
                                        * Referenced by:
                                        *   '<S272>/Limiting_Acceleration'
                                        *   '<S272>/Limiting_Rate'
                                        *   '<S272>/Integrator1'
                                        *   '<S272>/Saturation'
                                        *   '<S272>/Saturation1'
                                        */
  real_T Rudder3_siB_min;              /* Mask Parameter: Rudder3_siB_min
                                        * Referenced by:
                                        *   '<S273>/Limiting_Acceleration'
                                        *   '<S273>/Limiting_Rate'
                                        *   '<S273>/Integrator1'
                                        *   '<S273>/Saturation'
                                        *   '<S273>/Saturation1'
                                        */
  real_T Rudder_unc_bl;                /* Mask Parameter: Rudder_unc_bl
                                        * Referenced by: '<S270>/Gain3'
                                        */
  real_T Rudder1_unc_bl;               /* Mask Parameter: Rudder1_unc_bl
                                        * Referenced by: '<S271>/Gain3'
                                        */
  real_T Rudder2_unc_bl;               /* Mask Parameter: Rudder2_unc_bl
                                        * Referenced by: '<S272>/Gain3'
                                        */
  real_T Rudder3_unc_bl;               /* Mask Parameter: Rudder3_unc_bl
                                        * Referenced by: '<S273>/Gain3'
                                        */
  real_T Rudder_unc_off;               /* Mask Parameter: Rudder_unc_off
                                        * Referenced by: '<S270>/Constant'
                                        */
  real_T Rudder1_unc_off;              /* Mask Parameter: Rudder1_unc_off
                                        * Referenced by: '<S271>/Constant'
                                        */
  real_T Rudder2_unc_off;              /* Mask Parameter: Rudder2_unc_off
                                        * Referenced by: '<S272>/Constant'
                                        */
  real_T Rudder3_unc_off;              /* Mask Parameter: Rudder3_unc_off
                                        * Referenced by: '<S273>/Constant'
                                        */
  real_T Rudder_unc_scale;             /* Mask Parameter: Rudder_unc_scale
                                        * Referenced by: '<S270>/Gain1'
                                        */
  real_T Rudder1_unc_scale;            /* Mask Parameter: Rudder1_unc_scale
                                        * Referenced by: '<S271>/Gain1'
                                        */
  real_T Rudder2_unc_scale;            /* Mask Parameter: Rudder2_unc_scale
                                        * Referenced by: '<S272>/Gain1'
                                        */
  real_T Rudder3_unc_scale;            /* Mask Parameter: Rudder3_unc_scale
                                        * Referenced by: '<S273>/Gain1'
                                        */
  real_T IntervalTest_uplimit;         /* Mask Parameter: IntervalTest_uplimit
                                        * Referenced by: '<S258>/Upper Limit'
                                        */
  real_T IntervalTest1_uplimit;        /* Mask Parameter: IntervalTest1_uplimit
                                        * Referenced by: '<S259>/Upper Limit'
                                        */
  real_T ThreeaxisInertialMeasurementUnit_w_a;
                         /* Mask Parameter: ThreeaxisInertialMeasurementUnit_w_a
                          * Referenced by:
                          *   '<S399>/2*zeta * wn'
                          *   '<S399>/wn^2'
                          */
  real_T ThreeaxisInertialMeasurementUnit_w_g;
                         /* Mask Parameter: ThreeaxisInertialMeasurementUnit_w_g
                          * Referenced by:
                          *   '<S411>/2*zeta * wn'
                          *   '<S411>/wn^2'
                          */
  real_T ThreeaxisInertialMeasurementUnit_z_a;
                         /* Mask Parameter: ThreeaxisInertialMeasurementUnit_z_a
                          * Referenced by: '<S399>/2*zeta * wn'
                          */
  real_T ThreeaxisInertialMeasurementUnit_z_g;
                         /* Mask Parameter: ThreeaxisInertialMeasurementUnit_z_g
                          * Referenced by: '<S411>/2*zeta * wn'
                          */
  int32_T PacketInput_PacketID;        /* Mask Parameter: PacketInput_PacketID
                                        * Referenced by: '<S23>/Packet Input'
                                        */
  int32_T PacketOutput_PacketID;       /* Mask Parameter: PacketOutput_PacketID
                                        * Referenced by: '<S33>/Packet Output'
                                        */
  uint16_T WrapToZero_Threshold;       /* Mask Parameter: WrapToZero_Threshold
                                        * Referenced by: '<S386>/FixPt Switch'
                                        */
  real_T Constant11_Value;             /* Expression: 1
                                        * Referenced by: '<S19>/Constant11'
                                        */
  real_T Constant14_Value;             /* Expression: 1
                                        * Referenced by: '<S19>/Constant14'
                                        */
  real_T Constant7_Value;              /* Expression: 1
                                        * Referenced by: '<S19>/Constant7'
                                        */
  real_T Constant12_Value;             /* Expression: 1
                                        * Referenced by: '<S19>/Constant12'
                                        */
  real_T Constant9_Value;              /* Expression: 1
                                        * Referenced by: '<S19>/Constant9'
                                        */
  real_T Constant13_Value;             /* Expression: 1
                                        * Referenced by: '<S19>/Constant13'
                                        */
  real_T SineWave_Amp;                 /* Expression: 1
                                        * Referenced by: '<S23>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 0
                                        * Referenced by: '<S23>/Sine Wave'
                                        */
  real_T SineWave_Freq;                /* Expression: 1
                                        * Referenced by: '<S23>/Sine Wave'
                                        */
  real_T SineWave_Hsin;                /* Computed Parameter: SineWave_Hsin
                                        * Referenced by: '<S23>/Sine Wave'
                                        */
  real_T SineWave_HCos;                /* Computed Parameter: SineWave_HCos
                                        * Referenced by: '<S23>/Sine Wave'
                                        */
  real_T SineWave_PSin;                /* Computed Parameter: SineWave_PSin
                                        * Referenced by: '<S23>/Sine Wave'
                                        */
  real_T SineWave_PCos;                /* Computed Parameter: SineWave_PCos
                                        * Referenced by: '<S23>/Sine Wave'
                                        */
  real_T SineWave_Amp_c;               /* Expression: 1
                                        * Referenced by: '<S33>/Sine Wave'
                                        */
  real_T SineWave_Bias_b;              /* Expression: 0
                                        * Referenced by: '<S33>/Sine Wave'
                                        */
  real_T SineWave_Freq_c;              /* Expression: 1
                                        * Referenced by: '<S33>/Sine Wave'
                                        */
  real_T SineWave_Hsin_e;              /* Computed Parameter: SineWave_Hsin_e
                                        * Referenced by: '<S33>/Sine Wave'
                                        */
  real_T SineWave_HCos_g;              /* Computed Parameter: SineWave_HCos_g
                                        * Referenced by: '<S33>/Sine Wave'
                                        */
  real_T SineWave_PSin_i;              /* Computed Parameter: SineWave_PSin_i
                                        * Referenced by: '<S33>/Sine Wave'
                                        */
  real_T SineWave_PCos_i;              /* Computed Parameter: SineWave_PCos_i
                                        * Referenced by: '<S33>/Sine Wave'
                                        */
  real_T status_Y0;                    /* Computed Parameter: status_Y0
                                        * Referenced by: '<S30>/status'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S30>/Constant'
                                        */
  real_T One_Value;                    /* Expression: 1
                                        * Referenced by: '<S30>/One'
                                        */
  real_T Constant_Value_g;             /* Expression: 1
                                        * Referenced by: '<S73>/Constant'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<S73>/Constant3'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1
                                        * Referenced by: '<S73>/Gain2'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1
                                        * Referenced by: '<S73>/Gain3'
                                        */
  real_T c_flat_Value;                 /* Expression: c_flat
                                        * Referenced by: '<S227>/c_flat'
                                        */
  real_T Gain_Gain;                    /* Expression: 2
                                        * Referenced by: '<S228>/Gain'
                                        */
  real_T Constant_Value_gq;            /* Expression: 1
                                        * Referenced by: '<S229>/Constant'
                                        */
  real_T c_rsma_Value;                 /* Expression: c_rsma
                                        * Referenced by: '<S227>/c_rsma'
                                        */
  real_T Gain_Gain_c;                  /* Expression: 2
                                        * Referenced by: '<S229>/Gain'
                                        */
  real_T Constant_Value_j;             /* Expression: 1
                                        * Referenced by: '<S228>/Constant'
                                        */
  real_T Gain_Gain_i;                  /* Expression: -1
                                        * Referenced by: '<S226>/Gain'
                                        */
  real_T Cn_delta_n_Interpolation_Table[2601];
                           /* Expression: HIL_Data.FDM.soph.bus1.aero.Cn_delta_n
                            * Referenced by: '<S236>/Cn_delta_n_Interpolation'
                            */
  real_T Cn_delta_m_Interpolation_Table[2601];
                           /* Expression: HIL_Data.FDM.soph.bus1.aero.Cn_delta_m
                            * Referenced by: '<S236>/Cn_delta_m_Interpolation'
                            */
  real_T Cn_delta_l_Interpolation_Table[2601];
                           /* Expression: HIL_Data.FDM.soph.bus1.aero.Cn_delta_l
                            * Referenced by: '<S236>/Cn_delta_l_Interpolation'
                            */
  real_T Cnr_Interpolation_Table[2601];
                                  /* Expression: HIL_Data.FDM.soph.bus1.aero.Cnr
                                   * Referenced by: '<S236>/Cnr_Interpolation'
                                   */
  real_T Cnq_Interpolation_Table[2601];
                                  /* Expression: HIL_Data.FDM.soph.bus1.aero.Cnq
                                   * Referenced by: '<S236>/Cnq_Interpolation'
                                   */
  real_T Cnp_Interpolation_Table[2601];
                                  /* Expression: HIL_Data.FDM.soph.bus1.aero.Cnp
                                   * Referenced by: '<S236>/Cnp_Interpolation'
                                   */
  real_T Cn_Interpolation_Table[2601];
                                   /* Expression: HIL_Data.FDM.soph.bus1.aero.Cn
                                    * Referenced by: '<S236>/Cn_Interpolation'
                                    */
  real_T Cm_delta_n_Interpolation_Table[2601];
                           /* Expression: HIL_Data.FDM.soph.bus1.aero.Cm_delta_n
                            * Referenced by: '<S235>/Cm_delta_n_Interpolation'
                            */
  real_T Cm_delta_m_Interpolation_Table[2601];
                           /* Expression: HIL_Data.FDM.soph.bus1.aero.Cm_delta_m
                            * Referenced by: '<S235>/Cm_delta_m_Interpolation'
                            */
  real_T Cm_delta_l_Interpolation_Table[2601];
                           /* Expression: HIL_Data.FDM.soph.bus1.aero.Cm_delta_l
                            * Referenced by: '<S235>/Cm_delta_l_Interpolation'
                            */
  real_T Cmr_Interpolation_Table[2601];
                                  /* Expression: HIL_Data.FDM.soph.bus1.aero.Cmr
                                   * Referenced by: '<S235>/Cmr_Interpolation'
                                   */
  real_T Cmq_Interpolation_Table[2601];
                                  /* Expression: HIL_Data.FDM.soph.bus1.aero.Cmq
                                   * Referenced by: '<S235>/Cmq_Interpolation'
                                   */
  real_T Cmp_Interpolation_Table[2601];
                                  /* Expression: HIL_Data.FDM.soph.bus1.aero.Cmp
                                   * Referenced by: '<S235>/Cmp_Interpolation'
                                   */
  real_T Cm_Interpolation_Table[2601];
                                   /* Expression: HIL_Data.FDM.soph.bus1.aero.Cm
                                    * Referenced by: '<S235>/Cm_Interpolation'
                                    */
  real_T Cl_delta_n_Interpolation_Table[2601];
                           /* Expression: HIL_Data.FDM.soph.bus1.aero.Cl_delta_n
                            * Referenced by: '<S234>/Cl_delta_n_Interpolation'
                            */
  real_T Cl_delta_m_Interpolation_Table[2601];
                           /* Expression: HIL_Data.FDM.soph.bus1.aero.Cl_delta_m
                            * Referenced by: '<S234>/Cl_delta_m_Interpolation'
                            */
  real_T Cl_delta_l_Interpolation_Table[2601];
                           /* Expression: HIL_Data.FDM.soph.bus1.aero.Cl_delta_l
                            * Referenced by: '<S234>/Cl_delta_l_Interpolation'
                            */
  real_T Clr_Interpolation_Table[2601];
                                  /* Expression: HIL_Data.FDM.soph.bus1.aero.Clr
                                   * Referenced by: '<S234>/Clr_Interpolation'
                                   */
  real_T Clq_Interpolation_Table[2601];
                                  /* Expression: HIL_Data.FDM.soph.bus1.aero.Clq
                                   * Referenced by: '<S234>/Clq_Interpolation'
                                   */
  real_T Clp_Interpolation_Table[2601];
                                  /* Expression: HIL_Data.FDM.soph.bus1.aero.Clp
                                   * Referenced by: '<S234>/Clp_Interpolation'
                                   */
  real_T Cl_Interpolation_Table[2601];
                                   /* Expression: HIL_Data.FDM.soph.bus1.aero.Cl
                                    * Referenced by: '<S234>/Cl_Interpolation'
                                    */
  real_T c_flat_Value_f;               /* Expression: c_flat
                                        * Referenced by: '<S231>/c_flat'
                                        */
  real_T Gain_Gain_a;                  /* Expression: 2
                                        * Referenced by: '<S232>/Gain'
                                        */
  real_T Constant_Value_f;             /* Expression: 1
                                        * Referenced by: '<S233>/Constant'
                                        */
  real_T c_rsma_Value_b;               /* Expression: c_rsma
                                        * Referenced by: '<S231>/c_rsma'
                                        */
  real_T Gain_Gain_o;                  /* Expression: 2
                                        * Referenced by: '<S233>/Gain'
                                        */
  real_T Constant_Value_m;             /* Expression: 1
                                        * Referenced by: '<S232>/Constant'
                                        */
  real_T Gain_Gain_f;                  /* Expression: -1
                                        * Referenced by: '<S230>/Gain'
                                        */
  real_T WGS84_Gravity_Implementation_c_b_WGS;/* Expression: c_b_WGS
                                               * Referenced by: '<S254>/WGS84_Gravity_Implementation'
                                               */
  real_T WGS84_Gravity_Implementation_c_grav;/* Expression: c_grav
                                              * Referenced by: '<S254>/WGS84_Gravity_Implementation'
                                              */
  real_T WGS84_Gravity_Implementation_c_rot;/* Expression: c_rot
                                             * Referenced by: '<S254>/WGS84_Gravity_Implementation'
                                             */
  real_T WGS84_Gravity_Implementation_c_rsma;/* Expression: c_rsma
                                              * Referenced by: '<S254>/WGS84_Gravity_Implementation'
                                              */
  real_T c_flat_Value_c;               /* Expression: c_flat
                                        * Referenced by: '<S285>/c_flat'
                                        */
  real_T Gain_Gain_l;                  /* Expression: 2
                                        * Referenced by: '<S286>/Gain'
                                        */
  real_T Constant_Value_e;             /* Expression: 1
                                        * Referenced by: '<S287>/Constant'
                                        */
  real_T c_rsma_Value_m;               /* Expression: c_rsma
                                        * Referenced by: '<S285>/c_rsma'
                                        */
  real_T Gain_Gain_j;                  /* Expression: 2
                                        * Referenced by: '<S287>/Gain'
                                        */
  real_T Constant_Value_o;             /* Expression: 1
                                        * Referenced by: '<S286>/Constant'
                                        */
  real_T Gain_Gain_g;                  /* Expression: -1
                                        * Referenced by: '<S284>/Gain'
                                        */
  real_T Constant8_Value;              /* Expression: 0
                                        * Referenced by: '<S301>/Constant8'
                                        */
  real_T Constant7_Value_i;          /* Expression: HIL_Data.FDM.soph.bus2.c_rot
                                      * Referenced by: '<S301>/Constant7'
                                      */
  real_T Constant6_Value;              /* Expression: 0
                                        * Referenced by: '<S301>/Constant6'
                                        */
  real_T Gain2_Gain_k;                 /* Expression: -1
                                        * Referenced by: '<S304>/Gain2'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S304>/Gain1'
                                        */
  real_T Saturation_UpperSat;  /* Expression: HIL_Data.FDM.soph.bus1.t_prp1(end)
                                * Referenced by: '<S313>/Saturation'
                                */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S313>/Saturation'
                                        */
  real_T thrust_lookup_tableData[12];/* Expression: HIL_Data.FDM.soph.bus1.F_prp
                                      * Referenced by: '<S313>/thrust_lookup'
                                      */
  real_T thrust_lookup_bp01Data[12];/* Expression: HIL_Data.FDM.soph.bus1.t_prp1
                                     * Referenced by: '<S313>/thrust_lookup'
                                     */
  real_T Constant11_Value_o;           /* Expression: 1
                                        * Referenced by: '<S325>/Constant11'
                                        */
  real_T Constant10_Value;             /* Expression: 0
                                        * Referenced by: '<S325>/Constant10'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<S325>/Constant4'
                                        */
  real_T Constant7_Value_is;           /* Expression: 0
                                        * Referenced by: '<S325>/Constant7'
                                        */
  real_T Constant8_Value_d;            /* Expression: 0
                                        * Referenced by: '<S325>/Constant8'
                                        */
  real_T Gain_Gain_e;                  /* Expression: -1
                                        * Referenced by: '<S325>/Gain'
                                        */
  real_T Constant7_Value_a;            /* Expression: 0
                                        * Referenced by: '<S324>/Constant7'
                                        */
  real_T Gain1_Gain_d;                 /* Expression: -1
                                        * Referenced by: '<S324>/Gain1'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S324>/Constant2'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S324>/Constant1'
                                        */
  real_T Constant_Value_ek;            /* Expression: 0
                                        * Referenced by: '<S324>/Constant'
                                        */
  real_T Constant8_Value_k;            /* Expression: 0
                                        * Referenced by: '<S324>/Constant8'
                                        */
  real_T Constant7_Value_k;            /* Expression: 0
                                        * Referenced by: '<S323>/Constant7'
                                        */
  real_T Gain_Gain_h;                  /* Expression: -1
                                        * Referenced by: '<S323>/Gain'
                                        */
  real_T Constant8_Value_a;            /* Expression: 0
                                        * Referenced by: '<S323>/Constant8'
                                        */
  real_T Constant2_Value_j;            /* Expression: 0
                                        * Referenced by: '<S323>/Constant2'
                                        */
  real_T Constant1_Value_j;            /* Expression: 0
                                        * Referenced by: '<S323>/Constant1'
                                        */
  real_T Constant_Value_d;             /* Expression: 1
                                        * Referenced by: '<S323>/Constant'
                                        */
  real_T Constant11_Value_p;           /* Expression: 1
                                        * Referenced by: '<S322>/Constant11'
                                        */
  real_T Constant10_Value_f;           /* Expression: 0
                                        * Referenced by: '<S322>/Constant10'
                                        */
  real_T Constant4_Value_h;            /* Expression: 0
                                        * Referenced by: '<S322>/Constant4'
                                        */
  real_T Constant7_Value_d;            /* Expression: 0
                                        * Referenced by: '<S322>/Constant7'
                                        */
  real_T Constant8_Value_o;            /* Expression: 0
                                        * Referenced by: '<S322>/Constant8'
                                        */
  real_T Gain_Gain_hf;                 /* Expression: -1
                                        * Referenced by: '<S322>/Gain'
                                        */
  real_T Constant7_Value_ib;           /* Expression: 0
                                        * Referenced by: '<S321>/Constant7'
                                        */
  real_T Gain1_Gain_h;                 /* Expression: -1
                                        * Referenced by: '<S321>/Gain1'
                                        */
  real_T Constant2_Value_m;            /* Expression: 0
                                        * Referenced by: '<S321>/Constant2'
                                        */
  real_T Constant1_Value_l;            /* Expression: 1
                                        * Referenced by: '<S321>/Constant1'
                                        */
  real_T Constant_Value_dk;            /* Expression: 0
                                        * Referenced by: '<S321>/Constant'
                                        */
  real_T Constant8_Value_b;            /* Expression: 0
                                        * Referenced by: '<S321>/Constant8'
                                        */
  real_T Constant7_Value_f;            /* Expression: 0
                                        * Referenced by: '<S320>/Constant7'
                                        */
  real_T Gain_Gain_jq;                 /* Expression: -1
                                        * Referenced by: '<S320>/Gain'
                                        */
  real_T Constant8_Value_e;            /* Expression: 0
                                        * Referenced by: '<S320>/Constant8'
                                        */
  real_T Constant2_Value_e;            /* Expression: 0
                                        * Referenced by: '<S320>/Constant2'
                                        */
  real_T Constant1_Value_n;            /* Expression: 0
                                        * Referenced by: '<S320>/Constant1'
                                        */
  real_T Constant_Value_a;             /* Expression: 1
                                        * Referenced by: '<S320>/Constant'
                                        */
  real_T Constant11_Value_l;           /* Expression: 1
                                        * Referenced by: '<S319>/Constant11'
                                        */
  real_T Constant10_Value_l;           /* Expression: 0
                                        * Referenced by: '<S319>/Constant10'
                                        */
  real_T Constant4_Value_l;            /* Expression: 0
                                        * Referenced by: '<S319>/Constant4'
                                        */
  real_T Constant7_Value_c;            /* Expression: 0
                                        * Referenced by: '<S319>/Constant7'
                                        */
  real_T Constant8_Value_f;            /* Expression: 0
                                        * Referenced by: '<S319>/Constant8'
                                        */
  real_T Gain_Gain_k;                  /* Expression: -1
                                        * Referenced by: '<S319>/Gain'
                                        */
  real_T Constant7_Value_f2;           /* Expression: 0
                                        * Referenced by: '<S318>/Constant7'
                                        */
  real_T Gain1_Gain_hx;                /* Expression: -1
                                        * Referenced by: '<S318>/Gain1'
                                        */
  real_T Constant2_Value_d;            /* Expression: 0
                                        * Referenced by: '<S318>/Constant2'
                                        */
  real_T Constant1_Value_b;            /* Expression: 1
                                        * Referenced by: '<S318>/Constant1'
                                        */
  real_T Constant_Value_n;             /* Expression: 0
                                        * Referenced by: '<S318>/Constant'
                                        */
  real_T Constant8_Value_g;            /* Expression: 0
                                        * Referenced by: '<S318>/Constant8'
                                        */
  real_T Constant7_Value_b;            /* Expression: 0
                                        * Referenced by: '<S317>/Constant7'
                                        */
  real_T Gain_Gain_lj;                 /* Expression: -1
                                        * Referenced by: '<S317>/Gain'
                                        */
  real_T Constant8_Value_ks;           /* Expression: 0
                                        * Referenced by: '<S317>/Constant8'
                                        */
  real_T Constant2_Value_f;            /* Expression: 0
                                        * Referenced by: '<S317>/Constant2'
                                        */
  real_T Constant1_Value_o;            /* Expression: 0
                                        * Referenced by: '<S317>/Constant1'
                                        */
  real_T Constant_Value_l;             /* Expression: 1
                                        * Referenced by: '<S317>/Constant'
                                        */
  real_T Gain_Gain_p;                  /* Expression: -1
                                        * Referenced by: '<S328>/Gain'
                                        */
  real_T Gain12_Gain;                  /* Expression: 2
                                        * Referenced by: '<S335>/Gain12'
                                        */
  real_T Gain11_Gain;                  /* Expression: 2
                                        * Referenced by: '<S335>/Gain11'
                                        */
  real_T Gain6_Gain;                   /* Expression: 2
                                        * Referenced by: '<S335>/Gain6'
                                        */
  real_T Gain5_Gain;                   /* Expression: 2
                                        * Referenced by: '<S335>/Gain5'
                                        */
  real_T Gain4_Gain;                   /* Expression: 2
                                        * Referenced by: '<S335>/Gain4'
                                        */
  real_T Gain3_Gain_i;                 /* Expression: 2
                                        * Referenced by: '<S335>/Gain3'
                                        */
  real_T Gain8_Gain;                   /* Expression: 2
                                        * Referenced by: '<S335>/Gain8'
                                        */
  real_T Gain7_Gain;                   /* Expression: 2
                                        * Referenced by: '<S335>/Gain7'
                                        */
  real_T Gain10_Gain;                  /* Expression: 2
                                        * Referenced by: '<S335>/Gain10'
                                        */
  real_T Gain9_Gain;                   /* Expression: 2
                                        * Referenced by: '<S335>/Gain9'
                                        */
  real_T Gain2_Gain_i;                 /* Expression: 2
                                        * Referenced by: '<S335>/Gain2'
                                        */
  real_T Gain1_Gain_m;                 /* Expression: 2
                                        * Referenced by: '<S335>/Gain1'
                                        */
  real_T Constant11_Value_a;           /* Expression: 1
                                        * Referenced by: '<S358>/Constant11'
                                        */
  real_T Constant10_Value_d;           /* Expression: 0
                                        * Referenced by: '<S358>/Constant10'
                                        */
  real_T Constant4_Value_o;            /* Expression: 0
                                        * Referenced by: '<S358>/Constant4'
                                        */
  real_T Constant7_Value_g;            /* Expression: 0
                                        * Referenced by: '<S358>/Constant7'
                                        */
  real_T Constant8_Value_gg;           /* Expression: 0
                                        * Referenced by: '<S358>/Constant8'
                                        */
  real_T Gain_Gain_jn;                 /* Expression: -1
                                        * Referenced by: '<S358>/Gain'
                                        */
  real_T Constant7_Value_d1;           /* Expression: 0
                                        * Referenced by: '<S357>/Constant7'
                                        */
  real_T Gain1_Gain_j;                 /* Expression: -1
                                        * Referenced by: '<S357>/Gain1'
                                        */
  real_T Constant2_Value_g;            /* Expression: 0
                                        * Referenced by: '<S357>/Constant2'
                                        */
  real_T Constant1_Value_i;            /* Expression: 1
                                        * Referenced by: '<S357>/Constant1'
                                        */
  real_T Constant_Value_ob;            /* Expression: 0
                                        * Referenced by: '<S357>/Constant'
                                        */
  real_T Constant8_Value_ky;           /* Expression: 0
                                        * Referenced by: '<S357>/Constant8'
                                        */
  real_T Constant7_Value_j;            /* Expression: 0
                                        * Referenced by: '<S356>/Constant7'
                                        */
  real_T Gain_Gain_kj;                 /* Expression: -1
                                        * Referenced by: '<S356>/Gain'
                                        */
  real_T Constant8_Value_af;           /* Expression: 0
                                        * Referenced by: '<S356>/Constant8'
                                        */
  real_T Constant2_Value_b;            /* Expression: 0
                                        * Referenced by: '<S356>/Constant2'
                                        */
  real_T Constant1_Value_c;            /* Expression: 0
                                        * Referenced by: '<S356>/Constant1'
                                        */
  real_T Constant_Value_h;             /* Expression: 1
                                        * Referenced by: '<S356>/Constant'
                                        */
  real_T Saturation_UpperSat_c;/* Expression: HIL_Data.FDM.soph.bus1.t_prp2(end)
                                * Referenced by: '<S361>/Saturation'
                                */
  real_T Saturation_LowerSat_h;        /* Expression: 0
                                        * Referenced by: '<S361>/Saturation'
                                        */
  real_T uDLookupTable_tableData[17];
                             /* Expression: HIL_Data.FDM.soph.bus1.m_fuel_lookup
                              * Referenced by: '<S361>/1-D Lookup Table'
                              */
  real_T uDLookupTable_bp01Data[17];/* Expression: HIL_Data.FDM.soph.bus1.t_prp2
                                     * Referenced by: '<S361>/1-D Lookup Table'
                                     */
  real_T Constant11_Value_h;           /* Expression: 1
                                        * Referenced by: '<S379>/Constant11'
                                        */
  real_T Constant10_Value_g;           /* Expression: 0
                                        * Referenced by: '<S379>/Constant10'
                                        */
  real_T Constant4_Value_a;            /* Expression: 0
                                        * Referenced by: '<S379>/Constant4'
                                        */
  real_T Constant7_Value_cr;           /* Expression: 0
                                        * Referenced by: '<S379>/Constant7'
                                        */
  real_T Constant8_Value_os;           /* Expression: 0
                                        * Referenced by: '<S379>/Constant8'
                                        */
  real_T Gain_Gain_ow;                 /* Expression: -1
                                        * Referenced by: '<S379>/Gain'
                                        */
  real_T Constant7_Value_jt;           /* Expression: 0
                                        * Referenced by: '<S378>/Constant7'
                                        */
  real_T Gain1_Gain_n;                 /* Expression: -1
                                        * Referenced by: '<S378>/Gain1'
                                        */
  real_T Constant2_Value_jp;           /* Expression: 0
                                        * Referenced by: '<S378>/Constant2'
                                        */
  real_T Constant1_Value_c4;           /* Expression: 1
                                        * Referenced by: '<S378>/Constant1'
                                        */
  real_T Constant_Value_p;             /* Expression: 0
                                        * Referenced by: '<S378>/Constant'
                                        */
  real_T Constant8_Value_c;            /* Expression: 0
                                        * Referenced by: '<S378>/Constant8'
                                        */
  real_T Constant7_Value_p;            /* Expression: 0
                                        * Referenced by: '<S377>/Constant7'
                                        */
  real_T Gain_Gain_pk;                 /* Expression: -1
                                        * Referenced by: '<S377>/Gain'
                                        */
  real_T Constant8_Value_cs;           /* Expression: 0
                                        * Referenced by: '<S377>/Constant8'
                                        */
  real_T Constant2_Value_bt;           /* Expression: 0
                                        * Referenced by: '<S377>/Constant2'
                                        */
  real_T Constant1_Value_f;            /* Expression: 0
                                        * Referenced by: '<S377>/Constant1'
                                        */
  real_T Constant_Value_i;             /* Expression: 1
                                        * Referenced by: '<S377>/Constant'
                                        */
  real_T Constant11_Value_l2;          /* Expression: 1
                                        * Referenced by: '<S376>/Constant11'
                                        */
  real_T Constant10_Value_m;           /* Expression: 0
                                        * Referenced by: '<S376>/Constant10'
                                        */
  real_T Constant4_Value_b;            /* Expression: 0
                                        * Referenced by: '<S376>/Constant4'
                                        */
  real_T Constant7_Value_ch;           /* Expression: 0
                                        * Referenced by: '<S376>/Constant7'
                                        */
  real_T Constant8_Value_ke;           /* Expression: 0
                                        * Referenced by: '<S376>/Constant8'
                                        */
  real_T Gain_Gain_n;                  /* Expression: -1
                                        * Referenced by: '<S376>/Gain'
                                        */
  real_T Constant7_Value_fv;           /* Expression: 0
                                        * Referenced by: '<S375>/Constant7'
                                        */
  real_T Gain1_Gain_j0;                /* Expression: -1
                                        * Referenced by: '<S375>/Gain1'
                                        */
  real_T Constant2_Value_js;           /* Expression: 0
                                        * Referenced by: '<S375>/Constant2'
                                        */
  real_T Constant1_Value_a;            /* Expression: 1
                                        * Referenced by: '<S375>/Constant1'
                                        */
  real_T Constant_Value_c;             /* Expression: 0
                                        * Referenced by: '<S375>/Constant'
                                        */
  real_T Constant8_Value_dg;           /* Expression: 0
                                        * Referenced by: '<S375>/Constant8'
                                        */
  real_T Constant7_Value_n;            /* Expression: 0
                                        * Referenced by: '<S374>/Constant7'
                                        */
  real_T Gain_Gain_ax;                 /* Expression: -1
                                        * Referenced by: '<S374>/Gain'
                                        */
  real_T Constant8_Value_n;            /* Expression: 0
                                        * Referenced by: '<S374>/Constant8'
                                        */
  real_T Constant2_Value_c;            /* Expression: 0
                                        * Referenced by: '<S374>/Constant2'
                                        */
  real_T Constant1_Value_nq;           /* Expression: 0
                                        * Referenced by: '<S374>/Constant1'
                                        */
  real_T Constant_Value_lx;            /* Expression: 1
                                        * Referenced by: '<S374>/Constant'
                                        */
  real_T Constant11_Value_h1;          /* Expression: 1
                                        * Referenced by: '<S373>/Constant11'
                                        */
  real_T Constant10_Value_c;           /* Expression: 0
                                        * Referenced by: '<S373>/Constant10'
                                        */
  real_T Constant4_Value_l5;           /* Expression: 0
                                        * Referenced by: '<S373>/Constant4'
                                        */
  real_T Constant7_Value_p5;           /* Expression: 0
                                        * Referenced by: '<S373>/Constant7'
                                        */
  real_T Constant8_Value_gw;           /* Expression: 0
                                        * Referenced by: '<S373>/Constant8'
                                        */
  real_T Gain_Gain_f0;                 /* Expression: -1
                                        * Referenced by: '<S373>/Gain'
                                        */
  real_T Constant7_Value_je;           /* Expression: 0
                                        * Referenced by: '<S372>/Constant7'
                                        */
  real_T Gain1_Gain_hv;                /* Expression: -1
                                        * Referenced by: '<S372>/Gain1'
                                        */
  real_T Constant2_Value_i;            /* Expression: 0
                                        * Referenced by: '<S372>/Constant2'
                                        */
  real_T Constant1_Value_k;            /* Expression: 1
                                        * Referenced by: '<S372>/Constant1'
                                        */
  real_T Constant_Value_hw;            /* Expression: 0
                                        * Referenced by: '<S372>/Constant'
                                        */
  real_T Constant8_Value_l;            /* Expression: 0
                                        * Referenced by: '<S372>/Constant8'
                                        */
  real_T Constant7_Value_gi;           /* Expression: 0
                                        * Referenced by: '<S371>/Constant7'
                                        */
  real_T Gain_Gain_cy;                 /* Expression: -1
                                        * Referenced by: '<S371>/Gain'
                                        */
  real_T Constant8_Value_j;            /* Expression: 0
                                        * Referenced by: '<S371>/Constant8'
                                        */
  real_T Constant2_Value_a;            /* Expression: 0
                                        * Referenced by: '<S371>/Constant2'
                                        */
  real_T Constant1_Value_g;            /* Expression: 0
                                        * Referenced by: '<S371>/Constant1'
                                        */
  real_T Constant_Value_of;            /* Expression: 1
                                        * Referenced by: '<S371>/Constant'
                                        */
  real_T One_Value_g;                  /* Expression: 1
                                        * Referenced by: '<S21>/One'
                                        */
  real_T Constant_Value_pl[13];
  /* Expression: [HIL_Data.FDM.soph.bus2.pBII_0; HIL_Data.FDM.soph.bus2.vBII_0; HIL_Data.FDM.soph.bus2.qIB_0; HIL_Data.FDM.soph.bus2.wBIB_0]
   * Referenced by: '<S327>/Constant'
   */
  real_T Gain1_Gain_c;                 /* Expression: 2
                                        * Referenced by: '<S292>/Gain1'
                                        */
  real_T Gain2_Gain_c;                 /* Expression: 2
                                        * Referenced by: '<S292>/Gain2'
                                        */
  real_T Gain9_Gain_c;                 /* Expression: 2
                                        * Referenced by: '<S292>/Gain9'
                                        */
  real_T Gain10_Gain_g;                /* Expression: 2
                                        * Referenced by: '<S292>/Gain10'
                                        */
  real_T Gain7_Gain_c;                 /* Expression: 2
                                        * Referenced by: '<S292>/Gain7'
                                        */
  real_T Gain8_Gain_b;                 /* Expression: 2
                                        * Referenced by: '<S292>/Gain8'
                                        */
  real_T Gain3_Gain_p;                 /* Expression: 2
                                        * Referenced by: '<S292>/Gain3'
                                        */
  real_T Gain4_Gain_o;                 /* Expression: 2
                                        * Referenced by: '<S292>/Gain4'
                                        */
  real_T Gain5_Gain_l;                 /* Expression: 2
                                        * Referenced by: '<S292>/Gain5'
                                        */
  real_T Gain6_Gain_p;                 /* Expression: 2
                                        * Referenced by: '<S292>/Gain6'
                                        */
  real_T Gain11_Gain_d;                /* Expression: 2
                                        * Referenced by: '<S292>/Gain11'
                                        */
  real_T Gain12_Gain_g;                /* Expression: 2
                                        * Referenced by: '<S292>/Gain12'
                                        */
  real_T Gain_Gain_k1;                 /* Expression: 1
                                        * Referenced by: '<S194>/Gain'
                                        */
  real_T Gain1_Gain_mm;                /* Expression: 1
                                        * Referenced by: '<S194>/Gain1'
                                        */
  real_T Gain2_Gain_e;                 /* Expression: 1
                                        * Referenced by: '<S194>/Gain2'
                                        */
  real_T Gain17_Gain;                  /* Expression: 1
                                        * Referenced by: '<S194>/Gain17'
                                        */
  real_T Gain_Gain_pl;                 /* Expression: 1
                                        * Referenced by: '<S14>/Gain'
                                        */
  real_T Gain1_Gain_j5;                /* Expression: 1
                                        * Referenced by: '<S14>/Gain1'
                                        */
  real_T Gain2_Gain_g;                 /* Expression: 1
                                        * Referenced by: '<S14>/Gain2'
                                        */
  real_T Gain3_Gain_d;                 /* Expression: 1
                                        * Referenced by: '<S14>/Gain3'
                                        */
  real_T Constant_Value_ei;            /* Expression: -1
                                        * Referenced by: '<S12>/Constant'
                                        */
  real_T Constant1_Value_d;            /* Expression: -1
                                        * Referenced by: '<S12>/Constant1'
                                        */
  real_T Constant2_Value_h;            /* Expression: -1
                                        * Referenced by: '<S12>/Constant2'
                                        */
  real_T Constant3_Value_o;            /* Expression: -1
                                        * Referenced by: '<S12>/Constant3'
                                        */
  real_T Constant4_Value_om;           /* Expression: -1
                                        * Referenced by: '<S12>/Constant4'
                                        */
  real_T Constant5_Value;              /* Expression: -1
                                        * Referenced by: '<S12>/Constant5'
                                        */
  real_T Constant6_Value_d;            /* Expression: -1
                                        * Referenced by: '<S12>/Constant6'
                                        */
  real_T Constant7_Value_ny;           /* Expression: -1
                                        * Referenced by: '<S12>/Constant7'
                                        */
  real_T Constant8_Value_lk;           /* Expression: -1
                                        * Referenced by: '<S12>/Constant8'
                                        */
  real_T Constant9_Value_e;            /* Expression: -1
                                        * Referenced by: '<S12>/Constant9'
                                        */
  real_T Constant10_Value_j;           /* Expression: -1
                                        * Referenced by: '<S12>/Constant10'
                                        */
  real_T Constant11_Value_i;           /* Expression: -1
                                        * Referenced by: '<S12>/Constant11'
                                        */
  real_T TransferFcn1_A[2];            /* Computed Parameter: TransferFcn1_A
                                        * Referenced by: '<S48>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C[2];            /* Computed Parameter: TransferFcn1_C
                                        * Referenced by: '<S48>/Transfer Fcn1'
                                        */
  real_T Constant2_Value_bl;           /* Expression: 1
                                        * Referenced by: '<S48>/Constant2'
                                        */
  real_T Constant1_Value_lj;           /* Expression: 0
                                        * Referenced by: '<S37>/Constant1'
                                        */
  real_T Constant2_Value_gj;           /* Expression: 0
                                        * Referenced by: '<S37>/Constant2'
                                        */
  real_T Memory1_1_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S35>/Memory1'
                                        */
  real_T Shaft2degYaw_Gain;            /* Expression: 360/(65536)
                                        * Referenced by: '<S44>/Shaft2degYaw'
                                        */
  real_T TransportDelay_InitOutput;    /* Expression: 0
                                        * Referenced by: '<S175>/Transport Delay'
                                        */
  real_T Memory1_2_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S35>/Memory1'
                                        */
  real_T Shaft2degPitch_Gain;          /* Expression: -360/(65536)
                                        * Referenced by: '<S44>/Shaft2degPitch'
                                        */
  real_T TransportDelay_InitOutput_m;  /* Expression: 0
                                        * Referenced by: '<S173>/Transport Delay'
                                        */
  real_T Memory1_3_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S35>/Memory1'
                                        */
  real_T Shaft2degRoll_Gain;           /* Expression: -360/(65536)
                                        * Referenced by: '<S44>/Shaft2degRoll'
                                        */
  real_T TransportDelay_InitOutput_i;  /* Expression: 0
                                        * Referenced by: '<S174>/Transport Delay'
                                        */
  real_T Constant2_Value_k;            /* Expression: inf
                                        * Referenced by: '<S71>/Constant2'
                                        */
  real_T Switch2_Threshold;            /* Expression: 0
                                        * Referenced by: '<S71>/Switch2'
                                        */
  real_T Gain_Gain_d;                  /* Expression: -1
                                        * Referenced by: '<S71>/Gain'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S71>/Switch1'
                                        */
  real_T Constant_Value_pf;            /* Expression: 0.5
                                        * Referenced by: '<S205>/Constant'
                                        */
  real_T Gain_Gain_m;                  /* Expression: 2
                                        * Referenced by: '<S205>/Gain'
                                        */
  real_T Saturation_UpperSat_g;        /* Expression: 1
                                        * Referenced by: '<S205>/Saturation'
                                        */
  real_T Saturation_LowerSat_k;        /* Expression: -1
                                        * Referenced by: '<S205>/Saturation'
                                        */
  real_T Constant1_Value_jl;           /* Expression: 0.5
                                        * Referenced by: '<S205>/Constant1'
                                        */
  real_T Gain9_Gain_f;                 /* Expression: 1
                                        * Referenced by: '<S194>/Gain9'
                                        */
  real_T rad2deg_Gain;                 /* Expression: 360/(2*pi)
                                        * Referenced by: '<S191>/rad2deg'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S72>/Integrator'
                                        */
  real_T Filter_IC;                    /* Expression: 0
                                        * Referenced by: '<S72>/Filter'
                                        */
  real_T Merge_InitialOutput;         /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S72>/Merge'
                                       */
  real_T Merge_InitialOutput_e;     /* Computed Parameter: Merge_InitialOutput_e
                                     * Referenced by: '<S70>/Merge'
                                     */
  real_T Constant2_Value_gu;           /* Expression: inf
                                        * Referenced by: '<S52>/Constant2'
                                        */
  real_T Switch2_Threshold_a;          /* Expression: 0
                                        * Referenced by: '<S52>/Switch2'
                                        */
  real_T Gain_Gain_ec;                 /* Expression: -1
                                        * Referenced by: '<S52>/Gain'
                                        */
  real_T Switch1_Threshold_a;          /* Expression: 0
                                        * Referenced by: '<S52>/Switch1'
                                        */
  real_T Gain10_Gain_k;                /* Expression: 1
                                        * Referenced by: '<S194>/Gain10'
                                        */
  real_T rad2deg1_Gain;                /* Expression: 360/(2*pi)
                                        * Referenced by: '<S191>/rad2deg1'
                                        */
  real_T Integrator_IC_k;              /* Expression: 0
                                        * Referenced by: '<S53>/Integrator'
                                        */
  real_T Filter_IC_b;                  /* Expression: 0
                                        * Referenced by: '<S53>/Filter'
                                        */
  real_T Merge_InitialOutput_h;     /* Computed Parameter: Merge_InitialOutput_h
                                     * Referenced by: '<S53>/Merge'
                                     */
  real_T Constant2_Value_n;            /* Expression: inf
                                        * Referenced by: '<S61>/Constant2'
                                        */
  real_T Switch2_Threshold_f;          /* Expression: 0
                                        * Referenced by: '<S61>/Switch2'
                                        */
  real_T Gain_Gain_fh;                 /* Expression: -1
                                        * Referenced by: '<S61>/Gain'
                                        */
  real_T Switch1_Threshold_f;          /* Expression: 0
                                        * Referenced by: '<S61>/Switch1'
                                        */
  real_T Gain11_Gain_o;                /* Expression: 1
                                        * Referenced by: '<S194>/Gain11'
                                        */
  real_T rad2deg2_Gain;                /* Expression: 360/(2*pi)
                                        * Referenced by: '<S191>/rad2deg2'
                                        */
  real_T Integrator_IC_j;              /* Expression: 0
                                        * Referenced by: '<S62>/Integrator'
                                        */
  real_T Filter_IC_p;                  /* Expression: 0
                                        * Referenced by: '<S62>/Filter'
                                        */
  real_T Merge_InitialOutput_d;     /* Computed Parameter: Merge_InitialOutput_d
                                     * Referenced by: '<S62>/Merge'
                                     */
  real_T Merge_InitialOutput_g;     /* Computed Parameter: Merge_InitialOutput_g
                                     * Referenced by: '<S44>/Merge'
                                     */
  real_T Merge1_InitialOutput;       /* Computed Parameter: Merge1_InitialOutput
                                      * Referenced by: '<S44>/Merge1'
                                      */
  real_T Shaft2radRoll_Gain;           /* Expression: -(2*pi)/(65536)
                                        * Referenced by: '<S39>/Shaft2radRoll'
                                        */
  real_T Merge2_InitialOutput;       /* Computed Parameter: Merge2_InitialOutput
                                      * Referenced by: '<S44>/Merge2'
                                      */
  real_T Shaft2radPitch_Gain;          /* Expression: -(2*pi)/(65536)
                                        * Referenced by: '<S39>/Shaft2radPitch'
                                        */
  real_T Shaft2radYaw_Gain;            /* Expression: (2*pi)/(65536)
                                        * Referenced by: '<S39>/Shaft2radYaw'
                                        */
  real_T u2_Gain;                      /* Expression: 0.5
                                        * Referenced by: '<S42>/1//2'
                                        */
  real_T Constant_Value_c1;            /* Expression: -1
                                        * Referenced by: '<S40>/Constant'
                                        */
  real_T Constant1_Value_bz;           /* Expression: -1
                                        * Referenced by: '<S40>/Constant1'
                                        */
  real_T Constant2_Value_jr;           /* Expression: -1
                                        * Referenced by: '<S40>/Constant2'
                                        */
  real_T Constant3_Value_h;            /* Expression: -1
                                        * Referenced by: '<S40>/Constant3'
                                        */
  real_T Constant4_Value_c;            /* Expression: -1
                                        * Referenced by: '<S40>/Constant4'
                                        */
  real_T Constant5_Value_j;            /* Expression: -1
                                        * Referenced by: '<S40>/Constant5'
                                        */
  real_T Constant6_Value_k;            /* Expression: -1
                                        * Referenced by: '<S40>/Constant6'
                                        */
  real_T Constant7_Value_o;            /* Expression: -1
                                        * Referenced by: '<S40>/Constant7'
                                        */
  real_T Constant8_Value_kz;           /* Expression: -1
                                        * Referenced by: '<S40>/Constant8'
                                        */
  real_T Constant9_Value_c;            /* Expression: -1
                                        * Referenced by: '<S40>/Constant9'
                                        */
  real_T Constant10_Value_jg;          /* Expression: -1
                                        * Referenced by: '<S40>/Constant10'
                                        */
  real_T Constant11_Value_f;           /* Expression: -1
                                        * Referenced by: '<S40>/Constant11'
                                        */
  real_T Q_1_Value[16];    /* Expression: [0 0 0 1; 0 0 -1 0; 0 1 0 0; -1 0 0 0]
                            * Referenced by: '<S340>/Q~_1'
                            */
  real_T Q_2_Value[16];    /* Expression: [0 0 1 0; 0 0 0 1; -1 0 0 0; 0 -1 0 0]
                            * Referenced by: '<S340>/Q~_2'
                            */
  real_T Q_3_Value[16];    /* Expression: [0 -1 0 0; 1 0 0 0; 0 0 0 1; 0 0 -1 0]
                            * Referenced by: '<S340>/Q~_3'
                            */
  real_T Q_4_Value[16];      /* Expression: [1 0 0 0; 0 1 0 0; 0 0 1 0; 0 0 0 1]
                              * Referenced by: '<S340>/Q~_4'
                              */
  real_T Q_1_Value_i[16];  /* Expression: [0 0 0 1; 0 0 1 0; 0 -1 0 0; -1 0 0 0]
                            * Referenced by: '<S340>/Q_1'
                            */
  real_T Q_2_Value_n[16];  /* Expression: [0 0 -1 0; 0 0 0 1; 1 0 0 0; 0 -1 0 0]
                            * Referenced by: '<S340>/Q_2'
                            */
  real_T Q_3_Value_m[16];  /* Expression: [0 1 0 0; -1 0 0 0; 0 0 0 1; 0 0 -1 0]
                            * Referenced by: '<S340>/Q_3'
                            */
  real_T Q_4_Value_f[16];    /* Expression: [1 0 0 0; 0 1 0 0; 0 0 1 0; 0 0 0 1]
                              * Referenced by: '<S340>/Q_4'
                              */
  real_T Constant_Value_i3;
                         /* Expression: HIL_Data.FDM.soph.bus1.unc_aero_Cx_scale
                          * Referenced by: '<S237>/Constant'
                          */
  real_T Constant8_Value_i[4];       /* Expression: HIL_Data.FDM.soph.bus2.qIE_0
                                      * Referenced by: '<S302>/Constant8'
                                      */
  real_T Gain1_Gain_i;                 /* Expression: 2
                                        * Referenced by: '<S306>/Gain1'
                                        */
  real_T Gain2_Gain_iy;                /* Expression: 2
                                        * Referenced by: '<S306>/Gain2'
                                        */
  real_T Gain9_Gain_g;                 /* Expression: 2
                                        * Referenced by: '<S306>/Gain9'
                                        */
  real_T Gain10_Gain_h;                /* Expression: 2
                                        * Referenced by: '<S306>/Gain10'
                                        */
  real_T Gain7_Gain_i;                 /* Expression: 2
                                        * Referenced by: '<S306>/Gain7'
                                        */
  real_T Gain8_Gain_d;                 /* Expression: 2
                                        * Referenced by: '<S306>/Gain8'
                                        */
  real_T Gain3_Gain_if;                /* Expression: 2
                                        * Referenced by: '<S306>/Gain3'
                                        */
  real_T Gain4_Gain_f;                 /* Expression: 2
                                        * Referenced by: '<S306>/Gain4'
                                        */
  real_T Gain5_Gain_i;                 /* Expression: 2
                                        * Referenced by: '<S306>/Gain5'
                                        */
  real_T Gain6_Gain_n;                 /* Expression: 2
                                        * Referenced by: '<S306>/Gain6'
                                        */
  real_T Gain11_Gain_n;                /* Expression: 2
                                        * Referenced by: '<S306>/Gain11'
                                        */
  real_T Gain12_Gain_h;                /* Expression: 2
                                        * Referenced by: '<S306>/Gain12'
                                        */
  real_T Constant9_Value_p;     /* Expression: HIL_Data.FDM.soph.bus2.flag_I_rot
                                 * Referenced by: '<S301>/Constant9'
                                 */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S301>/Switch'
                                        */
  real_T Q_1_Value_k[16];  /* Expression: [0 0 0 1; 0 0 1 0; 0 -1 0 0; -1 0 0 0]
                            * Referenced by: '<S295>/Q_1'
                            */
  real_T Q_1_Value_d[16];  /* Expression: [0 0 0 1; 0 0 1 0; 0 -1 0 0; -1 0 0 0]
                            * Referenced by: '<S297>/Q_1'
                            */
  real_T Q_2_Value_nt[16]; /* Expression: [0 0 -1 0; 0 0 0 1; 1 0 0 0; 0 -1 0 0]
                            * Referenced by: '<S297>/Q_2'
                            */
  real_T Q_3_Value_o[16];  /* Expression: [0 1 0 0; -1 0 0 0; 0 0 0 1; 0 0 -1 0]
                            * Referenced by: '<S297>/Q_3'
                            */
  real_T Q_4_Value_n[16];    /* Expression: [1 0 0 0; 0 1 0 0; 0 0 1 0; 0 0 0 1]
                              * Referenced by: '<S297>/Q_4'
                              */
  real_T Constant8_Value_oz[4];      /* Expression: HIL_Data.FDM.soph.bus2.qEG_0
                                      * Referenced by: '<S303>/Constant8'
                                      */
  real_T Constant_Value_gc;            /* Expression: 1
                                        * Referenced by: '<S297>/Constant'
                                        */
  real_T Constant1_Value_ja;           /* Expression: -1
                                        * Referenced by: '<S297>/Constant1'
                                        */
  real_T Switch_Threshold_g;           /* Expression: 0
                                        * Referenced by: '<S297>/Switch'
                                        */
  real_T Gain1_Gain_p;                 /* Expression: -1
                                        * Referenced by: '<S294>/Gain1'
                                        */
  real_T Q_2_Value_c[16];  /* Expression: [0 0 -1 0; 0 0 0 1; 1 0 0 0; 0 -1 0 0]
                            * Referenced by: '<S295>/Q_2'
                            */
  real_T Q_3_Value_f[16];  /* Expression: [0 1 0 0; -1 0 0 0; 0 0 0 1; 0 0 -1 0]
                            * Referenced by: '<S295>/Q_3'
                            */
  real_T Q_4_Value_e[16];    /* Expression: [1 0 0 0; 0 1 0 0; 0 0 1 0; 0 0 0 1]
                              * Referenced by: '<S295>/Q_4'
                              */
  real_T Constant_Value_ie;            /* Expression: 1
                                        * Referenced by: '<S295>/Constant'
                                        */
  real_T Constant1_Value_m;            /* Expression: -1
                                        * Referenced by: '<S295>/Constant1'
                                        */
  real_T Switch_Threshold_h;           /* Expression: 0
                                        * Referenced by: '<S295>/Switch'
                                        */
  real_T Gain1_Gain_e;                 /* Expression: 2
                                        * Referenced by: '<S293>/Gain1'
                                        */
  real_T Gain2_Gain_j;                 /* Expression: 2
                                        * Referenced by: '<S293>/Gain2'
                                        */
  real_T Gain9_Gain_m;                 /* Expression: 2
                                        * Referenced by: '<S293>/Gain9'
                                        */
  real_T Gain10_Gain_d;                /* Expression: 2
                                        * Referenced by: '<S293>/Gain10'
                                        */
  real_T Gain7_Gain_h;                 /* Expression: 2
                                        * Referenced by: '<S293>/Gain7'
                                        */
  real_T Gain8_Gain_l;                 /* Expression: 2
                                        * Referenced by: '<S293>/Gain8'
                                        */
  real_T Gain3_Gain_e;                 /* Expression: 2
                                        * Referenced by: '<S293>/Gain3'
                                        */
  real_T Gain4_Gain_c;                 /* Expression: 2
                                        * Referenced by: '<S293>/Gain4'
                                        */
  real_T Gain5_Gain_c;                 /* Expression: 2
                                        * Referenced by: '<S293>/Gain5'
                                        */
  real_T Gain6_Gain_b;                 /* Expression: 2
                                        * Referenced by: '<S293>/Gain6'
                                        */
  real_T Gain11_Gain_g;                /* Expression: 2
                                        * Referenced by: '<S293>/Gain11'
                                        */
  real_T Gain12_Gain_j;                /* Expression: 2
                                        * Referenced by: '<S293>/Gain12'
                                        */
  real_T course_angle_wind_Value;      /* Expression: HIL_Data.FDM.soph.bus2.chW
                                        * Referenced by: '<S353>/course_angle_wind'
                                        */
  real_T course_angle_uncertainty_Value;
                                /* Expression: HIL_Data.FDM.soph.bus1.unc_chW_bl
                                 * Referenced by: '<S353>/course_angle_uncertainty'
                                 */
  real_T vWW_uncertainty_Value;
                             /* Expression: HIL_Data.FDM.soph.bus1.unc_a_vBEW_bl
                              * Referenced by: '<S353>/vWW_uncertainty'
                              */
  real_T vWW_Value;                 /* Expression: HIL_Data.FDM.soph.bus2.a_vBEW
                                     * Referenced by: '<S353>/vWW'
                                     */
  real_T Constant1_Value_fr;           /* Expression: 0
                                        * Referenced by: '<S353>/Constant1'
                                        */
  real_T specific_gas_constant_Value;  /* Expression: HIL_Data.FDM.soph.bus2.sgc
                                        * Referenced by: '<S266>/specific_gas_constant'
                                        */
  real_T heat_capacity_ratio_Value;    /* Expression: HIL_Data.FDM.soph.bus2.hcr
                                        * Referenced by: '<S266>/heat_capacity_ratio'
                                        */
  real_T deviation_Tmp_Value;        /* Expression: HIL_Data.FDM.soph.bus2.e_Tmp
                                      * Referenced by: '<S352>/deviation_Tmp'
                                      */
  real_T Tmp_norm_msl_Value;        /* Expression: HIL_Data.FDM.soph.bus2.c_Tmp0
                                     * Referenced by: '<S267>/Tmp_norm_msl'
                                     */
  real_T Tmp_gradient_tropo_Value;    /* Expression: HIL_Data.FDM.soph.bus2.c_be
                                       * Referenced by: '<S268>/Tmp_gradient_tropo'
                                       */
  real_T Constant_Value_b;           /* Expression: HIL_Data.FDM.soph.bus2.lon_0
                                      * Referenced by: '<S328>/Constant'
                                      */
  real_T Constant2_Value_e5;         /* Expression: HIL_Data.FDM.soph.bus2.lat_0
                                      * Referenced by: '<S328>/Constant2'
                                      */
  real_T Constant1_Value_bt;   /* Expression: HIL_Data.FDM.soph.bus2.flag_I_flat
                                * Referenced by: '<S328>/Constant1'
                                */
  real_T c_rsma_Value_j;               /* Expression: c_rsma
                                        * Referenced by: '<S330>/c_rsma'
                                        */
  real_T Constant_Value_ne;            /* Expression: 1
                                        * Referenced by: '<S332>/Constant'
                                        */
  real_T c_flat_Value_e;               /* Expression: c_flat
                                        * Referenced by: '<S330>/c_flat'
                                        */
  real_T Gain_Gain_le;                 /* Expression: 2
                                        * Referenced by: '<S332>/Gain'
                                        */
  real_T Constant_Value_nr;            /* Expression: 1
                                        * Referenced by: '<S331>/Constant'
                                        */
  real_T Gain_Gain_iy;                 /* Expression: 2
                                        * Referenced by: '<S331>/Gain'
                                        */
  real_T Switch_Threshold_c;           /* Expression: 0
                                        * Referenced by: '<S328>/Switch'
                                        */
  real_T Saturation_UpperSat_h;  /* Expression: HIL_Data.FDM.soph.bus2.c_h_geope
                                  * Referenced by: '<S255>/Saturation'
                                  */
  real_T Saturation_LowerSat_kz; /* Expression: HIL_Data.FDM.soph.bus2.c_h_geop0
                                  * Referenced by: '<S255>/Saturation'
                                  */
  real_T geopotential_height_ref_Value;
                                 /* Expression: HIL_Data.FDM.soph.bus2.c_h_geop0
                                  * Referenced by: '<S267>/geopotential_height_ref'
                                  */
  real_T Prelookup_Mach_BreakpointsData[9];
                                   /* Expression: HIL_Data.FDM.soph.bus1.aero.Ma
                                    * Referenced by: '<S240>/Prelookup_Mach'
                                    */
  real_T Constant_Value_jc[4];         /* Expression: [1; 0; 0; 1]
                                        * Referenced by: '<S346>/Constant'
                                        */
  real_T Gain_Gain_nn;                 /* Expression: 180/pi
                                        * Referenced by: '<S245>/Gain'
                                        */
  real_T Prelookup_alB_BreakpointsData[17];
                                /* Expression: HIL_Data.FDM.soph.bus1.aero.alpha
                                 * Referenced by: '<S240>/Prelookup_alB'
                                 */
  real_T Gain_Gain_kz;                 /* Expression: 180/pi
                                        * Referenced by: '<S246>/Gain'
                                        */
  real_T Prelookup_beB_BreakpointsData[17];
                                 /* Expression: HIL_Data.FDM.soph.bus1.aero.beta
                                  * Referenced by: '<S240>/Prelookup_beB'
                                  */
  real_T Cx_Interpolation_Table[2601];
                                   /* Expression: HIL_Data.FDM.soph.bus1.aero.Cx
                                    * Referenced by: '<S237>/Cx_Interpolation'
                                    */
  real_T Saturation1_UpperSat;         /* Expression: inf
                                        * Referenced by: '<S347>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 100*eps
                                        * Referenced by: '<S347>/Saturation1'
                                        */
  real_T Constant1_Value_is;     /* Expression: HIL_Data.FDM.soph.bus1.aero.lref
                                  * Referenced by: '<S347>/Constant1'
                                  */
  real_T Gain_Gain_b;                  /* Expression: 180/pi
                                        * Referenced by: '<S250>/Gain'
                                        */
  real_T Cxp_Interpolation_Table[2601];
                                  /* Expression: HIL_Data.FDM.soph.bus1.aero.Cxp
                                   * Referenced by: '<S237>/Cxp_Interpolation'
                                   */
  real_T Gain_Gain_hp;                 /* Expression: 180/pi
                                        * Referenced by: '<S251>/Gain'
                                        */
  real_T Cxq_Interpolation_Table[2601];
                                  /* Expression: HIL_Data.FDM.soph.bus1.aero.Cxq
                                   * Referenced by: '<S237>/Cxq_Interpolation'
                                   */
  real_T Gain_Gain_bz;                 /* Expression: 180/pi
                                        * Referenced by: '<S252>/Gain'
                                        */
  real_T Cxr_Interpolation_Table[2601];
                                  /* Expression: HIL_Data.FDM.soph.bus1.aero.Cxr
                                   * Referenced by: '<S237>/Cxr_Interpolation'
                                   */
  real_T Constant8_Value_g2[12];     /* Expression: HIL_Data.FDM.soph.bus1.Tr3r4
                                      * Referenced by: '<S274>/Constant8'
                                      */
  real_T Constant7_Value_dr;          /* Expression: HIL_Data.FDM.soph.bus1.tRRR
                                       * Referenced by: '<S199>/Constant7'
                                       */
  real_T Gain_Gain_aj;                 /* Expression: 180/pi
                                        * Referenced by: '<S247>/Gain'
                                        */
  real_T Cx_delta_l_Interpolation_Table[2601];
                           /* Expression: HIL_Data.FDM.soph.bus1.aero.Cx_delta_l
                            * Referenced by: '<S237>/Cx_delta_l_Interpolation'
                            */
  real_T Gain_Gain_l4;                 /* Expression: 180/pi
                                        * Referenced by: '<S248>/Gain'
                                        */
  real_T Cx_delta_m_Interpolation_Table[2601];
                           /* Expression: HIL_Data.FDM.soph.bus1.aero.Cx_delta_m
                            * Referenced by: '<S237>/Cx_delta_m_Interpolation'
                            */
  real_T Gain_Gain_pr;                 /* Expression: 180/pi
                                        * Referenced by: '<S249>/Gain'
                                        */
  real_T Cx_delta_n_Interpolation_Table[2601];
                           /* Expression: HIL_Data.FDM.soph.bus1.aero.Cx_delta_n
                            * Referenced by: '<S237>/Cx_delta_n_Interpolation'
                            */
  real_T Prelookup_altitude_BreakpointsData[20];
                                /* Expression: HIL_Data.FDM.soph.bus1.aero.hoehe
                                 * Referenced by: '<S237>/Prelookup_altitude'
                                 */
  real_T Cx_alt_Interpolation_Table[3060];
                               /* Expression: HIL_Data.FDM.soph.bus1.aero.Cx_alt
                                * Referenced by: '<S237>/Cx_alt_Interpolation'
                                */
  real_T Constant3_Value_f;            /* Expression: 2
                                        * Referenced by: '<S241>/Constant3'
                                        */
  real_T Gain1_Gain_b;                 /* Expression: pi/180
                                        * Referenced by: '<S242>/Gain1'
                                        */
  real_T Gain1_Gain_e2;                /* Expression: pi/180
                                        * Referenced by: '<S243>/Gain1'
                                        */
  real_T Gain_Gain_if;                 /* Expression: 180/pi
                                        * Referenced by: '<S244>/Gain'
                                        */
  real_T Saturation_UpperSat_f;        /* Expression: inf
                                        * Referenced by: '<S241>/Saturation'
                                        */
  real_T Saturation_LowerSat_g;        /* Expression: 100*eps
                                        * Referenced by: '<S241>/Saturation'
                                        */
  real_T Prelookup_delta_t_BreakpointsData[9];
                              /* Expression: HIL_Data.FDM.soph.bus1.aero.delta_t
                               * Referenced by: '<S237>/Prelookup_delta_t'
                               */
  real_T Cx_delta_t_Interpolation_Table[1377];
                           /* Expression: HIL_Data.FDM.soph.bus1.aero.Cx_delta_t
                            * Referenced by: '<S237>/Cx_delta_t_Interpolation'
                            */
  real_T Cx_base_Interpolation_Table[2601];
                              /* Expression: HIL_Data.FDM.soph.bus1.aero.Cx_base
                               * Referenced by: '<S237>/Cx_base_Interpolation'
                               */
  real_T Constant6_Value_i;     /* Expression: HIL_Data.FDM.soph.bus2.T_sim_lnch
                                 * Referenced by: '<S351>/Constant6'
                                 */
  real_T Constant_Value_ok;    /* Expression: HIL_Data.FDM.soph.bus1.t_prp2(end)
                                * Referenced by: '<S216>/Constant'
                                */
  real_T Constant_Value_oz;
                         /* Expression: HIL_Data.FDM.soph.bus1.unc_aero_Cy_scale
                          * Referenced by: '<S238>/Constant'
                          */
  real_T Cy_Interpolation_Table[2601];
                                   /* Expression: HIL_Data.FDM.soph.bus1.aero.Cy
                                    * Referenced by: '<S238>/Cy_Interpolation'
                                    */
  real_T Cyp_Interpolation_Table[2601];
                                  /* Expression: HIL_Data.FDM.soph.bus1.aero.Cyp
                                   * Referenced by: '<S238>/Cyp_Interpolation'
                                   */
  real_T Cyq_Interpolation_Table[2601];
                                  /* Expression: HIL_Data.FDM.soph.bus1.aero.Cyq
                                   * Referenced by: '<S238>/Cyq_Interpolation'
                                   */
  real_T Cyr_Interpolation_Table[2601];
                                  /* Expression: HIL_Data.FDM.soph.bus1.aero.Cyr
                                   * Referenced by: '<S238>/Cyr_Interpolation'
                                   */
  real_T Cy_delta_l_Interpolation_Table[2601];
                           /* Expression: HIL_Data.FDM.soph.bus1.aero.Cy_delta_l
                            * Referenced by: '<S238>/Cy_delta_l_Interpolation'
                            */
  real_T Cy_delta_m_Interpolation_Table[2601];
                           /* Expression: HIL_Data.FDM.soph.bus1.aero.Cy_delta_m
                            * Referenced by: '<S238>/Cy_delta_m_Interpolation'
                            */
  real_T Cy_delta_n_Interpolation_Table[2601];
                           /* Expression: HIL_Data.FDM.soph.bus1.aero.Cy_delta_n
                            * Referenced by: '<S238>/Cy_delta_n_Interpolation'
                            */
  real_T Constant_Value_gw;
                         /* Expression: HIL_Data.FDM.soph.bus1.unc_aero_Cz_scale
                          * Referenced by: '<S239>/Constant'
                          */
  real_T Cz_Interpolation_Table[2601];
                                   /* Expression: HIL_Data.FDM.soph.bus1.aero.Cz
                                    * Referenced by: '<S239>/Cz_Interpolation'
                                    */
  real_T Czp_Interpolation_Table[2601];
                                  /* Expression: HIL_Data.FDM.soph.bus1.aero.Czp
                                   * Referenced by: '<S239>/Czp_Interpolation'
                                   */
  real_T Czq_Interpolation_Table[2601];
                                  /* Expression: HIL_Data.FDM.soph.bus1.aero.Czq
                                   * Referenced by: '<S239>/Czq_Interpolation'
                                   */
  real_T Czr_Interpolation_Table[2601];
                                  /* Expression: HIL_Data.FDM.soph.bus1.aero.Czr
                                   * Referenced by: '<S239>/Czr_Interpolation'
                                   */
  real_T Cz_delta_l_Interpolation_Table[2601];
                           /* Expression: HIL_Data.FDM.soph.bus1.aero.Cz_delta_l
                            * Referenced by: '<S239>/Cz_delta_l_Interpolation'
                            */
  real_T Cz_delta_m_Interpolation_Table[2601];
                           /* Expression: HIL_Data.FDM.soph.bus1.aero.Cz_delta_m
                            * Referenced by: '<S239>/Cz_delta_m_Interpolation'
                            */
  real_T Cz_delta_n_Interpolation_Table[2601];
                           /* Expression: HIL_Data.FDM.soph.bus1.aero.Cz_delta_n
                            * Referenced by: '<S239>/Cz_delta_n_Interpolation'
                            */
  real_T Constant2_Value_a2;     /* Expression: HIL_Data.FDM.soph.bus1.aero.sref
                                  * Referenced by: '<S218>/Constant2'
                                  */
  real_T Constant_Value_ii;            /* Expression: 0.5
                                        * Referenced by: '<S344>/Constant'
                                        */
  real_T Constant1_Value_mh;           /* Expression: 1
                                        * Referenced by: '<S269>/Constant1'
                                        */
  real_T Tmp_gradient_tropo_Value_l;  /* Expression: HIL_Data.FDM.soph.bus2.c_be
                                       * Referenced by: '<S269>/Tmp_gradient_tropo'
                                       */
  real_T pressure_exponent_Value;     /* Expression: HIL_Data.FDM.soph.bus2.c_pe
                                       * Referenced by: '<S269>/pressure_exponent'
                                       */
  real_T deviation_pa_QFH_Value;      /* Expression: HIL_Data.FDM.soph.bus2.e_pa
                                       * Referenced by: '<S352>/deviation_pa_QFH'
                                       */
  real_T pa_norm_msl_Value;          /* Expression: HIL_Data.FDM.soph.bus2.c_pa0
                                      * Referenced by: '<S267>/pa_norm_msl'
                                      */
  real_T specific_gas_constant_Value_c;/* Expression: HIL_Data.FDM.soph.bus2.sgc
                                        * Referenced by: '<S264>/specific_gas_constant'
                                        */
  real_T Constant1_Value_lx;
                        /* Expression: HIL_Data.FDM.soph.bus2.flag_I_aero_switch
                         * Referenced by: '<S224>/Constant1'
                         */
  real_T Constant_Value_iu[3];      /* Expression: HIL_Data.FDM.soph.bus2.pBII_0
                                     * Referenced by: '<S226>/Constant'
                                     */
  real_T Constant2_Value_o;    /* Expression: HIL_Data.FDM.soph.bus2.flag_I_flat
                                * Referenced by: '<S226>/Constant2'
                                */
  real_T Switch1_Threshold_m;          /* Expression: 0
                                        * Referenced by: '<S226>/Switch1'
                                        */
  real_T Constant3_Value_f4;           /* Expression: 0
                                        * Referenced by: '<S224>/Constant3'
                                        */
  real_T Switch_Threshold_f;           /* Expression: 0.05
                                        * Referenced by: '<S224>/Switch'
                                        */
  real_T Constant1_Value_cj;           /* Expression: 0
                                        * Referenced by: '<S256>/Constant1'
                                        */
  real_T Saturation_UpperSat_d;        /* Expression: inf
                                        * Referenced by: '<S198>/Saturation'
                                        */
  real_T Saturation_LowerSat_j;        /* Expression: eps
                                        * Referenced by: '<S198>/Saturation'
                                        */
  real_T a3_Value;                     /* Expression: 1
                                        * Referenced by: '<S262>/a3'
                                        */
  real_T a2_Value;                     /* Expression: 2
                                        * Referenced by: '<S263>/a2'
                                        */
  real_T WGS84SemiminorAxism_Value;    /* Expression: c_b_WGS
                                        * Referenced by: '<S262>/WGS84 Semi-minor Axis, [m]'
                                        */
  real_T WGS84SemimajorAxism_Value;    /* Expression: c_rsma
                                        * Referenced by: '<S262>/WGS84 Semi-major Axis, [m]'
                                        */
  real_T Constant_Value_ov;            /* Expression: 1
                                        * Referenced by: '<S260>/Constant'
                                        */
  real_T Constant1_Value_mm;
                     /* Expression: HIL_Data.FDM.soph.bus2.flag_I_gravity_switch
                      * Referenced by: '<S283>/Constant1'
                      */
  real_T Constant_Value_g4[3];      /* Expression: HIL_Data.FDM.soph.bus2.pBII_0
                                     * Referenced by: '<S284>/Constant'
                                     */
  real_T Constant2_Value_id;   /* Expression: HIL_Data.FDM.soph.bus2.flag_I_flat
                                * Referenced by: '<S284>/Constant2'
                                */
  real_T Switch1_Threshold_d;          /* Expression: 0
                                        * Referenced by: '<S284>/Switch1'
                                        */
  real_T Constant3_Value_j;            /* Expression: 0
                                        * Referenced by: '<S283>/Constant3'
                                        */
  real_T Switch_Threshold_gn;          /* Expression: 0.05
                                        * Referenced by: '<S283>/Switch'
                                        */
  real_T Constant_Value_bs;      /* Expression: HIL_Data.FDM.soph.bus1.unc_mB_bl
                                  * Referenced by: '<S362>/Constant'
                                  */
  real_T Constant1_Value_iw;          /* Expression: HIL_Data.FDM.soph.bus1.mB_0
                                       * Referenced by: '<S361>/Constant1'
                                       */
  real_T Constant_Value_k;             /* Expression: 0
                                        * Referenced by: '<S361>/Constant'
                                        */
  real_T Switch_Threshold_fo;          /* Expression: 0
                                        * Referenced by: '<S361>/Switch'
                                        */
  real_T Switch1_Threshold_fz;         /* Expression: 0
                                        * Referenced by: '<S361>/Switch1'
                                        */
  real_T Constant2_Value_p;           /* Expression: HIL_Data.FDM.soph.bus1.mM_0
                                       * Referenced by: '<S361>/Constant2'
                                       */
  real_T Constant1_Value_mo;  /* Expression: HIL_Data.FDM.soph.bus1.unc_mB_scale
                               * Referenced by: '<S362>/Constant1'
                               */
  real_T thrust_rot_x_Value;     /* Expression: HIL_Data.FDM.soph.bus1.unc_prp_x
                                  * Referenced by: '<S314>/thrust_rot_x'
                                  */
  real_T thrust_rot_y_Value;     /* Expression: HIL_Data.FDM.soph.bus1.unc_prp_y
                                  * Referenced by: '<S314>/thrust_rot_y'
                                  */
  real_T Thrust_rot_z_Value;     /* Expression: HIL_Data.FDM.soph.bus1.unc_prp_z
                                  * Referenced by: '<S314>/Thrust_rot_z'
                                  */
  real_T Constant_Value_a0;            /* Expression: 0
                                        * Referenced by: '<S313>/Constant'
                                        */
  real_T Switch_Threshold_n;           /* Expression: 0
                                        * Referenced by: '<S313>/Switch'
                                        */
  real_T Switch1_Threshold_a2;         /* Expression: 0
                                        * Referenced by: '<S313>/Switch1'
                                        */
  real_T Constant1_Value_h;            /* Expression: 0
                                        * Referenced by: '<S313>/Constant1'
                                        */
  real_T uncert_thrust_Value;/* Expression: HIL_Data.FDM.soph.bus1.unc_prp_scale
                              * Referenced by: '<S314>/uncert_thrust'
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
                                        * Referenced by: '<S333>/Switch'
                                        */
  real_T Saturation_UpperSat_m;        /* Expression: Inf
                                        * Referenced by: '<S336>/Saturation'
                                        */
  real_T Saturation_LowerSat_a;        /* Expression: 1e-6
                                        * Referenced by: '<S336>/Saturation'
                                        */
  real_T Constant_Value_eq;            /* Expression: 0
                                        * Referenced by: '<S340>/Constant'
                                        */
  real_T Gain3_Gain_df;                /* Expression: 1
                                        * Referenced by: '<S194>/Gain3'
                                        */
  real_T Gain4_Gain_g;                 /* Expression: 1
                                        * Referenced by: '<S194>/Gain4'
                                        */
  real_T Gain5_Gain_n;                 /* Expression: 1
                                        * Referenced by: '<S194>/Gain5'
                                        */
  real_T Gain6_Gain_a;                 /* Expression: 1
                                        * Referenced by: '<S194>/Gain6'
                                        */
  real_T Gain7_Gain_ia;                /* Expression: 1
                                        * Referenced by: '<S194>/Gain7'
                                        */
  real_T Gain8_Gain_l1;                /* Expression: 1
                                        * Referenced by: '<S194>/Gain8'
                                        */
  real_T Gain23_Gain;                  /* Expression: 1
                                        * Referenced by: '<S194>/Gain23'
                                        */
  real_T Gain24_Gain;                  /* Expression: 1
                                        * Referenced by: '<S194>/Gain24'
                                        */
  real_T Gain25_Gain;                  /* Expression: 1
                                        * Referenced by: '<S194>/Gain25'
                                        */
  real_T u2_Gain_f;                    /* Expression: 0.5
                                        * Referenced by: '<S210>/1//2'
                                        */
  real_T Constant5_Value_k;            /* Expression: -1
                                        * Referenced by: '<S193>/Constant5'
                                        */
  real_T Gain12_Gain_b;                /* Expression: 1
                                        * Referenced by: '<S194>/Gain12'
                                        */
  real_T Constant4_Value_d;            /* Expression: -1
                                        * Referenced by: '<S193>/Constant4'
                                        */
  real_T Gain13_Gain;                  /* Expression: 1
                                        * Referenced by: '<S194>/Gain13'
                                        */
  real_T Gain14_Gain;                  /* Expression: 1
                                        * Referenced by: '<S194>/Gain14'
                                        */
  real_T Gain15_Gain;                  /* Expression: 1
                                        * Referenced by: '<S194>/Gain15'
                                        */
  real_T Gain16_Gain;                  /* Expression: 1
                                        * Referenced by: '<S194>/Gain16'
                                        */
  real_T Constant7_Value_l;            /* Expression: -1
                                        * Referenced by: '<S193>/Constant7'
                                        */
  real_T Gain18_Gain;                  /* Expression: 1
                                        * Referenced by: '<S194>/Gain18'
                                        */
  real_T Gain22_Gain;                  /* Expression: 1
                                        * Referenced by: '<S194>/Gain22'
                                        */
  real_T Constant3_Value_i;            /* Expression: -1
                                        * Referenced by: '<S193>/Constant3'
                                        */
  real_T Gain19_Gain;                  /* Expression: 1
                                        * Referenced by: '<S194>/Gain19'
                                        */
  real_T Constant2_Value_pm;           /* Expression: -1
                                        * Referenced by: '<S193>/Constant2'
                                        */
  real_T Gain20_Gain;                  /* Expression: 1
                                        * Referenced by: '<S194>/Gain20'
                                        */
  real_T Constant1_Value_ay;           /* Expression: -1
                                        * Referenced by: '<S193>/Constant1'
                                        */
  real_T Gain21_Gain;                  /* Expression: 1
                                        * Referenced by: '<S194>/Gain21'
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
                                        * Referenced by: '<S19>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Period;   /* Computed Parameter: PulseGenerator1_Period
                                    * Referenced by: '<S19>/Pulse Generator1'
                                    */
  real_T PulseGenerator1_Duty;       /* Computed Parameter: PulseGenerator1_Duty
                                      * Referenced by: '<S19>/Pulse Generator1'
                                      */
  real_T PulseGenerator1_PhaseDelay;
  /* Expression: External_Inputs.FCC.CMD.roll.pulse.delay_s+External_Inputs.FCC.CMD.roll.pulse.period_s
   * Referenced by: '<S19>/Pulse Generator1'
   */
  real_T PulseGenerator_Period;     /* Computed Parameter: PulseGenerator_Period
                                     * Referenced by: '<S19>/Pulse Generator'
                                     */
  real_T PulseGenerator_Duty;         /* Computed Parameter: PulseGenerator_Duty
                                       * Referenced by: '<S19>/Pulse Generator'
                                       */
  real_T PulseGenerator_PhaseDelay;
                       /* Expression: External_Inputs.FCC.CMD.roll.pulse.delay_s
                        * Referenced by: '<S19>/Pulse Generator'
                        */
  real_T Switch1_Threshold_mq;         /* Expression: 0
                                        * Referenced by: '<S19>/Switch1'
                                        */
  real_T PulseGenerator4_Amp;          /* Expression: -2
                                        * Referenced by: '<S19>/Pulse Generator4'
                                        */
  real_T PulseGenerator4_Period;   /* Computed Parameter: PulseGenerator4_Period
                                    * Referenced by: '<S19>/Pulse Generator4'
                                    */
  real_T PulseGenerator4_Duty;       /* Computed Parameter: PulseGenerator4_Duty
                                      * Referenced by: '<S19>/Pulse Generator4'
                                      */
  real_T PulseGenerator4_PhaseDelay;
  /* Expression: External_Inputs.FCC.CMD.pitch.pulse.delay_s+External_Inputs.FCC.CMD.pitch.pulse.period_s
   * Referenced by: '<S19>/Pulse Generator4'
   */
  real_T PulseGenerator3_Period;   /* Computed Parameter: PulseGenerator3_Period
                                    * Referenced by: '<S19>/Pulse Generator3'
                                    */
  real_T PulseGenerator3_Duty;       /* Computed Parameter: PulseGenerator3_Duty
                                      * Referenced by: '<S19>/Pulse Generator3'
                                      */
  real_T PulseGenerator3_PhaseDelay;
                      /* Expression: External_Inputs.FCC.CMD.pitch.pulse.delay_s
                       * Referenced by: '<S19>/Pulse Generator3'
                       */
  real_T Switch_Threshold_p;           /* Expression: 0
                                        * Referenced by: '<S19>/Switch'
                                        */
  real_T PulseGenerator7_Amp;          /* Expression: -2
                                        * Referenced by: '<S19>/Pulse Generator7'
                                        */
  real_T PulseGenerator7_Period;   /* Computed Parameter: PulseGenerator7_Period
                                    * Referenced by: '<S19>/Pulse Generator7'
                                    */
  real_T PulseGenerator7_Duty;       /* Computed Parameter: PulseGenerator7_Duty
                                      * Referenced by: '<S19>/Pulse Generator7'
                                      */
  real_T PulseGenerator7_PhaseDelay;
  /* Expression: External_Inputs.FCC.CMD.yaw.pulse.delay_s+External_Inputs.FCC.CMD.yaw.pulse.period_s
   * Referenced by: '<S19>/Pulse Generator7'
   */
  real_T PulseGenerator6_Period;   /* Computed Parameter: PulseGenerator6_Period
                                    * Referenced by: '<S19>/Pulse Generator6'
                                    */
  real_T PulseGenerator6_Duty;       /* Computed Parameter: PulseGenerator6_Duty
                                      * Referenced by: '<S19>/Pulse Generator6'
                                      */
  real_T PulseGenerator6_PhaseDelay;
                        /* Expression: External_Inputs.FCC.CMD.yaw.pulse.delay_s
                         * Referenced by: '<S19>/Pulse Generator6'
                         */
  real_T Switch2_Threshold_e;          /* Expression: 0
                                        * Referenced by: '<S19>/Switch2'
                                        */
  real_T Constant1_Value_bx;           /* Expression: 1
                                        * Referenced by: '<S28>/Constant1'
                                        */
  real_T Constant10_Value_ly;
                /* Expression: HIL_Data.Simulation_Ctrl.Com_Ctrl.Pix.Com_freq_Hz
                 * Referenced by: '<S8>/Constant10'
                 */
  real_T Constant2_Value_d1;           /* Expression: 1
                                        * Referenced by: '<S28>/Constant2'
                                        */
  real_T Memory_InitialCondition;      /* Expression: -1
                                        * Referenced by: '<S28>/Memory'
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
  real_T Gain1_Gain_j2;                /* Expression: 0
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T SineWave_Amp_o;               /* Expression: 5
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Bias_j;              /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Freq_d;              /* Expression: 10
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Phase;               /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T Gain2_Gain_i2;                /* Expression: 0
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T Constant_Value_oe;            /* Expression: 0
                                        * Referenced by: '<S38>/Constant'
                                        */
  real_T Constant7_Value_e;
          /* Expression: HIL_Data.Simulation_Ctrl.HW_Ctrl.enable_gimbal_ctrl_flg
           * Referenced by: '<S8>/Constant7'
           */
  real_T Gain_Gain_ez;                 /* Expression: 1
                                        * Referenced by: '<S43>/Gain'
                                        */
  real_T Constant_Value_b5;            /* Expression: 1
                                        * Referenced by: '<S175>/Constant'
                                        */
  real_T Constant_Value_mt;            /* Expression: 1
                                        * Referenced by: '<S173>/Constant'
                                        */
  real_T Constant_Value_ds;            /* Expression: 1
                                        * Referenced by: '<S174>/Constant'
                                        */
  real_T Constant1_Value_ljg;
                          /* Expression: HIL_Data.FDM.soph.bus1.unc_fin_def_roll
                           * Referenced by: '<S196>/Constant1'
                           */
  real_T Constant2_Value_ff;
                         /* Expression: HIL_Data.FDM.soph.bus1.unc_fin_def_pitch
                          * Referenced by: '<S196>/Constant2'
                          */
  real_T Constant3_Value_i5;
                           /* Expression: HIL_Data.FDM.soph.bus1.unc_fin_def_yaw
                            * Referenced by: '<S196>/Constant3'
                            */
  real_T Gain1_Gain_ps;                /* Expression: pi/180
                                        * Referenced by: '<S211>/Gain1'
                                        */
  real_T Gain1_Gain_n3;                /* Expression: pi/180
                                        * Referenced by: '<S212>/Gain1'
                                        */
  real_T Gain1_Gain_g;                 /* Expression: pi/180
                                        * Referenced by: '<S213>/Gain1'
                                        */
  real_T Constant7_Value_aa[12];     /* Expression: HIL_Data.FDM.soph.bus1.Tr4r3
                                      * Referenced by: '<S214>/Constant7'
                                      */
  real_T Constant_Value_e0;
                         /* Expression: HIL_Data.FDM.soph.bus1.unc_aero_Cl_scale
                          * Referenced by: '<S234>/Constant'
                          */
  real_T Constant_Value_jm;
                         /* Expression: HIL_Data.FDM.soph.bus1.unc_aero_Cm_scale
                          * Referenced by: '<S235>/Constant'
                          */
  real_T Constant_Value_ml;
                         /* Expression: HIL_Data.FDM.soph.bus1.unc_aero_Cn_scale
                          * Referenced by: '<S236>/Constant'
                          */
  real_T Constant4_Value_p;           /* Expression: HIL_Data.FDM.soph.bus1.xMPB
                                       * Referenced by: '<S359>/Constant4'
                                       */
  real_T Constant_Value_l1;            /* Expression: HIL_Data.FDM.soph.bus1.m0
                                        * Referenced by: '<S359>/Constant'
                                        */
  real_T Constant6_Value_d5;          /* Expression: HIL_Data.FDM.soph.bus1.x0PB
                                       * Referenced by: '<S359>/Constant6'
                                       */
  real_T Constant3_Value_fn;      /* Expression: HIL_Data.FDM.soph.bus1.unc_cg_x
                                   * Referenced by: '<S359>/Constant3'
                                   */
  real_T Constant7_Value_jc;          /* Expression: HIL_Data.FDM.soph.bus1.yMPB
                                       * Referenced by: '<S359>/Constant7'
                                       */
  real_T Constant5_Value_e;           /* Expression: HIL_Data.FDM.soph.bus1.y0PB
                                       * Referenced by: '<S359>/Constant5'
                                       */
  real_T Constant1_Value_in;      /* Expression: HIL_Data.FDM.soph.bus1.unc_cg_y
                                   * Referenced by: '<S359>/Constant1'
                                   */
  real_T Constant9_Value_cx;          /* Expression: HIL_Data.FDM.soph.bus1.zMPB
                                       * Referenced by: '<S359>/Constant9'
                                       */
  real_T Constant8_Value_l5;          /* Expression: HIL_Data.FDM.soph.bus1.z0PB
                                       * Referenced by: '<S359>/Constant8'
                                       */
  real_T Constant2_Value_mg;      /* Expression: HIL_Data.FDM.soph.bus1.unc_cg_z
                                   * Referenced by: '<S359>/Constant2'
                                   */
  real_T Constant1_Value_bk;     /* Expression: HIL_Data.FDM.soph.bus1.aero.lref
                                  * Referenced by: '<S218>/Constant1'
                                  */
  real_T Constant3_Value_m;            /* Expression: 0
                                        * Referenced by: '<S225>/Constant3'
                                        */
  real_T Constant1_Value_p;
                        /* Expression: HIL_Data.FDM.soph.bus2.flag_I_aero_switch
                         * Referenced by: '<S225>/Constant1'
                         */
  real_T Constant_Value_iee[3];     /* Expression: HIL_Data.FDM.soph.bus2.pBII_0
                                     * Referenced by: '<S230>/Constant'
                                     */
  real_T Constant2_Value_ad;   /* Expression: HIL_Data.FDM.soph.bus2.flag_I_flat
                                * Referenced by: '<S230>/Constant2'
                                */
  real_T Switch1_Threshold_n;          /* Expression: 0
                                        * Referenced by: '<S230>/Switch1'
                                        */
  real_T Switch_Threshold_j0;          /* Expression: 0.05
                                        * Referenced by: '<S225>/Switch'
                                        */
  real_T Gain_Gain_oz;                 /* Expression: omega^2
                                        * Referenced by: '<S270>/Gain'
                                        */
  real_T Gain_Gain_a3;                 /* Expression: omega^2
                                        * Referenced by: '<S271>/Gain'
                                        */
  real_T Gain_Gain_hm;                 /* Expression: omega^2
                                        * Referenced by: '<S272>/Gain'
                                        */
  real_T Gain_Gain_do;                 /* Expression: omega^2
                                        * Referenced by: '<S273>/Gain'
                                        */
  real_T pNPB_Value[3];               /* Expression: HIL_Data.FDM.soph.bus1.pNPB
                                       * Referenced by: '<S314>/pNPB'
                                       */
  real_T Q_1_Value_e[16];  /* Expression: [0 0 0 1; 0 0 1 0; 0 -1 0 0; -1 0 0 0]
                            * Referenced by: '<S296>/Q_1'
                            */
  real_T Q_2_Value_l[16];  /* Expression: [0 0 -1 0; 0 0 0 1; 1 0 0 0; 0 -1 0 0]
                            * Referenced by: '<S296>/Q_2'
                            */
  real_T Q_3_Value_o5[16]; /* Expression: [0 1 0 0; -1 0 0 0; 0 0 0 1; 0 0 -1 0]
                            * Referenced by: '<S296>/Q_3'
                            */
  real_T Q_4_Value_nu[16];   /* Expression: [1 0 0 0; 0 1 0 0; 0 0 1 0; 0 0 0 1]
                              * Referenced by: '<S296>/Q_4'
                              */
  real_T Constant_Value_ek0;           /* Expression: 1
                                        * Referenced by: '<S296>/Constant'
                                        */
  real_T Constant1_Value_ll;           /* Expression: -1
                                        * Referenced by: '<S296>/Constant1'
                                        */
  real_T Switch_Threshold_k;           /* Expression: 0
                                        * Referenced by: '<S296>/Switch'
                                        */
  real_T Gain1_Gain_b2;                /* Expression: 2
                                        * Referenced by: '<S291>/Gain1'
                                        */
  real_T Gain2_Gain_iv;                /* Expression: 2
                                        * Referenced by: '<S291>/Gain2'
                                        */
  real_T Gain3_Gain_a;                 /* Expression: 2
                                        * Referenced by: '<S291>/Gain3'
                                        */
  real_T Gain4_Gain_cb;                /* Expression: 2
                                        * Referenced by: '<S291>/Gain4'
                                        */
  real_T Gain5_Gain_k;                 /* Expression: 2
                                        * Referenced by: '<S291>/Gain5'
                                        */
  real_T Gain6_Gain_g;                 /* Expression: 2
                                        * Referenced by: '<S291>/Gain6'
                                        */
  real_T Gain7_Gain_k;                 /* Expression: 2
                                        * Referenced by: '<S291>/Gain7'
                                        */
  real_T Gain8_Gain_e;                 /* Expression: 2
                                        * Referenced by: '<S291>/Gain8'
                                        */
  real_T Gain9_Gain_i;                 /* Expression: 2
                                        * Referenced by: '<S291>/Gain9'
                                        */
  real_T Gain10_Gain_j;                /* Expression: 2
                                        * Referenced by: '<S291>/Gain10'
                                        */
  real_T Gain11_Gain_i;                /* Expression: 2
                                        * Referenced by: '<S291>/Gain11'
                                        */
  real_T Gain12_Gain_h5;               /* Expression: 2
                                        * Referenced by: '<S291>/Gain12'
                                        */
  real_T Gain_Gain_jo;                 /* Expression: -1
                                        * Referenced by: '<S290>/Gain'
                                        */
  real_T Q_1_Value_o[16];  /* Expression: [0 0 0 1; 0 0 1 0; 0 -1 0 0; -1 0 0 0]
                            * Referenced by: '<S305>/Q_1'
                            */
  real_T Constant8_Value_h;            /* Expression: 0
                                        * Referenced by: '<S305>/Constant8'
                                        */
  real_T Q_2_Value_b[16];  /* Expression: [0 0 -1 0; 0 0 0 1; 1 0 0 0; 0 -1 0 0]
                            * Referenced by: '<S305>/Q_2'
                            */
  real_T Q_3_Value_j[16];  /* Expression: [0 1 0 0; -1 0 0 0; 0 0 0 1; 0 0 -1 0]
                            * Referenced by: '<S305>/Q_3'
                            */
  real_T Q_4_Value_d[16];    /* Expression: [1 0 0 0; 0 1 0 0; 0 0 1 0; 0 0 0 1]
                              * Referenced by: '<S305>/Q_4'
                              */
  real_T Gain1_Gain_c5;                /* Expression: -1
                                        * Referenced by: '<S307>/Gain1'
                                        */
  real_T Gain_Gain_e4;                 /* Expression: 0.5
                                        * Referenced by: '<S305>/Gain'
                                        */
  real_T Gain1_Gain_in;                /* Expression: -1
                                        * Referenced by: '<S308>/Gain1'
                                        */
  real_T Constant8_Value_ck;           /* Expression: 0
                                        * Referenced by: '<S304>/Constant8'
                                        */
  real_T Constant9_Value_l;    /* Expression: HIL_Data.FDM.soph.bus2.flag_I_flat
                                * Referenced by: '<S304>/Constant9'
                                */
  real_T Switch_Threshold_m;           /* Expression: 0
                                        * Referenced by: '<S304>/Switch'
                                        */
  real_T Gain1_Gain_k;                 /* Expression: -1
                                        * Referenced by: '<S290>/Gain1'
                                        */
  real_T Q_1_Value_h[16];  /* Expression: [0 0 0 1; 0 0 1 0; 0 -1 0 0; -1 0 0 0]
                            * Referenced by: '<S309>/Q_1'
                            */
  real_T Constant8_Value_p;            /* Expression: 0
                                        * Referenced by: '<S309>/Constant8'
                                        */
  real_T Q_2_Value_g[16];  /* Expression: [0 0 -1 0; 0 0 0 1; 1 0 0 0; 0 -1 0 0]
                            * Referenced by: '<S309>/Q_2'
                            */
  real_T Q_3_Value_oc[16]; /* Expression: [0 1 0 0; -1 0 0 0; 0 0 0 1; 0 0 -1 0]
                            * Referenced by: '<S309>/Q_3'
                            */
  real_T Q_4_Value_ea[16];   /* Expression: [1 0 0 0; 0 1 0 0; 0 0 1 0; 0 0 0 1]
                              * Referenced by: '<S309>/Q_4'
                              */
  real_T Gain1_Gain_a;                 /* Expression: -1
                                        * Referenced by: '<S311>/Gain1'
                                        */
  real_T Gain_Gain_ba;                 /* Expression: 0.5
                                        * Referenced by: '<S309>/Gain'
                                        */
  real_T Gain1_Gain_mc;                /* Expression: -1
                                        * Referenced by: '<S312>/Gain1'
                                        */
  real_T Gain1_Gain_at;                /* Expression: 2
                                        * Referenced by: '<S310>/Gain1'
                                        */
  real_T Gain2_Gain_m;                 /* Expression: 2
                                        * Referenced by: '<S310>/Gain2'
                                        */
  real_T Gain3_Gain_f;                 /* Expression: 2
                                        * Referenced by: '<S310>/Gain3'
                                        */
  real_T Gain4_Gain_n;                 /* Expression: 2
                                        * Referenced by: '<S310>/Gain4'
                                        */
  real_T Gain5_Gain_n4;                /* Expression: 2
                                        * Referenced by: '<S310>/Gain5'
                                        */
  real_T Gain6_Gain_f;                 /* Expression: 2
                                        * Referenced by: '<S310>/Gain6'
                                        */
  real_T Gain7_Gain_j;                 /* Expression: 2
                                        * Referenced by: '<S310>/Gain7'
                                        */
  real_T Gain8_Gain_eu;                /* Expression: 2
                                        * Referenced by: '<S310>/Gain8'
                                        */
  real_T Gain9_Gain_gr;                /* Expression: 2
                                        * Referenced by: '<S310>/Gain9'
                                        */
  real_T Gain10_Gain_j0;               /* Expression: 2
                                        * Referenced by: '<S310>/Gain10'
                                        */
  real_T Gain11_Gain_nh;               /* Expression: 2
                                        * Referenced by: '<S310>/Gain11'
                                        */
  real_T Gain12_Gain_c;                /* Expression: 2
                                        * Referenced by: '<S310>/Gain12'
                                        */
  real_T Constant_Value_j3;            /* Expression: 0.5
                                        * Referenced by: '<S329>/Constant'
                                        */
  real_T Constant1_Value_ot;           /* Expression: 0.5
                                        * Referenced by: '<S329>/Constant1'
                                        */
  real_T Gain_Gain_pu;                 /* Expression: 2
                                        * Referenced by: '<S329>/Gain'
                                        */
  real_T Saturation_UpperSat_f4;       /* Expression: 1
                                        * Referenced by: '<S329>/Saturation'
                                        */
  real_T Saturation_LowerSat_l;        /* Expression: -1
                                        * Referenced by: '<S329>/Saturation'
                                        */
  real_T Constant9_Value_cv[9];        /* Expression: [0 0 0; 0 0 0; 0 0 0]
                                        * Referenced by: '<S327>/Constant9'
                                        */
  real_T Q_1_Value_f[16];  /* Expression: [0 0 0 1; 0 0 1 0; 0 -1 0 0; -1 0 0 0]
                            * Referenced by: '<S338>/Q_1'
                            */
  real_T Constant_Value_lp;            /* Expression: 0
                                        * Referenced by: '<S338>/Constant'
                                        */
  real_T Q_2_Value_n1[16]; /* Expression: [0 0 -1 0; 0 0 0 1; 1 0 0 0; 0 -1 0 0]
                            * Referenced by: '<S338>/Q_2'
                            */
  real_T Q_3_Value_a[16];  /* Expression: [0 1 0 0; -1 0 0 0; 0 0 0 1; 0 0 -1 0]
                            * Referenced by: '<S338>/Q_3'
                            */
  real_T Q_4_Value_b[16];    /* Expression: [1 0 0 0; 0 1 0 0; 0 0 1 0; 0 0 0 1]
                              * Referenced by: '<S338>/Q_4'
                              */
  real_T Gain1_Gain_o;                 /* Expression: -1
                                        * Referenced by: '<S341>/Gain1'
                                        */
  real_T Gain_Gain_pq;                 /* Expression: 0.5
                                        * Referenced by: '<S338>/Gain'
                                        */
  real_T Gain1_Gain_jq;                /* Expression: -1
                                        * Referenced by: '<S342>/Gain1'
                                        */
  real_T Constant15_Value[9];       /* Expression: HIL_Data.FDM.soph.bus1.J0PB_e
                                     * Referenced by: '<S363>/Constant15'
                                     */
  real_T Constant_Value_bk;           /* Expression: HIL_Data.FDM.soph.bus1.mB_0
                                       * Referenced by: '<S368>/Constant'
                                       */
  real_T Constant17_Value[3];         /* Expression: HIL_Data.FDM.soph.bus1.p0PB
                                       * Referenced by: '<S368>/Constant17'
                                       */
  real_T Gain_Gain_ky;                 /* Expression: -1
                                        * Referenced by: '<S380>/Gain'
                                        */
  real_T Gain1_Gain_oe;                /* Expression: -1
                                        * Referenced by: '<S380>/Gain1'
                                        */
  real_T Gain3_Gain_c;                 /* Expression: -1
                                        * Referenced by: '<S380>/Gain3'
                                        */
  real_T Constant16_Value[3];         /* Expression: HIL_Data.FDM.soph.bus1.pMPB
                                       * Referenced by: '<S369>/Constant16'
                                       */
  real_T Gain_Gain_lt;                 /* Expression: -1
                                        * Referenced by: '<S381>/Gain'
                                        */
  real_T Gain1_Gain_iq;                /* Expression: -1
                                        * Referenced by: '<S381>/Gain1'
                                        */
  real_T Gain3_Gain_fm;                /* Expression: -1
                                        * Referenced by: '<S381>/Gain3'
                                        */
  real_T thrust_rot_x_Value_b;   /* Expression: HIL_Data.FDM.soph.bus1.unc_prp_x
                                  * Referenced by: '<S366>/thrust_rot_x'
                                  */
  real_T thrust_rot_y_Value_j;   /* Expression: HIL_Data.FDM.soph.bus1.unc_prp_y
                                  * Referenced by: '<S366>/thrust_rot_y'
                                  */
  real_T Thrust_rot_z_Value_l;   /* Expression: HIL_Data.FDM.soph.bus1.unc_prp_z
                                  * Referenced by: '<S366>/Thrust_rot_z'
                                  */
  real_T Constant21_Value[9];       /* Expression: HIL_Data.FDM.soph.bus1.JMMM_0
                                     * Referenced by: '<S365>/Constant21'
                                     */
  real_T Constant20_Value;            /* Expression: HIL_Data.FDM.soph.bus1.mM_0
                                       * Referenced by: '<S365>/Constant20'
                                       */
  real_T Constant17_Value_j[9];     /* Expression: HIL_Data.FDM.soph.bus1.JMMM_e
                                     * Referenced by: '<S365>/Constant17'
                                     */
  real_T Constant16_Value_i[9];     /* Expression: HIL_Data.FDM.soph.bus1.JMMM_0
                                     * Referenced by: '<S365>/Constant16'
                                     */
  real_T Constant19_Value;            /* Expression: HIL_Data.FDM.soph.bus1.mM_e
                                       * Referenced by: '<S365>/Constant19'
                                       */
  real_T Constant18_Value;            /* Expression: HIL_Data.FDM.soph.bus1.mM_0
                                       * Referenced by: '<S365>/Constant18'
                                       */
  real_T Constant16_Value_c[9];
  /* Expression: [HIL_Data.FDM.soph.bus1.unc_moi_Jxx,0,0;0,HIL_Data.FDM.soph.bus1.unc_moi_Jyy,0;0,0,HIL_Data.FDM.soph.bus1.unc_moi_Jzz]
   * Referenced by: '<S367>/Constant16'
   */
  real_T Constant_Value_et;     /* Expression: HIL_Data.FDM.soph.bus1.de_JBBB_zz
                                 * Referenced by: '<S360>/Constant'
                                 */
  real_T Constant1_Value_lm;    /* Expression: HIL_Data.FDM.soph.bus1.de_JBBB_xx
                                 * Referenced by: '<S360>/Constant1'
                                 */
  real_T Constant2_Value_j2;    /* Expression: HIL_Data.FDM.soph.bus1.de_JBBB_yy
                                 * Referenced by: '<S360>/Constant2'
                                 */
  real_T Constant5_Value_p;          /* Expression: HIL_Data.FDM.soph.bus1.de_mM
                                      * Referenced by: '<S360>/Constant5'
                                      */
  real_T Constant6_Value_l;            /* Expression: 0
                                        * Referenced by: '<S364>/Constant6'
                                        */
  real_T Constant_Value_ep[3];         /* Expression: [0;0;9.81]
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Constant1_Value_i0[3];        /* Expression: [0,0,0]
                                        * Referenced by: '<S10>/Constant1'
                                        */
  real_T IntegratorSecondOrderLimited_ICX;/* Expression: 0
                                           * Referenced by: '<S399>/Integrator, Second-Order Limited'
                                           */
  real_T IntegratorSecondOrderLimited_ICDXDT;/* Expression: 0
                                              * Referenced by: '<S399>/Integrator, Second-Order Limited'
                                              */
  real_T ZeroOrderHold1_Gain;          /* Expression: 1
                                        * Referenced by: '<S392>/Zero-Order Hold1'
                                        */
  real_T ZeroOrderHold2_Gain;          /* Expression: 1
                                        * Referenced by: '<S392>/Zero-Order Hold2'
                                        */
  real_T ZeroOrderHold_Gain;           /* Expression: 1
                                        * Referenced by: '<S392>/Zero-Order Hold'
                                        */
  real_T ZeroOrderHold4_Gain;          /* Expression: 1
                                        * Referenced by: '<S392>/Zero-Order Hold4'
                                        */
  real_T Gain_Gain_il[3];              /* Expression: [1 -1 1]
                                        * Referenced by: '<S392>/Gain'
                                        */
  real_T ZeroOrderHold3_Gain;          /* Expression: 1
                                        * Referenced by: '<S392>/Zero-Order Hold3'
                                        */
  real_T IntegratorSecondOrderLimited_ICX_g;/* Expression: 0
                                             * Referenced by: '<S411>/Integrator, Second-Order Limited'
                                             */
  real_T IntegratorSecondOrderLimited_ICDXDT_b;/* Expression: 0
                                                * Referenced by: '<S411>/Integrator, Second-Order Limited'
                                                */
  real_T ZeroOrderHold_Gain_e;         /* Expression: 1
                                        * Referenced by: '<S393>/Zero-Order Hold'
                                        */
  real_T ZeroOrderHold1_Gain_n;        /* Expression: 1
                                        * Referenced by: '<S393>/Zero-Order Hold1'
                                        */
  real32_T ServoCMD_Y0;                /* Computed Parameter: ServoCMD_Y0
                                        * Referenced by: '<S27>/ServoCMD'
                                        */
  real32_T SensorACC_Y0;               /* Computed Parameter: SensorACC_Y0
                                        * Referenced by: '<S27>/SensorACC'
                                        */
  real32_T SensorROT_Y0;               /* Computed Parameter: SensorROT_Y0
                                        * Referenced by: '<S27>/SensorROT'
                                        */
  real32_T quaternion_Y0;              /* Computed Parameter: quaternion_Y0
                                        * Referenced by: '<S27>/quaternion'
                                        */
  real32_T TestSignal_Y0;              /* Computed Parameter: TestSignal_Y0
                                        * Referenced by: '<S27>/TestSignal'
                                        */
  real32_T Constant6_Value_c;          /* Computed Parameter: Constant6_Value_c
                                        * Referenced by: '<S20>/Constant6'
                                        */
  uint32_T Cn_delta_n_Interpolation_dimSize[3];
                         /* Computed Parameter: Cn_delta_n_Interpolation_dimSize
                          * Referenced by: '<S236>/Cn_delta_n_Interpolation'
                          */
  uint32_T Cn_delta_m_Interpolation_dimSize[3];
                         /* Computed Parameter: Cn_delta_m_Interpolation_dimSize
                          * Referenced by: '<S236>/Cn_delta_m_Interpolation'
                          */
  uint32_T Cn_delta_l_Interpolation_dimSize[3];
                         /* Computed Parameter: Cn_delta_l_Interpolation_dimSize
                          * Referenced by: '<S236>/Cn_delta_l_Interpolation'
                          */
  uint32_T Cnr_Interpolation_dimSize[3];
                                /* Computed Parameter: Cnr_Interpolation_dimSize
                                 * Referenced by: '<S236>/Cnr_Interpolation'
                                 */
  uint32_T Cnq_Interpolation_dimSize[3];
                                /* Computed Parameter: Cnq_Interpolation_dimSize
                                 * Referenced by: '<S236>/Cnq_Interpolation'
                                 */
  uint32_T Cnp_Interpolation_dimSize[3];
                                /* Computed Parameter: Cnp_Interpolation_dimSize
                                 * Referenced by: '<S236>/Cnp_Interpolation'
                                 */
  uint32_T Cn_Interpolation_dimSize[3];
                                 /* Computed Parameter: Cn_Interpolation_dimSize
                                  * Referenced by: '<S236>/Cn_Interpolation'
                                  */
  uint32_T Cm_delta_n_Interpolation_dimSize[3];
                         /* Computed Parameter: Cm_delta_n_Interpolation_dimSize
                          * Referenced by: '<S235>/Cm_delta_n_Interpolation'
                          */
  uint32_T Cm_delta_m_Interpolation_dimSize[3];
                         /* Computed Parameter: Cm_delta_m_Interpolation_dimSize
                          * Referenced by: '<S235>/Cm_delta_m_Interpolation'
                          */
  uint32_T Cm_delta_l_Interpolation_dimSize[3];
                         /* Computed Parameter: Cm_delta_l_Interpolation_dimSize
                          * Referenced by: '<S235>/Cm_delta_l_Interpolation'
                          */
  uint32_T Cmr_Interpolation_dimSize[3];
                                /* Computed Parameter: Cmr_Interpolation_dimSize
                                 * Referenced by: '<S235>/Cmr_Interpolation'
                                 */
  uint32_T Cmq_Interpolation_dimSize[3];
                                /* Computed Parameter: Cmq_Interpolation_dimSize
                                 * Referenced by: '<S235>/Cmq_Interpolation'
                                 */
  uint32_T Cmp_Interpolation_dimSize[3];
                                /* Computed Parameter: Cmp_Interpolation_dimSize
                                 * Referenced by: '<S235>/Cmp_Interpolation'
                                 */
  uint32_T Cm_Interpolation_dimSize[3];
                                 /* Computed Parameter: Cm_Interpolation_dimSize
                                  * Referenced by: '<S235>/Cm_Interpolation'
                                  */
  uint32_T Cl_delta_n_Interpolation_dimSize[3];
                         /* Computed Parameter: Cl_delta_n_Interpolation_dimSize
                          * Referenced by: '<S234>/Cl_delta_n_Interpolation'
                          */
  uint32_T Cl_delta_m_Interpolation_dimSize[3];
                         /* Computed Parameter: Cl_delta_m_Interpolation_dimSize
                          * Referenced by: '<S234>/Cl_delta_m_Interpolation'
                          */
  uint32_T Cl_delta_l_Interpolation_dimSize[3];
                         /* Computed Parameter: Cl_delta_l_Interpolation_dimSize
                          * Referenced by: '<S234>/Cl_delta_l_Interpolation'
                          */
  uint32_T Clr_Interpolation_dimSize[3];
                                /* Computed Parameter: Clr_Interpolation_dimSize
                                 * Referenced by: '<S234>/Clr_Interpolation'
                                 */
  uint32_T Clq_Interpolation_dimSize[3];
                                /* Computed Parameter: Clq_Interpolation_dimSize
                                 * Referenced by: '<S234>/Clq_Interpolation'
                                 */
  uint32_T Clp_Interpolation_dimSize[3];
                                /* Computed Parameter: Clp_Interpolation_dimSize
                                 * Referenced by: '<S234>/Clp_Interpolation'
                                 */
  uint32_T Cl_Interpolation_dimSize[3];
                                 /* Computed Parameter: Cl_Interpolation_dimSize
                                  * Referenced by: '<S234>/Cl_Interpolation'
                                  */
  uint32_T Cx_Interpolation_dimSize[3];
                                 /* Computed Parameter: Cx_Interpolation_dimSize
                                  * Referenced by: '<S237>/Cx_Interpolation'
                                  */
  uint32_T Cxp_Interpolation_dimSize[3];
                                /* Computed Parameter: Cxp_Interpolation_dimSize
                                 * Referenced by: '<S237>/Cxp_Interpolation'
                                 */
  uint32_T Cxq_Interpolation_dimSize[3];
                                /* Computed Parameter: Cxq_Interpolation_dimSize
                                 * Referenced by: '<S237>/Cxq_Interpolation'
                                 */
  uint32_T Cxr_Interpolation_dimSize[3];
                                /* Computed Parameter: Cxr_Interpolation_dimSize
                                 * Referenced by: '<S237>/Cxr_Interpolation'
                                 */
  uint32_T Cx_delta_l_Interpolation_dimSize[3];
                         /* Computed Parameter: Cx_delta_l_Interpolation_dimSize
                          * Referenced by: '<S237>/Cx_delta_l_Interpolation'
                          */
  uint32_T Cx_delta_m_Interpolation_dimSize[3];
                         /* Computed Parameter: Cx_delta_m_Interpolation_dimSize
                          * Referenced by: '<S237>/Cx_delta_m_Interpolation'
                          */
  uint32_T Cx_delta_n_Interpolation_dimSize[3];
                         /* Computed Parameter: Cx_delta_n_Interpolation_dimSize
                          * Referenced by: '<S237>/Cx_delta_n_Interpolation'
                          */
  uint32_T Cx_alt_Interpolation_dimSize[3];
                             /* Computed Parameter: Cx_alt_Interpolation_dimSize
                              * Referenced by: '<S237>/Cx_alt_Interpolation'
                              */
  uint32_T Cx_delta_t_Interpolation_dimSize[3];
                         /* Computed Parameter: Cx_delta_t_Interpolation_dimSize
                          * Referenced by: '<S237>/Cx_delta_t_Interpolation'
                          */
  uint32_T Cx_base_Interpolation_dimSize[3];
                            /* Computed Parameter: Cx_base_Interpolation_dimSize
                             * Referenced by: '<S237>/Cx_base_Interpolation'
                             */
  uint32_T Cy_Interpolation_dimSize[3];
                                 /* Computed Parameter: Cy_Interpolation_dimSize
                                  * Referenced by: '<S238>/Cy_Interpolation'
                                  */
  uint32_T Cyp_Interpolation_dimSize[3];
                                /* Computed Parameter: Cyp_Interpolation_dimSize
                                 * Referenced by: '<S238>/Cyp_Interpolation'
                                 */
  uint32_T Cyq_Interpolation_dimSize[3];
                                /* Computed Parameter: Cyq_Interpolation_dimSize
                                 * Referenced by: '<S238>/Cyq_Interpolation'
                                 */
  uint32_T Cyr_Interpolation_dimSize[3];
                                /* Computed Parameter: Cyr_Interpolation_dimSize
                                 * Referenced by: '<S238>/Cyr_Interpolation'
                                 */
  uint32_T Cy_delta_l_Interpolation_dimSize[3];
                         /* Computed Parameter: Cy_delta_l_Interpolation_dimSize
                          * Referenced by: '<S238>/Cy_delta_l_Interpolation'
                          */
  uint32_T Cy_delta_m_Interpolation_dimSize[3];
                         /* Computed Parameter: Cy_delta_m_Interpolation_dimSize
                          * Referenced by: '<S238>/Cy_delta_m_Interpolation'
                          */
  uint32_T Cy_delta_n_Interpolation_dimSize[3];
                         /* Computed Parameter: Cy_delta_n_Interpolation_dimSize
                          * Referenced by: '<S238>/Cy_delta_n_Interpolation'
                          */
  uint32_T Cz_Interpolation_dimSize[3];
                                 /* Computed Parameter: Cz_Interpolation_dimSize
                                  * Referenced by: '<S239>/Cz_Interpolation'
                                  */
  uint32_T Czp_Interpolation_dimSize[3];
                                /* Computed Parameter: Czp_Interpolation_dimSize
                                 * Referenced by: '<S239>/Czp_Interpolation'
                                 */
  uint32_T Czq_Interpolation_dimSize[3];
                                /* Computed Parameter: Czq_Interpolation_dimSize
                                 * Referenced by: '<S239>/Czq_Interpolation'
                                 */
  uint32_T Czr_Interpolation_dimSize[3];
                                /* Computed Parameter: Czr_Interpolation_dimSize
                                 * Referenced by: '<S239>/Czr_Interpolation'
                                 */
  uint32_T Cz_delta_l_Interpolation_dimSize[3];
                         /* Computed Parameter: Cz_delta_l_Interpolation_dimSize
                          * Referenced by: '<S239>/Cz_delta_l_Interpolation'
                          */
  uint32_T Cz_delta_m_Interpolation_dimSize[3];
                         /* Computed Parameter: Cz_delta_m_Interpolation_dimSize
                          * Referenced by: '<S239>/Cz_delta_m_Interpolation'
                          */
  uint32_T Cz_delta_n_Interpolation_dimSize[3];
                         /* Computed Parameter: Cz_delta_n_Interpolation_dimSize
                          * Referenced by: '<S239>/Cz_delta_n_Interpolation'
                          */
  uint16_T PixHeartbeat_Y0;            /* Computed Parameter: PixHeartbeat_Y0
                                        * Referenced by: '<S27>/PixHeartbeat'
                                        */
  uint16_T Constant_Value_lk;          /* Computed Parameter: Constant_Value_lk
                                        * Referenced by: '<S386>/Constant'
                                        */
  uint16_T Output_InitialCondition;
                                  /* Computed Parameter: Output_InitialCondition
                                   * Referenced by: '<S384>/Output'
                                   */
  uint16_T FixPtConstant_Value;       /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S385>/FixPt Constant'
                                       */
  boolean_T Constant10_Value_ca;
                /* Expression: External_Inputs.FCC.CMD.yaw.pulse.alternating_flg
                 * Referenced by: '<S19>/Constant10'
                 */
  boolean_T Constant6_Value_b;
               /* Expression: External_Inputs.FCC.CMD.roll.pulse.alternating_flg
                * Referenced by: '<S19>/Constant6'
                */
  boolean_T Constant8_Value_ej;
              /* Expression: External_Inputs.FCC.CMD.pitch.pulse.alternating_flg
               * Referenced by: '<S19>/Constant8'
               */
  boolean_T Status_Y0;                 /* Computed Parameter: Status_Y0
                                        * Referenced by: '<S23>/Status'
                                        */
  boolean_T packetfound_flg_Y0;        /* Computed Parameter: packetfound_flg_Y0
                                        * Referenced by: '<S24>/packetfound_flg'
                                        */
  boolean_T Memory_1_InitialCondition;
                                /* Computed Parameter: Memory_1_InitialCondition
                                 * Referenced by: '<S35>/Memory'
                                 */
  boolean_T Memory_2_InitialCondition;
                                /* Computed Parameter: Memory_2_InitialCondition
                                 * Referenced by: '<S35>/Memory'
                                 */
  boolean_T Constant1_Value_pw;        /* Computed Parameter: Constant1_Value_pw
                                        * Referenced by: '<S71>/Constant1'
                                        */
  boolean_T Constant1_Value_n3;        /* Computed Parameter: Constant1_Value_n3
                                        * Referenced by: '<S52>/Constant1'
                                        */
  boolean_T Constant1_Value_gc;        /* Computed Parameter: Constant1_Value_gc
                                        * Referenced by: '<S61>/Constant1'
                                        */
  boolean_T Constant9_Value_b;         /* Computed Parameter: Constant9_Value_b
                                        * Referenced by: '<S8>/Constant9'
                                        */
  boolean_T Constant12_Value_e;        /* Computed Parameter: Constant12_Value_e
                                        * Referenced by: '<S8>/Constant12'
                                        */
  boolean_T Constant_Value_gt;         /* Computed Parameter: Constant_Value_gt
                                        * Referenced by: '<S8>/Constant'
                                        */
  boolean_T Constant1_Value_c3;        /* Computed Parameter: Constant1_Value_c3
                                        * Referenced by: '<S8>/Constant1'
                                        */
  boolean_T Constant3_Value_it;
                             /* Expression: HIL_Data.Simulation_Ctrl.offline_flg
                              * Referenced by: '<S8>/Constant3'
                              */
  uint8_T Data_Y0;                     /* Computed Parameter: Data_Y0
                                        * Referenced by: '<S23>/Data'
                                        */
  uint8_T PixStatus_Y0;                /* Computed Parameter: PixStatus_Y0
                                        * Referenced by: '<S27>/PixStatus'
                                        */
  uint8_T PixRCStatus_Y0;              /* Computed Parameter: PixRCStatus_Y0
                                        * Referenced by: '<S27>/PixRCStatus'
                                        */
  uint8_T message_pass_Y0;             /* Computed Parameter: message_pass_Y0
                                        * Referenced by: '<S34>/message_pass'
                                        */
  uint8_T Constant_Value_jh;           /* Computed Parameter: Constant_Value_jh
                                        * Referenced by: '<S22>/Constant'
                                        */
  uint8_T Constant1_Value_e;           /* Computed Parameter: Constant1_Value_e
                                        * Referenced by: '<S22>/Constant1'
                                        */
  P_IfActionSubsystem_GRM_HIL_T IfActionSubsystem_k;/* '<S175>/If Action Subsystem' */
  P_IfActionSubsystem1_GRM_HIL_T IfActionSubsystem1_l;/* '<S175>/If Action Subsystem1' */
  P_IfActionSubsystem_GRM_HIL_T IfActionSubsystem_f;/* '<S174>/If Action Subsystem' */
  P_IfActionSubsystem1_GRM_HIL_T IfActionSubsystem1_n;/* '<S174>/If Action Subsystem1' */
  P_IfActionSubsystem_GRM_HIL_T IfActionSubsystem;/* '<S173>/If Action Subsystem' */
  P_IfActionSubsystem1_GRM_HIL_T IfActionSubsystem1;/* '<S173>/If Action Subsystem1' */
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
  real_T odeY[71];
  real_T odeF[3][71];
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
 * '<S6>'   : 'GRM_HIL/MATLAB Function'
 * '<S7>'   : 'GRM_HIL/Simulation'
 * '<S8>'   : 'GRM_HIL/Simulation_Ctrl'
 * '<S9>'   : 'GRM_HIL/Stop Simulation'
 * '<S10>'  : 'GRM_HIL/Subsystem'
 * '<S11>'  : 'GRM_HIL/Actuators/Emulate_Actuators'
 * '<S12>'  : 'GRM_HIL/Actuators/Emulate_Actuators/Encoder'
 * '<S13>'  : 'GRM_HIL/Actuators/Emulate_Actuators/Servo'
 * '<S14>'  : 'GRM_HIL/Actuators/Emulate_Actuators/Servo2Control_Surfaces'
 * '<S15>'  : 'GRM_HIL/Actuators/Emulate_Actuators/Servo/Servo_1'
 * '<S16>'  : 'GRM_HIL/Actuators/Emulate_Actuators/Servo/Servo_2'
 * '<S17>'  : 'GRM_HIL/Actuators/Emulate_Actuators/Servo/Servo_3'
 * '<S18>'  : 'GRM_HIL/Actuators/Emulate_Actuators/Servo/Servo_4'
 * '<S19>'  : 'GRM_HIL/External_Inputs/Commands_Generator'
 * '<S20>'  : 'GRM_HIL/FCC/Use_FCC'
 * '<S21>'  : 'GRM_HIL/FCC/Use_FCC/Serial_Recieve_from_Pixhawk'
 * '<S22>'  : 'GRM_HIL/FCC/Use_FCC/Serial_Send_to_Pixhawk'
 * '<S23>'  : 'GRM_HIL/FCC/Use_FCC/Serial_Recieve_from_Pixhawk/Receive_ExternalMode'
 * '<S24>'  : 'GRM_HIL/FCC/Use_FCC/Serial_Recieve_from_Pixhawk/input_hold'
 * '<S25>'  : 'GRM_HIL/FCC/Use_FCC/Serial_Recieve_from_Pixhawk/input_hold/ByteUnpack'
 * '<S26>'  : 'GRM_HIL/FCC/Use_FCC/Serial_Recieve_from_Pixhawk/input_hold/ExtractMessage'
 * '<S27>'  : 'GRM_HIL/FCC/Use_FCC/Serial_Recieve_from_Pixhawk/input_hold/hold'
 * '<S28>'  : 'GRM_HIL/FCC/Use_FCC/Serial_Send_to_Pixhawk/Com_Sync'
 * '<S29>'  : 'GRM_HIL/FCC/Use_FCC/Serial_Send_to_Pixhawk/CreateVector'
 * '<S30>'  : 'GRM_HIL/FCC/Use_FCC/Serial_Send_to_Pixhawk/send_to_pix'
 * '<S31>'  : 'GRM_HIL/FCC/Use_FCC/Serial_Send_to_Pixhawk/Com_Sync/Counter_with_external_limit'
 * '<S32>'  : 'GRM_HIL/FCC/Use_FCC/Serial_Send_to_Pixhawk/send_to_pix/MessageAssembly'
 * '<S33>'  : 'GRM_HIL/FCC/Use_FCC/Serial_Send_to_Pixhawk/send_to_pix/Send_ExternalMode'
 * '<S34>'  : 'GRM_HIL/FCC/Use_FCC/Serial_Send_to_Pixhawk/send_to_pix/no_CRC'
 * '<S35>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal'
 * '<S36>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbal'
 * '<S37>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl'
 * '<S38>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbal/Gimbal_TransferFunctions'
 * '<S39>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbal/Gimbal_TransferFunctions/Assemble_Gimbal_Subbusses'
 * '<S40>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbal/Gimbal_TransferFunctions/Assemble_Gimbal_Subbusses/Emulate_Encoder_Signals'
 * '<S41>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbal/Gimbal_TransferFunctions/Assemble_Gimbal_Subbusses/Eul2Quat'
 * '<S42>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbal/Gimbal_TransferFunctions/Assemble_Gimbal_Subbusses/Eul2Quat/Rotation Angles to Quaternions'
 * '<S43>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller'
 * '<S44>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller'
 * '<S45>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Pitch'
 * '<S46>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Roll'
 * '<S47>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw'
 * '<S48>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Damping'
 * '<S49>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/If Action Pass'
 * '<S50>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Monitor_Velocity_Limits'
 * '<S51>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Voltage_Limitations'
 * '<S52>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Pitch/Limits'
 * '<S53>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Pitch/PID_Controller_Dynamic_Limits'
 * '<S54>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Pitch/Limits/Compare To Constant'
 * '<S55>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Pitch/Limits/Compare To Constant1'
 * '<S56>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Pitch/Limits/Enabled adapt'
 * '<S57>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Pitch/Limits/Enabled pass'
 * '<S58>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Pitch/PID_Controller_Dynamic_Limits/Saturation'
 * '<S59>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Pitch/PID_Controller_Dynamic_Limits/pass'
 * '<S60>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Pitch/PID_Controller_Dynamic_Limits/Saturation/Saturation Dynamic'
 * '<S61>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Roll/Limits'
 * '<S62>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Roll/PID_Controller_Dynamic_Limits'
 * '<S63>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Roll/Limits/Compare To Constant'
 * '<S64>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Roll/Limits/Compare To Constant1'
 * '<S65>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Roll/Limits/Enabled adapt'
 * '<S66>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Roll/Limits/Enabled pass'
 * '<S67>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Roll/PID_Controller_Dynamic_Limits/Saturation'
 * '<S68>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Roll/PID_Controller_Dynamic_Limits/pass'
 * '<S69>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Roll/PID_Controller_Dynamic_Limits/Saturation/Saturation Dynamic'
 * '<S70>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers'
 * '<S71>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limits'
 * '<S72>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/PID_Controller_Dynamic_Limits'
 * '<S73>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits'
 * '<S74>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/pass'
 * '<S75>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller'
 * '<S76>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1'
 * '<S77>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Anti-windup'
 * '<S78>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/D Gain'
 * '<S79>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Filter'
 * '<S80>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Filter ICs'
 * '<S81>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/I Gain'
 * '<S82>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Ideal P Gain'
 * '<S83>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Ideal P Gain Fdbk'
 * '<S84>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Integrator'
 * '<S85>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Integrator ICs'
 * '<S86>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/N Copy'
 * '<S87>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/N Gain'
 * '<S88>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/P Copy'
 * '<S89>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Parallel P Gain'
 * '<S90>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Reset Signal'
 * '<S91>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Saturation'
 * '<S92>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Saturation Fdbk'
 * '<S93>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Sum'
 * '<S94>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Sum Fdbk'
 * '<S95>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Tracking Mode'
 * '<S96>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Tracking Mode Sum'
 * '<S97>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/postSat Signal'
 * '<S98>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/preSat Signal'
 * '<S99>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Anti-windup/Back Calculation'
 * '<S100>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/D Gain/Internal Parameters'
 * '<S101>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Filter/Cont. Filter'
 * '<S102>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S103>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/I Gain/Internal Parameters'
 * '<S104>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Ideal P Gain/Passthrough'
 * '<S105>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S106>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Integrator/Continuous'
 * '<S107>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Integrator ICs/Internal IC'
 * '<S108>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/N Copy/Disabled'
 * '<S109>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/N Gain/Internal Parameters'
 * '<S110>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/P Copy/Disabled'
 * '<S111>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S112>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Reset Signal/Disabled'
 * '<S113>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Saturation/Enabled'
 * '<S114>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Saturation Fdbk/Disabled'
 * '<S115>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Sum/Sum_PID'
 * '<S116>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Sum Fdbk/Disabled'
 * '<S117>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Tracking Mode/Disabled'
 * '<S118>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S119>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/postSat Signal/Forward_Path'
 * '<S120>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/preSat Signal/Forward_Path'
 * '<S121>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Anti-windup'
 * '<S122>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/D Gain'
 * '<S123>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Filter'
 * '<S124>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Filter ICs'
 * '<S125>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/I Gain'
 * '<S126>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Ideal P Gain'
 * '<S127>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Ideal P Gain Fdbk'
 * '<S128>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Integrator'
 * '<S129>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Integrator ICs'
 * '<S130>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/N Copy'
 * '<S131>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/N Gain'
 * '<S132>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/P Copy'
 * '<S133>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Parallel P Gain'
 * '<S134>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Reset Signal'
 * '<S135>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Saturation'
 * '<S136>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Saturation Fdbk'
 * '<S137>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Sum'
 * '<S138>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Sum Fdbk'
 * '<S139>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Tracking Mode'
 * '<S140>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Tracking Mode Sum'
 * '<S141>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/postSat Signal'
 * '<S142>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/preSat Signal'
 * '<S143>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Anti-windup/Back Calculation'
 * '<S144>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/D Gain/Internal Parameters'
 * '<S145>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Filter/Cont. Filter'
 * '<S146>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S147>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/I Gain/Internal Parameters'
 * '<S148>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Ideal P Gain/Passthrough'
 * '<S149>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S150>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Integrator/Continuous'
 * '<S151>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Integrator ICs/Internal IC'
 * '<S152>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/N Copy/Disabled'
 * '<S153>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/N Gain/Internal Parameters'
 * '<S154>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/P Copy/Disabled'
 * '<S155>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S156>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Reset Signal/Disabled'
 * '<S157>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Saturation/Enabled'
 * '<S158>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Saturation Fdbk/Disabled'
 * '<S159>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Sum/Sum_PID'
 * '<S160>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Sum Fdbk/Disabled'
 * '<S161>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Tracking Mode/Disabled'
 * '<S162>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S163>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/postSat Signal/Forward_Path'
 * '<S164>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/preSat Signal/Forward_Path'
 * '<S165>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limits/Compare To Constant'
 * '<S166>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limits/Compare To Constant1'
 * '<S167>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limits/Enabled adapt'
 * '<S168>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limits/Enabled pass'
 * '<S169>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/PID_Controller_Dynamic_Limits/Saturation'
 * '<S170>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/PID_Controller_Dynamic_Limits/pass'
 * '<S171>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/PID_Controller_Dynamic_Limits/Saturation/Saturation Dynamic'
 * '<S172>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Damping/Compare To Constant'
 * '<S173>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Monitor_Velocity_Limits/Pitch_rate_limit'
 * '<S174>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Monitor_Velocity_Limits/Roll_Rate_limit'
 * '<S175>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Monitor_Velocity_Limits/Yaw_rate_limit'
 * '<S176>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Monitor_Velocity_Limits/Pitch_rate_limit/If Action Subsystem'
 * '<S177>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Monitor_Velocity_Limits/Pitch_rate_limit/If Action Subsystem1'
 * '<S178>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Monitor_Velocity_Limits/Roll_Rate_limit/If Action Subsystem'
 * '<S179>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Monitor_Velocity_Limits/Roll_Rate_limit/If Action Subsystem1'
 * '<S180>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Monitor_Velocity_Limits/Yaw_rate_limit/If Action Subsystem'
 * '<S181>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Monitor_Velocity_Limits/Yaw_rate_limit/If Action Subsystem1'
 * '<S182>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Voltage_Limitations/If Action limit_pitch'
 * '<S183>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Voltage_Limitations/If Action limit_roll'
 * '<S184>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Voltage_Limitations/If Action limit_yaw'
 * '<S185>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Voltage_Limitations/If Action pass_pitch'
 * '<S186>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Voltage_Limitations/If Action pass_roll'
 * '<S187>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Voltage_Limitations/If Action pass_yaw'
 * '<S188>' : 'GRM_HIL/Initial_States/Assemble_States_Bus'
 * '<S189>' : 'GRM_HIL/Initial_States/Assemble_States_Bus/Rotation Angles to Quaternions'
 * '<S190>' : 'GRM_HIL/Simulation/FDM'
 * '<S191>' : 'GRM_HIL/Simulation/Gimbel_Cmd'
 * '<S192>' : 'GRM_HIL/Simulation/IMU_GPS_Emulator'
 * '<S193>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated'
 * '<S194>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/Assemble_States_Bus'
 * '<S195>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/MATLAB Function'
 * '<S196>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/Subsystem'
 * '<S197>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics'
 * '<S198>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/environment'
 * '<S199>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/fin_actuators'
 * '<S200>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/forces_moments'
 * '<S201>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/gravity'
 * '<S202>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/input'
 * '<S203>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics'
 * '<S204>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/propulsion'
 * '<S205>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/quaternion_to_euler_angles'
 * '<S206>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/rb_eom'
 * '<S207>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/stream_flow'
 * '<S208>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/tmp'
 * '<S209>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/weight_and_balance'
 * '<S210>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/Assemble_States_Bus/Rotation Angles to Quaternions'
 * '<S211>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/Subsystem/Degrees to Radians'
 * '<S212>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/Subsystem/Degrees to Radians1'
 * '<S213>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/Subsystem/Degrees to Radians2'
 * '<S214>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/Subsystem/control_allocation'
 * '<S215>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup'
 * '<S216>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/logic_base_drag'
 * '<S217>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_aero_coefficients'
 * '<S218>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_aero_for_mom'
 * '<S219>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_derivatives'
 * '<S220>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/transform_rad2deg_al_be'
 * '<S221>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/transform_rad2deg_fin'
 * '<S222>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/transform_rad2deg_rates'
 * '<S223>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_aero_for_mom/cross_product'
 * '<S224>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_aero_for_mom/launch_rail'
 * '<S225>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_aero_for_mom/launch_rail1'
 * '<S226>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_aero_for_mom/launch_rail/initial_altitude'
 * '<S227>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_aero_for_mom/launch_rail/initial_altitude/trafo_E_to_geodetic'
 * '<S228>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_aero_for_mom/launch_rail/initial_altitude/trafo_E_to_geodetic/Geodetic_altitude'
 * '<S229>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_aero_for_mom/launch_rail/initial_altitude/trafo_E_to_geodetic/Geodetic_latitude'
 * '<S230>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_aero_for_mom/launch_rail1/initial_altitude'
 * '<S231>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_aero_for_mom/launch_rail1/initial_altitude/trafo_E_to_geodetic'
 * '<S232>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_aero_for_mom/launch_rail1/initial_altitude/trafo_E_to_geodetic/Geodetic_altitude'
 * '<S233>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_aero_for_mom/launch_rail1/initial_altitude/trafo_E_to_geodetic/Geodetic_latitude'
 * '<S234>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_derivatives/Cl_derivatives_lookup'
 * '<S235>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_derivatives/Cm_derivatives_lookup'
 * '<S236>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_derivatives/Cn_derivatives_lookup'
 * '<S237>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_derivatives/Cx_derivatives_lookup'
 * '<S238>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_derivatives/Cy_derivatives_lookup'
 * '<S239>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_derivatives/Cz_derivatives_lookup'
 * '<S240>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_derivatives/aerodynamics_pre_lookup'
 * '<S241>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_derivatives/calc_total_deflection_angle'
 * '<S242>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_derivatives/calc_total_deflection_angle/Degrees to Radians'
 * '<S243>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_derivatives/calc_total_deflection_angle/Degrees to Radians1'
 * '<S244>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/calc_derivatives/calc_total_deflection_angle/Radians to Degrees1'
 * '<S245>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/transform_rad2deg_al_be/Radians to Degrees'
 * '<S246>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/transform_rad2deg_al_be/Radians to Degrees1'
 * '<S247>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/transform_rad2deg_fin/Radians to Degrees'
 * '<S248>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/transform_rad2deg_fin/Radians to Degrees1'
 * '<S249>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/transform_rad2deg_fin/Radians to Degrees2'
 * '<S250>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/transform_rad2deg_rates/Radians to Degrees'
 * '<S251>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/transform_rad2deg_rates/Radians to Degrees1'
 * '<S252>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/aerodynamic_via_lookup/transform_rad2deg_rates/Radians to Degrees2'
 * '<S253>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/aerodynamics/logic_base_drag/MATLAB Function'
 * '<S254>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/environment/WGS84_Gravitation'
 * '<S255>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/environment/atmosphere_static_ISO_2533'
 * '<S256>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/environment/convert_to_local_frame'
 * '<S257>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/environment/WGS84_Gravitation/Compare To Constant'
 * '<S258>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/environment/WGS84_Gravitation/Interval Test'
 * '<S259>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/environment/WGS84_Gravitation/Interval Test1'
 * '<S260>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/environment/WGS84_Gravitation/WGS84_2_ECEF'
 * '<S261>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/environment/WGS84_Gravitation/WGS84_Gravity_Implementation'
 * '<S262>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/environment/WGS84_Gravitation/WGS84_2_ECEF/WGS84 Transformation Parameter '
 * '<S263>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/environment/WGS84_Gravitation/WGS84_2_ECEF/WGS84 Transformation Parameter /Subsystem'
 * '<S264>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/environment/atmosphere_static_ISO_2533/density'
 * '<S265>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/environment/atmosphere_static_ISO_2533/geopot_height'
 * '<S266>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/environment/atmosphere_static_ISO_2533/speed_of_sound'
 * '<S267>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/environment/atmosphere_static_ISO_2533/tmp_and_pressure_ISO_2533'
 * '<S268>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/environment/atmosphere_static_ISO_2533/tmp_and_pressure_ISO_2533/static_Temperature'
 * '<S269>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/environment/atmosphere_static_ISO_2533/tmp_and_pressure_ISO_2533/static_pressure'
 * '<S270>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/fin_actuators/Rudder'
 * '<S271>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/fin_actuators/Rudder1'
 * '<S272>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/fin_actuators/Rudder2'
 * '<S273>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/fin_actuators/Rudder3'
 * '<S274>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/fin_actuators/control_allocation'
 * '<S275>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/fin_actuators/Rudder/Limiting_Acceleration'
 * '<S276>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/fin_actuators/Rudder/Limiting_Rate'
 * '<S277>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/fin_actuators/Rudder1/Limiting_Acceleration'
 * '<S278>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/fin_actuators/Rudder1/Limiting_Rate'
 * '<S279>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/fin_actuators/Rudder2/Limiting_Acceleration'
 * '<S280>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/fin_actuators/Rudder2/Limiting_Rate'
 * '<S281>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/fin_actuators/Rudder3/Limiting_Acceleration'
 * '<S282>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/fin_actuators/Rudder3/Limiting_Rate'
 * '<S283>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/gravity/launch_rail'
 * '<S284>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/gravity/launch_rail/initial_altitude'
 * '<S285>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/gravity/launch_rail/initial_altitude/trafo_E_to_geodetic'
 * '<S286>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/gravity/launch_rail/initial_altitude/trafo_E_to_geodetic/Geodetic_altitude'
 * '<S287>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/gravity/launch_rail/initial_altitude/trafo_E_to_geodetic/Geodetic_latitude'
 * '<S288>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics'
 * '<S289>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics/calc_transformation_matrix'
 * '<S290>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics/earth_rotation'
 * '<S291>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics/calc_transformation_matrix/T12_from_q1'
 * '<S292>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics/calc_transformation_matrix/T12_from_q12'
 * '<S293>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics/calc_transformation_matrix/T12_from_q2'
 * '<S294>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics/calc_transformation_matrix/conjugate_quaternion'
 * '<S295>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics/calc_transformation_matrix/q31_from_q32_mul_q1'
 * '<S296>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics/calc_transformation_matrix/q31_from_q32_mul_q2'
 * '<S297>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics/calc_transformation_matrix/q31_from_q32_mul_q21'
 * '<S298>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics/calc_transformation_matrix/q31_from_q32_mul_q1/normalize_quaternion'
 * '<S299>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics/calc_transformation_matrix/q31_from_q32_mul_q2/normalize_quaternion'
 * '<S300>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics/calc_transformation_matrix/q31_from_q32_mul_q21/normalize_quaternion'
 * '<S301>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics/earth_rotation/earth_rotation_rate'
 * '<S302>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics/earth_rotation/quaternion_integration'
 * '<S303>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics/earth_rotation/quaternion_integration1'
 * '<S304>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics/earth_rotation/transport_rate'
 * '<S305>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics/earth_rotation/quaternion_integration/Subsystem1'
 * '<S306>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics/earth_rotation/quaternion_integration/T12_from_q12'
 * '<S307>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics/earth_rotation/quaternion_integration/Subsystem1/conjugate_quaternion1'
 * '<S308>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics/earth_rotation/quaternion_integration/Subsystem1/conjugate_quaternion2'
 * '<S309>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics/earth_rotation/quaternion_integration1/Subsystem1'
 * '<S310>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics/earth_rotation/quaternion_integration1/T12_from_q12'
 * '<S311>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics/earth_rotation/quaternion_integration1/Subsystem1/conjugate_quaternion1'
 * '<S312>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/motion_kinematics/calc_motion_kinematics/earth_rotation/quaternion_integration1/Subsystem1/conjugate_quaternion2'
 * '<S313>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/propulsion/prp_look_up'
 * '<S314>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/propulsion/prp_uncertainty'
 * '<S315>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/propulsion/prp_uncertainty/3_rot_mat'
 * '<S316>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/propulsion/prp_uncertainty/cross_product'
 * '<S317>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/propulsion/prp_uncertainty/3_rot_mat/1. Rotation x-Achse'
 * '<S318>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/propulsion/prp_uncertainty/3_rot_mat/1. Rotation y-Achse'
 * '<S319>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/propulsion/prp_uncertainty/3_rot_mat/1. Rotation z-Achse'
 * '<S320>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/propulsion/prp_uncertainty/3_rot_mat/2. Rotation x-Achse'
 * '<S321>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/propulsion/prp_uncertainty/3_rot_mat/2. Rotation y-Achse'
 * '<S322>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/propulsion/prp_uncertainty/3_rot_mat/2. Rotation z-Achse'
 * '<S323>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/propulsion/prp_uncertainty/3_rot_mat/3. Rotation x-Achse'
 * '<S324>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/propulsion/prp_uncertainty/3_rot_mat/3. Rotation y-Achse'
 * '<S325>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/propulsion/prp_uncertainty/3_rot_mat/3. Rotation z-Achse'
 * '<S326>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/rb_eom/calc_bus_flight_dyn_bus_entries'
 * '<S327>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/rb_eom/eom_6dof'
 * '<S328>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/rb_eom/calc_bus_flight_dyn_bus_entries/Subsystem2'
 * '<S329>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/rb_eom/calc_bus_flight_dyn_bus_entries/quaternion_to_euler_angles'
 * '<S330>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/rb_eom/calc_bus_flight_dyn_bus_entries/Subsystem2/trafo_E_to_geodetic'
 * '<S331>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/rb_eom/calc_bus_flight_dyn_bus_entries/Subsystem2/trafo_E_to_geodetic/Geodetic_altitude'
 * '<S332>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/rb_eom/calc_bus_flight_dyn_bus_entries/Subsystem2/trafo_E_to_geodetic/Geodetic_latitude'
 * '<S333>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/rb_eom/eom_6dof/Rigid_Body_EOM_6_DOF'
 * '<S334>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/rb_eom/eom_6dof/Rigid_Body_EOM_6_DOF/Integration'
 * '<S335>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/rb_eom/eom_6dof/Rigid_Body_EOM_6_DOF/T12_from_q12'
 * '<S336>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/rb_eom/eom_6dof/Rigid_Body_EOM_6_DOF/rb_eom_6dof'
 * '<S337>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/rb_eom/eom_6dof/Rigid_Body_EOM_6_DOF/Integration/normalize_quaternion'
 * '<S338>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/rb_eom/eom_6dof/Rigid_Body_EOM_6_DOF/rb_eom_6dof/calc_d_qIB'
 * '<S339>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/rb_eom/eom_6dof/Rigid_Body_EOM_6_DOF/rb_eom_6dof/cross_product'
 * '<S340>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/rb_eom/eom_6dof/Rigid_Body_EOM_6_DOF/rb_eom_6dof/r2_from_r1_trans_q21'
 * '<S341>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/rb_eom/eom_6dof/Rigid_Body_EOM_6_DOF/rb_eom_6dof/calc_d_qIB/conjugate_quaternion'
 * '<S342>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/rb_eom/eom_6dof/Rigid_Body_EOM_6_DOF/rb_eom_6dof/calc_d_qIB/conjugate_quaternion1'
 * '<S343>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/stream_flow/calc_stream_flow'
 * '<S344>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/stream_flow/calc_stream_flow/Subsystem1'
 * '<S345>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/stream_flow/calc_stream_flow/velocity_vector_transformation'
 * '<S346>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/stream_flow/calc_stream_flow/Subsystem1/AoA_Sideslip_Alphatot_Phi'
 * '<S347>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/stream_flow/calc_stream_flow/Subsystem1/calc_nondimensional_rates'
 * '<S348>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/stream_flow/calc_stream_flow/Subsystem1/norm_of_vector'
 * '<S349>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/stream_flow/calc_stream_flow/Subsystem1/AoA_Sideslip_Alphatot_Phi/norm_of_vector'
 * '<S350>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/stream_flow/calc_stream_flow/velocity_vector_transformation/cross_product'
 * '<S351>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/tmp/Time'
 * '<S352>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/tmp/weather'
 * '<S353>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/tmp/weather/atm_dynamic'
 * '<S354>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/tmp/weather/atm_dynamic/trafo_around_z_axis'
 * '<S355>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/tmp/weather/atm_dynamic/trafo_around_z_axis/1_rot_mat'
 * '<S356>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/tmp/weather/atm_dynamic/trafo_around_z_axis/1_rot_mat/1. Rotation x-Achse'
 * '<S357>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/tmp/weather/atm_dynamic/trafo_around_z_axis/1_rot_mat/1. Rotation y-Achse'
 * '<S358>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/tmp/weather/atm_dynamic/trafo_around_z_axis/1_rot_mat/1. Rotation z-Achse'
 * '<S359>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/weight_and_balance/center_of_gravity'
 * '<S360>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/weight_and_balance/d_moi'
 * '<S361>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/weight_and_balance/mass'
 * '<S362>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/weight_and_balance/mass_uncertainty'
 * '<S363>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/weight_and_balance/moi'
 * '<S364>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/weight_and_balance/d_moi/vector2diagonal_matrix'
 * '<S365>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/weight_and_balance/moi/JMMM_linear_interpolation'
 * '<S366>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/weight_and_balance/moi/moi_coordinate_transformation'
 * '<S367>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/weight_and_balance/moi/moi_uncertainty'
 * '<S368>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/weight_and_balance/moi/steiners_theorem_missile'
 * '<S369>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/weight_and_balance/moi/steiners_theorem_motor'
 * '<S370>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/weight_and_balance/moi/moi_coordinate_transformation/3_rot_mat'
 * '<S371>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/weight_and_balance/moi/moi_coordinate_transformation/3_rot_mat/1. Rotation x-Achse'
 * '<S372>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/weight_and_balance/moi/moi_coordinate_transformation/3_rot_mat/1. Rotation y-Achse'
 * '<S373>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/weight_and_balance/moi/moi_coordinate_transformation/3_rot_mat/1. Rotation z-Achse'
 * '<S374>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/weight_and_balance/moi/moi_coordinate_transformation/3_rot_mat/2. Rotation x-Achse'
 * '<S375>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/weight_and_balance/moi/moi_coordinate_transformation/3_rot_mat/2. Rotation y-Achse'
 * '<S376>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/weight_and_balance/moi/moi_coordinate_transformation/3_rot_mat/2. Rotation z-Achse'
 * '<S377>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/weight_and_balance/moi/moi_coordinate_transformation/3_rot_mat/3. Rotation x-Achse'
 * '<S378>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/weight_and_balance/moi/moi_coordinate_transformation/3_rot_mat/3. Rotation y-Achse'
 * '<S379>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/weight_and_balance/moi/moi_coordinate_transformation/3_rot_mat/3. Rotation z-Achse'
 * '<S380>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/weight_and_balance/moi/steiners_theorem_missile/create_deviation_matrix'
 * '<S381>' : 'GRM_HIL/Simulation/FDM/FDM_Sophisticated/weight_and_balance/moi/steiners_theorem_motor/create_deviation_matrix1'
 * '<S382>' : 'GRM_HIL/Simulation_Ctrl/Synchronize_to_realtime'
 * '<S383>' : 'GRM_HIL/Simulation_Ctrl/hearbeat_SIM'
 * '<S384>' : 'GRM_HIL/Simulation_Ctrl/hearbeat_SIM/Counter Free-Running'
 * '<S385>' : 'GRM_HIL/Simulation_Ctrl/hearbeat_SIM/Counter Free-Running/Increment Real World'
 * '<S386>' : 'GRM_HIL/Simulation_Ctrl/hearbeat_SIM/Counter Free-Running/Wrap To Zero'
 * '<S387>' : 'GRM_HIL/Stop Simulation/Compare To Constant'
 * '<S388>' : 'GRM_HIL/Subsystem/Rotation Angles to Direction Cosine Matrix'
 * '<S389>' : 'GRM_HIL/Subsystem/Three-axis Inertial Measurement Unit'
 * '<S390>' : 'GRM_HIL/Subsystem/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
 * '<S391>' : 'GRM_HIL/Subsystem/Three-axis Inertial Measurement Unit/Acceleration Conversion'
 * '<S392>' : 'GRM_HIL/Subsystem/Three-axis Inertial Measurement Unit/Three-axis Accelerometer'
 * '<S393>' : 'GRM_HIL/Subsystem/Three-axis Inertial Measurement Unit/Three-axis Gyroscope'
 * '<S394>' : 'GRM_HIL/Subsystem/Three-axis Inertial Measurement Unit/Three-axis Accelerometer/Dynamics'
 * '<S395>' : 'GRM_HIL/Subsystem/Three-axis Inertial Measurement Unit/Three-axis Accelerometer/Random bias'
 * '<S396>' : 'GRM_HIL/Subsystem/Three-axis Inertial Measurement Unit/Three-axis Accelerometer/w x (w x d)'
 * '<S397>' : 'GRM_HIL/Subsystem/Three-axis Inertial Measurement Unit/Three-axis Accelerometer/wdot x d'
 * '<S398>' : 'GRM_HIL/Subsystem/Three-axis Inertial Measurement Unit/Three-axis Accelerometer/Dynamics/No Dynamics'
 * '<S399>' : 'GRM_HIL/Subsystem/Three-axis Inertial Measurement Unit/Three-axis Accelerometer/Dynamics/Second-order Dynamics'
 * '<S400>' : 'GRM_HIL/Subsystem/Three-axis Inertial Measurement Unit/Three-axis Accelerometer/w x (w x d)/w x (w x d)'
 * '<S401>' : 'GRM_HIL/Subsystem/Three-axis Inertial Measurement Unit/Three-axis Accelerometer/w x (w x d)/w x d'
 * '<S402>' : 'GRM_HIL/Subsystem/Three-axis Inertial Measurement Unit/Three-axis Accelerometer/w x (w x d)/w x (w x d)/Subsystem'
 * '<S403>' : 'GRM_HIL/Subsystem/Three-axis Inertial Measurement Unit/Three-axis Accelerometer/w x (w x d)/w x (w x d)/Subsystem1'
 * '<S404>' : 'GRM_HIL/Subsystem/Three-axis Inertial Measurement Unit/Three-axis Accelerometer/w x (w x d)/w x d/Subsystem'
 * '<S405>' : 'GRM_HIL/Subsystem/Three-axis Inertial Measurement Unit/Three-axis Accelerometer/w x (w x d)/w x d/Subsystem1'
 * '<S406>' : 'GRM_HIL/Subsystem/Three-axis Inertial Measurement Unit/Three-axis Accelerometer/wdot x d/Subsystem'
 * '<S407>' : 'GRM_HIL/Subsystem/Three-axis Inertial Measurement Unit/Three-axis Accelerometer/wdot x d/Subsystem1'
 * '<S408>' : 'GRM_HIL/Subsystem/Three-axis Inertial Measurement Unit/Three-axis Gyroscope/Dynamics'
 * '<S409>' : 'GRM_HIL/Subsystem/Three-axis Inertial Measurement Unit/Three-axis Gyroscope/Random bias'
 * '<S410>' : 'GRM_HIL/Subsystem/Three-axis Inertial Measurement Unit/Three-axis Gyroscope/Dynamics/No Dynamics'
 * '<S411>' : 'GRM_HIL/Subsystem/Three-axis Inertial Measurement Unit/Three-axis Gyroscope/Dynamics/Second-order Dynamics'
 */
#endif                                 /* RTW_HEADER_GRM_HIL_h_ */
