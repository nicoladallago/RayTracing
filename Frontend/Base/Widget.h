#ifndef WIDGET_H
#define WIDGET_H
#pragma once
#include "Layout.h"

class GraphicsHandler;

class Widget {
 protected:
   Layout m_layout;
   unsigned int m_width = 0;
   unsigned int m_height = 0;

 public:
   virtual ~Widget() noexcept = default;

   constexpr void SetWidth(const unsigned int width) noexcept;
   constexpr void SetHeight(const unsigned int height) noexcept;

   [[nodiscard]] constexpr const Layout& GetLayout() const noexcept;
   [[nodiscard]] constexpr Layout& GetLayout() noexcept;
   [[nodiscard]] constexpr unsigned int GetWidth() const noexcept;
   [[nodiscard]] constexpr unsigned int GetHeight() const noexcept;

   virtual void Draw(const GraphicsHandler& handler,
                     const unsigned int x,
                     const unsigned int y) const = 0;
};

#include "Widget.hpp"
#endif