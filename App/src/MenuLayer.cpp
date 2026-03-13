#include <pch/Precompiled.h>
#include "MenuLayer.h"

#include <raylib.h>
#include "GUI/Button.h"
#include "GameLayer.h"
#include "App.h"

MenuLayer::MenuLayer() : Core::Layer("Menu Layer"),
      m_startButton({320, 250}, {22, 14}, "Start the Game", PINK, DARKGRAY, 22)
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
   Core::Layer::OnAttach();
}

void MenuLayer::OnUpdate() {
   m_startButton.Update();

   if(m_startButton.isHovered)
      SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
   else 
      SetMouseCursor(MOUSE_CURSOR_DEFAULT);
}

void MenuLayer::OnEvent(Core::Event &e) {
   if(e.GetEventType() == Core::EventType::MouseClicked) {
      if(m_startButton.isHovered) {
         App::QueueLayerSwap(this, new GameLayer());
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
