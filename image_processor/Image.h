#pragma once
#include "FileHeader.h"
#include "DIBHeader.h"
#include "Pixel.h"
#include <vector>

struct Image {
    std::vector<std::vector<Pixel>> pixels;
    FileHeader file_header;
    DIBHeader dib_header;
};