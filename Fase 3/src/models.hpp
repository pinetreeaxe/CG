#ifndef MODELS_H
#define MODELS_H

#include "transformation.hpp"
#include "point.hpp"
#include "tinyxml2.h"
#include <vector>

class Model {
    private:
        GLuint vertices[1];
        int verticesCount;

    public:
        Model(const char *);
        void drawModel();
};

class Models {
    private:
        std::vector<Models> groups;
        std::vector<Model> models;
        Translate translation;
        Rotate rotation;
        Scale scale;
        Color color;
        CatmullRom cat;
    
    public:
        Models();
        Models(std::vector<Models>, std::vector<Model>, Translate, Rotate, Scale, Color, CatmullRom);
        void drawModels(float);
        void readFile(char *);
        Models groupParser(tinyxml2::XMLNode*, Color);
        std::vector<Point> translationParser(tinyxml2::XMLNode*);
        std::vector<Model> modelsParser(tinyxml2::XMLNode*);
};

#endif