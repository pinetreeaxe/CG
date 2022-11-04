#ifndef POINT_H
#define POINT_H

#include <string>
#include <iostream>
#include <sstream>
#include "vector.hpp"
#include "sphericalpoint.hpp"

class Point {
private:
    float x, y, z;

public:
    Point();
    Point(float, float, float);
    Point(SphericalPoint);
    std::string to_string() const;
    void add_vector(Vector);
    void set_x(float a);
    void set_y(float b);
    void set_z(float c);
    float get_x() const;
    float get_y() const;
    float get_z() const;
};
#endif
