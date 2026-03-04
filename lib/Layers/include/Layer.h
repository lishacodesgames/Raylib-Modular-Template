#pragma once
#include <string>
#include "Event.h"

class Layer {
public:
   Layer(const std::string& name);
   virtual ~Layer() = default;

   virtual void OnAttach() = 0;
   virtual void OnDetach() = 0;
   virtual void OnUpdate() = 0;
   virtual void OnEvent(Event &e) = 0;

protected:
   std::string m_name;
};