
#ifndef FINALPROJECT_EXAMPLE_H
#define FINALPROJECT_EXAMPLE_H

#include <Box2D/Box2D.h>
#include <vector>
#include <mylibrary/vehicle.h>

using std::vector;
const b2Vec2 gravity = b2Vec2(0.0f, 0.0f);
const int32 vel_iter = 3;
const int32 pos_iter = 5;
const float32 time_step = 1.0/60.0f;

namespace traffic_rush {

class Engine {
 public:
  Engine();
  void SetUp();
  void CreateVehicle();
  void Step();
  void DrawEngine();

 private:
  b2World my_world_;
  vector<Vehicle> all_vehicles_;
};
}
#endif  // FINALPROJECT_EXAMPLE_H