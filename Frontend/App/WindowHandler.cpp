#include "WindowHandler.h"

WindowHandler::WindowHandler(const char* name, HINSTANCE hInstance) noexcept:
    m_handle(CreateWindowEx(0,
                            name,
                            name,
                            WS_OVERLAPPEDWINDOW,
                            CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
                            nullptr,
                            nullptr,
                            hInstance,
                            nullptr)) {
}
