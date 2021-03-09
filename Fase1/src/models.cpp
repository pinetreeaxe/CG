#include <stdlib.h>
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

Model::Model(const char* fileName){
    float x,y,z;
    std::ifstream file(fileName);
        while(file >> x >> y >> z)
            points.push_back(Point(x,y,z));
}

Models::Models(std::vector<std::string> fileNames){
    printf("Dentro do Models\n");
    for(std::string fileName : fileNames){
        printf("%s\n", fileName);
        //models.push_back(Model(fileName));
    }
    for(Model model: models)
        model.printValores();    
    
}

void Models::readFile(char * fileName){
    tinyxml2::XMLDocument xmlDOC;   

    xmlDOC.LoadFile(fileName);
	if (xmlDOC.ErrorID()){
		printf("%s\n", xmlDOC.ErrorStr());
		exit(0);
	}

    tinyxml2::XMLNode* scene = xmlDOC.FirstChildElement("scene");
	if (scene == NULL){
		printf("Scene not founded.");
		exit(0);
	}

	tinyxml2::XMLNode* model = scene->FirstChild();
	while(model){
		if(!strcmp(model->Value(), "model"))
			models.push_back(Model(model->ToElement()->Attribute("file")));
		model = model->NextSibling();
	}

}