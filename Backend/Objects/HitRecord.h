#ifndef HIT_RECORD_H
#define HIT_RECORD_H
#pragma once
#include "Geometry/Point3.h"

class Ray;
class Material;

class HitRecord {
 public:
   Point3d p;
   Vector3d normal;
   std::shared_ptr<Material> mat = nullptr;
   double t = 0;
   bool frontFace = false;

 public:
   API void SetFaceFront(const Ray& ray, const Vector3d& outwardNormal) noexcept;
};

#endif