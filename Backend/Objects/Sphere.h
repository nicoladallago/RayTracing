#ifndef SPHERE_H
#define SPHERE_H
#pragma once
#include "Objects/Hittable.h"
#include "Geometry/Point3.h"
#include "Geometry/Ray.h"
#include "Image/Image.h"

class Sphere: public Hittable {
 private:
   const Point3d m_center;
   const double m_radius;

 public:
   API constexpr Sphere(const Point3d& center, const double radius);

   [[nodiscard]] API virtual constexpr bool Hit(const Ray& ray, const double rayMin, const double rayMax, HitRecord& rec) const noexcept override final;
};

#include "Sphere.hpp"
#endif