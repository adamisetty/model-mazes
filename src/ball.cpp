//
// Created by Ankitha Damisetty on 4/19/2020.
//
#include "mylibrary/ball.h"

namespace myapp {
  const float32 radius = 10;
  const size_t buffer = 5;

  Ball::Ball() {}

  void Ball::initialize(b2World *my_world) {
    //randomize color
    color_values.push_back((rand() % 10 + 1) /10.0);
    color_values.push_back((rand() % 10 + 1) /10.0);
    color_values.push_back((rand() % 10 + 1) /10.0);
    circle.m_radius = myapp::Conversions::ConvertToMeters(radius);
    float32 start_x = myapp::Conversions::ConvertToMeters((rand() % 400 + 100));

    float32 start_y = myapp::Conversions::ConvertToMeters(rand() % 50 + 20);
    circle.m_p = b2Vec2(start_x, start_y);
    location = circle.m_p;
    circle.m_p = b2Vec2(0, 0);

    b2BodyDef circleDef;
    //circleDef.type = b2_dynamicBody;

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
    std::cout << "activate";
  }

  b2Body* Ball::GetBody() {
    return circleBody;
  }

  b2CircleShape Ball::GetShape() {
    return circle;
  }

  void Ball::DrawSingleBall() {
    cinder::gl::color(color_values[0], color_values[1], color_values[2]);
    b2Vec2 curr_loc = circleBody->GetPosition();
    cinder::vec2 cinder_loc = cinder::vec2(myapp::Conversions::ConvertToPixels(curr_loc.x), myapp::Conversions::ConvertToPixels(curr_loc.y));
    cinder::gl::drawSolidCircle(cinder::vec2(cinder_loc[0], cinder_loc[1]),myapp::Conversions::ConvertToPixels(circle.m_radius));
  }
}