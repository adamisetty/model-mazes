//
// Created by Ankitha Damisetty on 4/18/2020.
//
#include <vector>
#include <Box2D/Box2D.h>
#include <cinder/gl/draw.h>
#include <cinder/gl/gl.h>
#include <mylibrary/edge.h>
#include <mylibrary/conversions.h>
#include <cmath>
#ifndef FINALPROJECT_SURFACES_H
#define FINALPROJECT_SURFACES_H

using namespace std;

namespace myapp {

class Surfaces{
  public:
    Surfaces();
    void CreateBox(b2World *my_world);
    void DrawBox();
    void DrawEdges();
    void SetEdges(vector<cinder::vec2> points);
  private:
    b2World *my_wrld;
    b2Body* groundBody;
    b2PolygonShape groundShape;
    b2Body* leftWallBody;
    b2PolygonShape leftWallShape;
    b2Body* rightWallBody;
    b2PolygonShape rightWallShape;
    vector<myapp::Edge> drawn_edges;
  b2Body* edgeBody;
  b2PolygonShape edgeShape;
  b2Vec2 m_start = b2Vec2(20, 400);
  b2Vec2 m_end = b2Vec2(450, 550);
  vector<b2Vec2> edge_points;
};


}
#endif //FINALPROJECT_SURFACES_H
