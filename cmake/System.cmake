include_guard()

include(${CMAKE_CURRENT_LIST_DIR}/Fausty.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/ImPlot.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/ImNodes.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/ImKnobs.cmake)

function(USES_SYSTEM THIS)
  USES_FAUSTY(${THIS})
  USES_IMPLOT(${THIS})
  USES_IMNODES(${THIS})
  USES_IMKNOBS(${THIS})
  target_link_libraries(${THIS} PRIVATE FaustySystem)
endfunction()
