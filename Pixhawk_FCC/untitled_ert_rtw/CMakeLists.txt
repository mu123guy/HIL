## This cmakelist.txt file was generated from
## the Embedded Coder Support Package for PX4 Autopilots

add_definitions(
-DMODEL=untitled -DNUMST=2 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DON_TARGET_WAIT_FOR_START=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DEXT_MODE=1 -DINTEGER_CODE=0 -DMT=1 -DPX4 -DFMUvx -DNULL=0 -DEXTMODE_DISABLETESTING -DEXTMODE_DISABLEPRINTF -DEXTMODE_DISABLE_ARGS_PROCESSING=1 -DDAEMON_MODE=1 -DSTACK_SIZE=64 -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__ -DRT -DMW_PX4_EXTMODE_BAUD_RATE=115200 -DMW_PX4_EXTMODE_HWPORT="/dev/ttyACM0" )

## Specify locations of header files
include_directories(
"${PX4_SOURCE_DIR}/src/modules/px4_simulink_app"
)

px4_add_module(
MODULE modules__px4_simulink_app
MAIN px4_simulink_app
STACK_MAIN 2000
SRCS
   MW_SCI.c
   ert_main.cpp
   untitled.cpp
   untitled_data.cpp
   updown.c
   ext_work.c
   rtiostream_utils.c
   MW_PX4_TaskControl.cpp
   nuttxinitialize.cpp
   MW_PX4_rtiostream_serial.cpp
   rtiostream_interface.c
   ext_svr_daemon.c
   daemon_checksum.c
   MW_PX4_SCI.h
   MW_SCI.h
   MW_custom_RTOS_header.h
   multiword_types.h
   rtmodel.h
   rtwtypes.h
   untitled.h
   untitled_dt.h
   untitled_private.h
   untitled_types.h
   rtiostream_utils.h
   MW_uORB_busstruct_conversion.h
   dt_info.h
   ext_share.h
   ext_svr.h
   ext_svr_transport.h
   ext_test.h
   ext_types.h
   ext_work.h
   updown.h
   updown_util.h
   upsup_public.h
   rtw_extmode.h
   sysran_types.h
   rtiostream.h
   daemon_checksum.h
   daemon_checksum_prereq.h
   MW_SVD.h
   MW_PX4_TaskControl.h
   nuttxinitialize.h
   MW_target_hardware_resources.h
DEPENDS
    platforms__common
)

string (REPLACE "-Werror" "" CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
string (REPLACE "-Werror" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpermissive -Wno-narrowing")

