#ifndef WINDOW_HANDLER_H
#define WINDOW_HANDLER_H
#pragma once

class WindowHandler {
 private:
   HWND m_handle = nullptr;

 public:
   explicit WindowHandler(const char* name,
                          HINSTANCE hInstance) noexcept;

   [[nodiscard]] inline HWND GetBase() const noexcept;
};

#include "WindowHandler.hpp"
#endif