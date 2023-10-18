#include "HittableList.h"
#include "Objects/HitRecord.h"
#include "Utils/Interval.h"

API bool HittableList::Hit(const Ray& ray, const Interval& rayT, HitRecord& rec) const noexcept {
   HitRecord tempRec;
   bool hitAnything = false;
   double closestSoFar = rayT.GetMax();

   for(const std::unique_ptr<Sphere>& upSpehre : m_objects) {
      if(upSpehre->Hit(ray, Interval(rayT.GetMin(), closestSoFar), tempRec)) {
         hitAnything = true;
         closestSoFar = tempRec.t;
         rec = tempRec;
      }
   }

   return hitAnything;
}