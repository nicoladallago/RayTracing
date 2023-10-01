#include "Application.h"

void Application::Init() {

}


Application& Application::Instance() noexcept {
   static Application instance;
   return instance;
}