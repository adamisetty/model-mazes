#include <mylibrary/vehicle.h>
#include <cinder/gl/draw.h>
#include <cinder/gl/gl.h>

using cinder::vec2;

namespace traffic_rush {
  Vehicle::Vehicle() {
    is_visible_ = true;
    is_destroyed_ = false;
    is_target_ = false;
  }

  void Vehicle::Initialize(b2World *this_world_, b2Vec2 start_p, b2Vec2 start_v,
      cinder::gl::TextureRef my_image_, cinder::gl::TextureRef star) {

    is_vertical = (start_v.x == 0);

    //float32 radius = 22;
    //shape_.m_radius = Conversions::ToMeters(radius);

    b2BodyDef def_;
    def_.position.Set(start_p.x, start_p.y);
    //shape_.m_p = b2Vec2(0, 0);

    if (is_vertical) {
      shape_.SetAsBox(Conversions::ToMeters(20), Conversions::ToMeters(45));
    } else {
      shape_.SetAsBox(Conversions::ToMeters(45), Conversions::ToMeters(20));
    }

    vehicle_body_ = this_world_->CreateBody(&def_);
    vehicle_body_->CreateFixture(&shape_, 1.0f);

    /*b2FixtureDef fix_def_;
    fix_def_.density = 1.0f;
    fix_def_.shape = &shape_;
    fix_def_.restitution = 0.7f;
    vehicle_body_->CreateFixture(&fix_def_);*/

    vehicle_body_->SetType(b2_dynamicBody);

    double velocity = (rand() % vel_buffer) + vel_start;
    velocity_vector_ = b2Vec2(start_v.x * velocity, start_v.y * velocity);
    vehicle_body_->SetLinearVelocity(velocity_vector_);

    vehicle_image_ = my_image_;
    star_ = star;
    color = Conversions::ColorChooser(-1);
    color = Conversions::ToCinderRBG(color);
  }

  void Vehicle::CheckInBounds() {
    b2Vec2 curr_loc = vehicle_body_->GetPosition();
    vec2 c_loc = vec2(traffic_rush::Conversions::ToPixels(curr_loc.x),
                      traffic_rush::Conversions::ToPixels(curr_loc.y));
    if (c_loc[0] > 600 || c_loc[0] < 0 || c_loc[1] > 600 || c_loc[1] < 0) {
      is_visible_ = false;
    }
    if (vehicle_body_->GetType() == b2_staticBody) {
      is_destroyed_ = true;
    }
  }

  void Vehicle::DestroyVehicle() {
    vehicle_body_->SetType(b2_staticBody);
    vehicle_body_->SetTransform(b2Vec2(-shape_.m_radius -
    Conversions::ToMeters(700), -shape_.m_radius -
    Conversions::ToMeters(700)), 0);
  }

  void Vehicle::MarkTarget() {
    is_target_ = !is_target_;
  }

  b2Body * Vehicle:: GetBody() {
    return vehicle_body_;
  }
  bool Vehicle::GetIsVisible() {
    return is_visible_;
  }

  bool Vehicle::GetIsDestroyed() {
    return is_destroyed_;
  }

  bool Vehicle::GetIsTarget() {
    return is_target_;
  }

  void Vehicle::ChangeSpeed(bool is_stop_) {
    if (is_stop_) {
      vehicle_body_->SetLinearVelocity(b2Vec2(0, 0));
    } else {
      if (vehicle_body_->GetLinearVelocity() == b2Vec2(0, 0)) {
        vehicle_body_->SetLinearVelocity(velocity_vector_);
      } else {
        if (!(abs(vehicle_body_->GetLinearVelocity().x) > 5 || abs(vehicle_body_->GetLinearVelocity().y) > 5)) {
          vehicle_body_->SetLinearVelocity(1.5 * vehicle_body_->GetLinearVelocity());
        }
      }
    }
  }

  void Vehicle::DrawVehicle() {

    cinder::gl::color(color[0], color[1], color[2]);
    b2Vec2 curr_loc = vehicle_body_->GetPosition();

    vec2 c_loc = vec2(traffic_rush::Conversions::ToPixels(curr_loc.x),
                      traffic_rush::Conversions::ToPixels(curr_loc.y));

    //cinder::gl::drawSolidCircle(vec2(c_loc[0], c_loc[1]), traffic_rush::Conversions::ToPixels(shape_.m_radius));

    if (is_vertical) {
      cinder::gl::draw(vehicle_image_, vec2(c_loc[0] - 22, c_loc[1] - 50));
    } else {
      cinder::gl::draw(vehicle_image_, vec2(c_loc[0] - 50, c_loc[1] - 22));
    }

    if (is_target_) {
      cinder::gl::color(1, 1, 1);
      cinder::gl::draw(star_, vec2(c_loc[0] - 10, c_loc[1] - 10));
    }
  }

  Vehicle::~Vehicle() = default;

}
