#ifndef WINDOW_HANDLER_H
#define WINDOW_HANDLER_H
#pragma once

class WindowHandler {
 private:
   HWND m_handler;

 public:
   explicit WindowHandler(HWND handler) noexcept;

   [[nodiscard]] HWND GetBase() const noexcept;
};

#endif