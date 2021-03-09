#ifndef VECTOR_H
#define VECTOR_H

#include <string>
#include <iostream>
#include <sstream>

class Vector {
private:
    float x, y, z;

public:
    Vector(float, float, float);
    void set_x(float a);
    void set_y(float b);
    void set_z(float c);
    float get_x() const;
    float get_y() const;
    float get_z() const;
};
#endif