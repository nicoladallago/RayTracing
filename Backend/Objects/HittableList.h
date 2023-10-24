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
   constexpr void AddDielectricSpehre(const DielectricSphere& sphere);
   constexpr void AddLambertianSpehre(const LambertianSphere& sphere);
   constexpr void AddMetalSpehre(const MetalSphere& sphere);

   [[nodiscard]] const Material* Hit(const Ray& ray, const Interval& rayT, HitRecord& rec) const noexcept;
};

#include "HittableList.hpp"
#endif