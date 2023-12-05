#include "Image.h"
#include "FileWorker.h"
#include "Filters.h"
#include <cmath>
#include <cstring>

int main(int argc, char* argv[]) {
    Image image;
    Read(image, argv[1]);
    for (int i = 0; i < argc; ++i) {
        if (strcmp(argv[i], "-crop") == 0) {
            CropFilter filter(static_cast<uint32_t>(std::stoi(argv[i + 1])),
                              static_cast<uint32_t>(std::stoi(argv[i + 2])));
            filter.Process(image);
        } else if (strcmp(argv[i], "-neg") == 0) {
            Negative filter;
            filter.Process(image);
        } else if (strcmp(argv[i], "-gs") == 0) {
            GrayscaleFilter filter;
            filter.Process(image);
        } else if (strcmp(argv[i], "-sharp") == 0) {
            SharpeningFilter filter;
            filter.Process(image);
        } else if (strcmp(argv[i], "-edge") == 0) {
            EdgeDetectionFilter filter(std::stod(argv[i + 1]));
            filter.Process(image);
        }
    }
    Write(argv[2], image);
}
