#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "models.hpp"
#include "tinyxml2.h"
#include <fstream>
#include <iostream>
#include <string>



void Model::drawModel(){

}

void Models::drawModels(){

}


Models::Models(){
    models = std::vector<Model>();
}

void Model::printValores(){
    for(Point point: points)
        point.to_string();
}

Model::Model(std::string fileName){
    float x,y,z;
    std::ifstream file(fileName);
    
    while(file >> x >> y >> z){
        printf("%d %d %d\n", x,y,z );
        points.push_back(Point(x,y,z));
    }
}

Models::Models(std::vector<std::string> fileNames){
    printf("Dentro do Models\n");
    for(std::string fileName : fileNames){
        printf("%s\n", fileName);
        models.push_back(Model(fileName));
    }
    for(Model model: models)
        model.printValores();    
    
}