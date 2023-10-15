#ifndef IMAGE_H
#define IMAGE_H
#pragma once

class Image {
 public:
   struct Pixel
   {
      double r = 0;
      double g = 0;
      double b = 0;
   };

 private:
   const unsigned int m_width;
   const unsigned int m_height;
   std::vector<Pixel> m_data;

 public:
   API Image(const unsigned int width, const unsigned int height);

   [[nodiscard]] API constexpr unsigned int GetWidth() const noexcept;
   [[nodiscard]] API constexpr unsigned int GetHeight() const noexcept;
   [[nodiscard]] API constexpr size_t GetSize() const noexcept;
   [[nodiscard]] API constexpr std::span<Pixel> Get() noexcept;

   API void Save(const std::filesystem::path& path);
};

#include "Image.hpp"
#endif