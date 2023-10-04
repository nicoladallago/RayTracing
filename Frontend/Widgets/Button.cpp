#include "Button.h"
#include "Draw/Draw2.h"

API Button::Button(Widget& parent):
    Button(std::string(), parent) {
}


API Button::Button(const std::string& text, Widget& parent):
    Widget(parent),
    m_text(text) {
   m_width = 80;  // TODO adjust according to text width
   m_height = 24; // TODO adjust according to text height
}


void Button::Draw(const unsigned int x, const unsigned int y) const {
   const Rect<unsigned int> rect(x, y, m_width, m_height);

   Draw2::Rectangle(GetHandler(), rect, m_color);
   Draw2::Text(GetHandler(), rect, m_text);
}