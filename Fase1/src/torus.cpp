#include "torus.hpp"
#include "point.hpp"
#define _USE_MATH_DEFINES
#include "math.h"

Torus::Torus(int argc, char** argv){
	float innerRadius = std::stof(argv[0]);
    float outerRadius = std::stof(argv[1]);
    radius = (innerRadius+outerRadius)/2.0f;
    ringRadius = (outerRadius-innerRadius)/2.0f;
	slices = std::stoi(argv[2]);
	stacks = std::stoi(argv[3]);
}

std::vector<Point> Torus::draw() {

	float step = 2 * M_PI / slices;
	float steph = 2 * M_PI / stacks;

	std::vector<Point> points;

	for (int i = 0; i < slices; i++) {
        //translate to the ring
        Vector center = Vector(radius*sin(step*i),0,radius*cos(step*i));
        Vector nextCenter= Vector(radius*sin(step*(i+1)),0,radius*cos(step*(i+1)));


		for (int j = 0; j < stacks; j++) {
            Point p1 = Point(SphericalPoint(step * i, steph * j, ringRadius));
            p1.add_vector(center);
            Point p2 = Point(SphericalPoint(step * i, steph * (j+1), ringRadius));
            p2.add_vector(center); 
            Point p3 = Point(SphericalPoint(step * (i+1), steph * j, ringRadius));
            p3.add_vector(nextCenter);
            Point p4 = Point(SphericalPoint(step * (i+1), steph * (j+1), ringRadius));
            p4.add_vector(nextCenter);

			points.push_back(p1);
			points.push_back(p3);
			points.push_back(p2);

			points.push_back(p2);
			points.push_back(p3);
			points.push_back(p4);
		}
	}
	return points;
}