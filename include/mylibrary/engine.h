// Copyright (c) 2020 Ankitha Damisetty. All rights reserved.

#ifndef FINALPROJECT_ENGINE_CC_H
#define FINALPROJECT_ENGINE_CC_H

#include <vector>
#include <string>
#include <random>
#include <Box2D/Box2D.h>
#include <mylibrary/ball.h>
#include <mylibrary/surfaces.h>

using namespace std;

namespace myapp {


class Engine {

  public:
    /**
     * Constructor, initialized once in my_app
     * @param this_wrld: b2World created in my_app, passed in by reference
     */
    Engine(b2World &this_wrld);

    /**
     * Creates all the small balls and the box around screen, set up of game
     */
    void Setup();

    /**
     * Used to access all the balls in this game
     * @return : all the balls, as a vector of Ball objects
     */
    vector<myapp::Ball> GetAllBalls();

    /**
     * Used to access all the surfaces in this game
     * @return : a surfaces objects, containing the Box and the user edges
     */
    myapp::Surfaces GetSurfaces();

    /**
     * Used during the drawing state, adds a point to list of edge endpoints
     * @param point: the point at which the user has clicked as a cinder::vec2
     */
    void AddTempEdges(cinder::vec2 point);

    /**
     * Used to access the temp edges the user has drawn
     * @return the vector of points at a specific time in the game
     */
    vector<cinder::vec2> GetTempEdges();

    /**
     * Draws the edges the user has chosen using cinder::gl functions
     */
    void DrawTempEdges();

    /**
     * Draws a cinder rectangle centered at the endpoint
     */
    void DrawEndBlock();

    /**
     * Turns all the balls into dynamic balls, called at the end of draw state
     */
    void ActivateBalls();

    /**
     * Score represents the number of balls that have hit the end point
     * @return :the current score, size_t
     */
    size_t GetScore();

  private:
    /**
     * Constructs many Ball objects as needed by engine
     * @param number: the specific number of balls this game has
     */
    void CreateBalls(size_t number);

    /**
     * Checks if each individual ball has the same position as the end point
     */
    void CalculateScore();


  private:
    /**
     * Stores the b2World created in my_app
     */
    b2World *my_wrld;

    /**
     * Stores the list of Ball objects needed for this game
     */
    vector<myapp::Ball> all_balls;

    /**
     * The surfaces object for this game which contains the box and user edges
     */
    myapp::Surfaces surfaces;

    /**
     * The points at which the user clicks to mark the start/end of an edge
     */
    vector<cinder::vec2> points;

    /**
     * Stores the starting x coordinate for the balls at the top of the screen
     */
    float32 start_x;

    /**
     * Stores the ending x coordinate for the end platform
     */
    float32 end_x;

    /**
     * Stores the ending y coordinate for the end platform
     */
    float32 end_y;

    /**
     * The current score of the game
     */
    size_t score;

};

}   //namespace falling_fun
#endif //FINALPROJECT_ENGINE_CC_H
