// Copyright (c) 2020 Ankitha Damisetty. All rights reserved.

#include <mylibrary/conversions.h>

namespace myapp {
    float32 myapp::Conversions::ToPixels(float32 b2_number) {
        return b2_number * 50.0f;
    }
    float32 myapp::Conversions::ToMeters(float32 cinder_number) {
        return cinder_number * 0.02;
    }
}  // namespace falling_fun

