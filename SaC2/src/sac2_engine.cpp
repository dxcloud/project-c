#include "sac2_engine.hpp"
#include "sac2_menu_state.hpp"

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

  GameState* state(new MenuState(this));
  m_state_manager.add_state(state);

#ifdef LOG_ENABLED
  m_log << "Engine::init() >> completed" << std::endl;
#endif

  return STATUS_SUCCESS;
}

void Engine::parse_options(int argc, char* argv[])
{
#ifdef LOG_ENABLED
  m_log << "Engine::process arguments:" << std::endl;
  for (int i = 0; i < argc; ++i)
    m_log << "#" << i << " " << argv[i] << std::endl;
#endif
}

sac2_status_t Engine::run()
{
#ifdef LOG_ENABLED
  m_log << "Engine::run() started" << std::endl;
#endif

  m_running = true;  // The Engine is running

  sac2_status_t status(STATUS_SUCCESS);
  status = init();

  if (STATUS_SUCCESS != status) {
#ifdef LOG_ENABLED
  m_log << "Engine::init() initialization failed" << std::endl;
#endif
    return status;
  }

  status = loop();  // Main loop

  if (STATUS_SUCCESS != status) {
#ifdef LOG_ENABLED
  m_log << "Engine::loop() quit with " << status << std::endl;
#endif
    return status;
  }

  status = cleanup();

#ifdef LOG_ENABLED
  m_log << "Engine::run() ended with " << status << std::endl;
#endif

  return status;
}

sac2_status_t Engine::loop()
{
  while (true == m_running) {
    GameState* state = m_state_manager.get_state();
    if (0 == state) return STATUS_ERROR;

    sf::Event event;

    if (true == m_window.GetEvent(event)) {
      if (sf::Event::Closed == event.Type) {
	quit();
      }
      else {
	state->handle_events(event);
      }
    }  // if an event happened
    if (false == state->is_paused()) {
      m_window.Clear();
      state->update();
      state->draw();
      state = 0;
      m_window.Display();
    }  // if the current state is active
  }  // Loop until m_running is true
  return STATUS_SUCCESS;
}

bool Engine::is_running() const
{
  return m_running;
}

sac2_status_t Engine::quit()
{
#ifdef LOG_ENABLED
  m_log << "Engine::quit() called" << std::endl;
#endif
  m_running = false;

  return STATUS_SUCCESS;
}

sac2_status_t Engine::cleanup()
{
  if (m_window.IsOpened()) {
    m_window.Close();
  } // if the window is opeend
#ifdef LOG_ENABLED
  m_log << "Engine::cleanup() completed" << std::endl;
#endif
  return STATUS_SUCCESS;
}

}