## Building
from faust_build sibling directory:

cmake -S ../faust/build -C ../faust/build/backends/backends.cmake


## Best - Use single float precision for now ...

faust osc.dsp -o osc_dsp.h -I C:/Faust -cn OscDsp -scn FaustModule

faust frenchBell.dsp -o frenchbell_dsp.h -I C:/Faust -cn FrenchBellDsp -scn FaustModule

faust chain.dsp -o chain_dsp.h -I C:/Faust -cn ChainDsp -scn FaustModule

faust freeverb.dsp -o freeverb_dsp.h -I C:/Faust -cn FreeVerbDsp -scn FaustModule