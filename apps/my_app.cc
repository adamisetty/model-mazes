// Copyright (c) 2020 Ankitha Damisetty & Nikitha Nagumalli. All rights reserved.

#include "my_app.h"
#include <chrono>
#include <string>
#include <vector>

using namespace std;

namespace traffic_rush {

  //TODO: reset game and timer
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
    current_state_ = GameState::kHomeScreen;
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
        game_over_timer.start();
        is_cleared_ = true;
      }
    }
  }

  void MyApp::draw() {
    switch (current_state_) {
      case GameState::kHomeScreen :
        DrawHomeScreen();
        break;
      case GameState::kPlaying :
      case GameState::kPaused :
        DrawPlayingScreen();
        break;
      case GameState::kGameOver :
        DrawGameOverScreen();
        break;
    }
  }

  void MyApp::keyDown(KeyEvent event) {
    if (event.getCode() == KeyEvent::KEY_SPACE && current_state_ == GameState::kHomeScreen) {
      current_state_ = GameState::kPlaying;
    } else {
      if (current_state_ == GameState::kPlaying) {
        engine_.KeyAction(event.getCode());
      }

      if (current_state_ == GameState::kPlaying ||
          current_state_ == GameState::kPaused) {
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
  }

  void MyApp::DrawHomeScreen() {
    cinder::gl::clear();
    cinder::gl::color(1, 1, 1);
    cinder::gl::draw(home_screen_images_[0], vec2(230, 80));
    cinder::gl::draw(home_screen_images_[1], vec2(30, 80));
    cinder::gl::draw(home_screen_images_[2], vec2(430, 80));
    cinder::gl::draw(home_screen_images_[1], vec2(230, 460));
    cinder::gl::draw(home_screen_images_[2], vec2(30, 460));
    cinder::gl::draw(home_screen_images_[0], vec2(430, 460));

    PrintText("Tra", vec2(170, 220), 60, vector<float>{1, 1, 0.6f});
    PrintText("ffic ", vec2(240, 220), 60, vector<float>{1, 1, 0.6f});
    PrintText("Ru", vec2(320, 220), 60, vector<float>{1, 1, 0.6f});
    PrintText("sh", vec2(380, 220), 60, vector<float>{1, 1, 0.6f});

    PrintText("Press", vec2(210, 300), 30, vector<float>{1, 1, 1});
    PrintText("Space", vec2(273, 300), 30, vector<float>{1, 1, 1});
    PrintText("to", vec2(343, 300), 30, vector<float>{1, 1, 1});
    PrintText("Start", vec2(230, 330), 30, vector<float>{1, 1, 1});
    PrintText("Game", vec2(283, 330), 30, vector<float>{1, 1, 1});

  }

  void MyApp::DrawPlayingScreen() {
    cinder::gl::clear();

    cinder::gl::color(1, 1, 1);
    cinder::gl::draw(background_, getWindowBounds());


    int curr_score_ = engine_.GetScore();
    string str = std::to_string(curr_score_);
    cinder::vec2 loc = cinder::vec2(535, 50);
    PrintText(str, loc, 30, vector<float>{0.8f, 0.8f, 0.8f});


    engine_.DrawEngine();

    if (current_state_ == GameState::kPaused) {
      cinder::gl::draw(pause_icon_, vec2(515, 80));
    }
  }

  void MyApp::DrawGameOverScreen() {
    if (game_over_timer.getSeconds() > 3) {
      cinder::gl::clear(cinder::Color(0.23f, 0.65f, 0.69f), true);

      PrintText("Your", vec2(200, 200), 35, vector<float>{0.2f, 0.2f, 0.2f});
      PrintText("score", vec2(263, 200), 35, vector<float>{0.2f, 0.2f, 0.2f});
      PrintText("is", vec2(340, 200), 35, vector<float>{0.2f, 0.2f, 0.2f});

      int curr_score_ = engine_.GetScore();
      string str = std::to_string(curr_score_);
      PrintText(str, vec2(370, 200), 35, vector<float>{0.2f, 0.2f, 0.2f});

      if (curr_score_ <= 5) {
        PrintText(":(", vec2(390, 200), 35, vector<float>{0.2f, 0.2f, 0.2f});
      } else {
        PrintText(":)", vec2(400, 200), 35, vector<float>{0.2f, 0.2f, 0.2f});
      }
    }
  }

  void MyApp::PrintText(string text, cinder::vec2 location, size_t size, vector<float> color) {
    cinder::gl::color(color[0], color[1], color[2]);
    auto box = cinder::TextBox();
    box.setText(text);
    box.setSize(font_box_size);
    box.setFont(cinder::Font(font_style, size));
    const auto surface = box.render();
    const auto texture = cinder::gl::Texture::create(surface);
    cinder::gl::draw(texture, location);
  }
}  // namespace myapp