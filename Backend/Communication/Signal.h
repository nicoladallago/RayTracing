#ifndef SIGNAL_H
#define SIGNAL_H
#pragma once
#include "SignalBase.h"

template<class T>
class Signal: public SignalBase {
 private:
   T m_data;

 public:
   explicit Signal(T&& data) noexcept;

   [[nodiscard]] T& Get() noexcept;
   [[nodiscard]] const T& Get() const noexcept;
};

#include "Signal.hpp"
#endif
