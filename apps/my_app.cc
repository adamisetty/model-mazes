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

const double kDrawTime = 20;
const seconds kLevelTime = seconds(30);
const size_t app_size_ = 600;

using cinder::app::KeyEvent;

MyApp::MyApp()
: current_state_{GameState::kDrawing},
 engine_{myapp::app_size_} {game_timer.start();}


void MyApp::setup() {

}

void MyApp::update() {
    engine_.myWorld->Step(1/30.0f, 8, 3);
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

  DrawSurfaces();
  //DrawEndPoint();
}

void MyApp::keyDown(KeyEvent event) { }

void MyApp::mouseDrag(cinder::app::MouseEvent event) {
  if (current_state_ == GameState::kDrawing) {
    int x = event.getX();
    int y = event.getY();
    engine_.AddSurfaces(x, y);
  }
}

void MyApp::DrawBall() {
  cinder::gl::color(0, 1, 1);
  b2Vec2 vel = engine_.GetCirclePtr()->GetLinearVelocity();
  if (vel.y != 0) {
      b2Vec2 loc = engine_.GetCirclePtr()->GetPosition();
      vec2 lo = vec2(loc.x, loc.y);
      cinder::gl::drawSolidCircle(vec2(lo[0], lo[1]),engine_.GetBall().GetRadius());
  }
}

void MyApp::DrawSurfaces() {
  vector<vector<size_t>> drawn_surfaces = engine_.GetSurfaces();
  for (vector<size_t> pixel: drawn_surfaces) {
    cinder::gl::color(0, 0.5, 1);
    cinder::gl::drawSolidCircle(vec2(pixel[0], pixel[1]), 1);
  }

  cinder::gl::color(1, 0, 0);
 // b2Vec2 pos1 = engine_.GetGround().m_vertices[0];
  b2Vec2 pos2 = engine_.GetGroundPtr()->GetPosition();
  cinder::gl::drawSolidRect(Rectf(pos2.x - 200, pos2.y, pos2.x + 200, pos2.y + 20));
}

void MyApp::DrawEndPoint() {
  vector<double> end = engine_.GetEndPoint();
  size_t rad = engine_.GetBall().GetRadius();
  cinder::gl::color(1, 0, 0);
  cinder::gl::drawSolidRect(Rectf(end[0] - rad, end[1], end[0] + rad, end[1] + 2.5));
}
}  // namespace myapp
