#include "HittableList.h"
#include "Objects/HitRecord.h"
#include "Utils/Interval.h"

API std::pair<bool, Material*> HittableList::Hit(const Ray& ray, const Interval& rayT, HitRecord& rec) const noexcept {
   HitRecord tempRec;
   bool hitAnything = false;
   Material* pMaterial = nullptr;
   double closestSoFar = rayT.GetMax();

   for(const std::unique_ptr<Sphere>& upSpehre : m_objects) {
      if(const std::pair<bool, Material*> hit = upSpehre->Hit(ray, Interval(rayT.GetMin(), closestSoFar), tempRec); hit.first) {
         hitAnything = true;
         pMaterial = hit.second;
         closestSoFar = tempRec.GetRoot();
         rec = tempRec;
      }
   }

   return std::make_pair(hitAnything, pMaterial);
}