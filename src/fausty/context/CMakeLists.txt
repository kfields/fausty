cmake_minimum_required(VERSION 3.14)

set(THIS FaustyContext)

project(${THIS} CXX)

include(${FAUSTY_CMAKE}/Fausty.cmake)
include(${FAUSTY_CMAKE}/Rack.cmake)
include(${FAUSTY_CMAKE}/ImPlot.cmake)
include(${FAUSTY_CMAKE}/ImNodes.cmake)
include(${FAUSTY_CMAKE}/ImKnobs.cmake)

file(GLOB CONTEXT_SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB CONTEXT_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

add_library(${PROJECT_NAME} STATIC
  ${CONTEXT_SRC}
  ${CONTEXT_INCLUDE}
)

USES_FAUSTY(${THIS})
USES_RACK(${THIS})
USES_IMPLOT(${THIS})
USES_IMNODES(${THIS})
USES_IMKNOBS(${THIS})
