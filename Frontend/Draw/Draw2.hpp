#include "Draw2.h"

inline void Draw2::Rectangle(HWND hwnd,
                             const Rect<unsigned int>& rect,
                             const Color& color) {
   const COLORREF ref = RGB(color.GetRed(), color.GetGreen(), color.GetBlue());
   RECT reg{};
   reg.left = rect.GetX();
   reg.right = rect.GetX() + rect.GetWidth();
   reg.bottom = rect.GetY();
   reg.top = rect.GetY() + rect.GetHeight();

   FillRect(GetDC(hwnd), &reg, CreateSolidBrush(ref));
}