//
// Created by Ankitha Damisetty on 4/19/2020.
//
#include "mylibrary/surfaces.h"

namespace myapp {
const size_t screen_size = 600;
const size_t buffer = 5;

Surfaces::Surfaces() {}

void Surfaces::CreateBox(b2World &my_world) {
  b2BodyDef ground_def;
  ground_def.position.Set(screen_size/2, screen_size - buffer);
  groundBody = my_world.CreateBody(&ground_def);
  groundShape.SetAsBox(screen_size,  buffer);
  groundBody->CreateFixture(&groundShape, 1.0f);
}

void Surfaces::DrawBox() {
  b2Vec2 corn_1 = groundShape.GetVertex(0);
  b2Vec2 corn_2 = groundShape.GetVertex(2);
  b2Vec2 ground_pos = groundBody->GetPosition();
  cinder::gl::color(0, 1, 1);
  cinder::gl::drawSolidRect(cinder::Rectf(ground_pos.x - screen_size/2,
          ground_pos.y + buffer, ground_pos.x + screen_size/2,
          screen_size - 5* buffer));
}
}