#ifndef MAIN_WIDGET_H
#define MAIN_WIDGET_H
#pragma once
#include "Base/Widget.h"

class MainWidget: public Widget {
 public:
   API explicit MainWidget(HWND handler) noexcept;

   API virtual void Draw(const unsigned int width,
                         const unsigned int height) const override final;
};

#endif