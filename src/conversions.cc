// Copyright (c) 2020 Ankitha Damisetty. All rights reserved.

#include <mylibrary/conversions.h>

namespace myapp {
  float32 myapp::Conversions::ToPixels(float32 b2_number) {
    return b2_number * 50.0f;
  }

  float32 myapp::Conversions::ToMeters(float32 cinder_number) {
    return cinder_number * 0.02;
  }

  vector<double> Conversions::ColorChooser() {
    size_t num_colors = 18;
    vector<vector<double>> colors{{221, 212, 232}, {193, 179, 215},
        {165, 137, 193}, {253, 222, 238}, {251, 182, 209}, {249, 140, 182},
        {204, 236, 239}, {154, 206, 233}, {111, 183, 214}, {191, 213, 232},
        {148, 168, 208}, {117, 137, 191}, {207, 236, 207}, {181, 255, 174},
        {145, 210, 144}, {179, 226, 221}, {134, 207, 190}, {72, 181, 163}};
    //vector<vector<double>> all_colors{{239, 53, 111}, {247, 103, 101},
      //                     {249, 149, 51}, {244, 206, 109}, {121, 105, 153},
        //                   {25, 66, 110}, {25, 149, 104}, {52, 161, 152}};
    size_t pos = rand() % num_colors;
    return colors[pos];
  }

  vector<double> Conversions::ToCinderRBG(vector<double> regular_RBG) {
    double converter = 255;
    for (size_t i = 0; i < regular_RBG.size(); i++) {
      regular_RBG[i] = regular_RBG[i]/converter;
    }
    return regular_RBG;
  }

}  // namespace falling_fun

