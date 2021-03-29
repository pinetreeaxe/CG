#include "transformation.hpp"

Translate::Translate(float xt, float yt, float zt){
    x = xt;
    y = yt;
    z = zt;
}

void Translate::transform(){
    glTranslatef(x,y,z);
}

Rotate::Rotate(float anglet, float xt, float yt, float zt){
    angle = anglet;
    x = xt;
    y = yt;
    z = zt;
}

void Rotate::transform(){
    glRotatef(angle,x,y,z);
}

Transformation::Transformation(Translate transl){
    t = transl;
}

Transformation::Transformation(Rotate rot){
    t = rot;
}