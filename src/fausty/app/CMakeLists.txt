cmake_minimum_required(VERSION 3.14)

project(FaustyApp LANGUAGES CXX)
set(THIS ${PROJECT_NAME})

include(${FAUSTY_CMAKE}/Shell.cmake)
include(${FAUSTY_CMAKE}/Rack.cmake)
include(${FAUSTY_CMAKE}/View.cmake)

file(GLOB APP_SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB APP_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

add_library(${PROJECT_NAME} STATIC
  ${APP_SRC}
  ${APP_INCLUDE}
)

USES_SHELL(${THIS})
USES_RACK(${THIS})
USES_VIEW(${THIS})
