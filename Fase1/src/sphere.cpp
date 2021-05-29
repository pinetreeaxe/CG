#include "sphere.hpp"
#include "point.hpp"
#define _USE_MATH_DEFINES
#include "math.h"

Sphere::Sphere(int argc, char** argv){
	radius = std::stof(argv[0]);
	slices = std::stoi(argv[1]);
	stacks = std::stoi(argv[2]);
}

std::vector<NormalTexPoint2> Sphere::draw() {

	Point top = Point(0, radius, 0);
	Point bot = Point(0, -radius, 0);

	float step = 2 * M_PI / slices;
	float steph = M_PI / stacks;

	std::vector<NormalTexPoint2> points;

	for (int i = 0; i < slices; i++) {
		Point p1 = Point(SphericalPoint(step * i, (M_PI / 2) - steph, radius));
		Point p2 = Point(SphericalPoint(step * (i+1), (M_PI / 2) - steph, radius));
		points.push_back(NormalTexPoint2(p1,Vector(p1.get_x()/radius, p1.get_y()/radius,p1.get_z()/radius),(i*1.0)/slices,((stacks-1)*1.0)/stacks));
		points.push_back(NormalTexPoint2(p2,Vector(p2.get_x()/radius, p2.get_y()/radius,p2.get_z()/radius),((i+1)*1.0)/slices,((stacks-1)*1.0)/stacks));
		points.push_back(NormalTexPoint2(top,Vector(top.get_x()/radius, top.get_y()/radius,top.get_z()/radius),(i*1.0)/slices,1.0));

		for (int j = 1; j < stacks-1; j++) {
			Point p3 = Point(SphericalPoint(step * i, (M_PI / 2) - steph * (j + 1), radius));
			Point p4 = Point(SphericalPoint(step * (i + 1), (M_PI / 2) - steph * (j + 1), radius));

			points.push_back(NormalTexPoint2(p1,Vector(p1.get_x()/radius, p1.get_y()/radius,p1.get_z()/radius),(i*1.0)/slices,((stacks-j)*1.0)/stacks));
			points.push_back(NormalTexPoint2(p3,Vector(p3.get_x()/radius, p3.get_y()/radius,p3.get_z()/radius),(i*1.0)/slices,((stacks-(j+1))*1.0)/stacks));
			points.push_back(NormalTexPoint2(p2,Vector(p2.get_x()/radius, p2.get_y()/radius,p2.get_z()/radius),((i+1)*1.0)/slices,((stacks-j)*1.0)/stacks));

			points.push_back(NormalTexPoint2(p3,Vector(p3.get_x()/radius, p3.get_y()/radius,p3.get_z()/radius),(i*1.0)/slices,((stacks-(j+1))*1.0)/stacks));
			points.push_back(NormalTexPoint2(p4,Vector(p4.get_x()/radius, p4.get_y()/radius,p4.get_z()/radius),((i+1)*1.0)/slices,((stacks-(j+1))*1.0)/stacks));
			points.push_back(NormalTexPoint2(p2,Vector(p2.get_x()/radius, p2.get_y()/radius,p2.get_z()/radius),((i+1)*1.0)/slices,((stacks-j)*1.0)/stacks));

			p1 = Point(p3.get_x(), p3.get_y(), p3.get_z());
			p2 = Point(p4.get_x(), p4.get_y(), p4.get_z());
		}
		points.push_back(NormalTexPoint2(p1,Vector(p1.get_x()/radius, p1.get_y()/radius,p1.get_z()/radius),(i*1.0)/slices,1.0/stacks));
		points.push_back(NormalTexPoint2(bot,Vector(bot.get_x()/radius, bot.get_y()/radius,bot.get_z()/radius),(i*1.0)/slices,1.0));
		points.push_back(NormalTexPoint2(p2,Vector(p2.get_x()/radius, p2.get_y()/radius,p2.get_z()/radius),((i+1)*1.0)/slices,1.0/stacks));
	}
	return points;
}