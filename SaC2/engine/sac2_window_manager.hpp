/*!
 * \file    sac2_window_manager.hpp
 * \author  Chengwu Huang
 * \version 0.1
 * \date    2013 - 4 - 19
 * \brief   Provides WindowManager
 */

#ifndef SAC2_WINDOW_MANAGER
#define SAC2_WINDOW_MANAGER

#include <string>

#include <SFML/Graphics.hpp>

#include "sac2_type.hpp"
#include "sac2_manager.hpp"
#include "sac2_asset_sprite.hpp"

namespace sac2
{

//! \class WindowManager
/*!
 * \brief   Window Management
 * \details This class provides methods for screen manipulation
 */
class WindowManager: public Manager<WindowManager>
{
public:

  friend class Manager<WindowManager>;

  /*!
   * \brief  Get the width of the Rendering Window
   * \return Width
   */
  sac2_length_t get_width();

  /*!
   * \brief  Get the height of the Rendering Window
   * \return Height
   */
  sac2_length_t get_height();

  /*!
   * \brief  Get an event on top of events statck
   * \param  event Event to be filled
   * \return Retrun \b true if an event was returned, \b false otherwise
   */
  bool get_event(sf::Event event);

  /*!
   * \brief  Get the current event
   * \return Current event
   */
  const sf::Event& get_event();

  /*!
   * \brief  Initialise the Rendering Window
   * \return SaC2 status
   */
  sac2_status_t initialize(const std::string& title);

  /*!
   * \brief  Clean the class before to destroying it
   * \return SaC2 status
   */
  sac2_status_t finalize();

  /*!
   * \brief  Draw a sprite on the sreen
   * \param  sprite The sprite to be drawn
   * \return SaC2 status
   */
  sac2_status_t draw(const AssetSprite& sprite);

  /*!
   * \brief  Close the current window
   * \return SaC2 status
   */
  sac2_status_t close();

  /*!
   * \brief  Clear the current screen and draw the next one
   * \return SaC2 status
   */
  sac2_status_t update();

protected:

  /*!
   * \brief Constructor
   */
  WindowManager();

  /*!
   * \brief Destructor
   */
  virtual ~WindowManager();

private:

  /*!
   * \brief Could NOT be copied
   */
  WindowManager(const WindowManager& window_manager);

  /*!
   * \brief Could NOT be copied
   */
  WindowManager& operator=(const WindowManager& window_manager);

  sf::VideoMode       m_video_mode;       //!< Video Mode (width, height, bpp)
  sf::RenderWindow    m_window;           //!< Render window
  sf::WindowSettings  m_window_settings;  //!< Window settings
  unsigned long       m_window_style;     //!< Window style

  sf::Event           m_event;            //!< Event
};

inline WindowManager::WindowManager():
    m_video_mode(DEFAULT_VIDEO_WIDTH, DEFAULT_VIDEO_HEIGHT, DEFAULT_VIDEO_BPP),
    m_window(),
    m_window_settings(),
    m_window_style(DEFAULT_STYLE)
{

}

inline WindowManager::~WindowManager()
{
  Manager::finalize();
}

inline sac2_length_t WindowManager::get_width()
{
  return m_window.GetHeight();
}

inline sac2_length_t WindowManager::get_height()
{
  return m_window.GetWidth();
}

inline bool WindowManager::get_event(sf::Event event)
{
  if (m_window.GetEvent(m_event) == true) {std::cout << "event" << std::endl;}
  return m_window.GetEvent(m_event);
}

inline const sf::Event& WindowManager::get_event()
{
  m_window.GetEvent(m_event);
  return m_event;
}

inline sac2_status_t WindowManager::draw(const AssetSprite& sprite)
{
  m_window.Draw(sprite.get_asset());
  return STATUS_SUCCESS;
}

inline sac2_status_t WindowManager::close()
{
  m_window.Close();
  return STATUS_SUCCESS;
}

inline sac2_status_t WindowManager::update()
{
  m_window.Clear();
  m_window.Display();
  return STATUS_SUCCESS;
}

}

#endif  //! SAC2_WINDOW_MANAGER
