#include "App.h"
#include "Core/Logging.h"

int main() {
   SetTraceLogCallback(Core::LishaLogger);
   SetTraceLogLevel(LOG_LEVEL);

   App game("Raylib Modular Template Example Game");
   game.Run();

   return 0;
}