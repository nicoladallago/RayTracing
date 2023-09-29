#include <limits>
#include <iostream>

#include "Frontend/ImGui/Application.h"

int main(int /*argc*/, char** /*argv*/) {
   Application::Init();

   std::cout << "Hello world" << std::endl;

   Application::Clean();
   return 0;
}