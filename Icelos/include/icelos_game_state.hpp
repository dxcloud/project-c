

#ifndef ICELOS_GAME_STATE_HPP
#define ICELOS_GAME_STATE_HPP

#include <icelos_type.hpp>

namespace icelos
{

class StateManager;

class GameState
{
public:
  bool is_paused() const;
  bool is_running() const;
  bool is_stopped() const;
protected:
  GameState();
  virtual ~GameState();
  virtual void initialize();
  virtual void update() = 0;
  virtual void pause();
  virtual void resume();
  virtual void stop();
  virtual void cleanup();
private:
  friend class StateManager;
private:
  state_t m_state;
}; // class GameState

inline GameState::GameState():
  m_state(UNINITIALIZED)
{
  // nothing to do
}

inline GameState::~GameState()
{
  // nothing to do
}

inline void GameState::initialize()
{
  // nothing to do
  OUT(">> game init")
}

inline void GameState::cleanup()
{
  // nothing to do
  OUT(">> game clean")
}

inline bool GameState::is_paused() const
{
  return (PAUSED == m_state) ? true : false;
}

inline bool GameState::is_running() const
{
  return (RUNNING == m_state) ? true : false;
}

inline bool GameState::is_stopped() const
{
  return (STOPPED == m_state) ? true : false;
}

inline void GameState::pause()
{
  // nothing to do
  OUT(">> game pause")
}

inline void GameState::resume()
{
  // nothing to do
  OUT(">> game resume")
}

inline void GameState::stop()
{
  // nothing to do
  OUT(">> game stop")
}


} // namespace icelos

#endif // ICELOS_GAME_STATE_HPP

