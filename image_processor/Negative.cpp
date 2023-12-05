#include "Filters.h"

const uint8_t INT_8_MAX = 255;

void Negative::Process(Image& image) {
    for (std::vector<Pixel>& row : image.pixels) {
        for (Pixel& pixel : row) {
            pixel.R = INT_8_MAX - pixel.R;
            pixel.G = INT_8_MAX - pixel.G;
            pixel.B = INT_8_MAX - pixel.B;
        }
    }
}