#include "sac2_engine.hpp"
#include "sac2_asset_sprite.hpp"

namespace sac2
{

sac2_status_t Engine::initialize()
{
  p_state_manager = StateManager::get_instance();
  p_asset_manager = AssetManager::get_instance();
  p_window_manager = WindowManager::get_instance();
  p_window_manager->initialize("SaCDemo");

#ifdef LOG_ENABLED
  m_log << "Engine::init() >> Completed" << std::endl;
#endif
  return STATUS_SUCCESS;
}

void Engine::parse_options(int argc, char* argv[])
{
#ifdef LOG_ENABLED
  m_log << "Engine::parse_options() >> Check parameters" << std::endl;
  for (int i = 0; i < argc; ++i) {
    m_log << "#" << i << " " << argv[i] << std::endl;
  }
  m_log << "Engine::parse_options() >> Completed" << std::endl;
#endif
}

sac2_status_t Engine::run()
{
#ifdef LOG_ENABLED
  m_log << "Engine::run() >> Started" << std::endl;
#endif

  m_running = true;  // the Engine is running

  sac2_status_t status(STATUS_SUCCESS);
  status = initialize();

  if (STATUS_SUCCESS == status) {
    status = loop();  // main loop

#ifdef LOG_ENABLED
  m_log << "Engine::loop() >> Completed" << std::endl;
#endif
  }  // if initialization success

#ifdef LOG_ENABLED
  m_log << "Engine::run() >> Ended with " << status << std::endl;
#endif

  return status;
}

sac2_status_t Engine::loop()
{
#ifdef LOG_ENABLED
  m_log << "Engine::loop() >> Started" << std::endl;
#endif

  while (true == m_running) {
    sf::Event event = p_window_manager->get_event();

    if (sf::Event::Closed == event.Type) {
      quit();
    }  // if the window is closed
    else {
//      sac2_status_t status(STATUS_SUCCESS);
//      status = p_state_manager->handle_events(event, m_window.GetInput());
//      if (STATUS_QUIT == status) { quit(); }  // if Engine::quit() requested
    }  // handle any other events
    p_window_manager->update();
  }  // loop while m_running is true
  return STATUS_SUCCESS;
}

sac2_status_t Engine::cleanup()
{
  p_state_manager->finalize();
  p_asset_manager->finalize();

#ifdef LOG_ENABLED
  m_log << "Engine::cleanup() >> Completed" << std::endl;
#endif
  return STATUS_SUCCESS;
}

}
