#include <Objects/HittableList.h>
#include <Image/Camera.h>

void Render() {
   HittableList world;
   world.AddLambertianSpehre(LambertianSphere(Point3(0, -1000, 0), 1000, Pixel(0.5, 0.5, 0.5)));

   for(int a = -11; a < 11; ++a) {
      for(int b = -11; b < 11; ++b) {
         const double chooseMat = Utils::Random();
         const Point3 center(a + 0.9 * Utils::Random(), 0.2, b + 0.9 * Utils::Random());

         if((center - Point3(4, 0.2, 0)).Length() > 0.9) {
            if(chooseMat < 0.8) {
               // diffuse
               const Pixel albedo = Pixel::Random() * Pixel::Random();
               world.AddLambertianSpehre(LambertianSphere(center, 0.2, albedo));
            }
            else if(chooseMat < 0.95) {
               // metal
               const Pixel albedo = Pixel::Random(0.5, 1);
               const double fuzz = Utils::Random(0, 0.5);
               world.AddMetalSpehre(MetalSphere(center, 0.2, albedo, fuzz));
            }
            else {
               // glass
               world.AddDielectricSpehre(DielectricSphere(center, 0.2, (1.5)));
            }
         }
      }
   }

   world.AddDielectricSpehre(DielectricSphere(Point3(0, 1, 0), 1.0, 1.5));
   world.AddLambertianSpehre(LambertianSphere(Point3(-4, 1, 0), 1.0, Pixel(0.4, 0.2, 0.1)));
   world.AddMetalSpehre(MetalSphere(Point3(4, 1, 0), 1.0, Pixel(0.7, 0.6, 0.5), 0.0));

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

   // 162 seconds -> 176 seconds -> 179 seconds

   cam.Render(world);
}


int main() {
   try {
      Render();
   }
   catch(const std::exception& e) {
      std::cout << e.what() << '\n';
   }

   return 1;
}