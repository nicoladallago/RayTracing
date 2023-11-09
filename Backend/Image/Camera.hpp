#ifndef CAMERA_HPP
#define CAMERA_HPP
#pragma once
#include "Camera.h"

API constexpr Camera::Camera(const double aspectRatio,
                             const unsigned int width,
                             const unsigned int samplesPerPixels,
                             const unsigned int maxDepth,
                             const double vfov,
                             const Point3& lookFrom,
                             const Point3& lookAt,
                             const Vector3& vup,
                             const double defocusAngle,
                             const double focusDist) noexcept:
    m_aspectRatio(aspectRatio),
    m_width(width),
    m_samplesPerPixels(samplesPerPixels),
    m_maxDepth(maxDepth),
    m_vfov(vfov),
    m_lookFrom(lookFrom),
    m_lookAt(lookAt),
    m_vup(vup),
    m_defocusAngle(defocusAngle),
    m_focusDist(focusDist) {
   Initialize();
}


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


constexpr void Camera::Initialize() noexcept {
   m_height = static_cast<unsigned int>(m_width / m_aspectRatio);

   const double theta = Utils::DegreesToRadians(m_vfov);
   const double h = Utils::Tan(theta / 2);
   const double viewportHeight = 2 * h * m_focusDist;
   const double viewportWidth = viewportHeight * static_cast<double>(m_width) / m_height;

   // Calculate the u,v,w unit basis vectors for the camera coordinate frame.
   m_w = UnitVector(m_lookFrom - m_lookAt);
   m_u = UnitVector(Cross(m_vup, m_w));
   m_v = Cross(m_w, m_u);

   const Vector3 viewportU = viewportWidth * m_u;
   const Vector3 viewportV = viewportHeight * -m_v;

   m_pixelDeltaU = viewportU / static_cast<double>(m_width);
   m_pixelDeltaV = viewportV / static_cast<double>(m_height);

   const Point3 viewportUpperLeft = m_lookFrom - (m_focusDist * m_w) - viewportU / 2 - viewportV / 2;
   m_pixel00Loc = viewportUpperLeft + 0.5 * (m_pixelDeltaU + m_pixelDeltaV);

   // Calculate the camera defocus disk basis vectors.
   const double defocusRadius = m_focusDist * Utils::Tan(Utils::DegreesToRadians(m_defocusAngle / 2));
   m_defocusDiskU = m_u * defocusRadius;
   m_defocusDiskV = m_v * defocusRadius;
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