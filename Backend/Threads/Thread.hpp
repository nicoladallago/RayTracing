#ifndef THREAD_HPP
#define THREAD_HPP
#pragma once
#include "Thread.h"
#include "Image/Camera.h"
#include "Objects/HittableList.h"

API constexpr Thread::Data::Data(Pixel& p, const unsigned int i, const unsigned int j) noexcept:
    m_p(p),
    m_i(i),
    m_j(j) {
}


API constexpr size_t Thread::GetId() const noexcept {
   return m_id;
}

#endif