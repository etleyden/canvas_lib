#ifndef COLOR_H
#define COLOR_H
#include <ostream>

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

#endif
