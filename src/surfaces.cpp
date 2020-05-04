// Copyright (c) 2020 Ankitha Damisetty. All rights reserved.
#include "mylibrary/surfaces.h"

namespace myapp {

const size_t screen_size = 600;
const size_t buffer = 5;
const vector<double> purple = myapp::Conversions::ToCinderRBG
    (myapp::Conversions::ColorChooser(2));

Surfaces::Surfaces() {}

void Surfaces::CreateBox(b2World *my_world) {
  my_wrld = my_world;

  //creates ground body
  b2BodyDef ground_def;
  float32 x_pos = myapp::Conversions::ToMeters(screen_size/2);
  float32 y_pos = myapp::Conversions::ToMeters(screen_size - buffer);
  ground_def.position.Set(x_pos, y_pos);
  ground_body = my_world->CreateBody(&ground_def);
  ground_shape.SetAsBox(x_pos, myapp::Conversions::ToMeters(buffer));
  ground_body->CreateFixture(&ground_shape, 0.0f);

  //creates left wall body
  b2BodyDef left_wall_def;
  float32 l_wall_x = myapp::Conversions::ToMeters(0);
  float32 l_wall_y = myapp::Conversions::ToMeters(screen_size/2);
  left_wall_def.position.Set(l_wall_x, l_wall_y);
  left_wall_body = my_world->CreateBody(&left_wall_def);
  left_wall_shape.SetAsBox(l_wall_x, l_wall_y);
  left_wall_body->CreateFixture(&left_wall_shape, 0.0f);

  //creates right wall body
  b2BodyDef right_wall_def;
  float32 r_wall_x =  myapp::Conversions::ToMeters(screen_size - buffer);
  float32 r_wall_y = myapp::Conversions::ToMeters(screen_size/2);
  right_wall_def.position.Set(r_wall_x, r_wall_y);
  right_wall_body = my_world->CreateBody(&right_wall_def);
  //both right and left wall fixtures have same dimensions
  right_wall_shape.SetAsBox(l_wall_x, l_wall_y);
  right_wall_body->CreateFixture(&right_wall_shape, 0.0f);
}

void Surfaces::DrawBox() {

  cinder::gl::color(purple[0], purple[1], purple[2]);
  //Draws Ground
  b2Vec2 ground_pos = ground_body->GetPosition();
  float32 c1 = myapp::Conversions::ToPixels(ground_pos.x) - screen_size/2;
  float32 c2 = myapp::Conversions::ToPixels(ground_pos.y) + buffer;
  float32 c3 = myapp::Conversions::ToPixels(ground_pos.x) + screen_size/2;
  float32 c4 = myapp::Conversions::ToPixels(ground_pos.y) - buffer;
  cinder::gl::drawSolidRect(cinder::Rectf(c1, c2, c3, c4));

  //Draws left wall
  b2Vec2 left_wall_pos = left_wall_body->GetPosition();
  float32 l_c1 = myapp::Conversions::ToPixels(left_wall_pos.x);
  float32 l_c2 = myapp::Conversions::ToPixels(left_wall_pos.y) + screen_size/2;
  float32 l_c3 = myapp::Conversions::ToPixels(left_wall_pos.x) + buffer;
  float32 l_c4 = myapp::Conversions::ToPixels(left_wall_pos.y) - screen_size/2;
  cinder::gl::drawSolidRect(cinder::Rectf(l_c1, l_c2, l_c3, l_c4));

  //Draws right wall
  b2Vec2 right_wall_pos = right_wall_body->GetPosition();
  float32 r_cl =  myapp::Conversions::ToPixels(right_wall_pos.x);
  float32 r_c2 = myapp::Conversions::ToPixels(right_wall_pos.y) + screen_size/2;
  float32 r_c3 = myapp::Conversions::ToPixels(right_wall_pos.x) + buffer;
  float32 r_c4 = myapp::Conversions::ToPixels(right_wall_pos.y) - screen_size/2;
  cinder::gl::drawSolidRect(cinder::Rectf(r_cl, r_c2, r_c3, r_c4));
}

void Surfaces::SetEdges(vector<cinder::vec2> points) {
  //Called after drawing period ended, makes edge objects out of drawn edges
  for (size_t i = 1; i < points.size(); i = i + 2) {
    b2Vec2 b2_start  = b2Vec2(Conversions::ToMeters(points[i].x),
                           Conversions::ToMeters(points[i].y));
    b2Vec2 b2_end  = b2Vec2(Conversions::ToMeters(points[i - 1].x),
                        Conversions::ToMeters(points[i - 1].y));
    myapp::Edge next_edge;
    //initializes a new edge per pair of user drawn points
    next_edge.initialize(my_wrld, b2_start, b2_end);
    drawn_edges.push_back(next_edge);
  }
}


}