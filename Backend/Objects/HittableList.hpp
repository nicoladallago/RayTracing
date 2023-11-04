#ifndef HITTABLE_LIST_HPP
#define HITTABLE_LIST_HPP
#pragma once
#include "HittableList.h"

constexpr void HittableList::Clear() noexcept {
   m_dielectricSpheres.clear();
   m_lambertianSpheres.clear();
   m_metalSpheres.clear();
}


constexpr void HittableList::AddDielectricSpehre(const Point3& center, const double radius, const double indexOfRefraction) {
   m_dielectricSpheres.emplace_back(center, radius, indexOfRefraction);
}


constexpr void HittableList::AddLambertianSpehre(const Point3& center, const double radius, const Pixel& albedo) {
   m_lambertianSpheres.emplace_back(center, radius, albedo);
}


constexpr void HittableList::AddMetalSpehre(const Point3& center, const double radius, const Pixel& albedo, const double fuzz) {
   m_metalSpheres.emplace_back(center, radius, albedo, fuzz);
}


constexpr const Material* HittableList::Hit(const Ray& ray, const Interval& rayT, HitRecord& rec) const noexcept {
   HitRecord tempRec;
   const Material* pMaterial = nullptr;
   double closestSoFar = rayT.GetMax();

   for(const DielectricSphere& sphere : m_dielectricSpheres) {
      if(const Material* pMat = sphere.Hit(ray, Interval(rayT.GetMin(), closestSoFar), tempRec); pMat != nullptr) {
         pMaterial = pMat;
         closestSoFar = tempRec.GetRoot();
         rec = tempRec;
      }
   }
   for(const LambertianSphere& sphere : m_lambertianSpheres) {
      if(const Material* pMat = sphere.Hit(ray, Interval(rayT.GetMin(), closestSoFar), tempRec); pMat != nullptr) {
         pMaterial = pMat;
         closestSoFar = tempRec.GetRoot();
         rec = tempRec;
      }
   }
   for(const MetalSphere& sphere : m_metalSpheres) {
      if(const Material* pMat = sphere.Hit(ray, Interval(rayT.GetMin(), closestSoFar), tempRec); pMat != nullptr) {
         pMaterial = pMat;
         closestSoFar = tempRec.GetRoot();
         rec = tempRec;
      }
   }

   return pMaterial;
}

#endif