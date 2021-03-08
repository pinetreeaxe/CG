#ifndef BOX_H
#define BOX_H
#include "point.hpp"
#include <vector>

class Box {
private:
    float x;
    float y;
    float z;
    int div;

public:
    Box(int argc, char** argv);
    std::vector<Point> draw() const;
};

#endif
