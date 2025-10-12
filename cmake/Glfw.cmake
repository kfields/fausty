include_guard()

function(USES_GLFW THIS)
  target_include_directories(${THIS} PRIVATE
    ${GLFW_ROOT}/include
  )
  target_link_libraries(${THIS} PRIVATE glfw)

endfunction()
