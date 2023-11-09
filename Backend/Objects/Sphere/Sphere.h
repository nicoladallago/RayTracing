#ifndef SPHERE_H
#define SPHERE_H
#pragma once
#include "Geometry/Point3.h"

class Ray;
class Interval;
class HitRecord;
class Material;

class Sphere {
 private:
   const Point3 m_center;
   const double m_radius;
   const double m_radiusSquared;

 public:
   API constexpr Sphere(const Point3& center, const double radius) noexcept;
   API virtual ~Sphere() noexcept = default;

   // Rule of 5
   API Sphere(const Sphere&) noexcept = default;
   API Sphere(Sphere&&) noexcept = default;
   //API Sphere& operator=(const Sphere&) noexcept = default;
   //API Sphere& operator=(Sphere&&) noexcept = default;

   [[nodiscard]] API constexpr bool Hit(const Ray& ray, const Interval& rayT, HitRecord& rec) const noexcept;

   [[nodiscard]] API virtual inline const Material& GetMaterial() const noexcept = 0;
};

#include "Sphere.hpp"
#endif