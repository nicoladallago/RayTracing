#ifndef POINT_H
#define POINT_H
#pragma once

template<class T>
class Point {
 private:
   constexpr T m_x = 0;
   constexpr T m_y = 0;

 public:
   API constexpr Point() noexcept = default;
   API constexpr Point(const T x, const T y) noexcept;

   API constexpr void SetX(const T x) noexcept;
   API constexpr void SetY(const T y) noexcept;

   API [[nodiscard]] constexpr T GetX() const noexcept;
   API [[nodiscard]] constexpr T GetY() const noexcept;
};

#include "Point.hpp"
#endif