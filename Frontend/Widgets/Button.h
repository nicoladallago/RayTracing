#ifndef BUTTON_H
#define BUTTON_H
#pragma once
#include "Base/Widget.h"
#include "Color/DefaultColors.h"

class Button: public Widget {
 private:
   std::string m_text;
   Color m_color = COLOR_BUTTON_BKG;

   Layout::VAlignement m_vTxtAlignement = Layout::VAlignement::Center;
   Layout::HAlignement m_hTxtAlignement = Layout::HAlignement::Center;

 public:
   API Button();
   API explicit Button(const std::string& text);

   constexpr void SetText(const std::string& text);
   constexpr void SetVTextAlignement(const Layout::VAlignement& align) noexcept;
   constexpr void SetHTextAlignement(const Layout::HAlignement& align) noexcept;

 protected:
   virtual void Draw(const WindowHandler& handler,
                     const unsigned int x,
                     const unsigned int y) const override final;
};

#include "Button.hpp"
#endif