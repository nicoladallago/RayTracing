#ifndef IMAGE_HPP
#define IMAGE_HPP
#pragma once
#include "Image.h"

API Image::Image(const unsigned int width, const unsigned int height):
    m_width(width),
    m_height(height),
    m_data(std::vector<Pixel>(width * height)) {
}


API constexpr unsigned int Image::GetWidth() const noexcept {
   return m_width;
}


API constexpr unsigned int Image::GetHeight() const noexcept {
   return m_height;
}


API constexpr size_t Image::GetSize() const noexcept {
   return m_data.size();
}


API constexpr std::span<Image::Pixel> Image::Get() noexcept {
   return m_data;
}

#endif