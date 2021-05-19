#include "box.hpp"
#include "point.hpp"
#include "normalTexPoint.hpp"

Box::Box(int argc, char** argv) {
    x = std::stof(argv[0]);
    y = std::stof(argv[1]);
    z = std::stof(argv[2]);
    if (argc < 4)
        div = 1;
    else
        div = std::stoi(argv[3]) + 1;
}

void Box::draw_face(std::vector<NormalTexPoint>& points, Point o, Vector v1, Vector v2, Vector normal) const {
    //creating the points from the two triangles on the bottom left corner of the face
    Point p0 = Point(o.get_x(), o.get_y(), o.get_z());
    Point p1 = Point(p0.get_x(), p0.get_y(), p0.get_z());
    p1.add_vector(v1);
    Point p2 = Point(p0.get_x(), p0.get_y(), p0.get_z());
    p2.add_vector(v2);
    Point p3 = Point(p0.get_x(), p0.get_y(), p0.get_z());
    p3.add_vector(v1);
    p3.add_vector(v2);

    //itera sobre as "colunas"
    for (int i = 0; i < div; i++) {
        Point p0i = Point(p0.get_x(), p0.get_y(), p0.get_z());
        Point p1i = Point(p1.get_x(), p1.get_y(), p1.get_z());
        Point p2i = Point(p2.get_x(), p2.get_y(), p2.get_z());
        Point p3i = Point(p3.get_x(), p3.get_y(), p3.get_z());

        //itera sobre as "linhas"
        for (int j = 0; j < div; j++) {

            NormalTexPoint p0j = NormalTexPoint(p0i,normal);
            NormalTexPoint p1j = NormalTexPoint(p1i,normal);
            NormalTexPoint p2j = NormalTexPoint(p2i,normal);
            NormalTexPoint p3j = NormalTexPoint(p3i,normal);

            //1st triangle 
            points.push_back(p0j);
            points.push_back(p1j);
            points.push_back(p2j);

            //front triangle
            points.push_back(p2j);
            points.push_back(p1j);
            points.push_back(p3j);

            //translate all points to the next slice ("horizontally")
            p0i.add_vector(v1);
            p1i.add_vector(v1);
            p2i.add_vector(v1);
            p3i.add_vector(v1);
        }

        //translate all points to the next slice ("vertically")
        p0.add_vector(v2);
        p1.add_vector(v2);
        p2.add_vector(v2);
        p3.add_vector(v2);
    }
}

std::vector<NormalTexPoint> Box::draw() const {
    float halfx = x / 2;
    float halfy = y / 2;
    float halfz = z / 2;

    float slicex = x / div;
    float slicey = y / div;
    float slicez = z / div;

    std::vector<NormalTexPoint> points;

    // front face
    draw_face(points, Point(-halfx, -halfy, halfz), Vector(slicex, 0, 0), Vector(0, slicey, 0),Vector(0,0,1));

    // back face
    draw_face(points, Point(halfx, -halfy, -halfz), Vector(-slicex, 0, 0), Vector(0, slicey, 0),Vector(0,0,-1));

    // left face
    draw_face(points, Point(-halfx, -halfy, -halfz), Vector(0, 0, slicez), Vector(0, slicey, 0),Vector(-1,0,0));

    // right face
    draw_face(points, Point(halfx, -halfy, halfz), Vector(0, 0, -slicez), Vector(0, slicey, 0),Vector(1,0,0));

    // top face
    draw_face(points, Point(-halfx, halfy, halfz), Vector(slicex, 0, 0), Vector(0, 0, -slicez),Vector(0,1,0));

    // bottom face
    draw_face(points, Point(-halfx, -halfy, -halfz), Vector(slicex, 0, 0), Vector(0, 0, slicez),Vector(0,-1,0));


    return points;
}