#pragma once

#include <fausty/shell/platform/x11/x11_window.h>

class Gl3Window : public X11Window {
public:
  //virtual int Run() override;
  virtual void Destroy();
  virtual bool DoCreate(CreateParams params) override;
  virtual bool PostCreate(CreateParams params) override;
  virtual void Render() override;
  void Draw() override;
  //Data members
  const char* glsl_version_ = nullptr;
};