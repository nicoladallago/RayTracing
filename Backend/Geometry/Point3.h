#ifndef POINT3_H
#define POINT3_H
#pragma once
#include "Point2.h"

template<class T>
class Point3 {
 private:
   Point2<T> m_xy;
   T m_z = 0;

 public:
   API constexpr Point3() noexcept = default;
   API constexpr Point3(const T& x, const T& y, const T& z) noexcept;
   API constexpr Point3(const Point2<T> point, const T& z) noexcept;

   [[nodiscard]] API constexpr Point3<T> operator-() const noexcept;

   API constexpr Point3<T>& operator+=(const Point3<T>& point) noexcept;
   API constexpr Point3<T>& operator*=(const T& val) noexcept;
   API constexpr Point3<T>& operator/=(const T& val) noexcept;

   API constexpr void SetX(const T x) noexcept;
   API constexpr void SetY(const T y) noexcept;
   API constexpr void SetZ(const T z) noexcept;

   [[nodiscard]] API constexpr const Point2<T>& GetXY() const noexcept;
   [[nodiscard]] API constexpr T GetX() const noexcept;
   [[nodiscard]] API constexpr T GetY() const noexcept;
   [[nodiscard]] API constexpr T GetZ() const noexcept;

   [[nodiscard]] API constexpr T Length() const noexcept;
   [[nodiscard]] API constexpr T LenghtSquared() const noexcept;
   [[nodiscard]] API constexpr bool NearZero() const noexcept;

   [[nodiscard]] API static inline Point3<T> Random() noexcept;                                   // TODO constexpr
   [[nodiscard]] API static inline Point3<T> Random(const double min, const double max) noexcept; // TODO constexpr
};

typedef Point3<unsigned int> Point3ui;
typedef Point3<double> Point3d;
typedef Point3<double> Vector3d;

template<typename T>
[[nodiscard]] API inline std::ostream& operator<<(std::ostream& out, const Point3<T>& point);


template<typename T>
API constexpr Point3<T> operator+(const Point3<T>& p1, const Point3<T>& p2) noexcept;


template<typename T>
API constexpr Point3<T> operator-(const Point3<T>& p1, const Point3<T>& p2) noexcept;


template<typename T>
API constexpr Point3<T> operator*(const Point3<T>& p1, const Point3<T>& p2) noexcept;


template<typename T>
API constexpr Point3<T> operator*(const T& val, const Point3<T>& p) noexcept;


template<typename T>
API constexpr Point3<T> operator*(const Point3<T>& p, const T& val) noexcept;


template<typename T>
API constexpr Point3<T> operator/(const Point3<T>& p, const T& val) noexcept;


template<typename T>
[[nodiscard]] API constexpr T Dot(const Point3<T>& p1, const Point3<T>& p2) noexcept;

template<typename T>
[[nodiscard]] API constexpr Point3<T> Cross(const Point3<T>& p1, const Point3<T>& p2) noexcept;

template<typename T>
[[nodiscard]] API constexpr Point3<T> UnitVector(const Point3<T>& p) noexcept;

template<typename T>
[[nodiscard]] API inline Point3<T> RandomInUnitDisk() noexcept;

template<typename T>
[[nodiscard]] API inline Point3<T> RandomInUnitSphere() noexcept; // TODO constexpr

template<typename T>
[[nodiscard]] API inline Point3<T> RandomUnitVector() noexcept; // TODO constexpr

template<typename T>
[[nodiscard]] API inline Point3<T> RandomOnHemisphere(const Point3<T>& normal) noexcept; // TODO constexpr

template<typename T>
[[nodiscard]] API constexpr Point3<T> Reflect(const Point3<T>& v, const Point3<T>& n) noexcept;

template<typename T>
[[nodiscard]] API constexpr Point3<T> Refract(const Point3<T>& uv, const Point3<T>& n, const T etaiOverEtat) noexcept;

#include "Point3.hpp"
#endif