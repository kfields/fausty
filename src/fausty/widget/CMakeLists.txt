cmake_minimum_required(VERSION 3.14)

set(THIS FaustyView)

project(${THIS} CXX)

include(${FAUSTY_CMAKE}/Fausty.cmake)
include(${FAUSTY_CMAKE}/Rack.cmake)
include(${FAUSTY_CMAKE}/ImPlot.cmake)
include(${FAUSTY_CMAKE}/ImNodes.cmake)
include(${FAUSTY_CMAKE}/ImKnobs.cmake)

file(GLOB WIDGET_SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB WIDGET_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

file(GLOB VIEW_SRC ${CMAKE_CURRENT_SOURCE_DIR}/view/*.cpp)
file(GLOB VIEW_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/view/*.h)

add_library(${PROJECT_NAME} STATIC
  ${VIEW_SRC}
  ${VIEW_INCLUDE}
  ${WIDGET_SRC}
  ${WIDGET_INCLUDE}
)

USES_FAUSTY(${THIS})
USES_RACK(${THIS})
USES_IMPLOT(${THIS})
USES_IMNODES(${THIS})
USES_IMKNOBS(${THIS})
