#ifndef SPHERICALPOINT_H
#define SPHERICALPOINT_H

class SphericalPoint {
private:
    float alpha, beta, radius;

public:
    SphericalPoint(float, float, float);
    float get_alpha() const;
    float get_beta() const;
    float get_radius() const;
};
#endif
