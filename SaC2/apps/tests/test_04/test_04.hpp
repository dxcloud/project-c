#ifndef SAC2_TEST_04_HPP
#define SAC2_TEST_04_HPP

#include <sac2.hpp>

class TestState: public sac2::GameState
{
public:
  TestState(const std::string num): sac2::GameState(), m_id(num)
  {
    sac2::Logger::log_debug("State " + m_id + " created");
  }
  ~TestState()
  {
    sac2::Logger::log_debug("State " + m_id + " destroyed");
  }

public:
  static const sac2::state_id_t S1;
  static const sac2::state_id_t S2;

protected:
  void initializing()
  {
    sac2::Logger::log_debug("State " + m_id + " initialized");
  }

  void updating()
  {

  }

  void pausing()
  {
    sac2::Logger::log_debug("State " + m_id + " paused");
  }

  void resuming()
  {
    sac2::Logger::log_debug("State " + m_id + " resumed");
  }

  void cleaning()
  {
    sac2::Logger::log_debug("State " + m_id + " cleaned");
  }

private:
  std::string m_id;
};

class TestInputConfig: public sac2::InputConfig
{
public:
  TestInputConfig():InputConfig(), m_manager(sac2::StateManager::create()), m_end(false) { }

  ~TestInputConfig() { }

  void handle_inputs() {
    if (true == is_key_pressed(sac2::KEY_I)) {
      print_message(sac2::KEY_I, ">> Initialize state");
      m_manager->initialize_state();
    }
    else if (true == is_key_pressed(sac2::KEY_S)) {
      print_message(sac2::KEY_S, ">> Stopt state");
      m_manager->stop_state();
    }
    else if (true == is_key_pressed(sac2::KEY_P)) {
      print_message(sac2::KEY_P, ">> Pause state");
      m_manager->pause_state();
    }
    else if (true == is_key_pressed(sac2::KEY_R)) {
      print_message(sac2::KEY_R, ">> Resume state");
      m_manager->resume_state();
    }
    else if (true == is_key_pressed(sac2::KEY_D)) {
      print_message(sac2::KEY_D, ">> Drop state");
      m_manager->drop_state();
    }
    else if ((true == is_key_pressed(sac2::KEY_1)) || (true == is_key_pressed(sac2::KEY_NUM1))){
      print_message(sac2::KEY_1, ">> Change to state 1");
      m_manager->start_state(TestState::S1);
    }
    else if ((true == is_key_pressed(sac2::KEY_2)) || (true == is_key_pressed(sac2::KEY_NUM2))){
      print_message(sac2::KEY_2, ">> Change to state 2");
      m_manager->start_state(TestState::S2);
    }
    else if (true == is_key_pressed(sac2::KEY_ESC)) { m_end = true; }
  }

  bool is_end() const {
    return m_end;
  }

  void print_message(const sac2::key_t key, const std::string& msg)
  {
    if (key != m_prev_key) {
      m_prev_key = key;
      sac2::Logger::log_debug(msg);
    }
  }

private:
  sac2::StateManager* m_manager;
  bool m_end;
  sac2::key_t m_prev_key;
};

#endif
