#ifndef POINT3_HPP
#define POINT3_HPP
#pragma once
#include "Point3.h"
#include "Utils/Utils.h"

API constexpr Point3::Point3(const double x, const double y, const double z) noexcept:
    m_x(x),
    m_y(y),
    m_z(z) {
}


API constexpr Point3 Point3::operator-() const noexcept {
   return Point3(-m_x, -m_y, -m_z);
}


API constexpr Point3& Point3::operator+=(const Point3& point) noexcept {
   m_x += point.m_x;
   m_y += point.m_y;
   m_z += point.m_z;
   return *this;
}


API constexpr Point3& Point3::operator*=(const double val) noexcept {
   m_x *= val;
   m_y *= val;
   m_z *= val;
   return *this;
}


API constexpr Point3& Point3::operator/=(const double val) noexcept {
   return *this *= 1 / val;
}


API constexpr void Point3::SetX(const double x) noexcept {
   m_x = x;
}


API constexpr void Point3::SetY(const double y) noexcept {
   m_y = y;
}


API constexpr void Point3::SetZ(const double z) noexcept {
   m_z = z;
}


API constexpr double Point3::GetX() const noexcept {
   return m_x;
}


API constexpr double Point3::GetY() const noexcept {
   return m_y;
}


API constexpr double Point3::GetZ() const noexcept {
   return m_z;
}


API constexpr double Point3::Length() const noexcept {
   return Utils::Sqrt(LenghtSquared());
}


API constexpr double Point3::LenghtSquared() const noexcept {
   return m_x * m_x + m_y * m_y + m_z * m_z;
}


API constexpr bool Point3::NearZero() const noexcept {
   return (Utils::Abs(m_x) < NEAR_ZERO) && (Utils::Abs(m_y) < NEAR_ZERO) && (Utils::Abs(m_z) < NEAR_ZERO);
}


API inline Point3 Point3::Random() noexcept {
   return Point3(Utils::Random(), Utils::Random(), Utils::Random());
}


API inline Point3 Point3::Random(const double min, const double max) noexcept {
   return Point3(Utils::Random(min, max), Utils::Random(min, max), Utils::Random(min, max));
}


API constexpr Point3 operator+(const Point3& p1, const Point3& p2) noexcept {
   return Point3(p1.GetX() + p2.GetX(), p1.GetY() + p2.GetY(), p1.GetZ() + p2.GetZ());
}


API constexpr Point3 operator-(const Point3& p1, const Point3& p2) noexcept {
   return Point3(p1.GetX() - p2.GetX(), p1.GetY() - p2.GetY(), p1.GetZ() - p2.GetZ());
}


API constexpr Point3 operator*(const Point3& p1, const Point3& p2) noexcept {
   return Point3(p1.GetX() * p2.GetX(), p1.GetY() * p2.GetY(), p1.GetZ() * p2.GetZ());
}


API constexpr Point3 operator*(const double val, const Point3& p) noexcept {
   return Point3(val * p.GetX(), val * p.GetY(), val * p.GetZ());
}


API constexpr Point3 operator*(const Point3& p, const double val) noexcept {
   return val * p;
}


API constexpr Point3 operator/(const Point3& p, const double val) noexcept {
   return (1 / val) * p;
}


API constexpr double Dot(const Point3& p1, const Point3& p2) noexcept {
   return p1.GetX() * p2.GetX() + p1.GetY() * p2.GetY() + p1.GetZ() * p2.GetZ();
}


API constexpr Point3 Cross(const Point3& p1, const Point3& p2) noexcept {
   return Point3(p1.GetY() * p2.GetZ() - p1.GetZ() * p2.GetY(),
                 p1.GetZ() * p2.GetX() - p1.GetX() * p2.GetZ(),
                 p1.GetX() * p2.GetY() - p1.GetY() * p2.GetX());
}


API constexpr Point3 UnitVector(const Point3& p) noexcept {
   return p / p.Length();
}


API inline Point3 RandomInUnitDisk() noexcept {
   while(true) {
      const Point3 p = Point3(Utils::Random(-1, 1), Utils::Random(-1, 1), 0);
      if(p.LenghtSquared() < 1)
         return p;
   }
}


API inline Point3 RandomInUnitSphere() noexcept {
   while(true) {
      const Point3 p = Point3::Random(-1, 1);
      if(p.LenghtSquared() < 1) {
         return p;
      }
   }
}


API inline Point3 RandomUnitVector() noexcept {
   return UnitVector(RandomInUnitSphere());
}


API inline Point3 RandomOnHemisphere(const Point3& normal) noexcept {
   const Point3 onUnitSphere = RandomUnitVector();
   if(Dot(onUnitSphere, normal) > 0) {
      return onUnitSphere;
   }
   return -onUnitSphere;
}


API constexpr Point3 Reflect(const Point3& v, const Point3& n) noexcept {
   return v - 2 * Dot(v, n) * n;
}


API constexpr Point3 Refract(const Point3& uv, const Point3& n, const double etaiOverEtat) noexcept {
   const double cosTheta = std::min(Dot(-uv, n), 1.0);
   const Point3 rOutPerp = etaiOverEtat * (uv + cosTheta * n);
   const Point3 rOutParallel = -Utils::Sqrt(Utils::Abs(1 - rOutPerp.LenghtSquared())) * n;
   return rOutPerp + rOutParallel;
}

#endif