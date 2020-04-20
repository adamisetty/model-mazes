//
// Created by Ankitha Damisetty on 4/18/2020.
//

#ifndef FINALPROJECT_ENGINE_CC_H
#define FINALPROJECT_ENGINE_CC_H
#include "ball.h"

namespace myapp {

class Engine {
  public:
    Engine(size_t board_size);
    void Step();

  private:
    myapp::Ball ball_;
    size_t size_;
    size_t ball_rad;
};

}   //namespace falling_fun
#endif //FINALPROJECT_ENGINE_CC_H
