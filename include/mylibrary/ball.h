// Copyright (c) 2020 Ankitha Damisetty. All rights reserved.
#include <vector>
#include <random>
#include <Box2D/Box2D.h>
#include <cinder/gl/draw.h>
#include <cinder/gl/gl.h>
#include <mylibrary/conversions.h>

#ifndef FINALPROJECT_BALL_H
#define FINALPROJECT_BALL_H

using std::vector;

namespace myapp {

class Ball {

  public:
    /**
     * Default constructor, does not initialize any values
     */
    Ball();

    /**
     * Creates a b2Body for this ball object in the passed in world
     * @param my_world: The world created in my_app, based in by pointer
     * @param start_x: a randomized x location, starting point of ball
     */
    void initialize(b2World *my_world, float32 start_x);

    /**
     * Ball destructor, the default
     */
    ~Ball();

    /**
     * Draws this ball using cinder functions to cinder application
     */
    void DrawSingleBall();

    /**
     * Converts the type of this body from static to dynamic, dropping the ball
     */
    void ActivateBall();

    /**
     * Checks if the ball has hit the end point at its current location
     * @param finish_loc: the end point of this game, determined by engine
     * @return : true if the ball is at the end point, false otherwise
     */
    bool CheckFinished(cinder::vec2 finish_loc);

    /**
     * Changes the ball to static, and moves it out of frame to not interfere
     * with the remaining ball objects, called when this has hit the endpoint
     */
    void DiminishBody();

  private:
    /**
     * b2Body pointer to this circle body
     */
    b2Body* circleBody;

    /**
     * A b2 circle shape stores the shape of this ball
     */
    b2CircleShape circle;

    /**
     * Start location of this ball
     */
    b2Vec2 location;

    /**
     * The color of this ball as determined by initialize()
     */
    std::vector<double> color_vals;
};
} // namespace myapp
#endif //FINALPROJECT_BALL_H
