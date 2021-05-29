#ifndef TORUS_H
#define TORUS_H

#include <vector>
#include "sphericalpoint.hpp"
#include "point.hpp"
#include "normalTexPoint.hpp"
#include "uga.hpp"
class Torus {
private:
    float radius, ringRadius;
    int stacks, slices;

public:
    Torus(int, char**);
    std::vector<NormalTexPoint2> draw();
};
#endif
