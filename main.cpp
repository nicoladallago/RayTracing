#include "App/Application.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
   if(uMsg == WM_DESTROY) {
      PostQuitMessage(0);
      return 0;
   }
   if(uMsg == WM_PAINT) {
      PAINTSTRUCT ps{};
      const HDC hdc = BeginPaint(hwnd, &ps);

      // All painting occurs here, between BeginPaint and EndPaint.
      FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
      EndPaint(hwnd, &ps);
      return 0;
   }

   return DefWindowProc(hwnd, uMsg, wParam, lParam);
}


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR, int nCmdShow) {
   const std::string name = "Ray Tracing";

   // Register the window class
   WNDCLASS wc{};
   wc.lpfnWndProc = WindowProc;
   wc.hInstance = hInstance;
   wc.lpszClassName = name.c_str();
   RegisterClass(&wc);

   // Create the window
   const HWND hwnd = CreateWindowEx(0,
                                    name.c_str(),
                                    name.c_str(),
                                    WS_OVERLAPPEDWINDOW,
                                    CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
                                    NULL,
                                    NULL,
                                    hInstance,
                                    NULL);
   if(hwnd == NULL) {
      return 0;
   }
   ShowWindow(hwnd, nCmdShow);

   Application::Init();

   // Run the message loop
   MSG msg{};
   while(GetMessage(&msg, NULL, 0, 0) > 0) {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
   }

   return 0;
}