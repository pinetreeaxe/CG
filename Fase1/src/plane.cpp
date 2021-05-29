#include "plane.hpp"

Plane::Plane(int argc, char** args) {
    side = std::stof(args[0]);
}

std::vector<NormalTexPoint2> Plane::draw() const {
    std::vector<NormalTexPoint2> points;
    Vector normal = Vector(0,1,0);
    float half = side/ 2;

    NormalTexPoint2 p0 = NormalTexPoint2(Point(-half, 0, -half), normal,0,0);
    NormalTexPoint2 p1 = NormalTexPoint2(Point(-half, 0, half), normal,0,1);
    NormalTexPoint2 p2 = NormalTexPoint2(Point(half, 0, -half), normal,1,0);
    NormalTexPoint2 p3 = NormalTexPoint2(Point(half, 0, half), normal,1,1);

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