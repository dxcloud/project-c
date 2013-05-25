#include "sac2_rendering_manager.hpp"

namespace sac2
{

status_t RenderingManager::initialize(const std::string& title)
{
//  m_video_mode.Width =
//  m_video_mode.Height =
//  m_video_mode.BitsPerPixel =
  if (false == m_video_mode.isValid()) {
    return STATUS_FAIL;
  }
//  m_title =
//  m_style = None, Titlebar, Resize, Close, Fullscreen
//  m_window_settings.DepthBits =
//  m_window_settings.StencilBits =
//  m_window_settings.AntialiasingLevel =

  m_window.create(m_video_mode, title, m_window_style, m_window_settings);

  m_window.setFramerateLimit(DEFAULT_FRAMERATE_LIMIT);

  return STATUS_SUCCESS;
}

status_t RenderingManager::update() {return STATUS_SUCCESS;}

}
