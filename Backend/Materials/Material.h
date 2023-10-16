#ifndef MATERIAL_H
#define MATERIAL_H
#pragma once

class Material {
 public:
   API virtual ~Material() = default;

   [[nodiscard]] API virtual bool Scatter(const Ray& ray, const HitRecord& rec, Image::Pixel& attenuation, Ray& scattered) const noexcept = 0;
};


#endif