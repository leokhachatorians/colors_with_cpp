#include <vector>
#include <iostream>
#include "quickcg.h"
using namespace QuickCG;

int main(int argc, char *argv[]) {
    unsigned long w = 0, h = 0;
    std::vector<ColorRGB> image;
    loadImage(image, w, h, "flower.png");
    screen(w, h, 0, "RGB Color");

    ColorRGB color;

    for (unsigned long y = 0; y < h; y++) {
        for (unsigned long x = 0; x < w; x++) {
            std::cout << image[y * w + x] << std::endl;;
            color.r = 255 - image[y * w + x].r;
            color.g = 255 - image[y * w + x].g;
            color.b = 255 - image[y * w + x].b;
            pset(x, y, color);
        }
    }
    redraw();
    sleep();
    return 0;
}
