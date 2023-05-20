#include <iostream>
#include "img.h"

int main() {
    Img *image = new Img(100, 100);
    image->addShape(new Rectangle(10, 0, 50, 70, RED));
    image->render("image.ppm");
}
