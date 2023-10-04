#include "Button.h"

constexpr void Button::SetText(const char* text) {
   m_text = text;
}


constexpr void Button::SetVTextAlignement(const Layout::VAlignement& align) noexcept {
   m_vTxtAlignement = align;
}


constexpr void Button::SetHTextAlignement(const Layout::HAlignement& align) noexcept {
   m_hTxtAlignement = align;
}