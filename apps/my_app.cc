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
  my_wrld{b2Vec2(0.0f, 10.0f)},
  engine_{my_wrld}
  {game_timer.start();}


void MyApp::setup() {
  engine_.Setup();
}

void MyApp::update() {
  float32 time_step = 1.0/60.0f;
  int32 vel_iter = 3;
  int32 pos_iter = 5;
  my_wrld.Step(time_step, vel_iter, pos_iter);
  if (game_timer.getSeconds() > kDrawTime) {
    current_state_ = GameState::kBallsMoving;
  }
}

void MyApp::draw() {
  cinder::gl::clear();
  DrawBall();
}

void MyApp::keyDown(KeyEvent event) { }

void MyApp::mouseDown(cinder::app::MouseEvent event) {
}

void MyApp::mouseDrag(cinder::app::MouseEvent event) {

}

void MyApp::DrawBall() {
  vector<myapp::Ball> current_balls = engine_.GetAllBalls();
  for (myapp::Ball ball: current_balls) {
    ball.DrawSingleBall();
  }
}

void MyApp::DrawSurfaces() {


}

void MyApp::DrawEndPoint() {

}
}  // namespace myapp
