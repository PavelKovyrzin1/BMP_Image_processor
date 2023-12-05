#include "FileWorker.h"

const uint32_t INT_SIZE = 32;

#pragma pack(1)

void Read(Image& image, const std::string& path) {
    std::ifstream file(path, std::ios::binary);

    file.read(reinterpret_cast<char*>(&image.file_header), sizeof(FileHeader));
    file.read(reinterpret_cast<char*>(&image.dib_header), sizeof(DIBHeader));

    uint32_t width = image.dib_header.width;
    uint32_t height = image.dib_header.height;

    image.pixels.resize(height);
    for (uint32_t i = 0; i < height; ++i) {
        image.pixels[i].resize(width);
    }

    uint32_t pixeldataoffset = image.file_header.offset;

    uint32_t row_size = 4 * ((image.dib_header.bitCount * image.dib_header.width + INT_SIZE - 1) / INT_SIZE);

    for (uint32_t i = 0; i < height; ++i) {
        file.seekg(pixeldataoffset + i * row_size);
        file.read(reinterpret_cast<char*>(image.pixels[i].data()), static_cast<std::streamsize>(width * sizeof(Pixel)));
    }
    file.close();
}

void Write(const std::string& filename, const Image& image) {
    std::ofstream file(filename, std::ios::binary);

    file.write(reinterpret_cast<const char*>(&image.file_header), sizeof(FileHeader));
    file.write(reinterpret_cast<const char*>(&image.dib_header), sizeof(DIBHeader));

    uint32_t width = image.dib_header.width;
    uint32_t height = image.dib_header.height;

    uint32_t row_size = 4 * ((image.dib_header.bitCount * image.dib_header.width + INT_SIZE - 1) / INT_SIZE);
    uint32_t pixeldataoffset = image.file_header.offset;

    for (int i = static_cast<int>(height - 1); i >= 0; --i) {
        file.seekp(pixeldataoffset + i * row_size);
        file.write(reinterpret_cast<const char*>(image.pixels[i].data()),
                   static_cast<std::streamsize>(width * sizeof(Pixel)));
    }
    file.close();
}
