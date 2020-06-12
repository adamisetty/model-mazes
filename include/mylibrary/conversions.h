
#ifndef FINALPROJECT_CONVERSIONS_H
#define FINALPROJECT_CONVERSIONS_H

#include <vector>
#include <random>
#include <Box2D/Box2D.h>

namespace traffic_rush {
  using std::vector;

  /**
   * Class, with only static methods, used to combat the differences in units.
   * Box2d (the library used for physics simulation) measures each cinder pixel as
   * one meter, which is too large for accurate simulations.
   */
  class Conversions {
   public:
    /**
     * Gives the b2_number as a number that can be used by cinder accurately
     * @param b2_number: float32 number measured in meters by box2d
     * @return: float32 number measured in pixels by cinder
     */
    static float32 ToPixels(float32 b2_number);

    /**
     * Gives the cinder_number as number that can be used by box2d accurately
     * @param cinder_number: float32 number measured in pixels by cinder
     * @return: float32 number measured in meters by box2d
     */
    static float32 ToMeters(float32 cinder_number);
  };
}

#endif  // FINALPROJECT_CONVERSIONS_H
