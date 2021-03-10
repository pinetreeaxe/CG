#include "sphere.hpp"
#include "point.hpp"
#define _USE_MATH_DEFINES
#include "math.h"

Sphere::Sphere(int argc, char** argv){
	radius = std::stof(argv[0]);
	slices = std::stoi(argv[1]);
	stacks = std::stoi(argv[2]);
}

std::vector<Point> Sphere::draw() {

	Point top = Point(0, radius, 0);
	Point bot = Point(0, -radius, 0);

	float step = 2 * M_PI / slices;
	float steph = M_PI / stacks;

	std::vector<Point> points;

	for (int i = 0; i < slices; i++) {
		Point p1 = Point(SphericalPoint(step * i, (M_PI / 2) - steph, radius));
		Point p2 = Point(SphericalPoint(step * (i+1), (M_PI / 2) - steph, radius));
		points.push_back(p1);
		points.push_back(p2);
		points.push_back(top);

		for (int j = 1; j < stacks-1; j++) {
			Point p3 = Point(SphericalPoint(step * i, (M_PI / 2) - steph * (j + 1), radius));
			Point p4 = Point(SphericalPoint(step * (i + 1), (M_PI / 2) - steph * (j + 1), radius));

			points.push_back(p1);
			points.push_back(p3);
			points.push_back(p2);

			points.push_back(p3);
			points.push_back(p4);
			points.push_back(p2);

			p1 = Point(p3.get_x(), p3.get_y(), p3.get_z());
			p2 = Point(p4.get_x(), p4.get_y(), p4.get_z());
		}
		points.push_back(p1);
		points.push_back(bot);
		points.push_back(p2);
	}
	return points;
}