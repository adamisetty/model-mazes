// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

#include <cinder/gl/draw.h>
#include <cinder/gl/gl.h>
#include <cinder/app/App.h>

#include <chrono>
#include <string>

namespace myapp {

using std::chrono::seconds;
using std::chrono::system_clock;
using std::string;
using cinder::Rectf;
using cinder::vec2;

const double kDrawTime = 5;
const seconds kLevelTime = seconds(30);

using cinder::app::KeyEvent;

MyApp::MyApp()
: current_state_{GameState::kDrawing},
 engine_{800} {game_timer.start();}


void MyApp::setup() {
  //cinder::gl::enableDepthWrite();
  //cinder::gl::enableDepthRead();
}

void MyApp::update() {
  if (current_state_ == GameState::kDrawing && game_timer.getSeconds() > kDrawTime) {
    current_state_ = GameState::kBallMoving;
    return;
  }
}

void MyApp::draw() {
  cinder::gl::clear();
  if (current_state_ == GameState::kDrawing) {
    DrawBall();
  }
}

void MyApp::keyDown(KeyEvent event) { }


void MyApp::DrawBall() const {
  cinder::gl::color(0, 1, 1);
  //cinder::gl::drawSolidRect(Rectf(20, 20, 40, 40));
  cinder::gl::drawSolidCircle(vec2(20, 20), 20);
}

}  // namespace myapp
