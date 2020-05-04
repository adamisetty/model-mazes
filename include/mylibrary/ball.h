// Copyright (c) 2020 Ankitha Damisetty. All rights reserved.
#include <vector>
#include <random>
#include <Box2D/Box2D.h>
#include <cinder/gl/draw.h>
#include <cinder/gl/gl.h>
#include <mylibrary/conversions.h>

#ifndef FINALPROJECT_BALL_H
#define FINALPROJECT_BALL_H

using std::vector;

namespace myapp {

class Ball {

  const float32 radius = 7.5;
  const size_t buffer = 10;
  const float32 finish_buffer = 8;

  public:
    Ball();
    void initialize(b2World *my_world, float32 start_x);
    ~Ball();
    void DrawSingleBall();
    void ActivateBall();
    bool CheckFinished(cinder::vec2 finish_loc);
    void DiminishBody();

  private:
    b2Body* circleBody;
    b2CircleShape circle;
    b2Vec2 location;
    std::vector<double> color_vals;
};
} // namespace myapp
#endif //FINALPROJECT_BALL_H
