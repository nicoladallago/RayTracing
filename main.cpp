#include <Objects/HittableList.h>
#include <Objects/Sphere.h>
#include <Image/Camera.h>
#include <Materials/Lambertian.h>
#include <Materials/Metal.h>
#include <Materials/Dielectric.h>

void Render() {
   HittableList world;
   world.Add(std::make_shared<Sphere>(Point3d(0, -1000, 0), 1000, std::make_unique<Lambertian>(Pixel(0.5, 0.5, 0.5))));

   for(int a = -11; a < 11; ++a) {
      for(int b = -11; b < 11; ++b) {
         const double chooseMat = Utils::Random();
         const Point3d center(a + 0.9 * Utils::Random(), 0.2, b + 0.9 * Utils::Random());

         if((center - Point3d(4, 0.2, 0)).Length() > 0.9) {
            if(chooseMat < 0.8) {
               // diffuse
               const Pixel albedo = Pixel::Random() * Pixel::Random();
               world.Add(std::make_shared<Sphere>(center, 0.2, std::make_unique<Lambertian>(albedo)));
            }
            else if(chooseMat < 0.95) {
               // metal
               const Pixel albedo = Pixel::Random(0.5, 1);
               const double fuzz = Utils::Random(0, 0.5);
               world.Add(std::make_shared<Sphere>(center, 0.2, std::make_unique<Metal>(albedo, fuzz)));
            }
            else {
               // glass
               world.Add(std::make_shared<Sphere>(center, 0.2, std::make_unique<Dielectric>(1.5)));
            }
         }
      }
   }

   world.Add(std::make_shared<Sphere>(Point3d(0, 1, 0), 1.0, std::make_unique<Dielectric>(1.5)));
   world.Add(std::make_shared<Sphere>(Point3d(-4, 1, 0), 1.0, std::make_unique<Lambertian>(Pixel(0.4, 0.2, 0.1))));
   world.Add(std::make_shared<Sphere>(Point3d(4, 1, 0), 1.0, std::make_unique<Metal>(Pixel(0.7, 0.6, 0.5), 0.0)));

   Camera cam(16.0 / 9.0,        // Aspect ratio
              2560,              // Width
              500,               // Samples per pixel
              50,                // Maximum depth
              20,                // Vertical view angle (field of view)
              Point3d(13, 2, 3), // Point camera is looking from
              Point3d(0, 0, 0),  // Point camera is looking at
              Vector3d(0, 1, 0), // Camera-relative "up" direction
              0.6,               // Defocus disk horizontal radius
              10);               // Defocus disk vertical radius
   cam.Render(world);
}


int main() {
   Render();

   return 1;
}