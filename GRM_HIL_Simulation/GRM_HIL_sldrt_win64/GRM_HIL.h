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
 * C source code generated on : Sun Nov 17 18:40:04 2019
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

/* Block states (default storage) for system '<S53>/Enabled pass' */
typedef struct {
  int8_T Enabledpass_SubsysRanBC;      /* '<S53>/Enabled pass' */
  boolean_T Enabledpass_MODE;          /* '<S53>/Enabled pass' */
} DW_Enabledpass_GRM_HIL_T;

/* Block states (default storage) for system '<S54>/Saturation' */
typedef struct {
  int8_T Saturation_SubsysRanBC;       /* '<S54>/Saturation' */
} DW_Saturation_GRM_HIL_T;

/* Block states (default storage) for system '<S54>/pass' */
typedef struct {
  int8_T pass_SubsysRanBC;             /* '<S54>/pass' */
} DW_pass_GRM_HIL_T;

/* Block signals for system '<S174>/If Action Subsystem1' */
typedef struct {
  real_T In1;                          /* '<S178>/In1' */
} B_IfActionSubsystem1_GRM_HIL_T;

/* Block states (default storage) for system '<S174>/If Action Subsystem1' */
typedef struct {
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S174>/If Action Subsystem1' */
} DW_IfActionSubsystem1_GRM_HIL_T;

/* Block signals for system '<S174>/If Action Subsystem' */
typedef struct {
  real_T In1;                          /* '<S177>/In1' */
} B_IfActionSubsystem_GRM_HIL_T;

/* Block states (default storage) for system '<S174>/If Action Subsystem' */
typedef struct {
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S174>/If Action Subsystem' */
} DW_IfActionSubsystem_GRM_HIL_T;

/* Block states (default storage) for system '<S52>/If Action pass_yaw' */
typedef struct {
  int8_T IfActionpass_yaw_SubsysRanBC; /* '<S52>/If Action pass_yaw' */
} DW_IfActionpass_yaw_GRM_HIL_T;

