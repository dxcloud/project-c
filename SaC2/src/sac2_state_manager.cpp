#include <sac2_state_manager.hpp>
#include <sac2_game_state.hpp>

namespace sac2
{

//----------------------------------------------------------------------------
//  StateManager::update
//----------------------------------------------------------------------------
void StateManager::update(float dt)
{
  if (false == is_empty()) {
    if (RUNNING == m_state_stack.back()->m_state_status) {
      m_state_stack.back()->updating(dt);
    }
  }
}

//----------------------------------------------------------------------------
//  StateManager::add_state
//----------------------------------------------------------------------------
status_t StateManager::add_state(state_id_t id, GameState* game_state)
{
  if (m_game_states.end() == m_game_states.find(id)) {
    m_game_states.insert(std::make_pair(id, game_state));
#ifdef SAC2_LOGGER_ENABLED
    Logger::log_debug("StateManager::add_state - state added");
#endif
    return STATUS_SUCCESS;
  }  // if state_id_t NOT used yet
  delete game_state;  // no need to be kept
  game_state = 0;
#ifdef SAC2_LOGGER_ENABLED
    Logger::log_debug("StateManager::add_state - state ID already used");
#endif
  return STATUS_ALREADY;
}

//----------------------------------------------------------------------------
//  StateManager::start_state
//----------------------------------------------------------------------------
status_t StateManager::start_state(state_id_t id)
{
  pause_state();  // attempt to pause the current game state
  if (0 == find_state(id)) { return STATUS_INVAL; }
  m_state_stack.push_back(find_state(id));  // add the new state on the stack
  switch (m_state_stack.back()->m_state_status) {
    case UNINITIALIZED:
      initialize_state();
      break;
    case PAUSED:
      resume_state();
      break;
    case STOPPED:
      reset_state();
      break;
    default:
      break;
  }
  return STATUS_SUCCESS;
}

//----------------------------------------------------------------------------
//  StateManager::initialize_state
//----------------------------------------------------------------------------
status_t StateManager::initialize_state()
{
  if (false == is_empty()) {
    if (UNINITIALIZED == m_state_stack.back()->m_state_status) {
      m_state_stack.back()->initializing();
      m_state_stack.back()->m_state_status = RUNNING;
      return STATUS_SUCCESS;
    }  // initialize the state
  }
  return STATUS_CANCEL;
}

//----------------------------------------------------------------------------
//  StateManager::pause_state
//----------------------------------------------------------------------------
status_t StateManager::pause_state()
{
  if (false == is_empty()) {
    if (RUNNING == m_state_stack.back()->m_state_status) {
      m_state_stack.back()->pausing();
      m_state_stack.back()->m_state_status = PAUSED;
      return STATUS_SUCCESS;
    }
  }
  return STATUS_CANCEL;
}

//----------------------------------------------------------------------------
//  StateManager::resume_state
//----------------------------------------------------------------------------
status_t StateManager::resume_state()
{
  if (false == is_empty()) {
    if (PAUSED == m_state_stack.back()->m_state_status) {
      m_state_stack.back()->resuming();
      m_state_stack.back()->m_state_status = RUNNING;
      return STATUS_SUCCESS;
    }
  }
  return STATUS_CANCEL;
}

//----------------------------------------------------------------------------
//  StateManager::clean_state
//----------------------------------------------------------------------------
status_t StateManager::stop_state()
{
  if (false == is_empty()) {
    if (PAUSED == m_state_stack.back()->m_state_status) {
      m_state_stack.back()->cleaning();
      m_state_stack.back()->m_state_status = STOPPED;
      return STATUS_SUCCESS;
    }
  }
  return STATUS_CANCEL;
}

//----------------------------------------------------------------------------
//  StateManager::drop_state
//----------------------------------------------------------------------------
status_t StateManager::drop_state()
{
  if (false == is_empty()) {
    if (RUNNING == m_state_stack.back()->m_state_status) {
      m_state_stack.back()->pausing();
    }
    m_state_stack.pop_back();
    return STATUS_SUCCESS;
  }
  return STATUS_CANCEL;
}

//----------------------------------------------------------------------------
//  StateManager::reset_state
//----------------------------------------------------------------------------
status_t StateManager::reset_state()
{
  if (false == is_empty()) {
    if (STOPPED == m_state_stack.back()->m_state_status) {
      m_state_stack.back()->initializing();
      m_state_stack.back()->m_state_status = RUNNING;
      return STATUS_SUCCESS;
    }
  }
  return STATUS_CANCEL;
}

//----------------------------------------------------------------------------
//  StateManager::initialize
//----------------------------------------------------------------------------
void StateManager::initialize()
{
  if (false == m_initialized) { m_initialized = true; }
}

//----------------------------------------------------------------------------
//  StateManager::cleanup
//----------------------------------------------------------------------------
void StateManager::cleanup()
{
  for (state_iter_t iter(m_game_states.begin());
                         iter != m_game_states.end();
                         ++iter) {
    iter->second->cleaning();
    delete iter->second;
    iter->second = 0;
  }  // delete the state collection
  m_game_states.clear();
}

}
