#include <pch/Precompiled.h>
#include "Core/Application.h"

#include "Core/Logging.h"
#include "MenuLayer.h"

Core::Application Core::CreateApplication(const std::string& name) {
   Core::Application app;
   app.bgColor = new Color(RAYWHITE);
   Core::ConsoleLog(LISHA_SAYS, std::format("Loading {}...", name));

   InitWindow(800, 600, name.c_str());
   SetTargetFPS(60);

   app.m_layerStack.PushLayer(new MenuLayer());
   Core::ConsoleLog(LISHA_SAYS, std::format("{} Loaded!", name));

   return app;
}

void Core::DestroyApplication(Core::Application& app) {
   app.m_layerStack.Delete();
   CloseWindow();
   Core::Application::s_instance = nullptr;
   Core::ConsoleLog(LISHA_SAYS, "GOODBYE!\n");
}
