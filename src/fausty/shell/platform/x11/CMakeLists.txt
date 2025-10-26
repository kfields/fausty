cmake_minimum_required(VERSION 3.14)

#set(THIS ${PROJECT_NAME}${CMAKE_SYSTEM_NAME})
set(THIS ${PROJECT_NAME}${SHELL_PLATFORM})

include(${FAUSTY_CMAKE}/Fausty.cmake)
include(${FAUSTY_CMAKE}/ImGui.cmake)
include(${FAUSTY_CMAKE}/Sdl.cmake)
include(${FAUSTY_CMAKE}/X11.cmake)

file(GLOB SHELL_SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB SHELL_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

add_library(${THIS} STATIC
  ${SHELL_SRC}
  ${SHELL_INCLUDE}

  ${IMGUI_EX}/imgui_impl_sdlgpu3.cpp
)

USES_FAUSTY(${THIS})
USES_IMGUI(${THIS})
USES_SDL(${THIS})
USES_X11(${THIS})

target_link_libraries(${THIS} PRIVATE FaustyShell)