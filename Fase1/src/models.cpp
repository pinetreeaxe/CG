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
    printf("Dentro do model: %s\n",fileName);
    float x,y,z;
    std::ifstream file(fileName);
    //Está a ler o ficheiro mas está todo errado ao ler o conteúdo do ficheiro
    if(file.is_open())
        while(file >> x >> y >> z){
            printf("%d %d %d\n", x,y,z );
            points.push_back(Point(x,y,z));
        }
    else
        printf("Não está a ler o ficheiro bem\n");

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
		if(!strcmp(model->Value(), "model")){
			//model->ToElement()->Attribute("file") devolve um Const char *
			//size_t  lenModel = strlen(model->ToElement()->Attribute("file"));
			//char * test2 = new char[lenModel + 1];
			//strcpy(test2, model->ToElement()->Attribute("file"));
			//printf("Tamanho: %d\n",lenModel);
			//printf("Test2: %s\n",test2);
			std::string test(model->ToElement()->Attribute("file"));
            //CONVERSÃO DE CONST CHAR * PARA STRING FICA TODO ERRADO
            printf("Teste: %s\n", test);
            printf("Teste correctly: %s\n",test.c_str());
			printf("XML: %s\n",model->ToElement()->Attribute("file"));
			models.push_back(Model(model->ToElement()->Attribute("file")));
			
		}
		model = model->NextSibling();
	}

}