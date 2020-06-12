
#ifndef FINALPROJECT_EXAMPLE_H
#define FINALPROJECT_EXAMPLE_H

#include <Box2D/Box2D.h>
#include <vector>

using std::vector;

namespace traffic_rush {

class Engine {
 public:
  /**
   * Constructor, initialized once in my_app
   * @param this_wrld: b2World created in my_app, passed in by reference
   */
  Engine(b2World &this_wrld);

  /**
   * Creates all the small balls and the box around screen, set up of game
   */
  void Setup();

  void CreateVehicle() {

  }

 private:
  b2World *my_world;
  vector<double> all_vehicles;
};
}
#endif  // FINALPROJECT_EXAMPLE_H