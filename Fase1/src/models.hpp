#ifndef MODELS_H
#define MODELS_H

#include "point.hpp"
#include <vector>

class Model {
    private:
        std::vector<Point> points;
        void drawTriangles(Point p1, Point p2, Point p3);

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
        void drawModels();
        void readFile(char *);
};

#endif