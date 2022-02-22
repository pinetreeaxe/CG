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
    float px[4][4];
    float py[4][4];
    float pz[4][4];
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            Point p = patch[i*4+j];
            px[i][j] = p.get_x();
            py[i][j] = p.get_y();
            pz[i][j] = p.get_z();
        }
    }
    float tu[4] = {u*u*u, u*u, u, 1.0f}; 
    float dtu[4] = {3.0f*u*u, 2.0f*u, 1.0f, 0.0f};
    float tv[4] = {v*v*v, v*v, v, 1.0f};
    float dtv[4] = {3.0f*v*v, 2.0f*v, 1.0f, 0.0f};
    float ax[4];
    float ay[4];
    float az[4];
    float fu[3];
    float fv[3];
    
    float mvv[4];
    multMatrixVector(m,tv,mvv);
    multMatrixVector(px,mvv,ax);
    multMatrixVector(py,mvv,ay);
    multMatrixVector(pz,mvv,az);
    fu[0] = (ax[0]*dtu[0])+(ax[1]*dtu[1])+(ax[2]*dtu[2])+(ax[3]*dtu[3]);
    fu[1] = (ay[0]*dtu[0])+(ay[1]*dtu[1])+(ay[2]*dtu[2])+(ay[3]*dtu[3]);
    fu[2] = (az[0]*dtu[0])+(az[1]*dtu[1])+(az[2]*dtu[2])+(az[3]*dtu[3]);

    float mvdv[4];
    multMatrixVector(m,dtv,mvdv);
    multMatrixVector(px,mvdv,ax);
    multMatrixVector(py,mvdv,ay);
    multMatrixVector(pz,mvdv,az);
    fv[0] = (ax[0]*tu[0])+(ax[1]*tu[1])+(ax[2]*tu[2])+(ax[3]*tu[3]);
    fv[1] = (ay[0]*tu[0])+(ay[1]*tu[1])+(ay[2]*tu[2])+(ay[3]*tu[3]);
    fv[2] = (az[0]*tu[0])+(az[1]*tu[1])+(az[2]*tu[2])+(az[3]*tu[3]);  

    float normal[3] = {};
    normalize(fu);
    normalize(fv);
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

	float tv[4] = { t * t * t, t * t, t, 1 };
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

NormalTexPoint Patches::getGlobalBezierPoint(int patchNum, float u, float v) {

    std::vector<Point> patch = std::vector<Point>();
    std::vector<int> patchPoints = indices[patchNum];
    
    for(int i=0; i<patchPoints.size();i++)
        patch.push_back(controlPoints[patchPoints[i]]);

    std::vector<Point> bezierPoints;
    for (int i = 0;i < patch.size();i += 4) {
        float p[3] = {};
        getBezierPoint(u, patch[i], patch[i+1], patch[i+2], patch[i+3],p);
        bezierPoints.push_back(Point(p[0],p[1],p[2]));
    }

    float pos[3] = {};

	getBezierPoint(v, bezierPoints[0], bezierPoints[1], bezierPoints[2], bezierPoints[3], pos);
    Vector normal = getNormal(patch,u,v);

    return NormalTexPoint(Point(pos[0],pos[1],pos[2]),normal,u,v);
}

std::vector<NormalTexPoint> Patches::draw(){
    std::vector<NormalTexPoint> points;
    float step = 1.0f / tesselationLevel;
    for (int i = 0; i < numPatches; i++) {
        
        for (int j = 0; j < tesselationLevel; j++) {
            
            float u = j * step;
            float nextU = (j+ 1) * step;

            for (int k = 0; k < tesselationLevel; k++) {
            
                float v = k * step;
                float nextV = (k + 1) * step;

                
                NormalTexPoint p0 = getGlobalBezierPoint(i, u, v);
                NormalTexPoint p1 = getGlobalBezierPoint(i, u, nextV);
                NormalTexPoint p2 = getGlobalBezierPoint(i, nextU, v);
                NormalTexPoint p3 = getGlobalBezierPoint(i, nextU, nextV);
                
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
