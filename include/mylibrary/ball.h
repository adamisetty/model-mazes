//
// Created by Ankitha Damisetty on 4/18/2020.
//
#include <vector>
#include <random>

#ifndef FINALPROJECT_BALL_H
#define FINALPROJECT_BALL_H

using std::vector;

namespace myapp {

class Ball {
  public:
    Ball(size_t board_size_);
    vector<size_t> GetLocation();
    size_t GetRadius();

  private:
    vector<size_t> center_;
    size_t radius_;
    void initialize(size_t board_size_);
};
} // namespace falling_fun
#endif //FINALPROJECT_BALL_H
