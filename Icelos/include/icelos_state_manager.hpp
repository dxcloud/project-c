#ifndef ICELOS_STATE_MANAGER_HPP
#define ICELOS_STATE_MANAGER_HPP

#include <icelos_type.hpp>
#include <icelos_manager.hpp>
//#include <icelos_game_state.hpp>

namespace icelos
{

/// @brief 

typedef uint32_t state_id_t;
// const state_id_t CURRENT_STATE = 0;

class GameState;

class StateManager:
  public Manager<StateManager>
{
public:
  void update();
  status_t insert_state(state_id_t id, GameState* state);
  status_t remove_state(state_id_t id);
  status_t start_state(state_id_t id);
  status_t pause_state();
  status_t stop_state();
  status_t resume_state();
protected:
  StateManager();
  ~StateManager();
  void initialize();
  void cleanup();
private:
  friend class Manager<StateManager>;
  typedef std::map<state_id_t, GameState*> game_state_map_t;
  typedef game_state_map_t::iterator game_state_iter_t;

  StateManager(const StateManager&);
  StateManager& operator=(const StateManager&);
private:
  GameState*         m_current;
//   state_id_t         m_current_state;
  game_state_map_t   m_state_map;
//   game_state_stack_t m_state_stack;
}; // class StateManager

} // namespace icelos


#endif // ICELOS_STATE_MANAGER_HPP

