#ifndef HITTABLE_LIST_HPP
#define HITTABLE_LIST_HPP
#pragma once
#include "HittableList.h"
#include "Objects/HitRecord.h"
#include "Utils/Interval.h"

API HittableList::HittableList(const std::shared_ptr<Hittable>& spObject) {
   Add(spObject);
}


API constexpr void HittableList::Clear() noexcept {
   m_objects.clear();
}


API constexpr void HittableList::Add(const std::shared_ptr<Hittable>& spObject) {
   m_objects.emplace_back(spObject);
}


API bool HittableList::Hit(const Ray& ray, const Interval& rayT, HitRecord& rec) const noexcept {
   HitRecord tempRec;
   bool hitAnything = false;
   double closestSoFar = rayT.GetMax();

   for(const std::shared_ptr<Hittable>& spObject : m_objects) {
      if(spObject->Hit(ray, Interval(rayT.GetMin(), closestSoFar), tempRec)) {
         hitAnything = true;
         closestSoFar = tempRec.t;
         rec = tempRec;
      }
   }

   return hitAnything;
}

#endif