//
// Created by Ankitha Damisetty on 4/26/2020.
//

#include "mylibrary/edge.h"
namespace myapp {
  myapp::Edge::Edge() {}

  void myapp::Edge::initialize(b2World &my_world, b2Vec2 start, b2Vec2 end) {
    edgeShape.Set(start, end);
    b2BodyDef edgeDef;
    edgeDef.position.Set((start.x + end.x)/2, (end.x + end.y)/2);
    edgeBody = my_world.CreateBody(&edgeDef);

    b2FixtureDef fixDef;
    fixDef.shape = &edgeShape;
    fixDef.restitution = 0.5f;
    fixDef.density = 1.0f;
    edgeBody->CreateFixture(&fixDef);
    m_start = start;
    m_end = end;
  }

  void myapp::Edge::DrawEdge() {
    cinder::gl::color(0, 1, 1);
    cinder::vec2 cinder_s = cinder::vec2(Conversions::ConvertToPixels(m_start.x), Conversions::ConvertToPixels(m_start.y));
    cinder::vec2 cinder_e = cinder::vec2(Conversions::ConvertToPixels(m_end.x), Conversions::ConvertToPixels(m_end.y));
    cinder::gl::drawLine(cinder_s, cinder_e);
  }

}