#include "HitRecord.h"
#include "Geometry/Ray.h"

API void HitRecord::SetFaceFront(const Ray& ray, const Vector3& outwardNormal) noexcept {
   m_frontFace = Dot(ray.GetDirection(), outwardNormal) < 0;
   m_normal = m_frontFace ? outwardNormal : -outwardNormal;
}
