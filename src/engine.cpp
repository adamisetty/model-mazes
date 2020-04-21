//
// Created by Ankitha Damisetty on 4/19/2020.
//
#include "mylibrary/engine.h"

namespace myapp {
 const size_t buffer = 5;
 const size_t radius = 20;

  Engine::Engine(size_t board_size)
  : ball_{board_size},
   myWorld{new b2World(gravity)} {
    size_ = board_size;
    ball_rad = ball_.GetRadius();

    double end_x = ((rand() % radius) + radius) * buffer;
    end_point_.push_back(board_size - (end_x + buffer));
    end_point_.push_back(board_size - buffer);
    CreateShapes();
    InitializeBodies();
}

void Engine::CreateShapes() {
  circle.m_p.Set(40.0f, 30.0f);
  circle.m_radius = 20.0f;

  int32 rect = 4;
  b2Vec2 vertices[4];
  vertices[0].Set(10.0f, 580.0f);
  vertices[1].Set(580.0f, 580.0f);
  vertices[2].Set(580.0f, 590.0f);
  vertices[3].Set(10.0f, 590.0f);
  edgeShape.Set(vertices, rect);
  //edge.Set(b2Vec2(5.0f, 100.0f), b2Vec2(100.0f, 100.0f));
}

void Engine::InitializeBodies() {
  b2BodyDef circleDef;
  circleDef.type = b2_dynamicBody;
  circleDef.position.Set(circle.m_p.x, circle.m_p.y);
  circleDef.linearDamping = 0.0f;
  circleDef.angularDamping = 0.01f;
  circleBody = myWorld->CreateBody(&circleDef);

  b2FixtureDef fixtureDef;
  fixtureDef.shape = &circle;
  fixtureDef.density = 1.0f;
  //makes the ball slightly bouncy
  fixtureDef.restitution = 0.2f;
  circleBody->CreateFixture(&fixtureDef);

  b2BodyDef groundDef;
  groundDef.position.Set(295.0f,585.0f);
  groundBody = myWorld->CreateBody(&groundDef);
  //default is static body, so no need to set type

  b2FixtureDef groundFixDef;
  groundFixDef.shape = &edgeShape;
  groundFixDef.restitution = 0.0f;
  groundFixDef.density = 1.0f;
  groundBody->CreateFixture(&groundFixDef);
}

b2CircleShape Engine::GetCircle() {
  return circle;
}

b2Body* Engine::GetCirclePtr() {
  return circleBody;
}

b2PolygonShape Engine::GetGround() {
  return edgeShape;
}

b2Body* Engine::GetGroundPtr() {
  return groundBody;
}

myapp::Ball Engine::GetBall() {
  return ball_;
}

vector<vector<size_t>> Engine::GetSurfaces() {
  return surfaces_;
}

vector<double> Engine::GetEndPoint() {
  return end_point_;
}

void Engine::AddSurfaces(int x, int y) {
  vector<size_t> adding;
  adding.push_back(x);
  adding.push_back(y);
  surfaces_.push_back(adding);
}
}
