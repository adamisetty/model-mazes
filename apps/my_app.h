// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>
#include <cinder/gl/gl.h>
#include <mylibrary/engine.h>
#include <Box2D/Box2D.h>

namespace myapp {

enum class GameState {
  kGameStart,
  kDrawing,
  kBallMoving,
  kCountDown,
  kGameOver,
};

class MyApp : public cinder::app::App {
 public:
  MyApp();
  void setup() override;
  void update() override;
  void draw() override;
  void keyDown(cinder::app::KeyEvent) override;
  void mouseDown(cinder::app::MouseEvent event) override;
  void mouseDrag(cinder::app::MouseEvent event) override;


 private:
  void DrawBall();
  void DrawSurfaces();
  void DrawEndPoint();

 private:
  myapp::Engine engine_;
  GameState current_state_;
  std::chrono::time_point<std::chrono::system_clock> start_time_;
  cinder::Timer game_timer;
  bool flag_ball_move = false;
  bool flag_edges_created = false;
  b2Vec2 ball_velocity = {0, 5};
};


}  // namespace falling_fun

#endif  // FINALPROJECT_APPS_MYAPP_H_
