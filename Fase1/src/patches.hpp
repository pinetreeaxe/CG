#ifndef PATCHES_H
#define PATCHES_H

#include <vector>
#include "point.hpp"
#include "normalTexPoint.hpp"
#include "uga.hpp"

class Patches {
private:
    std::vector<std::vector<int>> indices;
    std::vector<Point> controlPoints;
    int numPatches, numControlPoints, tesselationLevel;
    Vector crossVectors(Vector, Vector);
public:
    Patches(int, char**);
    void multMatrixVector(float[4][4], float *, float *);
    void getBezierPoint(float, Point, Point, Point, Point, float *);
    Vector getNormal(std::vector<Point>, float, float);
    NormalTexPoint2 getGlobalBezierPoint(int, float, float); 
    std::vector<NormalTexPoint2> draw();
};
#endif
