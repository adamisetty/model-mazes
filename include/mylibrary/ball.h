//
// Created by Ankitha Damisetty on 4/18/2020.
//
#include <vector>
#ifndef FINALPROJECT_BALL_H
#define FINALPROJECT_BALL_H
using std::vector;

namespace myapp {

class Ball {
  public:
    Ball();
    vector<size_t> GetLocation();

  private:
    vector<size_t> center_;
    size_t radius_;
};
} // namespace falling_fun
#endif //FINALPROJECT_BALL_H
