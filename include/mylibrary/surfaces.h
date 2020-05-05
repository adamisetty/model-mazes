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
     * Creates box around screen composed of ground, left wall, and right wall
     * @param my_world: box2d world created in my_app, used through project
     */
    void CreateBox(b2World *my_world);

    /**
     * Uses cinder::gl draw functions to display the box created
     */
    void DrawBox();

    /**
     * Called at end of drawing state, converts drawn edges into edge objects
     * @param points: vector of cinder locations, the user clicks
     */
    void SetEdges(vector<cinder::vec2> points);

  private:
    /**
     * Pointer to the b2World object created in my_app
     */
    b2World *my_wrld;

    /**
     * b2Body pointer to the ground shape that is created in CreateBox()
     */
    b2Body* ground_body;

    /**
     * Ground shape, it is a box, dimensions of bottom of screen
     */
    b2PolygonShape ground_shape;

    /**
     * b2Body pointer to the left wall shape that is created in CreateBox()
     */
    b2Body* left_wall_body;

    /**
     * Left wall shape, it is a box, dimensions of left side of screen
     */
    b2PolygonShape left_wall_shape;

    /**
     * b2Body pointer to the right wall shape that is created in CreateBox()
     */
    b2Body* right_wall_body;

    /**
     * Right wall shape, it is a box, dimensions of right side of screen
     */
    b2PolygonShape right_wall_shape;

    /**
     * Contains all edges the user has drawn in drawing state
     */
    vector<myapp::Edge> drawn_edges;
};


}
#endif //FINALPROJECT_SURFACES_H
