#ifndef HIT_RECORD_HPP
#define HIT_RECORD_HPP
#pragma once
#include "HitRecord.h"
#include "Geometry/Ray.h"

API void HitRecord::SetFaceFront(const Ray& ray, const Vector3d& outwardNormal) noexcept {
   frontFace = Dot(ray.GetDirection(), outwardNormal) < 0;
   normal = frontFace ? outwardNormal : -outwardNormal;
}

#endif