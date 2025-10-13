#include "context.h"

class ImGuiContext : public Context {
public:
  void Create() override;
  void Destroy() override;
};
