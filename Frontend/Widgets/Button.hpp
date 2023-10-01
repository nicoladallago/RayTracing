#include "Button.h"

constexpr void Button::SetWidth(const unsigned int width) noexcept {
   m_width = width;
}


constexpr void Button::SetHeight(const unsigned int height) noexcept {
   m_height = height;
}


constexpr void Button::SetText(const std::string& text) {
   m_text = text;
}


constexpr void Button::SetVTextAlignement(const Layout::VAlignement& align) noexcept {
   m_vTxtAlignement = align;
}


constexpr void Button::SetHTextAlignement(const Layout::HAlignement& align) noexcept {
   m_hTxtAlignement = align;
}