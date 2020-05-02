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

enum class GameState {
  kDrawing,
  kBallsMoving,
  kCountDown,
  kGameOver,
};

class MyApp : public cinder::app::App {
 public:
  MyApp();
  void setup() override;
  void update() override;
  void draw() override;
  void mouseDown(cinder::app::MouseEvent event) override;
  void mouseMove(cinder::app::MouseEvent event) override;


 private:
  void DrawBall();
  void DrawSurfaces();
  void DrawUserLines();
  void DrawScore();
  void DrawGameOver();
  void PrintText(string text, cinder::vec2 location, size_t size);

 private:
  myapp::Engine engine_;
  b2World my_wrld;
  GameState current_state_;
  cinder::Timer game_timer;
  size_t click_counter;
  size_t add_counter;
  b2Vec2 current_click;
  b2Vec2 current_pos;
  bool flag_activate_ball;
};


}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
