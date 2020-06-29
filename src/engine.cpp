#include "mylibrary/engine.h"

#include <cinder/app/KeyEvent.h>

namespace traffic_rush {
  Engine::Engine():
      my_world_{gravity},
      generator{seed} {
    my_listener_.is_playing_ = true;
    game_timer_.start();
    score_ = 0;
  }

  void Engine::SetUp(vector<cinder::gl::TextureRef> &images_) {
    my_images_ = images_;
    SetMaps();
    CreateVehicle();
    my_world_.SetContactListener(&my_listener_);
    target_index_ = 0;
    all_vehicles_[target_index_].MarkTarget();
    last_timestamp_ = 0;
    frequency = 8;
  }

  void Engine::SetMaps() {
    //Sets four positions (bottom, top, left, right)
    b2Vec2 top = b2Vec2(Conversions::ToMeters(265), Conversions::ToMeters(50));
    start_positions_.insert({0, top});
    b2Vec2 bottom = b2Vec2(Conversions::ToMeters(335), Conversions::ToMeters(550));
    start_positions_.insert({1, bottom});
    b2Vec2 left = b2Vec2(Conversions::ToMeters(50), Conversions::ToMeters(330));
    start_positions_.insert({2, left});
    b2Vec2 right = b2Vec2(Conversions::ToMeters(550), Conversions::ToMeters(270));
    start_positions_.insert({3, right});

    //Sets four starting velocities
    b2Vec2 top_v = b2Vec2(0, 1);
    start_velocities_.insert({0, top_v});
    b2Vec2 bottom_v = b2Vec2(0, -1);
    start_velocities_.insert({1, bottom_v});
    b2Vec2 left_v = b2Vec2(1, 0);
    start_velocities_.insert({2, left_v});
    b2Vec2 right_v = b2Vec2(-1, 0);
    start_velocities_.insert({3, right_v});

    start_images_.insert({0, my_images_[2]});
    start_images_.insert({1, my_images_[1]});
    start_images_.insert({2, my_images_[3]});
    start_images_.insert({3, my_images_[0]});
    start_images_.insert({4, my_images_[4]});
  }

  void Engine::CreateVehicle() {
    //want to create periodically
    //needs to give random position/direction

    std::uniform_int_distribution<int> distributionInteger(0, 3);

    size_t position = distributionInteger(generator);
    int attempt = 0;
    while(!CheckProximity(position)) {
      attempt++;
      if (attempt > 5 ) {
        return;
      }
      position = distributionInteger(generator);
    }
    b2Vec2 start_p = start_positions_.at(position);//GetPosition(position);
    b2Vec2 start_v = start_velocities_.at(position);//GetVelocity(position);
    cinder::gl::TextureRef car_image = start_images_.at(position);
    Vehicle v;
    v.Initialize(&my_world_, start_p, start_v, car_image, start_images_.at(4));
    all_vehicles_.push_back(v);
  }

  bool Engine::CheckProximity(size_t position) {
    b2Vec2 start_p = start_positions_.at(position);
    b2Vec2 start_v = start_velocities_.at(position);
    for (int i = 0; i < all_vehicles_.size(); i++) {
      if (all_vehicles_[i].GetIsVisible()) {
        if (start_v.x == 0 &&
            abs(all_vehicles_[i].GetBody()->GetPosition().y - start_p.y) < Conversions::ToMeters(150)) {
          return false;
        } else if (start_v.y == 0 &&
                   abs(all_vehicles_[i].GetBody()->GetPosition().x - start_p.x) < Conversions::ToMeters(150)) {
          return false;
        }
      }
    }
    return true;
  }

  void Engine::Step() {
    my_world_.Step(time_step, vel_iter, pos_iter);
    UpdateScore();

    double time = 2.0 * game_timer_.getSeconds();
    int seconds = (int) time;

    if (seconds != last_timestamp_ && seconds % 20 == 0 && frequency > 2) {
      last_timestamp_ = seconds;
      frequency--;
    }

    if (seconds != last_timestamp_ && seconds % frequency == 0) {
      last_timestamp_ = seconds;
      CreateVehicle();
    }
  }

