include_guard()

include(${CMAKE_CURRENT_LIST_DIR}/Fmt.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/XTensor.cmake)

function(USES_FAUSTY THIS)
  USES_FMT(${THIS})
  USES_XTENSOR(${THIS})
  target_include_directories(${THIS} PRIVATE ${FAUSTY_ROOT}/src)
  target_link_libraries(${THIS} PRIVATE Fausty)
  target_compile_definitions(${THIS} PRIVATE "NOMINMAX")
endfunction()
