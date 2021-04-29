#include "transformation.hpp"

CatmullRom::CatmullRom(){
    time = 0;
    points = std::vector<Point>();
}

CatmullRom::CatmullRom(float nTime, std::vector<Point> nPoints){
    time = nTime;
    points = nPoints;
}

void CatmullRom::buildRotMatrix(float *x, float *y, float *z, float *m) {

	m[0] = x[0]; m[1] = x[1]; m[2] = x[2]; m[3] = 0;
	m[4] = y[0]; m[5] = y[1]; m[6] = y[2]; m[7] = 0;
	m[8] = z[0]; m[9] = z[1]; m[10] = z[2]; m[11] = 0;
	m[12] = 0; m[13] = 0; m[14] = 0; m[15] = 1;
}


void CatmullRom::cross(float *a, float *b, float *res) {

	res[0] = a[1]*b[2] - a[2]*b[1];
	res[1] = a[2]*b[0] - a[0]*b[2];
	res[2] = a[0]*b[1] - a[1]*b[0];
}


void CatmullRom::normalize(float *a) {

	float l = sqrt(a[0]*a[0] + a[1] * a[1] + a[2] * a[2]);
	a[0] = a[0]/l;
	a[1] = a[1]/l;
	a[2] = a[2]/l;
}

void CatmullRom::multMatrixVector(float m[4][4], float *v, float *res) {

	for (int j = 0; j < 4; ++j) {
		res[j] = 0;
		for (int k = 0; k < 4; ++k) {
			res[j] += v[k] * m[j][k];
		}
	}

}

void CatmullRom::getCatmullRomPoint(float t, Point p0, Point p1, Point p2, Point p3, float *pos, float *deriv) {

	// catmull-rom matrix
	float m[4][4] = {	{-0.5f,  1.5f, -1.5f,  0.5f},
						{ 1.0f, -2.5f,  2.0f, -0.5f},
						{-0.5f,  0.0f,  0.5f,  0.0f},
						{ 0.0f,  1.0f,  0.0f,  0.0f}};

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
		// compute deriv = T' * A
		deriv[i] = 0;
		for (int j = 0; j < 4; j++) {
				deriv[i] += dtv[j] * a[j];
		}
	}
}

void CatmullRom::getGlobalCatmullRomPoint(float gt, float *pos, float *deriv) {
    int POINT_COUNT = points.size();
	float t = gt * POINT_COUNT; // this is the real global t
	int index = floor(t);  // which segment
	t = t - index; // where within  the segment

	// indices store the points
	int indices[4]; 
	indices[0] = (index + POINT_COUNT-1)%POINT_COUNT;	
	indices[1] = (indices[0]+1)%POINT_COUNT;
	indices[2] = (indices[1]+1)%POINT_COUNT; 
	indices[3] = (indices[2]+1)%POINT_COUNT;


	getCatmullRomPoint(t, points[indices[0]], points[indices[1]], points[indices[2]], points[indices[3]], pos, deriv);
}

void CatmullRom::transform(float timestamp) {

// draw curve using line segments with GL_LINE_LOOP
    if(points.size()>=4){
        float pos[3];
        float deriv[3];
        const float tessNum = points.size()*50;
        const float mod = time/tessNum;
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i < tessNum; i++)
        {
            getGlobalCatmullRomPoint(mod*i, pos, deriv);
            glVertex3f(pos[0],pos[1],pos[2]);
        }
        glEnd(); 
        getGlobalCatmullRomPoint(timestamp, pos, deriv);
        glTranslatef(pos[0], pos[1], pos[2]);

        float X[3] = { deriv[0], deriv[1], deriv[2] };
        normalize(X);

        float Y0[3] =  {0,1,0};

        float Z[3];
        cross(X,Y0,Z);
        normalize(Z);

        float Y[3];
        cross(Z,X,Y);
        normalize(Z);

        float m[16];

        buildRotMatrix(X,Y,Z,m);

       glMultMatrixf(m);
    }
}


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
    time = 0.0f;
}

Rotate::Rotate(float anglet, float xt, float yt, float zt, float timet){
    angle = anglet;
    x = xt;
    y = yt;
    z = zt;
    time = timet;
}

void Rotate::transform(float timestamp){
    float realAngle;
    if(time == 0)
        realAngle = angle;
    else
        realAngle = angle + timestamp * (360/time);
    glRotatef(realAngle,x,y,z);
    //a
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