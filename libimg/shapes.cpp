#include "shapes.h"
#include "img.h"
#include <iostream> //for debugging

Shape::Shape(Color* fill_color) {
    this->fill_color = fill_color;
    this->stroke_color = fill_color;
}
Shape::Shape(Color* fill_color, Color* stroke_color) {
    this->fill_color = fill_color;
    this->stroke_color = stroke_color;
}
Shape::Shape(Colors fill_color) {
    this->fill_color = new Color(fill_color);
    this->stroke_color = this->fill_color;
}
Shape::Shape(Colors fill_color, Colors stroke_color) {
    this->fill_color = new Color(fill_color);
    this->stroke_color = new Color(stroke_color);
}
Color* Shape::getFill() {
    return fill_color;
}

Circle::Circle(int c_x, int c_y, int radius, Color* fill_color) : Shape(fill_color) {
    x = c_x;
    y = c_y;
    r = radius;
}
Circle::Circle(int c_x, int c_y, int radius, Colors fill_color) : Shape(new Color(fill_color)) {
    x = c_x;
    y = c_y;
    r = radius;
}

bool Circle::isWithinCircle(int c_x, int c_y, int r, int x, int y) {
    int square_dist = ((c_x - x) * (c_x - x)) + ((c_y - y) * (c_y - y));
    return square_dist <= (r * r);
}


void Circle::render(Img *img) {
    int start_pos = img->getPositionInVector(x - r, y - r); 
    int current_pos = 0;
    int diameter = 2 * r;
    for(int i = 0; i < diameter; i++) {
        int pos_y = (y - r) + i;
        for(int j = 0; j < diameter; j++) {
            int pos_x = (x - r) + j;
            if(img->isWithinBounds(pos_x, pos_y) && isWithinCircle(x, y, r, pos_x, pos_y)) {
                img->fillPixel(start_pos + current_pos, this->getFill());
            } 
            current_pos++;
        }
        current_pos += img->getWidth() - diameter;
    }
}

Rectangle::Rectangle(int x, int y, int width, int height, Color* fill_color) : Shape(fill_color) {
    this->x = x; this->y = y; this->width = width; this->height = height;
}

Rectangle::Rectangle(int x, int y, int width, int height, Colors fill_color) : Shape(new Color(fill_color)) {
    this->x = x; this->y = y; this->width = width; this->height = height;
}

void Rectangle::render(Img* img) {
    int start_pos = img->getPositionInVector(x, y);
    int current_pos = 0;
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(img->isWithinBounds(x + j, y + i)) {
                img->fillPixel(start_pos + current_pos, getFill());
            }
            current_pos++;
        }
        current_pos += img->getWidth() - width; 
    }
}
