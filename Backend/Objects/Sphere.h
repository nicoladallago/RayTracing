#ifndef SPHERE_H
#define SPHERE_H
#pragma once
#include "Objects/Hittable.h"
#include "Geometry/Point3.h"

class Ray;
class Material;

class Sphere: public Hittable {
 private:
   const Point3d m_center;
   const double m_radius;
   const std::unique_ptr<Material> m_upMaterial;

 public:
   API Sphere(const Point3d& center, const double radius, std::unique_ptr<Material> upMaterial);

   [[nodiscard]] API virtual bool Hit(const Ray& ray, const Interval& rayT, HitRecord& rec) const noexcept override final;
};

#include "Sphere.hpp"
#endif