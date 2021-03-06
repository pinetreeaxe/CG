#include "point.h"

Point::Point(float a, float b, float c){
    x = a;
    y = b;
    z = c;
}

std::string Point::to_string() const {
    std::ostringstream pt;
    pt << x << ' ' << y << ' ' << z;
    return pt.str();
}

