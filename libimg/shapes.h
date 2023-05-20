#ifndef SHAPES_H
#define SHAPES_H

#include "img_util.h"
#include <vector>

class Img; //forward declaration

class Shape {
    int x, y;
    Color* fill_color, stroke_color;
    int stroke_width;
public:
    //Constructors
    Shape(Color*);
    Shape(Color*, Color*); // TODO
    Shape(Colors);
    Shape(Colors, Colors); //TODO
    //Getters & setters
    void setFill(Color*);
    void setFill(int, int, int);
    Color* getFill();
    Color* getStrokeColor();
    int getStrokeWidth();
    void setStrokeColor(Color*);
    void setStrokeColor(Colors);
    void setStrokeColor(int, int, int);
    void setStrokeWidth(int);
    virtual void render(Img*) {};
};

class Circle : public Shape {
    int x, y, r;
public:
    Circle(int, int, int, Color*);
    Circle(int, int, int, Colors);
    bool isWithinStroke(int, int);
    bool isWithinCircle(int, int);
    void render(Img*);
};

class Rectangle : public Shape {
    int x, y, width, height;
public:
    Rectangle(int, int, int, int, Color*);
    Rectangle(int, int, int, int, Colors);
    bool isWithinStroke(int, int);
    void render(Img*);
};

#endif
