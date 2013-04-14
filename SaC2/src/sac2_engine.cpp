#include "sac2_engine.hpp"

namespace sac2
{

sac2_status_t Engine::init()
{
//  m_video_mode.Width =
//  m_video_mode.Height =
//  m_video_mode.BitsPerPixel =
  if (false == m_video_mode.IsValid()) {
#ifdef LOG_ENABLED
    m_log << "Engine::init() >> Video mode is NOT supported" << std::endl
          << "The application is about to quit" << std::endl;
#endif
    return STATUS_FAIL;
  }
#ifdef LOG_ENABLED
  m_log << "Engine::init() >> Video mode OK" << std::endl;
#endif
//  m_title =
//  m_style = None, Titlebar, Resize, Close, Fullscreen
//  m_window_settings.DepthBits =
//  m_window_settings.StencilBits =
//  m_window_settings.AntialiasingLevel =

  m_window.Create(m_video_mode, m_title, m_window_style, m_window_settings);

  m_window.SetFramerateLimit(DEFAULT_FRAMERATE_LIMIT);

  p_state_manager = StateManager::get_instance();

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
  status = init();

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
    sf::Event event;

    if (true == m_window.GetEvent(event)) {
      if (sf::Event::Closed == event.Type) {
        quit();
      }  // if the window is closed
      else {
        sac2_status_t status(STATUS_SUCCESS);
        status = p_state_manager->handle_events(event, m_window.GetInput());
        if (STATUS_QUIT == status) { quit(); }  // if Engine::quit() requested
      }  // handle any other events
      m_window.Clear();
      m_window.Display();
    }  // if an event happened
  }  // loop while m_running is true
  return STATUS_SUCCESS;
}

sac2_status_t Engine::cleanup()
{
  if (m_window.IsOpened()) {
    m_window.Close();
  } // if the window is still opeend

  p_state_manager->finalize();

#ifdef LOG_ENABLED
  m_log << "Engine::cleanup() >> Completed" << std::endl;
#endif
  return STATUS_SUCCESS;
}

}
