#include <iostream>
#include <cmath>
#include "coord3d.h"
#include "funcs.h"

int main()
{
  Coord3D pointP = {10, 20, 30};
  Coord3D pointQ = {-10, 5, 40};
  std::cout <<"Distance of pointP = (10, 20, 30) from O: "<< length(&pointP) << std::endl;
  std::cout <<"Distance of pointQ = (-10, 5, 40) from O: "<< length(&pointQ) << std::endl;
  std::cout <<"&pointP: "<< &pointP << std::endl;
  std::cout <<"&pointQ: "<< &pointQ << std::endl;
  std::cout <<"The address of the further point is: "<< fartherFromOrigin(&pointP,&pointQ) << std::endl;
  Coord3D pos = {0, 0, 100.0};
  Coord3D vel = {1, -5, 0.2};
  move(&pos, &vel, 2.0);
  std::cout << pos.x << " " << pos.y << " " << pos.z << std::endl;
  double x, y, z;
  std::cout << "Enter position: ";
  std::cin >> x >> y >> z;
  Coord3D *ppos = createCoord3D(x,y,z);
    
  std::cout << "Enter velocity: ";
  std::cin >> x >> y >> z;
  Coord3D *pvel = createCoord3D(x,y,z);

  move(ppos, pvel, 10.0);

  std::cout << "Coordinates after 10 seconds: " 
            << (*ppos).x << " " << (*ppos).y << " " << (*ppos).z << std::endl;

  deleteCoord3D(ppos); // release memory
  deleteCoord3D(pvel);
  return 0;
}
