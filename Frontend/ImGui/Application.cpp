#include "Application.h"

void Application::Init() {
}


void Application::Clean() {
}


Application& Application::Instance() noexcept {
   static Application instance;
   return instance;
}