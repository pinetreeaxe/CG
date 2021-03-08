#include "vector.h"

Vector::Vector(float a, float b, float c) {
    x = a;
    y = b;
    z = c;
}

void set_x(float a) { x = a; }
void set_y(float b) { y = b; }
void set_z(float c) { z = c; }

float get_x() const { return x; }
float get_y() const { return y; }
float get_z() const { return z; }
