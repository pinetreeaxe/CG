#ifndef SPHERE_H
#define SPHERE_H

#include <vector>
#include "sphericalpoint.hpp"
#include "point.hpp"
#include "uga.hpp"

class Sphere {
private:
    float radius;
    int stacks, slices;

public:
    Sphere(int, char**);
    std::vector<NormalTexPoint2> draw();
};
#endif
