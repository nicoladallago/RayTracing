#ifndef THREAD_HPP
#define THREAD_HPP
#pragma once
#include "Thread.h"
#include "Image/Camera.h"
#include "Objects/HittableList.h"

API constexpr Thread::Data::Data(Pixel& p, const int i, const int j) noexcept:
    m_p(p),
    m_i(i),
    m_j(j) {
}


API constexpr void Thread::Add(Pixel& pixel, const int i, const int j) {
   m_pixels.emplace_back(pixel, i, j);
}


API constexpr size_t Thread::GetId() const noexcept {
   return m_id;
}


API constexpr bool Thread::RenderDone() const noexcept {
   return m_pixels.empty();
}


API constexpr size_t Thread::ItemsRemaining() const noexcept {
   return m_pixels.size();
}


inline void Thread::Render() noexcept {
   while(!m_pixels.empty()) {
      Data& data = m_pixels.back();
      RenderPixel(data.m_p, data.m_i, data.m_j);
      m_pixels.pop_back();
   }
}


inline void Thread::RenderPixel(Pixel& p, const int i, const int j) const noexcept {
   for(int sample = 0; sample < m_samplesPerPixel; ++sample) {
      p += Camera::RayColor(m_camera.GetRay(i, j), m_maxDepth, m_world);
   }
   p /= m_samplesPerPixel;

   Camera::LinearToGamma(p);

   p.SetX(MAX_PIXEL_VAL * CLAMP.Clamp(p.GetX()));
   p.SetY(MAX_PIXEL_VAL * CLAMP.Clamp(p.GetY()));
   p.SetZ(MAX_PIXEL_VAL * CLAMP.Clamp(p.GetZ()));
}


#endif