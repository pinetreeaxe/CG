#ifndef LIGHTS_H
#define LIGHTS_H

#include "point.hpp"
#include "transformation.hpp"

class PointLight {
  private:
    Point pos;
    Color amb;    
    Color diff;
    Color spec;     
    int number;

  public:
    PointLight(Point, Color, Color, Color, int);
    void turnOn();
};

class DirectionalLight {
  private:
    Point dir;
    Color amb;    
    Color diff;
    Color spec;     
    int number;

  public:
    DirectionalLight(Point, Color, Color, Color, int);
    void turnOn();
};

class SpotLight {
  private:
    Point pos;
    Vector dir;
    Color amb;    
    Color diff;
    Color spec;  
    float exp;
    float cut;
    int number;

  public:
    SpotLight(Point, Color, Color, Color, Vector, float, float, int);
    void turnOn();
};

#endif 