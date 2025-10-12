#include <fausty/view/faustyview.h>
#include "faustyapp.h"

bool FaustyApp::booted_ = false;

void FaustyApp::Boot() {
  if (booted_) return;
  FaustyView::Boot();
  booted_ = true;
}