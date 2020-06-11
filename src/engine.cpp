#include "mylibrary/engine.h"

namespace traffic_rush {
  Engine::Engine():
  my_world_{gravity} {
  }

  void Engine::SetUp() {}
  void Engine::Step() {
    my_world_.Step(time_step, vel_iter, pos_iter);
  }
  void Engine::CreateVehicle() {}

  void Engine::DrawEngine() {
    
  }
}