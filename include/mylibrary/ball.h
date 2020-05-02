//
// Created by Ankitha Damisetty on 4/18/2020.
//
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
    std::vector<float> color_vals;
};
} // namespace falling_fun
#endif //FINALPROJECT_BALL_H
