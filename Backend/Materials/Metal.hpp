#ifndef METAL_HPP
#define METAL_HPP
#pragma once
#include "Metal.h"
#include "Geometry/Ray.h"
#include "Objects/HitRecord.h"

constexpr Metal::Metal(const Pixel& a, const double f) noexcept:
    m_albedo(a),
    m_fuzz(f) {
}


inline bool Metal::Scatter(const Ray& ray,
                           const HitRecord& rec,
                           Pixel& attenuation,
                           Ray& scattered) const noexcept {
   const Vector3 reflected = Reflect(UnitVector(ray.GetDirection()), rec.GetNormal());
   scattered = Ray(rec.GetPoint(), reflected + m_fuzz * RandomUnitVector());
   attenuation = m_albedo;
   return (Dot(scattered.GetDirection(), rec.GetNormal()) > 0);
}

#endif