#ifndef IMAGE_HPP
#define IMAGE_HPP
#pragma once
#include "Image.h"

constexpr Image::Image(const int width, const int height) noexcept:
    m_width(static_cast<size_t>(width)),
    m_height(static_cast<size_t>(height)),
    m_data(std::vector<Pixel>(m_width * m_height)) {
}


constexpr size_t Image::GetWidth() const noexcept {
   return m_width;
}


constexpr size_t Image::GetHeight() const noexcept {
   return m_height;
}


constexpr size_t Image::GetSize() const noexcept {
   return m_data.size();
}


constexpr std::vector<Pixel>& Image::Get() noexcept {
   return m_data;
}

#endif