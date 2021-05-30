#ifndef TORUS_H
#define TORUS_H

#include <vector>
#include "sphericalpoint.hpp"
#include "point.hpp"
#include "normalTexPoint.hpp"

class Torus {
private:
    float radius, ringRadius;
    int stacks, slices;

public:
    Torus(int, char**);
    std::vector<NormalTexPoint> draw();
};
#endif
