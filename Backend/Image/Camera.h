#ifndef CAMERA_H
#define CAMERA_H
#pragma once
#include "Geometry/Ray.h"
#include "Image/Image.h"
#include "Utils/Interval.h"

class HittableList;

class Camera {
 private:
   static constexpr Interval INTERVAL = Interval(0.001, std::numeric_limits<double>::max());
   static constexpr double BKG_ATTENUATION = 0.5;
   static constexpr double BKG_R = 0.5;
   static constexpr double BKG_G = 0.5;
   //static constexpr double BKG_B = 0;

   const double m_aspectRatio;
   const int m_width;
   const int m_samplesPerPixels;
   const int m_maxDepth;
   const double m_vfov;
   const Point3 m_lookFrom;
   const Point3 m_lookAt;
   const Vector3 m_vup;
   const double m_defocusAngle;
   const double m_focusDist;

   int m_height;           // Rendered image height
   Point3 m_pixel00Loc;    // Location of pixel 0, 0
   Vector3 m_pixelDeltaU;  // Offset to pixel to the right
   Vector3 m_pixelDeltaV;  // Offset to pixel below
   Vector3 m_u, m_v, m_w;  // Camera frame basis vectors
   Vector3 m_defocusDiskU; // Defocus disk horizontal radius
   Vector3 m_defocusDiskV; // Defocus disk vertical radius

 public:
   API constexpr Camera(const double aspectRatio,
                        const int width,
                        const int samplesPerPixels,
                        const int maxDepth,
                        const double vfov,
                        const Point3& lookFrom,
                        const Point3& lookAt,
                        const Vector3& vup,
                        const double defocusAngle,
                        const double focusDist) noexcept;

   [[nodiscard]] API Image Render(const HittableList& world) noexcept; // TODO make it constexpr

   [[nodiscard]] constexpr int GetSamplesPerPixels() const noexcept;
   [[nodiscard]] constexpr int GetMaxDepth() const noexcept;

   [[nodiscard]] inline Ray GetRay(const int i, const int j) const noexcept;

   [[nodiscard]] static inline Pixel RayColor(const Ray& ray,
                                              const int depth,
                                              const HittableList& world) noexcept;
   static constexpr void LinearToGamma(Pixel& pixel) noexcept;

 private:
   constexpr void Initialize() noexcept;

   inline Vector3 PixelSampleSquare() const noexcept; // TODO constexpr
   inline Point3 DefocusDiskSample() const noexcept;

   static constexpr Pixel RayBackground(const Ray& ray) noexcept;
   static constexpr double LinearToGamma(const double linear) noexcept;
};

#include "Camera.hpp"
#endif