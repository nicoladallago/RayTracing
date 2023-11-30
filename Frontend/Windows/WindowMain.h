#ifndef WINDOW_MAIN_H
#define WINDOW_MAIN_H
#pragma once

class WindowMain: public Fl_Window {
 private:
   static constexpr int WIDTH = 300;
   static constexpr int HEIGHT = 300;

 public:
   WindowMain();

   virtual void show() override final;

 private:
   static void Render();
};

#endif