#ifndef SIGNAL_HPP
#define SIGNAL_HPP
#pragma once
#include "Signal.h"

template<class T>
constexpr Signal<T>::Signal(T&& data) noexcept:
    m_data(std::move(data)) {
}


template<class T>
constexpr T& Signal<T>::Get() noexcept {
   return m_data;
}


template<class T>
constexpr const T& Signal<T>::Get() const noexcept {
   return m_data;
}

#endif