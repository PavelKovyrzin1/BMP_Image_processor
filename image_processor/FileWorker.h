#pragma once

#include "Image.h"

void Read(Image& image, const std::string& path);
void Write(const std::string& filename, const Image& image);