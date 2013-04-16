#include "sac2_window_manager.hpp"

namespace sac2
{

sac2_status_t WindowManager::initialize(const std::string& title)
{
//  m_video_mode.Width =
//  m_video_mode.Height =
//  m_video_mode.BitsPerPixel =
  if (false == m_video_mode.IsValid()) {
    return STATUS_FAIL;
  }
//  m_title =
//  m_style = None, Titlebar, Resize, Close, Fullscreen
//  m_window_settings.DepthBits =
//  m_window_settings.StencilBits =
//  m_window_settings.AntialiasingLevel =

  m_window.Create(m_video_mode, title, m_window_style, m_window_settings);

  m_window.SetFramerateLimit(DEFAULT_FRAMERATE_LIMIT);

  return STATUS_SUCCESS;
}

}
