#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

#include <GL/gl.h>
#include <variant>
#include <vector>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

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
        float angle, x, y, z;

    public:
        Rotate();
        Rotate(float, float, float, float);
        void transform();
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
        void transform();
};
#endif