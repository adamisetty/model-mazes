//
// Created by Ankitha Damisetty on 4/19/2020.
//
#include "mylibrary/surfaces.h"

namespace myapp {
const size_t screen_size = 600;
const size_t buffer = 5;

Surfaces::Surfaces() {}

void Surfaces::CreateBox(b2World &my_world) {
  my_wrld = &my_world;
  b2BodyDef ground_def;
  float32 x_pos = myapp::Conversions::ConvertToMeters(screen_size/2);
  float32 y_pos = myapp::Conversions::ConvertToMeters(screen_size - buffer);
  ground_def.position.Set(x_pos, y_pos);
  groundBody = my_world.CreateBody(&ground_def);
  groundShape.SetAsBox(x_pos*2, myapp::Conversions::ConvertToMeters(buffer));
  groundBody->CreateFixture(&groundShape, 1.0f);

  b2BodyDef left_wall_def;
  float32 l_wall_x = myapp::Conversions::ConvertToMeters(buffer);
  float32 l_wall_y = myapp::Conversions::ConvertToMeters(screen_size/2);
  left_wall_def.position.Set(l_wall_x, l_wall_y);
  leftWallBody = my_world.CreateBody(&left_wall_def);
  leftWallShape.SetAsBox(l_wall_x, l_wall_y);
  leftWallBody->CreateFixture(&leftWallShape, 1.0f);
/*
  b2BodyDef right_wall_def;
  float32 r_wall_x =  myapp::Conversions::ConvertToMeters(350);//myapp::Conversions::ConvertToMeters(screen_size - buffer);
  float32 r_wall_y = myapp::Conversions::ConvertToMeters(screen_size/2);
  right_wall_def.position.Set(r_wall_x, r_wall_y);
  rightWallBody = my_world.CreateBody(&right_wall_def);
  rightWallShape.SetAsBox(r_wall_x, r_wall_y);
  rightWallBody->CreateFixture(&rightWallShape, 1.0f);*/
}

void Surfaces::DrawBox() {
    if (drawn_edges.size() == 0) {
        cinder::gl::color(1, 0, 0);
        cinder::gl::drawSolidRect(cinder::Rectf(20, 10, 50, 20));
    }
  DrawEdges();
  //Draws Ground
  b2Vec2 ground_pos = groundBody->GetPosition();
  cinder::gl::color(0, 1, 1);
  float32 c1 = myapp::Conversions::ConvertToPixels(ground_pos.x) - screen_size/2;
  float32 c2 = myapp::Conversions::ConvertToPixels(ground_pos.y) + buffer;
  float32 c3 = myapp::Conversions::ConvertToPixels(ground_pos.x) + screen_size/2;
  float32 c4 = myapp::Conversions::ConvertToPixels(ground_pos.y) - 5*buffer;
  cinder::gl::drawSolidRect(cinder::Rectf(c1, c2, c3, c4));

  //Draws left wall
  b2Vec2 left_wall_pos = leftWallBody->GetPosition();
  cinder::gl::color(0, 1, 1);
  float32 l_c1 = myapp::Conversions::ConvertToPixels(left_wall_pos.x);
  float32 l_c2 = myapp::Conversions::ConvertToPixels(left_wall_pos.y) + screen_size/2;
  float32 l_c3 = myapp::Conversions::ConvertToPixels(left_wall_pos.x) + buffer;
  float32 l_c4 = myapp::Conversions::ConvertToPixels(left_wall_pos.y) - screen_size/2;
  cinder::gl::drawSolidRect(cinder::Rectf(l_c1, l_c2, l_c3, l_c4));
/*
  //Draws right wall
  cinder::gl::color(0, 0, 1);
  b2Vec2 right_wall_pos = rightWallBody->GetPosition();
  float32 r_cl =  myapp::Conversions::ConvertToPixels(right_wall_pos.x);
  float32 r_c2 = myapp::Conversions::ConvertToPixels(right_wall_pos.y) + screen_size/2;
  float32 r_c3 = myapp::Conversions::ConvertToPixels(right_wall_pos.x) + buffer;
  float32 r_c4 = myapp::Conversions::ConvertToPixels(right_wall_pos.y) - screen_size/2;
  cinder::gl::drawSolidRect(cinder::Rectf(r_cl, r_c2, r_c3, r_c4));*/

}

void Surfaces::AddToEdges(b2Vec2 start, b2Vec2 end) {
  b2Vec2 b2_start  = b2Vec2(Conversions::ConvertToMeters(start.x), Conversions::ConvertToMeters(start.y));
  b2Vec2 b2_end  = b2Vec2(Conversions::ConvertToMeters(end.x), Conversions::ConvertToMeters(end.y));
  myapp::Edge next_edge;
  drawn_edges.push_back(next_edge);
  next_edge.initialize(*my_wrld, b2_start, b2_end);
}

void Surfaces::DrawEdges() {

  for (myapp::Edge edge: drawn_edges) {
    edge.DrawEdge();
  }
}

}