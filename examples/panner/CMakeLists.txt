cmake_minimum_required(VERSION 3.15)

project(panner LANGUAGES CXX)
set(BINARY_NAME "panner")

set(THIS ${BINARY_NAME})

file(GLOB RUNNER_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB RUNNER_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

include(${FAUSTY_CMAKE}/App.cmake)

add_executable(${THIS} "main.cpp" ${RUNNER_SOURCES} ${RUNNER_INCLUDES})
USES_EXE_APP(${THIS})

add_library(${THIS}_lib ${RUNNER_SOURCES})
USES_EXE_APP(${THIS}_lib)

target_compile_definitions(${THIS} PRIVATE "NOMINMAX" RACK_IMPL)

add_subdirectory(vst3)

if(${SHELL_PLATFORM} STREQUAL "Windows")
add_subdirectory(windows)
elseif(${SHELL_PLATFORM} STREQUAL "X11")
add_subdirectory(x11)
endif()
