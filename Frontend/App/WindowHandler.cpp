#include "WindowHandler.h"

WindowHandler::WindowHandler(HWND handler) noexcept:
    m_handler(handler) {
}


HWND WindowHandler::GetBase() const noexcept {
   return m_handler;
}