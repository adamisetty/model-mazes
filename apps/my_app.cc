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
 engine_{myapp::app_size_} {game_timer.start();}


void MyApp::setup() {

}

void MyApp::update() {
    //engine_.GetCirclePtr()->ApplyForceToCenter(b2Vec2(-10, 0));
    engine_.myWorld->Step(1/30.0f, 8, 3);
  if (current_state_ == GameState::kDrawing && game_timer.getSeconds() > kDrawTime) {
    current_state_ = GameState::kBallMoving;
    return;
  }

}

void MyApp::draw() {
  cinder::gl::clear();
  DrawBall();/*
  if (current_state_ == GameState::kDrawing) {
    DrawBall();
  }*/

  DrawSurfaces();
  //DrawEndPoint();
}

void MyApp::keyDown(KeyEvent event) { }

void MyApp::mouseDown(cinder::app::MouseEvent event) {
  b2Vec2 clicked_pos = b2Vec2(event.getX(), event.getY());
  engine_.AddEndpoints(clicked_pos);
}

void MyApp::mouseDrag(cinder::app::MouseEvent event) {
  if (current_state_ == GameState::kDrawing) {
    int x = event.getX();
    int y = event.getY();
    engine_.AddSurfaces(x, y);
  }
}

void MyApp::DrawBall() {
  cinder::gl::color(0, 1, 1);
  if (current_state_ == GameState::kBallMoving) {
      //b2Vec2 vel = engine_.GetCirclePtr()->GetLinearVelocity();
      //engine_.GetCirclePtr()->SetLinearVelocity(b2Vec2(-10, 0));
      b2Vec2 loc = engine_.GetCirclePtr()->GetPosition();
      vec2 lo = vec2(loc.x, loc.y);
      cinder::gl::drawSolidCircle(vec2(lo[0], lo[1]),engine_.GetCircle().m_radius);
  }

  if (current_state_ == GameState::kBallMoving && !flag_ball_move) {
    flag_ball_move = true;
    engine_.MoveBall();
  }

  if (current_state_ == GameState::kDrawing) {
      //vector<size_t> curr_position = engine_.GetBall().GetLocation();
      cinder::gl::drawSolidCircle(vec2(100.0f, 100.0f)
              ,engine_.GetCircle().m_radius);
//      cinder::gl::drawLine(vec2(5, 5), vec2(20, 20));
      b2Vec2 point_1 = engine_.GetEdge().m_vertex1;
      b2Vec2 point_2 = engine_.GetEdge().m_vertex2;
      cinder::gl::drawLine(vec2(point_1.x, point_1.y), vec2(point_2.x, point_2.y));
  }
}

void MyApp::DrawSurfaces() {

   if (current_state_ == GameState::kDrawing) {
       vector<vector<size_t>> drawn_surfaces = engine_.GetSurfaces();
       for (vector<size_t> pixel: drawn_surfaces) {
           cinder::gl::color(0, 0.5, 1);
           cinder::gl::drawSolidCircle(vec2(pixel[0], pixel[1]), 1);
       }
   } else {
       cinder::gl::color(0, 0.5, 1);
       vector<b2Vec2> edge_endpoints = engine_.GetEndPoints();
       for (size_t ind = 0; ind < edge_endpoints.size()/2; ind = ind + 2) {
         b2Vec2 point_1 = edge_endpoints[ind];
         b2Vec2 point_2 = edge_endpoints[ind + 1];
         cinder::gl::drawLine(vec2(point_1.x, point_1.y), vec2(point_2.x, point_2.y));
       }
   }

  cinder::gl::color(1, 0, 0);
  b2Vec2 pos2 = engine_.GetGroundPtr()->GetPosition();
  b2Vec2 corn_1 = engine_.GetGround().GetVertex(0);
  b2Vec2 corn_2 = engine_.GetGround().GetVertex(2);
  //cinder::gl::drawSolidRect(Rectf(pos2.x - 200, pos2.y, pos2.x + 200, pos2.y + 20));
  cinder::gl::drawSolidRect(Rectf(corn_1.x, corn_1.y, corn_2.x, corn_2.y));
}

void MyApp::DrawEndPoint() {
  vector<double> end = engine_.GetEndPoint();
  size_t rad = engine_.GetCircle().m_radius;
  cinder::gl::color(1, 0, 0);
  cinder::gl::drawSolidRect(Rectf(end[0] - rad, end[1], end[0] + rad, end[1] + 2.5));
}
}  // namespace myapp
