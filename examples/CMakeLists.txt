cmake_minimum_required(VERSION 3.15)

include(${FAUSTY_CMAKE}/RtAudio.cmake)

include(${FAUSTY_CMAKE}/Fausty.cmake)
include(${FAUSTY_CMAKE}/Rack.cmake)
include(${FAUSTY_CMAKE}/ExeApp.cmake)
include(${FAUSTY_CMAKE}/ImNodes.cmake)

add_executable(rtplaysaw rtplaysaw.cpp)
USES_RTAUDIO(rtplaysaw)

add_executable(xtbuffer xtbuffer.cpp ${FAUSTY_HEADERS})
USES_RTAUDIO(xtbuffer)
USES_FAUSTY(xtbuffer)

add_executable(ports ports.cpp ${FAUSTY_HEADERS})
USES_RTAUDIO(ports)
USES_RACK(ports)

add_executable(app app.cpp ${FAUSTY_HEADERS})
USES_EXE_APP(app)

add_executable(graph graph.cpp ${FAUSTY_HEADERS})
USES_EXE_APP(graph)
USES_IMNODES(graph)

add_subdirectory(panner)

add_subdirectory(osc)

add_subdirectory(frenchbell)

add_subdirectory(chain)

add_subdirectory(multi)

add_subdirectory(bubble)