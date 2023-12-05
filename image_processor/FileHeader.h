#pragma once

#include <iostream>
#include <fstream>
#pragma pack(push, 1)

struct FileHeader {
    char signature[2];
    uint32_t size;
    uint32_t unused;
    uint32_t offset;
};

#pragma pack(pop)