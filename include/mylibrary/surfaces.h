//
// Created by Ankitha Damisetty on 4/18/2020.
//
#include <vector>
#include <Box2D/Box2D.h>
#include <cinder/gl/draw.h>
#include <cinder/gl/gl.h>
#ifndef FINALPROJECT_SURFACES_H
#define FINALPROJECT_SURFACES_H

using namespace std;

namespace myapp {
class Surfaces{
public:
    Surfaces();
    void CreateBox(b2World &my_world);
    void DrawBox();
private:
    b2Body* groundBody;
    b2PolygonShape groundShape;
};


}
#endif //FINALPROJECT_SURFACES_H
