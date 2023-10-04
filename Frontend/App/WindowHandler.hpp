#include "WindowHandler.h"

inline HWND WindowHandler::GetBase() const noexcept {
   return m_handle;
}