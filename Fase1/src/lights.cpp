#include "lights.hpp"

GLenum getLight(int num){
    GLenum ans;
    switch (num)
    {
    case 0:
        ans = GL_LIGHT0;
        break;

    case 1:
        ans = GL_LIGHT1;
        break;

    case 2:
        ans = GL_LIGHT2;
        break;

    case 3:
        ans = GL_LIGHT3;
        break;

    case 4:
        ans = GL_LIGHT4;
        break;

    case 5:
        ans = GL_LIGHT5;
        break;

    case 6:
        ans = GL_LIGHT6;
        break;
    
    default:
        ans = GL_LIGHT7;
        break;
    }
    return ans;
}

PointLight::PointLight(Point p, Color a, Color d, Color s, int id){
    pos = p;
    amb = a;
    diff = d;
    spec = s;
    number = id;
}

void PointLight::turnOn(){

    GLfloat position[4] = {pos.get_x(), pos.get_y(), pos.get_z(),0.0f};
    GLfloat ambient[4] = {amb.getRed(), amb.getGreen(), amb.getBlue(),1.0f};
    GLfloat diffuse[4] = {diff.getRed(), diff.getGreen(), diff.getBlue(),1.0f};
    GLfloat specular[4] = {spec.getRed(), spec.getGreen(), spec.getBlue(),1.0f};
    GLenum light = getLight(number);
    
    glEnable(light);
    glLightfv(light, GL_AMBIENT, ambient);
    glLightfv(light, GL_DIFFUSE, diffuse);
    glLightfv(light, GL_SPECULAR, specular);
    glLightfv(light, GL_POSITION, position);

}