#ifndef HIT_RECORD_H
#define HIT_RECORD_H
#pragma once
#include "Geometry/Point3.h"

class Ray;

class HitRecord {
 public:
   Point3 p;
   Vector3 normal;
   double t = 0;
   bool frontFace = false;

 public:
   API void SetFaceFront(const Ray& ray, const Vector3& outwardNormal) noexcept;
};

#endif