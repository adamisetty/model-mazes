// Copyright (c) 2020 Ankitha Damisetty & Nikitha Nagumalli. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <Box2D/Box2D.h>
#include <cinder/app/App.h>
#include <cinder/app/KeyEvent.h>
#include <cinder/gl/gl.h>
#include <mylibrary/engine.h>
#include <cinder/app/KeyEvent.h>
#include <string>
#include <cinder/Color.h>

using std::string;
using cinder::app::KeyEvent;
using cinder::Color;

namespace traffic_rush {

/**
 * Describes current state of game, changes with elapsed time
 */
enum class GameState {
  /**
   * The state before the user begins the game
   */
  kHomeScreen,

  /**
   * The state when the user is controlling the vehicles
   */
  kPlaying,

  /**
   *
   */
  kPaused,

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
    void keyDown(KeyEvent event) override;
    void DrawHomeScreen();
    void DrawPlayingScreen();
    void DrawGameOverScreen();
    void SetUpEngine();


  private:

    /**
     * Prints a given text at a given location on the cinder screen
     * @param text: text as a string that will be printed
     * @param location: vec2 location of text, using cinder coordinates
     * @param size: size of text box that is created
     */
    void PrintText(string text, cinder::vec2 location, size_t size, vector<float> color);

  private:
    /**
     * Stores the current GameState of this game, updates with elapsed time
     */
    GameState current_state_;
    Engine engine_;
    bool is_cleared_;
    cinder::gl::TextureRef background_;
    cinder::gl::TextureRef pause_icon_;
    vector<cinder::gl::TextureRef> home_screen_images_;
    cinder::Timer game_over_timer;

};
}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
