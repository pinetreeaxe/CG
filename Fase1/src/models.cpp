#include <stdlib.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

#include "models.hpp"
#include "tinyxml2.h"
#include <fstream>
#include <iostream>
#include <string>
#include <random> 



void Model::drawTriangles(Point p1, Point p2, Point p3){
    //glColor3f((float) rand() / RAND_MAX, (float) rand() / RAND_MAX, (float) rand() / RAND_MAX);
    glBegin(GL_TRIANGLES);
        glVertex3f(p1.get_x(),p1.get_y(),p1.get_z());
        glVertex3f(p2.get_x(),p2.get_y(),p2.get_z());
        glVertex3f(p3.get_x(),p3.get_y(),p3.get_z());     
    glEnd();           
}

void Model::drawModel(){
    glDrawArrays(GL_TRIANGLES,0,verticesCount);
}


Model::Model(const char* fileName){
    std::vector<float> points = std::vector<float>();
    float x,y,z;
    std::ifstream file(fileName);
        while(file >> x >> y >> z){
            points.push_back(x);
            points.push_back(y);
            points.push_back(z);
        } 
    verticesCount = points.size()/3;
    glGenBuffers(1,&vertices);
    glBindBuffer(GL_ARRAY_BUFFER, vertices);
    glVertexPointer(3,GL_FLOAT,0,0);
	glBufferData(GL_ARRAY_BUFFER,sizeof(float)*points.size(), points.data(),GL_STATIC_DRAW);
}

Models::Models(){
    groups = std::vector<Models>();
    models = std::vector<Model>();
    translation = Translate();
    rotation = Rotate();
    scale = Scale();
    color = Color();
}

Models::Models(std::vector<Models> nGroups, std::vector<Model> nModels, Translate nTranslation, Rotate nRotation, Scale nScale, Color nColor, CatmullRom nCat){
    groups = nGroups;
    models = nModels;
    translation = nTranslation;
    rotation = nRotation;
    scale = nScale;
    color = nColor;
    cat = nCat;
}

std::vector<Point> Models::translationParser(tinyxml2::XMLNode* points){
    std::vector<Point> nPoints = std::vector<Point>();
    tinyxml2::XMLNode* type = points->FirstChild();
    while(type){
		if(!strcmp(type->Value(), "point"))
			nPoints.push_back(Point(std::stof(type->ToElement()->Attribute("X")),
                            std::stof(type->ToElement()->Attribute("Y")),
                            std::stof(type->ToElement()->Attribute("Z"))));
        type = type->NextSibling();
    }
    return nPoints;
}

std::vector<Model> Models::modelsParser(tinyxml2::XMLNode* models){
    std::vector<Model> nModels = std::vector<Model>();
    tinyxml2::XMLNode* type = models->FirstChild();
    while(type){
		if(!strcmp(type->Value(), "model"))
			nModels.push_back(Model(type->ToElement()->Attribute("file")));
        type = type->NextSibling();
    }
    return nModels;
}

Models Models::groupParser(tinyxml2::XMLNode* group, Color gColor){
    std::vector<Models> nGroups = std::vector<Models>(); 
    std::vector<Model> nModels = std::vector<Model>();
    CatmullRom nCat = CatmullRom();
    Translate nTranslation = Translate();
    Rotate nRotation = Rotate();
    Scale nScale = Scale();
    Color nColor = gColor;

    tinyxml2::XMLNode* type = group->FirstChild();
	while(type){
		if(!strcmp(type->Value(), "models")){
            std::vector<Model> auxModels = modelsParser(type);
            for(Model m : auxModels)
                nModels.push_back(m);
        }
        else if(!strcmp(type->Value(), "model"))
			nModels.push_back(Model(type->ToElement()->Attribute("file")));
        else if(!strcmp(type->Value(), "translate")){
            if(type->ToElement()->Attribute("time")){
                std::vector<Point> nPoints = std::vector<Point>();
                float time = std::stof(type->ToElement()->Attribute("time"));
                std::vector<Point> auxPoints = translationParser(type);
                for(Point p : auxPoints)
                    nPoints.push_back(p);
                nCat = CatmullRom(time,nPoints);
            }else{
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
                if(type->ToElement()->Attribute("Z"))
                    z = std::stof(type->ToElement()->Attribute("Z"));
                else
                    z = 0;
                nTranslation = Translate(x,y,z);
            }
        }
        else if(!strcmp(type->Value(), "rotate")){
            float angle,x,y,z,time;
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
            if(type->ToElement()->Attribute("time"))
                time = std::stof(type->ToElement()->Attribute("time"));
            else
                time = 0;
                //a
            nRotation = Rotate(angle,x,y,z,time);
        }
		else if(!strcmp(type->Value(), "scale")){
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
            nScale = Scale(x,y,z);
        }
		else if(!strcmp(type->Value(), "color")){
            float r,g,b;
            if(type->ToElement()->Attribute("R"))
                r = std::stof(type->ToElement()->Attribute("R"));
            else
                r = 0;
            if(type->ToElement()->Attribute("G"))
                g = std::stof(type->ToElement()->Attribute("G"));
            else
                g = 0;
            if(type->ToElement()->Attribute("B"))
                b = std::stof(type->ToElement()->Attribute("B"));
            else
                b = 0;
            nColor = Color(r,g,b);
        }
        else if(!strcmp(type->Value(), "group")){
            nGroups.push_back(groupParser(type, nColor));
        }
		type = type->NextSibling();
	}
    return Models(nGroups, nModels, nTranslation, nRotation, nScale, nColor, nCat);
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

    *this = groupParser(scene, color);
}

void Models::drawModels(float timestamp){    
    translation.transform();
    cat.transform(timestamp);
    rotation.transform(timestamp);
    scale.transform();
    color.transform();
    for(Model m: models)
        m.drawModel();
    for(Models ms: groups){
        glPushMatrix();
        ms.drawModels(timestamp);
        glPopMatrix();
    }
}