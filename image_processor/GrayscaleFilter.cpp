#include "Filters.h"
#include <cmath>

const double INT_8_MAX = 255.0;
const double RED_COEF = 0.299;
const double GREEN_COEF = 0.587;
const double BLUE_COEF = 0.114;

void GrayscaleFilter::Process(Image& image) {
    for (std::vector<Pixel>& row : image.pixels) {
        for (Pixel& pixel : row) {
            double red = static_cast<double>(pixel.R) / INT_8_MAX;
            double green = static_cast<double>(pixel.G) / INT_8_MAX;
            double blue = static_cast<double>(pixel.B) / INT_8_MAX;
            double grey = RED_COEF * red + GREEN_COEF * green + BLUE_COEF * blue;
            uint8_t int_grey = static_cast<uint8_t>(round(grey * INT_8_MAX));
            pixel.R = int_grey;
            pixel.G = int_grey;
            pixel.B = int_grey;
        }
    }
}