//
// Created by Ankitha Damisetty on 4/18/2020.
//
#include <vector>
#include <random>
#include <vector>
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
    void initialize(b2World &my_world);
    b2Vec2 GetLocation();
    b2Body* GetBody();
    b2CircleShape GetShape();
    void DrawSingleBall();

  private:
    b2Body* circleBody;
    b2CircleShape circle;
    b2Vec2 location;
    std::vector<float> color_values;
};
} // namespace falling_fun
#endif //FINALPROJECT_BALL_H
