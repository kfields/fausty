#include "app.h"

int main(int, char**) {
  App& app = *new MyApp();

  app.Run();
}