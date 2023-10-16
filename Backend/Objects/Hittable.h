#ifndef HITTABLE_H
#define HITTABLE_H
#pragma once
#include "Geometry/Point3.h"

class Ray;
class Interval;
class HitRecord;

class Hittable {
 public:
   API virtual ~Hittable() = default;

   [[nodiscard]] API virtual bool Hit(const Ray& ray, const Interval& rayT, HitRecord& rec) const noexcept = 0;
};

#endif