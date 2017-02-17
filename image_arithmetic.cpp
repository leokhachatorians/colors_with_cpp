#include <string>
#include <iostream>
#include "quickcg.h"
#include "math.h"

using namespace QuickCG;

void average_images(std::vector<ColorRGB>, std::vector<ColorRGB>, std::vector<ColorRGB>, unsigned long, unsigned long);
void add_images(std::vector<ColorRGB>, std::vector<ColorRGB>, std::vector<ColorRGB>, unsigned long, unsigned long);
void subtract_images(std::vector<ColorRGB>, std::vector<ColorRGB>, std::vector<ColorRGB>, unsigned long, unsigned long);
void difference_of_images(std::vector<ColorRGB>, std::vector<ColorRGB>, std::vector<ColorRGB>, unsigned long, unsigned long);
void crossfade(std::vector<ColorRGB>, std::vector<ColorRGB>, std::vector<ColorRGB>, unsigned long, unsigned long);
void min_of_images(std::vector<ColorRGB>, std::vector<ColorRGB>, std::vector<ColorRGB>, unsigned long, unsigned long);
void max_of_images(std::vector<ColorRGB>, std::vector<ColorRGB>, std::vector<ColorRGB>, unsigned long, unsigned long);

int main(int argc, char *argv[]) {
    unsigned long w = 0, h = 0;
    std::vector<ColorRGB> image1, image2, image3, result;

    loadImage(image1, w, h, "images/photo1.png");
    loadImage(image2, w, h, "images/photo2.png");
    loadImage(image3, w, h, "images/photo3.png");
    result.resize(w * h);

    screen(w, h, 0, "Arthimetic");

    //average_images(image1, image2, result, h, w);
    //add_images(image3, image2, result, h, w);
    //subtract_images(image2, image3, result, h, w);
    //average_images(image1, image3, result, h, w);
    //crossfade(image1, image2, result, h, w);
    //min_of_images(image1, image2, result, h, w);
    max_of_images(image1, image2, result, h, w);
    

    redraw();
    sleep();
}

void average_images(std::vector<ColorRGB> image1, std::vector<ColorRGB> image2,
                    std::vector<ColorRGB> result, unsigned long h, unsigned long w) {
    for (unsigned long y = 0; y < h; y++) {
        for (unsigned long x = 0; x < w; x++) {
            int sum = y * w + x;
            result[sum].r = (image1[sum].r + image2[sum].r) / 2;
            result[sum].g = (image1[sum].g + image2[sum].g) / 2;
            result[sum].b = (image1[sum].b + image2[sum].b) / 2;
            pset(x, y, result[sum]);
        }
    }
}

void add_images(std::vector<ColorRGB> image1, std::vector<ColorRGB> image2,
                std::vector<ColorRGB> result, unsigned long h, unsigned long w) {
    for (unsigned long y = 0; y < h; y++) {
        for (unsigned long x = 0; x < w; x++) {
            int sum = y * w + x;
            result[sum].r = std::min(image1[sum].r + image2[sum].r, 255);
            result[sum].g = std::min(image1[sum].g + image2[sum].g, 255);
            result[sum].b = std::min(image1[sum].b + image2[sum].b, 255);
            pset(x, y, result[sum]);
        }
    }
}

void subtract_images(std::vector<ColorRGB> image1, std::vector<ColorRGB> image2,
                     std::vector<ColorRGB> result, unsigned long h, unsigned long w) {
    for (unsigned long y = 0; y < h; y++) {
        for (unsigned long x = 0; x < w; x++) {
            int sum = y * w + x;
            result[sum].r = std::max(image1[sum].r - image2[sum].r, 0);
            result[sum].g = std::max(image1[sum].g - image2[sum].g, 0);
            result[sum].b = std::max(image1[sum].b - image2[sum].b, 0);
            pset(x, y, result[sum]);
        }
    }
}

void difference_of_images(std::vector<ColorRGB> image1, std::vector<ColorRGB> image2,
                          std::vector<ColorRGB> result, unsigned long h, unsigned long w) {
    for (unsigned long y = 0; y < h; y++) {
        for (unsigned long x = 0; x < w; x++) {
            int sum = y * w + x;
            result[sum].r = std::abs(image1[sum].r - image2[sum].r);
            result[sum].g = std::abs(image1[sum].g - image2[sum].g);
            result[sum].b = std::abs(image1[sum].b - image2[sum].b);
            pset(x, y, result[sum]);
        }
    }
}

void crossfade(std::vector<ColorRGB> image1, std::vector<ColorRGB> image2,
               std::vector<ColorRGB> result, unsigned long h, unsigned long w) {
    float weight;

    while (!done()) {
        weight = (1.0 + cos(getTicks() / 1000.0)) / 2.0;

        for (unsigned long y = 0; y < h; y++) {
            for (unsigned long x = 0; x < w; x++) {
                int sum = y * w + x;
                result[sum].r = int(image1[sum].r * weight + image2[sum].r * (1 - weight));
                result[sum].b = int(image1[sum].b * weight + image2[sum].b * (1 - weight));
                result[sum].g = int(image1[sum].g * weight + image2[sum].g * (1 - weight));
                pset(x, y, result[sum]);
            }
        }
        redraw();
    }
}

void min_of_images(std::vector<ColorRGB> image1, std::vector<ColorRGB> image2,
                 std::vector<ColorRGB> result, unsigned long h, unsigned long w) {
    for (unsigned long y = 0; y < h; y++) {
        for (unsigned long x = 0; x < w; x++) {
            int sum = y * w + x;
            result[sum].r = std::min(image1[sum].r, image2[sum].r);
            result[sum].g = std::min(image1[sum].g, image2[sum].g);
            result[sum].b = std::min(image1[sum].b, image2[sum].b);
            pset(x, y, result[sum]);
        }
    }
}

void max_of_images(std::vector<ColorRGB> image1, std::vector<ColorRGB> image2,
                 std::vector<ColorRGB> result, unsigned long h, unsigned long w) {
    for (unsigned long y = 0; y < h; y++) {
        for (unsigned long x = 0; x < w; x++) {
            int sum = y * w + x;
            result[sum].r = std::max(image1[sum].r, image2[sum].r);
            result[sum].g = std::max(image1[sum].g, image2[sum].g);
            result[sum].b = std::max(image1[sum].b, image2[sum].b);
            pset(x, y, result[sum]);
        }
    }
}
