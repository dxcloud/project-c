/*!
 * \file sac2_window_manager.hpp
 * \author
 * \version
 * \date
 * \brief
 */

#ifndef SAC2_WINDOW_MANAGER
#define SAC2_WINDOW_MANAGER

#include <string>

#include <SFML/Graphics.hpp>

#include "sac2_type.hpp"
#include "sac2_manager.hpp"

namespace sac2
{

//! \class WindowManager
/*!
 * \brief
 */
class WindowManager: public Manager<WindowManager>
{
public:

  friend class Manager<WindowManager>;

  sac2_status_t initialize(const std::string& title);

  sac2_status_t finalize();

  sac2_status_t draw(const sf::Sprite& sprite);

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

inline WindowManager::draw(const sf::Sprite& sprite)
{
  m_window.Draw(sprite);
  return STATUS_SUCCESS;
}


}


#endif  //! SAC2_WINDOW_MANAGER