/* Block signals (default storage) */
typedef struct {
  real_T motor_state_perc;             /* '<S189>/Gain18' */
  real_T ATT_Phi_rad;                  /* '<S189>/Gain9' */
  real_T ATT_Theta_rad;                /* '<S189>/Gain10' */
  real_T ATT_Psi_rad;                  /* '<S189>/Gain11' */
  real_T ACC_x_B_mDs2;                 /* '<S195>/Gain3' */
  real_T Gain2;                        /* '<S204>/Gain2' */
  real_T ACC_y_B_mDs2;                 /* '<S195>/Gain4' */
  real_T Gain1;                        /* '<S204>/Gain1' */
  real_T ACC_z_B_mDs2;                 /* '<S195>/Gain5' */
  real_T ATT_Phi_rad_l;                /* '<S195>/Gain9' */
  real_T ATT_Theta_rad_k;              /* '<S195>/Gain10' */
  real_T ATT_Psi_rad_j;                /* '<S195>/Gain11' */
  real_T Switch1;                      /* '<S16>/Switch1' */
  real_T Switch;                       /* '<S16>/Switch' */
  real_T Switch2;                      /* '<S16>/Switch2' */
  real_T w_x_K_IB_B_radDs;             /* '<S195>/Gain6' */
  real_T w_y_K_IB_B_radDs;             /* '<S195>/Gain7' */
  real_T w_z_K_IB_B_radDs;             /* '<S195>/Gain8' */
  real_T Gimbal_operational_flg;       /* '<S38>/Data Type Conversion1' */
  real_T Gimbal_Ramp_flg;              /* '<S38>/Data Type Conversion' */
  real_T Gimbal_Limit_flg;             /* '<S38>/Constant1' */
  real_T Gimbal_StopSim_flg;           /* '<S38>/Constant2' */
  real_T yaw_deg;                      /* '<S45>/Shaft2degYaw' */
  real_T Gain;                         /* '<S176>/Gain' */
  real_T pitch_deg;                    /* '<S45>/Shaft2degPitch' */
  real_T Gain_h;                       /* '<S174>/Gain' */
  real_T roll_deg;                     /* '<S45>/Shaft2degRoll' */
  real_T Gain_j;                       /* '<S175>/Gain' */
  real_T Merge;                        /* '<S72>/Merge' */
  real_T Switch2_p;                    /* '<S72>/Switch2' */
  real_T Gain_e;                       /* '<S72>/Gain' */
  real_T Merge1;                       /* '<S72>/Merge1' */
  real_T Switch1_h;                    /* '<S72>/Switch1' */
  real_T Gimbal_Phi_Cmd_deg;           /* '<S192>/rad2deg' */
  real_T Product;                      /* '<S48>/Product' */
  real_T Yaw_err;                      /* '<S48>/Sum' */
  real_T Integrator;                   /* '<S73>/Integrator' */
  real_T Filter;                       /* '<S73>/Filter' */
  real_T FilterCoefficient;            /* '<S73>/Filter Coefficient' */
  real_T Merge_f;                      /* '<S73>/Merge' */
  real_T Merge_a;                      /* '<S71>/Merge' */
  real_T Merge_m;                      /* '<S53>/Merge' */
  real_T Switch2_h;                    /* '<S53>/Switch2' */
  real_T Gain_hi;                      /* '<S53>/Gain' */
  real_T Merge1_j;                     /* '<S53>/Merge1' */
  real_T Switch1_f;                    /* '<S53>/Switch1' */
  real_T Gimbal_Theta_Cmd_deg;         /* '<S192>/rad2deg1' */
  real_T pitch_cmd;                    /* '<S46>/Product' */
  real_T pitch_err;                    /* '<S46>/Sum2' */
  real_T Integrator_o;                 /* '<S54>/Integrator' */
  real_T Filter_m;                     /* '<S54>/Filter' */
  real_T FilterCoefficient_a;          /* '<S54>/Filter Coefficient' */
  real_T Merge_fu;                     /* '<S54>/Merge' */
  real_T Merge_h;                      /* '<S62>/Merge' */
  real_T Switch2_i;                    /* '<S62>/Switch2' */
  real_T Gain_l;                       /* '<S62>/Gain' */
  real_T Merge1_k;                     /* '<S62>/Merge1' */
  real_T Switch1_l;                    /* '<S62>/Switch1' */
  real_T Gimbal_Psi_Cmd_deg;           /* '<S192>/rad2deg2' */
  real_T Product1;                     /* '<S47>/Product1' */
  real_T Roll_err;                     /* '<S47>/Sum1' */
  real_T Integrator_a;                 /* '<S63>/Integrator' */
  real_T Filter_n;                     /* '<S63>/Filter' */
  real_T FilterCoefficient_l;          /* '<S63>/Filter Coefficient' */
  real_T Merge_c;                      /* '<S63>/Merge' */
  real_T Merge_o;                      /* '<S45>/Merge' */
  real_T Merge1_o;                     /* '<S45>/Merge1' */
  real_T Sum2;                         /* '<S39>/Sum2' */
  real_T ATT_Phi_rad_a;                /* '<S40>/Shaft2radRoll' */
  real_T Merge2;                       /* '<S45>/Merge2' */
  real_T Sum1;                         /* '<S39>/Sum1' */
  real_T ATT_Theta_rad_i;              /* '<S40>/Shaft2radPitch' */
  real_T Sum;                          /* '<S39>/Sum' */
  real_T ATT_Psi_rad_g;                /* '<S40>/Shaft2radYaw' */
  real_T q0;                           /* '<S43>/q0' */
  real_T q1;                           /* '<S43>/q1' */
  real_T q2;                           /* '<S43>/q2' */
  real_T q3;                           /* '<S43>/q3' */
  real_T Data_plus;                    /* '<S41>/Constant' */
  real_T Data_minus;                   /* '<S41>/Constant1' */
  real_T Clock_plus;                   /* '<S41>/Constant2' */
  real_T Clock_minus;                  /* '<S41>/Constant3' */
  real_T Data_plus_a;                  /* '<S41>/Constant4' */
  real_T Data_minus_k;                 /* '<S41>/Constant5' */
  real_T Clock_plus_c;                 /* '<S41>/Constant6' */
  real_T Clock_minus_i;                /* '<S41>/Constant7' */
  real_T Data_plus_k;                  /* '<S41>/Constant8' */
  real_T Data_minus_kw;                /* '<S41>/Constant9' */
  real_T Clock_plus_b;                 /* '<S41>/Constant10' */
  real_T Clock_minus_g;                /* '<S41>/Constant11' */
  real_T phi_rad;                      /* '<S25>/Gain2' */
  real_T Gain_a;                       /* '<S24>/Gain' */
  real_T Phi_Cmd_rad;                  /* '<S24>/Transfer Fcn' */
  real_T acc_y_mDs2;                   /* '<S25>/Gain' */
  real_T Sum3;                         /* '<S24>/Sum3' */
  real_T Psi_Cmd_rad;                  /* '<S24>/Gain2' */
  real_T acc_z_mDs2;                   /* '<S25>/Gain1' */
  real_T Sum1_d;                       /* '<S24>/Sum1' */
  real_T Theta_Cmd_rad;                /* '<S24>/Gain1' */
  real_T Merge3;                       /* '<S28>/Merge3' */
  real_T Fin_4_Cmd_rad;                /* '<S23>/Add14' */
  real_T pulse_width_ms;               /* '<S35>/Saturation' */
  real_T Merge2_i;                     /* '<S28>/Merge2' */
  real_T Fin_3_Cmd_rad;                /* '<S23>/Add13' */
  real_T pulse_width_ms_e;             /* '<S34>/Saturation' */
  real_T Merge1_n;                     /* '<S28>/Merge1' */
  real_T Fin_2_Cmd_rad;                /* '<S23>/Add12' */
  real_T pulse_width_ms_c;             /* '<S33>/Saturation' */
  real_T Merge_n;                      /* '<S28>/Merge' */
  real_T Fin_1_Cmd_rad;                /* '<S23>/Add15' */
  real_T pulse_width_ms_p;             /* '<S32>/Saturation' */
  real_T VEL_u_K_R_E_B_mDs;            /* '<S189>/Gain' */
  real_T VEL_u_K_R_E_B_mDs_e;          /* '<S195>/Gain' */
  real_T VEL_v_K_R_E_B_mDs;            /* '<S189>/Gain1' */
  real_T VEL_v_K_R_E_B_mDs_e;          /* '<S195>/Gain1' */
  real_T VEL_w_K_R_E_B_mDs;            /* '<S189>/Gain2' */
  real_T VEL_w_K_R_E_B_mDs_d;          /* '<S195>/Gain2' */
  real_T Saturation_o;                 /* '<S12>/Saturation' */
  real_T Saturation_c;                 /* '<S13>/Saturation' */
  real_T Saturation_jy;                /* '<S14>/Saturation' */
  real_T Saturation_a;                 /* '<S15>/Saturation' */
  real_T SumI1;                        /* '<S54>/SumI1' */
  real_T SumI1_n;                      /* '<S63>/SumI1' */
  real_T SumI1_i;                      /* '<S73>/SumI1' */
  real_T DataTypeConversion;           /* '<S49>/Data Type Conversion' */
  real_T Samp_freq;                    /* '<S45>/Samp_Freq' */
  real_T POS_lambda_WGS84_rad;         /* '<S189>/Gain12' */
  real_T POS_mue_WGS84_rad;            /* '<S189>/Gain13' */
  real_T POS_h_WGS84_m;                /* '<S189>/Gain14' */
  real_T POS_x_NED_m;                  /* '<S189>/Gain15' */
  real_T POS_y_NED_m;                  /* '<S189>/Gain16' */
  real_T POS_z_NED_m;                  /* '<S189>/Gain17' */
  real_T Gain_o;                       /* '<S204>/Gain' */
  real_T DataTypeConversion_i;         /* '<S215>/Data Type Conversion' */
  real_T Product_f;                    /* '<S215>/Product' */
  real_T Product1_j;                   /* '<S215>/Product1' */
  real_T Product2;                     /* '<S215>/Product2' */
  real_T DataTypeConversion_d;         /* '<S217>/Data Type Conversion' */
  real_T Multiply;                     /* '<S217>/Multiply' */
  real_T DataTypeConversion_n;         /* '<S218>/Data Type Conversion' */
  real_T Product_b;                    /* '<S218>/Product' */
  real_T Product1_f;                   /* '<S218>/Product1' */
  real_T Product2_d;                   /* '<S218>/Product2' */
  real_T DataTypeConversion_k;         /* '<S219>/Data Type Conversion' */
  real_T Product_g;                    /* '<S219>/Product' */
  real_T Product1_g;                   /* '<S219>/Product1' */
  real_T Product2_d1;                  /* '<S219>/Product2' */
  real_T DataTypeConversion_e;         /* '<S220>/Data Type Conversion' */
  real_T Product_p;                    /* '<S220>/Product' */
  real_T Product1_o;                   /* '<S220>/Product1' */
  real_T Product2_n;                   /* '<S220>/Product2' */
  real_T OutportBufferFormotor_state_perc_dot;/* '<S203>/Subsystem' */
  real_T Clock;                        /* '<S211>/Clock' */
  real_T OutportBufferForthrust;       /* '<S210>/Constant' */
  real_T Add1;                         /* '<S210>/Add1' */
  real_T acc_x;                        /* '<S201>/MATLAB Function' */
  real_T acc_y;                        /* '<S201>/MATLAB Function' */
  real_T acc_z;                        /* '<S201>/MATLAB Function' */
  real_T OutportBufferForacc_x_drag_mDs2;/* '<S200>/Constant' */
  real_T OutportBufferForacc_y_drag_mDs2;/* '<S200>/Constant1' */
  real_T OutportBufferForacc_z_drag_mDs2;/* '<S200>/Constant2' */
  real_T Abs1;                         /* '<S52>/Abs1' */
  real_T Abs3;                         /* '<S52>/Abs3' */
  real_T Abs5;                         /* '<S52>/Abs5' */
  real_T Abs;                          /* '<S168>/Abs' */
  real_T FilterCoefficient_f;          /* '<S110>/Filter Coefficient' */
  real_T FilterCoefficient_j;          /* '<S154>/Filter Coefficient' */
  real_T SumI4;                        /* '<S100>/SumI4' */
  real_T SumI4_c;                      /* '<S144>/SumI4' */
  real_T Abs_j;                        /* '<S66>/Abs' */
  real_T Abs_b;                        /* '<S57>/Abs' */
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
  real_T value;                        /* '<S18>/Counter_with_external_limit' */
  boolean_T LogicalOperator;           /* '<S72>/Logical Operator' */
  boolean_T HiddenBuf_InsertedFor_Enabledadapt_at_inport_3;/* '<S72>/Logical Operator' */
  boolean_T LogicalOperator1;          /* '<S72>/Logical Operator1' */
  boolean_T Switch_g;                  /* '<S72>/Switch' */
  boolean_T HiddenBuf_InsertedFor_Saturation_at_inport_3;
  boolean_T LogicalOperator_o;         /* '<S73>/Logical Operator' */
  boolean_T LogicalOperator_a;         /* '<S53>/Logical Operator' */
  boolean_T HiddenBuf_InsertedFor_Enabledadapt_at_inport_3_h;/* '<S53>/Logical Operator' */
  boolean_T LogicalOperator1_i;        /* '<S53>/Logical Operator1' */
  boolean_T Switch_a;                  /* '<S53>/Switch' */
  boolean_T HiddenBuf_InsertedFor_Saturation_at_inport_3_k;
  boolean_T LogicalOperator_n;         /* '<S54>/Logical Operator' */
  boolean_T LogicalOperator_b;         /* '<S62>/Logical Operator' */
  boolean_T HiddenBuf_InsertedFor_Enabledadapt_at_inport_3_hn;/* '<S62>/Logical Operator' */
  boolean_T LogicalOperator1_k;        /* '<S62>/Logical Operator1' */
  boolean_T Switch_p;                  /* '<S62>/Switch' */
  boolean_T HiddenBuf_InsertedFor_Saturation_at_inport_3_kk;
  boolean_T LogicalOperator_p;         /* '<S63>/Logical Operator' */
  boolean_T LogicalOperator_c;         /* '<S45>/Logical Operator' */
  boolean_T Equal;                     /* '<S18>/Equal' */
  boolean_T OR;                        /* '<S29>/OR' */
  boolean_T LogicalOperator_at;        /* '<S28>/Logical Operator' */
  boolean_T HiddenBuf_InsertedFor_Pass_at_inport_4;/* '<S28>/Logical Operator' */
  boolean_T HiddenBuf_InsertedFor_Saturate_at_inport_5;/* '<S28>/Check_Limit_exceeding' */
  boolean_T cmd_pass_enable_flg;       /* '<S39>/Data Type Conversion' */
  boolean_T emergency_stop_flg;        /* '<S39>/Data Type Conversion1' */
  boolean_T LogicalOperator2;          /* '<S7>/Logical Operator2' */
  boolean_T lock;                      /* '<S203>/lock' */
  boolean_T LogicalOperator1_ii;       /* '<S203>/Logical Operator1' */
  boolean_T LogicalOperator_h;         /* '<S203>/Logical Operator' */
  boolean_T HiddenBuf_InsertedFor_hold_time_at_inport_0;/* '<S203>/Logical Operator' */
  boolean_T LogicalOperator2_m;        /* '<S203>/Logical Operator2' */
  boolean_T HiddenBuf_InsertedFor_Subsystem_at_inport_1;/* '<S203>/Logical Operator2' */
  B_IfActionSubsystem_GRM_HIL_T IfActionSubsystem_m;/* '<S176>/If Action Subsystem' */
  B_IfActionSubsystem1_GRM_HIL_T IfActionSubsystem1_e;/* '<S176>/If Action Subsystem1' */
  B_IfActionSubsystem_GRM_HIL_T IfActionSubsystem_p;/* '<S175>/If Action Subsystem' */
  B_IfActionSubsystem1_GRM_HIL_T IfActionSubsystem1_j;/* '<S175>/If Action Subsystem1' */
  B_IfActionSubsystem_GRM_HIL_T IfActionSubsystem;/* '<S174>/If Action Subsystem' */
  B_IfActionSubsystem1_GRM_HIL_T IfActionSubsystem1;/* '<S174>/If Action Subsystem1' */
} B_GRM_HIL_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Memory1_1_PreviousInput;      /* '<S36>/Memory1' */
  real_T Memory1_2_PreviousInput;      /* '<S36>/Memory1' */
  real_T Memory1_3_PreviousInput;      /* '<S36>/Memory1' */
  real_T Memory_PreviousInput;         /* '<S18>/Memory' */
  struct {
    real_T modelTStart;
    real_T TUbufferArea[2048];
  } TransportDelay_RWORK;              /* '<S176>/Transport Delay' */

  struct {
    real_T modelTStart;
    real_T TUbufferArea[2048];
  } TransportDelay_RWORK_l;            /* '<S174>/Transport Delay' */

  struct {
    real_T modelTStart;
    real_T TUbufferArea[2048];
  } TransportDelay_RWORK_b;            /* '<S175>/Transport Delay' */

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

  struct {
    void *TUbufferPtrs[2];
  } TransportDelay_PWORK;              /* '<S176>/Transport Delay' */

  struct {
    void *TUbufferPtrs[2];
  } TransportDelay_PWORK_j;            /* '<S174>/Transport Delay' */

  struct {
    void *TUbufferPtrs[2];
  } TransportDelay_PWORK_l;            /* '<S175>/Transport Delay' */

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

  struct {
    void *LoggedData;
  } Roll_PWORK;                        /* '<S45>/Roll' */

  struct {
    void *LoggedData;
  } pitch_PWORK;                       /* '<S45>/pitch' */

  struct {
    void *LoggedData;
  } scopeyawpitchroll_PWORK;           /* '<S45>/scope yaw,pitch,roll' */

  struct {
    void *LoggedData;
  } yaw_PWORK;                         /* '<S45>/yaw' */

  struct {
    void *LoggedData;
  } Velocity_pitch_PWORK;              /* '<S174>/Velocity_pitch' */

  struct {
    void *LoggedData;
  } Velocity_roll_PWORK;               /* '<S175>/Velocity_roll' */

  struct {
    void *LoggedData;
  } velocity_yaw_PWORK;                /* '<S176>/velocity_yaw' */

  void *RealTimeSynchronization_PWORK; /* '<S221>/Real-Time Synchronization' */
  int32_T clockTickCounter;            /* '<S16>/Pulse Generator1' */
  int32_T clockTickCounter_d;          /* '<S16>/Pulse Generator' */
  int32_T clockTickCounter_d3;         /* '<S16>/Pulse Generator4' */
  int32_T clockTickCounter_e;          /* '<S16>/Pulse Generator3' */
  int32_T clockTickCounter_o;          /* '<S16>/Pulse Generator7' */
  int32_T clockTickCounter_l;          /* '<S16>/Pulse Generator6' */
  int_T Integrator_IWORK;              /* '<S217>/Integrator' */
  int_T Integrator_IWORK_i;            /* '<S215>/Integrator' */
  int_T Integrator1_IWORK;             /* '<S215>/Integrator1' */
  int_T Integrator2_IWORK;             /* '<S215>/Integrator2' */
  struct {
    int_T Tail;
    int_T Head;
    int_T Last;
    int_T CircularBufSize;
  } TransportDelay_IWORK;              /* '<S176>/Transport Delay' */

  struct {
    int_T Tail;
    int_T Head;
    int_T Last;
    int_T CircularBufSize;
  } TransportDelay_IWORK_i;            /* '<S174>/Transport Delay' */

  struct {
    int_T Tail;
    int_T Head;
    int_T Last;
    int_T CircularBufSize;
  } TransportDelay_IWORK_k;            /* '<S175>/Transport Delay' */

  int_T Integrator_IWORK_ic;           /* '<S220>/Integrator' */
  int_T Integrator1_IWORK_g;           /* '<S220>/Integrator1' */
  int_T Integrator2_IWORK_m;           /* '<S220>/Integrator2' */
  int_T Integrator1_IWORK_n;           /* '<S219>/Integrator1' */
  int_T Integrator2_IWORK_e;           /* '<S219>/Integrator2' */
  int_T Integrator_IWORK_m;            /* '<S218>/Integrator' */
  int_T Integrator1_IWORK_m;           /* '<S218>/Integrator1' */
  int_T Integrator2_IWORK_c;           /* '<S218>/Integrator2' */
  int_T Integrator_IWORK_l;            /* '<S219>/Integrator' */
  int8_T If_ActiveSubsystem;           /* '<S176>/If' */
  int8_T If_ActiveSubsystem_l;         /* '<S174>/If' */
  int8_T If_ActiveSubsystem_g;         /* '<S175>/If' */
  int8_T Synchronize_to_realtime_SubsysRanBC;/* '<S7>/Synchronize_to_realtime' */
  int8_T Propulsion_SubsysRanBC;       /* '<S197>/Propulsion' */
  int8_T hold_time_SubsysRanBC;        /* '<S203>/hold_time' */
  int8_T Subsystem_SubsysRanBC;        /* '<S203>/Subsystem' */
  int8_T Gravity_SubsysRanBC;          /* '<S197>/Gravity' */
  int8_T Drag_SubsysRanBC;             /* '<S197>/Drag' */
  int8_T Voltage_Limitations_SubsysRanBC;/* '<S45>/Voltage_Limitations' */
  int8_T If_ActiveSubsystem_a;         /* '<S52>/If' */
  int8_T If1_ActiveSubsystem;          /* '<S52>/If1' */
  int8_T If2_ActiveSubsystem;          /* '<S52>/If2' */
  int8_T IfActionlimit_roll_SubsysRanBC;/* '<S52>/If Action limit_roll' */
  int8_T IfActionlimit_pitch_SubsysRanBC;/* '<S52>/If Action limit_pitch' */
  int8_T IfActionlimit_yaw_SubsysRanBC;/* '<S52>/If Action limit_yaw' */
  int8_T IfActionPass_SubsysRanBC;     /* '<S45>/If Action Pass' */
  int8_T Enabledadapt_SubsysRanBC;     /* '<S72>/Enabled adapt' */
  int8_T pass_SubsysRanBC;             /* '<S71>/pass' */
  int8_T Control_Limits_SubsysRanBC;   /* '<S71>/Control_Limits' */
  int8_T Enabledadapt_SubsysRanBC_b;   /* '<S62>/Enabled adapt' */
  int8_T Enabledadapt_SubsysRanBC_g;   /* '<S53>/Enabled adapt' */
  int8_T FB_Com_freq_emul_SubsysRanBC; /* '<S17>/FB_Com_freq_emul' */
  int8_T Saturate_SubsysRanBC;         /* '<S28>/Saturate' */
  int8_T Pass_SubsysRanBC;             /* '<S28>/Pass' */
  int8_T Com_to_FCC_emul_SubsysRanBC;  /* '<S17>/Com_to_FCC_emul' */
  boolean_T Memory_1_PreviousInput;    /* '<S36>/Memory' */
  boolean_T Memory_2_PreviousInput;    /* '<S36>/Memory' */
  boolean_T lock_PreviousInput;        /* '<S203>/lock' */
  boolean_T Propulsion_MODE;           /* '<S197>/Propulsion' */
  boolean_T hold_time_MODE;            /* '<S203>/hold_time' */
  boolean_T Subsystem_MODE;            /* '<S203>/Subsystem' */
  boolean_T Gravity_MODE;              /* '<S197>/Gravity' */
  boolean_T Drag_MODE;                 /* '<S197>/Drag' */
  boolean_T Voltage_Limitations_MODE;  /* '<S45>/Voltage_Limitations' */
  boolean_T IfActionPass_MODE;         /* '<S45>/If Action Pass' */
  boolean_T Enabledadapt_MODE;         /* '<S72>/Enabled adapt' */
  boolean_T Control_Limits_MODE;       /* '<S71>/Control_Limits' */
  boolean_T Enabledadapt_MODE_h;       /* '<S62>/Enabled adapt' */
  boolean_T Enabledadapt_MODE_n;       /* '<S53>/Enabled adapt' */
  boolean_T Saturate_MODE;             /* '<S28>/Saturate' */
  boolean_T Pass_MODE;                 /* '<S28>/Pass' */
  boolean_T Com_to_FCC_emul_MODE;      /* '<S17>/Com_to_FCC_emul' */
  DW_IfActionpass_yaw_GRM_HIL_T IfActionpass_roll;/* '<S52>/If Action pass_roll' */
  DW_IfActionpass_yaw_GRM_HIL_T IfActionpass_pitch;/* '<S52>/If Action pass_pitch' */
  DW_IfActionpass_yaw_GRM_HIL_T IfActionpass_yaw;/* '<S52>/If Action pass_yaw' */
  DW_IfActionSubsystem_GRM_HIL_T IfActionSubsystem_m;/* '<S176>/If Action Subsystem' */
  DW_IfActionSubsystem1_GRM_HIL_T IfActionSubsystem1_e;/* '<S176>/If Action Subsystem1' */
  DW_IfActionSubsystem_GRM_HIL_T IfActionSubsystem_p;/* '<S175>/If Action Subsystem' */
  DW_IfActionSubsystem1_GRM_HIL_T IfActionSubsystem1_j;/* '<S175>/If Action Subsystem1' */
  DW_IfActionSubsystem_GRM_HIL_T IfActionSubsystem;/* '<S174>/If Action Subsystem' */
  DW_IfActionSubsystem1_GRM_HIL_T IfActionSubsystem1;/* '<S174>/If Action Subsystem1' */
  DW_pass_GRM_HIL_T pass_l;            /* '<S73>/pass' */
  DW_Saturation_GRM_HIL_T Saturation_e;/* '<S73>/Saturation' */
  DW_Enabledpass_GRM_HIL_T Enabledpass_a;/* '<S72>/Enabled pass' */
  DW_pass_GRM_HIL_T pass_c;            /* '<S63>/pass' */
  DW_Saturation_GRM_HIL_T Saturation_j;/* '<S63>/Saturation' */
  DW_Enabledpass_GRM_HIL_T Enabledpass_j;/* '<S62>/Enabled pass' */
  DW_pass_GRM_HIL_T pass;              /* '<S54>/pass' */
  DW_Saturation_GRM_HIL_T Saturation;  /* '<S54>/Saturation' */
  DW_Enabledpass_GRM_HIL_T Enabledpass;/* '<S53>/Enabled pass' */
} DW_GRM_HIL_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S217>/Integrator' */
  real_T Integrator_CSTATE_k;          /* '<S215>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S215>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<S215>/Integrator2' */
  real_T TransferFcn_CSTATE[2];        /* '<S10>/Transfer Fcn' */
  real_T TransferFcn1_CSTATE[2];       /* '<S10>/Transfer Fcn1' */
  real_T TransferFcn2_CSTATE[2];       /* '<S10>/Transfer Fcn2' */
  real_T TransferFcn3_CSTATE[2];       /* '<S10>/Transfer Fcn3' */
  real_T dy2ay_CSTATE[2];              /* '<S197>/dy2ay' */
  real_T dp2az_CSTATE[2];              /* '<S197>/dp2az' */
  real_T dr2roll_CSTATE;               /* '<S197>/dr2roll' */
  real_T dp2pitch_CSTATE[2];           /* '<S197>/dp2pitch' */
  real_T dy2yaw_CSTATE[2];             /* '<S197>/dy2yaw' */
  real_T TransferFcn1_CSTATE_d[2];     /* '<S49>/Transfer Fcn1' */
  real_T Integrator_CSTATE_c;          /* '<S73>/Integrator' */
  real_T Filter_CSTATE;                /* '<S73>/Filter' */
  real_T Integrator_CSTATE_n;          /* '<S54>/Integrator' */
  real_T Filter_CSTATE_i;              /* '<S54>/Filter' */
  real_T Integrator_CSTATE_f;          /* '<S63>/Integrator' */
  real_T Filter_CSTATE_n;              /* '<S63>/Filter' */
  real_T Phi2MotorRoll_CSTATE[3];      /* '<S39>/Phi2Motor -> Roll' */
  real_T Theta2MotorPitch_CSTATE[5];   /* '<S39>/Theta2Motor -> Pitch' */
  real_T Psi2MotorYaw_CSTATE[2];       /* '<S39>/Psi2Motor -> Yaw' */
  real_T TransferFcn_CSTATE_j;         /* '<S24>/Transfer Fcn' */
  real_T TransferFcn2_CSTATE_e;        /* '<S24>/Transfer Fcn2' */
  real_T TransferFcn1_CSTATE_e;        /* '<S24>/Transfer Fcn1' */
  real_T Integrator_CSTATE_j;          /* '<S220>/Integrator' */
  real_T Integrator1_CSTATE_p;         /* '<S220>/Integrator1' */
  real_T Integrator2_CSTATE_a;         /* '<S220>/Integrator2' */
  real_T Integrator1_CSTATE_e;         /* '<S219>/Integrator1' */
  real_T Integrator2_CSTATE_d;         /* '<S219>/Integrator2' */
  real_T Integrator_CSTATE_d;          /* '<S218>/Integrator' */
  real_T Integrator1_CSTATE_eg;        /* '<S218>/Integrator1' */
  real_T Integrator2_CSTATE_e;         /* '<S218>/Integrator2' */
  real_T Integrator_CSTATE_jz;         /* '<S219>/Integrator' */
  real_T Integrator_CSTATE_i;          /* '<S107>/Integrator' */
  real_T Filter_CSTATE_p;              /* '<S102>/Filter' */
  real_T Integrator_CSTATE_fq;         /* '<S151>/Integrator' */
  real_T Filter_CSTATE_k;              /* '<S146>/Filter' */
} X_GRM_HIL_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S217>/Integrator' */
  real_T Integrator_CSTATE_k;          /* '<S215>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S215>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<S215>/Integrator2' */
  real_T TransferFcn_CSTATE[2];        /* '<S10>/Transfer Fcn' */
  real_T TransferFcn1_CSTATE[2];       /* '<S10>/Transfer Fcn1' */
  real_T TransferFcn2_CSTATE[2];       /* '<S10>/Transfer Fcn2' */
  real_T TransferFcn3_CSTATE[2];       /* '<S10>/Transfer Fcn3' */
  real_T dy2ay_CSTATE[2];              /* '<S197>/dy2ay' */
  real_T dp2az_CSTATE[2];              /* '<S197>/dp2az' */
  real_T dr2roll_CSTATE;               /* '<S197>/dr2roll' */
  real_T dp2pitch_CSTATE[2];           /* '<S197>/dp2pitch' */
  real_T dy2yaw_CSTATE[2];             /* '<S197>/dy2yaw' */
  real_T TransferFcn1_CSTATE_d[2];     /* '<S49>/Transfer Fcn1' */
  real_T Integrator_CSTATE_c;          /* '<S73>/Integrator' */
  real_T Filter_CSTATE;                /* '<S73>/Filter' */
  real_T Integrator_CSTATE_n;          /* '<S54>/Integrator' */
  real_T Filter_CSTATE_i;              /* '<S54>/Filter' */
  real_T Integrator_CSTATE_f;          /* '<S63>/Integrator' */
  real_T Filter_CSTATE_n;              /* '<S63>/Filter' */
  real_T Phi2MotorRoll_CSTATE[3];      /* '<S39>/Phi2Motor -> Roll' */
  real_T Theta2MotorPitch_CSTATE[5];   /* '<S39>/Theta2Motor -> Pitch' */
  real_T Psi2MotorYaw_CSTATE[2];       /* '<S39>/Psi2Motor -> Yaw' */
  real_T TransferFcn_CSTATE_j;         /* '<S24>/Transfer Fcn' */
  real_T TransferFcn2_CSTATE_e;        /* '<S24>/Transfer Fcn2' */
  real_T TransferFcn1_CSTATE_e;        /* '<S24>/Transfer Fcn1' */
  real_T Integrator_CSTATE_j;          /* '<S220>/Integrator' */
  real_T Integrator1_CSTATE_p;         /* '<S220>/Integrator1' */
  real_T Integrator2_CSTATE_a;         /* '<S220>/Integrator2' */
  real_T Integrator1_CSTATE_e;         /* '<S219>/Integrator1' */
  real_T Integrator2_CSTATE_d;         /* '<S219>/Integrator2' */
  real_T Integrator_CSTATE_d;          /* '<S218>/Integrator' */
  real_T Integrator1_CSTATE_eg;        /* '<S218>/Integrator1' */
  real_T Integrator2_CSTATE_e;         /* '<S218>/Integrator2' */
  real_T Integrator_CSTATE_jz;         /* '<S219>/Integrator' */
  real_T Integrator_CSTATE_i;          /* '<S107>/Integrator' */
  real_T Filter_CSTATE_p;              /* '<S102>/Filter' */
  real_T Integrator_CSTATE_fq;         /* '<S151>/Integrator' */
  real_T Filter_CSTATE_k;              /* '<S146>/Filter' */
} XDot_GRM_HIL_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S217>/Integrator' */
  boolean_T Integrator_CSTATE_k;       /* '<S215>/Integrator' */
  boolean_T Integrator1_CSTATE;        /* '<S215>/Integrator1' */
  boolean_T Integrator2_CSTATE;        /* '<S215>/Integrator2' */
  boolean_T TransferFcn_CSTATE[2];     /* '<S10>/Transfer Fcn' */
  boolean_T TransferFcn1_CSTATE[2];    /* '<S10>/Transfer Fcn1' */
  boolean_T TransferFcn2_CSTATE[2];    /* '<S10>/Transfer Fcn2' */
  boolean_T TransferFcn3_CSTATE[2];    /* '<S10>/Transfer Fcn3' */
  boolean_T dy2ay_CSTATE[2];           /* '<S197>/dy2ay' */
  boolean_T dp2az_CSTATE[2];           /* '<S197>/dp2az' */
  boolean_T dr2roll_CSTATE;            /* '<S197>/dr2roll' */
  boolean_T dp2pitch_CSTATE[2];        /* '<S197>/dp2pitch' */
  boolean_T dy2yaw_CSTATE[2];          /* '<S197>/dy2yaw' */
  boolean_T TransferFcn1_CSTATE_d[2];  /* '<S49>/Transfer Fcn1' */
  boolean_T Integrator_CSTATE_c;       /* '<S73>/Integrator' */
  boolean_T Filter_CSTATE;             /* '<S73>/Filter' */
  boolean_T Integrator_CSTATE_n;       /* '<S54>/Integrator' */
  boolean_T Filter_CSTATE_i;           /* '<S54>/Filter' */
  boolean_T Integrator_CSTATE_f;       /* '<S63>/Integrator' */
  boolean_T Filter_CSTATE_n;           /* '<S63>/Filter' */
  boolean_T Phi2MotorRoll_CSTATE[3];   /* '<S39>/Phi2Motor -> Roll' */
  boolean_T Theta2MotorPitch_CSTATE[5];/* '<S39>/Theta2Motor -> Pitch' */
  boolean_T Psi2MotorYaw_CSTATE[2];    /* '<S39>/Psi2Motor -> Yaw' */
  boolean_T TransferFcn_CSTATE_j;      /* '<S24>/Transfer Fcn' */
  boolean_T TransferFcn2_CSTATE_e;     /* '<S24>/Transfer Fcn2' */
  boolean_T TransferFcn1_CSTATE_e;     /* '<S24>/Transfer Fcn1' */
  boolean_T Integrator_CSTATE_j;       /* '<S220>/Integrator' */
  boolean_T Integrator1_CSTATE_p;      /* '<S220>/Integrator1' */
  boolean_T Integrator2_CSTATE_a;      /* '<S220>/Integrator2' */
  boolean_T Integrator1_CSTATE_e;      /* '<S219>/Integrator1' */
  boolean_T Integrator2_CSTATE_d;      /* '<S219>/Integrator2' */
  boolean_T Integrator_CSTATE_d;       /* '<S218>/Integrator' */
  boolean_T Integrator1_CSTATE_eg;     /* '<S218>/Integrator1' */
  boolean_T Integrator2_CSTATE_e;      /* '<S218>/Integrator2' */
  boolean_T Integrator_CSTATE_jz;      /* '<S219>/Integrator' */
  boolean_T Integrator_CSTATE_i;       /* '<S107>/Integrator' */
  boolean_T Filter_CSTATE_p;           /* '<S102>/Filter' */
  boolean_T Integrator_CSTATE_fq;      /* '<S151>/Integrator' */
  boolean_T Filter_CSTATE_k;           /* '<S146>/Filter' */
} XDis_GRM_HIL_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Integrator_Reset_ZCE;     /* '<S217>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_f;   /* '<S215>/Integrator' */
  ZCSigState Integrator1_Reset_ZCE;    /* '<S215>/Integrator1' */
  ZCSigState Integrator2_Reset_ZCE;    /* '<S215>/Integrator2' */
  ZCSigState Integrator_Reset_ZCE_i;   /* '<S220>/Integrator' */
  ZCSigState Integrator1_Reset_ZCE_p;  /* '<S220>/Integrator1' */
  ZCSigState Integrator2_Reset_ZCE_f;  /* '<S220>/Integrator2' */
  ZCSigState Integrator1_Reset_ZCE_d;  /* '<S219>/Integrator1' */
  ZCSigState Integrator2_Reset_ZCE_g;  /* '<S219>/Integrator2' */
  ZCSigState Integrator_Reset_ZCE_k;   /* '<S218>/Integrator' */
  ZCSigState Integrator1_Reset_ZCE_i;  /* '<S218>/Integrator1' */
  ZCSigState Integrator2_Reset_ZCE_m;  /* '<S218>/Integrator2' */
  ZCSigState Integrator_Reset_ZCE_ff;  /* '<S219>/Integrator' */
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

