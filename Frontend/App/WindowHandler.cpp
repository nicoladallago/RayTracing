#include "WindowHandler.h"

API WindowHandler::WindowHandler(HDC handler) noexcept:
    m_handler(handler) {
}


HDC WindowHandler::GetBase() const noexcept {
   return m_handler;
}