  void Engine::UpdateScore() {
    for (int i = 0; i < all_vehicles_.size(); i++) {
      all_vehicles_[i].CheckInBounds();
      if (!all_vehicles_[i].GetIsDestroyed() && !all_vehicles_[i].GetIsVisible()) {
        score_++;
        all_vehicles_[i].DestroyVehicle();
      }
    }

    if (!all_vehicles_[target_index_].GetIsVisible()) {
      for (int j = 0; j < all_vehicles_.size(); j++) {
        if (all_vehicles_[j].GetIsVisible()) {
          all_vehicles_[target_index_].MarkTarget();
          target_index_ = j;
          all_vehicles_[target_index_].MarkTarget();
          break;
        }
      }
    }
  }

  void Engine::DrawEngine() {
    for (Vehicle v: all_vehicles_) {
      v.DrawVehicle();
    }
  }

  void Engine::KeyAction(int user_action_) {
    if (user_action_ == KeyEvent::KEY_a || user_action_ == KeyEvent::KEY_s) {
      SpeedAction(user_action_);
    } else {
      if (!all_vehicles_.empty() && my_listener_.is_playing_) {
        int minimum_distance_ = Conversions::ToMeters(600);
        int minimum_index_ = -1;
        b2Vec2 current_position_ =
            all_vehicles_[target_index_].GetBody()->GetPosition();

        for (int i = 0; i < all_vehicles_.size(); i++) {
          Vehicle* v = &all_vehicles_[i];
          if (v->GetIsVisible()) {
            int v_distance_ =
                v->GetBody()->GetPosition().y - current_position_.y;
            int h_distance_ =
                v->GetBody()->GetPosition().x - current_position_.x;
            if (user_action_ == KeyEvent::KEY_UP) {
              if (v_distance_ < 0 &&
                  abs(v_distance_) < abs(minimum_distance_)) {
                minimum_distance_ = v_distance_;
                minimum_index_ = i;
              }
            }

            if (user_action_ == KeyEvent::KEY_DOWN) {
              if (v_distance_ > 0 && v_distance_ < minimum_distance_) {
                minimum_distance_ = v_distance_;
                minimum_index_ = i;
              }
            }

            if (user_action_ == KeyEvent::KEY_RIGHT) {
              if (h_distance_ > 0 && h_distance_ < minimum_distance_) {
                minimum_distance_ = h_distance_;
                minimum_index_ = i;
              }
            }

            if (user_action_ == KeyEvent::KEY_LEFT) {
              if (h_distance_ < 0 &&
                  abs(h_distance_) < abs(minimum_distance_)) {
                minimum_distance_ = h_distance_;
                minimum_index_ = i;
              }
            }
          }
        }

        if (minimum_index_ == -1) {
          minimum_index_ = target_index_;
        }

        all_vehicles_[target_index_].MarkTarget();
        all_vehicles_[minimum_index_].MarkTarget();
        target_index_ = minimum_index_;
      }
    }
  }

  void Engine::SpeedAction(int user_action_) {
    all_vehicles_[target_index_].ChangeSpeed(user_action_ == KeyEvent::KEY_s);
  }

  bool Engine::GetIsPlaying() {
    return my_listener_.is_playing_;
  }

  int Engine::GetScore() {
    return score_;
  }

  cinder::Timer Engine::GetTimer() {
    return game_timer_;
  }

  void Engine::MyContactListener::BeginContact(b2Contact *contact) {
    is_playing_ = false;
  }

  void Engine::DestroyEngine() {
    for (int i = 0; i < all_vehicles_.size(); i++) {
      my_world_.DestroyBody(all_vehicles_[i].GetBody());
    }

    all_vehicles_.clear();
  }
}