#include "formats.h"
#include "img.h"
#include <iostream>
#include <fstream>

PPM::PPM(Dimension dimensions) : d(dimensions) {
    header = "P3\n" + std::to_string(d.w) + " " + std::to_string(d.h) + "\n255\n";
}

void PPM::render(std::string filename, Img* image) {
    std::ofstream out(filename);

    out << "P3\n" << image->getWidth() << " " << image->getHeight() << "\n255\n";
    std::vector<Shape*> shapes = image->getShapes();
    
    for(auto & i : shapes) { //Update image to reflect shape objects
        i->render(image);
    }
    
    //Output the data into the image
    std::vector<Color*> image_vector = image->getImageVector();
    for(auto & i : image_vector) {
        i->print(out);
    }

    out.close();

}
