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

void add_vector(Vector v) {
    x += v.get_x();
    y += v.get_y();
    z += v.get_z();
}

void set_x(float a) { x = a; }
void set_y(float b) { y = b; }
void set_z(float c) { z = c; }

float get_x() const { return x; }
float get_y() const { return y; }
float get_z() const { return z; }

