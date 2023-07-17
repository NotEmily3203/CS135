#include <iostream>
#include <cmath>
#include "coord3d.h"

double length(Coord3D *p){
    double result = sqrt((pow(((*p).x),2))+(pow(((*p).y),2))+(pow(((*p).z),2)));
    return result;
}