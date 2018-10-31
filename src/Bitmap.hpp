#ifndef BITMAP_H_
#define BITMAP_H_

#include <cstdint>
#include <memory>
#include <string>

namespace mybitmapnamespace {

class Bitmap {
 private:
  int m_width{0};
  int m_height{0};
  std::unique_ptr<std::uint8_t[]> m_pPixels{nullptr};

 public:
  Bitmap(int width, int height);
  void setPixel(int x, int y, std::uint8_t red, std::uint8_t green,
                std::uint8_t blue);
  bool write(std::string filename);
  virtual ~Bitmap();
};

}  // namespace mybitmapnamespace

#endif