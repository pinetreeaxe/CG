#ifndef UGA_H
#define UGA_H

#include <string>
#include <iostream>
#include <sstream>
#include "vector.hpp"
#include "point.hpp"

class NormalTexPoint2 {
private:
    Point p;
    Vector n;
    float texX;
    float texY;

public:
    NormalTexPoint2(Point, Vector, float, float);
    std::string to_string();
};
#endif