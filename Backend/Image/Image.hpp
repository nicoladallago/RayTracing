#ifndef IMAGE_HPP
#define IMAGE_HPP
#pragma once
#include "Image.h"

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