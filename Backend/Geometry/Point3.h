#ifndef POINT3_H
#define POINT3_H
#pragma once
#include "Point2.h"

template<class T>
class Point3 {
 private:
   Point2<T> m_xy;
   constexpr T m_z = 0;

 public:
   API constexpr Point3() noexcept = default;
   API constexpr Point3(const T x, const T y, const T z) noexcept;

   API constexpr void SetX(const T x) noexcept;
   API constexpr void SetY(const T y) noexcept;
   API constexpr void SetZ(const T z) noexcept;

   [[nodiscard]] API constexpr T GetX() const noexcept;
   [[nodiscard]] API constexpr T GetY() const noexcept;
   [[nodiscard]] API constexpr T GetZ() const noexcept;
};

#include "Point3.hpp"
#endif