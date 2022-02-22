#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include <GL/gl.h>
#include <variant>
#include <vector>
#include <math.h>
#include "point.hpp"
#include "vector.hpp"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

class CatmullRom {
    private:
        float time;
        std::vector<Point> points;
    public:
        CatmullRom();
        CatmullRom(float,std::vector<Point>);
        void buildRotMatrix(float *, float *, float *, float *);
        void cross(float *, float *, float *);
        void normalize(float *); 
        void multMatrixVector(float[4][4], float*, float *);
        void getCatmullRomPoint(float, Point, Point, Point, Point, float *, float *);
        void getGlobalCatmullRomPoint(float, float *, float *);
        void transform(float);
};

class Translate {
    private:
        float x, y, z;

    public:
        Translate();
        Translate(float, float, float);
        void transform();
};

class Rotate {
    private:
        float angle, x, y, z, time;

    public:
        Rotate();
        Rotate(float, float, float, float,float);
        void transform(float);
};

class Scale {
    private:
        float x, y, z;
    
    public:
        Scale();
        Scale(float, float, float);
        void transform();
};

class Color {
    private:
        float r, g, b;

    public:
        Color();
        Color(float, float, float);
        float getRed();
        float getGreen();
        float getBlue();
        void transform();
};
#endif