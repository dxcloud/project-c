//----------------------------------------------------------------------------
//  Engine::~Engine
//----------------------------------------------------------------------------
inline Engine::~Engine()
{
  cleanup();
#ifdef SAC2_LOGGER_ENABLED
  Logger::log_info("Engine::destructor - successfully destroyed");
#endif
  m_engine_state = SHUTDOWN;
}

//----------------------------------------------------------------------------
//  Engine::get_engine_state
//----------------------------------------------------------------------------
inline state_t Engine::get_engine_state() const
{
  return m_engine_state;
}

//----------------------------------------------------------------------------
//  Engine::quit
//----------------------------------------------------------------------------
inline void Engine::quit()
{
#ifdef SAC2_LOGGER_ENABLED
  Logger::log_info("Engine::quit - called");
#endif
  m_engine_state = STOPPED;
}