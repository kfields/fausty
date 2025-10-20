#pragma once

#include <fausty/shell/platform/x11/x11_window.h>

class Gl3Window : public X11Window {
public:
  void Destroy() override;
  bool DoCreate(CreateParams params) override;
  bool PostCreate(CreateParams params) override;
  void Render() override;
  void Draw() override;
  void OnMouseButton(int button, int action, int mods) override;
  //Data members
  const char* glsl_version_ = nullptr;
};