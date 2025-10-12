cmake_minimum_required(VERSION 3.14)

project(FaustyVst3 LANGUAGES CXX)
set(THIS ${PROJECT_NAME})

include(${FAUSTY_CMAKE}/Fausty.cmake)
include(${FAUSTY_CMAKE}/VST3SDK.cmake)

file(GLOB SHELL_SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB SHELL_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

add_library(${THIS} STATIC
  ${SHELL_SRC}
  ${SHELL_INCLUDE}
)
USES_FAUSTY(${THIS})
USES_VST3SDK(${THIS})

#target_link_libraries(${THIS} D3d12 dxgi)
