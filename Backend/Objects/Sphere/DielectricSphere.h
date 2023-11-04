#ifndef DIELECTRIC_SPHERE_H
#define DIELECTRIC_SPHERE_H
#pragma once
#include "Objects/Sphere/BaseSphere.h"
#include "Materials/Dielectric.h"

class DielectricSphere: public BaseSphere {
 private:
   const Dielectric m_material;

 public:
   API constexpr DielectricSphere(const Point3& center, const double radius, const double indexOfRefraction) noexcept;

   [[nodiscard]] API constexpr const Dielectric* Hit(const Ray& ray, const Interval& rayT, HitRecord& rec) const noexcept;
};

#include "DielectricSphere.hpp"
#endif