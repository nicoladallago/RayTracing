#ifndef CAMERA_HPP
#define CAMERA_HPP
#pragma once
#include "Camera.h"

constexpr unsigned int Camera::GetSamplesPerPixels() const noexcept {
   return m_samplesPerPixels;
}


constexpr unsigned int Camera::GetMaxDepth() const noexcept {
   return m_maxDepth;
}

#endif