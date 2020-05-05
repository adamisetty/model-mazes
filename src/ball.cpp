// Copyright (c) 2020 Ankitha Damisetty. All rights reserved.
#include "mylibrary/ball.h"

namespace myapp {
const float32 radius = 7.5;
const size_t buffer = 10;
const size_t y_buffer = 20;
const float32 finish_buffer = 8;
const float32 restitution = 0.5f;
const float32 density = 1.0f;

using cinder::vec2;

Ball::Ball() {}

void Ball::initialize(b2World *my_world, float32 s_x) {
  //randomize color
  color_vals = myapp::Conversions::ColorChooser(-1);
  color_vals = myapp::Conversions::ToCinderRBG(color_vals);

  circle.m_radius = myapp::Conversions::ToMeters(radius);
  //converts the starting_x from pixels to meters
  s_x = myapp::Conversions::ToMeters(s_x);
  float32 start_x = s_x + myapp::Conversions::ToMeters(rand() % buffer);
  float32 start_y = myapp::Conversions::ToMeters(rand() % y_buffer);
  location = b2Vec2(start_x, start_y);
  //sets m_p to (0, 0) because it represents center with respect to fixture
  circle.m_p = b2Vec2(0, 0);

  b2BodyDef circleDef;
  circleDef.position.Set(location.x, location.y);
  circleBody = my_world->CreateBody(&circleDef);

  b2FixtureDef fixDef;
  fixDef.shape = &circle;
  fixDef.restitution = restitution;
  fixDef.density = density;
  circleBody->CreateFixture(&fixDef);
}

void Ball::ActivateBall() {
  circleBody->SetType(b2_dynamicBody);
}

bool Ball::CheckFinished(cinder::vec2 finish_loc) {
  b2Vec2 curr_loc = circleBody->GetPosition();
  vec2 c_loc = vec2(myapp::Conversions::ToPixels(curr_loc.x),
                    myapp::Conversions::ToPixels(curr_loc.y));
  //checking if this ball has reached the finishing location
  bool cond = abs(c_loc.x - finish_loc.x) <= finish_buffer &&
              abs(c_loc.y - finish_loc.y) <= finish_buffer;
  return cond;
}

void Ball::DiminishBody() {
  //moving the ball to some negative x, no interference with other bodies
  circleBody->SetTransform(b2Vec2(-radius, 0), 0);
  circleBody->SetType(b2_staticBody);
}

void Ball::DrawSingleBall() {
  cinder::gl::color(color_vals[0], color_vals[1], color_vals[2]);
  b2Vec2 curr_loc = circleBody->GetPosition();
  vec2 c_loc = vec2(myapp::Conversions::ToPixels(curr_loc.x),
                    myapp::Conversions::ToPixels(curr_loc.y));
  cinder::gl::drawSolidCircle(vec2(c_loc[0], c_loc[1]),
          myapp::Conversions::ToPixels(circle.m_radius));
}

Ball::~Ball() = default;
}