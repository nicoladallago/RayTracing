#ifndef COLOR_H
#define COLOR_H
#pragma once

class Color {
 private:
   uint8_t m_red = 0;
   uint8_t m_green = 0;
   uint8_t m_blue = 0;
   uint8_t m_alpha = std::numeric_limits<uint8_t>::max();

 public:
   constexpr Color() noexcept = default;
   constexpr Color(const uint8_t red,
                   const uint8_t green,
                   const uint8_t blue,
                   const uint8_t alpha = std::numeric_limits<uint8_t>::max()) noexcept;
   constexpr Color(const Color& color, const uint8_t alpha = std::numeric_limits<uint8_t>::max()) noexcept;

   constexpr void SetRred(const uint8_t red) noexcept;
   constexpr void SetGreen(const uint8_t green) noexcept;
   constexpr void SetBlue(const uint8_t blue) noexcept;
   constexpr void SetAlpha(const uint8_t alpha) noexcept;

   [[nodiscard]] constexpr uint8_t GetRed() const noexcept;
   [[nodiscard]] constexpr uint8_t GetGreen() const noexcept;
   [[nodiscard]] constexpr uint8_t GetBlue() const noexcept;
   [[nodiscard]] constexpr uint8_t GetAlpha() const noexcept;

   [[nodiscard]] constexpr COLORREF ToPlatform() const noexcept;
};

#include "Color.hpp"
#endif