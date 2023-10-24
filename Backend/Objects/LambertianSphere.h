#ifndef LAMBERTIAN_SPHERE_H
#define LAMBERTIAN_SPHERE_H
#pragma once
#include "Objects/BaseSphere.h"
#include "Materials/Lambertian.h"

class LambertianSphere: public BaseSphere {
 private:
   const Lambertian m_material;

 public:
   API LambertianSphere(const Point3& center, const double radius, const Pixel& albedo) noexcept;

   [[nodiscard]] API const Lambertian* Hit(const Ray& ray, const Interval& rayT, HitRecord& rec) const noexcept;
};

#endif