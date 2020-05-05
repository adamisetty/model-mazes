// Copyright (c) 2020 Ankitha Damisetty. All rights reserved.

#include "mylibrary/edge.h"
namespace myapp {

const float32 small_distance = 0.002;
const float32 density = 0.0f;

  myapp::Edge::Edge() {}

  void myapp::Edge::initialize(b2World *my_world, b2Vec2 start, b2Vec2 end) {
    b2BodyDef sample_edge;
    //creates body centered at the midpoint of the line segment given
    sample_edge.position.Set((start.x + end.x)/2, (start.y + end.y)/2);
    edgeBody = my_world->CreateBody(&sample_edge);

    //must transform the shape to be at the same angle as the drawn line
    float32 angle = atan((start.y - end.y)/ (start.x - end.x));
    edgeBody->SetTransform(edgeBody->GetPosition(), angle);

    //fixture must be the same length as distance between start and end
    float distance = (end.x - start.x) * (end.x - start.x)
                     + (end.y - start.y)*(end.y - start.y);
    distance = sqrt(distance);
    edgeShape.SetAsBox(distance/2, small_distance);
    edgeBody->CreateFixture(&edgeShape, density);

    //Printing Edge occurs in the engine class
  }


}