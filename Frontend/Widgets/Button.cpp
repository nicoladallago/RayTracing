#include "Button.h"
#include "Draw/Draw2.h"

Button::Button(Widget& parent):
    Widget(parent) {
}


Button::Button(const std::string& text, Widget& parent):
    Widget(parent),
    m_text(text) {
}


void Button::Draw(const unsigned int x, const unsigned int y) const {
   Draw2::Rectangle(GetBase(), Rect<unsigned int>(x, y, m_width, m_height), m_color);
}