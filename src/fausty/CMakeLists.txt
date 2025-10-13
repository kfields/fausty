cmake_minimum_required(VERSION 3.14)

project(Fausty LANGUAGES CXX)
set(THIS ${PROJECT_NAME})

file(GLOB FAUSTY_SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB FAUSTY_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

add_library(${PROJECT_NAME} STATIC
  ${FAUSTY_SRC}
  ${FAUSTY_INCLUDE}
)

include(${FAUSTY_CMAKE}/XTensor.cmake)
USES_XTENSOR(${THIS})

add_subdirectory(shell)
add_subdirectory(vst3)
add_subdirectory(rack)
add_subdirectory(widget)
add_subdirectory(app)
add_subdirectory(system)

