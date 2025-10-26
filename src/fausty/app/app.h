#pragma once

#include <fausty/shell/shell.h>

namespace fausty {

class App : public Window {
public:
  App();
  static void Boot();
  //virtual ~App();
  void CreateContext() override;

  void Destroy() override;
  bool PostCreate(CreateParams params) override;
  void Render() override;

  //Data members
  static bool booted_;
  bool show_demo_window = true;
  bool show_another_window = false;
};

} // namespace fausty