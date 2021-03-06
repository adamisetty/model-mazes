// Copyright (c) 2020 [Your Name]. All rights reserved.

#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>

#include "my_app.h"


using cinder::app::App;
using cinder::app::RendererGl;


namespace traffic_rush {

const int kSamples = 10;
const int kWidth = 600;
const int kHeight = 600;

void SetUp(App::Settings* settings) {

  settings->setWindowSize(kWidth, kHeight);
  settings->setResizable(false);
  settings->setTitle("Falling Fun");
}

}  // namespace falling_fun


// This is a macro that runs the application.
CINDER_APP(traffic_rush::MyApp,
           RendererGl(RendererGl::Options().msaa(traffic_rush::kSamples)),
           traffic_rush::SetUp)
