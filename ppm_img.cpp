#include <iostream>
#include "ppm_img.h"

//Constructors
PPM_Img::PPM_Img(int width, int height) {
    this->width = width;
    this->height = height;
    this->fill_color = (new Color(255, 255, 255));
    this->stroke_color = (new Color(50, 50, 50));
    this->image.reserve(width * height);
    for(int i = 0; i < width * height; i++) {
        image.push_back((new Color(*fill_color)));
    }
}

//Checkers
bool PPM_Img::isWithinBounds(int x, int y) {
    bool isWithinXBounds = 0 <= x && x < width;
    bool isWithinYBounds = 0 <= y && y < height;
    return isWithinXBounds && isWithinYBounds;
}
int PPM_Img::getPositionInVector(int x, int y) {
    return (y * this->height) + x;
}

//Rendering Tools
void PPM_Img::fillPixel(int pos_in_vector, Color* fill_color) {
    image[pos_in_vector] = new Color(*fill_color);
}
void PPM_Img::addShape(Shape* shape) {
    shapes.push_back(shape);
}

//Draw Settings

//Core function
void PPM_Img::render(std::ostream& out) {
    out << "P3\n" << width << " " << height << "\n255\n";
    for(auto & i : shapes) {
        i->render(this);
    }
    for(auto & i : image) {
        i->print(out);
    }
}

//Getters and Setters
int PPM_Img::getHeight() {return height;}
int PPM_Img::getWidth() {return width;}
