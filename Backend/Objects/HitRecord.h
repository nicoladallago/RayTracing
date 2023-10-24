#ifndef HIT_RECORD_H
#define HIT_RECORD_H
#pragma once
#include "Geometry/Point3.h"

class Ray;

class HitRecord {
 private:
   Point3 m_p;
   Vector3 m_normal;
   double m_t = 0;
   bool m_frontFace = false;

 public:
   constexpr void SetRoot(const double t) noexcept;
   constexpr void SetPoint(const Point3& p) noexcept;

   [[nodiscard]] constexpr const Point3& GetPoint() const noexcept;
   [[nodiscard]] constexpr const Vector3& GetNormal() const noexcept;
   [[nodiscard]] constexpr double GetRoot() const noexcept;
   [[nodiscard]] constexpr bool IsFrontFace() const noexcept;

   void SetFaceFront(const Ray& ray, const Vector3& outwardNormal) noexcept;
};

#include "HitRecord.hpp"
#endif