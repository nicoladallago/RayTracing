#include "Draw2.h"
#include "App/GraphicsHandler.h"
#include "Color/Color.h"

inline void Draw2::Rectangle(const GraphicsHandler& handler,
                             const Rectui& rect,
                             const Color& color) {
   RECT reg{};
   reg.left = static_cast<long>(rect.GetLeft());
   reg.right = static_cast<long>(rect.GetRight());
   reg.bottom = static_cast<long>(rect.GetBottom());
   reg.top = static_cast<long>(rect.GetTop());

   FillRect(handler.GetBase(), &reg, CreateSolidBrush(color.ToPlatform()));
}


void Draw2::Text(const GraphicsHandler& handler,
                 const Rectui& rect,
                 const Color& color,
                 const std::string& text) {
   MoveToEx(handler.GetBase(), static_cast<int>(rect.GetX()), static_cast<int>(rect.GetY()), NULL);
   SetTextAlign(handler.GetBase(), TA_CENTER); // TODO Parameter for text alignement
   SetTextColor(handler.GetBase(), color.ToPlatform());
   SetBkMode(handler.GetBase(), TRANSPARENT);
   TextOut(handler.GetBase(), rect.GetWidth() / 2, rect.GetBottom(), text.c_str(), static_cast<int>(text.size()));
}