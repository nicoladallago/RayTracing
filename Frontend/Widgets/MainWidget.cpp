#include "MainWidget.h"

API MainWidget::MainWidget(HWND handler) noexcept:
    Widget(WindowHandler(handler)) {
}


API void MainWidget::Draw(const unsigned int width,
                          const unsigned int height) const {
   m_layout.Draw(width, height);
}