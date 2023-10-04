#include "Color.h"

constexpr Color::Color(const unsigned char red,
                       const unsigned char green,
                       const unsigned char blue,
                       const unsigned char alpha) noexcept:
    m_red(red),
    m_green(green),
    m_blue(blue),
    m_alpha(alpha) {
}


constexpr Color::Color(const Color& color, const unsigned char alpha) noexcept:
    Color(color.GetRed(), color.GetGreen(), color.GetBlue(), alpha) {
}


constexpr void Color::SetRred(const unsigned char red) noexcept {
   m_red = red;
}


constexpr void Color::SetGreen(const unsigned char green) noexcept {
   m_green = green;
}


constexpr void Color::SetBlue(const unsigned char blue) noexcept {
   m_blue = blue;
}


constexpr void Color::SetAlpha(const unsigned char alpha) noexcept {
   m_alpha = alpha;
}


constexpr unsigned char Color::GetRed() const noexcept {
   return m_red;
}


constexpr unsigned char Color::GetGreen() const noexcept {
   return m_green;
}


constexpr unsigned char Color::GetBlue() const noexcept {
   return m_blue;
}


constexpr unsigned char Color::GetAlpha() const noexcept {
   return m_alpha;
}


constexpr COLORREF Color::ToPlatform() const noexcept {
   return RGB(GetRed(), GetGreen(), GetBlue());
}