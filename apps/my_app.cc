// Copyright (c) 2020 Ankitha Damisetty. All rights reserved.

#include "my_app.h"

#include <cinder/gl/draw.h>
#include <cinder/gl/gl.h>
#include <cinder/app/App.h>

#include <chrono>
#include <string>
#include <vector>

using namespace std;
namespace myapp {

using std::chrono::seconds;
using std::chrono::system_clock;
using std::string;
using cinder::Rectf;
using cinder::vec2;

const double kDrawTime = 10;
const seconds kLevelTime = seconds(30);
const size_t app_size_ = 600;

using cinder::app::KeyEvent;

MyApp::MyApp()
: current_state_{GameState::kDrawing},
  my_wrld{b2Vec2(0.0f, 7.0f)},
  engine_{my_wrld}
  {game_timer.start();
  current_click = b2Vec2(0, 0);
  current_pos = b2Vec2(0, 0);
  click_counter = 0;
  add_counter = 0;
  flag_activate_ball = false;
  }


void MyApp::setup() {
  engine_.Setup();
}

void MyApp::update() {
  float32 time_step = 1.0/60.0f;
  int32 vel_iter = 3;
  int32 pos_iter = 5;
  my_wrld.Step(time_step, vel_iter, pos_iter);
  if (game_timer.getSeconds() > kDrawTime && !flag_activate_ball) {
    flag_activate_ball = true;
    engine_.GetSurfaces().SetEdges(engine_.GetTempEdges());
    engine_.ActivateBalls();
    current_state_ = GameState::kBallsMoving;
  }
}

void MyApp::draw() {
  cinder::gl::clear();
  DrawSurfaces();
  std::cout << "drew surfaces";
  DrawBall();
  DrawUserLines();
}

void MyApp::keyDown(KeyEvent event) { }

void MyApp::mouseDown(cinder::app::MouseEvent event) {
  if (current_state_ == GameState::kDrawing) {
    click_counter++;
    engine_.AddTempEdges(cinder::vec2(event.getX(), event.getY()));
    if (click_counter % 2 == 0) {
      current_pos = b2Vec2(event.getX(), event.getY());
      add_counter = add_counter + 1;
    } else {
      current_click = b2Vec2(event.getX(), event.getY());
      current_pos = current_click;
    }
  }
}

void MyApp::mouseMove(cinder::app::MouseEvent event) {
  if (current_state_ == GameState::kDrawing) {
    if (click_counter % 2 == 1) {
      current_pos = b2Vec2(event.getX(), event.getY());
    }
  }
}

void MyApp::DrawBall() {
  vector<myapp::Ball> current_balls = engine_.GetAllBalls();
  for (myapp::Ball ball: current_balls) {
    ball.DrawSingleBall();
  }
}

void MyApp::DrawSurfaces() {
  engine_.GetSurfaces().DrawBox();
  engine_.DrawTempEdges();
}

void MyApp::DrawUserLines() {
  if (current_state_ == GameState::kDrawing) {
    if (click_counter % 2 == 1) {
      cinder::gl::color(0, 1, 0);
      cinder::gl::drawLine(vec2(current_pos.x, current_pos.y),
              vec2(current_click.x, current_click.y));
    }
  }
}
}  // namespace myapp
