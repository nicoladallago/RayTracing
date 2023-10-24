#include "BaseSphere.h"
#include "Geometry/Ray.h"
#include "Objects/HitRecord.h"
#include "Utils/Interval.h"

API bool BaseSphere::HitBase(const Ray& ray, const Interval& rayT, HitRecord& rec) const noexcept {
   const Vector3& direction = ray.GetDirection();

   const Vector3 oc = ray.GetOrigin() - m_center;
   const double a = direction.LenghtSquared();
   const double halfB = Dot(oc, direction);
   const double c = oc.LenghtSquared() - m_radiusSquared;
   const double discriminant = halfB * halfB - a * c;
   if(discriminant < 0) {
      return false;
   }

   const double sqrtd = std::sqrt(discriminant);

   // Find the nearest root that lies in the acceptable range.
   double root = (-halfB - sqrtd) / a;
   if(!rayT.Surrounds(root)) {
      root = (-halfB + sqrtd) / a;
      if(!rayT.Surrounds(root)) {
         return false;
      }
   }

   rec.SetRoot(root);
   rec.SetPoint(ray.At(rec.GetRoot()));
   rec.SetFaceFront(ray, (rec.GetPoint() - m_center) / m_radius);
   return true;
}