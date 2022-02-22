#ifndef CONE_H
#define CONE_H

#include <vector>
#include "sphericalpoint.hpp"
#include "point.hpp"
#include "normalTexPoint.hpp"

class Cone {
private:
    float radius, height;
    int slices, stacks;

public:
    Cone(int, char**);
    std::vector<NormalTexPoint> draw();
};
#endif
