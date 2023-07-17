#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "coord3d.h"
#include "funcs.h"

Coord3D pointP = {10, 20, 30};
Coord3D pointQ = {-10, 5, 40};
Coord3D pos = {0, 0, 100.0};
Coord3D vel = {1, -5, 0.2};

// add your tests here
TEST_CASE("3dDistance"){
    CHECK(length(&pointP)==sqrt(100+400+900));
    CHECK(length(&pointQ)==sqrt(100+25+1600));
}

TEST_CASE("Farther"){
    CHECK(fartherFromOrigin(&pointP,&pointQ)==&pointQ);
    CHECK(fartherFromOrigin(&pointQ,&pointP)==&pointQ);
}

TEST_CASE("Move"){
    (move(&pos,&vel,2.0));
    pos.x == 2;
    pos.y == -10;
    pos.z == 100.4;
}

TEST_CASE("Create and Delete"){
    Coord3D *temp = createCoord3D(1.0, 2.0, 3.0);
    CHECK((*temp).x == 1.0);
    CHECK((*temp).y == 2.0);
    CHECK((*temp).z == 3.0);
    deleteCoord3D(temp);
}