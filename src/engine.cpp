#include "mylibrary/engine.h"

namespace traffic_rush {
  Engine::Engine():
    my_world_{gravity} {
    my_listener_.is_playing_ = true;
    game_timer_.start();
    score_ = 0;
  }

  void Engine::SetUp() {
    SetMaps();
    CreateVehicle();
    my_world_.SetContactListener(&my_listener_);
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
  }

  void Engine::CreateVehicle() {
    //want to create periodically
    //needs to give random position/direction
    size_t position = rand() % num_positions;
    b2Vec2 start_p = GetPosition(position);
    b2Vec2 start_v = GetVelocity(position);
    Vehicle v;
    v.Initialize(&my_world_, start_p, start_v);
    all_vehicles_.push_back(v);
  }

  void Engine::Step() {
    my_world_.Step(time_step, vel_iter, pos_iter);
    UpdateScore();

    int seconds = game_timer_.getSeconds();
    if (seconds - (all_vehicles_.size() * 5) == 0) {
      CreateVehicle();
    }
  }

  void Engine::UpdateScore() {
    for(Vehicle v: all_vehicles_) {
      v.CheckInBounds();
      if (!v.GetIsDestroyed() && !v.GetIsVisible()) {
        score_++;
        v.DestroyVehicle();
      }
    }

    //cleaning the list of vehicles
    if (!all_vehicles_.empty() && !all_vehicles_[0].GetIsVisible()) {
      all_vehicles_.erase(all_vehicles_.cbegin());
    }
  }

  void Engine::DrawEngine() {
    for (Vehicle v: all_vehicles_){
      v.DrawVehicle();
    }
  }

  b2Vec2 Engine::GetPosition(size_t position) {
    return start_positions_.at(position);
  }

  b2Vec2 Engine::GetVelocity(size_t position) {
    return start_velocities_.at(position);
  }

  bool Engine::GetIsPlaying() {
    return my_listener_.is_playing_;
  }

  int Engine::GetScore() {
    return score_;
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