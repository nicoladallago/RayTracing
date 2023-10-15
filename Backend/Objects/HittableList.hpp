#include "HittableList.h"

API HittableList::HittableList(const std::shared_ptr<Hittable>& spObject) {
   Add(spObject);
}


API constexpr void HittableList::Clear() noexcept {
   m_objects.clear();
}


API constexpr void HittableList::Add(const std::shared_ptr<Hittable>& spObject) {
   m_objects.emplace_back(spObject);
}


API constexpr bool HittableList::Hit(const Ray& ray, const double rayMin, const double rayMax, HitRecord& rec) const noexcept {
   HitRecord tempRec;
   bool hitAnything = false;
   auto closestSoFar = rayMax;

   for(const std::shared_ptr<Hittable>& spObject : m_objects) {
      if(spObject->Hit(ray, rayMin, closestSoFar, tempRec)) {
         hitAnything = true;
         closestSoFar = tempRec.t;
         rec = tempRec;
      }
   }

   return hitAnything;
}