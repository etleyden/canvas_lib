#ifndef PPM_IMG_H
#define PPM_IMG_H

#include <vector>
#include <ostream>
#include "color.h"
#include "shapes.h"

class PPM_Img {
    int width, height;
    std::vector<Shape*> shapes;
    std::vector<Color*> image; 
    Color *fill_color;
    Color *stroke_color;
    int stroke_width;
public:
    PPM_Img(int, int);

    //Checkers
    bool isWithinBounds(int, int);
    int getPositionInVector(int, int);

    //Rendering tools
    void fillPixel(int, Color*); 
    void addShape(Shape*); //TODO

    //Draw Settings
    void background(int, int, int); //TODO
    void background(Color); //TODO

    //Core function
    void render(std::ostream&);

    //Getters & Setters
    int getHeight();
    int getWidth();
};

#endif
