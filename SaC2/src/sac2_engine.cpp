/**
 * \file sac2_engine.cpp
 */

#include <sstream>

#include <sac2_engine.hpp>
#include <sac2_rendering_manager.hpp>
#include <sac2_input_manager.hpp>
#include <sac2_asset_manager.hpp>
#include <sac2_state_manager.hpp>

namespace sac2
{

//----------------------------------------------------------------------------
//  Engine::m_engine_state
//----------------------------------------------------------------------------
state_t Engine::m_engine_state(SHUTDOWN);

//----------------------------------------------------------------------------
//  Engine::Engine
//----------------------------------------------------------------------------
Engine::Engine(const std::string& title):
  m_clock()
//  p_rendering_manager(RenderingManager::create()),
//  p_input_manager(InputManager::create()),
//  p_asset_manager(AssetManager::create()),
//  p_state_manager(StateManager::create())
{
#ifdef SAC2_LOGGER_ENABLED
  Logger::log_info("Engine::constructor - start initialization");
#endif
  initialize();
}

//----------------------------------------------------------------------------
//  Engine::initialize
//----------------------------------------------------------------------------
void Engine::initialize()
{
//  if (false == p_rendering_manager->is_initialized()) { return; }
//  if (false == p_input_manager->is_initialized()) { return; }
//  if (false == p_asset_manager->is_initialized()) { return; }
//  if (false == p_state_manager->is_initialized()) { return; }

  m_engine_state = INITIALIZED;
#ifdef SAC2_LOGGER_ENABLED
  Logger::log_debug("Engine::initialize - successfully initialized");
#endif
}

//----------------------------------------------------------------------------
//  Engine::parse_options
//----------------------------------------------------------------------------
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

//----------------------------------------------------------------------------
//  Engine::run
//----------------------------------------------------------------------------
status_t Engine::run()
{
  if (INITIALIZED != m_engine_state) {
#ifdef SAC2_LOGGER_ENABLED
  Logger::log_error("Engine::run - run failed");
#endif
    return STATUS_FAIL;
  }  // initialization failed
  m_engine_state = RUNNING;

#ifdef SAC2_LOGGER_ENABLED
  Logger::log_info("Engine::run - running started");
#endif

  loop();  // main loop
  return STATUS_SUCCESS;
}

//----------------------------------------------------------------------------
//  Engine::loop
//----------------------------------------------------------------------------
void Engine::loop()
{
  m_clock.restart();
  while (RUNNING == m_engine_state) {
    sf::Time elapsed(m_clock.restart());
    float dt(elapsed.asSeconds());
//    p_input_manager->update(dt);
//    p_rendering_manager->update(dt);
//    p_state_manager->update(dt);
    InputManager::instance().update(dt);
    StateManager::instance().update(dt);
    RenderingManager::instance().update(dt);
  }  // loop while m_engine_state is RUNNING
}

//----------------------------------------------------------------------------
//  Engine::cleanup
//----------------------------------------------------------------------------
void Engine::cleanup()
{
  RenderingManager::destroy();
  InputManager::destroy();
  AssetManager::destroy();
  StateManager::destroy();
#ifdef SAC2_LOGGER_ENABLED
  Logger::log_info("Engine::cleanup - all managers deleted");
#endif
}

}
