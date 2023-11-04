#ifndef LAMBERTIAN_SPHERE_HPP
#define LAMBERTIAN_SPHERE_HPP
#pragma once
#include "LambertianSphere.h"

API constexpr LambertianSphere::LambertianSphere(const Point3& center, const double radius, const Pixel& albedo) noexcept:
    BaseSphere(center, radius),
    m_material(albedo) {
}


API constexpr const Lambertian* LambertianSphere::Hit(const Ray& ray, const Interval& rayT, HitRecord& rec) const noexcept {
   return (BaseSphere::HitBase(ray, rayT, rec) ? &m_material : nullptr);
}

#endif