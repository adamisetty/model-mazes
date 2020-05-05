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

/**
 * Class that creates an object that is one user drawn edge
 */
class Edge{
  public:
    /**
     * Default constructor, does not initialize any instance variables
     */
    Edge();
    /**
     * Creates this edge shape in the b2World, interacting with other bodies
     * @param my_world: the b2World created in my_app, passed by pointer
     * @param start: the starting point of this edge shape
     * @param end : the ending point of this edge shape
     */
    void initialize(b2World *my_world, b2Vec2 start, b2Vec2 end);

  private:
    /**
     * b2Body pointer that points to this edge body created in the world
     */
    b2Body* edgeBody;

    /**
     * PolygonShape that represents this edge in the world
     */
    b2PolygonShape edgeShape;
};
}
#endif //FINALPROJECT_EDGE_H