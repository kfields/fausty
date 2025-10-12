include_guard()

include(${CMAKE_CURRENT_LIST_DIR}/Fausty.cmake)

function(USES_RACK THIS)
USES_FAUSTY(${THIS})
target_link_libraries(${THIS} PRIVATE FaustyRack)
endfunction()
