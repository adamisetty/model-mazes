// Copyright (c) 2020 Ankitha Damisetty. All rights reserved.

#include <mylibrary/conversions.h>

namespace myapp {
  float32 myapp::Conversions::ToPixels(float32 b2_number) {
    return b2_number * 50.0f;
  }

  float32 myapp::Conversions::ToMeters(float32 cinder_number) {
    return cinder_number * 0.02;
  }

  vector<double> Conversions::ColorChooser(int position) {
    size_t num_colors = 20;
    vector<vector<double>> colors{{197, 113, 227}, {193, 179, 215},
        {165, 137, 193}, {227, 113, 172}, {251, 182, 209}, {249, 140, 182},
        {113, 200, 227}, {154, 206, 233}, {111, 183, 214}, {191, 213, 232},
        {148, 168, 208}, {117, 137, 191}, {113, 227, 132}, {181, 255, 174},
        {145, 210, 144}, {109, 180, 201}, {134, 207, 190}, {72, 181, 163},
        {191, 228, 118}, {133, 202, 93}};
    //vector<vector<double>> all_colors{{239, 53, 111}, {247, 103, 101},
      //                     {249, 149, 51}, {244, 206, 109}, {121, 105, 153},
        //                   {25, 66, 110}, {25, 149, 104}, {52, 161, 152}};
    if (position >= 0) {
      return colors[position];
    } else{
      size_t pos = rand() % num_colors;
      return colors[pos];
    }
  }

  vector<double> Conversions::ToCinderRBG(vector<double> regular_RBG) {
    double converter = 255;
    for (size_t i = 0; i < regular_RBG.size(); i++) {
      regular_RBG[i] = regular_RBG[i]/converter;
    }
    return regular_RBG;
  }

  }  // namespace falling_fun

