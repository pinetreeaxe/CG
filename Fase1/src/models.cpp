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
#include <random> 


void Model::drawTriangles(Point p1, Point p2, Point p3){
    glColor3f((float) rand() / RAND_MAX, (float) rand() / RAND_MAX, (float) rand() / RAND_MAX);
    glBegin(GL_TRIANGLES);
        glVertex3f(p1.get_x(),p1.get_y(),p1.get_z());
        glVertex3f(p2.get_x(),p2.get_y(),p2.get_z());
        glVertex3f(p3.get_x(),p3.get_y(),p3.get_z());     
    glEnd();           
}

void Model::drawModel(){
    for (int i = 0; i < points.size(); i += 3){
        drawTriangles(points[i], points[i+1], points[i+2]);
    }
}


Model::Model(const char* fileName){
    float x,y,z;
    std::ifstream file(fileName);
        while(file >> x >> y >> z){
            points.push_back(Point(x,y,z));
        }  
}

Models::Models(){
    models = std::vector<Model>();
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
		printf("Scene not found.\n");
		exit(0);
	}

	tinyxml2::XMLNode* type = scene->FirstChild();
	while(type){
		if(!strcmp(type->Value(), "model"))
			models.push_back(Model(type->ToElement()->Attribute("file")));
        if(!strcmp(type->Value(), "translate")){
            float x,y,z;
            if(type->ToElement()->Attribute("X"))
                x = std::stof(type->ToElement()->Attribute("X"));
            else
                x = 0;
            if(type->ToElement()->Attribute("Y"))
                y = std::stof(type->ToElement()->Attribute("Y"));
            else
                y = 0;
            if(type->ToElement()->Attribute("Z"))
                z = std::stof(type->ToElement()->Attribute("Z"));
            else
                z = 0;        
            translations.push_back(Translate(x,y,z));
        }
        if(!strcmp(type->Value(), "rotate")){
            float angle,x,y,z;
            if(type->ToElement()->Attribute("angle"))
                angle = std::stof(type->ToElement()->Attribute("angle"));
            else
                angle = 0;
            if(type->ToElement()->Attribute("axisX"))
                x = std::stof(type->ToElement()->Attribute("axisX"));
            else
                x = 0;
            if(type->ToElement()->Attribute("axisY"))
                y = std::stof(type->ToElement()->Attribute("axisY"));
            else
                y = 0;
            if(type->ToElement()->Attribute("axisZ"))
                z = std::stof(type->ToElement()->Attribute("axisZ"));
            else
                z = 0;        
            rotations.push_back(Rotate(angle,x,y,z));
        }
		
		type = type->NextSibling();
	}

}

void Models::drawModels(){
    for(Translate t: translations)
        t.transform();
    for(Rotate r : rotations)
        r.transform();
    for(Model m: models)
        m.drawModel();
}