
#ifndef FINALPROJECT_EXAMPLE_H
#define FINALPROJECT_EXAMPLE_H

#include <Box2D/Box2D.h>
#include <mylibrary/vehicle.h>
#include <mylibrary/conversions.h>
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
  b2Vec2 GetPosition(size_t position);
  b2Vec2 GetVelocity(size_t position);

 private:
  b2World my_world_;
  vector<Vehicle> all_vehicles_;
  map<int, b2Vec2> start_positions_;
  map<int, b2Vec2> start_velocities_;
};
}
#endif  // FINALPROJECT_EXAMPLE_H