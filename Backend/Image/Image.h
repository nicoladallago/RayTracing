#ifndef IMAGE_H
#define IMAGE_H
#pragma once
#include "Geometry/Point3.h"

class Image {
 private:
   const size_t m_width;
   const size_t m_height;
   std::vector<Pixel> m_data;

 public:
   constexpr Image(const int width, const int height) noexcept;

   [[nodiscard]] constexpr size_t GetWidth() const noexcept;
   [[nodiscard]] constexpr size_t GetHeight() const noexcept;
   [[nodiscard]] constexpr size_t GetSize() const noexcept;
   [[nodiscard]] constexpr std::vector<Pixel>& Get() noexcept;

   API void Save(const std::filesystem::path& path) const;
};

#include "Image.hpp"
#endif