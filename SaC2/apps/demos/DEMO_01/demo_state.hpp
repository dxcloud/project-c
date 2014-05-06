#ifndef DEMO_STATE_HPP
#define DEMO_STATE_HPP

#include <sac2.hpp>
#include "resource.hpp"

using namespace sac2;

enum {
  WALK_DOWN  = 100,
  WALK_UP    = 101,
  WALK_LEFT  = 102,
  WALK_RIGHT = 103,
  IDLE_DOWN  = 200,
  IDLE_UP    = 201,
  IDLE_LEFT  = 202,
  IDLE_RIGHT = 203
};

const float frame_speed = 0.2;
const float move_speed = 3.0f;

const frame_t f_idle_down    = {point_t(32, 0), 32, 32, frame_speed};
const frame_t f_idle_up      = {point_t(32, 96), 32, 32, frame_speed};
const frame_t f_idle_left    = {point_t(32, 32), 32, 32, frame_speed};
const frame_t f_idle_right   = {point_t(32, 64), 32, 32, frame_speed};

const frame_t f_walk_down_1  = {point_t(0, 0), 32, 32, frame_speed};
const frame_t f_walk_down_2  = {point_t(64, 0), 32, 32, frame_speed};
const frame_t f_walk_up_1    = {point_t(0, 96), 32, 32, frame_speed};
const frame_t f_walk_up_2    = {point_t(64, 96), 32, 32, frame_speed};
const frame_t f_walk_left_1  = {point_t(0, 32), 32, 32, frame_speed};
const frame_t f_walk_left_2  = {point_t(64, 32), 32, 32, frame_speed};
const frame_t f_walk_right_1 = {point_t(0, 64), 32, 32, frame_speed};
const frame_t f_walk_right_2 = {point_t(64, 64), 32, 32, frame_speed};

class Idle: public AnimationState
{
public:
  Idle(frame_t frame): AnimationState() {
    animation().add_frame(frame);
  }
  ~Idle() {}
private:
  animation_state_t handle(animation_state_t state, float dt) {
    animation().play();
    return state;
  }
};

class Walk: public AnimationState
{
public:
  Walk(frame_t f1, frame_t f2): AnimationState() {
    animation().add_frame(f1);
    animation().add_frame(f2);
    animation().set_repeat_enabled();
  }
  ~Walk() {}
private:
  animation_state_t handle(animation_state_t state, float dt) {
    animation().play();
    return state;
  }
};

class Character: public GameObject
{
public:
  Character()
  {
    ASSET_MANAGER.use_texture(C001, m_a_sprite);
    walk_state   = IDLE_DOWN;

    m_idle_down  = new Idle(f_idle_down);
    m_idle_up    = new Idle(f_idle_up);
    m_idle_left  = new Idle(f_idle_left);
    m_idle_right = new Idle(f_idle_right);

    m_walk_down  = new Walk(f_walk_down_1, f_walk_down_2);
    m_walk_up    = new Walk(f_walk_up_1, f_walk_up_2);
    m_walk_left  = new Walk(f_walk_left_1, f_walk_left_2);
    m_walk_right = new Walk(f_walk_right_1, f_walk_right_2);

    m_a_sprite.add_animation_state(IDLE_DOWN, m_idle_down);
    m_a_sprite.add_animation_state(IDLE_UP, m_idle_up);
    m_a_sprite.add_animation_state(IDLE_LEFT, m_idle_left);
    m_a_sprite.add_animation_state(IDLE_RIGHT, m_idle_right);
   
    m_a_sprite.add_animation_state(WALK_DOWN, m_walk_down);
    m_a_sprite.add_animation_state(WALK_UP, m_walk_up);
    m_a_sprite.add_animation_state(WALK_LEFT, m_walk_left);
    m_a_sprite.add_animation_state(WALK_RIGHT, m_walk_right);

    m_a_sprite.set_position(WINDOW_WIDTH/2.0, WINDOW_HEIGHT/2.0);
  }
  ~Character() {
    delete m_idle_down;
    delete m_idle_up;
    delete m_idle_left;
    delete m_idle_right;
    delete m_walk_down;
    delete m_walk_up;
    delete m_walk_left;
    delete m_walk_right;
  }
  void walk(animation_state_t state, float dt) {
    m_a_sprite.update(state, dt);
    if (WALK_DOWN == state) {
      walk_state = IDLE_DOWN;
      m_a_sprite.move(0.0f, move_speed);
    } else if (WALK_UP == state) {
      walk_state = IDLE_UP;
      m_a_sprite.move(0.0f, -move_speed);
    } else if (WALK_LEFT == state) {
      walk_state = IDLE_LEFT;
      m_a_sprite.move(-move_speed, 0.0f);
    } else if (WALK_RIGHT == state) {
      walk_state = IDLE_RIGHT;
      m_a_sprite.move(move_speed, 0.0f);
    }
  }
  void idle(float dt) {
    m_a_sprite.update(walk_state, dt);
  }
private:
  Walk* m_walk_down;
  Walk* m_walk_up;
  Walk* m_walk_left;
  Walk* m_walk_right;
  Idle* m_idle_down;
  Idle* m_idle_up;
  Idle* m_idle_left;
  Idle* m_idle_right;

  AnimateSprite m_a_sprite;
  animation_state_t walk_state;
};


class DemoState: public GameState
{
public:
  DemoState(): character(), no_key(true) {
  }
  ~DemoState() {}
  void initializing() {}
  void pausing() {}
  void resuming() {}
  void updating(float dt) {
    if (INPUT_MANAGER.is_key_pressed(KEY_DOWN)) {
      character.walk(WALK_DOWN, dt);
      no_key = false;
    } else if (INPUT_MANAGER.is_key_pressed(KEY_UP)) {
      character.walk(WALK_UP, dt);
      no_key = false;
    } else if (INPUT_MANAGER.is_key_pressed(KEY_LEFT)) {
      character.walk(WALK_LEFT, dt);
      no_key = false;
    } else if (INPUT_MANAGER.is_key_pressed(KEY_RIGHT)) {
      character.walk(WALK_RIGHT, dt);
      no_key = false;
    } else if (INPUT_MANAGER.is_key_pressed(KEY_ESC)) {
      Engine::quit();
    }
    
    if (no_key) { character.idle(dt); }
    no_key = true;
  }
  void cleaning() {}
private:
  Character character;
  bool no_key;
};

#endif // DEMO_STATE_HPP

