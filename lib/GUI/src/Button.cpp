#include <Precompiled.h>
#include "Button.h"

void Button::Draw()  {
   if(isHovering()) {
      DrawRectangleRounded(bounds, 0.8f, 10, ColorBrightness(buttonColor, 0.169f));
      DrawRectangleRoundedLinesEx(bounds, 0.8f, 10, 2, ColorBrightness(buttonColor, -0.1f));
   }
   else
      DrawRectangleRounded(bounds, 0.8f, 10, buttonColor);

   Vector2 textSize = MeasureTextEx(GetFontDefault(), text, 20, 1);
   Vector2 textPos = { 
      bounds.x + (bounds.width - textSize.x) / 2, 
      bounds.y + (bounds.height - textSize.y) / 2 
   };

   DrawTextEx(GetFontDefault(), text, textPos, 20, 1, textColor);
}

bool Button::isHovering() {
   Vector2 mousePos = GetMousePosition();

   return CheckCollisionPointRec(mousePos, bounds);
}

bool Button::isClicked() {
  if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
    Vector2 mousePos = GetMousePosition();

    if (CheckCollisionPointRec(mousePos, bounds)) return true;
  }
  return false;
}