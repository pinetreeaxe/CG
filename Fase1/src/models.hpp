#ifndef MODELS_H
#define MODELS_H

#include "transformation.hpp"
#include "point.hpp"
#include "tinyxml2.h"
#include <vector>

class Model {
    private:
        std::vector<Point> points;
        void drawTriangles(Point p1, Point p2, Point p3);

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
    
    public:
        Models();
        Models(std::vector<Models>, std::vector<Model>, Translate, Rotate, Scale, Color);
        void drawModels();
        void readFile(char *);
        Models groupParser(tinyxml2::XMLNode*, Color);
        std::vector<Model> modelsParser(tinyxml2::XMLNode*);
};

#endif