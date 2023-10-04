#ifndef GRAPHICS_HANDLER_H
#define GRAPHICS_HANDLER_H
#pragma once

class GraphicsHandler {
 private:
   HDC m_handler;

 public:
   API explicit inline GraphicsHandler(HDC handler) noexcept;

   [[nodiscard]] inline HDC GetBase() const noexcept;
};

#include "GraphicsHandler.hpp"
#endif