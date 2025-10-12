#include <fausty/vst3/rackview.h>

namespace Steinberg {
namespace Panner {

class PannerEditor;

class PannerView : public RackView {
public:
	PannerView(PannerEditor* editor, ViewRect* size);
	virtual void attachedToParent() override;
};

}
}