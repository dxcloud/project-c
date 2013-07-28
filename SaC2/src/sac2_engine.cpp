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
#include <sac2_state_manager.hpp>
#include <sac2_rendering_manager.hpp>

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
#ifdef SAC2_LOGGER_ENABLED
  Logger::log_info("Engine::constructor - start initialization");
#endif
  // initialize all managers
  InputManager::instance();
  AssetManager::instance();
  StateManager::instance();
  RenderingManager::instance();
  if (SHUTDOWN == m_engine_state) { m_engine_state = INITIALIZED; }
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
    argument << "argv["
             << i
             << "]"
             << " = "
             << argv[i];
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
#ifdef SAC2_LOGGER_ENABLED
  Logger::log_error("Engine::run - run failed");
#endif
    return STATUS_FAIL;
  }  // initialization failed
#ifdef SAC2_LOGGER_ENABLED
  Logger::log_info("Engine::run - running started");
#endif
  m_engine_state = RUNNING;
  loop();  // main loop
  return STATUS_SUCCESS;
}

//////////////////////////////////////////////////////////////////////////////
// Engine::loop
//////////////////////////////////////////////////////////////////////////////
void Engine::loop()
{
  m_clock.restart();
  while (RUNNING == m_engine_state) {
//    sf::Time elapsed(m_clock.restart());
//    float dt(elapsed.asSeconds());
    float dt(m_clock.restart().asSeconds());
    InputManager::instance().update(dt);
    AssetManager::instance().update(dt);
    StateManager::instance().update(dt);
    RenderingManager::instance().update(dt);
  }  // loop while m_engine_state is RUNNING
}

//////////////////////////////////////////////////////////////////////////////
// Engine::cleanup
//////////////////////////////////////////////////////////////////////////////
void Engine::cleanup()
{
  RenderingManager::destroy();
  StateManager::destroy();
  AssetManager::destroy();
  InputManager::destroy();
#ifdef SAC2_LOGGER_ENABLED
  Logger::log_info("Engine::cleanup - all managers destroyed");
#endif
}

}
