#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H
#pragma once
#include "Materials/Material.h"
#include "Image/Image.h"

class Lambertian: public Material {
 private:
   const Image::Pixel m_albedo;

 public:
   API constexpr Lambertian(const Image::Pixel& a) noexcept;

   [[nodiscard]] API virtual bool Scatter(const Ray& ray,
                                          const HitRecord& rec,
                                          Image::Pixel& attenuation,
                                          Ray& scattered) const noexcept override final;
};

#include "Lambertian.hpp"
#endif