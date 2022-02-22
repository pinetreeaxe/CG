#include "vector.hpp"

Vector::Vector(){
    x = 0;
    y = 0;
    z = 0;
}

Vector::Vector(float a, float b, float c) {
    x = a;
    y = b;
    z = c;
}

void Vector::set_x(float a) { x = a; }
void Vector::set_y(float b) { y = b; }
void Vector::set_z(float c) { z = c; }

void Vector::multiply(float m) {
    x *= m;
    y *= m;
    z *= m;
}

void Vector::divide(float d) {
    x /= d;
    y /= d;
    z /= d;
}

float Vector::get_x() const { return x; }
float Vector::get_y() const { return y; }
float Vector::get_z() const { return z; }

std::string Vector::to_string() const {
    std::ostringstream pt;
    pt << x << ' ' << y << ' ' << z;
    return pt.str();
}
