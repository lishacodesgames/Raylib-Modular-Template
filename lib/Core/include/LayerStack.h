#pragma once
#include <Layer.h>
#include <cstdint>
#include <vector>

class LayerStack {
public:
   LayerStack() = default;
   ~LayerStack() = default;

   void PushLayer(Layer* layer);
   void PushOverlay(Layer* overlay);
   void PopLayer(Layer* layer);
   void Delete(); // explicit deletion of pointers

   // to allow range based forloops over the layerstack object itself
   std::vector<Layer*>::iterator begin();
   std::vector<Layer*>::iterator end();
   std::vector<Layer*>::reverse_iterator rbegin();
   std::vector<Layer*>::reverse_iterator rend();

private:
   std::vector<Layer*> m_Layers{};

   /// makes sure standard layers get placed before overlay layers
   uint32_t m_layerInsertIndex = 0;
};