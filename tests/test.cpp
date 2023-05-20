#include <iostream>
#include "img.h"

int main() {
    Img *image = new Img(1000, 1000);
    Rectangle *rect = new Rectangle(450, 550, 200, 300, RED);
    rect->setStrokeColor(BLUE);
    rect->setStrokeWidth(10);
    image->addShape(rect);

    Circle *circle = new Circle(200, 200, 100, RED);
    circle->setStrokeColor(BLUE);
    circle->setStrokeWidth(10);
    image->addShape(circle);

    image->render("image.ppm");
}
