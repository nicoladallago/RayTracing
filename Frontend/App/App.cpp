#include "App.h"
#include "Windows/WindowMain.h"

API int App::Run() {
   WindowMain main;
   main.show();
   return Fl::run();
}