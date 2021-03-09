#ifndef SPHERE_H
#define SPHERE_H

#include <vector>
#include "sphericalpoint.hpp"
#include "point.hpp"

class Sphere {
private:
    float stacks, slices, radius;

public:
    Sphere(int, char**);
    std::vector<Point> draw();
};
#endif
