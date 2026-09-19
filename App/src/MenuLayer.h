#pragma once
#include <raylib.h>
#include "Core/Event.h"
#include "Core/Layer.h"
#include "GUI/Button.h"

class MenuLayer : public Core::Layer {
public:
   MenuLayer();
   ~MenuLayer() override;

   void OnAttach() override;
   void OnUpdate() override;
   void OnEvent(Core::Event &e) override;
   void OnRender() override;
private:
   Texture2D m_backgroundTexture = {0};
   GUI::Button m_startButton;
};