#ifndef DRAW2_H
#define DRAW2_H
#pragma once
#include "Color/COlor.h"

class GraphicsHandler;

namespace Draw2 {
   inline void Rectangle(const GraphicsHandler& handler,
                         const Rect<unsigned int>& rect,
                         const Color& color);
   inline void Text(const GraphicsHandler& handler,
                    const Rect<unsigned int>& rect,
                    const Color& color,
                    const std::string& text);
}

#include "Draw2.hpp"
#endif