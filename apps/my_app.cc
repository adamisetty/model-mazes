// Copyright (c) 2020 Ankitha Damisetty. All rights reserved.

#include "my_app.h"
#include <chrono>
#include <string>
#include <vector>

using namespace std;

namespace traffic_rush {

using std::chrono::seconds;
using std::chrono::system_clock;
using std::string;
using cinder::Rectf;
using cinder::vec2;
using cinder::Color;
using cinder::app::KeyEvent;

const double kDrawTime = 10;
const double kLevelTime = 20;


const size_t font_size = 20;
const glm::ivec2 font_box_size = glm::ivec2(85, 50);
const string font_style = "Arial";

MyApp::MyApp() {
  current_state_ = GameState::kPlaying;
}


void MyApp::setup() {
  engine_.SetUp();
}

void MyApp::update() {
  engine_.Step();
  if (!engine_.GetIsPlaying()) {
    current_state_ = GameState::kGameOver;
  }
}

void MyApp::draw() {
  cinder::gl::clear();
  if (current_state_ == GameState::kPlaying) {
    engine_.DrawEngine();
  }
}

void MyApp::mouseDown(cinder::app::MouseEvent event) {
}

void MyApp::mouseMove(cinder::app::MouseEvent event) {
}

void MyApp::PrintText(string text, cinder::vec2 location, size_t size) {
  auto box = cinder::TextBox();
  box.setText(text);
  box.setSize(font_box_size);
  box.setFont(cinder::Font(font_style, size));
  const auto surface = box.render();
  const auto texture = cinder::gl::Texture::create(surface);
  cinder::gl::draw(texture, location);
}
}  // namespace myapp
