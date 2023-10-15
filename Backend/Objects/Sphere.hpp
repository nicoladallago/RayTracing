#include "Sphere.h"

API constexpr void Sphere::Color(Image::Pixel& p, const Ray& ray) {
   const double t = Hit(Point3d(0, 0, -1), 0.5, ray);
   if(t > 0) {
      const Vector3d N = UnitVector(ray.At(t) - Vector3d(0, 0, -1));
      p.r = 0.5 * (N.GetX() + 1);
      p.g = 0.5 * (N.GetY() + 1);
      p.b = 0.5 * (N.GetZ() + 1);
      return;
   }

   const Vector3d unitDirection = UnitVector(ray.GetDirection());
   const double a = 0.5 * (unitDirection.GetY() + 1);
   p.r = (1 - a) + 0.5 * a;
   p.g = (1 - a) + 0.7 * a;
   p.b = (1 - a) + a;
}


API constexpr double Sphere::Hit(const Point3d& center, const double radius, const Ray& ray) {
   const Vector3d oc = ray.GetOrigin() - center;
   const double a = ray.GetDirection().LenghtSquared();
   const double halfB = Dot(oc, ray.GetDirection());
   const double c = oc.LenghtSquared() - radius * radius;
   const double discriminant = halfB * halfB - a * c;
   if(discriminant < 0) {
      return -1;
   }
   return (-halfB - std::sqrt(discriminant)) / a;
}