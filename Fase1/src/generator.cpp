#include <stdlib.h>
#include "point.hpp"
#include "box.hpp"
#include "plane.hpp"
#include "sphere.hpp"
#include "cone.hpp"
#include "torus.hpp"
#include "patches.hpp"
#include "normalTexPoint.hpp"
#include "uga.hpp"

#include<string>
#include<ostream>
#include<iostream>
#include<fstream>

template<typename T>
void writeFile(T primitive, std::string fileName){
    std::ofstream file(fileName);
    for (Point p : primitive.draw()){
        p.to_string();
        file << p.to_string() << "\n";
    }
}


template<typename T>
void writeFileNew2(T primitive, std::string fileName){
    std::ofstream file(fileName);
    for (NormalTexPoint2 p : primitive.draw()){
        p.to_string();
        file << p.to_string() << "\n";
    }
}

int main(int argc, char** argv){
    std::string primitive(argv[1]);
    if(primitive == "plane")
        writeFileNew2(Plane(argc-3, argv+2), argv[argc-1]);
    else if(primitive == "box")
        writeFileNew2(Box(argc-3, argv+2), argv[argc-1]);
    else if(primitive == "sphere")
        writeFileNew2(Sphere(argc-3, argv+2), argv[argc-1]);
    else if(primitive == "cone")
        writeFileNew2(Cone(argc-3, argv+2), argv[argc-1]);
    else if(primitive == "torus")
        writeFileNew2(Torus(argc-3, argv+2), argv[argc-1]);
    else if(primitive == "patches")
        writeFileNew2(Patches(argc-3, argv+2), argv[argc-1]); 
}