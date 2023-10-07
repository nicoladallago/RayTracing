#ifndef SIGNAL_H
#define SIGNAL_H
#pragma once
#include "SignalBase.h"

template<class T>
class Signal: public SignalBase {
 private:
   T m_data;

 public:
   constexpr explicit Signal(T&& data) noexcept;

   [[nodiscard]] constexpr T& Get() noexcept;
   [[nodiscard]] constexpr const T& Get() const noexcept;
};

#include "Signal.hpp"
#endif
