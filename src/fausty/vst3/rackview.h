#pragma once

#include "public.sdk/source/vst/vsteditcontroller.h"

#include <fausty/rack/rack.h>
//#include "control_center.h"

using namespace Steinberg;

class RackEditor;

class RackView : public Steinberg::Vst::EditorView
{
public:
	RackView (RackEditor* editor, ViewRect* size = nullptr);
	//Accessors
	RackEditor& editor() { return *((RackEditor*)controller.get()); }
	// 
	//Data members
	//ControlCenter cc_;
};
