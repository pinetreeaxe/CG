#include "vector.hpp"

Vector::Vector(float a, float b, float c) {
    x = a;
    y = b;
    z = c;
}

void Vector::set_x(float a) { x = a; }
void Vector::set_y(float b) { y = b; }
void Vector::set_z(float c) { z = c; }

float Vector::get_x() const { return x; }
float Vector::get_y() const { return y; }
float Vector::get_z() const { return z; }
