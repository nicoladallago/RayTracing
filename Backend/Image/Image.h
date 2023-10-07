#ifndef IMAGE_H
#define IMAGE_H

class Image {
 private:
   const unsigned int m_width;
   const unsigned int m_height;
   std::vector<unsigned char> m_ptr;

 public:
   inline Image(const unsigned int width, const unsigned int height);

   [[nodiscard]] constexpr unsigned int GetWidth() const noexcept;
   [[nodiscard]] constexpr unsigned int GetHeight() const noexcept;
   [[nodiscard]] constexpr size_t GetSize() const noexcept;

   void Save(const std::filesystem::path& path);
};

#include "Image.hpp"
#endif