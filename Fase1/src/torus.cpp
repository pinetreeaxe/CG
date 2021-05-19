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

std::vector<NormalTexPoint> Torus::draw() {

	float step = 2 * M_PI / slices;
	float steph = 2 * M_PI / stacks;

	std::vector<NormalTexPoint> points;

	for (int i = 0; i < slices; i++) {
        //translate to the ring
        Vector center = Vector(radius*sin(step*i),0,radius*cos(step*i));
        Vector nextCenter= Vector(radius*sin(step*(i+1)),0,radius*cos(step*(i+1)));


		for (int j = 0; j < stacks; j++) {
            Point p1 = Point(SphericalPoint(step * i, steph * j, ringRadius));
			Vector v1 = Vector(p1.get_x()/ringRadius, p1.get_y()/ringRadius, p1.get_z()/ringRadius);
            p1.add_vector(center);

            Point p2 = Point(SphericalPoint(step * i, steph * (j+1), ringRadius));
			Vector v2 = Vector(p2.get_x()/ringRadius, p2.get_y()/ringRadius, p2.get_z()/ringRadius);
            p2.add_vector(center); 

            Point p3 = Point(SphericalPoint(step * (i+1), steph * j, ringRadius));
			Vector v3 = Vector(p3.get_x()/ringRadius, p3.get_y()/ringRadius, p3.get_z()/ringRadius);
            p3.add_vector(nextCenter);

            Point p4 = Point(SphericalPoint(step * (i+1), steph * (j+1), ringRadius));
			Vector v4 = Vector(p4.get_x()/ringRadius, p4.get_y()/ringRadius, p4.get_z()/ringRadius);
            p4.add_vector(nextCenter);

			points.push_back(NormalTexPoint(p1,v1));
			points.push_back(NormalTexPoint(p3,v3));
			points.push_back(NormalTexPoint(p2,v2));

			points.push_back(NormalTexPoint(p2,v2));
			points.push_back(NormalTexPoint(p3,v3));
			points.push_back(NormalTexPoint(p4,v4));
		}
	}
	return points;
}