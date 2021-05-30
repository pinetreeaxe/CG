#define _USE_MATH_DEFINES
#include "math.h"
#include <fstream>
#include "patches.hpp"

Patches::Patches(int argc, char** argv) {
    std::ifstream file(argv[0]);
	tesselationLevel = std::stoi(argv[1]);
    file >> numPatches;

    int i = 0;
    indices = std::vector<std::vector<int>>();

    while(i<numPatches){
        std::vector<int> indice = std::vector<int>();
        bool nextLine = false;
        while(!nextLine){ 
            int num;
            file >> num;
            indice.push_back(num);
            if(file.peek() == ',' || file.peek() == ' ') file.ignore();
            if(file.peek() == '\n') nextLine = true;
        }
        indices.push_back(indice);
        i++;
    }
    
    file >> numControlPoints;

    controlPoints = std::vector<Point>();
    i=0;
    while(i<numControlPoints){
        float p[3] = {};
        int found = 0;
        while(found != 3){ 
            file >> p[found];
            found++;
            if(file.peek() == ',' || file.peek() == ' ' || file.peek() == '\n')
                file.ignore();
        }
        controlPoints.push_back(Point(p[0],p[1],p[2]));
        i++;
    }
    
}

void cross(float *a, float *b, float *res) {

	res[0] = a[1]*b[2] - a[2]*b[1];
	res[1] = a[2]*b[0] - a[0]*b[2];
	res[2] = a[0]*b[1] - a[1]*b[0];
}


void normalize(float *a) {

	float l = sqrt(a[0]*a[0] + a[1] * a[1] + a[2] * a[2]);
	a[0] = a[0]/l;
	a[1] = a[1]/l;
	a[2] = a[2]/l;
}

void Patches::multMatrixVector(float m[4][4], float *v, float *res) {

	for (int j = 0; j < 4; ++j) {
		res[j] = 0;
		for (int k = 0; k < 4; ++k) {
			res[j] += v[k] * m[j][k];
		}
	}
}

Vector Patches::getNormal(std::vector<Point> patch, float u, float v){
    // Bezier matrix
	float m[4][4] = {{-1.0f, +3.0f, -3.0f, +1.0f},
                    {+3.0f, -6.0f, +3.0f, +0.0f},
                    {-3.0f, +3.0f, +0.0f, +0.0f},
                    {+1.0f, +0.0f, +0.0f, +0.0f}};
    float tu[4] = {u*u*u,u*u,u,1.0f};
    float dtu[4] = {3*u*u,2*u,1.0f,0.0f};
    float tv[4] = {v*v*v,v*v,v,1.0f};
    float dtv[4] = {3*v*v,2*v,1.0f,0.0f};
    float duvm[4] = {};
    multMatrixVector(m,dtu,duvm);
    Point duvmvp[4] = {};
    for (int i = 0; i < 4; i++){
        duvmvp[i] = Point(0,0,0);
    }
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            Point p = patch[j*4+i];
            duvmvp[i] = Point(duvmvp[i].get_x()+p.get_x()*duvm[j],duvmvp[i].get_y()+p.get_y()*duvm[j], duvmvp[i].get_z()+p.get_z()*duvm[j]);
        }
    }
    float mvv[4];
    multMatrixVector(m,tv,mvv);
    float fu[3] = {0};
    for (int i = 0; i < 4; i++){
        fu[0] = fu[0] + duvmvp[i].get_x()*mvv[i];
        fu[1] = fu[1] + duvmvp[i].get_y()*mvv[i];
        fu[2] = fu[2] + duvmvp[i].get_z()*mvv[i]; 
    }

    float uvm[4] = {};
    multMatrixVector(m,tu,uvm);
    Point uvmvp[4] = {};
    for (int i = 0; i < 4; i++){
        uvmvp[i] = Point(0,0,0);
    }
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            Point p = patch[j*4+i];
            uvmvp[i] = Point(uvmvp[i].get_x()+p.get_x()*uvm[j],uvmvp[i].get_y()+p.get_y()*uvm[j], uvmvp[i].get_z()+p.get_z()*uvm[j]);
        }
    }
    float mvdv[4] = {};
    multMatrixVector(m,dtv,mvdv);
    float fv[3] = {0};
    for (int i = 0; i < 4; i++){
        fv[0] = fv[0] + uvmvp[i].get_x()*mvdv[i];
        fv[1] = fv[1] + uvmvp[i].get_y()*mvdv[i];
        fv[2] = fv[2] + uvmvp[i].get_z()*mvdv[i]; 
    }

    float normal[3] = {};
    cross(fv,fu,normal);
    normalize(normal);
    return Vector(normal[0], normal[1], normal[2]);
}

