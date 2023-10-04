#include "App/Application.h"
#include "App/GraphicsHandler.h"
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
      PAINTSTRUCT paint{};
      HDC hdc = BeginPaint(hwnd, &paint);

      // All painting occurs here, between BeginPaint and EndPaint.
      FillRect(hdc, &paint.rcPaint, CreateSolidBrush(COLOR_WINDOW_BKG.ToPlatform()));

      m_upMainWidget->Draw(GraphicsHandler(hdc),
                           static_cast<unsigned int>(paint.rcPaint.right - paint.rcPaint.left),
                           static_cast<unsigned int>(paint.rcPaint.top - paint.rcPaint.bottom));

      EndPaint(hwnd, &paint);
      return 0;
   }

   return DefWindowProc(hwnd, uMsg, wParam, lParam);
}


void CreateMainLayout() {
   m_upMainWidget = std::make_unique<MainWidget>();

   Layout& layout = m_upMainWidget->GetLayout();
   layout.AddWidget(0, 0, new Button("text"));
}


int WINAPI wWinMain(_In_ HINSTANCE hInstance,
                    [[maybe_unused]] _In_opt_ HINSTANCE hPrevInstance,
                    [[maybe_unused]] _In_ LPWSTR lpCmdLine,
                    _In_ int nShowCmd) {
   const char* name = "Ray Tracing";

   // Register the window class
   WNDCLASS wnd{};
   wnd.lpfnWndProc = WindowProc;
   wnd.hInstance = hInstance;
   wnd.lpszClassName = name;
   RegisterClass(&wnd);

   // Create the window
   HWND hwnd = CreateWindowEx(0,
                              name,
                              name,
                              WS_OVERLAPPEDWINDOW,
                              CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
                              nullptr,
                              nullptr,
                              hInstance,
                              nullptr);
   if(hwnd == nullptr) {
      return 0;
   }

   CreateMainLayout();
   ShowWindow(hwnd, nShowCmd);

   // Run the message loop
   MSG msg{};
   while(GetMessage(&msg, nullptr, 0, 0) > 0) {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
   }

   return 0;
}