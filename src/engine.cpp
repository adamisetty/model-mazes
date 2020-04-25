//
// Created by Ankitha Damisetty on 4/19/2020.
//
#include "mylibrary/engine.h"

namespace myapp {
const size_t total_num_balls = 7;

  Engine::Engine(b2World &this_wrld) {
    my_wrld = &this_wrld;
  }

  void Engine::Setup() {
    CreateBalls(total_num_balls);
    surfaces.CreateBox(*my_wrld);
  }

  void Engine::CreateBalls(size_t number) {
    for (size_t i = 0; i < number; i++) {
      myapp::Ball next_ball;
      next_ball.initialize(*my_wrld);
      all_balls.push_back(next_ball);
    }
  }

  vector<myapp::Ball> Engine::GetAllBalls() {
    return all_balls;
  }

  myapp::Surfaces Engine::GetSurfaces() {
    return surfaces;
  }
}
