#include <vector>
#include <iostream>
#include <string>
#include "quickcg.h"
using namespace QuickCG;

void remove_channel(std::string, std::vector<ColorRGB>, unsigned long, unsigned long);

int main(int argc, char *argv[]) {
    unsigned long w = 0, h = 0;
    std::vector<ColorRGB> image;
    loadImage(image, w, h, "flower.png");
    screen(w, h, 0, "RGB Color");

    //ColorRGB color;
    remove_channel("green", image, h, w);

   // for (unsigned long y = 0; y < h; y++) {
   //     for (unsigned long x = 0; x < w; x++) {
   //         ColorRGB color_holder = image[y * w + x];
   //         color.r = color.g = color.b = 
   //             0.2126 * color_holder.r +
   //             0.7152 * color_holder.g +
   //             0.0722 * color_holder.b;
   //         pset(x, y, color);
   //     }
   // }
    redraw();
    sleep();
    return 0;
}


void remove_channel(std::string channel, std::vector<ColorRGB> image, unsigned long height, unsigned long width) {
    ColorRGB color;
    for (unsigned long y = 0; y < height; y++) {
        for (unsigned long x = 0; x < width; x++) {
            ColorRGB color_holder = image[y * w + x];
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
            pset(x, y, color);
        }
    }
}

