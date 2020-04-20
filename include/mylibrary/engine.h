//
// Created by Ankitha Damisetty on 4/18/2020.
//

#ifndef FINALPROJECT_ENGINE_CC_H
#define FINALPROJECT_ENGINE_CC_H
#include "ball.h"

#include <vector>
#include <string>
#include <random>

using namespace std;

namespace myapp {

class Engine {
  public:
    Engine(size_t board_size);
    void Step();
    myapp::Ball GetBall();
    vector<vector<size_t>> GetSurfaces();
    void AddSurfaces(int x, int y);
    vector<double> GetEndPoint();

  private:
    myapp::Ball ball_;
    size_t size_;
    size_t ball_rad;
    vector<vector<size_t>> surfaces_;
    vector<double> end_point_;
};

}   //namespace falling_fun
#endif //FINALPROJECT_ENGINE_CC_H
