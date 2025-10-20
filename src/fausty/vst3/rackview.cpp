#include "rackeditor.h"
#include "rackview.h"

using namespace Steinberg;

RackView::RackView (RackEditor* editor, ViewRect* size)
: Steinberg::Vst::EditorView(editor, size)
{
}

tresult PLUGIN_API RackView::isPlatformTypeSupported (FIDString type) {
    if (std::strcmp(type, Steinberg::kPlatformTypeX11EmbedWindowID) == 0)
        return kResultTrue;
    return kResultFalse;
}