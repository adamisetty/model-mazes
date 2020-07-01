#ifndef FINALPROJECT_VEHICLE_H
#define FINALPROJECT_VEHICLE_H

#include <Box2D/Box2D.h>
#include <mylibrary/conversions.h>
#include <cinder/gl/gl.h>

#include <random>

const size_t num_positions = 4;
const size_t vel_buffer = 2;
const double vel_start = .5;

namespace traffic_rush {
  class Vehicle {
   public:
    Vehicle();
    ~Vehicle();

    // should set initial position and velocity
    void Initialize(b2World *this_world_, b2Vec2 start_p, b2Vec2 start_v,
        cinder::gl::TextureRef my_image_, cinder::gl::TextureRef star);
    void DrawVehicle();
    void CheckInBounds();
    bool GetIsVisible();
    bool GetIsDestroyed();
    void DestroyVehicle();
    b2Body* GetBody();
    void ChangeSpeed(bool is_stop_);
    void MarkTarget();

   private:
    b2PolygonShape shape_;
    b2Body *vehicle_body_;
    vector<double> color;
    bool is_visible_;
    bool is_destroyed_;
    b2Vec2 velocity_vector_;
    bool is_target_;
    cinder::gl::TextureRef vehicle_image_;
    bool is_vertical;
    cinder::gl::TextureRef star_;
  };
}
#endif  // FINALPROJECT_VEHICLE_H
