//
// Created by Ankitha Damisetty on 4/19/2020.
//
#include "mylibrary/ball.h"

namespace myapp {
  const size_t radius = 20;
  const size_t buffer = 5;

  Ball::Ball() {}

  void Ball::initialize(b2World &my_world) {
    circle.m_radius = 10.0f;
    circle.m_p = b2Vec2(rand()%40 + 10, 20.0);
    location = circle.m_p;
    b2BodyDef circleDef;
    circleDef.type = b2_dynamicBody;
    //NEED TO MAKE RANDOM POSITION TO START
    circleDef.position.Set(20.0, 20.0);
    circleBody = my_world.CreateBody(&circleDef);

    b2FixtureDef fixDef;
    fixDef.shape = &circle;
    fixDef.restitution = 0.3f;
    fixDef.density = 2.0f;
    circleBody->CreateFixture(&fixDef);
  }

  b2Body* Ball::GetBody() {
    return circleBody;
  }

  b2CircleShape Ball::GetShape() {
    return circle;
  }

  size_t Ball::GetRadius() {
    return circle.m_radius;
  }

  void Ball::DrawSingleBall() {
    cinder::gl::color(0, 1, 1);
    b2Vec2 curr_loc = circleBody->GetPosition();
    cinder::vec2 cinder_loc = cinder::vec2(curr_loc.x, curr_loc.y);
    cinder::gl::drawSolidCircle(cinder::vec2(cinder_loc[0], cinder_loc[1]), circle.m_radius);
  }
}