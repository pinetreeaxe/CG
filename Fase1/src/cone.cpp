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

		points.push_back(NormalTexPoint(p1,Vector(0,-1,0),0.8125+0.1875 * sin(i * step),0.1875+0.1875 * sin(i * step)));
		points.push_back(NormalTexPoint(center,Vector(0,-1,0),0.8125,0.1875));
		points.push_back(NormalTexPoint(p2,Vector(0,-1,0),0.8125+0.1875 * sin((i+1) * step),0.1875+0.1875 * sin((i+1) * step)));

		Vector step1 = Vector(sin(i*step)*(radius/stacks)*(-1), height/stacks, cos(i*step)*(radius/stacks)*(-1));
		Vector step2 = Vector(sin((i+1)*step)*(radius/stacks)*(-1), height/stacks, cos((i+1)*step)*(radius/stacks)*(-1));
		Vector normal1 = Vector(sin(i*step)*(height/stacks), radius/stacks, cos(i*step)*(height/stacks));
		Vector normal2 = Vector(sin((i+1)*step)*(height/stacks), radius/stacks, cos((i+1)*step)*(height/stacks));

		for (int j = 0; j < stacks;j++) {
			Point p3 = Point(p1.get_x(), p1.get_y(), p1.get_z());
			p3.add_vector(step1);
			Point p4 = Point(p2.get_x(), p2.get_y(), p2.get_z());
			p4.add_vector(step2);
			
			points.push_back(NormalTexPoint(p1,normal1,(i*1.0)/slices,0.375+(j*((1-0.375)/stacks))));
			points.push_back(NormalTexPoint(p2,normal2,((i+1)*1.0)/slices,0.375+(j*((1-0.375)/stacks))));
			points.push_back(NormalTexPoint(p3,normal1,(i*1.0)/slices,0.375+((j+1)*((1-0.375)/stacks))));

			points.push_back(NormalTexPoint(p2,normal2,((i+1)*1.0)/slices,0.375+(j*((1-0.375)/stacks))));
			points.push_back(NormalTexPoint(p4,normal1,((i+1)*1.0)/slices,0.375+((j+1)*((1-0.375)/stacks))));
			points.push_back(NormalTexPoint(p3,normal1,(i*1.0)/slices,0.375+((j+1)*((1-0.375)/stacks))));

			p1.set_x(p3.get_x());
			p1.set_y(p3.get_y());
			p1.set_z(p3.get_z());

			p2.set_x(p4.get_x());
			p2.set_y(p4.get_y());
			p2.set_z(p4.get_z());
		}

		/*points.push_back(NormalTexPoint(p2,normal2));
		points.push_back(NormalTexPoint(top,normal2));
		points.push_back(NormalTexPoint(p1,normal1));*/

	}
	return points;
}