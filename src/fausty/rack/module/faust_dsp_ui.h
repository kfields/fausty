#pragma once

#include <cstdlib>
#include <cstdint>
#include <cmath>
#include <list>
#include <map>
#include <set>
#include <vector>

#include "faust_ui.h"

using namespace std;


struct Meta : std::map<const char *, const char *>
{
  void declare(const char *key, const char *value)
  {
    (*this)[key] = value;
  }
  const char *get(const char *key, const char *def)
  {
    if (this->find(key) != this->end())
      return (*this)[key];
    else
      return def;
  }
};

namespace fausty {

class Model;

class FaustDsp;

typedef pair<const char *, const char *> strpair;

struct Zone : std::map<const char *, const char *>
{
  void declare(const char *key, const char *value)
  {
    (*this)[key] = value;
  }
  const char *get(const char *key)
  {
    if (this->find(key) != this->end())
      return (*this)[key];
    else
      return nullptr;
  }
  // Metadata
  bool isKnob()
  {
    return this->get("style") == "knob";
  }
};

enum SliderKind {
  Vertical,
  Horizontal
};

class FaustDspUi : public UI
{
public:
  FaustDspUi(FaustDsp &m);
  void PushModel(Model &model);
  Model *PopModel();
  void AddModel(Model &model);
  // Builder methods
  virtual void declare(float *zone, const char *key, const char *value) override;

  virtual void addButton(const char *label, float *zone) override;
  virtual void addToggleButton(const char *label, float *zone) override;
  virtual void addCheckButton(const char *label, float *zone) override;
  void addKnob(const char *label, float *zone, float init, float min, float max, float step);
  virtual void addVerticalSlider(const char *label, float *zone, float init, float min, float max, float step) override;
  virtual void addHorizontalSlider(const char *label, float *zone, float init, float min, float max, float step) override;
  virtual void addNumEntry(const char *label, float *zone, float init, float min, float max, float step) override;

  // -- passive widgets
  virtual void addNumDisplay(const char *label, float *zone, int precision) override;
  virtual void addTextDisplay(const char *label, float *zone, char *names[], float min, float max) override;
  virtual void addHorizontalBargraph(const char *label, float *zone, float min, float max) override;
  virtual void addVerticalBargraph(const char *label, float *zone, float min, float max) override;

  // -- frames and labels
  virtual void openFrameBox(const char *label) override;
  virtual void openTabBox(const char *label) override;
  virtual void openHorizontalBox(const char *label) override;
  virtual void openVerticalBox(const char *label) override;
  virtual void closeBox() override;

  // Data members
  FaustDsp *m_;
  map<int, list<strpair>> metadata_;
  map<FAUSTFLOAT*, Zone> zones_;
  int nelems_, nports_;
  std::vector<Model *> models_;
  bool is_top_ = true;
};

} // namespace fausty