#ifndef LAYOUT_H
#define LAYOUT_H
#pragma once
class Widget;
class WindowHandler;

class Layout {
 public:
   enum class VAlignement
   {
      Top,
      Bottom,
      Center
   };

   enum class HAlignement
   {
      Left,
      Right,
      Center
   };

 private:
   struct Data
   {
      std::unique_ptr<Widget> m_upWidget = nullptr;
      VAlignement m_vAlignement = VAlignement::Center;
      HAlignement m_hAlignement = HAlignement::Center;
   };

 private:
   std::map<Point2<unsigned int>, Data> m_widgets;

   unsigned int m_borderMargin = 4;
   unsigned int m_innerMargin = 4;

 public:
   constexpr void SetBorderMargin(unsigned int margin) noexcept;
   constexpr void SetInnerMargin(unsigned int margin) noexcept;

   API void AddWidget(const unsigned int row,
                      const unsigned int col,
                      Widget* pWidget,
                      const VAlignement vAlignement = VAlignement::Center,
                      const HAlignement hAlignement = HAlignement::Center);

   [[nodiscard]] bool IsPreset(const unsigned int row, const unsigned int col) const;

   [[nodiscard]] const Widget& GetWidget(const unsigned int row, const unsigned int col) const;
   [[nodiscard]] Widget& GetWidget(const unsigned int row, const unsigned int col);

   void Draw(const WindowHandler& handler,
             const unsigned int width,
             const unsigned int height) const;
};

#include "Layout.hpp"
#endif