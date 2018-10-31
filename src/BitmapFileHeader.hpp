#ifndef BITMAPFILEHEADER_H_
#define BITMAPFILEHEADER_H_

#include <cstdint>

namespace mybitmapnamespace {

#pragma pack(push, 2)

/**
 * Bitmap file header.
 *
 * The Bitmap file header is a block of bytes at the start of the file and it
 * is used to identify the file.
 * http://www.daubnet.com/en/file-format-bmp
 * https://en.wikipedia.org/wiki/BMP_file_format#Bitmap_file_header
 *
 */
struct BitmapFileHeader {
  char header[2]{'B', 'M'};
  std::int32_t fileSize;
  std::int32_t reserved{0};
  std::int32_t dataOffset;
};

#pragma pack(pop)

}  // namespace mybitmapnamespace

#endif
