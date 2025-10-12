include_guard()

include(${CMAKE_CURRENT_LIST_DIR}/Fausty.cmake)

function(USES_RUNNER THIS)
  USES_FAUSTY(${THIS})
  target_include_directories(${THIS} PRIVATE
    ${RUNNER_INCLUDE_DIRS}
  )
  #target_link_libraries(${THIS} PRIVATE common)
endfunction()
