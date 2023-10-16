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
   const std::shared_ptr<Material> m_spMaterial;

 public:
   API Sphere(const Point3d& center, const double radius, const std::shared_ptr<Material>& spMaterial);

   [[nodiscard]] API virtual bool Hit(const Ray& ray, const Interval& rayT, HitRecord& rec) const noexcept override final;
};

#include "Sphere.hpp"
#endif