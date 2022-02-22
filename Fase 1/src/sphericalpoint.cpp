#include "sphericalpoint.hpp"

SphericalPoint::SphericalPoint(float a, float b, float r) {
    alpha = a;
    beta = b;
    radius = r;
}

float SphericalPoint::get_alpha() const { return alpha; }
float SphericalPoint::get_beta() const { return beta; }
float SphericalPoint::get_radius() const { return radius; }