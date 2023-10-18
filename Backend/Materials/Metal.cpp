#include "Metal.h"
#include "Geometry/Ray.h"
#include "Objects/HitRecord.h"

API bool Metal::Scatter(const Ray& ray,
                        const HitRecord& rec,
                        Pixel& attenuation,
                        Ray& scattered) const noexcept {
   const Vector3 reflected = Reflect(UnitVector(ray.GetDirection()), rec.GetNormal());
   scattered = Ray(rec.GetPoint(), reflected + m_fuzz * RandomUnitVector());
   attenuation = m_albedo;
   return (Dot(scattered.GetDirection(), rec.GetNormal()) > 0);
}