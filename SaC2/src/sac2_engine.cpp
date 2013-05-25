/**
 * \file sac2_engine.cpp
 */

#include "sac2_engine.hpp"

namespace sac2
{

//----------------------------------------------------------------------------
//  Engine::initialize
//----------------------------------------------------------------------------
status_t Engine::initialize()
{
//  p_state_manager = StateManager::get_instance();
//  p_asset_manager = AssetManager::get_instance();
//  p_asset_manager->initialize();
//  p_window_manager = RenderingManager::get_instance();
//  p_window_manager->initialize("SaCDemo");

  return STATUS_SUCCESS;
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
  if (INITILIAZED != m_engine_state) {
    return STATUS_ERROR;
  }  // initialization failed

  m_engine_state = RUNNING;

  loop();  // main loop
  return STATUS_SUCCESS;
}

//----------------------------------------------------------------------------
//  Engine::loop
//----------------------------------------------------------------------------
void Engine::loop()
{
  sf::Event event;
  while (RUNNING == m_engine_state) {
    p_window_manager->get_event(event);

    if (sf::Event::Closed == event.type) {
      quit();
    }  // if the window is closed
    else {
//      p_state_manager->handle_events(event, p_window_manager->get_input());
//      p_window_manager->clear();
//      p_state_manager->update();
    }  // handle any other events
//    p_window_manager->display();
  }  // loop while m_running is true
}

//----------------------------------------------------------------------------
//  Engine::cleanup
//----------------------------------------------------------------------------
void Engine::cleanup()
{
//  p_state_manager->finalize();
//  p_asset_manager->finalize();
}

}
