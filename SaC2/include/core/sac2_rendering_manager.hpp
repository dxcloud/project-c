/*!
 * \file    sac2_rendering_manager.hpp
 * \author  Chengwu Huang
 * \version 0.1
 * \date    2013 - 4 - 19
 * \brief   Provides RenderingManager
 */

#ifndef SAC2_RENDERING_MANAGER
#define SAC2_RENDERING_MANAGER

#include <string>

#include <SFML/Graphics.hpp>

#include <sac2_type.hpp>
#include <sac2_manager.hpp>
#include <sac2_logger.hpp>


/**
 * \TODO Configure from file
 *   \b VideoMode
 *     - width
 *     - height
 *     - bitsPerPixel
 *   \b ContextSettings:
 *     - depthBits (DB)
 *     - stencilBits (SB)
 *     - antialiasingLevel (AAL)
 *     - majorVersion (MaV)
 *     - minorVersion (MiV)
 *   \b RenderWindow
 *     - setVerticalSyncEnabled (vSync)
 *     - setMouseCursorVisible (mouse)
 *     - setKeyRepeatEnabled (keyR)
 *     - setFramerateLimit (FRL)
 */

namespace sac2
{
/*!
 * \brief
 */
enum {
  STYLE_NONE       = sf::Style::None,
  STYLE_TITLEBAR   = sf::Style::Titlebar,
  STYLE_RESIZE     = sf::Style::Resize,
  STYLE_CLOSE      = sf::Style::Close,
  STYLE_FULLSCREEN = sf::Style::Fullscreen,
  STYLE_DEFAULT    = sf::Style::Default
};

/*!
 * \class   RenderingManager
 * \brief   Rendering Management
 * \details This class provides methods for screen manipulation.
 *          Most of methods are the same as the class \b sf::RenderWindow.
 *          The class is implemented with \a Singleton \a Pattern.
 */
class RenderingManager:
  public Manager<RenderingManager>
{
public:
  friend class Manager<RenderingManager>;

public:
  /*!
   * \brief  Get the width of the Rendering Window
   * \return Width of the window
   */
  uint32_t get_width();

  /*!
   * \brief  Get the height of the Rendering Window
   * \return Height of the window
   */
  uint32_t get_height();

  /*!
   * \brief  Get the current event
   * \return Current event
   */
  bool get_event(sf::Event& event);

  /*!
   * \brief  Get the input from Keyboard
   * \return Keyboard input
   */
//  const sf::Input& get_input() const;

  /*!
   * \brief  Draw a sprite on the sreen
   * \param  sprite The sprite to be drawn
   * \return SaC2 status
   */
//  status_t draw_sprite(const AssetSprite& sprite);

  /*!
   * \brief 
   */
//  status_t display_text(const AssetText& text);

  /*!
   * \brief  Close the current window
   * \return SaC2 status
   */
  status_t close();

  /*!
   * \brief  Clear the current screen
   * \return SaC2 status
   */
  status_t clear();

  /*!
   * \brief Display the current screen
   * \return SaC2 status
   */
  status_t display();
  status_t add_drawable(sf::Drawable* drawable);
  void update(float dt);

protected:
  /*!
   * \brief Constructor
   */
  RenderingManager();

  /*!
   * \brief Destructor
   */
  virtual ~RenderingManager();

  /*!
   * \brief  Initialise the Rendering Window
   */

  void initialize();
  void cleanup();

private:
  /*!
   * \brief   Private constructor
   * \details This class could NOT be copied
   */
  RenderingManager(const RenderingManager& window_manager);

  /*!
   * \brief   Private assignment operator
   * \details This class could NOT be copied
   */
  RenderingManager& operator=(const RenderingManager& window_manager);

private:
  sf::RenderWindow     m_window;           //!< Render window
  sf::VideoMode        m_video_mode;       //!< Video Mode (width, height, bpp)
  sf::ContextSettings  m_settings;  //!< Window settings
  unsigned long        m_window_style;     //!< Window style

  sf::Event            m_event;            //!< Event
  std::vector<sf::Drawable*> m_draw_list;

};  // class RenderingManager


//----------------------------------------------------------------------------
//  RenderingManager::RenderingManager
//----------------------------------------------------------------------------
inline RenderingManager::RenderingManager():
  Manager<RenderingManager>(),
  m_window(),
  m_video_mode(),
  m_settings(),
  m_window_style(STYLE_DEFAULT),
  m_event()
{
#ifdef SAC2_LOGGER_ENABLED
  Logger::log_info("RenderingManager::constructor - start initialization");
#endif
}

//----------------------------------------------------------------------------
//  RenderingManager::~RenderingManager
//----------------------------------------------------------------------------
inline RenderingManager::~RenderingManager()
{
#ifdef SAC2_LOGGER_ENABLED
  Logger::log_info("RenderingManager::destructor - successfully destroyed");
#endif
}

inline uint32_t RenderingManager::get_width()
{
  return m_window.getSize().x;
}

inline uint32_t RenderingManager::get_height()
{
  return m_window.getSize().y;
}

inline bool RenderingManager::get_event(sf::Event& event)
{
  if (false == m_window.isOpen()) {
    event.type = sf::Event::Closed;
    return true;
  }
  return m_window.pollEvent(event);
}

/*
inline status_t RenderingManager::draw_sprite(const AssetSprite& sprite)
{
  m_window.draw(sprite.get_asset());
  return STATUS_SUCCESS;
}

inline status_t RenderingManager::display_text(const AssetText& text)
{
//  m_window.draw(text.get_asset());
  return STATUS_SUCCESS;
}
*/
inline status_t RenderingManager::close()
{
  m_window.close();
  return STATUS_SUCCESS;
}

inline status_t RenderingManager::clear()
{
  m_window.clear();
  return STATUS_SUCCESS;
}

inline status_t RenderingManager::display()
{
  m_window.display();
  return STATUS_SUCCESS;
}

inline status_t RenderingManager::add_drawable(sf::Drawable* drawable)
{
  m_draw_list.push_back(drawable);
  return STATUS_SUCCESS;
}

}  // namespace sac2

#endif  //! SAC2_WINDOW_MANAGER
