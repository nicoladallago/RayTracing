#include "Widget.h"

Widget::Widget(Widget& parent) noexcept:
    m_hwnd(parent.GetBase()) {
}
