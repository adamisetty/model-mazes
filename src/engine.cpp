#include "mylibrary/engine.h"

namespace traffic_rush {
Engine::Engine():
    my_world_{gravity} {
}

void Engine::SetUp() {
  SetPositions();
  CreateVehicle();
}

void Engine::SetPositions() {
  //Sets four positions (bottom, top, left, right)

  b2Vec2 top = b2Vec2(Conversions::ToMeters(300), Conversions::ToMeters(50));
  start_positions_.insert({0, top});
  b2Vec2 bottom = b2Vec2(Conversions::ToMeters(300), Conversions::ToMeters(550));
  start_positions_.insert({1, bottom});
  b2Vec2 left = b2Vec2(Conversions::ToMeters(50), Conversions::ToMeters(300));
  start_positions_.insert({2, left});
  b2Vec2 right = b2Vec2(Conversions::ToMeters(550), Conversions::ToMeters(300));
  start_positions_.insert({3, right});
}

void Engine::CreateVehicle() {
//want to create periodically
//needs to give random position/direction
  for (size_t i = 0; i < num_v; i++) {
    b2Vec2 start = GetPosition(rand() % num_positions);
    Vehicle v;
    v.Initialize(&my_world_, start);
    all_vehicles_.push_back(v);
  }
}

void Engine::Step() {
  my_world_.Step(time_step, vel_iter, pos_iter);
}


void Engine::DrawEngine() {
  for (Vehicle v: all_vehicles_){
    v.DrawVehicle();
  }
}

b2Vec2 Engine::GetPosition(size_t position) {
  return start_positions_.at(position);
}

}