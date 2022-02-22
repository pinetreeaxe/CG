#ifndef MODELS_H
#define MODELS_H

#include "transformation.hpp"
#include "point.hpp"
#include "lights.hpp"
#include "tinyxml2.h"
#include <vector>

class Model {
    private:
        GLuint buffers[3];
        int verticesCount;
        int texture;
        Color amb;
        Color diff;
        Color spec;
        Color emiss;


    public:
        Model(const char *,std::string,Color,Color,Color,Color);
        void drawModel();
        int loadTexture(std::string);
};

class Models {
    private:
        std::vector<Models> groups;
        std::vector<Model> models;
        std::vector<PointLight> pointLights;
        std::vector<DirectionalLight> dirLights;
        std::vector<SpotLight> spotLights;
        Translate translation;
        Rotate rotation;
        Scale scale;
        Color color;
        CatmullRom cat;
    
    public:
        Models();
        Models(std::vector<Models>, std::vector<Model>,std::vector<PointLight>, std::vector<DirectionalLight>,std::vector<SpotLight>, Translate, Rotate, Scale, Color, CatmullRom);
        void drawModels(float);
        void readFile(char *);
        Models groupParser(tinyxml2::XMLNode*, Color);
        std::vector<Point> translationParser(tinyxml2::XMLNode*);
        std::vector<Model> modelsParser(tinyxml2::XMLNode*);
        void lightsParser(tinyxml2::XMLNode*, std::vector<PointLight>*, std::vector<DirectionalLight> *, std::vector<SpotLight>*);
};

#endif