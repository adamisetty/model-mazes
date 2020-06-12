#include "mylibrary/engine.h"

namespace traffic_rush {
Engine::Engine():
  my_world_{gravity} {
  game_timer_.start();
}

void Engine::SetUp() {
  SetMaps();
  CreateVehicle();
}

void Engine::SetMaps() {
  //Sets four positions (bottom, top, left, right)
  b2Vec2 top = b2Vec2(Conversions::ToMeters(300), Conversions::ToMeters(50));
  start_positions_.insert({0, top});
  b2Vec2 bottom = b2Vec2(Conversions::ToMeters(300), Conversions::ToMeters(550));
  start_positions_.insert({1, bottom});
  b2Vec2 left = b2Vec2(Conversions::ToMeters(50), Conversions::ToMeters(300));
  start_positions_.insert({2, left});
  b2Vec2 right = b2Vec2(Conversions::ToMeters(550), Conversions::ToMeters(300));
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

  int seconds = game_timer_.getSeconds();
  if (seconds - (all_vehicles_.size() * 5) == 0) {
    CreateVehicle();
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

}