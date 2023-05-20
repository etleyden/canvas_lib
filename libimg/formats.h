#ifndef FORMATS_H
#define FORMATS_H

#include <string>
#include "img_util.h"

class Img; //forward declaration

//Currently supported types: ppm

class PPM {
    Dimension d; //width & height
    std::string header;
public:
    PPM(Dimension dimensions);
    static void render(std::string, Img*);
};

#endif // !FORMATS_H

