#ifndef SPHERE_H
#define SPHERE_H
#pragma once
#include "Objects/Hittable.h"
#include "Geometry/Point3.h"
#include "Materials/Material.h"

class Ray;

class Sphere: public Hittable {
 private:
   const Point3 m_center;
   const double m_radius;
   const double m_radiusSquared;

   const std::unique_ptr<Material> m_upMaterial;

 public:
   API Sphere(const Point3& center, const double radius, std::unique_ptr<Material> upMaterial);

   [[nodiscard]] API virtual bool Hit(const Ray& ray, const Interval& rayT, HitRecord& rec) const noexcept override final;
};

#include "Sphere.hpp"
#endif