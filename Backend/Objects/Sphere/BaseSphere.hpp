#ifndef BASE_SPHERE_HPP
#define BASE_SPHERE_HPP
#pragma once
#include "BaseSphere.h"
#include "Geometry/Ray.h"
#include "Objects/HitRecord.h"
#include "Utils/Interval.h"

API constexpr BaseSphere::BaseSphere(const Point3& center, const double radius) noexcept:
    m_center(center),
    m_radius(radius),
    m_radiusSquared(radius * radius) {
}


API constexpr bool BaseSphere::HitBase(const Ray& ray, const Interval& rayT, HitRecord& rec) const noexcept {
   const Vector3& direction = ray.GetDirection();

   const Vector3 oc = ray.GetOrigin() - m_center;
   const double a = direction.LenghtSquared();
   const double halfB = Dot(oc, direction);
   const double c = oc.LenghtSquared() - m_radiusSquared;
   const double discriminant = halfB * halfB - a * c;
   if(discriminant < 0) {
      return false;
   }

   const double sqrtd = Utils::Sqrt(discriminant);

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

#endif