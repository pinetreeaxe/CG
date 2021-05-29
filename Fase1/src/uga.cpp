#include "uga.hpp"

NormalTexPoint2::NormalTexPoint2(Point pn, Vector nn, float x, float y){
    p = pn;
    n = nn;
    texX = x;
    texY = y;
}

std::string NormalTexPoint2::to_string(){
    std::string str;
    str.append(p.to_string());
    str.append(" ");
    str.append(n.to_string());
    str.append(" ");
    std::ostringstream ss;
    ss << texX << " " << texY;
    str.append(ss.str());
    return str;
}


