// Copyright (c) 2020 Ankitha Damisetty. All rights reserved.
#ifndef FINALPROJECT_MYLIBRARY_EXAMPLE_H_
#define FINALPROJECT_MYLIBRARY_EXAMPLE_H_
#include <vector>
#include <Box2D/Box2D.h>

namespace myapp {
  class Conversions{
    public:
      static float32 ToPixels(float32 b2_number);
      static float32 ToMeters(float32 cinder_number);
  };
}  // namespace falling_fun


#endif // FINALPROJECT_MYLIBRARY_EXAMPLE_H_
