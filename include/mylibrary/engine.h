//
// Created by Ankitha Damisetty on 4/18/2020.
//

#ifndef FINALPROJECT_ENGINE_CC_H
#define FINALPROJECT_ENGINE_CC_H
//#include "surfaces.h"

#include <vector>
#include <string>
#include <random>
#include <Box2D/Box2D.h>
#include <mylibrary/ball.h>
#include <mylibrary/surfaces.h>

using namespace std;

namespace myapp {

class Engine {

  public:
    Engine(b2World &this_wrld);
    void Setup();
    vector<myapp::Ball> GetAllBalls();
    myapp::Surfaces GetSurfaces();

  private:
    b2World *my_wrld;
    vector<myapp::Ball> all_balls;
    void CreateBalls(size_t number);
    myapp::Surfaces surfaces;
};

}   //namespace falling_fun
#endif //FINALPROJECT_ENGINE_CC_H
