#ifndef WINDOW_HANDLER_H
#define WINDOW_HANDLER_H
#pragma once

class WindowHandler {
 private:
   HDC m_handler;

 public:
   API explicit WindowHandler(HDC handler) noexcept;

   [[nodiscard]] HDC GetBase() const noexcept;
};

#endif