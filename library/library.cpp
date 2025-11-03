#include <fausty/rack/model_manufacturer.h>

#include <fausty/rack/module/faust_dsp.h>
#include <fausty/rack/module/faust_dsp_ui.h>
#include <fausty/rack/module/module.h>

#include "flanger_dsp.h"
#include "freeverb_dsp.h"
#include "frenchbell_dsp.h"
#include "osc_dsp.h"
#include "phaser_dsp.h"

using namespace fausty;

class FrenchBellDspImpl : public FrenchBellDsp {
public:
    REFLECT_ENABLE(FrenchBellDsp)
};
DEFINE_MODEL_FACTORY(FrenchBellDspImpl, "French Bell", "Instrument")

class OscDspImpl final : public OscDsp {
    REFLECT_ENABLE(FaustDsp)
};
DEFINE_MODEL_FACTORY(OscDspImpl, "Oscillator", "Generator")

class FreeverbDspImpl final : public FreeverbDsp {
    REFLECT_ENABLE(FaustDsp)
};
DEFINE_MODEL_FACTORY(FreeverbDspImpl, "Freeverb", "Reverb")

class FlangerDspImpl final : public FlangerDsp {
    REFLECT_ENABLE(FaustDsp)
};
DEFINE_MODEL_FACTORY(FlangerDspImpl, "Flanger", "Effect")

class PhaserDspImpl final : public PhaserDsp {
    REFLECT_ENABLE(FaustDsp)
};
DEFINE_MODEL_FACTORY(PhaserDspImpl, "Phaser", "Effect")

void InitFaustDspLibrary() {
    REGISTER_MODEL_FACTORY(FrenchBellDspImpl);
    REGISTER_MODEL_FACTORY(OscDspImpl);
    REGISTER_MODEL_FACTORY(FreeverbDspImpl);
    REGISTER_MODEL_FACTORY(FlangerDspImpl);
    REGISTER_MODEL_FACTORY(PhaserDspImpl);
}
