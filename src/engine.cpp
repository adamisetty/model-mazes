// Copyright (c) 2020 Ankitha Damisetty. All rights reserved.
#include "mylibrary/engine.h"

namespace myapp {

const size_t total_num_balls = 20;
const size_t buffer = 8;
const size_t screen_size = 600;

const size_t x_start_center = 240;
const size_t x_start_buffer = 10;
const size_t x_end_center = 380;
const size_t x_end_buffer = 300;
const size_t block_buffer = 16;

const vector<double> blue = myapp::Conversions::ToCinderRBG
    (myapp::Conversions::ColorChooser(8));
const vector<double> green = myapp::Conversions::ToCinderRBG
    (myapp::Conversions::ColorChooser(19));


  Engine::Engine(b2World &this_wrld) {
    my_wrld = &this_wrld;
    start_x = rand() % x_start_center + x_start_buffer;
    end_x = rand() % x_end_center + x_end_buffer;
    end_y = screen_size - block_buffer;
    score = 0;
  }

  void Engine::Setup() {
    CreateBalls(total_num_balls);
    surfaces.CreateBox(my_wrld);
  }

  void Engine::CreateBalls(size_t number) {
    for (size_t i = 0; i < number; i++) {
      myapp::Ball next_ball;
      next_ball.initialize(my_wrld, start_x);
      all_balls.push_back(next_ball);
    }
  }

  void Engine::ActivateBalls() {
    for (myapp::Ball ball: all_balls) {
      ball.ActivateBall();
    }
  }

  void Engine::CalculateScore() {
    for (myapp::Ball ball : all_balls) {
      if (ball.CheckFinished(cinder::vec2(end_x, end_y))) {
        score++;
        //"removes the body", moves it to be out of the way of other balls
        ball.DiminishBody();
      }
    }
  }

  void Engine::AddTempEdges(cinder::vec2 point) {
    points.push_back(point);
  }

  vector<cinder::vec2> Engine::GetTempEdges() {
    return points;
  }

  vector<myapp::Ball> Engine::GetAllBalls() {
    return all_balls;
  }

  myapp::Surfaces Engine::GetSurfaces() {
    return surfaces;
  }

  size_t Engine::GetScore() {
    CalculateScore();
    return score;
  }

  void Engine::DrawEndBlock() {
    cinder::gl::color(blue[0], blue[1], blue[2]);

    cinder::vec2 end_point = cinder::vec2(end_x, end_y);
    cinder::gl::drawSolidRect(cinder::Rectf(end_point.x - buffer,
                                            end_point.y - buffer,
                                            end_point.x + buffer,
                                            end_point.y + buffer));
  }

  void Engine::DrawTempEdges() {
    //if there are no drawn edges, no action should be taken
    if (points.empty()) {
      return;
    }
    cinder::gl::color(blue[0], blue[1], blue[2]);
    size_t endpoint_radius = 2;

    for (size_t i = 1; i < points.size(); i = i + 2) {
      cinder::gl::drawLine(points[i], points[i - 1]);
    }
    for (cinder::vec2 point: points) {
      cinder::gl::color(green[0], green[1], green[2]);
      //Creates the click point, so user can see the edge start/end
      cinder::gl::drawSolidCircle(point, endpoint_radius);
    }
  }

}
