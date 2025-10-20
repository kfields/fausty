#pragma once

#include <thread>
#include <atomic>
#include <optional>

#include "public.sdk/source/vst/vsteditcontroller.h"

#include <fausty/rack/rack.h>

using namespace Steinberg;

class RackEditor;

class RackView : public Steinberg::Vst::EditorView
{
public:
	RackView(RackEditor *editor, ViewRect *size = nullptr);
	tresult PLUGIN_API isPlatformTypeSupported(FIDString type) override;
	// Accessors
	RackEditor &editor() { return *((RackEditor *)controller.get()); }
	//
	// Data members
	std::thread renderThread_;
	std::atomic<bool> running_{false};
	int targetFps_ = 60; // tweak as you like
};
