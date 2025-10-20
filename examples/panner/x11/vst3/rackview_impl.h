#pragma once

#include <filesystem>

#include <fausty/app/app.h>

#include "rackview.h"

using namespace Steinberg::Panner;

class RackViewImpl final : public PannerView
{
public:
	RackViewImpl(PannerEditor *editor, ViewRect *size = nullptr);

	tresult PLUGIN_API attached(void *parent, FIDString type) override;
	tresult PLUGIN_API removed() override;
	tresult PLUGIN_API canResize() override
	{
		return Steinberg::kResultTrue;
	}

	tresult PLUGIN_API onSize(ViewRect *newSize) override;
	void Run();
	//
public:
	fausty::App *app_ = nullptr;
	void *parent_ = nullptr;
};
