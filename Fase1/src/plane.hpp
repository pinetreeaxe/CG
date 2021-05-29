#ifndef PLANE_H
#define PLANE_H
#include "uga.hpp"

#include <vector>

class Plane {
private:
    float side;

public:
    Plane(int argc, char** args);
    std::vector<NormalTexPoint2> draw() const;
};

#endif
