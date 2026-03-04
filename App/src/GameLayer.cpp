#include <Precompiled.h>
#include <cstdio>
#include "GameLayer.h"
#include "Layer.h"

GameLayer::GameLayer() : Layer("GameLayer") {}

void GameLayer::OnAttach() {
   printf("Game Layer attached\n");
}

void GameLayer::OnDetach() {
   printf("Game Layer detached\n");
}

void GameLayer::OnUpdate() {
  if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) x += 4;
  if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) x -= 4;
  if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) y -= 4;
  if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) y += 4;
}

void GameLayer::OnEvent(Event& e) {
   if(e.GetEventType() == EventType::KeyPressed) {
      char key = static_cast<KeyPressedEvent&>(e).key;
      printf("Key Pressed: %c\n", key);
   }
}

void GameLayer::OnRender() {
   DrawCircle(x, y, 25, PINK);
}
