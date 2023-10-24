#ifndef METAL_SPHERE_H
#define METAL_SPHERE_H
#pragma once
#include "Objects/BaseSphere.h"
#include "Materials/Metal.h"

class MetalSphere: public BaseSphere {
 private:
   const Metal m_material;

 public:
   API MetalSphere(const Point3& center, const double radius, const Pixel& albedo, const double fuzz) noexcept;

   [[nodiscard]] API const Metal* Hit(const Ray& ray, const Interval& rayT, HitRecord& rec) const noexcept;
};

#endif