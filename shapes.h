#ifndef SHAPES_H
#define SHAPES_H

#include "color.h"
#include <vector>

class PPM_Img; //forward declaration

class Shape {
    int x, y;
    Color* fill_color;
    Color* stroke_color;
public:
    Shape(Color*);
    Shape(Color*, Color*); // TODO
    Shape(Colors);
    Shape(Colors, Colors); //TODO
    void setFill(Color*);
    void setFill(int, int, int);
    Color* getFill();
    void setStroke(Color*);
    void setStroke(int, int, int);
    virtual void render(PPM_Img*) {};
};

class Circle : public Shape {
    int x, y, r;
public:
    Circle(int, int, int, Color*);
    Circle(int, int, int, Colors);
    bool isWithinCircle(int, int, int, int, int);
    void render(PPM_Img*);
};

class Rectangle : public Shape {
    int x, y, width, height;
public:
    Rectangle(int, int, int, int, Color*);
    Rectangle(int, int, int, int, Colors);
    void render(PPM_Img*);
};

#endif
