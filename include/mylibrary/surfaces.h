//
// Created by Ankitha Damisetty on 4/18/2020.
//
#include <vector>
#include <Box2D/Box2D.h>
#include <cinder/gl/draw.h>
#include <cinder/gl/gl.h>
#include <mylibrary/edge.h>
#include <mylibrary/conversions.h>
#ifndef FINALPROJECT_SURFACES_H
#define FINALPROJECT_SURFACES_H

using namespace std;

namespace myapp {

class Surfaces{
  public:
    Surfaces();
    void CreateBox(b2World &my_world);
    void DrawBox();
    void DrawEdges();
    void AddToEdges(b2Vec2 start, b2Vec2 end);
  private:
    b2World *my_wrld;
    b2Body* groundBody;
    b2PolygonShape groundShape;
    b2Body* leftWallBody;
    b2PolygonShape leftWallShape;
    b2Body* rightWallBody;
    b2PolygonShape rightWallShape;
    vector<myapp::Edge> drawn_edges;
    vector<b2Vec2> edge_points;
};


}
#endif //FINALPROJECT_SURFACES_H
