#pragma once

#include <fausty/shell/shell.h>


class App : public Window {
public:
  App();
  static void Boot();
  //virtual ~App();
  //void Destroy() override;
  /*
  * Context
  */
  bool DoCreate(CreateParams params) override;
  void CreateContext() override;
  //virtual void DestroyContext();
  //Data members
  static bool booted_;
  bool show_demo_window = true;
  bool show_another_window = false;
};