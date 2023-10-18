#include "HitRecord.h"
#include "Geometry/Ray.h"

API void HitRecord::SetFaceFront(const Ray& ray, const Vector3& outwardNormal) noexcept {
   frontFace = Dot(ray.GetDirection(), outwardNormal) < 0;
   normal = frontFace ? outwardNormal : -outwardNormal;
}
