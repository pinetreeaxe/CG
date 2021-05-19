#include "normalTexPoint.hpp"

NormalTexPoint::NormalTexPoint(Point pn, Vector nn){
    p = pn;
    n = nn;
}

std::string NormalTexPoint::to_string(){
    std::string str;
    str.append(p.to_string());
    str.append("\n");
    str.append(n.to_string());
    return str;
}


