#include "HittableList.h"
#include "Objects/HitRecord.h"
#include "Utils/Interval.h"

API std::pair<bool, const Material*> HittableList::Hit(const Ray& ray, const Interval& rayT, HitRecord& rec) const noexcept {
   HitRecord tempRec;
   bool hitAnything = false;
   const Material* pMaterial = nullptr;
   double closestSoFar = rayT.GetMax();

   for(const DielectricSphere& sphere : m_dielectricSpheres) {
      if(const Material* pMat = sphere.Hit(ray, Interval(rayT.GetMin(), closestSoFar), tempRec); pMat != nullptr) {
         hitAnything = true;
         pMaterial = pMat;
         closestSoFar = tempRec.GetRoot();
         rec = tempRec;
      }
   }
   for(const LambertianSphere& sphere : m_lambertianSpheres) {
      if(const Material* pMat = sphere.Hit(ray, Interval(rayT.GetMin(), closestSoFar), tempRec); pMat != nullptr) {
         hitAnything = true;
         pMaterial = pMat;
         closestSoFar = tempRec.GetRoot();
         rec = tempRec;
      }
   }
   for(const MetalSphere& sphere : m_metalSpheres) {
      if(const Material* pMat = sphere.Hit(ray, Interval(rayT.GetMin(), closestSoFar), tempRec); pMat != nullptr) {
         hitAnything = true;
         pMaterial = pMat;
         closestSoFar = tempRec.GetRoot();
         rec = tempRec;
      }
   }

   return std::make_pair(hitAnything, pMaterial);
}