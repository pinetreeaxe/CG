#ifndef BOX_H
#define BOX_H
#include "point.hpp"
#include "normalTexPoint.hpp"
#include "uga.hpp"
#include <vector>

class Box {
private:
    float x;
    float y;
    float z;
    int div;
    void draw_face(std::vector<NormalTexPoint2>&, Point, Vector, Vector, Vector, float, float) const;

public:
    Box(int argc, char** argv);
    std::vector<NormalTexPoint2> draw() const;
};

#endif
