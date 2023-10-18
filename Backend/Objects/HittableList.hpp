#ifndef HITTABLE_LIST_HPP
#define HITTABLE_LIST_HPP
#pragma once
#include "HittableList.h"
#include "Objects/HitRecord.h"
#include "Utils/Interval.h"

API constexpr void HittableList::Clear() noexcept {
   m_objects.clear();
}


API constexpr void HittableList::Add(std::unique_ptr<Hittable> upObject) {
   m_objects.emplace_back(std::move(upObject));
}


API bool HittableList::Hit(const Ray& ray, const Interval& rayT, HitRecord& rec) const noexcept {
   HitRecord tempRec;
   bool hitAnything = false;
   double closestSoFar = rayT.GetMax();

   for(const std::unique_ptr<Hittable>& upObject : m_objects) {
      if(upObject->Hit(ray, Interval(rayT.GetMin(), closestSoFar), tempRec)) {
         hitAnything = true;
         closestSoFar = tempRec.t;
         rec = tempRec;
      }
   }

   return hitAnything;
}

#endif