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
#include <Materials/Dielectric.h>

void Render() {
   // World
   HittableList world;

   const std::shared_ptr<Lambertian> material_ground = std::make_shared<Lambertian>(Image::Pixel(0.8, 0.8, 0));
   const std::shared_ptr<Lambertian> material_center = std::make_shared<Lambertian>(Image::Pixel(0.1, 0.2, 0.5));
   const std::shared_ptr<Dielectric> material_left = std::make_shared<Dielectric>(1.5);
   const std::shared_ptr<Metal> material_right = std::make_shared<Metal>(Image::Pixel(0.8, 0.6, 0.2), 0);

   world.Add(std::make_shared<Sphere>(Point3d(0.0, -100.5, -1.0), 100.0, material_ground));
   world.Add(std::make_shared<Sphere>(Point3d(0.0, 0.0, -1.0), 0.5, material_center));
   world.Add(std::make_shared<Sphere>(Point3d(-1.0, 0.0, -1.0), 0.5, material_left));
   world.Add(std::make_shared<Sphere>(Point3d(-1.0, 0.0, -1.0), -0.4, material_left));
   world.Add(std::make_shared<Sphere>(Point3d(1.0, 0.0, -1.0), 0.5, material_right));

   Camera cam(16.0 / 9.0,         // Aspect ratio
              400,                // Width
              100,                // Samples per pixel
              50,                 // Maximum depth
              90,                 // Vertical view angle (field of view)
              Point3d(-2, 2, 1),  // Point camera is looking from
              Point3d(0, 0, -1),  // Point camera is looking at
              Vector3d(0, 1, 0)); // Camera-relative "up" direction
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