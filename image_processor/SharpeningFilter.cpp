#include "Filters.h"

const int CENTRAL_COEF = 5;

SharpeningFilter::~SharpeningFilter() {
    for (size_t i = 0; i < 3; ++i) {
        delete[] filter[i];
    }
    delete[] filter;
}

int** SharpeningFilter::CreateFilter() {
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

SharpeningFilter::SharpeningFilter() : MatrixFilter(CreateFilter()) {
}