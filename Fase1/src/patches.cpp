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

void Patches::multMatrixVector(float m[4][4], float *v, float *res) {

	for (int j = 0; j < 4; ++j) {
		res[j] = 0;
		for (int k = 0; k < 4; ++k) {
			res[j] += v[k] * m[j][k];
		}
	}
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

Point Patches::getGlobalBezierPoint(int patchNum, float u, float v) {

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

    return Point(pos[0],pos[1],pos[2]);
}

Vector Patches::crossVectors(Vector a, Vector b) {
    float x = a.get_y()*b.get_z() - a.get_z()*b.get_y();
    float y = a.get_z()*b.get_x() - a.get_x()*b.get_z();
    float z = a.get_x()*b.get_y() - a.get_y()*b.get_x();
	return Vector(x,y,z);
}

std::vector<Point> Patches::draw(){
    std::vector<Point> points;
    float step = 1.0f / tesselationLevel;

    for (int i = 0; i < numPatches; i++) {
        
        for (int j = 0; j < tesselationLevel; j++) {
            
            float u = j * step;
            float nextU = (j+ 1) * step;

            for (int k = 0; k < tesselationLevel; k++) {
            
                float v = k * step;
                float nextV = (k + 1) * step;

                
                Point p0 = getGlobalBezierPoint(i, u, v);
                Point p1 = getGlobalBezierPoint(i, u, nextV);
                Point p2 = getGlobalBezierPoint(i, nextU, v);
                Point p3 = getGlobalBezierPoint(i, nextU, nextV);

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
