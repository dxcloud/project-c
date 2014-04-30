//////////////////////////////////////////////////////////////////////////////
//! \file sac2_state_manager.cpp
//! \author
//!     Chengwu HUANG
//! \version
//!     0.2 (alpha)
//! \date
//!     2013-04-08: Initial develepment.
//////////////////////////////////////////////////////////////////////////////

#include <sac2_state_manager.hpp>
#include <sac2_game_state.hpp>

namespace sac2
{

//////////////////////////////////////////////////////////////////////////////
// StateManager::StateManager
//////////////////////////////////////////////////////////////////////////////
StateManager::StateManager():
  m_state_stack(),
  m_state_map()
{
  LOG_INFO("StateManager::ctor - successfully initialized")
}

//////////////////////////////////////////////////////////////////////////////
// StateManager::~StateManager
//////////////////////////////////////////////////////////////////////////////
StateManager::~StateManager()
{
  LOG_INFO("StateManager::dtor - successfully destroyed")
}

//////////////////////////////////////////////////////////////////////////////
// StateManager::is_empty
//////////////////////////////////////////////////////////////////////////////
bool StateManager::is_empty() const
{
  return m_state_stack.empty();
}

//////////////////////////////////////////////////////////////////////////////
// StateManager::update
//////////////////////////////////////////////////////////////////////////////
void StateManager::update(float dt)
{
  if (true == is_empty()) { return; }  // state stack is empty
  if (RUNNING == m_state_stack.back()->m_state_status) {
    m_state_stack.back()->updating(dt);
  }
}

//////////////////////////////////////////////////////////////////////////////
// StateManager::add_state
//////////////////////////////////////////////////////////////////////////////
status_t StateManager::add_state(state_id_t id, GameState* game_state)
{
  if (m_state_map.end() == m_state_map.find(id)) {
    LOG_DEBUG("StateManager::add_state - new Game State added")
    m_state_map.insert(std::make_pair(id, game_state));
    return STATUS_SUCCESS;
  }  // state_id_t NOT used yet
  LOG_DEBUG("StateManager::add_state - ID already used")
  delete game_state;  // delete the pointer (allocated with new)
  game_state = 0;
  return STATUS_ALREADY;
}

//////////////////////////////////////////////////////////////////////////////
// StateManager::start_state
//////////////////////////////////////////////////////////////////////////////
status_t StateManager::start_state(state_id_t id)
{
  pause_state();  // attempt to pause the current game state
  state_iter_t iter(m_state_map.find(id));
  if (m_state_map.end() == iter) {
    LOG_DEBUG("StateManager::start_state - ID no recognized")
    return STATUS_MISS;
  }  // NOT found
  LOG_DEBUG("StateManager::start_state - called")
  m_state_stack.push_back(iter->second);  // add the new state on the stack
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

//////////////////////////////////////////////////////////////////////////////
// StateManager::initialize_state
//////////////////////////////////////////////////////////////////////////////
status_t StateManager::initialize_state()
{
  if ((false == is_empty())
       && (UNINITIALIZED == m_state_stack.back()->m_state_status)) {
    LOG_DEBUG("StateManager::initialize_state - called")
    m_state_stack.back()->initializing();
    m_state_stack.back()->m_state_status = RUNNING;
    return STATUS_SUCCESS;
  }  // initialize the state
  LOG_DEBUG("StateManager::initialize_state - cancelled")
  return STATUS_CANCEL;
}

//////////////////////////////////////////////////////////////////////////////
// StateManager::pause_state
//////////////////////////////////////////////////////////////////////////////
status_t StateManager::pause_state()
{
  if ((false == is_empty())
       && (RUNNING == m_state_stack.back()->m_state_status)) {
    LOG_DEBUG("StateManager::pause_state - called")
    m_state_stack.back()->pausing();
    m_state_stack.back()->m_state_status = PAUSED;
    return STATUS_SUCCESS;
  }  // pause the state
  LOG_DEBUG("StateManager::pause_state - cancelled")
  return STATUS_CANCEL;
}

//////////////////////////////////////////////////////////////////////////////
// StateManager::resume_state
//////////////////////////////////////////////////////////////////////////////
status_t StateManager::resume_state()
{
  if ((false == is_empty())
       && (PAUSED == m_state_stack.back()->m_state_status)) {
      LOG_DEBUG("StateManager::resume_state - called")
    m_state_stack.back()->resuming();
    m_state_stack.back()->m_state_status = RUNNING;
    return STATUS_SUCCESS;
  }  // resume the state
  LOG_DEBUG("StateManager::resume_state - cancelled")
  return STATUS_CANCEL;
}

//////////////////////////////////////////////////////////////////////////////
// StateManager::stop_state
//////////////////////////////////////////////////////////////////////////////
status_t StateManager::stop_state()
{
  if ((false == is_empty())
       && (PAUSED == m_state_stack.back()->m_state_status)) {
    LOG_DEBUG("StateManager::stop_state - called")
    m_state_stack.back()->cleaning();
    m_state_stack.back()->m_state_status = STOPPED;
    return STATUS_SUCCESS;
  }  // stop and clean the state
  LOG_DEBUG("StateManager::stop_state - cancelled")
  return STATUS_CANCEL;
}

//////////////////////////////////////////////////////////////////////////////
// StateManager::drop_state
//////////////////////////////////////////////////////////////////////////////
status_t StateManager::drop_state()
{
  if (false == is_empty()) {
    if (RUNNING == m_state_stack.back()->m_state_status) {
      m_state_stack.back()->pausing();
    }  // first, pause the state
    LOG_DEBUG("StateManager::drop_state - called")
    m_state_stack.pop_back();
    return STATUS_SUCCESS;
  }
  LOG_DEBUG("StateManager::drop_state - cancelled")
  return STATUS_CANCEL;
}

//////////////////////////////////////////////////////////////////////////////
// StateManager::reset_state
//////////////////////////////////////////////////////////////////////////////
status_t StateManager::reset_state()
{
  if ((false == is_empty())
       && (STOPPED == m_state_stack.back()->m_state_status)) {
    LOG_DEBUG("StateManager::stop_state - called")
    m_state_stack.back()->initializing();
    m_state_stack.back()->m_state_status = RUNNING;
    return STATUS_SUCCESS;
  }  // reset the state
  LOG_DEBUG("StateManager::reset_state - cancelled")
  return STATUS_CANCEL;
}

//////////////////////////////////////////////////////////////////////////////
// StateManager::cleanup
//////////////////////////////////////////////////////////////////////////////
void StateManager::cleanup()
{
  for (state_iter_t it(m_state_map.begin()); it != m_state_map.end(); ++it) {
    it->second->cleaning();
    delete it->second;
    it->second = 0;
  }  // delete the state collection
  m_state_map.clear();
}

}
