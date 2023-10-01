#ifndef DRAW2_H
#define DRAW2_H
#pragma once
#include "Color/COlor.h"

namespace Draw2 {
   inline void Rectangle(HWND hwnd,
                         const Rect<unsigned int>& rect,
                         const Color& color);
}

#include "Draw2.hpp"
#endif