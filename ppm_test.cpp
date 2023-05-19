#include <iostream>
#include "ppm_img.h"

int main() {
    PPM_Img *image = new PPM_Img(100, 100);
    image->addShape(new Rectangle(10, 0, 50, 70, RED));
    image->render(std::cout);
}
