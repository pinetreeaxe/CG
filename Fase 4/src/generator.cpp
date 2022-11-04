#include <stdlib.h>
#include "point.hpp"
#include "box.hpp"
#include "plane.hpp"
#include "sphere.hpp"
#include "cone.hpp"
#include "torus.hpp"
#include "patches.hpp"
#include "normalTexPoint.hpp"

#include<string>
#include<ostream>
#include<iostream>
#include<fstream>

template<typename T>
void writeFile(T primitive, std::string fileName){
    std::ofstream file(fileName);
    for (NormalTexPoint p : primitive.draw()){
        p.to_string();
        file << p.to_string() << "\n";
    }
}

int main(int argc, char** argv){
    std::string primitive(argv[1]);
    if(primitive == "plane")
        writeFile(Plane(argc-3, argv+2), argv[argc-1]);
    else if(primitive == "box")
        writeFile(Box(argc-3, argv+2), argv[argc-1]);
    else if(primitive == "sphere")
        writeFile(Sphere(argc-3, argv+2), argv[argc-1]);
    else if(primitive == "cone")
        writeFile(Cone(argc-3, argv+2), argv[argc-1]);
    else if(primitive == "torus")
        writeFile(Torus(argc-3, argv+2), argv[argc-1]);
    else if(primitive == "patches")
        writeFile(Patches(argc-3, argv+2), argv[argc-1]); 
}