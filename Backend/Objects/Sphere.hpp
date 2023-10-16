#include "Sphere.h"

API constexpr Sphere::Sphere(const Point3d& center, const double radius):
    m_center(center),
    m_radius(radius) {
}


API constexpr bool Sphere::Hit(const Ray& ray, const Interval& rayT, HitRecord& rec) const noexcept {
   const Vector3d oc = ray.GetOrigin() - m_center;
   const double a = ray.GetDirection().LenghtSquared();
   const double halfB = Dot(oc, ray.GetDirection());
   const double c = oc.LenghtSquared() - m_radius * m_radius;
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

   rec.t = root;
   rec.p = ray.At(rec.t);
   const Vector3d outwardNormal = (rec.p - m_center) / m_radius;
   rec.SetFaceFront(ray, outwardNormal);

   return true;
}