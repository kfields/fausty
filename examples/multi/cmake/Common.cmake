include_guard()

include(${FAUSTY_CMAKE}/Fausty.cmake)

function(USES_COMMON THIS)
USES_FAUSTY(${THIS})
target_include_directories(${THIS} PRIVATE ${PROJECT_ROOT})
endfunction()
