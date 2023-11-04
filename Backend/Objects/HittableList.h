#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H
#pragma once
#include "Objects/Sphere/DielectricSphere.h"
#include "Objects/Sphere/LambertianSphere.h"
#include "Objects/Sphere/MetalSphere.h"

class HittableList {
 private:
   std::vector<DielectricSphere> m_dielectricSpheres;
   std::vector<LambertianSphere> m_lambertianSpheres;
   std::vector<MetalSphere> m_metalSpheres;

 public:
   constexpr void Clear() noexcept;
   constexpr void AddDielectricSpehre(const Point3& center, const double radius, const double indexOfRefraction);
   constexpr void AddLambertianSpehre(const Point3& center, const double radius, const Pixel& albedo);
   constexpr void AddMetalSpehre(const Point3& center, const double radius, const Pixel& albedo, const double fuzz);

   [[nodiscard]] constexpr const Material* Hit(const Ray& ray, const Interval& rayT, HitRecord& rec) const noexcept;
};

#include "HittableList.hpp"
#endif