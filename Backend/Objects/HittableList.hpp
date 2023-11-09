#ifndef HITTABLE_LIST_HPP
#define HITTABLE_LIST_HPP
#pragma once
#include "HittableList.h"
#include "Objects/Sphere/DielectricSphere.h"
#include "Objects/Sphere/LambertianSphere.h"
#include "Objects/Sphere/MetalSphere.h"

constexpr void HittableList::Clear() noexcept {
   m_spheres.clear();
}


constexpr void HittableList::AddDielectricSpehre(const Point3& center, const double radius, const double indexOfRefraction) {
   m_spheres.emplace_back(std::make_unique<DielectricSphere>(center, radius, indexOfRefraction));
}


constexpr void HittableList::AddLambertianSpehre(const Point3& center, const double radius, const Pixel& albedo) {
   m_spheres.emplace_back(std::make_unique<LambertianSphere>(center, radius, albedo));
}


constexpr void HittableList::AddMetalSpehre(const Point3& center, const double radius, const Pixel& albedo, const double fuzz) {
   m_spheres.emplace_back(std::make_unique<MetalSphere>(center, radius, albedo, fuzz));
}


constexpr const Material* HittableList::Hit(const Ray& ray, const Interval& rayT, HitRecord& rec) const noexcept {
   HitRecord tempRec;
   const Material* pMaterial = nullptr;
   double closestSoFar = rayT.GetMax();

   for(const std::unique_ptr<Sphere>& upSphere : m_spheres) {
      if(upSphere->Hit(ray, Interval(rayT.GetMin(), closestSoFar), tempRec)) {
         pMaterial = &upSphere->GetMaterial();
         closestSoFar = tempRec.GetRoot();
         rec = tempRec;
      }
   }

   return pMaterial;
}

#endif