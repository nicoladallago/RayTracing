#include "Widget.h"

constexpr void Widget::SetWidth(const unsigned int width) noexcept {
   m_width = width;
}


constexpr void Widget::SetHeight(const unsigned int height) noexcept {
   m_height = height;
}


constexpr const Layout& Widget::GetLayout() const noexcept {
   return m_layout;
}


constexpr Layout& Widget::GetLayout() noexcept {
   return m_layout;
}


constexpr const WindowHandler& Widget::GetHandler() const noexcept {
   return m_handler;
}


constexpr unsigned int Widget::GetWidth() const noexcept {
   return m_width;
}


constexpr unsigned int Widget::GetHeight() const noexcept {
   return m_height;
}