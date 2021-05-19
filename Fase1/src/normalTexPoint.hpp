#ifndef NORMALTEXPOINT_H
#define NORMALTEXPOINT_H

#include <string>
#include <iostream>
#include <sstream>
#include "vector.hpp"
#include "point.hpp"

class NormalTexPoint {
private:
    Point p;
    Vector n;
    //texture missing

public:
    NormalTexPoint(Point, Vector);
    std::string to_string();
};
#endif