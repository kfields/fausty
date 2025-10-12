#include "rackeditor.h"
#include "rackview.h"

using namespace Steinberg;

RackView::RackView (RackEditor* editor, ViewRect* size)
: Steinberg::Vst::EditorView(editor, size)
{
}