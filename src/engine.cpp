#include "mylibrary/engine.h"

namespace traffic_rush {

Engine::Engine(b2World &this_wrld) {
  my_world = &this_wrld;
}
}