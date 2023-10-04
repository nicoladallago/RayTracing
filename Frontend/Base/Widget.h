#ifndef WIDGET_H
#define WIDGET_H
#pragma once
#include "Layout.h"
#include "App/WindowHandler.h"

class Widget {
 private:
   const WindowHandler m_handler;

 protected:
   Layout m_layout;
   unsigned int m_width = 0;
   unsigned int m_height = 0;

 public:
   explicit Widget(const Widget& parent) noexcept;
   virtual ~Widget() noexcept = default;

   constexpr void SetWidth(const unsigned int width) noexcept;
   constexpr void SetHeight(const unsigned int height) noexcept;

   [[nodiscard]] constexpr const Layout& GetLayout() const noexcept;
   [[nodiscard]] constexpr Layout& GetLayout() noexcept;
   [[nodiscard]] constexpr const WindowHandler& GetHandler() const noexcept;
   [[nodiscard]] constexpr unsigned int GetWidth() const noexcept;
   [[nodiscard]] constexpr unsigned int GetHeight() const noexcept;

   virtual void Draw(const unsigned int x,
                     const unsigned int y) const = 0;

 protected:
   explicit Widget(const WindowHandler& handler) noexcept;
};

#include "Widget.hpp"
#endif