#include "Bitmap.hpp"
#include <fstream>
#include "BitmapFileHeader.hpp"
#include "BitmapInfoHeader.hpp"

namespace mybitmapnamespace {

/**
 * Constructor for the bitmap image.
 *
 * @param width is the image width
 * @param height is the image height
 */
Bitmap::Bitmap(int width, int height)
    : m_width(width),
      m_height(height),
      m_pPixels(new std::uint8_t[width * height * 3]{}) {}

/**
 * Write the bitmap image to disk.
 *
 * @param filename is the name of the bitmap image.
 * @return A boolean that indicates whether the bitmap image was succesfully
 *         written to disk or not.
 */
bool Bitmap::write(std::string filename) {
  BitmapFileHeader fileHeader;
  BitmapInfoHeader infoHeader;

  fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) +
                        m_width * m_height * 3;
  fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

  infoHeader.width = m_width;
  infoHeader.height = m_height;

  std::ofstream file;
  file.open(filename, std::ios::out | std::ios::binary);

  if (!file) {
    return false;
  }

  file.write((char*)&fileHeader, sizeof(fileHeader));
  file.write((char*)&infoHeader, sizeof(infoHeader));
  file.write((char*)m_pPixels.get(), m_width * m_height * 3);

  file.close();

  if (!file) {
    return false;
  }

  return true;
}

/**
 * Set one pixel of the bitmap image to a RGB value.
 *
 * @param x is the x position
 * @param y is the y position
 * @param red is the R channel in RGB
 * @param green is the G channel in RGB
 * @param blue is the B channel in RGB
 */
void Bitmap::setPixel(int x, int y, std::uint8_t red, std::uint8_t green,
                      std::uint8_t blue) {
  std::uint8_t* pPixel = m_pPixels.get();

  pPixel += (y * 3) * m_width + (x * 3);

  pPixel[0] = blue;
  pPixel[1] = green;
  pPixel[2] = red;
}

/**
 * Destructor for the bitmap image
 */
Bitmap::~Bitmap() {}

}  // namespace mybitmapnamespace
