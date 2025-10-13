#include "app.h"

using namespace fausty;

int main(int, char**) {
  App& app = *new MyApp();

  app.Run();
}