#include "Image.h"

Image::Image(const unsigned int width, const unsigned int height):
    m_width(width),
    m_height(height),
    m_ptr(std::vector<unsigned char>(width * height)) {
}


constexpr unsigned int Image::GetWidth() const noexcept {
   return m_width;
}


constexpr unsigned int Image::GetHeight() const noexcept {
   return m_height;
}


constexpr size_t Image::GetSize() const noexcept {
   return m_ptr.size();
}


void Image::Save(const std::filesystem::path& path) {
   std::ofstream file(path);
}