#ifndef RECT_H
#define RECT_H
#pragma once
#include "Point2.h"

template<class T>
class Rect {
 private:
   Point2<T> m_origin;
   T m_width = 0;
   T m_height = 0;

 public:
   API constexpr Rect() noexcept = default;
   API constexpr Rect(const T width, const T height) noexcept;
   API constexpr Rect(const Point2<T>& origin, const T width, const T height) noexcept;
   API constexpr Rect(const T x, const T y, const T width, const T height) noexcept;

   API constexpr void SetOrigin(const Point2<T>& origin) noexcept;
   API constexpr void SetOrigin(const T x, const T y) noexcept;
   API constexpr void SetWidth(const T width) noexcept;
   API constexpr void SetHeight(const T height) noexcept;

   [[nodiscard]] API constexpr const Point2<T>& GetOrigin() const noexcept;
   [[nodiscard]] API constexpr T GetX() const noexcept;
   [[nodiscard]] API constexpr T GetY() const noexcept;
   [[nodiscard]] API constexpr T GetWidth() const noexcept;
   [[nodiscard]] API constexpr T GetHeight() const noexcept;
   [[nodiscard]] API constexpr T GetLeft() const noexcept;
   [[nodiscard]] API constexpr T GetRight() const noexcept;
   [[nodiscard]] API constexpr T GetBottom() const noexcept;
   [[nodiscard]] API constexpr T GetTop() const noexcept;
};

#include "Rect.hpp"
#endif