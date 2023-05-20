#ifndef IMG_UTIL_H
#define IMG_UTIL_H
#include <ostream>

/*
 * This class is intended for all utilities for the library:
 * Color
 * Dimension
 */


enum Colors {
    BLACK, WHITE, RED, GREEN, BLUE
};

class Color {
    int r, g, b;
public:
    Color(Colors);
    Color(Color&);
    Color(int, int, int);
    void print(std::ostream&);
};

class Dimension {
public:
    int w, h;
    Dimension(int, int);
    Dimension(Dimension&);
};

#endif
