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

void RayColor(Image::Pixel& p, const Ray& ray, const Hittable& world) {
   Hittable::HitRecord rec;
   if(world.Hit(ray, 0, std::numeric_limits<double>::max(), rec)) {
      p.r = 0.5 * (rec.normal.GetX() + 1);
      p.g = 0.5 * (rec.normal.GetY() + 1);
      p.b = 0.5 * (rec.normal.GetZ() + 1);
      return;
   }

   const Vector3d unitDirection = UnitVector(ray.GetDirection());
   const double a = 0.5 * (unitDirection.GetY() + 1);

   p.r = (1 - a) + 0.5 * a;
   p.g = (1 - a) + 0.7 * a;
   p.b = (1 - a) + 1 * a;
}


void Render() {
   const double aspectRatio = 16.0 / 9.0;
   const unsigned int width = 400;
   const unsigned int height = static_cast<unsigned int>(width / aspectRatio);

   // World
   HittableList world;
   world.Add(std::make_shared<Sphere>(Point3d(0, 0, -1), 0.5));
   world.Add(std::make_shared<Sphere>(Point3d(0, -100.5, -1), 100));

   const double focalLenght = 1;
   const double viewportHeight = 2;
   const double viewportWidth = viewportHeight * static_cast<double>(width) / height;
   const Point3d cameraCenter(0, 0, 0);

   const Vector3d viewportU(viewportWidth, 0, 0);
   const Vector3d viewportV(0, -viewportHeight, 0);

   const Vector3d pixelDeltaU = viewportU / static_cast<double>(width);
   const Vector3d pixelDeltaV = viewportV / static_cast<double>(height);

   const Point3d viewportUpperLeft = cameraCenter - Vector3d(0, 0, focalLenght) - viewportU / 2.0 - viewportV / 2.0;
   const Point3d pixell00Loc = viewportUpperLeft + 0.5 * (pixelDeltaU + pixelDeltaV);

   // Render
   Image img(width, height);
   std::span<Image::Pixel> pixels = img.Get();

   for(unsigned int j = 0; j < height; ++j) {
      unsigned int offset = j * width;
      for(unsigned int i = 0; i < width; ++i) {
         const Point3d pixelCenter = pixell00Loc + (static_cast<double>(i) * pixelDeltaU) + (static_cast<double>(j) * pixelDeltaV);
         const Vector3d rayDirection = pixelCenter - cameraCenter;
         const Ray ray(cameraCenter, rayDirection);

         Image::Pixel& p = pixels[offset + i];
         RayColor(p, ray, world);
      }
      std::cout << "Progress " << std::to_string(j * 100.0 / height) << '%' << '\n';
   }
   img.Save("image.ppm");
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