#ifndef HITTABLE_LIST_HPP
#define HITTABLE_LIST_HPP
#pragma once
#include "HittableList.h"
#include "Materials/Dielectric.h"
#include "Materials/Lambertian.h"
#include "Materials/Metal.h"

constexpr void HittableList::Clear() noexcept {
   m_spheres.clear();
}


constexpr void HittableList::AddDielectricSpehre(const Point3& center, const double radius, const double indexOfRefraction) {
   m_spheres.emplace_back(Sphere(center, radius, new Dielectric(indexOfRefraction)));
}


constexpr void HittableList::AddLambertianSpehre(const Point3& center, const double radius, const Pixel& albedo) {
   m_spheres.emplace_back(Sphere(center, radius, new Lambertian(albedo)));
}


constexpr void HittableList::AddMetalSpehre(const Point3& center, const double radius, const Pixel& albedo, const double fuzz) {
   m_spheres.emplace_back(Sphere(center, radius, new Metal(albedo, fuzz)));
}


constexpr const Material* HittableList::Hit(const Ray& ray, const Interval& rayT, HitRecord& rec) const noexcept {
   HitRecord tempRec;
   const Material* pMaterial = nullptr;
   double closestSoFar = rayT.GetMax();

   for(const Sphere& sphere : m_spheres) {
      if(sphere.Hit(ray, Interval(rayT.GetMin(), closestSoFar), tempRec)) {
         pMaterial = &sphere.GetMaterial();
         closestSoFar = tempRec.GetRoot();
         rec = tempRec;
      }
   }

   return pMaterial;
}

#endif