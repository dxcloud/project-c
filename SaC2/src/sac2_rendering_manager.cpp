//////////////////////////////////////////////////////////////////////////////
//! \file
//!     sac2_rendering_manager.cpp
//! \author
//!     Chengwu Huang
//! \version
//!     0.1
//! \date
//!     2013-04-19
//////////////////////////////////////////////////////////////////////////////

#include <sac2_rendering_manager.hpp>
#include <sac2_engine.hpp>

namespace sac2
{

//////////////////////////////////////////////////////////////////////////////
// RenderingManager::RenderingManager
//////////////////////////////////////////////////////////////////////////////
RenderingManager::RenderingManager():
  Manager<RenderingManager>(),
  m_window(),
  m_video_mode(),
  m_settings(),
  m_window_style(STYLE_DEFAULT)
{
#ifdef SAC2_LOGGER_ENABLED
  Logger::log_info("RenderingManager::constructor - start initialization");
#endif
}

//////////////////////////////////////////////////////////////////////////////
// RenderingManager::~RenderingManager
//////////////////////////////////////////////////////////////////////////////
RenderingManager::~RenderingManager()
{
#ifdef SAC2_LOGGER_ENABLED
  Logger::log_info("RenderingManager::destructor - successfully destroyed");
#endif
}

//////////////////////////////////////////////////////////////////////////////
// RenderingManager::get_width
//////////////////////////////////////////////////////////////////////////////
uint32_t RenderingManager::get_width()
{
  return m_window.getSize().x;
}

//////////////////////////////////////////////////////////////////////////////
// RenderingManager::get_height
//////////////////////////////////////////////////////////////////////////////
uint32_t RenderingManager::get_height()
{
  return m_window.getSize().y;
}

//////////////////////////////////////////////////////////////////////////////
// RenderingManager::add_drawable
//////////////////////////////////////////////////////////////////////////////
status_t RenderingManager::add_drawable(sf::Drawable* drawable)
{
  m_draw_list.push_back(drawable);
  return STATUS_SUCCESS;
}

//////////////////////////////////////////////////////////////////////////////
//  RenderingManager::initialize
//////////////////////////////////////////////////////////////////////////////
void RenderingManager::initialize()
{
  m_video_mode.width = DEFAULT_VIDEO_WIDTH;
  m_video_mode.height = DEFAULT_VIDEO_HEIGHT;
  m_video_mode.bitsPerPixel = DEFAULT_VIDEO_BPP;
  if (true == m_video_mode.isValid()) {
    string_t title = "SAC2 Demo";
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
    Engine::quit();
  }
#endif
}

//////////////////////////////////////////////////////////////////////////////
//  RenderingManager::update
//////////////////////////////////////////////////////////////////////////////
void RenderingManager::update(float dt)
{
  sf::Event event;
  while (true == m_window.pollEvent(event)) {
    if (sf::Event::Closed == event.type) {
#ifdef SAC2_LOGGER_ENABLED
      Logger::log_debug("RenderingManager::update - window closed");
#endif
      Engine::quit();
      return;
    }  // stop engine whether the window is closed
  }
  m_window.clear();
  for (size_t i(0); i < m_draw_list.size(); ++i) {
    m_window.draw(*m_draw_list[i]);
  }
  m_window.display();
}

//////////////////////////////////////////////////////////////////////////////
//  RenderingManager::cleanup
//////////////////////////////////////////////////////////////////////////////
void RenderingManager::cleanup()
{
  if (true == m_window.isOpen()) { m_window.close(); }  // close window
}

}
