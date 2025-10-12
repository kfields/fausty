#pragma once

#include "public.sdk/source/vst/vsteditcontroller.h"
using namespace Steinberg;

//-----------------------------------------------------------------------------
class RackEditor : public Steinberg::Vst::EditController
{
public:
  IPlugView* PLUGIN_API createView (FIDString name) SMTG_OVERRIDE;
};
