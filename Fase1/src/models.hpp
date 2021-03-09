#ifndef MODELS_H
#define MODELS_H

#include "point.hpp"
#include <vector>

class Model {
    private:
        std::vector<Point> points;

    public:
        Model(const char *);
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
        void readFile(char *);
};

#endif