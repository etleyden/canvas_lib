#include "color.h"

Color::Color(int r, int g, int b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

Color::Color(Color& color) {
    this->r = color.r;
    this->g = color.g;
    this->b = color.b;
}

Color::Color(Colors color) {
    switch(color) {
        case BLACK:
            r = 0; g = 0; b = 0;
            break; 
        case WHITE:
            r = 255; g = 255; b = 255;
            break;
        case RED:
            r = 255; g = 0; b = 0;
            break;
        case GREEN:
            r = 0; g = 255; b = 0;
            break; 
        case BLUE:
            r = 0; g = 0; b = 255;
            break;
    }
}

void Color::print(std::ostream& out) {
    out << r << " " << g << " " << b << "\n";
}
