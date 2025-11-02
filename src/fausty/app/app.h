#pragma once

#include <fausty/shell/shell.h>

namespace fausty {

class App : public Window {
public:
    App();
    // virtual ~App();

    void CreateContext() override;

    bool DoCreate(CreateParams params) override;
    bool PostCreate(CreateParams params) override;
    void Destroy() override;

    void Render() override;

    // Data members
    bool show_demo_window = true;
    bool show_another_window = false;
};

} // namespace fausty