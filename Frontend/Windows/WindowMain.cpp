#include "WindowMain.h"

WindowMain::WindowMain():
    Fl_Window(WIDTH, HEIGHT, "Ray Tracing") {
   Fl_Box* pBox = new Fl_Box(0, 0, WIDTH, HEIGHT, "Rendering");

   pBox->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
   pBox->labelfont(pBox->labelfont() | FL_BOLD | FL_ITALIC);
   pBox->labelsize(36);
   pBox->labelcolor(fl_rgb_color(0x00, 0x80, 0x00));
   pBox->labeltype(FL_SHADOW_LABEL);

   resizable(this);
   position((Fl::w() - w()) / 2, (Fl::h() - h()) / 2);
}


void WindowMain::show() {
   Fl_Window::show();

   // TODO do it in a separe thread maybe
   try {
      Render();
   }
   catch(const std::exception& e) {
      std::cout << e.what() << '\n';
   }
}


void WindowMain::Render() {
   std::cout << "Creating scene..\n";
   HittableList world;
   world.AddLambertianSpehre(Point3(0, -1000, 0), 1000, Pixel(0.5, 0.5, 0.5));

   for(int a = -11; a < 11; ++a) {
      for(int b = -11; b < 11; ++b) {
         const double chooseMat = Utils::Random();
         const Point3 center(a + 0.9 * Utils::Random(), 0.2, b + 0.9 * Utils::Random());

         if((center - Point3(4, 0.2, 0)).Length() > 0.9) {
            if(chooseMat < 0.8) {
               // diffuse
               const Pixel albedo = Pixel::Random() * Pixel::Random();
               world.AddLambertianSpehre(center, 0.2, albedo);
            }
            else if(chooseMat < 0.95) {
               // metal
               const Pixel albedo = Pixel::Random(0.5, 1);
               const double fuzz = Utils::Random(0, 0.5);
               world.AddMetalSpehre(center, 0.2, albedo, fuzz);
            }
            else {
               // glass
               world.AddDielectricSpehre(center, 0.2, 1.5);
            }
         }
      }
   }

   world.AddDielectricSpehre(Point3(0, 1, 0), 1, 1.5);
   world.AddLambertianSpehre(Point3(-4, 1, 0), 1, Pixel(0.4, 0.2, 0.1));
   world.AddMetalSpehre(Point3(4, 1, 0), 1, Pixel(0.7, 0.6, 0.5), 0);

   Camera cam(16.0 / 9.0,       // Aspect ratio
              2560,             // Width
              32,               // Samples per pixel (500)
              8,                // Maximum depth (50)
              20,               // Vertical view angle (field of view)
              Point3(13, 2, 3), // Point camera is looking from
              Point3(0, 0, 0),  // Point camera is looking at
              Vector3(0, 1, 0), // Camera-relative "up" direction
              0.6,              // Defocus disk horizontal radius
              10);              // Defocus disk vertical radius

   // 162 -> 176 -> 179 -> 182 -> 178 -> 190 -> 136 -> 124 -> 105 -> 90 seconds

   std::cout << "Redering scene..\n";
   const Image img = cam.Render(world);
   std::cout << "Saving image..\n";
   img.Save("image.ppm");
}