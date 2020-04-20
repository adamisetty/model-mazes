//
// Created by Ramesh on 4/19/2020.
//
#include "mylibrary/ball.h"

namespace myapp {
  const size_t radius = 20;
  const size_t buffer = 5;

  Ball::Ball(size_t board_size_) {
   initialize(board_size_);
  }

  void Ball::initialize(size_t board_size) {
    //size_t start_pos = (rand() % (board_size - radius)) + radius;
    center_.push_back(radius + buffer*2);
    center_.push_back(radius + buffer);
  }

  vector<size_t> Ball::GetLocation() {
    return center_;
  }

  size_t Ball::GetRadius() {
    return radius;
  }
}