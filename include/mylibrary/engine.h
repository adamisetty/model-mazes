// Copyright (c) 2020 Ankitha Damisetty. All rights reserved.

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

const size_t total_num_balls = 20;
const size_t buffer = 8;
const size_t screen_size = 600;

class Engine {

  public:
    Engine(b2World &this_wrld);
    void Setup();
    vector<myapp::Ball> GetAllBalls();
    myapp::Surfaces GetSurfaces();
    void AddTempEdges(cinder::vec2 point);
    vector<cinder::vec2> GetTempEdges();
    void DrawTempEdges();
    void ActivateBalls();
    size_t GetScore();

  private:
    b2World *my_wrld;
    vector<myapp::Ball> all_balls;
    void CreateBalls(size_t number);
    void CalculateScore();
    myapp::Surfaces surfaces;
    vector<cinder::vec2> points;
    float32 start_x;
    float32 end_x;
    float32 end_y;
    size_t score;
};

}   //namespace falling_fun
#endif //FINALPROJECT_ENGINE_CC_H
