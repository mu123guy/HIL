/*
 * GRM_HIL.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "GRM_HIL".
 *
 * Model version              : 1.44
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Fri Nov  8 10:21:14 2019
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
#include "rt_defines.h"
#include "rt_nonfinite.h"

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

/* Block signals for system '<S18>/Counter_with_external_limit' */
typedef struct {
  real_T value;                        /* '<S18>/Counter_with_external_limit' */
} B_Counter_with_external_limit_GRM_HIL_T;

/* Block signals (default storage) */
typedef struct {
  real_T motor_state_perc;             /* '<S46>/Gain18' */
  real_T ATT_Phi_rad;                  /* '<S46>/Gain9' */
  real_T ATT_Theta_rad;                /* '<S46>/Gain10' */
  real_T ATT_Psi_rad;                  /* '<S46>/Gain11' */
  real_T ACC_x_B_mDs2;                 /* '<S52>/Gain3' */
  real_T Gain2;                        /* '<S61>/Gain2' */
  real_T ACC_y_B_mDs2;                 /* '<S52>/Gain4' */
  real_T Gain1;                        /* '<S61>/Gain1' */
  real_T ACC_z_B_mDs2;                 /* '<S52>/Gain5' */
  real_T ATT_Phi_rad_l;                /* '<S52>/Gain9' */
  real_T ATT_Theta_rad_k;              /* '<S52>/Gain10' */
  real_T ATT_Psi_rad_j;                /* '<S52>/Gain11' */
  real_T Switch1;                      /* '<S16>/Switch1' */
  real_T Switch;                       /* '<S16>/Switch' */
  real_T Switch2;                      /* '<S16>/Switch2' */
  real_T w_x_K_IB_B_radDs;             /* '<S52>/Gain6' */
  real_T w_y_K_IB_B_radDs;             /* '<S52>/Gain7' */
  real_T w_z_K_IB_B_radDs;             /* '<S52>/Gain8' */
  real_T Receive_from_FTHWICC_o1;      /* '<S37>/Receive_from_FTHWICC' */
  real_T Receive_from_FTHWICC_o2;      /* '<S37>/Receive_from_FTHWICC' */
  real_T Receive_from_FTHWICC_o3;      /* '<S37>/Receive_from_FTHWICC' */
  real_T Receive_from_FTHWICC_o4;      /* '<S37>/Receive_from_FTHWICC' */
  real_T Receive_from_FTHWICC_o5;      /* '<S37>/Receive_from_FTHWICC' */
  real_T Receive_from_FTHWICC_o6;      /* '<S37>/Receive_from_FTHWICC' */
  real_T Receive_from_FTHWICC_o7;      /* '<S37>/Receive_from_FTHWICC' */
  real_T Receive_from_FTHWICC_o9;      /* '<S37>/Receive_from_FTHWICC' */
  real_T Gimbal_Phi_Cmd_deg;           /* '<S49>/rad2deg' */
  real_T Gimbal_Theta_Cmd_deg;         /* '<S49>/rad2deg1' */
  real_T Gimbal_Psi_Cmd_deg;           /* '<S49>/rad2deg2' */
  real_T phi_rad;                      /* '<S25>/Gain2' */
  real_T Gain;                         /* '<S24>/Gain' */
  real_T Phi_Cmd_rad;                  /* '<S24>/Transfer Fcn' */
  real_T acc_y_mDs2;                   /* '<S25>/Gain' */
  real_T Sum3;                         /* '<S24>/Sum3' */
  real_T Psi_Cmd_rad;                  /* '<S24>/Gain2' */
  real_T acc_z_mDs2;                   /* '<S25>/Gain1' */
  real_T Sum1;                         /* '<S24>/Sum1' */
  real_T Theta_Cmd_rad;                /* '<S24>/Gain1' */
  real_T Merge3;                       /* '<S28>/Merge3' */
  real_T Fin_4_Cmd_rad;                /* '<S23>/Add14' */
  real_T pulse_width_ms;               /* '<S35>/Saturation' */
  real_T Merge2;                       /* '<S28>/Merge2' */
  real_T Fin_3_Cmd_rad;                /* '<S23>/Add13' */
  real_T pulse_width_ms_e;             /* '<S34>/Saturation' */
  real_T Merge1;                       /* '<S28>/Merge1' */
  real_T Fin_2_Cmd_rad;                /* '<S23>/Add12' */
  real_T pulse_width_ms_c;             /* '<S33>/Saturation' */
  real_T Merge;                        /* '<S28>/Merge' */
  real_T Fin_1_Cmd_rad;                /* '<S23>/Add15' */
  real_T pulse_width_ms_p;             /* '<S32>/Saturation' */
  real_T VEL_u_K_R_E_B_mDs;            /* '<S46>/Gain' */
  real_T VEL_u_K_R_E_B_mDs_e;          /* '<S52>/Gain' */
  real_T VEL_v_K_R_E_B_mDs;            /* '<S46>/Gain1' */
  real_T VEL_v_K_R_E_B_mDs_e;          /* '<S52>/Gain1' */
  real_T VEL_w_K_R_E_B_mDs;            /* '<S46>/Gain2' */
  real_T VEL_w_K_R_E_B_mDs_d;          /* '<S52>/Gain2' */
  real_T Saturation;                   /* '<S12>/Saturation' */
  real_T Saturation_c;                 /* '<S13>/Saturation' */
  real_T Saturation_j;                 /* '<S14>/Saturation' */
  real_T Saturation_a;                 /* '<S15>/Saturation' */
  real_T enable_gimbal_ctrl_flg;       /* '<S7>/Constant7' */
  real_T stop_gimbal_flg;              /* '<S7>/Constant8' */
  real_T Constant;                     /* '<S37>/Constant' */
  real_T POS_lambda_WGS84_rad;         /* '<S46>/Gain12' */
  real_T POS_mue_WGS84_rad;            /* '<S46>/Gain13' */
  real_T POS_h_WGS84_m;                /* '<S46>/Gain14' */
  real_T POS_x_NED_m;                  /* '<S46>/Gain15' */
  real_T POS_y_NED_m;                  /* '<S46>/Gain16' */
  real_T POS_z_NED_m;                  /* '<S46>/Gain17' */
  real_T Gain_o;                       /* '<S61>/Gain' */
  real_T DataTypeConversion;           /* '<S72>/Data Type Conversion' */
  real_T Product;                      /* '<S72>/Product' */
  real_T Product1;                     /* '<S72>/Product1' */
  real_T Product2;                     /* '<S72>/Product2' */
  real_T DataTypeConversion_d;         /* '<S74>/Data Type Conversion' */
  real_T Multiply;                     /* '<S74>/Multiply' */
  real_T DataTypeConversion_n;         /* '<S75>/Data Type Conversion' */
  real_T Product_b;                    /* '<S75>/Product' */
  real_T Product1_f;                   /* '<S75>/Product1' */
  real_T Product2_d;                   /* '<S75>/Product2' */
  real_T DataTypeConversion_k;         /* '<S76>/Data Type Conversion' */
  real_T Product_g;                    /* '<S76>/Product' */
  real_T Product1_g;                   /* '<S76>/Product1' */
  real_T Product2_d1;                  /* '<S76>/Product2' */
  real_T DataTypeConversion_e;         /* '<S77>/Data Type Conversion' */
  real_T Product_p;                    /* '<S77>/Product' */
  real_T Product1_o;                   /* '<S77>/Product1' */
  real_T Product2_n;                   /* '<S77>/Product2' */
  real_T OutportBufferFormotor_state_perc_dot;/* '<S60>/Subsystem' */
  real_T Clock;                        /* '<S68>/Clock' */
  real_T OutportBufferForthrust;       /* '<S67>/Constant' */
  real_T Add1;                         /* '<S67>/Add1' */
  real_T acc_x;                        /* '<S58>/MATLAB Function' */
  real_T acc_y;                        /* '<S58>/MATLAB Function' */
  real_T acc_z;                        /* '<S58>/MATLAB Function' */
  real_T OutportBufferForacc_x_drag_mDs2;/* '<S57>/Constant' */
  real_T OutportBufferForacc_y_drag_mDs2;/* '<S57>/Constant1' */
  real_T OutportBufferForacc_z_drag_mDs2;/* '<S57>/Constant2' */
  real_T Gimbal_operational_flg;
               /* '<S39>/BusConversion_InsertedFor_Gimbal_Status_at_inport_0' */
  real_T Gimbal_Ramp_flg;
               /* '<S39>/BusConversion_InsertedFor_Gimbal_Status_at_inport_0' */
  real_T Gimbal_Limit_flg;
               /* '<S39>/BusConversion_InsertedFor_Gimbal_Status_at_inport_0' */
  real_T Gimbal_StopSim_flg;
               /* '<S39>/BusConversion_InsertedFor_Gimbal_Status_at_inport_0' */
  real_T Data_plus;                    /* '<S43>/Constant' */
  real_T Data_minus;                   /* '<S43>/Constant1' */
  real_T Clock_plus;                   /* '<S43>/Constant2' */
  real_T Clock_minus;                  /* '<S43>/Constant3' */
  real_T Data_minus_o;                 /* '<S43>/Constant1' */
  real_T Clock_plus_f;                 /* '<S43>/Constant2' */
  real_T Clock_minus_c;                /* '<S43>/Constant3' */
  real_T Data_plus_j;                  /* '<S43>/Constant' */
  real_T Data_plus_p;                  /* '<S43>/Constant4' */
  real_T Data_minus_p;                 /* '<S43>/Constant5' */
  real_T Clock_plus_j;                 /* '<S43>/Constant6' */
  real_T Clock_minus_e;                /* '<S43>/Constant7' */
  real_T Data_plus_j1;                 /* '<S43>/Constant4' */
  real_T Data_minus_oy;                /* '<S43>/Constant5' */
  real_T Clock_plus_fx;                /* '<S43>/Constant6' */
  real_T Clock_minus_cm;               /* '<S43>/Constant7' */
  real_T Clock_plus_m;                 /* '<S43>/Constant10' */
  real_T Clock_minus_h;                /* '<S43>/Constant11' */
  real_T Data_plus_g;                  /* '<S43>/Constant8' */
  real_T Data_minus_d;                 /* '<S43>/Constant9' */
  real_T Clock_plus_fx0;               /* '<S43>/Constant10' */
  real_T Clock_minus_cmq;              /* '<S43>/Constant11' */
  real_T Data_plus_j13;                /* '<S43>/Constant8' */
  real_T Data_minus_oyn;               /* '<S43>/Constant9' */
  real_T ATT_Psi_rad_o;                /* '<S42>/Shaft2radYaw' */
  real_T ATT_Theta_rad_j;              /* '<S42>/Shaft2radPitch' */
  real_T ATT_Phi_rad_lz;               /* '<S42>/Shaft2radRoll' */
  real_T q0;                           /* '<S45>/q0' */
  real_T q1;                           /* '<S45>/q1' */
  real_T q2;                           /* '<S45>/q2' */
  real_T q3;                           /* '<S45>/q3' */
  real_T Gimbal_yaw_sns;
          /* '<S39>/BusConversion_InsertedFor_Gimbal_Pos_Encoder_at_inport_0' */
  real_T Gimbal_pitch_sns;
          /* '<S39>/BusConversion_InsertedFor_Gimbal_Pos_Encoder_at_inport_0' */
  real_T Gimbal_roll_sns;
          /* '<S39>/BusConversion_InsertedFor_Gimbal_Pos_Encoder_at_inport_0' */
  real_T Fin_3_Cmd_rad_o;
                        /* '<S20>/BusConversion_InsertedFor_hold_at_inport_0' */
  real_T Fin_4_Cmd_rad_c;
                        /* '<S20>/BusConversion_InsertedFor_hold_at_inport_0' */
  real_T pulse_width_ms_p2;
                        /* '<S20>/BusConversion_InsertedFor_hold_at_inport_0' */
  real_T pulse_width_ms_p2d;
                        /* '<S20>/BusConversion_InsertedFor_hold_at_inport_0' */
  real_T pulse_width_ms_p2de;
                        /* '<S20>/BusConversion_InsertedFor_hold_at_inport_0' */
  real_T pulse_width_ms_p2dee;
                        /* '<S20>/BusConversion_InsertedFor_hold_at_inport_0' */
  real_T Fin_1_Cmd_rad_l;
                        /* '<S20>/BusConversion_InsertedFor_hold_at_inport_0' */
  real_T Fin_2_Cmd_rad_e;
                        /* '<S20>/BusConversion_InsertedFor_hold_at_inport_0' */
  real_T ATT_Phi_rad_f;
                 /* '<S19>/BusConversion_InsertedFor_States_hold_at_inport_0' */
  real_T ACC_y_B_mDs2_o;
                 /* '<S19>/BusConversion_InsertedFor_States_hold_at_inport_0' */
  real_T ACC_z_B_mDs2_e;
                 /* '<S19>/BusConversion_InsertedFor_States_hold_at_inport_0' */
  real_T w_x_K_IB_B_radDs_f;
                 /* '<S19>/BusConversion_InsertedFor_States_hold_at_inport_0' */
  real_T w_y_K_IB_B_radDs_e;
                 /* '<S19>/BusConversion_InsertedFor_States_hold_at_inport_0' */
  real_T w_z_K_IB_B_radDs_n;
                 /* '<S19>/BusConversion_InsertedFor_States_hold_at_inport_0' */
  real_T CMD_phi_rad;
        /* '<S19>/BusConversion_InsertedFor_External_Inputs_hold_at_inport_0' */
  real_T CMD_acc_z_mDs2;
        /* '<S19>/BusConversion_InsertedFor_External_Inputs_hold_at_inport_0' */
  real_T CMD_acc_y_mDs2;
        /* '<S19>/BusConversion_InsertedFor_External_Inputs_hold_at_inport_0' */
  uint16_T Receive_from_FTHWICC_o8;    /* '<S37>/Receive_from_FTHWICC' */
  uint16_T DataTypeConversion1;        /* '<S79>/Data Type Conversion1' */
  uint16_T FixPtSwitch;                /* '<S82>/FixPt Switch' */
  boolean_T reset;                     /* '<S7>/Constant2' */
  boolean_T Equal;                     /* '<S18>/Equal' */
  boolean_T OR;                        /* '<S29>/OR' */
  boolean_T LogicalOperator_a;         /* '<S28>/Logical Operator' */
  boolean_T HiddenBuf_InsertedFor_Pass_at_inport_4;/* '<S28>/Logical Operator' */
  boolean_T HiddenBuf_InsertedFor_Saturate_at_inport_5;/* '<S28>/Check_Limit_exceeding' */
  boolean_T run;                       /* '<S7>/Constant' */
  boolean_T LogicalOperator2;          /* '<S7>/Logical Operator2' */
  boolean_T lock;                      /* '<S60>/lock' */
  boolean_T LogicalOperator1;          /* '<S60>/Logical Operator1' */
  boolean_T LogicalOperator_h;         /* '<S60>/Logical Operator' */
  boolean_T HiddenBuf_InsertedFor_hold_time_at_inport_0;/* '<S60>/Logical Operator' */
  boolean_T LogicalOperator2_m;        /* '<S60>/Logical Operator2' */
  boolean_T HiddenBuf_InsertedFor_Subsystem_at_inport_1;/* '<S60>/Logical Operator2' */
  B_Counter_with_external_limit_GRM_HIL_T sf_Counter_with_external_limit_b;/* '<S38>/Counter_with_external_limit' */
  B_Counter_with_external_limit_GRM_HIL_T sf_Counter_with_external_limit;/* '<S18>/Counter_with_external_limit' */
} B_GRM_HIL_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Memory_PreviousInput;         /* '<S18>/Memory' */
  real_T Memory_PreviousInput_g;       /* '<S38>/Memory' */
  struct {
    void *LoggedData[3];
  } ACC_PWORK;                         /* '<Root>/ACC' */

  struct {
    void *LoggedData[3];
  } ATT_PWORK;                         /* '<Root>/ATT' */

  struct {
    void *LoggedData[3];
  } CMD_PWORK;                         /* '<Root>/CMD' */

  struct {
    void *LoggedData[3];
  } ROT_PWORK;                         /* '<Root>/ROT' */

  void *Receive_from_FTHWICC_PWORK;    /* '<S37>/Receive_from_FTHWICC' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData[4];
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData[3];
  } VEL_PWORK;                         /* '<Root>/VEL' */

  void *RealTimeSynchronization_PWORK; /* '<S78>/Real-Time Synchronization' */
  void *Send_to_FTHWICC_PWORK[2];      /* '<S40>/Send_to_FTHWICC' */
  int32_T clockTickCounter;            /* '<S16>/Pulse Generator1' */
  int32_T clockTickCounter_d;          /* '<S16>/Pulse Generator' */
  int32_T clockTickCounter_d3;         /* '<S16>/Pulse Generator4' */
  int32_T clockTickCounter_e;          /* '<S16>/Pulse Generator3' */
  int32_T clockTickCounter_o;          /* '<S16>/Pulse Generator7' */
  int32_T clockTickCounter_l;          /* '<S16>/Pulse Generator6' */
  int_T Integrator_IWORK;              /* '<S74>/Integrator' */
  int_T Integrator_IWORK_i;            /* '<S72>/Integrator' */
  int_T Integrator1_IWORK;             /* '<S72>/Integrator1' */
  int_T Integrator2_IWORK;             /* '<S72>/Integrator2' */
  int_T Integrator_IWORK_ic;           /* '<S77>/Integrator' */
  int_T Integrator1_IWORK_g;           /* '<S77>/Integrator1' */
  int_T Integrator2_IWORK_m;           /* '<S77>/Integrator2' */
  int_T Integrator1_IWORK_n;           /* '<S76>/Integrator1' */
  int_T Integrator2_IWORK_e;           /* '<S76>/Integrator2' */
  int_T Integrator_IWORK_m;            /* '<S75>/Integrator' */
  int_T Integrator1_IWORK_m;           /* '<S75>/Integrator1' */
  int_T Integrator2_IWORK_c;           /* '<S75>/Integrator2' */
  int_T Integrator_IWORK_l;            /* '<S76>/Integrator' */
  uint16_T Output_DSTATE;              /* '<S80>/Output' */
  int8_T Synchronize_to_realtime_SubsysRanBC;/* '<S7>/Synchronize_to_realtime' */
  int8_T Propulsion_SubsysRanBC;       /* '<S54>/Propulsion' */
  int8_T hold_time_SubsysRanBC;        /* '<S60>/hold_time' */
  int8_T Subsystem_SubsysRanBC;        /* '<S60>/Subsystem' */
  int8_T Gravity_SubsysRanBC;          /* '<S54>/Gravity' */
  int8_T Drag_SubsysRanBC;             /* '<S54>/Drag' */
  int8_T Send_to_FTHWICC_SubsysRanBC;  /* '<S37>/Send_to_FTHWICC' */
  int8_T Construct_Bus_SubsysRanBC;    /* '<S37>/Construct_Bus' */
  int8_T FB_Com_freq_emul_SubsysRanBC; /* '<S17>/FB_Com_freq_emul' */
  int8_T Saturate_SubsysRanBC;         /* '<S28>/Saturate' */
  int8_T Pass_SubsysRanBC;             /* '<S28>/Pass' */
  int8_T Com_to_FCC_emul_SubsysRanBC;  /* '<S17>/Com_to_FCC_emul' */
  boolean_T lock_PreviousInput;        /* '<S60>/lock' */
  boolean_T Propulsion_MODE;           /* '<S54>/Propulsion' */
  boolean_T hold_time_MODE;            /* '<S60>/hold_time' */
  boolean_T Subsystem_MODE;            /* '<S60>/Subsystem' */
  boolean_T Gravity_MODE;              /* '<S54>/Gravity' */
  boolean_T Drag_MODE;                 /* '<S54>/Drag' */
  boolean_T Send_to_FTHWICC_MODE;      /* '<S37>/Send_to_FTHWICC' */
  boolean_T Saturate_MODE;             /* '<S28>/Saturate' */
  boolean_T Pass_MODE;                 /* '<S28>/Pass' */
  boolean_T Com_to_FCC_emul_MODE;      /* '<S17>/Com_to_FCC_emul' */
} DW_GRM_HIL_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S74>/Integrator' */
  real_T Integrator_CSTATE_k;          /* '<S72>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S72>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<S72>/Integrator2' */
  real_T TransferFcn_CSTATE[2];        /* '<S10>/Transfer Fcn' */
  real_T TransferFcn1_CSTATE[2];       /* '<S10>/Transfer Fcn1' */
  real_T TransferFcn2_CSTATE[2];       /* '<S10>/Transfer Fcn2' */
  real_T TransferFcn3_CSTATE[2];       /* '<S10>/Transfer Fcn3' */
  real_T dy2ay_CSTATE[2];              /* '<S54>/dy2ay' */
  real_T dp2az_CSTATE[2];              /* '<S54>/dp2az' */
  real_T dr2roll_CSTATE;               /* '<S54>/dr2roll' */
  real_T dp2pitch_CSTATE[2];           /* '<S54>/dp2pitch' */
  real_T dy2yaw_CSTATE[2];             /* '<S54>/dy2yaw' */
  real_T TransferFcn_CSTATE_j;         /* '<S24>/Transfer Fcn' */
  real_T TransferFcn2_CSTATE_e;        /* '<S24>/Transfer Fcn2' */
  real_T TransferFcn1_CSTATE_e;        /* '<S24>/Transfer Fcn1' */
  real_T Integrator_CSTATE_j;          /* '<S77>/Integrator' */
  real_T Integrator1_CSTATE_p;         /* '<S77>/Integrator1' */
  real_T Integrator2_CSTATE_a;         /* '<S77>/Integrator2' */
  real_T Integrator1_CSTATE_e;         /* '<S76>/Integrator1' */
  real_T Integrator2_CSTATE_d;         /* '<S76>/Integrator2' */
  real_T Integrator_CSTATE_d;          /* '<S75>/Integrator' */
  real_T Integrator1_CSTATE_eg;        /* '<S75>/Integrator1' */
  real_T Integrator2_CSTATE_e;         /* '<S75>/Integrator2' */
  real_T Integrator_CSTATE_jz;         /* '<S76>/Integrator' */
} X_GRM_HIL_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S74>/Integrator' */
  real_T Integrator_CSTATE_k;          /* '<S72>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S72>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<S72>/Integrator2' */
  real_T TransferFcn_CSTATE[2];        /* '<S10>/Transfer Fcn' */
  real_T TransferFcn1_CSTATE[2];       /* '<S10>/Transfer Fcn1' */
  real_T TransferFcn2_CSTATE[2];       /* '<S10>/Transfer Fcn2' */
  real_T TransferFcn3_CSTATE[2];       /* '<S10>/Transfer Fcn3' */
  real_T dy2ay_CSTATE[2];              /* '<S54>/dy2ay' */
  real_T dp2az_CSTATE[2];              /* '<S54>/dp2az' */
  real_T dr2roll_CSTATE;               /* '<S54>/dr2roll' */
  real_T dp2pitch_CSTATE[2];           /* '<S54>/dp2pitch' */
  real_T dy2yaw_CSTATE[2];             /* '<S54>/dy2yaw' */
  real_T TransferFcn_CSTATE_j;         /* '<S24>/Transfer Fcn' */
  real_T TransferFcn2_CSTATE_e;        /* '<S24>/Transfer Fcn2' */
  real_T TransferFcn1_CSTATE_e;        /* '<S24>/Transfer Fcn1' */
  real_T Integrator_CSTATE_j;          /* '<S77>/Integrator' */
  real_T Integrator1_CSTATE_p;         /* '<S77>/Integrator1' */
  real_T Integrator2_CSTATE_a;         /* '<S77>/Integrator2' */
  real_T Integrator1_CSTATE_e;         /* '<S76>/Integrator1' */
  real_T Integrator2_CSTATE_d;         /* '<S76>/Integrator2' */
  real_T Integrator_CSTATE_d;          /* '<S75>/Integrator' */
  real_T Integrator1_CSTATE_eg;        /* '<S75>/Integrator1' */
  real_T Integrator2_CSTATE_e;         /* '<S75>/Integrator2' */
  real_T Integrator_CSTATE_jz;         /* '<S76>/Integrator' */
} XDot_GRM_HIL_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S74>/Integrator' */
  boolean_T Integrator_CSTATE_k;       /* '<S72>/Integrator' */
  boolean_T Integrator1_CSTATE;        /* '<S72>/Integrator1' */
  boolean_T Integrator2_CSTATE;        /* '<S72>/Integrator2' */
  boolean_T TransferFcn_CSTATE[2];     /* '<S10>/Transfer Fcn' */
  boolean_T TransferFcn1_CSTATE[2];    /* '<S10>/Transfer Fcn1' */
  boolean_T TransferFcn2_CSTATE[2];    /* '<S10>/Transfer Fcn2' */
  boolean_T TransferFcn3_CSTATE[2];    /* '<S10>/Transfer Fcn3' */
  boolean_T dy2ay_CSTATE[2];           /* '<S54>/dy2ay' */
  boolean_T dp2az_CSTATE[2];           /* '<S54>/dp2az' */
  boolean_T dr2roll_CSTATE;            /* '<S54>/dr2roll' */
  boolean_T dp2pitch_CSTATE[2];        /* '<S54>/dp2pitch' */
  boolean_T dy2yaw_CSTATE[2];          /* '<S54>/dy2yaw' */
  boolean_T TransferFcn_CSTATE_j;      /* '<S24>/Transfer Fcn' */
  boolean_T TransferFcn2_CSTATE_e;     /* '<S24>/Transfer Fcn2' */
  boolean_T TransferFcn1_CSTATE_e;     /* '<S24>/Transfer Fcn1' */
  boolean_T Integrator_CSTATE_j;       /* '<S77>/Integrator' */
  boolean_T Integrator1_CSTATE_p;      /* '<S77>/Integrator1' */
  boolean_T Integrator2_CSTATE_a;      /* '<S77>/Integrator2' */
  boolean_T Integrator1_CSTATE_e;      /* '<S76>/Integrator1' */
  boolean_T Integrator2_CSTATE_d;      /* '<S76>/Integrator2' */
  boolean_T Integrator_CSTATE_d;       /* '<S75>/Integrator' */
  boolean_T Integrator1_CSTATE_eg;     /* '<S75>/Integrator1' */
  boolean_T Integrator2_CSTATE_e;      /* '<S75>/Integrator2' */
  boolean_T Integrator_CSTATE_jz;      /* '<S76>/Integrator' */
} XDis_GRM_HIL_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Integrator_Reset_ZCE;     /* '<S74>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_f;   /* '<S72>/Integrator' */
  ZCSigState Integrator1_Reset_ZCE;    /* '<S72>/Integrator1' */
  ZCSigState Integrator2_Reset_ZCE;    /* '<S72>/Integrator2' */
  ZCSigState Integrator_Reset_ZCE_i;   /* '<S77>/Integrator' */
  ZCSigState Integrator1_Reset_ZCE_p;  /* '<S77>/Integrator1' */
  ZCSigState Integrator2_Reset_ZCE_f;  /* '<S77>/Integrator2' */
  ZCSigState Integrator1_Reset_ZCE_d;  /* '<S76>/Integrator1' */
  ZCSigState Integrator2_Reset_ZCE_g;  /* '<S76>/Integrator2' */
  ZCSigState Integrator_Reset_ZCE_k;   /* '<S75>/Integrator' */
  ZCSigState Integrator1_Reset_ZCE_i;  /* '<S75>/Integrator1' */
  ZCSigState Integrator2_Reset_ZCE_m;  /* '<S75>/Integrator2' */
  ZCSigState Integrator_Reset_ZCE_ff;  /* '<S76>/Integrator' */
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
                                        *   '<S18>/Constant'
                                        *   '<S38>/Constant'
                                        */
  struct_0kz5Xf5aDCvwuRhz9h36UB FDM_Linear_FDM;/* Mask Parameter: FDM_Linear_FDM
                                                * Referenced by:
                                                *   '<S58>/Constant1'
                                                *   '<S73>/Constant'
                                                *   '<S73>/Constant1'
                                                *   '<S66>/Constant'
                                                *   '<S67>/Constant'
                                                *   '<S67>/Constant1'
                                                */
  struct_xafWrx5dwrT8wEsj34nY2B FDM_Linear_TF;/* Mask Parameter: FDM_Linear_TF
                                               * Referenced by:
                                               *   '<S54>/dp2az'
                                               *   '<S54>/dp2pitch'
                                               *   '<S54>/dr2roll'
                                               *   '<S54>/dy2ay'
                                               *   '<S54>/dy2yaw'
                                               */
  struct_Y7PS1rxhiw1TKkxrPVqWqG External_Inputs_External_Inputs;
                              /* Mask Parameter: External_Inputs_External_Inputs
                               * Referenced by:
                               *   '<S2>/Step'
                               *   '<S16>/Constant'
                               *   '<S16>/Constant1'
                               *   '<S16>/Constant2'
                               *   '<S16>/Constant3'
                               *   '<S16>/Constant4'
                               *   '<S16>/Constant5'
                               *   '<S16>/Pulse Generator'
                               *   '<S16>/Pulse Generator3'
                               *   '<S16>/Pulse Generator6'
                               */
  struct_FhGLidBATzAyVEgGPUcCPB Initial_States_Rigid_Body;
                                    /* Mask Parameter: Initial_States_Rigid_Body
                                     * Referenced by:
                                     *   '<S5>/Constant'
                                     *   '<S5>/Constant1'
                                     *   '<S5>/Constant10'
                                     *   '<S5>/Constant11'
                                     *   '<S5>/Constant12'
                                     *   '<S5>/Constant13'
                                     *   '<S5>/Constant14'
                                     *   '<S5>/Constant15'
                                     *   '<S5>/Constant16'
                                     *   '<S5>/Constant17'
                                     *   '<S5>/Constant2'
                                     *   '<S5>/Constant9'
                                     */
  struct_SpfmErt2JG4vKmjTJRH6OB FlightController_FCC;/* Mask Parameter: FlightController_FCC
                                                      * Referenced by:
                                                      *   '<S24>/Gain'
                                                      *   '<S24>/Gain1'
                                                      *   '<S24>/Gain2'
                                                      *   '<S24>/Gain3'
                                                      *   '<S24>/Gain4'
                                                      *   '<S24>/Transfer Fcn'
                                                      *   '<S24>/Transfer Fcn1'
                                                      *   '<S24>/Transfer Fcn2'
                                                      */
  struct_fqhbejXln8QRylaPqhUyTF Servo_TF;/* Mask Parameter: Servo_TF
                                          * Referenced by:
                                          *   '<S10>/Transfer Fcn'
                                          *   '<S10>/Transfer Fcn1'
                                          *   '<S10>/Transfer Fcn2'
                                          *   '<S10>/Transfer Fcn3'
                                          */
  struct_7SrGNOW0Gr039ZOMvXVVTD Servo_Cmd_PWM;/* Mask Parameter: Servo_Cmd_PWM
                                               * Referenced by:
                                               *   '<S32>/Constant2'
                                               *   '<S32>/Constant6'
                                               *   '<S32>/Saturation'
                                               *   '<S33>/Constant2'
                                               *   '<S33>/Constant6'
                                               *   '<S33>/Saturation'
                                               *   '<S34>/Constant2'
                                               *   '<S34>/Constant6'
                                               *   '<S34>/Saturation'
                                               *   '<S35>/Constant2'
                                               *   '<S35>/Constant6'
                                               *   '<S35>/Saturation'
                                               */
  struct_7SrGNOW0Gr039ZOMvXVVTD Servo_PWM;/* Mask Parameter: Servo_PWM
                                           * Referenced by:
                                           *   '<S12>/Constant'
                                           *   '<S12>/Constant1'
                                           *   '<S12>/Constant2'
                                           *   '<S12>/Saturation'
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
                                           */
  struct_skgRGNdg4uikkiJBtrraoB ReverseFinDeflection_Control_Surfaces;
                        /* Mask Parameter: ReverseFinDeflection_Control_Surfaces
                         * Referenced by:
                         *   '<S61>/Constant4'
                         *   '<S61>/Constant5'
                         *   '<S61>/Constant6'
                         *   '<S61>/Constant7'
                         */
  struct_skgRGNdg4uikkiJBtrraoB FinDeflection_Control_Surfaces;
                               /* Mask Parameter: FinDeflection_Control_Surfaces
                                * Referenced by:
                                *   '<S23>/Constant'
                                *   '<S23>/Constant1'
                                *   '<S23>/Constant2'
                                *   '<S23>/Constant3'
                                *   '<S23>/Constant4'
                                *   '<S23>/Limit2maxDeflection'
                                */
  struct_skgRGNdg4uikkiJBtrraoB Servo_Cmd_Control_Surfaces;
                                   /* Mask Parameter: Servo_Cmd_Control_Surfaces
                                    * Referenced by: '<S27>/Constant'
                                    */
  struct_RIcaXENoLMkyG3vAzx3LrF Communication_FT_HWI_ControlComputer_FTHWICC;
                 /* Mask Parameter: Communication_FT_HWI_ControlComputer_FTHWICC
                  * Referenced by: '<S40>/Send_to_FTHWICC'
                  */
  Airframe_States_Bus Initial_States_Airframe;
                                      /* Mask Parameter: Initial_States_Airframe
                                       * Referenced by: '<S5>/Constant18'
                                       */
  real_T RealTimeSynchronization_MaxMissedTicks;
                       /* Mask Parameter: RealTimeSynchronization_MaxMissedTicks
                        * Referenced by: '<S78>/Real-Time Synchronization'
                        */
  real_T Receive_from_FTHWICC_MaxMissedTicks;
                          /* Mask Parameter: Receive_from_FTHWICC_MaxMissedTicks
                           * Referenced by: '<S37>/Receive_from_FTHWICC'
                           */
  real_T Send_to_FTHWICC_YieldWhenWaiting;
                             /* Mask Parameter: Send_to_FTHWICC_YieldWhenWaiting
                              * Referenced by: '<S40>/Send_to_FTHWICC'
                              */
  real_T RealTimeSynchronization_YieldWhenWaiting;
                     /* Mask Parameter: RealTimeSynchronization_YieldWhenWaiting
                      * Referenced by: '<S78>/Real-Time Synchronization'
                      */
  real_T Receive_from_FTHWICC_YieldWhenWaiting;
                        /* Mask Parameter: Receive_from_FTHWICC_YieldWhenWaiting
                         * Referenced by: '<S37>/Receive_from_FTHWICC'
                         */
  int32_T Send_to_FTHWICC_PacketID;  /* Mask Parameter: Send_to_FTHWICC_PacketID
                                      * Referenced by: '<S40>/Send_to_FTHWICC'
                                      */
  int32_T Receive_from_FTHWICC_PacketID;
                                /* Mask Parameter: Receive_from_FTHWICC_PacketID
                                 * Referenced by: '<S37>/Receive_from_FTHWICC'
                                 */
  uint16_T WrapToZero_Threshold;       /* Mask Parameter: WrapToZero_Threshold
                                        * Referenced by: '<S82>/FixPt Switch'
                                        */
  struct_4BEF1wwN52Uf7px5A1b9LF States_hold_Y0;/* Computed Parameter: States_hold_Y0
                                                * Referenced by: '<S19>/States_hold'
                                                */
  struct_naMSiPeANZdxK1BVj547qE Gimbal_State_hold_Y0;
                                     /* Computed Parameter: Gimbal_State_hold_Y0
                                      * Referenced by: '<S19>/Gimbal_State_hold'
                                      */
  struct_F8un5srqOha4P4SBfdUeHD hold_Y0;/* Computed Parameter: hold_Y0
                                         * Referenced by: '<S20>/hold'
                                         */
  struct_VkUZsEuPLDWiHwBdN4zERD Gimbal_Pos_Encoder_Y0;
                                    /* Computed Parameter: Gimbal_Pos_Encoder_Y0
                                     * Referenced by: '<S39>/Gimbal_Pos_Encoder'
                                     */
  Simulation_Ctrl_Bus Simulation_Control_hold_Y0;
                               /* Computed Parameter: Simulation_Control_hold_Y0
                                * Referenced by: '<S19>/Simulation_Control_hold'
                                */
  struct_mYS1N2caX135AIcTArxUzD Gimbal_Pos_Y0;/* Computed Parameter: Gimbal_Pos_Y0
                                               * Referenced by: '<S39>/Gimbal_Pos'
                                               */
  struct_lQamzfSfua9vI4k5KcpdyB External_Inputs_hold_Y0;
                                  /* Computed Parameter: External_Inputs_hold_Y0
                                   * Referenced by: '<S19>/External_Inputs_hold'
                                   */
  Gimbal_Status_Bus Gimbal_Status_Y0;  /* Computed Parameter: Gimbal_Status_Y0
                                        * Referenced by: '<S39>/Gimbal_Status'
                                        */
  real_T Constant11_Value;             /* Expression: 1
                                        * Referenced by: '<S16>/Constant11'
                                        */
  real_T Constant14_Value;             /* Expression: 1
                                        * Referenced by: '<S16>/Constant14'
                                        */
  real_T Constant7_Value;              /* Expression: 1
                                        * Referenced by: '<S16>/Constant7'
                                        */
  real_T Constant12_Value;             /* Expression: 1
                                        * Referenced by: '<S16>/Constant12'
                                        */
  real_T Constant9_Value;              /* Expression: 1
                                        * Referenced by: '<S16>/Constant9'
                                        */
  real_T Constant13_Value;             /* Expression: 1
                                        * Referenced by: '<S16>/Constant13'
                                        */
  real_T ComCheck_Y0;                  /* Computed Parameter: ComCheck_Y0
                                        * Referenced by: '<S39>/ComCheck'
                                        */
  real_T Constant_Value;               /* Expression: -1
                                        * Referenced by: '<S43>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: -1
                                        * Referenced by: '<S43>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: -1
                                        * Referenced by: '<S43>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: -1
                                        * Referenced by: '<S43>/Constant3'
                                        */
  real_T Constant4_Value;              /* Expression: -1
                                        * Referenced by: '<S43>/Constant4'
                                        */
  real_T Constant5_Value;              /* Expression: -1
                                        * Referenced by: '<S43>/Constant5'
                                        */
  real_T Constant6_Value;              /* Expression: -1
                                        * Referenced by: '<S43>/Constant6'
                                        */
  real_T Constant7_Value_h;            /* Expression: -1
                                        * Referenced by: '<S43>/Constant7'
                                        */
  real_T Constant10_Value;             /* Expression: -1
                                        * Referenced by: '<S43>/Constant10'
                                        */
  real_T Constant11_Value_d;           /* Expression: -1
                                        * Referenced by: '<S43>/Constant11'
                                        */
  real_T Constant8_Value;              /* Expression: -1
                                        * Referenced by: '<S43>/Constant8'
                                        */
  real_T Constant9_Value_g;            /* Expression: -1
                                        * Referenced by: '<S43>/Constant9'
                                        */
  real_T Shaft2radYaw_Gain;            /* Expression: (2*pi)/(65536)
                                        * Referenced by: '<S42>/Shaft2radYaw'
                                        */
  real_T Shaft2radPitch_Gain;          /* Expression: (2*pi)/(65536)
                                        * Referenced by: '<S42>/Shaft2radPitch'
                                        */
  real_T Shaft2radRoll_Gain;           /* Expression: (2*pi)/(65536)
                                        * Referenced by: '<S42>/Shaft2radRoll'
                                        */
  real_T u2_Gain;                      /* Expression: 0.5
                                        * Referenced by: '<S45>/1//2'
                                        */
  real_T acc_x_drag_mDs2_Y0;           /* Expression: 0
                                        * Referenced by: '<S57>/acc_x_drag_mDs2'
                                        */
  real_T acc_y_drag_mDs2_Y0;           /* Expression: 0
                                        * Referenced by: '<S57>/acc_y_drag_mDs2'
                                        */
  real_T acc_z_drag_mDs2_Y0;           /* Expression: 0
                                        * Referenced by: '<S57>/acc_z_drag_mDs2'
                                        */
  real_T Constant_Value_d;             /* Expression: -1
                                        * Referenced by: '<S57>/Constant'
                                        */
  real_T Constant1_Value_o;            /* Expression: -1
                                        * Referenced by: '<S57>/Constant1'
                                        */
  real_T Constant2_Value_o;            /* Expression: -1
                                        * Referenced by: '<S57>/Constant2'
                                        */
  real_T acc_x_grav_mDs_Y0;            /* Expression: 0
                                        * Referenced by: '<S58>/acc_x_grav_mDs'
                                        */
  real_T acc_y_grav_mDs_Y0;            /* Expression: 0
                                        * Referenced by: '<S58>/acc_y_grav_mDs'
                                        */
  real_T acc_z_grav_mDs_Y0;            /* Expression: 0
                                        * Referenced by: '<S58>/acc_z_grav_mDs'
                                        */
  real_T thrust_Y0;                    /* Expression: 0
                                        * Referenced by: '<S67>/thrust'
                                        */
  real_T state_percentage_change_Y0;   /* Expression: 1
                                        * Referenced by: '<S67>/state_percentage_change'
                                        */
  real_T Constant2_Value_d;            /* Expression: 1
                                        * Referenced by: '<S67>/Constant2'
                                        */
  real_T exec_time_hold_s_Y0;         /* Computed Parameter: exec_time_hold_s_Y0
                                       * Referenced by: '<S68>/exec_time_hold_s'
                                       */
  real_T motor_state_perc_dot_Y0;      /* Expression: 0
                                        * Referenced by: '<S60>/motor_state_perc_dot'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<S2>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 1
                                        * Referenced by: '<S2>/Step'
                                        */
  real_T Gain18_Gain;                  /* Expression: 1
                                        * Referenced by: '<S46>/Gain18'
                                        */
  real_T Gain9_Gain;                   /* Expression: 1
                                        * Referenced by: '<S46>/Gain9'
                                        */
  real_T Gain10_Gain;                  /* Expression: 1
                                        * Referenced by: '<S46>/Gain10'
                                        */
  real_T Gain11_Gain;                  /* Expression: 1
                                        * Referenced by: '<S46>/Gain11'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1
                                        * Referenced by: '<S52>/Gain3'
                                        */
  real_T Gain_Gain;                    /* Expression: 1
                                        * Referenced by: '<S11>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1
                                        * Referenced by: '<S11>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1
                                        * Referenced by: '<S11>/Gain2'
                                        */
  real_T Gain3_Gain_d;                 /* Expression: 1
                                        * Referenced by: '<S11>/Gain3'
                                        */
  real_T Gain2_Gain_a;                 /* Expression: 1/4
                                        * Referenced by: '<S61>/Gain2'
                                        */
  real_T Gain4_Gain;                   /* Expression: 1
                                        * Referenced by: '<S52>/Gain4'
                                        */
  real_T Gain1_Gain_n;                 /* Expression: 1/4
                                        * Referenced by: '<S61>/Gain1'
                                        */
  real_T Gain5_Gain;                   /* Expression: 1
                                        * Referenced by: '<S52>/Gain5'
                                        */
  real_T Gain9_Gain_b;                 /* Expression: 1
                                        * Referenced by: '<S52>/Gain9'
                                        */
  real_T Gain10_Gain_f;                /* Expression: 1
                                        * Referenced by: '<S52>/Gain10'
                                        */
  real_T Gain11_Gain_d;                /* Expression: 1
                                        * Referenced by: '<S52>/Gain11'
                                        */
  real_T PulseGenerator1_Amp;          /* Expression: -2
                                        * Referenced by: '<S16>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Period;   /* Computed Parameter: PulseGenerator1_Period
                                    * Referenced by: '<S16>/Pulse Generator1'
                                    */
  real_T PulseGenerator1_Duty;       /* Computed Parameter: PulseGenerator1_Duty
                                      * Referenced by: '<S16>/Pulse Generator1'
                                      */
  real_T PulseGenerator1_PhaseDelay;
  /* Expression: External_Inputs.FCC.CMD.roll.pulse.delay_s+External_Inputs.FCC.CMD.roll.pulse.period_s
   * Referenced by: '<S16>/Pulse Generator1'
   */
  real_T PulseGenerator_Period;     /* Computed Parameter: PulseGenerator_Period
                                     * Referenced by: '<S16>/Pulse Generator'
                                     */
  real_T PulseGenerator_Duty;         /* Computed Parameter: PulseGenerator_Duty
                                       * Referenced by: '<S16>/Pulse Generator'
                                       */
  real_T PulseGenerator_PhaseDelay;
                       /* Expression: External_Inputs.FCC.CMD.roll.pulse.delay_s
                        * Referenced by: '<S16>/Pulse Generator'
                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S16>/Switch1'
                                        */
  real_T PulseGenerator4_Amp;          /* Expression: -2
                                        * Referenced by: '<S16>/Pulse Generator4'
                                        */
  real_T PulseGenerator4_Period;   /* Computed Parameter: PulseGenerator4_Period
                                    * Referenced by: '<S16>/Pulse Generator4'
                                    */
  real_T PulseGenerator4_Duty;       /* Computed Parameter: PulseGenerator4_Duty
                                      * Referenced by: '<S16>/Pulse Generator4'
                                      */
  real_T PulseGenerator4_PhaseDelay;
  /* Expression: External_Inputs.FCC.CMD.pitch.pulse.delay_s+External_Inputs.FCC.CMD.pitch.pulse.period_s
   * Referenced by: '<S16>/Pulse Generator4'
   */
  real_T PulseGenerator3_Period;   /* Computed Parameter: PulseGenerator3_Period
                                    * Referenced by: '<S16>/Pulse Generator3'
                                    */
  real_T PulseGenerator3_Duty;       /* Computed Parameter: PulseGenerator3_Duty
                                      * Referenced by: '<S16>/Pulse Generator3'
                                      */
  real_T PulseGenerator3_PhaseDelay;
                      /* Expression: External_Inputs.FCC.CMD.pitch.pulse.delay_s
                       * Referenced by: '<S16>/Pulse Generator3'
                       */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S16>/Switch'
                                        */
  real_T PulseGenerator7_Amp;          /* Expression: -2
                                        * Referenced by: '<S16>/Pulse Generator7'
                                        */
  real_T PulseGenerator7_Period;   /* Computed Parameter: PulseGenerator7_Period
                                    * Referenced by: '<S16>/Pulse Generator7'
                                    */
  real_T PulseGenerator7_Duty;       /* Computed Parameter: PulseGenerator7_Duty
                                      * Referenced by: '<S16>/Pulse Generator7'
                                      */
  real_T PulseGenerator7_PhaseDelay;
  /* Expression: External_Inputs.FCC.CMD.yaw.pulse.delay_s+External_Inputs.FCC.CMD.yaw.pulse.period_s
   * Referenced by: '<S16>/Pulse Generator7'
   */
  real_T PulseGenerator6_Period;   /* Computed Parameter: PulseGenerator6_Period
                                    * Referenced by: '<S16>/Pulse Generator6'
                                    */
  real_T PulseGenerator6_Duty;       /* Computed Parameter: PulseGenerator6_Duty
                                      * Referenced by: '<S16>/Pulse Generator6'
                                      */
  real_T PulseGenerator6_PhaseDelay;
                        /* Expression: External_Inputs.FCC.CMD.yaw.pulse.delay_s
                         * Referenced by: '<S16>/Pulse Generator6'
                         */
  real_T Switch2_Threshold;            /* Expression: 0
                                        * Referenced by: '<S16>/Switch2'
                                        */
  real_T Gain6_Gain;                   /* Expression: 1
                                        * Referenced by: '<S52>/Gain6'
                                        */
  real_T Gain7_Gain;                   /* Expression: 1
                                        * Referenced by: '<S52>/Gain7'
                                        */
  real_T Gain8_Gain;                   /* Expression: 1
                                        * Referenced by: '<S52>/Gain8'
                                        */
  real_T rad2deg_Gain;                 /* Expression: 360/(2*pi)
                                        * Referenced by: '<S49>/rad2deg'
                                        */
  real_T rad2deg1_Gain;                /* Expression: 360/(2*pi)
                                        * Referenced by: '<S49>/rad2deg1'
                                        */
  real_T rad2deg2_Gain;                /* Expression: 360/(2*pi)
                                        * Referenced by: '<S49>/rad2deg2'
                                        */
  real_T Constant1_Value_a;            /* Expression: 1
                                        * Referenced by: '<S18>/Constant1'
                                        */
  real_T Constant10_Value_l;
                /* Expression: HIL_Data.Simulation_Ctrl.Com_Ctrl.Pix.Com_freq_Hz
                 * Referenced by: '<S7>/Constant10'
                 */
  real_T Constant2_Value_a;            /* Expression: 1
                                        * Referenced by: '<S18>/Constant2'
                                        */
  real_T Memory_InitialCondition;      /* Expression: -1
                                        * Referenced by: '<S18>/Memory'
                                        */
  real_T Gain2_Gain_b;                 /* Expression: 1
                                        * Referenced by: '<S25>/Gain2'
                                        */
  real_T Gain_Gain_e;                  /* Expression: 1
                                        * Referenced by: '<S25>/Gain'
                                        */
  real_T Gain1_Gain_c;                 /* Expression: 1
                                        * Referenced by: '<S25>/Gain1'
                                        */
  real_T Gain_Gain_d;                  /* Expression: 1
                                        * Referenced by: '<S46>/Gain'
                                        */
  real_T Gain_Gain_k;                  /* Expression: 1
                                        * Referenced by: '<S52>/Gain'
                                        */
  real_T Gain1_Gain_i;                 /* Expression: 1
                                        * Referenced by: '<S46>/Gain1'
                                        */
  real_T Gain1_Gain_b;                 /* Expression: 1
                                        * Referenced by: '<S52>/Gain1'
                                        */
  real_T Gain2_Gain_l;                 /* Expression: 1
                                        * Referenced by: '<S46>/Gain2'
                                        */
  real_T Gain2_Gain_e;                 /* Expression: 1
                                        * Referenced by: '<S52>/Gain2'
                                        */
  real_T Constant7_Value_e;
          /* Expression: HIL_Data.Simulation_Ctrl.HW_Ctrl.enable_gimbal_ctrl_flg
           * Referenced by: '<S7>/Constant7'
           */
  real_T Constant8_Value_l;
                 /* Expression: HIL_Data.Simulation_Ctrl.HW_Ctrl.stop_gimbal_flg
                  * Referenced by: '<S7>/Constant8'
                  */
  real_T Constant_Value_b;             /* Expression: 0
                                        * Referenced by: '<S37>/Constant'
                                        */
  real_T Constant1_Value_h;            /* Expression: 1
                                        * Referenced by: '<S38>/Constant1'
                                        */
  real_T Constant11_Value_p;
                 /* Expression: HIL_Data.Simulation_Ctrl.Com_Ctrl.FT.Com_freq_Hz
                  * Referenced by: '<S7>/Constant11'
                  */
  real_T Constant2_Value_f;            /* Expression: 1
                                        * Referenced by: '<S38>/Constant2'
                                        */
  real_T Memory_InitialCondition_o;    /* Expression: -1
                                        * Referenced by: '<S38>/Memory'
                                        */
  real_T Gain12_Gain;                  /* Expression: 1
                                        * Referenced by: '<S46>/Gain12'
                                        */
  real_T Gain13_Gain;                  /* Expression: 1
                                        * Referenced by: '<S46>/Gain13'
                                        */
  real_T Gain14_Gain;                  /* Expression: 1
                                        * Referenced by: '<S46>/Gain14'
                                        */
  real_T Gain15_Gain;                  /* Expression: 1
                                        * Referenced by: '<S46>/Gain15'
                                        */
  real_T Gain16_Gain;                  /* Expression: 1
                                        * Referenced by: '<S46>/Gain16'
                                        */
  real_T Gain17_Gain;                  /* Expression: 1
                                        * Referenced by: '<S46>/Gain17'
                                        */
  real_T Gain_Gain_kk;                 /* Expression: 1/4
                                        * Referenced by: '<S61>/Gain'
                                        */
  uint16_T FCC_heartbeat_Y0;           /* Computed Parameter: FCC_heartbeat_Y0
                                        * Referenced by: '<S39>/FCC_heartbeat'
                                        */
  uint16_T Constant_Value_l;           /* Computed Parameter: Constant_Value_l
                                        * Referenced by: '<S82>/Constant'
                                        */
  uint16_T Output_InitialCondition;
                                  /* Computed Parameter: Output_InitialCondition
                                   * Referenced by: '<S80>/Output'
                                   */
  uint16_T FixPtConstant_Value;       /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S81>/FixPt Constant'
                                       */
  boolean_T Constant10_Value_c;
                /* Expression: External_Inputs.FCC.CMD.yaw.pulse.alternating_flg
                 * Referenced by: '<S16>/Constant10'
                 */
  boolean_T Constant6_Value_b;
               /* Expression: External_Inputs.FCC.CMD.roll.pulse.alternating_flg
                * Referenced by: '<S16>/Constant6'
                */
  boolean_T Constant8_Value_e;
              /* Expression: External_Inputs.FCC.CMD.pitch.pulse.alternating_flg
               * Referenced by: '<S16>/Constant8'
               */
  boolean_T lock_InitialCondition;  /* Computed Parameter: lock_InitialCondition
                                     * Referenced by: '<S60>/lock'
                                     */
  boolean_T Constant4_Value_g;         /* Computed Parameter: Constant4_Value_g
                                        * Referenced by: '<S7>/Constant4'
                                        */
  boolean_T Constant2_Value_f5;        /* Computed Parameter: Constant2_Value_f5
                                        * Referenced by: '<S7>/Constant2'
                                        */
  boolean_T Constant6_Value_k;         /* Computed Parameter: Constant6_Value_k
                                        * Referenced by: '<S7>/Constant6'
                                        */
  boolean_T Constant5_Value_k;         /* Computed Parameter: Constant5_Value_k
                                        * Referenced by: '<S7>/Constant5'
                                        */
  boolean_T Constant_Value_g;          /* Computed Parameter: Constant_Value_g
                                        * Referenced by: '<S7>/Constant'
                                        */
  boolean_T Constant3_Value_b;         /* Computed Parameter: Constant3_Value_b
                                        * Referenced by: '<S38>/Constant3'
                                        */
  boolean_T Constant1_Value_c;         /* Computed Parameter: Constant1_Value_c
                                        * Referenced by: '<S7>/Constant1'
                                        */
  boolean_T Constant9_Value_b;         /* Computed Parameter: Constant9_Value_b
                                        * Referenced by: '<S7>/Constant9'
                                        */
  boolean_T Constant3_Value_i;
                             /* Expression: HIL_Data.Simulation_Ctrl.offline_flg
                              * Referenced by: '<S7>/Constant3'
                              */
  uint8_T ManualSwitch_5_CurrentSetting;
                            /* Computed Parameter: ManualSwitch_5_CurrentSetting
                             * Referenced by: '<S50>/Manual Switch'
                             */
  uint8_T ManualSwitch_6_CurrentSetting;
                            /* Computed Parameter: ManualSwitch_6_CurrentSetting
                             * Referenced by: '<S50>/Manual Switch'
                             */
  uint8_T ManualSwitch_7_CurrentSetting;
                            /* Computed Parameter: ManualSwitch_7_CurrentSetting
                             * Referenced by: '<S50>/Manual Switch'
                             */
  uint8_T ManualSwitch_8_CurrentSetting;
                            /* Computed Parameter: ManualSwitch_8_CurrentSetting
                             * Referenced by: '<S50>/Manual Switch'
                             */
  uint8_T ManualSwitch_9_CurrentSetting;
                            /* Computed Parameter: ManualSwitch_9_CurrentSetting
                             * Referenced by: '<S50>/Manual Switch'
                             */
  uint8_T ManualSwitch_10_CurrentSetting;
                           /* Computed Parameter: ManualSwitch_10_CurrentSetting
                            * Referenced by: '<S50>/Manual Switch'
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
  real_T odeY[33];
  real_T odeF[3][33];
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
    uint32_T clockTick4;
    uint32_T clockTickH4;
    time_T stepSize4;
    boolean_T firstInitCondFlag;
    struct {
      uint8_T TID[5];
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
    time_T sampleTimesArray[5];
    time_T offsetTimesArray[5];
    int_T sampleTimeTaskIDArray[5];
    int_T sampleHitArray[5];
    int_T perTaskSampleHitsArray[25];
    time_T tArray[5];
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
 * '<S8>'   : 'GRM_HIL/Actuators/Emulate_Actuators'
 * '<S9>'   : 'GRM_HIL/Actuators/Emulate_Actuators/Encoder'
 * '<S10>'  : 'GRM_HIL/Actuators/Emulate_Actuators/Servo'
 * '<S11>'  : 'GRM_HIL/Actuators/Emulate_Actuators/Servo2Control_Surfaces'
 * '<S12>'  : 'GRM_HIL/Actuators/Emulate_Actuators/Servo/Servo_1'
 * '<S13>'  : 'GRM_HIL/Actuators/Emulate_Actuators/Servo/Servo_2'
 * '<S14>'  : 'GRM_HIL/Actuators/Emulate_Actuators/Servo/Servo_3'
 * '<S15>'  : 'GRM_HIL/Actuators/Emulate_Actuators/Servo/Servo_4'
 * '<S16>'  : 'GRM_HIL/External_Inputs/Commands_Generator'
 * '<S17>'  : 'GRM_HIL/FCC/Emulate_FCC'
 * '<S18>'  : 'GRM_HIL/FCC/Emulate_FCC/Com_Sync'
 * '<S19>'  : 'GRM_HIL/FCC/Emulate_FCC/Com_to_FCC_emul'
 * '<S20>'  : 'GRM_HIL/FCC/Emulate_FCC/FB_Com_freq_emul'
 * '<S21>'  : 'GRM_HIL/FCC/Emulate_FCC/FCC'
 * '<S22>'  : 'GRM_HIL/FCC/Emulate_FCC/Com_Sync/Counter_with_external_limit'
 * '<S23>'  : 'GRM_HIL/FCC/Emulate_FCC/FCC/Fin Deflection'
 * '<S24>'  : 'GRM_HIL/FCC/Emulate_FCC/FCC/Flight Controller'
 * '<S25>'  : 'GRM_HIL/FCC/Emulate_FCC/FCC/Guidance'
 * '<S26>'  : 'GRM_HIL/FCC/Emulate_FCC/FCC/Navigation'
 * '<S27>'  : 'GRM_HIL/FCC/Emulate_FCC/FCC/Servo_Cmd'
 * '<S28>'  : 'GRM_HIL/FCC/Emulate_FCC/FCC/Fin Deflection/Saturation'
 * '<S29>'  : 'GRM_HIL/FCC/Emulate_FCC/FCC/Fin Deflection/Saturation/Check_Limit_exceeding'
 * '<S30>'  : 'GRM_HIL/FCC/Emulate_FCC/FCC/Fin Deflection/Saturation/Pass'
 * '<S31>'  : 'GRM_HIL/FCC/Emulate_FCC/FCC/Fin Deflection/Saturation/Saturate'
 * '<S32>'  : 'GRM_HIL/FCC/Emulate_FCC/FCC/Servo_Cmd/Servo_1'
 * '<S33>'  : 'GRM_HIL/FCC/Emulate_FCC/FCC/Servo_Cmd/Servo_2'
 * '<S34>'  : 'GRM_HIL/FCC/Emulate_FCC/FCC/Servo_Cmd/Servo_3'
 * '<S35>'  : 'GRM_HIL/FCC/Emulate_FCC/FCC/Servo_Cmd/Servo_4'
 * '<S36>'  : 'GRM_HIL/Gimbal/Use_Gimbal_HWInterface_CC'
 * '<S37>'  : 'GRM_HIL/Gimbal/Use_Gimbal_HWInterface_CC/Communication_FT_HWI_ControlComputer'
 * '<S38>'  : 'GRM_HIL/Gimbal/Use_Gimbal_HWInterface_CC/Communication_FT_HWI_ControlComputer/Com_Sync'
 * '<S39>'  : 'GRM_HIL/Gimbal/Use_Gimbal_HWInterface_CC/Communication_FT_HWI_ControlComputer/Construct_Bus'
 * '<S40>'  : 'GRM_HIL/Gimbal/Use_Gimbal_HWInterface_CC/Communication_FT_HWI_ControlComputer/Send_to_FTHWICC'
 * '<S41>'  : 'GRM_HIL/Gimbal/Use_Gimbal_HWInterface_CC/Communication_FT_HWI_ControlComputer/Com_Sync/Counter_with_external_limit'
 * '<S42>'  : 'GRM_HIL/Gimbal/Use_Gimbal_HWInterface_CC/Communication_FT_HWI_ControlComputer/Construct_Bus/Assemble_Gimbal_Subbusses'
 * '<S43>'  : 'GRM_HIL/Gimbal/Use_Gimbal_HWInterface_CC/Communication_FT_HWI_ControlComputer/Construct_Bus/Assemble_Gimbal_Subbusses/Emulate_Encoder_Signals'
 * '<S44>'  : 'GRM_HIL/Gimbal/Use_Gimbal_HWInterface_CC/Communication_FT_HWI_ControlComputer/Construct_Bus/Assemble_Gimbal_Subbusses/Eul2Quat'
 * '<S45>'  : 'GRM_HIL/Gimbal/Use_Gimbal_HWInterface_CC/Communication_FT_HWI_ControlComputer/Construct_Bus/Assemble_Gimbal_Subbusses/Eul2Quat/Rotation Angles to Quaternions'
 * '<S46>'  : 'GRM_HIL/Initial_States/Assemble_States_Bus'
 * '<S47>'  : 'GRM_HIL/Initial_States/Assemble_States_Bus/Rotation Angles to Quaternions'
 * '<S48>'  : 'GRM_HIL/Simulation/FDM'
 * '<S49>'  : 'GRM_HIL/Simulation/Gimbel_Cmd'
 * '<S50>'  : 'GRM_HIL/Simulation/IMU_GPS_Emulator'
 * '<S51>'  : 'GRM_HIL/Simulation/FDM/FDM_Linear'
 * '<S52>'  : 'GRM_HIL/Simulation/FDM/FDM_Linear/Assemble_States_Bus'
 * '<S53>'  : 'GRM_HIL/Simulation/FDM/FDM_Linear/Flight_State'
 * '<S54>'  : 'GRM_HIL/Simulation/FDM/FDM_Linear/Motion_Kinematics'
 * '<S55>'  : 'GRM_HIL/Simulation/FDM/FDM_Linear/State_Integration'
 * '<S56>'  : 'GRM_HIL/Simulation/FDM/FDM_Linear/Assemble_States_Bus/Rotation Angles to Quaternions'
 * '<S57>'  : 'GRM_HIL/Simulation/FDM/FDM_Linear/Motion_Kinematics/Drag'
 * '<S58>'  : 'GRM_HIL/Simulation/FDM/FDM_Linear/Motion_Kinematics/Gravity'
 * '<S59>'  : 'GRM_HIL/Simulation/FDM/FDM_Linear/Motion_Kinematics/NED2PosWGS84Dot'
 * '<S60>'  : 'GRM_HIL/Simulation/FDM/FDM_Linear/Motion_Kinematics/Propulsion'
 * '<S61>'  : 'GRM_HIL/Simulation/FDM/FDM_Linear/Motion_Kinematics/Reverse Fin Deflection'
 * '<S62>'  : 'GRM_HIL/Simulation/FDM/FDM_Linear/Motion_Kinematics/pqr2EulerDot'
 * '<S63>'  : 'GRM_HIL/Simulation/FDM/FDM_Linear/Motion_Kinematics/uvw2PosNEDDot'
 * '<S64>'  : 'GRM_HIL/Simulation/FDM/FDM_Linear/Motion_Kinematics/Gravity/MATLAB Function'
 * '<S65>'  : 'GRM_HIL/Simulation/FDM/FDM_Linear/Motion_Kinematics/NED2PosWGS84Dot/MATLAB Function'
 * '<S66>'  : 'GRM_HIL/Simulation/FDM/FDM_Linear/Motion_Kinematics/Propulsion/Compare To Constant'
 * '<S67>'  : 'GRM_HIL/Simulation/FDM/FDM_Linear/Motion_Kinematics/Propulsion/Subsystem'
 * '<S68>'  : 'GRM_HIL/Simulation/FDM/FDM_Linear/Motion_Kinematics/Propulsion/hold_time'
 * '<S69>'  : 'GRM_HIL/Simulation/FDM/FDM_Linear/Motion_Kinematics/uvw2PosNEDDot/MATLAB Function'
 * '<S70>'  : 'GRM_HIL/Simulation/FDM/FDM_Linear/Motion_Kinematics/uvw2PosNEDDot/MATLAB Function1'
 * '<S71>'  : 'GRM_HIL/Simulation/FDM/FDM_Linear/Motion_Kinematics/uvw2PosNEDDot/MATLAB Function2'
 * '<S72>'  : 'GRM_HIL/Simulation/FDM/FDM_Linear/State_Integration/ATT_Integration'
 * '<S73>'  : 'GRM_HIL/Simulation/FDM/FDM_Linear/State_Integration/Mass_Balance'
 * '<S74>'  : 'GRM_HIL/Simulation/FDM/FDM_Linear/State_Integration/Motor_State_Integration'
 * '<S75>'  : 'GRM_HIL/Simulation/FDM/FDM_Linear/State_Integration/POS_NED_Integrator'
 * '<S76>'  : 'GRM_HIL/Simulation/FDM/FDM_Linear/State_Integration/POS_WGS84_Integrator'
 * '<S77>'  : 'GRM_HIL/Simulation/FDM/FDM_Linear/State_Integration/VEL_Integrator'
 * '<S78>'  : 'GRM_HIL/Simulation_Ctrl/Synchronize_to_realtime'
 * '<S79>'  : 'GRM_HIL/Simulation_Ctrl/hearbeat_SIM'
 * '<S80>'  : 'GRM_HIL/Simulation_Ctrl/hearbeat_SIM/Counter Free-Running'
 * '<S81>'  : 'GRM_HIL/Simulation_Ctrl/hearbeat_SIM/Counter Free-Running/Increment Real World'
 * '<S82>'  : 'GRM_HIL/Simulation_Ctrl/hearbeat_SIM/Counter Free-Running/Wrap To Zero'
 */
#endif                                 /* RTW_HEADER_GRM_HIL_h_ */
