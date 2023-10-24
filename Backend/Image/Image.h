#ifndef IMAGE_H
#define IMAGE_H
#pragma once
#include "Geometry/Point3.h"

class Image {
 private:
   const unsigned int m_width;
   const unsigned int m_height;
   std::vector<Pixel> m_data;

 public:
   Image(const unsigned int width, const unsigned int height);

   [[nodiscard]] constexpr unsigned int GetWidth() const noexcept;
   [[nodiscard]] constexpr unsigned int GetHeight() const noexcept;
   [[nodiscard]] constexpr size_t GetSize() const noexcept;
   [[nodiscard]] constexpr std::span<Pixel> Get() noexcept;

   void Save(const std::filesystem::path& path);
};

#include "Image.hpp"
#endif