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


void Model::drawModel(){
    glBindBuffer(GL_ARRAY_BUFFER,buffers[0]);
	glVertexPointer(3,GL_FLOAT,0,0);
	glBindBuffer(GL_ARRAY_BUFFER, buffers[1]);
	glNormalPointer(GL_FLOAT, 0, 0);
	glDrawArrays(GL_TRIANGLES, 0, verticesCount);
}


Model::Model(const char* fileName){
    std::vector<float> points = std::vector<float>();
    std::vector<float> normals = std::vector<float>();
    float x,y,z,nx,ny,nz;
    std::ifstream file(fileName);
    int vertex = 0;
    while(file >> x >> y >> z >> nx >> ny >> nz){
        points.push_back(x);
        points.push_back(y);
        points.push_back(z);
        normals.push_back(nx);
        normals.push_back(ny);
        normals.push_back(nz);
        vertex++;
    } 
    verticesCount = vertex;
    glGenBuffers(2, buffers);
	glBindBuffer(GL_ARRAY_BUFFER,buffers[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * verticesCount * 3, points.data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, buffers[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)* verticesCount * 3, normals.data(), GL_STATIC_DRAW);
}

Models::Models(){
    groups = std::vector<Models>();
    models = std::vector<Model>();
    translation = Translate();
    rotation = Rotate();
    scale = Scale();
    color = Color();
}

Models::Models(std::vector<Models> nGroups, std::vector<Model> nModels, std::vector<PointLight> pls, Translate nTranslation, Rotate nRotation, Scale nScale, Color nColor, CatmullRom nCat){
    groups = nGroups;
    models = nModels;
    pointLights = pls;
    translation = nTranslation;
    rotation = nRotation;
    scale = nScale;
    color = nColor;
    cat = nCat;
}

void Models::lightsParser(tinyxml2::XMLNode* points, std::vector<PointLight> *pls){
    tinyxml2::XMLNode* type = points->FirstChild();
    int number = 0;
    while(type){
		if(!strcmp(type->Value(), "light")){
            if(!strcmp(type->ToElement()->Attribute("type"), "POINT")){
                Point pos = Point(std::stof(type->ToElement()->Attribute("posX")),
                                std::stof(type->ToElement()->Attribute("posY")),
                                std::stof(type->ToElement()->Attribute("posZ")));
                Color amb = Color(0.2f,0.2f,0.2f);
                Color diff = Color(1.0f,1.0f,1.0f);
                Color spec = Color(1.0f,1.0f,1.0f);

                if(type->ToElement()->Attribute("ambR")){
                    amb = Color(std::stof(type->ToElement()->Attribute("ambR")),
                                std::stof(type->ToElement()->Attribute("posG")),
                                std::stof(type->ToElement()->Attribute("posB")));
                }
                if(type->ToElement()->Attribute("diffR")){
                    diff = Color(std::stof(type->ToElement()->Attribute("diffR")),
                                std::stof(type->ToElement()->Attribute("diffG")),
                                std::stof(type->ToElement()->Attribute("diffB")));
                }
                if(type->ToElement()->Attribute("diffR")){
                    diff = Color(std::stof(type->ToElement()->Attribute("diffR")),
                                std::stof(type->ToElement()->Attribute("diffG")),
                                std::stof(type->ToElement()->Attribute("diffB")));
                }
                if(type->ToElement()->Attribute("specR")){
                    diff = Color(std::stof(type->ToElement()->Attribute("specR")),
                                std::stof(type->ToElement()->Attribute("specG")),
                                std::stof(type->ToElement()->Attribute("specB")));
                }
                (*pls).push_back(PointLight(pos,amb,diff,spec,number));
                number++;
            }
        }
        type = type->NextSibling();
    }
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
    std::vector<PointLight> pls = std::vector<PointLight>();
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
        else if(!strcmp(type->Value(), "lights")){
            lightsParser(type,&pls);
        }
        else if(!strcmp(type->Value(), "group")){
            nGroups.push_back(groupParser(type, nColor));
        }
		type = type->NextSibling();
	}
    return Models(nGroups, nModels, pls, nTranslation, nRotation, nScale, nColor, nCat);
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
    /*if(pointLights.size()>0){
        glEnable(GL_LIGHTING);
    }*/
    for(PointLight pl : pointLights)
        pl.turnOn();
    for(Model m: models)
        m.drawModel();
    for(Models ms: groups){
        glPushMatrix();
        ms.drawModels(timestamp);
        glPopMatrix();
    }
}