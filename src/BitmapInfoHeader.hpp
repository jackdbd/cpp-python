#ifndef BITMAPINFOHEADER_H_
#define BITMAPINFOHEADER_H_

#include <cstdint>

namespace mybitmapnamespace {

#pragma pack(push, 2)

/**
 * Bitmap info header.
 *
 * This block of bytes tells the application detailed information about the
 * image, which will be used to display the image on the screen.
 * https://msdn.microsoft.com/en-us/library/Dd183376(v=VS.85).aspx
 * https://en.wikipedia.org/wiki/BMP_file_format#DIB_header_(bitmap_information_header)
 */
struct BitmapInfoHeader {
  std::int32_t headerSize{40};
  std::int32_t width;
  std::int32_t height;
  std::int16_t planes{1};
  std::int16_t bitsPerPixel{24};
  std::int32_t compression{0};
  std::int32_t dataSize{0};
  std::int32_t horizontalResolution{2400};
  std::int32_t verticalResolution{2400};
  std::int32_t colors{0};
  std::int32_t importantColors{0};
};

#pragma pack(pop)

}  // namespace mybitmapnamespace

#endif