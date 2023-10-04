#include "App/Application.h"
#include "App/WindowHandler.h"
#include "Color/DefaultColors.h"
#include "Widgets/MainWidget.h"
#include "Widgets/Button.h"

std::unique_ptr<MainWidget> m_upMainWidget = nullptr;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
   if(uMsg == WM_DESTROY) {
      PostQuitMessage(0);
      return 0;
   }
   if(uMsg == WM_PAINT) {
      PAINTSTRUCT ps{};
      const HDC hdc = BeginPaint(hwnd, &ps);

      // All painting occurs here, between BeginPaint and EndPaint.
      const COLORREF color = RGB(COLOR_WINDOW_BKG.GetRed(), COLOR_WINDOW_BKG.GetGreen(), COLOR_WINDOW_BKG.GetBlue());
      const HBRUSH brush = CreateSolidBrush(color);
      FillRect(hdc, &ps.rcPaint, brush);

      m_upMainWidget->Draw(WindowHandler(hdc),
                           ps.rcPaint.right - ps.rcPaint.left,
                           ps.rcPaint.top - ps.rcPaint.bottom);

      EndPaint(hwnd, &ps);
      return 0;
   }

   return DefWindowProc(hwnd, uMsg, wParam, lParam);
}


void CreateMainLayout() {
   m_upMainWidget = std::make_unique<MainWidget>();

   Layout& layout = m_upMainWidget->GetLayout();
   layout.AddWidget(0, 0, new Button("text"));
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

   CreateMainLayout();
   ShowWindow(hwnd, nCmdShow);

   // Run the message loop
   MSG msg{};
   while(GetMessage(&msg, NULL, 0, 0) > 0) {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
   }

   return 0;
}