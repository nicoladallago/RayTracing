#include "Button.h"
#include "Draw/Draw2.h"

API Button::Button():
    Button(std::string()) {
}


API Button::Button(const std::string& text):
    m_text(text) {
   m_width = 80;  // TODO adjust according to text width
   m_height = 24; // TODO adjust according to text height
}


void Button::Draw(const WindowHandler& handler,
                  const unsigned int x,
                  const unsigned int y) const {
   const Rect<unsigned int> rect(x, y, m_width, m_height);

   Draw2::Rectangle(handler, rect, m_color);
   Draw2::Text(handler, rect, m_text);
}