#pragma once

#include <iostream>
#include <fstream>

struct DIBHeader {
    uint32_t headerSize;
    uint32_t width;
    uint32_t height;
    uint16_t planes;
    uint16_t bitCount;
    uint32_t compression;
    uint32_t imageSize;
    uint32_t xPixelsPerMeter;
    uint32_t yPixelsPerMeter;
    uint32_t colorsUsed;
    uint32_t colorsImportant;
};