#ifndef BASE_SPHERE_H
#define BASE_SPHERE_H
#pragma once
#include "Geometry/Point3.h"

class Ray;
class Interval;
class HitRecord;

class BaseSphere {
 private:
   const Point3 m_center;
   const double m_radius;
   const double m_radiusSquared;

 public:
   API constexpr BaseSphere(const Point3& center, const double radius) noexcept;

   [[nodiscard]] API constexpr bool HitBase(const Ray& ray, const Interval& rayT, HitRecord& rec) const noexcept;
};

#include "BaseSphere.hpp"
#endif