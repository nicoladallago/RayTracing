#ifndef DRAW2_H
#define DRAW2_H
#pragma once
#include "Color/COlor.h"

class WindowHandler;

namespace Draw2 {
   inline void Rectangle(const WindowHandler& handler,
                         const Rect<unsigned int>& rect,
                         const Color& color);
   inline void Text(const WindowHandler& handler,
                    const Rect<unsigned int>& rect,
                    const std::string& text);
}

#include "Draw2.hpp"
#endif