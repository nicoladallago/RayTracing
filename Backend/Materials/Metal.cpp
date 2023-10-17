#include "Metal.h"
#include "Geometry/Ray.h"
#include "Objects/HitRecord.h"

API bool Metal::Scatter(const Ray& ray,
                        const HitRecord& rec,
                        Pixel& attenuation,
                        Ray& scattered) const noexcept {
   const Vector3d reflected = Reflect(UnitVector(ray.GetDirection()), rec.normal);
   scattered = Ray(rec.p, reflected + m_fuzz * RandomUnitVector<double>());
   attenuation = m_albedo;
   return (Dot(scattered.GetDirection(), rec.normal) > 0);
}