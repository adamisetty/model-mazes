
#ifndef FINALPROJECT_EXAMPLE_H
#define FINALPROJECT_EXAMPLE_H

#include <Box2D/Box2D.h>
#include <mylibrary/vehicle.h>
#include <mylibrary/conversions.h>
#include <cinder/app/App.h>
#include <cinder/gl/gl.h>
#include <vector>
#include <random>
#include <map>


using std::vector;
using std::map;

const b2Vec2 gravity = b2Vec2(0.0f, 0.0f);
const int32 vel_iter = 3;
const int32 pos_iter = 5;
const float32 time_step = 1.0/60.0f;
const size_t num_v = 2;

namespace traffic_rush {

class Engine {
 public:
  Engine();
  void SetUp();
  void SetMaps();
  void CreateVehicle();
  void Step();
  void DrawEngine();
  void UpdateScore();
  b2Vec2 GetPosition(size_t position);
  b2Vec2 GetVelocity(size_t position);
  bool GetIsPlaying();
  int GetScore();
  void ClickAction(cinder::vec2 position, bool is_left_);
  void DestroyEngine();

 public:
  class MyContactListener : public b2ContactListener {
    void BeginContact(b2Contact* contact);

   public:
    bool is_playing_;
  };

 private:
  b2World my_world_;
  vector<Vehicle> all_vehicles_;
  map<int, b2Vec2> start_positions_;
  map<int, b2Vec2> start_velocities_;
  cinder::Timer game_timer_;
  MyContactListener my_listener_;
  int score_;
};
}
#endif  // FINALPROJECT_EXAMPLE_H