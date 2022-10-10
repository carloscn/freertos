cmake_minimum_required(VERSION 3.15.3)
project(freertos C)

MESSAGE(STATUS "operation system is ${CMAKE_SYSTEM}")

set(CMAKE_C_STANDARD 99)
AUX_SOURCE_DIRECTORY(src DIR_SRCS)

IF(APPLE)

ELSEIF(UNIX)
    MESSAGE(STATUS "Now is Linux")
    # Set cross compile
    SET(CMAKE_SYSTEM_NAME Linux)
    SET(CMAKE_C_COMPILER
        /opt/cross-compile/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-gcc)
    SET(CMAKE_CXX_COMPILER
        /opt/cross-compile/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-g++)

    SET(CMAKE_C_FILAGS "$ENV{CFLAGS} -O0 -Wall -g -ggdb -D GCC_ARMCM3_LM3S102")
    SET(CMAKE_C_FLAGS_RELEASE "$ENV{CFLAGS} -DNODEBUG -O3 -Wall  -D GCC_ARMCM3_LM3S102")

    SET(dir_kernel ./FreeRTOS/FreeRTOS-Kernel)
    SET(dir_app ./FreeRTOS/app/)

    # config include
    include_directories(${dir_app}/include
                        ${dir_kernel}/include
                        ${dir_kernel}/portable/GCC/ARM_CM3
                        )

    # config sources
    file(GLOB_RECURSE APP_SRC_DIR_LIST  "${dir_app}/src/*.c")
    message(STATUS "SRC_DIR_LIST = ${SRC_DIR_LIST}")
    SET(SRC_PATH
        ${dir_kernel}/tasks.c
        ${dir_kernel}/queue.c
        ${dir_kernel}/list.c
        ${dir_kernel}/portable/GCC/ARM_CM3/port.c
        ${dir_kernel}/portable/MemMang/heap_1.c
        #${dir_kernel}/portable/MemMang/heap_2.c
        #${dir_kernel}/portable/MemMang/heap_3.c
        #${dir_kernel}/portable/MemMang/heap_4.c
        #${dir_kernel}/portable/MemMang/heap_5.c
        ${APP_SRC_DIR_LIST}
        )
    link_libraries()
    add_executable(${PROJECT_NAME} ${SRC_PATH})
ENDIF()