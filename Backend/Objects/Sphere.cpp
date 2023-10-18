#include "Sphere.h"
#include "Geometry/Ray.h"
#include "Objects/HitRecord.h"
#include "Utils/Interval.h"

API Sphere::Sphere(const Point3& center, const double radius, std::unique_ptr<Material> upMaterial):
    m_center(center),
    m_radius(radius),
    m_radiusSquared(m_radius * m_radius),
    m_upMaterial(std::move(upMaterial)) {
}


API std::pair<bool, Material*> Sphere::Hit(const Ray& ray, const Interval& rayT, HitRecord& rec) const noexcept {
   const Vector3& direction = ray.GetDirection();

   const Vector3 oc = ray.GetOrigin() - m_center;
   const double a = direction.LenghtSquared();
   const double halfB = Dot(oc, direction);
   const double c = oc.LenghtSquared() - m_radiusSquared;
   const double discriminant = halfB * halfB - a * c;
   if(discriminant < 0) {
      return std::make_pair(false, nullptr);
   }

   const double sqrtd = std::sqrt(discriminant);

   // Find the nearest root that lies in the acceptable range.
   double root = (-halfB - sqrtd) / a;
   if(!rayT.Surrounds(root)) {
      root = (-halfB + sqrtd) / a;
      if(!rayT.Surrounds(root)) {
         return std::make_pair(false, nullptr);
      }
   }

   rec.t = root;
   rec.p = ray.At(rec.t);
   const Vector3 outwardNormal = (rec.p - m_center) / m_radius;
   rec.SetFaceFront(ray, outwardNormal);

   return std::make_pair(true, m_upMaterial.get());
}