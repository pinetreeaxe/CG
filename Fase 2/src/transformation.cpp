#include "transformation.hpp"

Translate::Translate(){
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
}

Translate::Translate(float xt, float yt, float zt){
    x = xt;
    y = yt;
    z = zt;
}

void Translate::transform(){
    glTranslatef(x,y,z);
}

Rotate::Rotate(){
    angle = 0.0f;
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
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

Scale::Scale(){
    x = 1.0f;
    y = 1.0f;
    z = 1.0f;
}

Scale::Scale(float xt, float yt, float zt){
    x = xt;
    y = yt;
    z = zt;
}

void Scale::transform(){
    glScalef(x,y,z);
}

Color::Color(){
    r = 1.0f;
    g = 1.0f;
    b = 1.0f;
}

Color::Color(float rt, float gt, float bt){
    r = rt;
    g = gt;
    b = bt;
}

void Color::transform(){
    glColor3f(r,g,b);
}