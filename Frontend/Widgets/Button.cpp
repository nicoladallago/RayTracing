#include "Button.h"
#include "Color/DefaultColors.h"
#include "Draw/Draw2.h"

API Button::Button():
    Button("") {
}


API Button::Button(const char* text):
    m_text(text) {
   m_width = DEFAULT_WIDTH;   // TODO adjust according to text width
   m_height = DEFAULT_HEIGHT; // TODO adjust according to text height
}


void Button::Draw(const GraphicsHandler& handler,
                  const unsigned int x,
                  const unsigned int y) const {
   const Rectui rect(x, y, m_width, m_height);

   Draw2::Rectangle(handler, rect, COLOR_BUTTON_BKG);
   Draw2::Text(handler, rect, COLOR_TEXT, m_text);
}