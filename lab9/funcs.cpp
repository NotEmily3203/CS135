#include <iostream>
#include "funcs.h"
#include "coord3d.h"
// add functions here

Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2){
    if(length(p1)>length(p2)){
        return p1;
    }else if(length(p1)<length(p2)){
        return p2;
    }
}

void move(Coord3D *ppos, Coord3D *pvel, double dt){
    (*ppos).x += ((*pvel).x)*dt;
    (*ppos).y += ((*pvel).y)*dt;
    (*ppos).z += ((*pvel).z)*dt;
}

Coord3D* createCoord3D(double x, double y, double z){
    Coord3D *p = new Coord3D;
    (*p).x = x;
    (*p).y = y;
    (*p).z = z;
    return p;
}
void deleteCoord3D(Coord3D *p){
    delete p;
}