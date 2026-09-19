#pragma once
#include "Core/Event.h"
#include "Core/Layer.h"

class GameLayer : public Core::Layer {
public:
   GameLayer();
   ~GameLayer() = default;

   void OnAttach() override;
   void OnUpdate() override;
   void OnEvent(Core::Event& e) override;
   void OnRender() override;
private:
   int x = 400, y = 300;
};