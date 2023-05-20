#ifndef IMG_H
#define IMG_H

#include <vector>
#include <ostream>
#include <string>
#include "img_util.h"
#include "shapes.h"
#include "formats.h"

class Img {
    int width, height;
    std::vector<Shape*> shapes;
    std::vector<Color*> image; 
    Color *fill_color;
    Color *stroke_color;
    int stroke_width;
public:
    Img(int, int);

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
    void render(std::string);

    //Getters & Setters
    int getHeight();
    int getWidth();
    std::vector<Shape*> getShapes();
    std::vector<Color*> getImageVector();
};

#endif
