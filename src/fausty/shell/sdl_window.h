#ifndef RUNNER_WIN32_WINDOW_H_
#define RUNNER_WIN32_WINDOW_H_

#include <functional>
#include <memory>
#include <string>
#include <mutex>
#include <queue>

#include <fausty/shell/window.h>

struct SDL_Window;
struct SDL_GPUDevice;

class SdlWindow : public WindowBase
{
public:
  SdlWindow();
  virtual ~SdlWindow();
  virtual void Render() {}

  virtual bool DoCreate(CreateParams params) override;
  virtual bool PostCreate(CreateParams params) override;
  virtual bool DoRun(RunParams params) override;
  virtual bool PostRun(RunParams params) override;
  virtual void Destroy();
  // If true, closing this window will quit the application.
  void SetQuitOnClose(bool quit_on_close);

  // Called from other threads (EditorView::onSize)
  void RequestResize(int w, int h); // thread-safe

protected:
  bool quit_on_close_ = false;
  //
public:
  SDL_Window *window_ = nullptr;
  SDL_GPUDevice *gpu_device_ = nullptr;

private:
  struct Cmd
  {
    enum Kind
    {
      Resize
    } kind;
    int w, h;
  };
  std::mutex mtx_;
  std::queue<Cmd> q_;              // simple thread-safe queue
  void applyResize_(int w, int h); // runs on window thread
};

#endif // RUNNER_WIN32_WINDOW_H_
