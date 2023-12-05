#pragma once

#include "Image.h"

class AbstractFilter {
public:
    virtual void Process(Image& image) = 0;
};

class CropFilter : public AbstractFilter {
public:
    uint32_t width;
    uint32_t height;
    explicit CropFilter(uint32_t input_width, uint32_t input_height);
    void Process(Image& image) override;
};

class GrayscaleFilter : public AbstractFilter {
public:
    void Process(Image& image) override;
};

class Negative : public AbstractFilter {
public:
    void Process(Image& image) override;
};

class MatrixFilter : public AbstractFilter {
public:
    int** matrix;
    explicit MatrixFilter(int** input);
    ~MatrixFilter();
    void Process(Image& image) override;
};

class SharpeningFilter : public MatrixFilter {
public:
    int** filter;
    SharpeningFilter();
    ~SharpeningFilter();
    int** CreateFilter();
};

class EdgeDetectionFilter final : public MatrixFilter, public GrayscaleFilter {
public:
    int** filter;
    double threshold;
    explicit EdgeDetectionFilter(double);
    ~EdgeDetectionFilter();
    void Process(Image& image) override;
    int** CreateFilter();
};
