// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <string>
#include <cinder/app/App.h>
#include <cinder/gl/gl.h>
#include <Box2D/Box2D.h>
#include <mylibrary/engine.h>

using std::string;

namespace traffic_rush {

/**
 * Describes current state of game, changes with elapsed time
 */
enum class GameState {
  /**
   * The state before the user begins the game
   */
  kPreparing,

  /**
   * The state when the user is controlling the vehicles
   */
  kPlaying,

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
     * Prints a given text at a given location on the cinder screen
     * @param text: text as a string that will be printed
     * @param location: vec2 location of text, using cinder coordinates
     * @param size: size of text box that is created
     */
    void PrintText(string text, cinder::vec2 location, size_t size);

  private:
    /**
     * Stores the current GameState of this game, updates with elapsed time
     */
    GameState current_state_;
    Engine engine_;
    bool found_collision_;

};


}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
