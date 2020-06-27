// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_PLAYER_H
#define FINALPROJECT_PLAYER_H

#include <string>

namespace traffic_rush {

struct Player {
  Player(const std::string& name, size_t score) : name(name), score(score) {}
  std::string name;
  size_t score;
};

}  // namespace traffic_rush

#endif  // FINALPROJECT_PLAYER_H
