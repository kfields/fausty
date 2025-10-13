cmake_minimum_required(VERSION 3.14)

project(FaustyShell LANGUAGES CXX)
set(THIS ${PROJECT_NAME})

include(${FAUSTY_CMAKE}/Fausty.cmake)
include(${FAUSTY_CMAKE}/ImGui.cmake)
include(${FAUSTY_CMAKE}/Glfw.cmake)

file(GLOB SHELL_SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB SHELL_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

add_library(${THIS} STATIC
  ${SHELL_SRC}
  ${SHELL_INCLUDE}
  ${IMGUI_EX}/imgui_impl_glfw.cpp
)

USES_FAUSTY(${THIS})
USES_IMGUI(${THIS})
USES_GLFW(${THIS})

target_link_libraries(${THIS} PRIVATE ${PROJECT_NAME}${CMAKE_SYSTEM_NAME} glfw)

if(${SHELL_PLATFORM} STREQUAL "X11")
  add_subdirectory(platform/x11)
elseif(${SHELL_PLATFORM} STREQUAL "Windows")
  add_subdirectory(platform/windows)
endif()