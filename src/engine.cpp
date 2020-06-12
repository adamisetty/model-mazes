#include "mylibrary/engine.h"

namespace traffic_rush {
Engine::Engine():
    my_world_{gravity} {
}

void Engine::SetUp() {
  CreateVehicle();
}

void Engine::Step() {
  my_world_.Step(time_step, vel_iter, pos_iter);
}

void Engine::CreateVehicle() {
//want to create periodically
//needs to give random position/direction
  for (size_t i = 0; i < num_v; i++) {
    Vehicle v;
    v.Initialize(&my_world_);
    all_vehicles_.push_back(v);
  }
}

void Engine::DrawEngine() {
  for (Vehicle v: all_vehicles_){
    v.DrawVehicle();
  }
}
}