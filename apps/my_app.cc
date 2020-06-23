// Copyright (c) 2020 Ankitha Damisetty & Nikitha Nagumalli. All rights reserved.

#include "my_app.h"
#include <chrono>
#include <string>
#include <vector>

using namespace std;

namespace traffic_rush {

  //TODO: leaderboard, stop timer, increasing frequency of vehicles
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
    is_cleared_ = false;
  }


  void MyApp::setup() {
    background_ = cinder::gl::Texture::create(loadImage(loadAsset("background.jpg")));
    vector<cinder::gl::TextureRef> vehicle_images_{cinder::gl::Texture::create(loadImage(loadAsset("teal_car_.png"))),
                                                   cinder::gl::Texture::create(loadImage(loadAsset("red_car_.png")))};
    engine_.SetUp(vehicle_images_);
  }

  void MyApp::update() {
    if (current_state_ == GameState::kPlaying) {
      engine_.Step();
    }
    if (!engine_.GetIsPlaying()) {
      current_state_ = GameState::kGameOver;
      if (!is_cleared_) {
        engine_.DestroyEngine();
        is_cleared_ = true;
      }
    }
  }

  void MyApp::draw() {
    cinder::gl::clear();

    cinder::gl::color(1, 1, 1);
    cinder::gl::draw(background_, getWindowBounds());

    int curr_score_ = engine_.GetScore();
    string str = std::to_string(curr_score_);
    cinder::vec2 loc = cinder::vec2(550, 50);
    PrintText(str, loc, 20);

    if (current_state_ == GameState::kPlaying) {
      engine_.DrawEngine();
    }

  }

  /*void MyApp::mouseDown(cinder::app::MouseEvent event) {
    engine_.ClickAction(event.getPos(), event.isLeft());
  }

  void MyApp::mouseMove(cinder::app::MouseEvent event) {
  }*/

  void MyApp::keyDown(KeyEvent event) {
    if (current_state_ == GameState::kPlaying) {
      engine_.KeyAction(event.getCode());
    }
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
