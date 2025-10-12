cmake_minimum_required(VERSION 3.14)

set(THIS ${PROJECT_NAME}${CMAKE_SYSTEM_NAME})

include(${FAUSTY_CMAKE}/Fausty.cmake)
include(${FAUSTY_CMAKE}/ImGui.cmake)
include(${FAUSTY_CMAKE}/Glfw.cmake)
include(${FAUSTY_CMAKE}/X11.cmake)

file(GLOB SHELL_SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB SHELL_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

add_library(${THIS} STATIC
  ${SHELL_SRC}
  ${SHELL_INCLUDE}

  ${IMGUI_EX}/imgui_impl_opengl3.cpp
)

USES_FAUSTY(${THIS})
USES_IMGUI(${THIS})
USES_GLFW(${THIS})
USES_X11(${THIS})

if(${SHELL_BACKEND} STREQUAL "Gl3")
  add_subdirectory(gl3)
elseif(${SHELL_BACKEND} STREQUAL "Dx12")
  add_subdirectory(dx12)
endif()

