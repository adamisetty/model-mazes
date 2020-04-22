//
// Created by Ankitha Damisetty on 4/18/2020.
//

#ifndef FINALPROJECT_ENGINE_CC_H
#define FINALPROJECT_ENGINE_CC_H
#include "ball.h"
//#include <Box2D/Dynamics/b2World.h>
//#include <Box2D/Dynamics/b2Body.h>
//#include <Box2D/Dynamics/b2World.cpp>

#include <vector>
#include <string>
#include <random>
#include <Box2D/Box2D.h>

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
    void CreateShapes();
    void InitializeBodies();
    b2CircleShape GetCircle();
    b2PolygonShape GetGround();
    b2Body* GetCirclePtr();
    b2Body* GetGroundPtr();
    b2World* myWorld;

  private:
    myapp::Ball ball_;
    size_t size_;
    size_t ball_rad;
    vector<vector<size_t>> surfaces_;
    vector<double> end_point_;
    b2Vec2 gravity = {0, 4.8};
    b2CircleShape circle;
    //b2EdgeShape edge;
    b2PolygonShape edgeShape;
    b2Vec2 ball_velocity;
    b2Body* circleBody;
    b2Body* groundBody;
};

}   //namespace falling_fun
#endif //FINALPROJECT_ENGINE_CC_H
