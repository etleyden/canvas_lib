#include <iostream>
#include "img.h"

//Constructors
Img::Img(int width, int height) {
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
bool Img::isWithinBounds(int x, int y) {
    bool isWithinXBounds = 0 <= x && x < width;
    bool isWithinYBounds = 0 <= y && y < height;
    return isWithinXBounds && isWithinYBounds;
}
int Img::getPositionInVector(int x, int y) {
    return (y * this->height) + x;
}

//Rendering Tools
void Img::fillPixel(int pos_in_vector, Color* fill_color) {
    image[pos_in_vector] = new Color(*fill_color);
}
void Img::addShape(Shape* shape) {
    shapes.push_back(shape);
}

//Draw Settings

//Core function
void Img::render(std::string filename) {
    std::string extension = filename.substr(filename.find_last_of(".") + 1);

    if(extension == "ppm") {
        PPM::render(filename, this);
    }
}

//Getters and Setters
int Img::getHeight() {return height;}
int Img::getWidth() {return width;}
std::vector<Shape*> Img::getShapes() {return shapes;}
std::vector<Color*> Img::getImageVector() {return image;}