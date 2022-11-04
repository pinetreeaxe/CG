#ifndef SPHERE_H
#define SPHERE_H

#include <vector>
#include "sphericalpoint.hpp"
#include "point.hpp"

class Sphere {
private:
    float radius;
    int stacks, slices;

public:
    Sphere(int, char**);
    std::vector<Point> draw();
};
#endif
