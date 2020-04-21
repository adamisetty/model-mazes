//
// Created by Ankitha Damisetty on 4/19/2020.
//
#include "mylibrary/engine.h"

namespace myapp {
 const size_t buffer = 5;
 const size_t radius = 20;

  Engine::Engine(size_t board_size)
  : ball_{board_size},
   myWorld{new b2World(gravity)} {
    size_ = board_size;
    ball_rad = ball_.GetRadius();

    double end_x = ((rand() % radius) + radius) * buffer;
    end_point_.push_back(board_size - (end_x + buffer));
    end_point_.push_back(board_size - buffer);
    CreateCircle();
}

void Engine::CreateCircle() {
  circle.m_p.Set(40.0f, 30.0f);
  circle.m_radius = 0.5f;
}

b2CircleShape Engine::GetCircle() {
    return circle;
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
