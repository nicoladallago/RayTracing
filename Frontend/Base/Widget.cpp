#include "Widget.h"

Widget::Widget(const Widget& parent) noexcept:
    Widget(parent.GetHandler()) {
}


Widget::Widget(const WindowHandler& handler) noexcept:
    m_handler(handler) {
}
