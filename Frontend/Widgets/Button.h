#ifndef BUTTON_H
#define BUTTON_H
#pragma once
#include "Base/Widget.h"

class Button: public Widget {
 private:
   static constexpr unsigned int DEFAULT_WIDTH = 80;
   static constexpr unsigned int DEFAULT_HEIGHT = 24;

   std::string m_text;
   Layout::VAlignement m_vTxtAlignement = Layout::VAlignement::Center;
   Layout::HAlignement m_hTxtAlignement = Layout::HAlignement::Center;

 public:
   API Button();
   API explicit Button(const std::string& text);

   constexpr void SetText(const std::string& text);
   constexpr void SetVTextAlignement(const Layout::VAlignement& align) noexcept;
   constexpr void SetHTextAlignement(const Layout::HAlignement& align) noexcept;

 protected:
   virtual void Draw(const GraphicsHandler& handler,
                     const unsigned int x,
                     const unsigned int y) const override final;
};

#include "Button.hpp"
#endif