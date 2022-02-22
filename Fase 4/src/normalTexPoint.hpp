#ifndef NORMALTEXPOINT_H
#define NORMALTEXPOINT_H

#include <string>
#include <iostream>
#include <sstream>
#include "vector.hpp"
#include "point.hpp"

class NormalTexPoint{
private:
    Point p;
    Vector n;
    float texX;
    float texY;

public:
    NormalTexPoint(Point, Vector, float, float);
    std::string to_string();
};
#endif