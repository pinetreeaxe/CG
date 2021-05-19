#ifndef PLANE_H
#define PLANE_H
#include "normalTexPoint.hpp"

#include <vector>

class Plane {
private:
    float side;

public:
    Plane(int argc, char** args);
    std::vector<NormalTexPoint> draw() const;
};

#endif
