#pragma once

#include "public.sdk/source/vst/vstparameters.h"

namespace Steinberg {
namespace Panner {

// HERE are defined the parameter Ids which are exported to the host
enum PannerParams : Vst::ParamID
{
	kBypassId = 100,

	kParamPanId = 102,
};


// HERE you have to define new unique class ids: for processor and for controller
// you can use GUID creator tools like https://www.guidgenerator.com/
static const FUID MyProcessorUID (0xA2EAF7DB, 0x320640F4, 0x8EDE380D, 0xDF89562C);
static const FUID MyControllerUID (0x239F80C2, 0x4F1442C4, 0x8B58AE6E, 0x7C8644EB);

//------------------------------------------------------------------------
} // namespace Panner
} // namespace Steinberg
