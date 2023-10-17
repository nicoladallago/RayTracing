#ifndef CAMERA_HPP
#define CAMERA_HPP
#pragma once
#include "Camera.h"

API constexpr unsigned int Camera::GetSamplesPerPixels() const noexcept {
   return m_samplesPerPixels;
}


API constexpr unsigned int Camera::GetMaxDepth() const noexcept {
   return m_maxDepth;
}

#endif