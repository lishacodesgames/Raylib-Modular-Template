#include <Precompiled.h>
#include <raylib.h>
#include "Game.h"

void Game::Init() {
   constexpr int screenWidth = 800;
   constexpr int screenHeight = 600;

   InitWindow(screenWidth, screenHeight, "Raylib Template");
   SetTargetFPS(60);

   // TODO gonna move this part to MenuLayer once implemented
   Image bg = LoadImage("assets/background.jpg");
   ImageResize(&bg, screenWidth, screenHeight);
   background = LoadTextureFromImage(bg);
   UnloadImage(bg);
}

void Game::Run() {
   while(!WindowShouldClose()) {
      HandleEvents();
      
      BeginDrawing();
      ClearBackground(RAYWHITE);
      DrawTexture(background, 0, 0, Color{240, 240, 240, 100}); // translucent background image

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