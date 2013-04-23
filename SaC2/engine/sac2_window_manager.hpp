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
 * \details This class provides methods for screen manipulation.
 *          Most of methods are the same as the class \b sf::RenderWindow.
 *          The class is implemented with \a Singleton \a Pattern.
 */
class WindowManager: public Manager<WindowManager>
{
public:

  friend class Manager<WindowManager>;

  /*!
   * \brief  Get the width of the Rendering Window
   * \return Width of the window
   */
  sac2_length_t get_width();

  /*!
   * \brief  Get the height of the Rendering Window
   * \return Height of the window
   */
  sac2_length_t get_height();

  /*!
   * \brief  Get the current event
   * \return Current event
   */
  bool get_event(sf::Event& event);

  /*!
   * \brief  Get the input from Keyboard
   * \return Keyboard input
   */
  const sf::Input& get_input() const;

  /*!
   * \brief  Initialise the Rendering Window
   * \param  title Title for the window
   * \return SaC2 status
   *         - \b STATUS_SUCCESS
   *         - \b STATUS_ALREADY
   *         - \b STATUS_FAIL
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
   * \brief  Clear the current screen
   * \return SaC2 status
   */
  sac2_status_t clear();

  /*!
   * \brief Display the current screen
   * \return SaC2 status
   */
  sac2_status_t display();

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
   * \brief   Private constructor
   * \details This class could NOT be copied
   */
  WindowManager(const WindowManager& window_manager);

  /*!
   * \brief   Private assignment operator
   * \details This class could NOT be copied
   */
  WindowManager& operator=(const WindowManager& window_manager);

  sf::VideoMode       m_video_mode;       //!< Video Mode (width, height, bpp)
  sf::RenderWindow    m_window;           //!< Render window
  sf::WindowSettings  m_window_settings;  //!< Window settings
  unsigned long       m_window_style;     //!< Window style

//  sf::Event           m_event;            //!< Event

};  // class WindowManager

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

inline bool WindowManager::get_event(sf::Event& event)
{
  return m_window.GetEvent(event);
}

inline const sf::Input& WindowManager::get_input() const
{
  return m_window.GetInput();
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

inline sac2_status_t WindowManager::clear()
{
  m_window.Clear();
  return STATUS_SUCCESS;
}

inline sac2_status_t WindowManager::display()
{
  m_window.Display();
  return STATUS_SUCCESS;
}

}  // namespace sac2

#endif  //! SAC2_WINDOW_MANAGER
