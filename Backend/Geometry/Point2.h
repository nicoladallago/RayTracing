#ifndef POINT2_H
#define POINT2_H
#pragma once

template<class T>
class Point2 {
 private:
   constexpr T m_x = 0;
   constexpr T m_y = 0;

 public:
   API constexpr Point2() noexcept = default;
   API constexpr Point2(const T x, const T y) noexcept;

   API constexpr void SetX(const T x) noexcept;
   API constexpr void SetY(const T y) noexcept;

   API [[nodiscard]] constexpr T GetX() const noexcept;
   API [[nodiscard]] constexpr T GetY() const noexcept;
};

#include "Point2.hpp"
#endif