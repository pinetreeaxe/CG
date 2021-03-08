#ifndef MODELS_H
#define MODELS_H

#include "point.h"
#include <vector>

class Model {
    private:
        std::vector<Point> points;

    public:
        Model(std::string);
        void drawModel();
        void printValores();
};

class Models {
    private:
        std::vector<Model> models;
    
    public:
        Models();
        Models(std::vector<std::string>);
        void drawModels();
};

#endif