#include "Filters.h"

CropFilter::CropFilter(uint32_t input_width, uint32_t input_height) {
    width = input_width;
    height = input_height;
}

void CropFilter::Process(Image& image) {
    width = std::min(width, image.dib_header.width);
    height = std::min(height, image.dib_header.height);
    std::vector<std::vector<Pixel>> crop_image(height, std::vector<Pixel>(width));
    for (uint32_t i = image.dib_header.height - height; i < image.dib_header.height; ++i) {
        for (uint32_t j = 0; j < width; ++j) {
            crop_image[i - image.dib_header.height + height][j] = image.pixels[i][j];
        }
    }
    image.pixels = crop_image;
    image.dib_header.height = height;
    image.dib_header.width = width;
}