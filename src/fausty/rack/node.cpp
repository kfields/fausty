#include "node.h"
#include "graph.h"

Node::Node(Graph &graph) : Model(graph)
{
  // graph.AddNode(*this);
}

void Node::AddInput(Pin &input)
{
  inport_.AddPin(input);
  graph().AddInput(input);
}

void Node::AddOutput(Pin &output)
{
  outport_.AddPin(output);
  graph().AddOutput(output);
}
