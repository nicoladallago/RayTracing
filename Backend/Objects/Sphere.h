#ifndef SPHERE_H
#define SPHERE_H
#pragma once
#include "Geometry/Point3.h"
#include "Materials/Material.h"

class Ray;
class Interval;
class HitRecord;

class Sphere {
 private:
   const Point3 m_center;
   const double m_radius;
   const double m_radiusSquared;
   std::unique_ptr<Material> m_upMaterial;

 public:
   API constexpr Sphere(const Point3& center, const double radius, std::unique_ptr<Material> upMaterial) noexcept;

   [[nodiscard]] API constexpr bool Hit(const Ray& ray, const Interval& rayT, HitRecord& rec) const noexcept;

   [[nodiscard]] API constexpr const Material& GetMaterial() const noexcept;
};

#include "Sphere.hpp"
#endif