#ifndef POINT_H
#define POINT_H

#include <string>
#include <iostream>
#include <sstream>

class Point {
private:
    float x, y, z;

public:
    Point(float, float, float);
    std::string to_string() const;
};
#endif
