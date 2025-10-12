#pragma once

#include <fausty/shell/shell.h>

class App : public Window {
public:
  App();
  //App(const char* name, int argc, char** argv);
  //virtual ~App();
  /*
  * Context
  */
  virtual void CreateContext() override;
  virtual void DestroyContext() override;
  //Data members
  bool show_demo_window = true;
  bool show_another_window = false;
};