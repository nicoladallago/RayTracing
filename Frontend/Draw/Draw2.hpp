#include "Draw2.h"
#include "App/WindowHandler.h"

inline void Draw2::Rectangle(const WindowHandler& handler,
                             const Rect<unsigned int>& rect,
                             const Color& color) {
   const COLORREF ref = RGB(color.GetRed(), color.GetGreen(), color.GetBlue());
   RECT reg{};
   reg.left = rect.GetX();
   reg.right = rect.GetX() + rect.GetWidth();
   reg.bottom = rect.GetY();
   reg.top = rect.GetY() + rect.GetHeight();

   FillRect(GetDC(handler.GetBase()), &reg, CreateSolidBrush(ref));
}


void Draw2::Text(const WindowHandler& handler,
                 const Rect<unsigned int>& rect,
                 const std::string& text) {
   RECT reg{};
   reg.left = rect.GetX();
   reg.right = rect.GetX() + rect.GetWidth();
   reg.bottom = rect.GetY();
   reg.top = rect.GetY() + rect.GetHeight();

   SetTextColor(GetDC(handler.GetBase()), 0x00000000);
   SetBkMode(GetDC(handler.GetBase()), TRANSPARENT);
   DrawText(GetDC(handler.GetBase()), text.c_str(), static_cast<int>(text.size()), &reg, DT_CENTER | DT_VCENTER);
}