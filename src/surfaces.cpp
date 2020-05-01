//
// Created by Ankitha Damisetty on 4/19/2020.
//
#include "mylibrary/surfaces.h"

namespace myapp {
const size_t screen_size = 600;
const size_t buffer = 5;

Surfaces::Surfaces() {}

void Surfaces::CreateBox(b2World *my_world) {
  my_wrld = my_world;
  b2BodyDef ground_def;
  float32 x_pos = myapp::Conversions::ConvertToMeters(screen_size/2);
  float32 y_pos = myapp::Conversions::ConvertToMeters(screen_size - buffer);
  ground_def.position.Set(x_pos, y_pos);
  groundBody = my_world->CreateBody(&ground_def);
  groundShape.SetAsBox(x_pos*2, myapp::Conversions::ConvertToMeters(buffer));
  groundBody->CreateFixture(&groundShape, 0.0f);

  b2BodyDef left_wall_def;
  float32 l_wall_x = myapp::Conversions::ConvertToMeters(buffer);
  float32 l_wall_y = myapp::Conversions::ConvertToMeters(screen_size/2);
  left_wall_def.position.Set(l_wall_x, l_wall_y);
  leftWallBody = my_world->CreateBody(&left_wall_def);
  leftWallShape.SetAsBox(l_wall_x, l_wall_y);
  leftWallBody->CreateFixture(&leftWallShape, 0.0f);
  std::cout << "left wall finished ";

  b2BodyDef right_wall_def;
  float32 r_wall_x =  myapp::Conversions::ConvertToMeters(595);//myapp::Conversions::ConvertToMeters(screen_size - buffer);
  float32 r_wall_y = myapp::Conversions::ConvertToMeters(screen_size/2);
  right_wall_def.position.Set(r_wall_x, r_wall_y);
  rightWallBody = my_world->CreateBody(&right_wall_def);
  rightWallShape.SetAsBox(l_wall_x, l_wall_y);
  rightWallBody->CreateFixture(&rightWallShape, 0.0f);
  std::cout << "right wall finished";
/*
  b2Vec2 start = b2Vec2(myapp::Conversions::ConvertToMeters(m_start.x),
                        myapp::Conversions::ConvertToMeters(m_start.y));
  b2Vec2 end = b2Vec2(myapp::Conversions::ConvertToMeters(m_end.x),
                      myapp::Conversions::ConvertToMeters(m_end.y));


  b2BodyDef sample_edge;
  sample_edge.position.Set((start.x + end.x)/2, (start.y + end.y)/2);
  edgeBody = my_world->CreateBody(&sample_edge);
  float32 angle = atan((start.y - end.y)/ (start.x - end.x));
  edgeBody->SetTransform(edgeBody->GetPosition(), angle);
  float distance = (end.x - start.x) * (end.x - start.x) + (end.y - start.y)*(end.y - start.y);
  distance = sqrt(distance);
  edgeShape.SetAsBox(distance/2, 0.002);
  edgeBody->CreateFixture(&edgeShape, 0.0f);*/

}

void Surfaces::DrawBox() {
  DrawEdges();
  //Draws Ground
  b2Vec2 ground_pos = groundBody->GetPosition();
  cinder::gl::color(0, 1, 1);
  float32 c1 = myapp::Conversions::ConvertToPixels(ground_pos.x) - screen_size/2;
  float32 c2 = myapp::Conversions::ConvertToPixels(ground_pos.y) + buffer;
  float32 c3 = myapp::Conversions::ConvertToPixels(ground_pos.x) + screen_size/2;
  float32 c4 = myapp::Conversions::ConvertToPixels(ground_pos.y) - buffer;
  cinder::gl::drawSolidRect(cinder::Rectf(c1, c2, c3, c4));

  //Draws left wall
  b2Vec2 left_wall_pos = leftWallBody->GetPosition();
  cinder::gl::color(0, 1, 1);
  float32 l_c1 = myapp::Conversions::ConvertToPixels(left_wall_pos.x);
  float32 l_c2 = myapp::Conversions::ConvertToPixels(left_wall_pos.y) + screen_size/2;
  float32 l_c3 = myapp::Conversions::ConvertToPixels(left_wall_pos.x) + buffer;
  float32 l_c4 = myapp::Conversions::ConvertToPixels(left_wall_pos.y) - screen_size/2;
  cinder::gl::drawSolidRect(cinder::Rectf(l_c1, l_c2, l_c3, l_c4));

  //Draws right wall
  cinder::gl::color(0, 0, 1);
  b2Vec2 right_wall_pos = rightWallBody->GetPosition();
  float32 r_cl =  myapp::Conversions::ConvertToPixels(right_wall_pos.x);
  float32 r_c2 = myapp::Conversions::ConvertToPixels(right_wall_pos.y) + screen_size/2;
  float32 r_c3 = myapp::Conversions::ConvertToPixels(right_wall_pos.x) + buffer;
  float32 r_c4 = myapp::Conversions::ConvertToPixels(right_wall_pos.y) - screen_size/2;
  cinder::gl::drawSolidRect(cinder::Rectf(r_cl, r_c2, r_c3, r_c4));
}

void Surfaces::SetEdges(vector<cinder::vec2> points) {
    for (size_t i = 1; i < points.size(); i = i + 2) {
        b2Vec2 b2_start  = b2Vec2(Conversions::ConvertToMeters(points[i].x), Conversions::ConvertToMeters(points[i].y));
        b2Vec2 b2_end  = b2Vec2(Conversions::ConvertToMeters(points[i - 1].x), Conversions::ConvertToMeters(points[i - 1].y));
        myapp::Edge next_edge;
        next_edge.initialize(my_wrld, b2_start, b2_end);
        drawn_edges.push_back(next_edge);
    }
}

void Surfaces::DrawEdges() {
  for (myapp::Edge edge: drawn_edges) {
    edge.DrawEdge();
  }
}

}