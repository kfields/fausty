#Note: could go one more level: system/graphics/windows, ie windows/gl3/glfw, windows/dx12/native, etc
cmake_minimum_required(VERSION 3.14)

set(THIS ${PROJECT_NAME}${CMAKE_SYSTEM_NAME}Gl3)

include(${FAUSTY_CMAKE}/Fausty.cmake)
include(${FAUSTY_CMAKE}/Glfw.cmake)
include(${FAUSTY_CMAKE}/ImGui.cmake)

file(GLOB SHELL_SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB SHELL_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

add_library(${THIS} STATIC
  ${SHELL_SRC}
  ${SHELL_INCLUDE}
  ${IMGUI_EX}/imgui_impl_opengl3.cpp
)
USES_FAUSTY(${THIS})
USES_GLFW(${THIS})
USES_IMGUI(${THIS})

target_link_libraries(${THIS} PRIVATE ${PROJECT_NAME}${CMAKE_SYSTEM_NAME} FaustyShell glad_gl_core_33)
