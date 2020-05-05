// Copyright (c) 2020 Ankitha Damisetty. All rights reserved.
#ifndef FINALPROJECT_MYLIBRARY_EXAMPLE_H_
#define FINALPROJECT_MYLIBRARY_EXAMPLE_H_
#include <vector>
#include <random>
#include <Box2D/Box2D.h>

namespace myapp {
using std::vector;

/**
 * Class with only static methods, used to combat the differences in units.
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

      /**
       * Contains an array of all colors in game's color pallete, chooses one
       * @param position: a specific index of a color in the color pallete, will
       * give random color if position is out of bounds
       * @return: a vector of doubles (rbg values) of specific color in pallete
       */
      static vector<double> ColorChooser(int position);

      /**
       * Cinder uses decimal values of cinder::gl::color function, used to
       * convert between the two variations of RBG values
       * @param regular_RBG: vector of 3 doubles on a 255 scale
       * @return: vector or 3 doubles on a 1/255 scale
       */
      static vector<double> ToCinderRBG(vector<double> regular_RBG);
  };
}  // namespace falling_fun


#endif // FINALPROJECT_MYLIBRARY_EXAMPLE_H_
