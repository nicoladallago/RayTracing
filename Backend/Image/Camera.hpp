#ifndef CAMERA_HPP
#define CAMERA_HPP
#pragma once
#include "Camera.h"

constexpr unsigned int Camera::GetSamplesPerPixels() const noexcept {
   return m_samplesPerPixels;
}


constexpr unsigned int Camera::GetMaxDepth() const noexcept {
   return m_maxDepth;
}


inline Ray Camera::GetRay(const unsigned int i, const unsigned int j) const noexcept {
   const Point3 pixelCenter = m_pixel00Loc + (i * m_pixelDeltaU) + (j * m_pixelDeltaV);
   const Point3 rayOrigin = (m_defocusAngle <= 0) ? m_lookFrom : DefocusDiskSample();

   return Ray(rayOrigin, pixelCenter + PixelSampleSquare() - rayOrigin);
}


constexpr double Camera::LinearToGamma(const double linear) noexcept {
   return Utils::Sqrt(linear);
}


inline Vector3 Camera::PixelSampleSquare() const noexcept {
   const double px = -0.5 + Utils::Random();
   const double py = -0.5 + Utils::Random();
   return (px * m_pixelDeltaU) + (py * m_pixelDeltaV);
}


inline Point3 Camera::DefocusDiskSample() const noexcept {
   // Returns a random point in the camera defocus disk.
   const Point3 p = RandomInUnitDisk();
   return m_lookFrom + (p.GetX() * m_defocusDiskU) + (p.GetY() * m_defocusDiskV);
}


constexpr Pixel Camera::RayBackground(const Ray& ray) noexcept {
   const Vector3 unitDirection = UnitVector(ray.GetDirection());
   const double a = BKG_ATTENUATION * (unitDirection.GetY() + 1);
   return Pixel(1 - BKG_R * a, 1 - BKG_G * a, 1);
}


#endif