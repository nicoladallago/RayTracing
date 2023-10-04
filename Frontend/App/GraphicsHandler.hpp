#include "GraphicsHandler.h"

API inline GraphicsHandler::GraphicsHandler(HDC handler) noexcept:
    m_handler(handler) {
}


HDC inline GraphicsHandler::GetBase() const noexcept {
   return m_handler;
}