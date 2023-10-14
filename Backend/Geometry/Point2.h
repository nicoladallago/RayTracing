#ifndef POINT2_H
#define POINT2_H
#pragma once

template<class T>
class Point2 {
 private:
   T m_x = 0;
   T m_y = 0;

 public:
   API constexpr Point2() noexcept = default;
   API constexpr Point2(const T x, const T y) noexcept;

   API constexpr bool operator<(const Point2<T>& point) const noexcept;

   API constexpr void SetX(const T x) noexcept;
   API constexpr void SetY(const T y) noexcept;

   [[nodiscard]] API constexpr T GetX() const noexcept;
   [[nodiscard]] API constexpr T GetY() const noexcept;
};

#include "Point2.hpp"

typedef Point2<unsigned int> Point2ui;

#endif