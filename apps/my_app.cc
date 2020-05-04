// Copyright (c) 2020 Ankitha Damisetty. All rights reserved.

#include "my_app.h"
#include "mylibrary/conversions.h"
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
using cinder::Color;
using cinder::app::KeyEvent;

const double kDrawTime = 10;
const double kLevelTime = 20;
const size_t num_balls = 20;

const b2Vec2 gravity = b2Vec2(0.0f, 7.0f);
const cinder::vec2 top_right = vec2(490, 10);
const cinder::vec2 middle = vec2(265, 300);
const int32 vel_iter = 3;
const int32 pos_iter = 5;
const float32 time_step = 1.0/60.0f;
const size_t font_size = 20;
const glm::ivec2 font_box_size = glm::ivec2(85, 50);

const vector<double> green = myapp::Conversions::ToCinderRBG
    (myapp::Conversions::ColorChooser(19));
const vector<double> blue = myapp::Conversions::ToCinderRBG
    (myapp::Conversions::ColorChooser(8));
const double gray = 0.3;

MyApp::MyApp()
: current_state_{GameState::kDrawing},
  my_wrld{gravity},
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

  my_wrld.Step(time_step, vel_iter, pos_iter);

  size_t score = engine_.GetScore();
  if (game_timer.getSeconds() > kDrawTime && !flag_activate_ball) {
    flag_activate_ball = true;
    engine_.GetSurfaces().SetEdges(engine_.GetTempEdges());
    engine_.ActivateBalls();
    current_state_ = GameState::kBallsMoving;
  }
  if (score == num_balls || game_timer.getSeconds() > kLevelTime + kDrawTime) {
    current_state_ = GameState::kGameOver;
  }
}

void MyApp::draw() {
  cinder::gl::clear(cinder::Color(gray, gray, gray), true);
  if (current_state_ != GameState::kGameOver) {
    DrawSurfaces();
    DrawBall();
    DrawUserLines();
    DrawScore();
  } else {
    DrawGameOver();
  }
}

void MyApp::mouseDown(cinder::app::MouseEvent event) {
  if (current_state_ == GameState::kDrawing) {
    click_counter++;
    engine_.AddTempEdges(cinder::vec2(event.getX(), event.getY()));
    if (click_counter % 2 == 0) {
      current_pos = b2Vec2(event.getX(), event.getY());
      add_counter++;
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

void MyApp::PrintText(string text, cinder::vec2 location, size_t size) {
  auto box = cinder::TextBox();
  box.setText(text);
  box.setSize(font_box_size);
  box.setFont(cinder::Font("Arial", size));
  const auto surface = box.render();
  const auto texture = cinder::gl::Texture::create(surface);
  cinder::gl::draw(texture, location);
}

void MyApp::DrawBall() {
  vector<myapp::Ball> current_balls = engine_.GetAllBalls();
  for (myapp::Ball ball: current_balls) {
    ball.DrawSingleBall();
  }
}

void MyApp::DrawSurfaces() {
  engine_.GetSurfaces().DrawBox();
  engine_.DrawEndBlock();
  engine_.DrawTempEdges();
}

void MyApp::DrawUserLines() {
  if (current_state_ == GameState::kDrawing) {
    if (click_counter % 2 == 1) {
      cinder::gl::color(green[0], green[1], green[2]);
      cinder::gl::drawLine(vec2(current_pos.x, current_pos.y),
              vec2(current_click.x, current_click.y));
    }
  }
}

void MyApp::DrawScore() {
  cinder::gl::color(blue[0], blue[1], blue[2]);
  size_t score = engine_.GetScore();
  string score_string = "Score: " + std::to_string(score);
  PrintText(score_string, top_right, font_size);
}

void MyApp::DrawGameOver() {
  if (engine_.GetScore() == num_balls) {
    cinder::gl::color(0, 1, 0);
    string winner = "Congrats!";
    PrintText(winner, middle, 20);
  } else {
    cinder::gl::color(1, 0, 0);
    string loser = "Time's up:(";
    PrintText(loser, middle, font_size);
  }
}

}  // namespace myapp
