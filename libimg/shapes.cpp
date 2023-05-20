#include "shapes.h"
#include "img.h"
#include <iostream> //for debugging

//Abstract Shape class
//Constructors
Shape::Shape(Color* fill_color) : 
    fill_color{fill_color},
    stroke_color{fill_color} {
}
Shape::Shape(Color* fill_color, Color* stroke_color) :
    fill_color{fill_color},
    stroke_color{stroke_color} {
}
Shape::Shape(Colors fill_color) :
    fill_color{new Color(fill_color)},
    stroke_color{new Color(fill_color)} {
}
Shape::Shape(Colors fill_color, Colors stroke_color) :
    fill_color{new Color(fill_color)},
    stroke_color{new Color(stroke_color)} {
}

//Getters and Setters
//Fill
Color* Shape::getFill() { return fill_color; }
void Shape::setFill(Color* color) {this->fill_color = color;}
void Shape::setFill(int r, int g, int b) {this->fill_color = new Color(r, g, b);}
//Stroke
Color* Shape::getStrokeColor() {return &stroke_color; } //Not sure why this has to be different from fill_color
int Shape::getStrokeWidth() { return stroke_width; }
void Shape::setStrokeColor(Color* color) { this->stroke_color = color;}
void Shape::setStrokeColor(Colors color) { this->stroke_color = new Color(color); }
void Shape::setStrokeColor(int r, int g, int b) {this->stroke_color = new Color(r, g, b); }
void Shape::setStrokeWidth(int width) {this->stroke_width = width;}

//Circle
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

//detect if pt (x, y) is inside the STROKE target
bool Circle::isWithinStroke(int px, int py) {
    int square_dist = ((x - px) * (x - px)) + ((y - py) * (y - py));
    return (r - getStrokeWidth()) * (r - getStrokeWidth()) <= square_dist && square_dist <= (r * r);
}
/**
 * Detect if pt. (x, y) is inside the circle
*/
bool Circle::isWithinCircle(int px, int py) {
    int square_dist = ((x - px) * (x - px)) + ((y - py) * (y - py));
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
            if(img->isWithinBounds(pos_x, pos_y) && isWithinCircle(pos_x, pos_y)) {
                bool isStrokePixel = isWithinStroke(pos_x, pos_y);
                img->fillPixel(
                    start_pos + current_pos, 
                    (isStrokePixel) ? this->getStrokeColor() : this->getFill());
            } 
            current_pos++;
        }
        current_pos += img->getWidth() - diameter;
    }
}


//Rectangle
Rectangle::Rectangle(int x, int y, int width, int height, Color* fill_color) : Shape(fill_color) {
    this->x = x; this->y = y; this->width = width; this->height = height;
}

Rectangle::Rectangle(int x, int y, int width, int height, Colors fill_color) : Shape(new Color(fill_color)) {
    this->x = x; this->y = y; this->width = width; this->height = height;
}

bool Rectangle::isWithinStroke(int px, int py) {
    int stroke_width = getStrokeWidth(); //localized stroke width
    bool isStroke = !(px > (x + stroke_width) && px < (x + width - stroke_width) //checks if px is in the inner rectangle, and takes the inverse
                    && py > (y + stroke_width) && py < (y + height - stroke_width));
    return isStroke;
}

void Rectangle::render(Img* img) {
    int start_pos = img->getPositionInVector(x, y);
    int current_pos = 0;
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(img->isWithinBounds(x + j, y + i)) {
                img->fillPixel(start_pos + current_pos,
                (isWithinStroke(x + j, y + i)) ? getStrokeColor() : getFill());
            }
            current_pos++;
        }
        current_pos += img->getWidth() - width; 
    }
}
