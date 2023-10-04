#include "Draw2.h"
#include "App/GraphicsHandler.h"

inline void Draw2::Rectangle(const GraphicsHandler& handler,
                             const Rect<unsigned int>& rect,
                             const Color& color) {
   RECT reg{};
   reg.left = rect.GetLeft();
   reg.right = rect.GetRight();
   reg.bottom = rect.GetBottom();
   reg.top = rect.GetTop();

   FillRect(handler.GetBase(), &reg, CreateSolidBrush(color.ToPlatform()));
}


void Draw2::Text(const GraphicsHandler& handler,
                 const Rect<unsigned int>& rect,
                 const Color& color,
                 const std::string& text) {
   MoveToEx(handler.GetBase(), rect.GetX(), rect.GetY(), NULL);
   SetTextAlign(handler.GetBase(), TA_CENTER); // TODO Parameter for text alignement
   SetTextColor(handler.GetBase(), color.ToPlatform());
   SetBkMode(handler.GetBase(), TRANSPARENT);
   TextOut(handler.GetBase(), rect.GetWidth() / 2, rect.GetBottom(), text.c_str(), static_cast<int>(text.size()));
}