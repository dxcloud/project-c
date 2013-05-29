#include <sac2_rendering_manager.hpp>
#include <sac2_engine.hpp>

namespace sac2
{

//----------------------------------------------------------------------------
//  RenderingManager::initialize
//----------------------------------------------------------------------------
status_t RenderingManager::initialize()
{
  if (false == m_initialized) {
    m_video_mode.width = DEFAULT_VIDEO_WIDTH;
    m_video_mode.height = DEFAULT_VIDEO_HEIGHT;
    m_video_mode.bitsPerPixel = DEFAULT_VIDEO_BPP;
    if (false == m_video_mode.isValid()) {
      return STATUS_FAIL;
    }
    std::string title = "SAC2 Demo";
    m_window_style = STYLE_DEFAULT;
    m_settings.depthBits = 0;
    m_settings.stencilBits = 0;
    m_settings.antialiasingLevel = 0;
    m_settings.majorVersion = 2;
    m_settings.minorVersion = 0;

    m_window.create(m_video_mode, title, m_window_style, m_settings);

    m_window.setFramerateLimit(DEFAULT_FRAMERATE_LIMIT);
    m_initialized = true;
    return STATUS_SUCCESS;
  }
  return STATUS_ALREADY;
}

//----------------------------------------------------------------------------
//  RenderingManager::update
//----------------------------------------------------------------------------
status_t RenderingManager::update()
{
  sf::Event event;
  m_window.pollEvent(event);
  if (sf::Event::Closed == event.type) {
    Engine::quit();
  }  // stop engine whether the window is closed
  return STATUS_SUCCESS;
}

}
