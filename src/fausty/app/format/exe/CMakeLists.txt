cmake_minimum_required(VERSION 3.14)

set(THIS ${PROJECT_NAME}Exe)

include(${FAUSTY_CMAKE}/Rack.cmake)

file(GLOB EXE_SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB EXE_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

add_library(${THIS} STATIC
  ${EXE_SRC}
  ${EXE_INCLUDE}
)
USES_RACK(${THIS})