void Patches::getBezierPoint(float t, Point p0, Point p1, Point p2, Point p3, float *pos) {

	// Bezier matrix
	float m[4][4] = {{-1.0f, +3.0f, -3.0f, +1.0f},
                    {+3.0f, -6.0f, +3.0f, +0.0f},
                    {-3.0f, +3.0f, +0.0f, +0.0f},
                    {+1.0f, +0.0f, +0.0f, +0.0f}};

	float tv[4] = { t * t * t,t * t,t,1 };
	float dtv[4] = { 3*t * t ,2*t ,1,0 };

    float p0a[3] = {p0.get_x(),p0.get_y(),p0.get_z()};
    float p1a[3] = {p1.get_x(),p1.get_y(),p1.get_z()};
    float p2a[3] = {p2.get_x(),p2.get_y(),p2.get_z()};
    float p3a[3] = {p3.get_x(),p3.get_y(),p3.get_z()};

	for (int i = 0; i < 3; i++)
	{
		float p[4] = { p0a[i],p1a[i],p2a[i],p3a[i] };
		float a[4];
		// Compute A = M * P
		multMatrixVector(m, p, a);
		// Compute pos = T * A
		pos[i] = 0;
		for (int j = 0; j < 4; j++) {
			pos[i] += tv[j] * a[j];
		}
	}
}

NormalTexPoint2 Patches::getGlobalBezierPoint(int patchNum, float u, float v, float texX, float texY) {

    std::vector<Point> patch = std::vector<Point>();
    std::vector<int> patchPoints = indices[patchNum];
    
    for(int i=0; i<patchPoints.size();i++)
        patch.push_back(controlPoints[patchPoints[i]]);

    Vector normal = getNormal(patch,u,v);

    std::vector<Point> bezierPoints;
    for (int i = 0;i < patch.size();i += 4) {
        float p[3] = {};
        getBezierPoint(u, patch[i], patch[i+1], patch[i+2], patch[i+3],p);
        bezierPoints.push_back(Point(p[0],p[1],p[2]));
    }

    float pos[3] = {};

	getBezierPoint(v, bezierPoints[0], bezierPoints[1], bezierPoints[2], bezierPoints[3], pos);

    return NormalTexPoint2(Point(pos[0],pos[1],pos[2]),normal,texX,texY);
}

std::vector<NormalTexPoint2> Patches::draw(){
    std::vector<NormalTexPoint2> points;
    float step = 1.0f / tesselationLevel;
    for (int i = 0; i < numPatches; i++) {
        
        for (int j = 0; j < tesselationLevel; j++) {
            
            float u = j * step;
            float nextU = (j+ 1) * step;

            for (int k = 0; k < tesselationLevel; k++) {
            
                float v = k * step;
                float nextV = (k + 1) * step;

                
                NormalTexPoint2 p0 = getGlobalBezierPoint(i, u, v,j*step,k*step);
                NormalTexPoint2 p1 = getGlobalBezierPoint(i, u, nextV,j*step,(k+1)*step);
                NormalTexPoint2 p2 = getGlobalBezierPoint(i, nextU, v,(j+1)*step,k*step);
                NormalTexPoint2 p3 = getGlobalBezierPoint(i, nextU, nextV,(j+1)*step,(k+1)*step);
                
                points.push_back(p3);
                points.push_back(p2);
                points.push_back(p1);

                points.push_back(p2);
                points.push_back(p0);
                points.push_back(p1);
            
            }
        }
    }

    return points;
}
