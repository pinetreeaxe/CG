#include "plane.hpp"

Plane::Plane(int argc, char** args) {
    side = std::stof(args[0]);
}

std::vector<NormalTexPoint> Plane::draw() const {
    std::vector<NormalTexPoint> points;
    Vector normal = Vector(0,1,0);
    float half = side/ 2;

    NormalTexPoint p0 = NormalTexPoint(Point(-half, 0, -half), normal,0,0);
    NormalTexPoint p1 = NormalTexPoint(Point(-half, 0, half), normal,0,1);
    NormalTexPoint p2 = NormalTexPoint(Point(half, 0, -half), normal,1,0);
    NormalTexPoint p3 = NormalTexPoint(Point(half, 0, half), normal,1,1);

    //back triangle 
    points.push_back(p0);
    points.push_back(p1);
    points.push_back(p2);

    //front triangle
    points.push_back(p2);
    points.push_back(p1);
    points.push_back(p3);

    return points;
}