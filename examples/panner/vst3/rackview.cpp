//#include <plugfarm/controls/toggle.h>

#include <iostream>

#include "rackeditor.h"
#include "rackview.h"
#include "plug.h"

namespace Steinberg {
namespace Panner {


PannerView::PannerView(Panner::PannerEditor* editor, ViewRect* size)
    : RackView(editor, size)
{
}

void PannerView::attachedToParent() {
    std::cout << "PannerView::attachedToParent" << std::endl << std::flush;
    /*Control& control = *new Toggle("toggle", Panner::kBypassId);
    cc_.Add(control);
    cc_.Bind(this);*/
}

}}