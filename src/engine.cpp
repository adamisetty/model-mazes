//
// Created by Ankitha Damisetty on 4/19/2020.
//
#include "mylibrary/engine.h"

namespace myapp {
 const size_t buffer = 5;
 const size_t radius = 20;

  Engine::Engine(size_t board_size)
  : ball_{board_size},
    myWorld{new b2World(b2Vec2(0, 10))} {
    size_ = board_size;
    ball_rad = ball_.GetRadius();

    double end_x = ((rand() % radius) + radius) * buffer;
    end_point_.push_back(board_size - (end_x + buffer));
    end_point_.push_back(board_size - buffer);
    //CreateShapes();
    InitializeBodies();
}

void Engine::CreateShapes() {

}

void Engine::InitializeBodies() {
  InitializeCircle();
  InitializeBorders();
}

void Engine::InitializeCircle() {
    circle.m_p.Set(100.0f, 100.0f);
    circle.m_radius = 10.0f;
    //circle.m_p.Set(0, 0);

    b2BodyDef circleDef;
    circleDef.type = b2_staticBody;
    //circleDef.position.Set(circle.m_p.x, circle.m_p.y);
    circleDef.linearDamping = 0.0f;
    circleDef.angularDamping = 0.01f;
    circleDef.active = true;
    circleBody = myWorld->CreateBody(&circleDef);
    circleBody->SetTransform(b2Vec2(circle.m_p.x, circle.m_p.y), 0);
    //circleBody->SetType(b2_dynamicBody);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &circle;
    fixtureDef.density = 1.0f;
    //makes the ball slightly bouncy
    fixtureDef.restitution = 0.2f;
    circleBody->CreateFixture(&fixtureDef);
    ball_velocity = circleBody->GetLinearVelocity();
}

void Engine::InitializeBorders() {
    int32 rect = 4;
    b2Vec2 vertices[4];
    vertices[0].Set(0.0f, 580.0f);
    vertices[1].Set(600.0f, 580.0f);
    vertices[2].Set(600.0f, 590.0f);
    vertices[3].Set(0.0f, 590.0f);
    edgeShape.Set(vertices, rect);

    b2BodyDef groundDef;
    groundDef.position.Set(300.0f,285.0f);
    groundDef.type = b2_staticBody;
    groundDef.active = true;
    groundBody = myWorld->CreateBody(&groundDef);
    //default is static body, so no need to set type

    b2FixtureDef groundFixDef;
    groundFixDef.shape = &edgeShape;
    groundFixDef.restitution = 0.0f;
    groundFixDef.density = 1.0f;
    groundBody->CreateFixture(&groundFixDef);

    edge.Set(b2Vec2(5, 5), b2Vec2(40, 50));
}

void Engine::CreateEdges() {
  b2EdgeShape edgeShape1;
  edgeShape1.Set(edge_endpoints[0], edge_endpoints[1]);

  b2BodyDef edgeDef;
  edgeDef.type = b2_staticBody;
  b2Vec2 mid_point = b2Vec2((edge_endpoints[0].x + edge_endpoints[1].x)/2,
          (edge_endpoints[0].y + edge_endpoints[1].y)/2);
  edgeDef.position.Set(mid_point.x, mid_point.y);
  b2Body* this_edge;
  this_edge = myWorld->CreateBody(&edgeDef);

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

b2EdgeShape Engine::GetEdge() {
   return edge;
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

vector<b2Vec2> Engine::GetEndPoints() {
  return edge_endpoints;
}

void Engine::AddSurfaces(int x, int y) {
  vector<size_t> adding;
  adding.push_back(x);
  adding.push_back(y);
  surfaces_.push_back(adding);
}

void Engine::AddEndpoints(b2Vec2 x) {
   edge_endpoints.push_back(x);

}

void Engine::MoveBall() {
  circleBody->SetType(b2_dynamicBody);
}

}
