//
// Created by Ankitha Damisetty on 4/26/2020.
//

#include "mylibrary/edge.h"
namespace myapp {
  myapp::Edge::Edge() {}

  void myapp::Edge::initialize(b2World *my_world, b2Vec2 start, b2Vec2 end) {
    b2BodyDef sample_edge;
    sample_edge.position.Set((start.x + end.x)/2, (start.y + end.y)/2);
    edgeBody = my_world->CreateBody(&sample_edge);
    float32 angle = atan((start.y - end.y)/ (start.x - end.x));
    edgeBody->SetTransform(edgeBody->GetPosition(), angle);
    float distance = (end.x - start.x) * (end.x - start.x)
                     + (end.y - start.y)*(end.y - start.y);
    distance = sqrt(distance);
    edgeShape.SetAsBox(distance/2, 0.002);
    edgeBody->CreateFixture(&edgeShape, 0.0f);
    m_start = start;
    m_end = end;
  }

  void myapp::Edge::DrawEdge() {
    cinder::gl::color(0, 1, 1);
    cinder::vec2 c_start = cinder::vec2(Conversions::ConvertToPixels(m_start.x),
                                  Conversions::ConvertToPixels(m_start.y));
    cinder::vec2 c_end = cinder::vec2(Conversions::ConvertToPixels(m_end.x),
                                  Conversions::ConvertToPixels(m_end.y));
    cinder::gl::drawLine(c_start, c_end);
  }

}