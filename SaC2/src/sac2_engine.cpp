//////////////////////////////////////////////////////////////////////////////
//! \file
//!     sac2_engine.cpp
//////////////////////////////////////////////////////////////////////////////

#ifdef SAC2_LOGGER_ENABLED
#include <sstream>
#endif

#include <sac2_engine.hpp>
#include <sac2_input_manager.hpp>
#include <sac2_asset_manager.hpp>
#include <sac2_audio_manager.hpp>
#include <sac2_state_manager.hpp>
#include <sac2_rendering_manager.hpp>
#include <sac2_logger.hpp>

namespace sac2
{

//////////////////////////////////////////////////////////////////////////////
// Engine::m_engine_state
//////////////////////////////////////////////////////////////////////////////
state_t Engine::m_engine_state(SHUTDOWN);

//////////////////////////////////////////////////////////////////////////////
// Engine::Engine
//////////////////////////////////////////////////////////////////////////////
Engine::Engine():
  m_clock()
{
  LOG_DEBUG("Engine::ctor - start initializing")
  // initialize all managers
  InputManager::instance();
  AssetManager::instance();
  AudioManager::instance();
  StateManager::instance();
  RenderingManager::instance();
  if (SHUTDOWN == m_engine_state) { m_engine_state = INITIALIZED; }
}

//////////////////////////////////////////////////////////////////////////////
// Engine::~Engine
//////////////////////////////////////////////////////////////////////////////
Engine::~Engine()
{
  cleanup();
  m_engine_state = SHUTDOWN;
  LOG_DEBUG("Engine::dtor - successfully destroyed")
}

//////////////////////////////////////////////////////////////////////////////
// Engine::get_engine_state
//////////////////////////////////////////////////////////////////////////////
state_t Engine::get_engine_state() const
{
  return m_engine_state;
}

//////////////////////////////////////////////////////////////////////////////
// Engine::parse_options
//////////////////////////////////////////////////////////////////////////////
void Engine::parse_options(int argc, char* argv[])
{
#ifdef SAC2_LOGGER_ENABLED
  Logger::log_debug("Engine::parse_options - checking passing arguments");
  for (int i(0); i < argc; ++i) {
    std::stringstream argument;
    argument << "argv[" << i << "]" << " = " << argv[i];
    Logger::log_debug(argument.str());
  }
#endif
}

//////////////////////////////////////////////////////////////////////////////
// Engine::run
//////////////////////////////////////////////////////////////////////////////
status_t Engine::run()
{
  if (INITIALIZED != m_engine_state) {
    LOG_ERROR("Engine::run - initialization failed")
    return STATUS_FAIL;
  }  // initialization failed
  LOG_DEBUG("Engine::run - successfully initialized")
  m_engine_state = RUNNING;
  loop();  // main loop
  return STATUS_SUCCESS;
}

//////////////////////////////////////////////////////////////////////////////
// Engine::quit
//////////////////////////////////////////////////////////////////////////////
void Engine::quit()
{
  LOG_DEBUG("Engine::quit - called")
  m_engine_state = STOPPED;
}

//////////////////////////////////////////////////////////////////////////////
// Engine::loop
//////////////////////////////////////////////////////////////////////////////
void Engine::loop()
{
  m_clock.restart();
  while (RUNNING == m_engine_state) {
    float dt(m_clock.restart().asSeconds());
    InputManager::instance().update(dt);
    AssetManager::instance().update(dt);
    AudioManager::instance().update(dt);
    StateManager::instance().update(dt);
    RenderingManager::instance().update(dt);
  }  // loop while m_engine_state is RUNNING
}

//////////////////////////////////////////////////////////////////////////////
// Engine::cleanup
//////////////////////////////////////////////////////////////////////////////
void Engine::cleanup()
{
  LOG_DEBUG("Engine::cleanup - start destroying Managers")
  RenderingManager::destroy();
  StateManager::destroy();
  AudioManager::destroy();
  AssetManager::destroy();
  InputManager::destroy();
}

}
