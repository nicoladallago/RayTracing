#ifndef METAL_H
#define METAL_H
#pragma once
#include "Materials/Material.h"
#include "Image/Image.h"

class Metal: public Material {
 private:
   const Image::Pixel m_albedo;

 public:
   API constexpr Metal(const Image::Pixel& a) noexcept;

   [[nodiscard]] API virtual constexpr bool Scatter(const Ray& ray,
                                                    const Hittable::HitRecord& rec,
                                                    Image::Pixel& attenuation,
                                                    Ray& scattered) const noexcept override final;
};

#include "Metal.hpp"
#endif