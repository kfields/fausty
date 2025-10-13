#include <iostream>
#include <cstdlib>

#include <vector>
#include <fausty/rack/node.h>

using namespace fausty;

int main( int argc, char *argv[] )
{
  Node a, b;
  PinT<float> output(a, "input1");
  //output.value_.subscribe();
  return 0;
}
