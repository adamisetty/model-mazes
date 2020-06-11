#include <mylibrary/conversions.h>

namespace traffic_rush {

  float32 traffic_rush::Conversions::ToPixels(float32 b2_number) {
    return b2_number * 50.0f;
  }

  float32 traffic_rush::Conversions::ToMeters(float32 cinder_number) {
    return cinder_number * 0.02;
  }
}