#include "Color.h"

constexpr Color::Color(const uint8_t red,
                       const uint8_t green,
                       const uint8_t blue,
                       const uint8_t alpha) noexcept:
    m_red(red),
    m_green(green),
    m_blue(blue),
    m_alpha(alpha) {
}


constexpr Color::Color(const Color& color, const uint8_t alpha) noexcept:
    Color(color.GetRed(), color.GetGreen(), color.GetBlue(), alpha) {
}


constexpr void Color::SetRred(const uint8_t red) noexcept {
   m_red = red;
}


constexpr void Color::SetGreen(const uint8_t green) noexcept {
   m_green = green;
}


constexpr void Color::SetBlue(const uint8_t blue) noexcept {
   m_blue = blue;
}


constexpr void Color::SetAlpha(const uint8_t alpha) noexcept {
   m_alpha = alpha;
}


constexpr uint8_t Color::GetRed() const noexcept {
   return m_red;
}


constexpr uint8_t Color::GetGreen() const noexcept {
   return m_green;
}


constexpr uint8_t Color::GetBlue() const noexcept {
   return m_blue;
}


constexpr uint8_t Color::GetAlpha() const noexcept {
   return m_alpha;
}


constexpr COLORREF Color::ToPlatform() const noexcept {
   return RGB(GetRed(), GetGreen(), GetBlue());
}