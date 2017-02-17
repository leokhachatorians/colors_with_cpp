#include <vector>
#include <iostream>
#include <string>
#include "quickcg.h"
using namespace QuickCG;

void remove_channel(std::string, std::vector<ColorRGB>, unsigned long, unsigned long);
void grey_scale(std::vector<ColorRGB>, unsigned long, unsigned long);
void negative(std::vector<ColorRGB>, unsigned long, unsigned long);
void swap_channel(std::string, std::string, std::vector<ColorRGB>, unsigned long, unsigned long);

int main(int argc, char *argv[]) {
    unsigned long w = 0, h = 0;
    std::vector<ColorRGB> image;
    loadImage(image, w, h, "images/flower.png");
    screen(w, h, 0, "RGB Color");

    //remove_channel("green", image, h, w);
    //grey_scale(image, h, w);
    //negative(image, h, w);
    swap_channel("red", "blue", image, h, w);

    redraw();
    sleep();
    return 0;
}


void remove_channel(std::string channel, std::vector<ColorRGB> image, unsigned long height, unsigned long width) {
    ColorRGB color;
    for (unsigned long y = 0; y < height; y++) {
        for (unsigned long x = 0; x < width; x++) {
            ColorRGB color_holder = image[y * width + x];
            if (channel == "red") {
                color.r = 0;
                color.g = color_holder.g;
                color.b = color_holder.b;
            } else if (channel == "green") {
                color.g = 0;
                color.b = color_holder.b;
                color.r = color_holder.r;
            } else if (channel == "blue") {
                color.b = 0;
                color.g = color_holder.g;
                color.r = color_holder.r;
            }
            else {
                std::cout << "Invalid channel" << std::endl;
            }
            pset(x, y, color);
        }
    }
}

void grey_scale(std::vector<ColorRGB> image, unsigned long height, unsigned long width) {
    ColorRGB color;
    for (unsigned long y = 0; y < height; y++) {
        for (unsigned long x = 0; x < width; x++) {
            ColorRGB color_holder = image[y * width + x];
            color.r = color.g = color.b = 
                0.2126 * color_holder.r +
                0.7152 * color_holder.g +
                0.0722 * color_holder.b;
            pset(x, y, color);
        }
    }
}

void negative(std::vector<ColorRGB> image, unsigned long height, unsigned long width) {
    ColorRGB color;
    for (unsigned long y = 0; y < height; y++) {
        for (unsigned long x = 0; x < width; x++) {
            ColorRGB color_holder = image[y * width + x];
            color.r = 255 - color_holder.r;
            color.g = 255 - color_holder.g;
            color.b = 255 - color_holder.b;
            pset(x, y, color);
        }
    }
}

void swap_channel(std::string c1, std::string c2, std::vector<ColorRGB> image, unsigned long height, unsigned long width) {
    ColorRGB color;
    for (unsigned long y = 0; y < height; y++) {
        for (unsigned long x = 0; x < width; x++) {
            ColorRGB color_holder = image[y * width + x];
            if (c1 == "red" && c2 == "green") {
                color.r = color_holder.g;
                color.g = color_holder.r;
                color.b = color_holder.b;
            }
            if (c1 == "red" && c2 == "blue") {
                color.r = color_holder.b;
                color.b = color_holder.r;
                color.g = color_holder.g;
            }
            if (c1 == "blue" && c2 == "green") {
                color.b = color_holder.g;
                color.g = color_holder.b;
                color.r = color_holder.r;
            }
            if (c1 == "green" && c2 == "blue") {
                color.r = color_holder.g;
                color.g = color_holder.r;
                color.b = color_holder.b;
            }
            pset(x, y, color);
        }
    }
}


