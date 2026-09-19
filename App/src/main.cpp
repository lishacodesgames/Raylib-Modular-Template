#include "Core/Application.h"
#include "Core/Logging.h"

int main() {
   SetTraceLogCallback(Core::LishaLogger);
   SetTraceLogLevel(LOG_LEVEL);

   Core::Application game = Core::CreateApplication("My Game");
   game.Run();
}