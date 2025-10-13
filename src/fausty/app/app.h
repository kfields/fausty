#pragma once

#include <fausty/shell/shell.h>

class App : public Window {
public:
  App();
  //virtual ~App();
  /*
  * Context
  */
  bool DoCreate(CreateParams params) override;
  virtual void CreateContext();
  virtual void DestroyContext();
  //Data members
  bool show_demo_window = true;
  bool show_another_window = false;
};