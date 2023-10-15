#include "Hittable.h"

constexpr void Hittable::HitRecord::SetFaceFront(const Ray& ray, const Vector3d& outwardNormal) noexcept {
   frontFace = Dot(ray.GetDirection(), outwardNormal) < 0;
   normal = frontFace ? outwardNormal : -outwardNormal;
}