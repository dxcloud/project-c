#include <icelos_state_manager.hpp>
#include <icelos_game_state.hpp>

namespace icelos
{

StateManager::StateManager():
  Manager<StateManager>(),
  m_current(0),
  m_state_map()
{
  // nothing to do
}

StateManager::~StateManager()
{
  // nothing to do
}

void StateManager::initialize()
{

}

void StateManager::cleanup()
{
  for (game_state_iter_t it(m_state_map.begin()); m_state_map.end() != it; ++it) {
    it->second->cleanup();
    delete it->second;
    it->second = 0;
  } // delete all states
  m_state_map.clear();
}

void StateManager::update()
{
  if ((0 != m_current) && (RUNNING == m_current->m_state) ) {
    m_current->update();
  } // update current state
}

status_t StateManager::pause_state()
{
  if ((0 != m_current) && (RUNNING == m_current->m_state)) {
    m_current->pause();
    m_current->m_state = PAUSED;
    return STATUS_SUCCESS;
  } // pause
  return STATUS_CANCEL;
}

status_t StateManager::resume_state()
{
  if ((0 != m_current) && (PAUSED == m_current->m_state)) {
    m_current->resume();
    m_current->m_state = RUNNING;
    return STATUS_SUCCESS;
  }
  return STATUS_CANCEL;
}

status_t StateManager::start_state(state_id_t id)
{
  OUT("call start state")
  game_state_iter_t it(m_state_map.find(id));
  if (m_state_map.end() == it) { return STATUS_MISS; }
  m_current = it->second;
  if (UNINITIALIZED == m_current->m_state) { m_current->initialize(); OUT("start - uninit") }
  else if (PAUSED == m_current->m_state) { m_current->resume(); OUT("start - pause") }
  else if (STOPPED == m_current->m_state) { m_current->initialize(); OUT("start - stop") }
  m_current->m_state = RUNNING;
  OUT("start - set current")
  return STATUS_SUCCESS;
}

status_t StateManager::stop_state()
{
  if (0 != m_current) {
    if ((RUNNING == m_current->m_state) || (PAUSED == m_current->m_state)) {
      m_current->stop();
      m_current->cleanup();
      m_current->m_state = STOPPED;
      return STATUS_SUCCESS;
    } // stop the state
  }
  return STATUS_CANCEL;
}

status_t StateManager::insert_state(state_id_t id, GameState* state)
{
  OUT("call insert_state")
  game_state_iter_t it(m_state_map.find(id));
  if (m_state_map.end() != it) {
    OUT("game state ID already used")
    delete state;
    state = 0;
    return STATUS_ALREADY;
  } // delete second parameter whether ID is already used
  m_state_map.insert(std::make_pair(id, state));
  return STATUS_SUCCESS;
}

status_t StateManager::remove_state(state_id_t id)
{
  OUT("call remove_state")
  game_state_iter_t it(m_state_map.find(id));
  if (m_state_map.end() == it) { return STATUS_MISS; }
  (it->second)->cleanup();
  delete it->second;
  it->second = 0;
  m_state_map.erase(it);
  return STATUS_SUCCESS;
}

} // namespace icelos

