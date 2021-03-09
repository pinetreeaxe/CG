#include "point.hpp"

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

void Point::add_vector(Vector v) {
    x += v.get_x();
    y += v.get_y();
    z += v.get_z();
}

void Point::set_x(float a) { x = a; }
void Point::set_y(float b) { y = b; }
void Point::set_z(float c) { z = c; }

float Point::get_x() const { return x; }
float Point::get_y() const { return y; }
float Point::get_z() const { return z; }

