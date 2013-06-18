/*!
 * \file sac2_game_state.inl
 */

#ifndef SAC2_GAME_STATE_INL
#define SAC2_GAME_STATE_INL

//----------------------------------------------------------------------------
//  GameState::GameState
//----------------------------------------------------------------------------
inline GameState::GameState():
  p_state_manager(StateManager::create()),
  p_asset_manager(AssetManager::create()),
  p_rendering_manager(RenderingManager::create()),
  p_input_manager(InputManager::create()),
  m_state_status(UNINITIALIZED)
{
  // nothing to do
}

//----------------------------------------------------------------------------
//  GameState::~GameState
//----------------------------------------------------------------------------
inline GameState::~GameState()
{
  // nothing to do
}

//----------------------------------------------------------------------------
//  GameState::is_initialized
//----------------------------------------------------------------------------
inline bool GameState::is_initialized() const
{
  if (UNINITIALIZED == m_state_status) { return false; }
  return true;
}

//----------------------------------------------------------------------------
//  GameState::is_paused
//----------------------------------------------------------------------------
inline bool GameState::is_paused() const
{
  if (PAUSED == m_state_status) { return true; }
  return false;
}
//----------------------------------------------------------------------------
//  GameState::is_running
//----------------------------------------------------------------------------
inline bool GameState::is_running() const
{
  if (RUNNING == m_state_status) { return true; }
  return false;
}
//----------------------------------------------------------------------------
//  GameState::is_stopped
//----------------------------------------------------------------------------
inline bool GameState::is_stopped() const
{
  if (STOPPED == m_state_status) { return true; }
  return false;
}

#endif  //! SAC2_GAME_STATE_INL
