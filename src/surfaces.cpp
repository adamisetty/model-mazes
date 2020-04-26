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
  float32 x_pos = myapp::Conversions::ConvertToMeters(screen_size/2);
  float32 y_pos = myapp::Conversions::ConvertToMeters(screen_size - buffer);
  ground_def.position.Set(x_pos, y_pos);
  groundBody = my_world.CreateBody(&ground_def);
  groundShape.SetAsBox(x_pos*2, myapp::Conversions::ConvertToMeters(buffer));
  groundBody->CreateFixture(&groundShape, 1.0f);
}

void Surfaces::DrawBox() {
 // b2Vec2 corn_1 = groundShape.GetVertex(0);
 // b2Vec2 corn_2 = groundShape.GetVertex(2);
  b2Vec2 ground_pos = groundBody->GetPosition();
 // cinder::vec2 cinder_corn1 = cinder::vec2(corn_1.x, corn_1.y);
 // cinder::vec2 cinder_corn2 = cinder::vec2(corn_2.x, corn_2.y);
  cinder::gl::color(0, 1, 1);
  float32 c1 = myapp::Conversions::ConvertToPixels(ground_pos.x) - screen_size/2;
  float32 c2 = myapp::Conversions::ConvertToPixels(ground_pos.y) + buffer;
  float32 c3 = myapp::Conversions::ConvertToPixels(ground_pos.x) + screen_size/2;
  float32 c4 = myapp::Conversions::ConvertToPixels(ground_pos.y) - 5*buffer;
  cinder::gl::drawSolidRect(cinder::Rectf(c1, c2, c3, c4));
//  cinder::gl::color(1, 0, 0);
//  cinder::gl::drawSolidRect(cinder::Rectf(cinder_corn1.x, cinder_corn1.y, cinder_corn2.x, cinder_corn2.y));
}
}