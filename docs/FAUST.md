## Build and Install Faust

```bash
cd depot/faust
make
sudo make install
```

## Faust Compiler Options

[Faust Compiler Options](https://faustdoc.grame.fr/manual/options/)

## Best - Use single float precision for now ...

faust osc.dsp -o osc_dsp.h -I C:/Faust -cn OscDsp -scn fausty::FaustDsp

faust frenchBell.dsp -o frenchbell_dsp.h -I C:/Faust -cn FrenchBellDsp -scn fausty::FaustDsp -ns fausty

faust chain.dsp -o chain_dsp.h -I C:/Faust -cn ChainDsp -scn fausty::FaustDsp

faust freeverb.dsp -o freeverb_dsp.h -I C:/Faust -cn FreeVerbDsp -scn fausty::FaustDsp

```bash
faust bubble.dsp -o bubble_dsp.h -cn BubbleDsp -scn fausty::FaustDsp
```