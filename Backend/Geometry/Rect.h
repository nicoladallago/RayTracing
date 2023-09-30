#ifndef RECT_H
#define RECT_H
#pragma once
#include "Point.h"

template<class T> 
class Rect {
 private:
   constexpr Point<T> m_origin;
   constexpr T m_width = 0;
   constexpr T m_height = 0;

 public:
   API constexpr Rect() noexcept = default;
   API constexpr Rect(const T width, const T height) noexcept;
   API constexpr Rect(const Point<T>& origin, const T width, const T height) noexcept;
   API constexpr Rect(const T x, const T y, const T width, const T height) noexcept;

   API constexpr void SetOrigin(const Point<T>& origin) noexcept;
   API constexpr void SetOrigin(const T x, const T y) noexcept;
   API constexpr void SetWidth(const T width) noexcept;
   API constexpr void SetHeight(const T height) noexcept;

   API [[nodiscard]] constexpr const Point<T>& GetOrigin() const noexcept;
   API [[nodiscard]] constexpr T GetX() const noexcept;
   API [[nodiscard]] constexpr T GetY() const noexcept;
   API [[nodiscard]] constexpr T GetWidth() const noexcept;
   API [[nodiscard]] constexpr T GetHeight() const noexcept;
};

#include "Rect.hpp"
#endif