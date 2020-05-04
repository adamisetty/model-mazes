// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <string>
#include <cinder/app/App.h>
#include <cinder/gl/gl.h>
#include <mylibrary/engine.h>
#include <mylibrary/surfaces.h>
#include <Box2D/Box2D.h>

namespace myapp {

/**
 * Describes current state of game, changes with elapsed time
 */
enum class GameState {
  /**
   * The state while the user is able to draw lines on their screen
   */
  kDrawing,

  /**
   * The state when the balls have been released and are falling down
   */
  kBallsMoving,

  /**
   * The state after level time is elapsed, displays game result
   */
  kGameOver,
};

/**
 * Cinder app class, used to run and display application
 */
class MyApp : public cinder::app::App {
  public:
   /**
    * default constructor, initializes all instance variables and objects
    */
    MyApp();

    /**
     * Used to set up engine instance variable, makes ball objects and edges
     */
    void setup() override;

    /**
     * Called in a continuous loop, changes game state and takes appropriate
     * action when game state is changed
     */
    void update() override;

    /**
     * Called in a continuous loop, displays all shapes on cinder application
     */
    void draw() override;

    /**
     * Tracks user mouse click, used when drawing edges on screen
     * @param event: current instance of mouse event, stores position
     */
    void mouseDown(cinder::app::MouseEvent event) override;

    /**
     * Tracks mouse current position, used after mouse click in drawing state
     * @param event: current instance of mouse event, stores position
     */
    void mouseMove(cinder::app::MouseEvent event) override;

  private:
    /**
     * Draws all balls present in the game
     */
    void DrawBall();

    /**
     * Draws all surfaces: outside box end platform and user fixed edges
     */
    void DrawSurfaces();

    /**
     * Draws a traacking line of mouse position if user has marked first point
     * the specific edge being drawn
     */
    void DrawUserLines();

    /**
     * Draws score on the top right corner of the screen
     */
    void DrawScore();

    /**
     * Draws result of game (win or lose) in game over state
     */
    void DrawGameOver();

    /**
     * Prints a given text at a given location on the cinder screen
     * @param text: text as a string that will be printed
     * @param location: vec2 location of text, using cinder coordinates
     * @param size: size of text box that is created
     */
    void PrintText(string text, cinder::vec2 location, size_t size);

  private:
    /**
     * Stores all properties of game, all balls and surfaces
     * Takes in b2World object to add all bodies into
     */
    myapp::Engine engine_;

    /**
     * World object passed into engine, stores all bodies of this game
     */
    b2World my_wrld;

    /**
     * Stores the current GameState of this game, updates with elapsed time
     */
    GameState current_state_;

    /**
     * Timer begins at start of game, used to determine changes in game state
     */
    cinder::Timer game_timer;

    /**
     * In drawing state, stores an odd number if user has marked the starting
     * point of the edge they are drawing. Even number otherwise
     */
    size_t click_counter;

    /**
     * Stores the number of edges that user has drawn during the drawing state
     */
    size_t add_counter;

    /**
     * Stores the last clicked position in the drawing state
     */
    b2Vec2 current_click;

    /**
     * If user has made a first click, this stores the current mouse position
     */
    b2Vec2 current_pos;

    /**
     * False if in drawing state, true afterwards, indicates whether ball
     * objects have been dropped from top of screen
     */
    bool flag_activate_ball;
};


}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
