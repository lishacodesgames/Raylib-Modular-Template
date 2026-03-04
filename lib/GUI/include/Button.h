#pragma once
#include <raylib.h>

struct Button {
   Rectangle bounds;
   Color buttonColor;
   
   const char* text;
   Color textColor;
   
   bool isHovering();
   bool isClicked();

   void Draw();
};