/**
 * \file sac2_engine.cpp
 */

#include <sac2_engine.hpp>
#include <sac2_rendering_manager.hpp>
#include <sac2_input_manager.hpp>

namespace sac2
{

engine_state_t Engine::m_engine_state(UNINITIALIZED);

//----------------------------------------------------------------------------
//  Engine::initialize
//----------------------------------------------------------------------------
void Engine::initialize()
{
//  p_state_manager = StateManager::get_instance();
//  p_asset_manager = AssetManager::get_instance();
//  p_asset_manager->initialize();
  p_rendering_manager = RenderingManager::create();
  if (false == p_rendering_manager->is_initialized()) { return; }
  p_input_manager = InputManager::create();
  if (false == p_input_manager->is_initialized()) { return; }
//  p_rendering_manager->initialize();
//  p_window_manager->initialize("SaCDemo");
  m_engine_state = INITIALIZED;
#ifdef SAC2_LOGGER_ENABLED
  Logger::log_info("Engine::initialize - successfully initialized");
#endif
}

//----------------------------------------------------------------------------
//  Engine::parse_options
//----------------------------------------------------------------------------
void Engine::parse_options(int argc, char* argv[])
{

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
  while (RUNNING == m_engine_state) {
    p_input_manager->update();
    p_rendering_manager->update();
  }  // loop while m_engine_state is RUNNING
}

//----------------------------------------------------------------------------
//  Engine::cleanup
//----------------------------------------------------------------------------
void Engine::cleanup()
{
  RenderingManager::destroy();
  InputManager::destroy();
#ifdef SAC2_LOGGER_ENABLED
  Logger::log_info("Engine::cleanup - all managers deleted");
#endif
}

}
