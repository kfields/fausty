#include "rackeditor.h"
#include "rackview.h"

IPlugView* PLUGIN_API RackEditor::createView (FIDString name) {
  return new RackView(this);
}