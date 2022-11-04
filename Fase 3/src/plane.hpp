#ifndef PLANE_H
#define PLANE_H
#include "point.hpp"

#include <vector>

class Plane {
private:
    float side;

public:
    Plane(int argc, char** args);
    std::vector<Point> draw() const;
};

#endif
