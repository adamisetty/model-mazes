#include <mylibrary/vehicle.h>
#include <cinder/gl/draw.h>
#include <cinder/gl/gl.h>

using cinder::vec2;

namespace traffic_rush {
  Vehicle::Vehicle() {

  }

  void Vehicle::Initialize(b2World *this_world_) {
    int location = 300;
    shape_.m_p = b2Vec2(Conversions::ToMeters(location),
        Conversions::ToMeters(location));

    int radius = 10;
    shape_.m_radius = Conversions::ToMeters(radius);

    b2BodyDef def_;
    def_.position.Set(shape_.m_p.x, shape_.m_p.y);

    vehicle_body_ = this_world_->CreateBody(&def_);

    b2FixtureDef fix_def_;
    fix_def_.density = 1.0f;
    fix_def_.shape = &shape_;
    fix_def_.restitution = .1f;
    vehicle_body_->CreateFixture(&fix_def_);
    vehicle_body_->SetType(b2_dynamicBody);
  }

  void Vehicle::DrawVehicle() {
    cinder::gl::color(0, 1, 1);
    b2Vec2 curr_loc = vehicle_body_->GetPosition();
    vec2 c_loc = vec2(traffic_rush::Conversions::ToPixels(curr_loc.x),
                      traffic_rush::Conversions::ToPixels(curr_loc.y));
    cinder::gl::drawSolidCircle(vec2(c_loc[0], c_loc[1]),
                                traffic_rush::Conversions::ToPixels(shape_.m_radius));
  }
}
