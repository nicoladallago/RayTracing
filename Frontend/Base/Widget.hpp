#include "Widget.h"

constexpr const Layout& Widget::GetLayout() const noexcept {
   return m_layout;
}


constexpr Layout& Widget::GetLayout() noexcept {
   return m_layout;
}


constexpr HWND Widget::GetBase() const noexcept {
   return m_hwnd;
}