#include "base/source/fstring.h"

#include "plug.h"
#include "rackeditor_impl.h"
#include "rackview_impl.h"

namespace Steinberg {
namespace Panner {
//------------------------------------------------------------------------
IPlugView* PLUGIN_API PannerEditorImpl::createView(const char* _name)
{
	ConstString name (_name);
	if (name == Vst::ViewType::kEditor)
	{
		auto* view = new RackViewImpl(this, new Steinberg::ViewRect(0,0,640,480));
		return view;
	}
	return nullptr;
}

//------------------------------------------------------------------------
} // namespace
} // namespace Steinberg
