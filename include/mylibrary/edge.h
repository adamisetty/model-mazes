//
// Created by Ankitha Damisetty on 4/26/2020.
//
#include <Box2D/Box2D.h>
#include <cinder/gl/draw.h>
#include <cinder/gl/gl.h>
#include <mylibrary/conversions.h>
#include <cmath>

#ifndef FINALPROJECT_EDGE_H
#define FINALPROJECT_EDGE_H


namespace myapp{

class Edge{

  public:
    Edge();
    void initialize(b2World *my_world, b2Vec2 start, b2Vec2 end);
  private:
    b2Body* edgeBody;
    b2PolygonShape edgeShape;
};
}
#endif //FINALPROJECT_EDGE_H