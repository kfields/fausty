#pragma once

#include <vector>

#include <fausty/rack/node.h>
#include <fausty/rack/audio_pin.h>

namespace fausty {

class Module : public Node
{
public:
  //
  virtual bool Create(Part &owner) override;
  virtual Audio ProcessAudio(Audio input = Audio()) { return Audio(); }
  virtual void Process() {}
  // Data members
  const char *label_ = nullptr;
  AudioPin *audio_in_ = nullptr;
  AudioPin *audio_out_ = nullptr;

  REFLECT_ENABLE(Node)
};

} // namespace fausty