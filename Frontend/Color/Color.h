#ifndef COLOR_H
#define COLOR_H
#pragma once

class Color {
 private:
   unsigned char m_red = 0;
   unsigned char m_green = 0;
   unsigned char m_blue = 0;
   unsigned char m_alpha = std::numeric_limits<unsigned char>::max();

 public:
   constexpr Color() noexcept = default;
   constexpr Color(const unsigned char red,
                   const unsigned char green,
                   const unsigned char blue,
                   const unsigned char alpha = std::numeric_limits<unsigned char>::max()) noexcept;
   constexpr Color(const Color& color, const unsigned char alpha = std::numeric_limits<unsigned char>::max()) noexcept;

   constexpr void SetRred(const unsigned char red) noexcept;
   constexpr void SetGreen(const unsigned char green) noexcept;
   constexpr void SetBlue(const unsigned char blue) noexcept;
   constexpr void SetAlpha(const unsigned char alpha) noexcept;

   [[nodiscard]] constexpr unsigned char GetRed() const noexcept;
   [[nodiscard]] constexpr unsigned char GetGreen() const noexcept;
   [[nodiscard]] constexpr unsigned char GetBlue() const noexcept;
   [[nodiscard]] constexpr unsigned char GetAlpha() const noexcept;

   [[nodiscard]] constexpr COLORREF ToPlatform() const noexcept;
};

#include "Color.hpp"
#endif