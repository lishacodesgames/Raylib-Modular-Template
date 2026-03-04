#include <Precompiled.h>
#include <raylib.h>
#include "Game.h"

void Game::Init() {
   constexpr int screenWidth = 800;
   constexpr int screenHeight = 600;

   InitWindow(screenWidth, screenHeight, "Raylib Template");
   SetTargetFPS(60);
}

void Game::Run() {
   while(!WindowShouldClose()) {
      HandleEvents();
      
      BeginDrawing();
      ClearBackground(RAYWHITE);
      Draw();
      EndDrawing();
   }

   CloseWindow();
}

void Game::HandleEvents() {
   if(IsKeyDown(KEY_RIGHT))
      x += 4;
   if(IsKeyDown(KEY_LEFT))
      x -= 4;
   if(IsKeyDown(KEY_UP))
      y -= 4;
   if(IsKeyDown(KEY_DOWN))
      y += 4;
}

void Game::Draw() {
   DrawCircle(x, y, 25, PINK);
}