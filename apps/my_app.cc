// Copyright (c) 2020 Ankitha Damisetty & Nikitha Nagumalli. All rights reserved.

#include "my_app.h"
#include <chrono>
#include <string>
#include <vector>

using namespace std;

namespace traffic_rush {

  //TODO: leaderboard(game over screen), home screen,
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

    cinder::gl::color(0,0,0);
    home_screen_images_.push_back(cinder::gl::Texture::create(loadImage(loadAsset("red_car.png"))));
    home_screen_images_.push_back(cinder::gl::Texture::create(loadImage(loadAsset("blue_car.png"))));
    home_screen_images_.push_back(cinder::gl::Texture::create(loadImage(loadAsset("green_car.png"))));


    background_ = cinder::gl::Texture::create(loadImage(loadAsset("background.jpg")));
    pause_icon_ = cinder::gl::Texture::create(loadImage(loadAsset("pause.png")));
    vector<cinder::gl::TextureRef> images_{cinder::gl::Texture::create(loadImage(loadAsset("left_car.png"))),
                                           cinder::gl::Texture::create(loadImage(loadAsset("up_car.png"))),
                                           cinder::gl::Texture::create(loadImage(loadAsset("down_car.png"))),
                                           cinder::gl::Texture::create(loadImage(loadAsset("right_car.png"))),
                                           cinder::gl::Texture::create(loadImage(loadAsset("star.png")))};
    engine_.SetUp(images_);
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

    /*if (current_state_ == GameState::kHomeScreen) {
      DrawHomeScreen();
    }*/

    cinder::gl::clear();

    cinder::gl::color(1, 1, 1);
    cinder::gl::draw(background_, getWindowBounds());


    int curr_score_ = engine_.GetScore();
    string str = std::to_string(curr_score_);
    cinder::vec2 loc = cinder::vec2(535, 50);
    PrintText(str, loc, 30);

    //if (current_state_ == GameState::kPlaying) {
    engine_.DrawEngine();
    //}

    if (current_state_ == GameState::kPaused) {
      cinder::gl::draw(pause_icon_, vec2(515, 80));
    }
  }

  void MyApp::keyDown(KeyEvent event) {
    if (current_state_ == GameState::kPlaying) {
      engine_.KeyAction(event.getCode());
    }

    if (current_state_ == GameState::kPlaying || current_state_ == GameState::kPaused) {
      if (event.getCode() == KeyEvent::KEY_SPACE &&
          current_state_ == GameState::kPlaying) {
        current_state_ = GameState::kPaused;
        engine_.GetTimer().stop();
      } else if (event.getCode() == KeyEvent::KEY_SPACE) {
        current_state_ = GameState::kPlaying;
        engine_.GetTimer().resume();
      }
    }
  }

  void MyApp::DrawHomeScreen() {
    cinder::gl::draw(home_screen_images_[0], vec2(100, 300));
    cinder::gl::draw(home_screen_images_[1], vec2(200, 100));
    cinder::gl::draw(home_screen_images_[1], vec2(300, 300));
  }

  void MyApp::PrintText(string text, cinder::vec2 location, size_t size) {
    cinder::gl::color(Color::gray(0.2));
    auto box = cinder::TextBox();
    box.setText(text);
    box.setSize(font_box_size);
    box.setFont(cinder::Font(font_style, size));
    const auto surface = box.render();
    const auto texture = cinder::gl::Texture::create(surface);
    cinder::gl::draw(texture, location);
  }
}  // namespace myapp