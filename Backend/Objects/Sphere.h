#ifndef SPHERE_H
#define SPHERE_H
#pragma once
#include "Geometry/Point3.h"
#include "Geometry/Ray.h"
#include "Image/Image.h"

class Sphere {
 public:
   [[nodiscard]] API static constexpr void Color(Image::Pixel& p, const Ray& ray);

 private:
   API static constexpr double Hit(const Point3d& center, const double radius, const Ray& ray);
};

#include "Sphere.hpp"
#endif