#pragma once

#include <vector>
#include <map>
#include <string>
#include <typeindex>

namespace fausty {

class WidgetFactory;

class WidgetManager {
public:
  static void AddFactory(WidgetFactory& factory);
  static WidgetFactory* GetFactory(std::type_index& key);
  static WidgetFactory* FindFactory(const std::type_index& type);
  //Data members
  static std::vector<WidgetFactory*> factories_;
  static std::map<std::type_index, WidgetFactory*> factory_map_;
};

#define REGISTER_WIDGET_FACTORY(T) \
  extern WidgetFactory* Get##T##Factory(); \
  WidgetManager::AddFactory(*Get##T##Factory());

} // namespace fausty