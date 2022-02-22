#include "cone.hpp"
#include "point.hpp"
#define _USE_MATH_DEFINES
#include "math.h"

Cone::Cone(int argc, char** argv) {
	radius = std::stof(argv[0]);
	height = std::stof(argv[1]);
	slices = std::stoi(argv[2]);
	stacks = std::stoi(argv[2]);
}

std::vector<Point> Cone::draw() {
	Point center = Point(0, 0, 0);

	Point top = Point(0, height, 0);

	float step = 2 * M_PI / slices;

	std::vector<Point> points;

	for (int i = 0; i < slices; i++) {
		Point p1 = Point(SphericalPoint(step * i, 0, radius));
		Point p2 = Point(SphericalPoint(step * (i+1), 0, radius));

		points.push_back(p1);
		points.push_back(center);
		points.push_back(p2);

		Vector step1 = Vector(top.get_x() - p1.get_x(), top.get_y() - p1.get_y(), top.get_z() - p1.get_z());
		step1.divide(stacks);
		Vector step2 = Vector(top.get_x() - p2.get_x(), top.get_y() - p2.get_y(), top.get_z() - p2.get_z());
		step2.divide(stacks);


		for (int j = 0; j < stacks - 1;j++) {
			Point p3 = Point(p1.get_x(), p1.get_y(), p1.get_z());
			p3.add_vector(step1);
			Point p4 = Point(p2.get_x(), p2.get_y(), p2.get_z());
			p4.add_vector(step2);
			
			points.push_back(p1);
			points.push_back(p2);
			points.push_back(p3);

			points.push_back(p2);
			points.push_back(p4);
			points.push_back(p3);

			p1.set_x(p3.get_x());
			p1.set_y(p3.get_y());
			p1.set_z(p3.get_z());

			p2.set_x(p4.get_x());
			p2.set_y(p4.get_y());
			p2.set_z(p4.get_z());
		}

		points.push_back(p2);
		points.push_back(top);
		points.push_back(p1);

	}
	return points;

}