#include <Precompiled.h>
#include "Layers/MenuLayer.h"

#include <raylib.h>
#include <cstdio>
#include "Layers/GameLayer.h"
#include "App.h"

MenuLayer::MenuLayer() : Layer("Menu Layer"),
      m_startButton({320, 250}, {22, 14}, nullptr, "Start the Game", PINK, DARKGRAY, 22)
{
   Image bg = LoadImage("assets/background.jpg");
   if(bg.data) {
      ImageResize(&bg, GetScreenWidth(), GetScreenHeight());
      m_backgroundTexture = LoadTextureFromImage(bg);
      UnloadImage(bg);
   }
}

MenuLayer::~MenuLayer() {
   if(IsTextureValid(m_backgroundTexture))
      UnloadTexture(m_backgroundTexture);
}

void MenuLayer::OnAttach() {
   SetMouseCursor(MOUSE_CURSOR_DEFAULT);
   printf("Menu Layer attached\n");
}

void MenuLayer::OnDetach() {
   printf("Menu Layer detached\n");
}

void MenuLayer::OnUpdate() {
   m_startButton.Update();

   if(m_startButton.isHovered)
      SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
   else 
      SetMouseCursor(MOUSE_CURSOR_DEFAULT);
}

void MenuLayer::OnEvent(Event &e) {
   if(e.GetEventType() == EventType::MouseClicked) {
      if(m_startButton.isHovered) {
         App::Get().QueueLayerSwap(this, new GameLayer());
         e.Handled = true;
      }
   }
}

void MenuLayer::OnRender() {
   DrawTexture(m_backgroundTexture, 0, 0, {240, 240, 240, 150}); // background

   DrawText("Welcome to the Game!", 172, 152, 45, BLACK); // outline
   DrawText("Welcome to the Game!", 170, 150, 45, DARKBLUE);
   m_startButton.Draw();
}
