#ifndef CAMERA_H
#define CAMERA_H
#pragma once
#include "Geometry/Ray.h"

class HittableList;

class Camera {
 private:
   const double m_aspectRatio;
   const unsigned int m_width;
   const unsigned int m_samplesPerPixels;
   const unsigned int m_maxDepth;
   const double m_vfov;
   const Point3 m_lookFrom;
   const Point3 m_lookAt;
   const Vector3 m_vup;
   const double m_defocusAngle;
   const double m_focusDist;

   unsigned int m_height;   // Rendered image height
   Point3 m_center;        // Camera center
   Point3 m_pixel00Loc;    // Location of pixel 0, 0
   Vector3 m_pixelDeltaU;  // Offset to pixel to the right
   Vector3 m_pixelDeltaV;  // Offset to pixel below
   Vector3 m_u, m_v, m_w;  // Camera frame basis vectors
   Vector3 m_defocusDiskU; // Defocus disk horizontal radius
   Vector3 m_defocusDiskV; // Defocus disk vertical radius

 public:
   API Camera(const double aspectRatio,
              const unsigned int width,
              const unsigned int samplesPerPixels,
              const unsigned int maxDepth,
              const double vfov,
              const Point3& lookFrom,
              const Point3& lookAt,
              const Vector3& vup,
              const double defocusAngle,
              const double focusDist) noexcept;

   API void Render(const HittableList& world) noexcept; // TODO make it constexpr

   [[nodiscard]] API constexpr unsigned int GetSamplesPerPixels() const noexcept;
   [[nodiscard]] API constexpr unsigned int GetMaxDepth() const noexcept;

   [[nodiscard]] API Ray GetRay(const unsigned int i, const unsigned int j) const noexcept;

   [[nodiscard]] API static Pixel RayColor(const Ray& ray, const unsigned int depth, const HittableList& world) noexcept;
   [[nodiscard]] API static double LinearToGamma(const double linear) noexcept;

 private:
   void Initialize() noexcept;
   Vector3 PixelSampleSquare() const noexcept; // TODO constexpr
   Point3 DefocusDiskSample() const;
};

#include "Camera.hpp"
#endif