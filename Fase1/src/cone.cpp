#include "cone.hpp"
#include "point.hpp"
#include "normalTexPoint.hpp"
#define _USE_MATH_DEFINES
#include "math.h"

Cone::Cone(int argc, char** argv) {
	radius = std::stof(argv[0]);
	height = std::stof(argv[1]);
	slices = std::stoi(argv[2]);
	stacks = std::stoi(argv[3]);
}

std::vector<NormalTexPoint> Cone::draw() {
	Point center = Point(0, 0, 0);

	Point top = Point(0, height, 0);

	float step = 2 * M_PI / slices;

	std::vector<NormalTexPoint> points;

	for (int i = 0; i < slices; i++) {
		Point p1 = Point(SphericalPoint(step * i, 0, radius));
		Point p2 = Point(SphericalPoint(step * (i+1), 0, radius));

		points.push_back(NormalTexPoint(p1,Vector(0,-1,0)));
		points.push_back(NormalTexPoint(center,Vector(0,-1,0)));
		points.push_back(NormalTexPoint(p2,Vector(0,-1,0)));

		Vector step1 = Vector(top.get_x() - p1.get_x(), top.get_y() - p1.get_y(), top.get_z() - p1.get_z());
		step1.divide(stacks);
		Vector step2 = Vector(top.get_x() - p2.get_x(), top.get_y() - p2.get_y(), top.get_z() - p2.get_z());
		step2.divide(stacks);
		Vector normal = Vector(sin((i+0.5)*step),height/stacks,cos((i+0.5)*step));

		for (int j = 0; j < stacks - 1;j++) {
			Point p3 = Point(p1.get_x(), p1.get_y(), p1.get_z());
			p3.add_vector(step1);
			Point p4 = Point(p2.get_x(), p2.get_y(), p2.get_z());
			p4.add_vector(step2);
			
			points.push_back(NormalTexPoint(p1,normal));
			points.push_back(NormalTexPoint(p2,normal));
			points.push_back(NormalTexPoint(p3,normal));

			points.push_back(NormalTexPoint(p2,normal));
			points.push_back(NormalTexPoint(p4,normal));
			points.push_back(NormalTexPoint(p3,normal));

			p1.set_x(p3.get_x());
			p1.set_y(p3.get_y());
			p1.set_z(p3.get_z());

			p2.set_x(p4.get_x());
			p2.set_y(p4.get_y());
			p2.set_z(p4.get_z());
		}

		points.push_back(NormalTexPoint(p2,normal));
		points.push_back(NormalTexPoint(top,normal));
		points.push_back(NormalTexPoint(p1,normal));

	}
	return points;

}