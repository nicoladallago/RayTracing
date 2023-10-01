#ifndef WIDGET_H
#define WIDGET_H
#pragma once
#include "Layout.h"

class Widget {
 private:
   HWND m_hwnd = nullptr;

   Layout m_layout;

 public:
   explicit Widget(Widget& parent) noexcept;
   virtual ~Widget() noexcept = default;

   [[nodiscard]] constexpr const Layout& GetLayout() const noexcept;
   [[nodiscard]] constexpr Layout& GetLayout() noexcept;

   [[nodiscard]] constexpr HWND GetBase() const noexcept;

 protected:
   virtual void Draw(const unsigned int x,
                     const unsigned int y) const = 0;
};

#include "Widget.hpp"
#endif