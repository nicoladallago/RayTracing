#ifndef CAMERA_H
#define CAMERA_H
#pragma once
#include "Image/Image.h"
#include "Objects/Hittable.h"

class Camera {
 private:
   const double m_aspectRatio;
   const unsigned int m_width;
   unsigned int m_height;  // Rendered image height
   Point3d m_center;       // Camera center
   Point3d m_pixel00Loc;   // Location of pixel 0, 0
   Vector3d m_pixelDeltaU; // Offset to pixel to the right
   Vector3d m_pixelDeltaV; // Offset to pixel below

 public:
   API constexpr Camera(const double aspectRatio, const unsigned int width) noexcept;

   API void Render(const Hittable& world) noexcept; // TODO make it constexpr

 private:
   constexpr void Initialize() noexcept;
   constexpr void RayColor(Image::Pixel& p, const Ray& ray, const Hittable& world) const noexcept;
};

#include "Camera.hpp"
#endif