#pragma once

#include <filesystem>

#include <fausty/shell/shell.h>

#include "rackview.h"

using namespace Steinberg::Panner;

class RackViewImpl final : public PannerView
{
public:
	RackViewImpl(PannerEditor* editor, ViewRect* size = nullptr);

	virtual tresult PLUGIN_API attached(void* parent, FIDString type) override;
	virtual tresult PLUGIN_API removed() override;
  virtual tresult PLUGIN_API canResize() override
  {
  return Steinberg::kResultTrue;
  }

	virtual tresult PLUGIN_API onSize(ViewRect* newSize) override;
	void Run();
	//
public:
	Window* window_ = nullptr;
};
