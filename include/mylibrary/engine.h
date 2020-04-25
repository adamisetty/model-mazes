//
// Created by Ankitha Damisetty on 4/18/2020.
//

#ifndef FINALPROJECT_ENGINE_CC_H
#define FINALPROJECT_ENGINE_CC_H
#include "ball.h"
#include "surfaces.h"
//#include <Box2D/Dynamics/b2World.h>
//#include <Box2D/Dynamics/b2Body.h>
//#include <Box2D/Dynamics/b2World.cpp>

#include <vector>
#include <string>
#include <random>
#include <Box2D/Box2D.h>
#include <mylibrary/ball.h>

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
