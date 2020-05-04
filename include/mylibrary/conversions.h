// Copyright (c) 2020 Ankitha Damisetty. All rights reserved.
#ifndef FINALPROJECT_MYLIBRARY_EXAMPLE_H_
#define FINALPROJECT_MYLIBRARY_EXAMPLE_H_
#include <vector>
#include <random>
#include <Box2D/Box2D.h>

namespace myapp {
using std::vector;
  class Conversions{
    public:
      static float32 ToPixels(float32 b2_number);
      static float32 ToMeters(float32 cinder_number);
      static vector<double> ColorChooser(int position);
      static vector<double> ToCinderRBG(vector<double> regular_RBG);
  };
}  // namespace falling_fun


#endif // FINALPROJECT_MYLIBRARY_EXAMPLE_H_
