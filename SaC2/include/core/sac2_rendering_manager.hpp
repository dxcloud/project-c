//////////////////////////////////////////////////////////////////////////////
//! \file
//!     sac2_rendering_manager.hpp
//! \author
//!     Chengwu Huang
//! \version
//!     0.1
//! \date
//!     2013-04-19
//! \brief
//!     Provides RenderingManager
//////////////////////////////////////////////////////////////////////////////

#ifndef SAC2_RENDERING_MANAGER
#define SAC2_RENDERING_MANAGER

#include <SFML/Graphics.hpp>

#include <sac2_manager.hpp>

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

class Camera;

//////////////////////////////////////////////////////////////////////////////
//! \enum
//!     window_style_t
//! \brief
//!     SFML defined style.
//////////////////////////////////////////////////////////////////////////////
enum window_style_t
{
  STYLE_NONE       = sf::Style::None,
  STYLE_TITLEBAR   = sf::Style::Titlebar,
  STYLE_RESIZE     = sf::Style::Resize,
  STYLE_CLOSE      = sf::Style::Close,
  STYLE_FULLSCREEN = sf::Style::Fullscreen,
  STYLE_DEFAULT    = sf::Style::Default
};

//////////////////////////////////////////////////////////////////////////////
//! \class
//!     RenderingManager
//! \brief
//!     Rendering Management
//! \details
//!     This class provides methods for screen manipulation.
//!          Most of methods are the same as the class \b sf::RenderWindow.
//!          The class is implemented with \a Singleton \a Pattern.
//////////////////////////////////////////////////////////////////////////////
class RenderingManager:
  public Manager<RenderingManager>
{
public:
  friend class Manager<RenderingManager>;

public:
  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Get the width of the Rendering Window.
  //! \return
  //!     Width of the window in pixels.
  ////////////////////////////////////////////////////////////////////////////
  uint32_t get_width();

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Get the height of the Rendering Window.
  //! \return
  //!     Height of the window in pixels.
  ////////////////////////////////////////////////////////////////////////////
  uint32_t get_height();

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Set a 2D camera.
  //! \param[in] camera
  //!     Camera to use.
  ////////////////////////////////////////////////////////////////////////////
  void set_camera(const Camera& camera);

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Close the current window.
  //! \return
  //!     SaC2 status.
  ////////////////////////////////////////////////////////////////////////////
  status_t close();

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!
  ////////////////////////////////////////////////////////////////////////////
  status_t add_drawable(sf::Drawable* drawable);

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  ////////////////////////////////////////////////////////////////////////////
  void update(float dt);

protected:
  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Initialise the Rendering window.
  ////////////////////////////////////////////////////////////////////////////
  void initialize();

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Cleanup the Rendering window.
  ////////////////////////////////////////////////////////////////////////////
  void cleanup();

private:
  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Private constructor
  ////////////////////////////////////////////////////////////////////////////
  RenderingManager();

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Private destructor
  ////////////////////////////////////////////////////////////////////////////
  virtual ~RenderingManager();

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Private copy constructor
  ////////////////////////////////////////////////////////////////////////////
  RenderingManager(const RenderingManager& window_manager);

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Private assignment operator
  ////////////////////////////////////////////////////////////////////////////
  RenderingManager& operator=(const RenderingManager& window_manager);

private:
  sf::RenderWindow     m_window;           //!< Render window
  sf::VideoMode        m_video_mode;       //!< Video Mode (width, height, bpp)
  sf::ContextSettings  m_settings;  //!< Window settings
  uint32_t             m_window_style;     //!< Window style

  std::vector<sf::Drawable*> m_draw_list;

};  // class RenderingManager

}  // namespace sac2

#endif  //! SAC2_WINDOW_MANAGER

