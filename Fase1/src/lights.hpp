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


#endif 