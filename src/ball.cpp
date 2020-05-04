// Copyright (c) 2020 Ankitha Damisetty. All rights reserved.
#include "mylibrary/ball.h"

namespace myapp {

  using cinder::vec2;

  Ball::Ball() {}

  void Ball::initialize(b2World *my_world, float32 s_x) {
    //randomize color
    color_vals = myapp::Conversions::ColorChooser();
    color_vals = myapp::Conversions::ToCinderRBG(color_vals);
    circle.m_radius = myapp::Conversions::ToMeters(radius);
    s_x = myapp::Conversions::ToMeters(s_x);
    float32 start_x = s_x + myapp::Conversions::ToMeters(rand() % buffer);
    float32 start_y = myapp::Conversions::ToMeters(rand() % (buffer*3));
    circle.m_p = b2Vec2(start_x, start_y);
    location = circle.m_p;
    circle.m_p = b2Vec2(0, 0);

    b2BodyDef circleDef;
    circleDef.position.Set(location.x, location.y);
    circleBody = my_world->CreateBody(&circleDef);

    b2FixtureDef fixDef;
    fixDef.shape = &circle;
    fixDef.restitution = 0.5f;
    fixDef.density = 1.0f;
    circleBody->CreateFixture(&fixDef);
  }

  void Ball::ActivateBall() {
    b2Vec2 start = location;
    circleBody->SetType(b2_dynamicBody);
    circle.m_p = start;
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