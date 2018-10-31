#include <iostream>
#include "Bitmap.hpp"

// define an alias for the namespace
namespace bmp = mybitmapnamespace;

int main() {
  int const WIDTH = 800;
  int const HEIGHT = 600;

  bmp::Bitmap bitmap(WIDTH, HEIGHT);

  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      bitmap.setPixel(x, y, 255, 0, 0);
    }
  }

  bitmap.write("test.bmp");

  std::cout << "WIDTH is " << WIDTH << " and HEIGHT is " << HEIGHT << std::endl;
  return 0;
}