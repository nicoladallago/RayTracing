#ifndef POINT3_H
#define POINT3_H
#pragma once

class Point3 {
 private:
   static constexpr double NEAR_ZERO = 1E-8;

   double m_x = 0;
   double m_y = 0;
   double m_z = 0;

 public:
   API constexpr Point3() noexcept = default;
   API constexpr Point3(const double x, const double y, const double z) noexcept;

   [[nodiscard]] API constexpr Point3 operator-() const noexcept;

   API constexpr Point3& operator+=(const Point3& point) noexcept;
   API constexpr Point3& operator*=(const double val) noexcept;
   API constexpr Point3& operator/=(const double val) noexcept;

   API constexpr void SetX(const double x) noexcept;
   API constexpr void SetY(const double y) noexcept;
   API constexpr void SetZ(const double z) noexcept;

   [[nodiscard]] API constexpr double GetX() const noexcept;
   [[nodiscard]] API constexpr double GetY() const noexcept;
   [[nodiscard]] API constexpr double GetZ() const noexcept;

   [[nodiscard]] API inline double Length() const noexcept;
   [[nodiscard]] API constexpr double LenghtSquared() const noexcept;
   [[nodiscard]] API inline bool NearZero() const noexcept;

   [[nodiscard]] API static inline Point3 Random() noexcept;                                   // TODO constexpr
   [[nodiscard]] API static inline Point3 Random(const double min, const double max) noexcept; // TODO constexpr
};

typedef Point3 Vector3;
typedef Point3 Pixel;

API constexpr Point3 operator+(const Point3& p1, const Point3& p2) noexcept;
API constexpr Point3 operator-(const Point3& p1, const Point3& p2) noexcept;
API constexpr Point3 operator*(const Point3& p1, const Point3& p2) noexcept;
API constexpr Point3 operator*(const double val, const Point3& p) noexcept;
API constexpr Point3 operator*(const Point3& p, const double val) noexcept;
API constexpr Point3 operator/(const Point3& p, const double val) noexcept;
[[nodiscard]] API constexpr double Dot(const Point3& p1, const Point3& p2) noexcept;
[[nodiscard]] API constexpr Point3 Cross(const Point3& p1, const Point3& p2) noexcept;
[[nodiscard]] API constexpr Point3 UnitVector(const Point3& p) noexcept;
[[nodiscard]] API inline Point3 RandomInUnitDisk() noexcept;
[[nodiscard]] API inline Point3 RandomInUnitSphere() noexcept;                     // TODO constexpr
[[nodiscard]] API inline Point3 RandomUnitVector() noexcept;                       // TODO constexpr
[[nodiscard]] API inline Point3 RandomOnHemisphere(const Point3& normal) noexcept; // TODO constexpr
[[nodiscard]] API constexpr Point3 Reflect(const Point3& v, const Point3& n) noexcept;
[[nodiscard]] API inline Point3 Refract(const Point3& uv, const Point3& n, const double etaiOverEtat) noexcept;

#include "Point3.hpp"
#endif