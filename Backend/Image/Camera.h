#ifndef CAMERA_H
#define CAMERA_H
#pragma once
#include "Image/Image.h"

class Hittable;

class Camera {
 private:
   const double m_aspectRatio;
   const unsigned int m_width;
   const unsigned int m_samplesPerPixels;
   const unsigned int m_maxDepth;
   const double m_vfov;
   const Point3d m_lookFrom;
   const Point3d m_lookAt;
   const Vector3d m_vup;
   const double m_defocusAngle;
   const double m_focusDist;

   unsigned int m_height;   // Rendered image height
   Point3d m_center;        // Camera center
   Point3d m_pixel00Loc;    // Location of pixel 0, 0
   Vector3d m_pixelDeltaU;  // Offset to pixel to the right
   Vector3d m_pixelDeltaV;  // Offset to pixel below
   Vector3d m_u, m_v, m_w;  // Camera frame basis vectors
   Vector3d m_defocusDiskU; // Defocus disk horizontal radius
   Vector3d m_defocusDiskV; // Defocus disk vertical radius

 public:
   API Camera(const double aspectRatio,
              const unsigned int width,
              const unsigned int samplesPerPixels,
              const unsigned int maxDepth,
              const double vfov,
              const Point3d& lookFrom,
              const Point3d& lookAt,
              const Vector3d& vup,
              const double defocusAngle,
              const double focusDist) noexcept;

   API void Render(const Hittable& world) noexcept; // TODO make it constexpr

 private:
   void Initialize() noexcept;
   constexpr Ray GetRay(const unsigned int i, const unsigned int j) const noexcept;
   Vector3d PixelSampleSquare() const noexcept; // TODO constexpr
   Point3d DefocusDiskSample() const;

   static constexpr Image::Pixel RayColor(const Ray& ray,
                                          const unsigned int depth,
                                          const Hittable& world) noexcept;
   static double LinearToGamma(const double linear) noexcept;
};

#include "Camera.hpp"
#endif