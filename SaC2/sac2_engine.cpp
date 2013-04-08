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

  return STATUS_SUCCESS;
}

void Engine::process_arguments(int argc, char* argv[])
{
#ifdef LOG_ENABLED
  m_log << "Engine::process arguments:" << std::endl;
  for (int i = 0; i < argc; ++i)
    m_log << "#" << i << " " << argv[i] << std::endl;
#endif
}

sac2_status_t Engine::run()
{
  m_running = true;

  sac2_status_t status(STATUS_SUCCESS);
  status = init();

  if (STATUS_SUCCESS != status)
    return status;

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

  sac2_status_t Engine::update()
  {
    return STATUS_SUCCESS;
  }

  sac2_status_t Engine::draw()
  {
    return STATUS_SUCCESS;
  }

}