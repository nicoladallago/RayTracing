#ifndef IMAGE_HPP
#define IMAGE_HPP
#pragma once
#include "Image.h"

constexpr Image::Image(const unsigned int width, const unsigned int height) noexcept:
    m_width(width),
    m_height(height),
    m_data(std::vector<Pixel>(width * height)) {
}


constexpr unsigned int Image::GetWidth() const noexcept {
   return m_width;
}


constexpr unsigned int Image::GetHeight() const noexcept {
   return m_height;
}


constexpr size_t Image::GetSize() const noexcept {
   return m_data.size();
}


constexpr std::span<Pixel> Image::Get() noexcept {
   return m_data;
}

#endif