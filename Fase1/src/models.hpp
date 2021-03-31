#ifndef MODELS_H
#define MODELS_H

#include "transformation.hpp"
#include "point.hpp"
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
        std::vector<Model> models;
        std::vector<Translate> translations;
        std::vector<Rotate> rotations;
        std::vector<Scale> scales;
    
    public:
        Models();
        void drawModels();
        void readFile(char *);
};

#endif