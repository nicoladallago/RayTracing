#include "MainWidget.h"

API void MainWidget::Draw(const WindowHandler& handler,
                          const unsigned int width,
                          const unsigned int height) const {
   m_layout.Draw(handler, width, height);
}