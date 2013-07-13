#include <sac2_rendering_manager.hpp>
#include <sac2_engine.hpp>

namespace sac2
{

//----------------------------------------------------------------------------
//  RenderingManager::initialize
//----------------------------------------------------------------------------
void RenderingManager::initialize()
{

    m_video_mode.width = DEFAULT_VIDEO_WIDTH;
    m_video_mode.height = DEFAULT_VIDEO_HEIGHT;
    m_video_mode.bitsPerPixel = DEFAULT_VIDEO_BPP;
    if (true == m_video_mode.isValid()) {
      std::string title = "SAC2 Demo";
      m_window_style = STYLE_DEFAULT;
      m_settings.depthBits = 0;
      m_settings.stencilBits = 0;
      m_settings.antialiasingLevel = 0;
      m_settings.majorVersion = 2;
      m_settings.minorVersion = 0;

      m_window.create(m_video_mode, title, m_window_style, m_settings);

      m_window.setFramerateLimit(DEFAULT_FRAMERATE_LIMIT);

#ifdef SAC2_LOGGER_ENABLED
      Logger::log_info("RenderingManager::initialize - successfully initialized");
#endif
    }  // video mode supported
#ifdef SAC2_LOGGER_ENABLED
    else {
      Logger::log_error("RenderingManager::initialize - mode NOT supported");
    }
#endif

}

//----------------------------------------------------------------------------
//  RenderingManager::update
//----------------------------------------------------------------------------
void RenderingManager::update(float dt)
{
  m_window.pollEvent(m_event);
  if (sf::Event::Closed == m_event.type) {
#ifdef SAC2_LOGGER_ENABLED
    Logger::log_debug("RenderingManager::update - window closed");
#endif
    Engine::quit();
    return;
  }  // stop engine whether the window is closed
  m_window.clear();
  for (uint32_t i(0); i < m_draw_list.size(); ++i) {
    m_window.draw(*m_draw_list[i]);
  }
  m_window.display();
}

//----------------------------------------------------------------------------
//  RenderingManager::cleanup
//----------------------------------------------------------------------------
void RenderingManager::cleanup()
{

}

}
