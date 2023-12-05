#include "Filters.h"

const double INT_8_MAX = 255.0;
const uint8_t WHITE = 255;
const uint8_t BLACK = 0;
const int CENTRAL_COEF = 4;

EdgeDetectionFilter::~EdgeDetectionFilter() {
    for (size_t i = 0; i < 3; ++i) {
        delete[] filter[i];
    }
    delete[] filter;
}

int** EdgeDetectionFilter::CreateFilter() {
    filter = new int*[3];
    for (size_t i = 0; i < 3; ++i) {
        filter[i] = new int[3];
    }
    filter[0][0] = 0;
    filter[0][1] = -1;
    filter[0][2] = 0;
    filter[1][0] = -1;
    filter[1][1] = CENTRAL_COEF;
    filter[1][2] = -1;
    filter[2][0] = 0;
    filter[2][1] = -1;
    filter[2][2] = 0;
    return filter;
}

EdgeDetectionFilter::EdgeDetectionFilter(double input) : MatrixFilter(CreateFilter()) {
    threshold = input;
}

void EdgeDetectionFilter::Process(Image& image) {
    GrayscaleFilter::Process(image);
    MatrixFilter::Process(image);
    for (uint32_t x = 0; x < image.dib_header.height; ++x) {
        for (uint32_t y = 0; y < image.dib_header.width; ++y) {
            if ((static_cast<double>(image.pixels[x][y].R) / INT_8_MAX) > threshold) {
                image.pixels[x][y] = {WHITE, WHITE, WHITE};
            } else {
                image.pixels[x][y] = {BLACK, BLACK, BLACK};
            }
        }
    }
}