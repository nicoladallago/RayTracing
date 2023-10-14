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
   API constexpr Point3(const T& x, const T& y, const T& z) noexcept;
   API constexpr Point3(const Point2<T> point, const T& z) noexcept;

   [[nodiscard]] API constexpr Point3<T> operator-() const noexcept;

   [[nodiscard]] API constexpr T operator[](const unsigned int index) const;
   [[nodiscard]] API constexpr T& operator[](const unsigned int index);

   [[nodiscard]] API constexpr Point3<T>& operator+=(const Point3<T>& point) noexcept;
   [[nodiscard]] API constexpr Point3<T>& operator*=(const T& val) noexcept;
   [[nodiscard]] API constexpr Point3<T>& operator/=(const T& val) noexcept;

   API constexpr void SetX(const T x) noexcept;
   API constexpr void SetY(const T y) noexcept;
   API constexpr void SetZ(const T z) noexcept;

   [[nodiscard]] API constexpr const Point2<T>& GetXY() const noexcept;
   [[nodiscard]] API constexpr T GetX() const noexcept;
   [[nodiscard]] API constexpr T GetY() const noexcept;
   [[nodiscard]] API constexpr T GetZ() const noexcept;

   [[nodiscard]] API constexpr T Length() const noexcept;
   [[nodiscard]] API constexpr T LenghtSquared() const noexcept;
};

template<typename T>
[[nodiscard]] API inline std::ostream& operator<<(std::ostream& out, const Point3<T>& point);


template<typename T>
[[nodiscard]] API inline Point3<T> operator+(const Point3<T>& p1, const Point3<T>& p2) noexcept;


template<typename T>
[[nodiscard]] API inline Point3<T> operator-(const Point3<T>& p1, const Point3<T>& p2) noexcept;


template<typename T>
[[nodiscard]] API inline Point3<T> operator*(const Point3<T>& p1, const Point3<T>& p2) noexcept;


template<typename T>
[[nodiscard]] API inline Point3<T> operator*(const T& val, const Point3<T>& p) noexcept;


template<typename T>
[[nodiscard]] API inline Point3<T> operator*(const Point3<T>& p, const T& val) noexcept;


template<typename T>
[[nodiscard]] API inline Point3<T> operator/(const Point3<T>& p, const T& val) noexcept;


template<typename T>
[[nodiscard]] API inline T Dot(const Point3<T>& p1, const Point3<T>& p2) noexcept;

template<typename T>
[[nodiscard]] API inline Point3<T> Cross(const Point3<T>& p1, const Point3<T>& p2) noexcept;

template<typename T>
[[nodiscard]] API inline Point3<T> UnitVector(const Point3<T>& p) noexcept;

#include "Point3.hpp"
#endif