//#include "App/Application.h"
//#include "App/GraphicsHandler.h"
//#include "Color/DefaultColors.h"
//#include "Widgets/MainWidget.h"
//#include "Widgets/Button.h"

#include <Image/Image.h>
#include <Geometry/Point3.h>
#include <Geometry/Ray.h>
#include <Objects/HittableList.h>
#include <Objects/Sphere.h>
#include <Utils/Interval.h>
#include <Image/Camera.h>
#include <Materials/Lambertian.h>
#include <Materials/Metal.h>

void Render() {
   // World
   HittableList world;
   std::shared_ptr<Lambertian> matGround = std::make_shared<Lambertian>(Image::Pixel(0.8, 0.8, 0));
   std::shared_ptr<Lambertian> matCenter = std::make_shared<Lambertian>(Image::Pixel(0.7, 0.3, 0.3));
   std::shared_ptr<Metal> matLeft = std::make_shared<Metal>(Image::Pixel(0.8, 0.8, 0.8), 0.3);
   std::shared_ptr<Metal> matRight = std::make_shared<Metal>(Image::Pixel(0.8, 0.6, 0.2), 1);

   world.Add(std::make_shared<Sphere>(Point3d(0.0, -100.5, -1.0), 100.0, matGround));
   world.Add(std::make_shared<Sphere>(Point3d(0.0, 0.0, -1.0), 0.5, matCenter));
   world.Add(std::make_shared<Sphere>(Point3d(-1.0, 0.0, -1.0), 0.5, matLeft));
   world.Add(std::make_shared<Sphere>(Point3d(1.0, 0.0, -1.0), 0.5, matRight));

   Camera cam(16.0 / 9.0, // Aspect ratio
              400,        // Width
              100,        // Samples per pixel
              50);        // Maximum depth
   cam.Render(world);
}

int main() {
   Render();

   return 1;
}


//std::unique_ptr<MainWidget> m_upMainWidget = nullptr;
//
//LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
//   if(uMsg == WM_DESTROY) {
//      PostQuitMessage(0);
//      return 0;
//   }
//   if(uMsg == WM_PAINT) {
//      PAINTSTRUCT paint{};
//      HDC hdc = BeginPaint(hwnd, &paint);
//
//      // All painting occurs here, between BeginPaint and EndPaint.
//      FillRect(hdc, &paint.rcPaint, CreateSolidBrush(COLOR_WINDOW_BKG.ToPlatform()));
//
//      m_upMainWidget->Draw(GraphicsHandler(hdc),
//                           static_cast<unsigned int>(paint.rcPaint.right - paint.rcPaint.left),
//                           static_cast<unsigned int>(paint.rcPaint.top - paint.rcPaint.bottom));
//
//      EndPaint(hwnd, &paint);
//      return 0;
//   }
//
//   return DefWindowProc(hwnd, uMsg, wParam, lParam);
//}
//
//
//void CreateMainLayout() {
//   m_upMainWidget = std::make_unique<MainWidget>();
//
//   Layout& layout = m_upMainWidget->GetLayout();
//   layout.AddWidget(0, 0, new Button("text"));
//}
//
//
//int WINAPI wWinMain(_In_ HINSTANCE hInstance,
//                    [[maybe_unused]] _In_opt_ HINSTANCE hPrevInstance,
//                    [[maybe_unused]] _In_ LPWSTR lpCmdLine,
//                    _In_ int nShowCmd) {
//   const char* name = "Ray Tracing";
//
//   // Register the window class
//   WNDCLASS wnd{};
//   wnd.lpfnWndProc = WindowProc;
//   wnd.hInstance = hInstance;
//   wnd.lpszClassName = name;
//   RegisterClass(&wnd);
//
//   // Create the window
//   HWND hwnd = CreateWindowEx(0,
//                              name,
//                              name,
//                              WS_OVERLAPPEDWINDOW,
//                              CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
//                              nullptr,
//                              nullptr,
//                              hInstance,
//                              nullptr);
//   if(hwnd == nullptr) {
//      return 0;
//   }
//
//   CreateMainLayout();
//   ShowWindow(hwnd, nShowCmd);
//
//   // test print image
//   Render();
//
//   // Run the message loop
//   MSG msg{};
//   while(GetMessage(&msg, nullptr, 0, 0) > 0) {
//      TranslateMessage(&msg);
//      DispatchMessage(&msg);
//   }
//
//   return 0;
//}