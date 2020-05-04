// Copyright (c) 2020 Ankitha Damisetty. All rights reserved.

#include <Box2D/Box2D.h>
#include <cinder/gl/draw.h>
#include <cinder/gl/gl.h>
#include <mylibrary/edge.h>
#include <mylibrary/conversions.h>
#include <vector>
#include <cmath>
#ifndef FINALPROJECT_SURFACES_H
#define FINALPROJECT_SURFACES_H

using namespace std;

namespace myapp {

/**
 * Class manages all the solid surfaces set and created by the game
 */
class Surfaces{
  public:
    /**
     * Default constructor, does not initialize any variables
     */
    Surfaces();

    /**
     * Creates box around screen composed of ground and two
     * @param my_world
     */
    void CreateBox(b2World *my_world);
    void DrawBox();
    void SetEdges(vector<cinder::vec2> points);

  private:
    b2World *my_wrld;
    b2Body* ground_body;
    b2PolygonShape ground_shape;
    b2Body* left_wall_body;
    b2PolygonShape left_wall_shape;
    b2Body* right_wall_body;
    b2PolygonShape right_wall_shape;
    vector<myapp::Edge> drawn_edges;
};


}
#endif //FINALPROJECT_SURFACES_H
