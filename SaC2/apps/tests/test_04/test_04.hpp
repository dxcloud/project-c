//////////////////////////////////////////////////////////////////////////////
//! \file test_04.hpp
//! \author
//!     Chengwu HUANG
//! \version
//!     0.1 (alpha)
//! \date
//!     2013-08-17
//! \brief
//!     Test Game State Management.
//////////////////////////////////////////////////////////////////////////////

#ifndef SAC2_TEST_04_HPP
#define SAC2_TEST_04_HPP

#include <iostream>

#include <sac2_game_state.hpp>
#include <sac2_input_config.hpp>
#include <sac2_state_manager.hpp>
#include <sac2_input_manager.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

const sac2::state_id_t SID1 = 1;
const sac2::state_id_t SID2 = 2;

using std::cout;
using std::endl;
using std::string;

class TestState: public sac2::GameState
{
public:
  TestState(const string num): sac2::GameState(), m_id(num), m_update(false)
  {
    cout << ">>[ called] : ["
         << m_id << "=" << current_state()
         << "] created"
         << endl;
  }

  ~TestState()
  {
    cout << ">>[ called] : ["
         << m_id << "=" << current_state()
         << "] destroyed"
         << endl;
  }

  const string& get_id() const { return m_id; }

  string current_state() const {
    if (is_paused()) { return "PAUSED"; }
    if (is_running()) { return "RUNNING"; }
    if (is_stopped()) { return "STOPPED"; }
    return "NONE";
  }

protected:
  void initializing() {
    m_update = false;
    cout << ">>[ called] : ["
         << m_id << "=" << current_state()
         << "] {initializing}"
         << endl;
  }

  void updating(float dt) {
    if (false == m_update) {
      m_update = true;
      cout << ">>[ called] : ["
           << m_id << "=" << current_state()
           << "] {updating}"
           << endl;
    }
  }

  void pausing() {
    m_update = false;
    cout << ">>[ called] : ["
         << m_id << "=" << current_state()
         << "] {pausing}"
         << endl;
  }

  void resuming() {
    m_update = false;
    cout << ">>[ called] : ["
         << m_id << "=" << current_state()
         << "] {resuming}"
         << endl;
  }

  void cleaning() {
    m_update = false;
    cout << ">>[ called] : ["
         << m_id << "=" << current_state()
         << "] {cleaning}"
         << endl;
  }

private:
  string m_id;
  bool m_update;
};  // class TestState

class TestInputConfig: public sac2::InputConfig
{
public:
  TestInputConfig(): sac2::InputConfig(), p_game_state(0) { }

  ~TestInputConfig() { }

  virtual void bind_game_state(sac2::GameState* game_state) {
    p_game_state = dynamic_cast<TestState*>(game_state);
  }

  void print_action(const string& action) const {
    string tmp;
    tmp = ">>[pressed] : [" + p_game_state->get_id() + "=";
    tmp += p_game_state->current_state();
    tmp += "] ";
    tmp += "{action=" + action + "}";
    cout << tmp << endl;
  }

  void print_result(const string& action, bool success) const {
    string tmp = p_game_state->get_id();
    tmp += "=";
    tmp += p_game_state->current_state();
    tmp += "]";    
    if (success == true) { cout << ">>[success] : [" << tmp << endl; }
    else { cout << ">>[   fail] : [" << tmp << endl; }
  }

  void handle_inputs() {
    if (true == is_key_pressed(sac2::KEY_I)) {
      print_action("initialize");
      if (0 == STATE_MANAGER.initialize_state()) {
        print_result("initialize", true);
      } else {
        print_result("initialize", false);
      }
    }
    else if (true == is_key_pressed(sac2::KEY_S)) {
      print_action("stop");
      if (0 == STATE_MANAGER.stop_state()) {
        print_result("stop", true);
      } else {
        print_result("stop", false);
      }
    }
    else if (true == is_key_pressed(sac2::KEY_P)) {
      print_action("pause");
      if (0 == STATE_MANAGER.pause_state()) {
        print_result("pause", true);
      } else {
        print_result("pause", false);
      }
    }
    else if (true == is_key_pressed(sac2::KEY_R)) {
      print_action("resume");
      if (0 == STATE_MANAGER.resume_state()) {
        print_result("resume", true);
      } else {
        print_result("resume", false);
      }
    }
    else if (true == is_key_pressed(sac2::KEY_D)) {
      print_action("drop");
      if (0 == STATE_MANAGER.drop_state()) {
        print_result("drop", true);
      } else {
        print_result("drop", false);
      }
    }
    else if (is_key_pressed(sac2::KEY_T)) {
      print_action("reset");
      if (0 == STATE_MANAGER.reset_state()) {
        print_result("reset", true);
      } else {
        print_result("reset", false);
      }
    }
    else if (is_key_pressed(sac2::KEY_N)) {
      print_action("start");
      if (0 == STATE_MANAGER.start_state(SID1)) {
        print_result("start", true);
      } else {
        print_result("start", false);
      }
    }
  }

private:
  TestState* p_game_state;
};  // TestInputConfig

#endif  //! SAC2_TEST_04_HPP
