#include "Application.h"

Application& Application::Instance() noexcept {
   static Application instance;
   return instance;
}