//
// Created by Ankitha Damisetty on 4/19/2020.
//
#include "mylibrary/engine.h"

namespace myapp {
 const size_t buffer = 5;
 const size_t radius = 20;

  Engine::Engine(size_t board_size)
  : ball_{board_size} {
    size_ = board_size;
    ball_rad = ball_.GetRadius();
    double end_x = ((rand() % 10) + 1)/10.0;
    end_point_.push_back(end_x * (board_size - radius));
    end_point_.push_back(buffer);
}

myapp::Ball Engine::GetBall() {
  return ball_;
}

vector<vector<size_t>> Engine::GetSurfaces() {
  return surfaces_;
}

vector<double> Engine::GetEndPoint() {
  return end_point_;
}

void Engine::AddSurfaces(int x, int y) {
  vector<size_t> adding;
  adding.push_back(x);
  adding.push_back(y);
  surfaces_.push_back(adding);
}
}
