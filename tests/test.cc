// Copyright (c) 2020 CS126SP20. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <Box2D/Box2D.h>
#include <mylibrary/conversions.h>

#include <vector>

TEST_CASE("Convert to Pixels", "[conversions]") {
  float32 input = 2;
  const float expected = 50 * input;
  float32 result = myapp::Conversions::ToPixels(input);
  REQUIRE(expected == result);

  float32 n_input = -1;
  const float n_expected = 50 * n_input;
  float32 n_result = myapp::Conversions::ToPixels(n_input);
  REQUIRE(n_expected == n_result);
}

TEST_CASE("Convert to Meters", "[conversions]") {
  float32 input = 100;
  const float expected = 0.02 * input;
  float32 result = myapp::Conversions::ToMeters(input);
  REQUIRE(expected == result);

  float32 n_input = -100;
  const float n_expected = 0.02 * n_input;
  float32 n_result = myapp::Conversions::ToMeters(n_input);
  REQUIRE(n_expected == n_result);
}

TEST_CASE("Get Specific Color", "[conversions]") {
  std::vector<double> expected{165, 137, 193};
  std::vector<double> result = myapp::Conversions::ColorChooser(2);
  REQUIRE(expected == result);

  std::vector<double> random_1 = myapp::Conversions::ColorChooser(25);
  std::vector<double> random_2 = myapp::Conversions::ColorChooser(-1);
  REQUIRE(random_1 != random_2);
}

TEST_CASE("Convert to RGB", "[conversions]") {
  std::vector<double> regular_rbg{255, 255, 255};
  std::vector<double> expected{1, 1, 1};
  std::vector<double> result = myapp::Conversions::ToCinderRBG(regular_rbg);
  REQUIRE(expected == result);

  std::vector<double> g_expected{165.0/255, 137.0/255, 193.0/255};
  std::vector<double> g_result = myapp::Conversions::ToCinderRBG(
      myapp::Conversions::ColorChooser(2));
  REQUIRE(g_expected == g_result);
}