#ifndef POINT2_H
#define POINT2_H
#pragma once

template<class T>
class Point2 {
 public:
   static constexpr double NEAR_ZERO = 1E-8;

 private:
   T m_x = 0;
   T m_y = 0;

 public:
   API constexpr Point2() noexcept = default;
   API constexpr Point2(const T& x, const T& y) noexcept;

   [[nodiscard]] API constexpr Point2<T> operator-() const noexcept;

   API constexpr Point2<T>& operator+=(const Point2<T>& point) noexcept;
   API constexpr Point2<T>& operator*=(const T& val) noexcept;
   API constexpr Point2<T>& operator/=(const T& val) noexcept;

   API constexpr bool operator<(const Point2<T>& point) const noexcept;

   API constexpr void SetX(const T x) noexcept;
   API constexpr void SetY(const T y) noexcept;

   [[nodiscard]] API constexpr T GetX() const noexcept;
   [[nodiscard]] API constexpr T GetY() const noexcept;

   [[nodiscard]] API constexpr T Length() const noexcept;
   [[nodiscard]] API constexpr T LenghtSquared() const noexcept;
   [[nodiscard]] API constexpr bool NearZero() const noexcept;

   [[nodiscard]] API static inline Point2<T> Random() noexcept;                                   // TODO constexpr
   [[nodiscard]] API static inline Point2<T> Random(const double min, const double max) noexcept; // TODO constexpr
};

typedef Point2<unsigned int> Point2ui;
typedef Point2<double> Point2d;


template<typename T>
API inline Point2<T> operator+(const Point2<T>& p1, const Point2<T>& p2) noexcept;


template<typename T>
API inline Point2<T> operator-(const Point2<T>& p1, const Point2<T>& p2) noexcept;


template<typename T>
API inline Point2<T> operator*(const Point2<T>& p1, const Point2<T>& p2) noexcept;


template<typename T>
API inline Point2<T> operator*(const T& val, const Point2<T>& p) noexcept;


template<typename T>
API inline Point2<T> operator*(const Point2<T>& p, const T& val) noexcept;


template<typename T>
API inline Point2<T> operator/(const Point2<T>& p, const T& val) noexcept;


template<typename T>
[[nodiscard]] API inline T Dot(const Point2<T>& p1, const Point2<T>& p2) noexcept;


// TODO Cross?

template<typename T>
[[nodiscard]] API inline Point2<T> UnitVector(const Point2<T>& p) noexcept;

#include "Point2.hpp"
#endif