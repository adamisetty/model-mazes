
#ifndef FINALPROJECT_EXAMPLE_H
#define FINALPROJECT_EXAMPLE_H

#include <Box2D/Box2D.h>
#include <mylibrary/vehicle.h>
#include <mylibrary/conversions.h>
#include <cinder/app/App.h>
#include <cinder/gl/gl.h>
#include <vector>
#include <random>
#include <map>
#include <cinder/app/KeyEvent.h>


using std::vector;
using std::map;
using cinder::app::KeyEvent;

const b2Vec2 gravity = b2Vec2(0.0f, 0.0f);
const int32 vel_iter = 3;
const int32 pos_iter = 5;
const float32 time_step = 1.0/60.0f;
const size_t num_v = 2;
const unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

namespace traffic_rush {

class Engine {
 public:
  Engine();
  void SetUp(vector<cinder::gl::TextureRef> &images_);
  void SetMaps();
  void CreateVehicle();
  void Step();
  void DrawEngine();
  void UpdateScore();
  cinder::gl::TextureRef GetImage(size_t position);
  bool GetIsPlaying();
  int GetScore();
  cinder::Timer* GetTimer();
  void KeyAction(int user_action_);
  void SpeedAction(int user_action_);
  void DestroyEngine();
  void ResetEngine();
  bool CheckProximity(size_t position);

 public:
  class MyContactListener : public b2ContactListener {
    void BeginContact(b2Contact* contact);

   public:
    bool is_playing_;
  };

 private:
  b2World my_world_;
  vector<Vehicle> all_vehicles_;
  map<int, b2Vec2> start_positions_;
  map<int, b2Vec2> start_velocities_;
  map<int, cinder::gl::TextureRef> start_images_;
  cinder::Timer game_timer_;
  MyContactListener my_listener_;
  int score_;
  Vehicle* current_vehicle_;
  int target_index_;
  vector<cinder::gl::TextureRef> my_images_;
  int last_timestamp_;
  int frequency;
  std::default_random_engine generator;
};
}
#endif  // FINALPROJECT_EXAMPLE_H