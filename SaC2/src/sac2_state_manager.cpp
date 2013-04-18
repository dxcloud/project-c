#include "sac2_state_manager.hpp"
#include "sac2_game_state.hpp"

namespace sac2
{

sac2_status_t StateManager::set_state_to_active(sac2_state_id_t id)
{
  if (false == m_states.empty()) {
    GameState* state = find_state(id);
    if (0 != state) { return state->resume(); }
  } // if m_states is NOT empty

  return STATUS_INVAL;
}

sac2_status_t StateManager::set_state_to_inactive(sac2_state_id_t id)
{
  if (false == m_states.empty()) {
    GameState* state = find_state(id);
    if (0 != state) { return state->pause(); }
  } // if m_states is NOT empty

  return STATUS_INVAL;
}

sac2_status_t StateManager::set_state_to_current(sac2_state_id_t id, bool activated)
{
  if (false == m_states.empty()) {
    if (STATE_CURRENT == id) {
      if (true == activated) { return m_states.back()->resume(); }
      else { return m_states.back()->pause(); }
    } // if STATE_CURRENT

    for (state_it it(m_states.begin()); it < m_states.end(); ++it) {
      if (id == (*it)->get_state_id()) {
        GameState* state = dynamic_cast<GameState*> (*it);
        m_states.erase(it);
        m_states.push_back(state);
        state = 0;
        if (true == activated) { return m_states.back()->resume(); }
        else { return m_states.back()->pause(); }
      } // if id found
    }
  } // if m_states is NOT empty

  return STATUS_INVAL;
}

sac2_status_t StateManager::add_state(GameState* state, bool activated)
{
  //add a state
  m_states.push_back(state);
  m_states.back()->initialize();

  if (true == activated) { return m_states.back()->resume(); }
  else { return m_states.back()->pause(); }
}

sac2_status_t StateManager::reset_state(sac2_state_id_t id)
{
  if (false == m_states.empty()) {
    GameState* state = find_state(id);
    state->pause();
    state->reset();
    state = 0;

    return STATUS_SUCCESS;
  } // if m_states is NOT empty
  return STATUS_INVAL;
}

sac2_status StateManager::drop_state()
{
  if (false == m_states.empty()) {
    GameState* state = m_states.back();
    m_states.pop_back();
    m_dropped_states.push_back(state);
    state = 0;
    return STATUS_SUCCESS;
  } // if m_states is NOT empty
  return STATUS_INVAL;
}

sac2_status_t StateManager::remove_state(sac2_state_id_t id)
{
  if (STATE_CURRENT == id) return drop_state();

  if (false == m_states.empty()) {
    for (state_it it(m_states.begin()); it < m_states.end(); ++it) {
      if (id == (*it)->get_state_id()) {
        GameState* state = dynamic_cast<GameState*> (*it);
        m_states.erase(it);
        m_dropped_states.push_back(state);
        state = 0;
        return STATUS_SUCCESS;
      } // if id found
    }
  } // if m_states is NOT empty

  return STATUS_INVAL;
}

void StateManager::cleanup()
{
  while (false == m_dropped_states.empty()) {
    GameState* state = m_dropped_states.back();
    m_dropped_states.pop_back();
    state->cleanup();
    delete state;
    state = 0;
  } // while m_dropped_states is NOT empty
}

GameState* StateManager::find_state(sac2_state_id_t id)
{
  if (STATE_CURRENT == id) return m_states.back();

  for (state_it it(m_states.begin()); it < m_states.end(); ++it) {
    if ((*it)->get_state_id() == id) {
      return dynamic_cast<GameState*>(*it);
    }
  }
  return 0;
}

sac2_status_t StateManager::handle_events(const sf::Event& event,
                                          const sf::Input& input)
{
  if (false == m_states.empty()) {
    return m_states.back()->handle_events(event, input);
  }
  else { return STATUS_SUCCESS; }
}

void StateManager::update()
{
  if (false == m_states.empty()) {
    m_states.back()->update();
  }
}

}