/* Parameters for system: '<S174>/If Action Subsystem1' */
struct P_IfActionSubsystem1_GRM_HIL_T_ {
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S178>/Out1'
                                        */
};

/* Parameters for system: '<S174>/If Action Subsystem' */
struct P_IfActionSubsystem_GRM_HIL_T_ {
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S177>/Out1'
                                        */
};

/* Parameters (default storage) */
struct P_GRM_HIL_T_ {
  real_T HIL_Sample_Time;              /* Variable: HIL_Sample_Time
                                        * Referenced by: '<S18>/Constant'
                                        */
  struct_0kz5Xf5aDCvwuRhz9h36UB FDM_Linear_FDM;/* Mask Parameter: FDM_Linear_FDM
                                                * Referenced by:
                                                *   '<S201>/Constant1'
                                                *   '<S216>/Constant'
                                                *   '<S216>/Constant1'
                                                *   '<S209>/Constant'
                                                *   '<S210>/Constant'
                                                *   '<S210>/Constant1'
                                                */
  struct_t5lid3aqguggysQaotuOhC Gimbel_Ctrl_Gimbal_Ctrl;
                                      /* Mask Parameter: Gimbel_Ctrl_Gimbal_Ctrl
                                       * Referenced by:
                                       *   '<S45>/Constant2'
                                       *   '<S45>/Samp_Freq'
                                       *   '<S52>/max_vel_pitch'
                                       *   '<S52>/max_vel_roll'
                                       *   '<S52>/max_vel_yaw'
                                       *   '<S53>/Constant'
                                       *   '<S53>/const_lower_limit'
                                       *   '<S53>/const_upper_limit'
                                       *   '<S54>/Derivative Gain'
                                       *   '<S54>/Filter Coefficient'
                                       *   '<S54>/Integral Gain'
                                       *   '<S54>/Kb'
                                       *   '<S54>/Proportional Gain'
                                       *   '<S62>/Constant'
                                       *   '<S62>/const_lower_limit'
                                       *   '<S62>/const_upper_limit'
                                       *   '<S63>/Derivative Gain'
                                       *   '<S63>/Filter Coefficient'
                                       *   '<S63>/Integral Gain'
                                       *   '<S63>/Kb'
                                       *   '<S63>/Proportional Gain'
                                       *   '<S71>/Constant'
                                       *   '<S72>/Constant'
                                       *   '<S72>/const_lower_limit'
                                       *   '<S72>/const_upper_limit'
                                       *   '<S73>/Derivative Gain'
                                       *   '<S73>/Filter Coefficient'
                                       *   '<S73>/Integral Gain'
                                       *   '<S73>/Kb'
                                       *   '<S73>/Proportional Gain'
                                       *   '<S174>/Constant1'
                                       *   '<S174>/Gain'
                                       *   '<S174>/Transport Delay'
                                       *   '<S175>/Constant1'
                                       *   '<S175>/Gain'
                                       *   '<S175>/Transport Delay'
                                       *   '<S176>/Constant1'
                                       *   '<S176>/Gain'
                                       *   '<S176>/Transport Delay'
                                       *   '<S183>/Limit_Voltage_Pitch'
                                       *   '<S184>/Limit_Voltage_Roll'
                                       *   '<S185>/Limit_Voltage_Yaw'
                                       *   '<S55>/Constant'
                                       *   '<S56>/Constant'
                                       *   '<S57>/Constant'
                                       *   '<S57>/Constant1'
                                       *   '<S57>/Gain'
                                       *   '<S64>/Constant'
                                       *   '<S65>/Constant'
                                       *   '<S66>/Constant'
                                       *   '<S66>/Constant1'
                                       *   '<S66>/Gain'
                                       *   '<S74>/Constant1'
                                       *   '<S74>/Constant2'
                                       *   '<S74>/Gain'
                                       *   '<S74>/Gain1'
                                       *   '<S166>/Constant'
                                       *   '<S167>/Constant'
                                       *   '<S168>/Constant'
                                       *   '<S168>/Constant1'
                                       *   '<S168>/Gain'
                                       *   '<S101>/Derivative Gain'
                                       *   '<S104>/Integral Gain'
                                       *   '<S112>/Proportional Gain'
                                       *   '<S145>/Derivative Gain'
                                       *   '<S148>/Integral Gain'
                                       *   '<S156>/Proportional Gain'
                                       */
  struct_xafWrx5dwrT8wEsj34nY2B FDM_Linear_TF;/* Mask Parameter: FDM_Linear_TF
                                               * Referenced by:
                                               *   '<S197>/dp2az'
                                               *   '<S197>/dp2pitch'
                                               *   '<S197>/dr2roll'
                                               *   '<S197>/dy2ay'
                                               *   '<S197>/dy2yaw'
                                               */
  struct_X0z48mq1MJmnXMBjrHYvYC Gimbal_TransferFunctions_TF;
                                  /* Mask Parameter: Gimbal_TransferFunctions_TF
                                   * Referenced by:
                                   *   '<S39>/Phi2Motor -> Pitch'
                                   *   '<S39>/Phi2Motor -> Roll'
                                   *   '<S39>/Phi2Motor -> Yaw'
                                   *   '<S39>/Psi2Motor -> Pitch'
                                   *   '<S39>/Psi2Motor -> Roll'
                                   *   '<S39>/Psi2Motor -> Yaw'
                                   *   '<S39>/Theta2Motor -> Pitch'
                                   *   '<S39>/Theta2Motor -> Roll'
                                   *   '<S39>/Theta2Motor -> Yaw'
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
                         *   '<S204>/Constant4'
                         *   '<S204>/Constant5'
                         *   '<S204>/Constant6'
                         *   '<S204>/Constant7'
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
  Airframe_States_Bus Initial_States_Airframe;
                                      /* Mask Parameter: Initial_States_Airframe
                                       * Referenced by: '<S5>/Constant18'
                                       */
  real_T PIDController_InitialConditionForFilter;
                      /* Mask Parameter: PIDController_InitialConditionForFilter
                       * Referenced by: '<S102>/Filter'
                       */
  real_T PIDController1_InitialConditionForFilter;
                     /* Mask Parameter: PIDController1_InitialConditionForFilter
                      * Referenced by: '<S146>/Filter'
                      */
  real_T PIDController_InitialConditionForIntegrator;
                  /* Mask Parameter: PIDController_InitialConditionForIntegrator
                   * Referenced by: '<S107>/Integrator'
                   */
  real_T PIDController1_InitialConditionForIntegrator;
                 /* Mask Parameter: PIDController1_InitialConditionForIntegrator
                  * Referenced by: '<S151>/Integrator'
                  */
  real_T PIDController_Kb;             /* Mask Parameter: PIDController_Kb
                                        * Referenced by: '<S100>/Kb'
                                        */
  real_T PIDController1_Kb;            /* Mask Parameter: PIDController1_Kb
                                        * Referenced by: '<S144>/Kb'
                                        */
  real_T PIDController_LowerSaturationLimit;
                           /* Mask Parameter: PIDController_LowerSaturationLimit
                            * Referenced by: '<S114>/Saturation'
                            */
  real_T PIDController1_LowerSaturationLimit;
                          /* Mask Parameter: PIDController1_LowerSaturationLimit
                           * Referenced by: '<S158>/Saturation'
                           */
  real_T RealTimeSynchronization_MaxMissedTicks;
                       /* Mask Parameter: RealTimeSynchronization_MaxMissedTicks
                        * Referenced by: '<S221>/Real-Time Synchronization'
                        */
  real_T PIDController_N;              /* Mask Parameter: PIDController_N
                                        * Referenced by: '<S110>/Filter Coefficient'
                                        */
  real_T PIDController1_N;             /* Mask Parameter: PIDController1_N
                                        * Referenced by: '<S154>/Filter Coefficient'
                                        */
  real_T PIDController_UpperSaturationLimit;
                           /* Mask Parameter: PIDController_UpperSaturationLimit
                            * Referenced by: '<S114>/Saturation'
                            */
  real_T PIDController1_UpperSaturationLimit;
                          /* Mask Parameter: PIDController1_UpperSaturationLimit
                           * Referenced by: '<S158>/Saturation'
                           */
  real_T RealTimeSynchronization_YieldWhenWaiting;
                     /* Mask Parameter: RealTimeSynchronization_YieldWhenWaiting
                      * Referenced by: '<S221>/Real-Time Synchronization'
                      */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S173>/Constant'
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
  Simulation_Ctrl_Bus Simulation_Control_hold_Y0;
                               /* Computed Parameter: Simulation_Control_hold_Y0
                                * Referenced by: '<S19>/Simulation_Control_hold'
                                */
  struct_lQamzfSfua9vI4k5KcpdyB External_Inputs_hold_Y0;
                                  /* Computed Parameter: External_Inputs_hold_Y0
                                   * Referenced by: '<S19>/External_Inputs_hold'
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
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S74>/Constant'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<S74>/Constant3'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1
                                        * Referenced by: '<S74>/Gain2'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1
                                        * Referenced by: '<S74>/Gain3'
                                        */
  real_T acc_x_drag_mDs2_Y0;           /* Expression: 0
                                        * Referenced by: '<S200>/acc_x_drag_mDs2'
                                        */
  real_T acc_y_drag_mDs2_Y0;           /* Expression: 0
                                        * Referenced by: '<S200>/acc_y_drag_mDs2'
                                        */
  real_T acc_z_drag_mDs2_Y0;           /* Expression: 0
                                        * Referenced by: '<S200>/acc_z_drag_mDs2'
                                        */
  real_T Constant_Value_d;             /* Expression: -1
                                        * Referenced by: '<S200>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: -1
                                        * Referenced by: '<S200>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: -1
                                        * Referenced by: '<S200>/Constant2'
                                        */
  real_T acc_x_grav_mDs_Y0;            /* Expression: 0
                                        * Referenced by: '<S201>/acc_x_grav_mDs'
                                        */
  real_T acc_y_grav_mDs_Y0;            /* Expression: 0
                                        * Referenced by: '<S201>/acc_y_grav_mDs'
                                        */
  real_T acc_z_grav_mDs_Y0;            /* Expression: 0
                                        * Referenced by: '<S201>/acc_z_grav_mDs'
                                        */
  real_T thrust_Y0;                    /* Expression: 0
                                        * Referenced by: '<S210>/thrust'
                                        */
  real_T state_percentage_change_Y0;   /* Expression: 1
                                        * Referenced by: '<S210>/state_percentage_change'
                                        */
  real_T Constant2_Value_d;            /* Expression: 1
                                        * Referenced by: '<S210>/Constant2'
                                        */
  real_T exec_time_hold_s_Y0;         /* Computed Parameter: exec_time_hold_s_Y0
                                       * Referenced by: '<S211>/exec_time_hold_s'
                                       */
  real_T motor_state_perc_dot_Y0;      /* Expression: 0
                                        * Referenced by: '<S203>/motor_state_perc_dot'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<S2>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 1
                                        * Referenced by: '<S2>/Step'
                                        */
  real_T Gain18_Gain;                  /* Expression: 1
                                        * Referenced by: '<S189>/Gain18'
                                        */
  real_T Gain9_Gain;                   /* Expression: 1
                                        * Referenced by: '<S189>/Gain9'
                                        */
  real_T Gain10_Gain;                  /* Expression: 1
                                        * Referenced by: '<S189>/Gain10'
                                        */
  real_T Gain11_Gain;                  /* Expression: 1
                                        * Referenced by: '<S189>/Gain11'
                                        */
  real_T Gain3_Gain_n;                 /* Expression: 1
                                        * Referenced by: '<S195>/Gain3'
                                        */
  real_T Gain_Gain;                    /* Expression: 1
                                        * Referenced by: '<S11>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1
                                        * Referenced by: '<S11>/Gain1'
                                        */
  real_T Gain2_Gain_g;                 /* Expression: 1
                                        * Referenced by: '<S11>/Gain2'
                                        */
  real_T Gain3_Gain_d;                 /* Expression: 1
                                        * Referenced by: '<S11>/Gain3'
                                        */
  real_T Gain2_Gain_a;                 /* Expression: 1/4
                                        * Referenced by: '<S204>/Gain2'
                                        */
  real_T Gain4_Gain;                   /* Expression: 1
                                        * Referenced by: '<S195>/Gain4'
                                        */
  real_T Gain1_Gain_n;                 /* Expression: 1/4
                                        * Referenced by: '<S204>/Gain1'
                                        */
  real_T Gain5_Gain;                   /* Expression: 1
                                        * Referenced by: '<S195>/Gain5'
                                        */
  real_T Gain9_Gain_b;                 /* Expression: 1
                                        * Referenced by: '<S195>/Gain9'
                                        */
  real_T Gain10_Gain_f;                /* Expression: 1
                                        * Referenced by: '<S195>/Gain10'
                                        */
  real_T Gain11_Gain_d;                /* Expression: 1
                                        * Referenced by: '<S195>/Gain11'
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
                                        * Referenced by: '<S195>/Gain6'
                                        */
  real_T Gain7_Gain;                   /* Expression: 1
                                        * Referenced by: '<S195>/Gain7'
                                        */
  real_T Gain8_Gain;                   /* Expression: 1
                                        * Referenced by: '<S195>/Gain8'
                                        */
  real_T TransferFcn1_A[2];            /* Computed Parameter: TransferFcn1_A
                                        * Referenced by: '<S49>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C[2];            /* Computed Parameter: TransferFcn1_C
                                        * Referenced by: '<S49>/Transfer Fcn1'
                                        */
  real_T Constant2_Value_h;            /* Expression: 1
                                        * Referenced by: '<S49>/Constant2'
                                        */
  real_T Constant1_Value_b;            /* Expression: 0
                                        * Referenced by: '<S38>/Constant1'
                                        */
  real_T Constant2_Value_c;            /* Expression: 0
                                        * Referenced by: '<S38>/Constant2'
                                        */
  real_T Memory1_1_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S36>/Memory1'
                                        */
  real_T Shaft2degYaw_Gain;            /* Expression: 360/(65536)
                                        * Referenced by: '<S45>/Shaft2degYaw'
                                        */
  real_T TransportDelay_InitOutput;    /* Expression: 0
                                        * Referenced by: '<S176>/Transport Delay'
                                        */
  real_T Memory1_2_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S36>/Memory1'
                                        */
  real_T Shaft2degPitch_Gain;          /* Expression: -360/(65536)
                                        * Referenced by: '<S45>/Shaft2degPitch'
                                        */
  real_T TransportDelay_InitOutput_j;  /* Expression: 0
                                        * Referenced by: '<S174>/Transport Delay'
                                        */
  real_T Memory1_3_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S36>/Memory1'
                                        */
  real_T Shaft2degRoll_Gain;           /* Expression: -360/(65536)
                                        * Referenced by: '<S45>/Shaft2degRoll'
                                        */
  real_T TransportDelay_InitOutput_g;  /* Expression: 0
                                        * Referenced by: '<S175>/Transport Delay'
                                        */
  real_T Constant2_Value_o;            /* Expression: inf
                                        * Referenced by: '<S72>/Constant2'
                                        */
  real_T Switch2_Threshold_l;          /* Expression: 0
                                        * Referenced by: '<S72>/Switch2'
                                        */
  real_T Gain_Gain_a;                  /* Expression: -1
                                        * Referenced by: '<S72>/Gain'
                                        */
  real_T Switch1_Threshold_k;          /* Expression: 0
                                        * Referenced by: '<S72>/Switch1'
                                        */
  real_T rad2deg_Gain;                 /* Expression: 360/(2*pi)
                                        * Referenced by: '<S192>/rad2deg'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S73>/Integrator'
                                        */
  real_T Filter_IC;                    /* Expression: 0
                                        * Referenced by: '<S73>/Filter'
                                        */
  real_T Merge_InitialOutput;         /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S73>/Merge'
                                       */
  real_T Merge_InitialOutput_d;     /* Computed Parameter: Merge_InitialOutput_d
                                     * Referenced by: '<S71>/Merge'
                                     */
  real_T Constant2_Value_h5;           /* Expression: inf
                                        * Referenced by: '<S53>/Constant2'
                                        */
  real_T Switch2_Threshold_k;          /* Expression: 0
                                        * Referenced by: '<S53>/Switch2'
                                        */
  real_T Gain_Gain_g;                  /* Expression: -1
                                        * Referenced by: '<S53>/Gain'
                                        */
  real_T Switch1_Threshold_g;          /* Expression: 0
                                        * Referenced by: '<S53>/Switch1'
                                        */
  real_T rad2deg1_Gain;                /* Expression: 360/(2*pi)
                                        * Referenced by: '<S192>/rad2deg1'
                                        */
  real_T Integrator_IC_c;              /* Expression: 0
                                        * Referenced by: '<S54>/Integrator'
                                        */
  real_T Filter_IC_c;                  /* Expression: 0
                                        * Referenced by: '<S54>/Filter'
                                        */
  real_T Merge_InitialOutput_a;     /* Computed Parameter: Merge_InitialOutput_a
                                     * Referenced by: '<S54>/Merge'
                                     */
  real_T Constant2_Value_ht;           /* Expression: inf
                                        * Referenced by: '<S62>/Constant2'
                                        */
  real_T Switch2_Threshold_i;          /* Expression: 0
                                        * Referenced by: '<S62>/Switch2'
                                        */
  real_T Gain_Gain_p;                  /* Expression: -1
                                        * Referenced by: '<S62>/Gain'
                                        */
  real_T Switch1_Threshold_m;          /* Expression: 0
                                        * Referenced by: '<S62>/Switch1'
                                        */
  real_T rad2deg2_Gain;                /* Expression: 360/(2*pi)
                                        * Referenced by: '<S192>/rad2deg2'
                                        */
  real_T Integrator_IC_m;              /* Expression: 0
                                        * Referenced by: '<S63>/Integrator'
                                        */
  real_T Filter_IC_d;                  /* Expression: 0
                                        * Referenced by: '<S63>/Filter'
                                        */
  real_T Merge_InitialOutput_j;     /* Computed Parameter: Merge_InitialOutput_j
                                     * Referenced by: '<S63>/Merge'
                                     */
  real_T Merge_InitialOutput_a0;   /* Computed Parameter: Merge_InitialOutput_a0
                                    * Referenced by: '<S45>/Merge'
                                    */
  real_T Merge1_InitialOutput;       /* Computed Parameter: Merge1_InitialOutput
                                      * Referenced by: '<S45>/Merge1'
                                      */
  real_T Shaft2radRoll_Gain;           /* Expression: (2*pi)/(65536)
                                        * Referenced by: '<S40>/Shaft2radRoll'
                                        */
  real_T Merge2_InitialOutput;       /* Computed Parameter: Merge2_InitialOutput
                                      * Referenced by: '<S45>/Merge2'
                                      */
  real_T Shaft2radPitch_Gain;          /* Expression: (2*pi)/(65536)
                                        * Referenced by: '<S40>/Shaft2radPitch'
                                        */
  real_T Shaft2radYaw_Gain;            /* Expression: (2*pi)/(65536)
                                        * Referenced by: '<S40>/Shaft2radYaw'
                                        */
  real_T u2_Gain;                      /* Expression: 0.5
                                        * Referenced by: '<S43>/1//2'
                                        */
  real_T Constant_Value_k;             /* Expression: -1
                                        * Referenced by: '<S41>/Constant'
                                        */
  real_T Constant1_Value_h;            /* Expression: -1
                                        * Referenced by: '<S41>/Constant1'
                                        */
  real_T Constant2_Value_e;            /* Expression: -1
                                        * Referenced by: '<S41>/Constant2'
                                        */
  real_T Constant3_Value_p;            /* Expression: -1
                                        * Referenced by: '<S41>/Constant3'
                                        */
  real_T Constant4_Value;              /* Expression: -1
                                        * Referenced by: '<S41>/Constant4'
                                        */
  real_T Constant5_Value;              /* Expression: -1
                                        * Referenced by: '<S41>/Constant5'
                                        */
  real_T Constant6_Value;              /* Expression: -1
                                        * Referenced by: '<S41>/Constant6'
                                        */
  real_T Constant7_Value_e;            /* Expression: -1
                                        * Referenced by: '<S41>/Constant7'
                                        */
  real_T Constant8_Value;              /* Expression: -1
                                        * Referenced by: '<S41>/Constant8'
                                        */
  real_T Constant9_Value_g;            /* Expression: -1
                                        * Referenced by: '<S41>/Constant9'
                                        */
  real_T Constant10_Value;             /* Expression: -1
                                        * Referenced by: '<S41>/Constant10'
                                        */
  real_T Constant11_Value_c;           /* Expression: -1
                                        * Referenced by: '<S41>/Constant11'
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
                                        * Referenced by: '<S189>/Gain'
                                        */
  real_T Gain_Gain_k;                  /* Expression: 1
                                        * Referenced by: '<S195>/Gain'
                                        */
  real_T Gain1_Gain_i;                 /* Expression: 1
                                        * Referenced by: '<S189>/Gain1'
                                        */
  real_T Gain1_Gain_b;                 /* Expression: 1
                                        * Referenced by: '<S195>/Gain1'
                                        */
  real_T Gain2_Gain_l;                 /* Expression: 1
                                        * Referenced by: '<S189>/Gain2'
                                        */
  real_T Gain2_Gain_e;                 /* Expression: 1
                                        * Referenced by: '<S195>/Gain2'
                                        */
  real_T Constant_Value_n;             /* Expression: 0
                                        * Referenced by: '<S39>/Constant'
                                        */
  real_T Constant7_Value_e5;
          /* Expression: HIL_Data.Simulation_Ctrl.HW_Ctrl.enable_gimbal_ctrl_flg
           * Referenced by: '<S7>/Constant7'
           */
  real_T Gain_Gain_o;                  /* Expression: 1
                                        * Referenced by: '<S44>/Gain'
                                        */
  real_T Constant_Value_p;             /* Expression: 1
                                        * Referenced by: '<S176>/Constant'
                                        */
  real_T Constant_Value_l;             /* Expression: 1
                                        * Referenced by: '<S174>/Constant'
                                        */
  real_T Constant_Value_lt;            /* Expression: 1
                                        * Referenced by: '<S175>/Constant'
                                        */
  real_T Gain12_Gain;                  /* Expression: 1
                                        * Referenced by: '<S189>/Gain12'
                                        */
  real_T Gain13_Gain;                  /* Expression: 1
                                        * Referenced by: '<S189>/Gain13'
                                        */
  real_T Gain14_Gain;                  /* Expression: 1
                                        * Referenced by: '<S189>/Gain14'
                                        */
  real_T Gain15_Gain;                  /* Expression: 1
                                        * Referenced by: '<S189>/Gain15'
                                        */
  real_T Gain16_Gain;                  /* Expression: 1
                                        * Referenced by: '<S189>/Gain16'
                                        */
  real_T Gain17_Gain;                  /* Expression: 1
                                        * Referenced by: '<S189>/Gain17'
                                        */
  real_T Gain_Gain_kk;                 /* Expression: 1/4
                                        * Referenced by: '<S204>/Gain'
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
                                     * Referenced by: '<S203>/lock'
                                     */
  boolean_T Constant4_Value_g;         /* Computed Parameter: Constant4_Value_g
                                        * Referenced by: '<S7>/Constant4'
                                        */
  boolean_T Constant2_Value_f;         /* Computed Parameter: Constant2_Value_f
                                        * Referenced by: '<S7>/Constant2'
                                        */
  boolean_T Constant6_Value_k;         /* Computed Parameter: Constant6_Value_k
                                        * Referenced by: '<S7>/Constant6'
                                        */
  boolean_T Constant5_Value_k;         /* Computed Parameter: Constant5_Value_k
                                        * Referenced by: '<S7>/Constant5'
                                        */
  boolean_T Memory_1_InitialCondition;
                                /* Computed Parameter: Memory_1_InitialCondition
                                 * Referenced by: '<S36>/Memory'
                                 */
  boolean_T Memory_2_InitialCondition;
                                /* Computed Parameter: Memory_2_InitialCondition
                                 * Referenced by: '<S36>/Memory'
                                 */
  boolean_T Constant1_Value_f;         /* Computed Parameter: Constant1_Value_f
                                        * Referenced by: '<S72>/Constant1'
                                        */
  boolean_T Constant1_Value_m;         /* Computed Parameter: Constant1_Value_m
                                        * Referenced by: '<S53>/Constant1'
                                        */
  boolean_T Constant1_Value_j;         /* Computed Parameter: Constant1_Value_j
                                        * Referenced by: '<S62>/Constant1'
                                        */
  boolean_T Constant_Value_g;          /* Computed Parameter: Constant_Value_g
                                        * Referenced by: '<S7>/Constant'
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
  P_IfActionSubsystem_GRM_HIL_T IfActionSubsystem_m;/* '<S176>/If Action Subsystem' */
  P_IfActionSubsystem1_GRM_HIL_T IfActionSubsystem1_e;/* '<S176>/If Action Subsystem1' */
  P_IfActionSubsystem_GRM_HIL_T IfActionSubsystem_p;/* '<S175>/If Action Subsystem' */
  P_IfActionSubsystem1_GRM_HIL_T IfActionSubsystem1_j;/* '<S175>/If Action Subsystem1' */
  P_IfActionSubsystem_GRM_HIL_T IfActionSubsystem;/* '<S174>/If Action Subsystem' */
  P_IfActionSubsystem1_GRM_HIL_T IfActionSubsystem1;/* '<S174>/If Action Subsystem1' */
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
  real_T odeY[55];
  real_T odeF[3][55];
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
 * '<S36>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal'
 * '<S37>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbal'
 * '<S38>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl'
 * '<S39>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbal/Gimbal_TransferFunctions'
 * '<S40>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbal/Gimbal_TransferFunctions/Assemble_Gimbal_Subbusses'
 * '<S41>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbal/Gimbal_TransferFunctions/Assemble_Gimbal_Subbusses/Emulate_Encoder_Signals'
 * '<S42>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbal/Gimbal_TransferFunctions/Assemble_Gimbal_Subbusses/Eul2Quat'
 * '<S43>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbal/Gimbal_TransferFunctions/Assemble_Gimbal_Subbusses/Eul2Quat/Rotation Angles to Quaternions'
 * '<S44>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller'
 * '<S45>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller'
 * '<S46>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Pitch'
 * '<S47>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Roll'
 * '<S48>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw'
 * '<S49>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Damping'
 * '<S50>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/If Action Pass'
 * '<S51>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Monitor_Velocity_Limits'
 * '<S52>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Voltage_Limitations'
 * '<S53>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Pitch/Limits'
 * '<S54>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Pitch/PID_Controller_Dynamic_Limits'
 * '<S55>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Pitch/Limits/Compare To Constant'
 * '<S56>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Pitch/Limits/Compare To Constant1'
 * '<S57>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Pitch/Limits/Enabled adapt'
 * '<S58>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Pitch/Limits/Enabled pass'
 * '<S59>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Pitch/PID_Controller_Dynamic_Limits/Saturation'
 * '<S60>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Pitch/PID_Controller_Dynamic_Limits/pass'
 * '<S61>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Pitch/PID_Controller_Dynamic_Limits/Saturation/Saturation Dynamic'
 * '<S62>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Roll/Limits'
 * '<S63>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Roll/PID_Controller_Dynamic_Limits'
 * '<S64>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Roll/Limits/Compare To Constant'
 * '<S65>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Roll/Limits/Compare To Constant1'
 * '<S66>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Roll/Limits/Enabled adapt'
 * '<S67>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Roll/Limits/Enabled pass'
 * '<S68>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Roll/PID_Controller_Dynamic_Limits/Saturation'
 * '<S69>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Roll/PID_Controller_Dynamic_Limits/pass'
 * '<S70>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Roll/PID_Controller_Dynamic_Limits/Saturation/Saturation Dynamic'
 * '<S71>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers'
 * '<S72>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limits'
 * '<S73>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/PID_Controller_Dynamic_Limits'
 * '<S74>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits'
 * '<S75>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/pass'
 * '<S76>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller'
 * '<S77>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1'
 * '<S78>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Anti-windup'
 * '<S79>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/D Gain'
 * '<S80>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Filter'
 * '<S81>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Filter ICs'
 * '<S82>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/I Gain'
 * '<S83>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Ideal P Gain'
 * '<S84>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Ideal P Gain Fdbk'
 * '<S85>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Integrator'
 * '<S86>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Integrator ICs'
 * '<S87>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/N Copy'
 * '<S88>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/N Gain'
 * '<S89>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/P Copy'
 * '<S90>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Parallel P Gain'
 * '<S91>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Reset Signal'
 * '<S92>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Saturation'
 * '<S93>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Saturation Fdbk'
 * '<S94>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Sum'
 * '<S95>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Sum Fdbk'
 * '<S96>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Tracking Mode'
 * '<S97>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Tracking Mode Sum'
 * '<S98>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/postSat Signal'
 * '<S99>'  : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/preSat Signal'
 * '<S100>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Anti-windup/Back Calculation'
 * '<S101>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/D Gain/Internal Parameters'
 * '<S102>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Filter/Cont. Filter'
 * '<S103>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S104>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/I Gain/Internal Parameters'
 * '<S105>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Ideal P Gain/Passthrough'
 * '<S106>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S107>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Integrator/Continuous'
 * '<S108>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Integrator ICs/Internal IC'
 * '<S109>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/N Copy/Disabled'
 * '<S110>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/N Gain/Internal Parameters'
 * '<S111>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/P Copy/Disabled'
 * '<S112>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S113>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Reset Signal/Disabled'
 * '<S114>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Saturation/Enabled'
 * '<S115>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Saturation Fdbk/Disabled'
 * '<S116>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Sum/Sum_PID'
 * '<S117>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Sum Fdbk/Disabled'
 * '<S118>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Tracking Mode/Disabled'
 * '<S119>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S120>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/postSat Signal/Forward_Path'
 * '<S121>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller/preSat Signal/Forward_Path'
 * '<S122>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Anti-windup'
 * '<S123>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/D Gain'
 * '<S124>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Filter'
 * '<S125>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Filter ICs'
 * '<S126>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/I Gain'
 * '<S127>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Ideal P Gain'
 * '<S128>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Ideal P Gain Fdbk'
 * '<S129>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Integrator'
 * '<S130>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Integrator ICs'
 * '<S131>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/N Copy'
 * '<S132>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/N Gain'
 * '<S133>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/P Copy'
 * '<S134>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Parallel P Gain'
 * '<S135>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Reset Signal'
 * '<S136>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Saturation'
 * '<S137>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Saturation Fdbk'
 * '<S138>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Sum'
 * '<S139>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Sum Fdbk'
 * '<S140>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Tracking Mode'
 * '<S141>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Tracking Mode Sum'
 * '<S142>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/postSat Signal'
 * '<S143>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/preSat Signal'
 * '<S144>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Anti-windup/Back Calculation'
 * '<S145>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/D Gain/Internal Parameters'
 * '<S146>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Filter/Cont. Filter'
 * '<S147>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S148>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/I Gain/Internal Parameters'
 * '<S149>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Ideal P Gain/Passthrough'
 * '<S150>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S151>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Integrator/Continuous'
 * '<S152>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Integrator ICs/Internal IC'
 * '<S153>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/N Copy/Disabled'
 * '<S154>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/N Gain/Internal Parameters'
 * '<S155>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/P Copy/Disabled'
 * '<S156>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S157>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Reset Signal/Disabled'
 * '<S158>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Saturation/Enabled'
 * '<S159>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Saturation Fdbk/Disabled'
 * '<S160>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Sum/Sum_PID'
 * '<S161>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Sum Fdbk/Disabled'
 * '<S162>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Tracking Mode/Disabled'
 * '<S163>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S164>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/postSat Signal/Forward_Path'
 * '<S165>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limit_Controllers/Control_Limits/PID Controller1/preSat Signal/Forward_Path'
 * '<S166>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limits/Compare To Constant'
 * '<S167>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limits/Compare To Constant1'
 * '<S168>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limits/Enabled adapt'
 * '<S169>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/Limits/Enabled pass'
 * '<S170>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/PID_Controller_Dynamic_Limits/Saturation'
 * '<S171>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/PID_Controller_Dynamic_Limits/pass'
 * '<S172>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Controller_Yaw/PID_Controller_Dynamic_Limits/Saturation/Saturation Dynamic'
 * '<S173>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Damping/Compare To Constant'
 * '<S174>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Monitor_Velocity_Limits/Pitch_rate_limit'
 * '<S175>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Monitor_Velocity_Limits/Roll_Rate_limit'
 * '<S176>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Monitor_Velocity_Limits/Yaw_rate_limit'
 * '<S177>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Monitor_Velocity_Limits/Pitch_rate_limit/If Action Subsystem'
 * '<S178>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Monitor_Velocity_Limits/Pitch_rate_limit/If Action Subsystem1'
 * '<S179>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Monitor_Velocity_Limits/Roll_Rate_limit/If Action Subsystem'
 * '<S180>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Monitor_Velocity_Limits/Roll_Rate_limit/If Action Subsystem1'
 * '<S181>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Monitor_Velocity_Limits/Yaw_rate_limit/If Action Subsystem'
 * '<S182>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Monitor_Velocity_Limits/Yaw_rate_limit/If Action Subsystem1'
 * '<S183>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Voltage_Limitations/If Action limit_pitch'
 * '<S184>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Voltage_Limitations/If Action limit_roll'
 * '<S185>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Voltage_Limitations/If Action limit_yaw'
 * '<S186>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Voltage_Limitations/If Action pass_pitch'
 * '<S187>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Voltage_Limitations/If Action pass_roll'
 * '<S188>' : 'GRM_HIL/Gimbal/Emulate_Gimbal/Gimbel_Ctrl/Gimbal_Controller/Controller/Voltage_Limitations/If Action pass_yaw'
 * '<S189>' : 'GRM_HIL/Initial_States/Assemble_States_Bus'
 * '<S190>' : 'GRM_HIL/Initial_States/Assemble_States_Bus/Rotation Angles to Quaternions'
 * '<S191>' : 'GRM_HIL/Simulation/FDM'
 * '<S192>' : 'GRM_HIL/Simulation/Gimbel_Cmd'
 * '<S193>' : 'GRM_HIL/Simulation/IMU_GPS_Emulator'
 * '<S194>' : 'GRM_HIL/Simulation/FDM/FDM_Linear'
 * '<S195>' : 'GRM_HIL/Simulation/FDM/FDM_Linear/Assemble_States_Bus'
 * '<S196>' : 'GRM_HIL/Simulation/FDM/FDM_Linear/Flight_State'
 * '<S197>' : 'GRM_HIL/Simulation/FDM/FDM_Linear/Motion_Kinematics'
 * '<S198>' : 'GRM_HIL/Simulation/FDM/FDM_Linear/State_Integration'
 * '<S199>' : 'GRM_HIL/Simulation/FDM/FDM_Linear/Assemble_States_Bus/Rotation Angles to Quaternions'
 * '<S200>' : 'GRM_HIL/Simulation/FDM/FDM_Linear/Motion_Kinematics/Drag'
 * '<S201>' : 'GRM_HIL/Simulation/FDM/FDM_Linear/Motion_Kinematics/Gravity'
 * '<S202>' : 'GRM_HIL/Simulation/FDM/FDM_Linear/Motion_Kinematics/NED2PosWGS84Dot'
 * '<S203>' : 'GRM_HIL/Simulation/FDM/FDM_Linear/Motion_Kinematics/Propulsion'
 * '<S204>' : 'GRM_HIL/Simulation/FDM/FDM_Linear/Motion_Kinematics/Reverse Fin Deflection'
 * '<S205>' : 'GRM_HIL/Simulation/FDM/FDM_Linear/Motion_Kinematics/pqr2EulerDot'
 * '<S206>' : 'GRM_HIL/Simulation/FDM/FDM_Linear/Motion_Kinematics/uvw2PosNEDDot'
 * '<S207>' : 'GRM_HIL/Simulation/FDM/FDM_Linear/Motion_Kinematics/Gravity/MATLAB Function'
 * '<S208>' : 'GRM_HIL/Simulation/FDM/FDM_Linear/Motion_Kinematics/NED2PosWGS84Dot/MATLAB Function'
 * '<S209>' : 'GRM_HIL/Simulation/FDM/FDM_Linear/Motion_Kinematics/Propulsion/Compare To Constant'
 * '<S210>' : 'GRM_HIL/Simulation/FDM/FDM_Linear/Motion_Kinematics/Propulsion/Subsystem'
 * '<S211>' : 'GRM_HIL/Simulation/FDM/FDM_Linear/Motion_Kinematics/Propulsion/hold_time'
 * '<S212>' : 'GRM_HIL/Simulation/FDM/FDM_Linear/Motion_Kinematics/uvw2PosNEDDot/MATLAB Function'
 * '<S213>' : 'GRM_HIL/Simulation/FDM/FDM_Linear/Motion_Kinematics/uvw2PosNEDDot/MATLAB Function1'
 * '<S214>' : 'GRM_HIL/Simulation/FDM/FDM_Linear/Motion_Kinematics/uvw2PosNEDDot/MATLAB Function2'
 * '<S215>' : 'GRM_HIL/Simulation/FDM/FDM_Linear/State_Integration/ATT_Integration'
 * '<S216>' : 'GRM_HIL/Simulation/FDM/FDM_Linear/State_Integration/Mass_Balance'
 * '<S217>' : 'GRM_HIL/Simulation/FDM/FDM_Linear/State_Integration/Motor_State_Integration'
 * '<S218>' : 'GRM_HIL/Simulation/FDM/FDM_Linear/State_Integration/POS_NED_Integrator'
 * '<S219>' : 'GRM_HIL/Simulation/FDM/FDM_Linear/State_Integration/POS_WGS84_Integrator'
 * '<S220>' : 'GRM_HIL/Simulation/FDM/FDM_Linear/State_Integration/VEL_Integrator'
 * '<S221>' : 'GRM_HIL/Simulation_Ctrl/Synchronize_to_realtime'
 * '<S222>' : 'GRM_HIL/Simulation_Ctrl/hearbeat_SIM'
 * '<S223>' : 'GRM_HIL/Simulation_Ctrl/hearbeat_SIM/Counter Free-Running'
 * '<S224>' : 'GRM_HIL/Simulation_Ctrl/hearbeat_SIM/Counter Free-Running/Increment Real World'
 * '<S225>' : 'GRM_HIL/Simulation_Ctrl/hearbeat_SIM/Counter Free-Running/Wrap To Zero'
 */
#endif                                 /* RTW_HEADER_GRM_HIL_h_ */
