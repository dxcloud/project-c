#ifndef _SAC2_ENGINE_HPP_
#define _SAC2_ENGINE_HPP_

/*!
 * \file    sac2_engine.hpp
 * \author  Chengwu HUANG
 * \version 0.1
 * \date    2013-04-08
 * \brief   Provides Engine class
 */

#include <string>

#ifdef LOG_ENABLED
#include <fstream>
#endif

#include <SFML/Graphics.hpp>

#include "sac2_type.hpp"
#include "sac2_state_manager.hpp"
#include "sac2_asset_manager.hpp"

//! \todo Load from a configuration file

namespace sac2
{

//! \class Engine
/*!
 * \brief   Base Engine
 * \warning LOG_ENABLED should be defined only for \a Debug or
 *          \a Test Purposes
 */
class Engine
{
 public:

  /*!
   * \brief Constructor
   * \param title Title for the window
   */
  Engine(const std::string& title=defaultApplicationName);

  /*!
   * \brief Destructor
   */
  virtual ~Engine();

  /*!
   * \brief Analyse command line arguments
   * \param argc Number of arguments
   * \param argv Values of the arguments
   */
  void parse_options(int argc, char* argv[]);

  /*!
   * \brief   Start the engine
   * \details The following methods will be called by \b run():
   *          - \b init()
   *          - \b loop()
   *          - \b cleanup()
   */
  sac2_status_t run(void);

  /*!
   * \brief  Stop the Engine and quit
   * \return SaC2 status
   */
  sac2_status_t quit();

 protected:

  /*!
   * \brief Test the Engine is still running
   * \return Return \b true if the Engine is still running, \b false otherwise
   */
  bool is_running(void) const;

  /*!
   * \brief  Initialize the Engine
   * \return SaC2 status
   */
  sac2_status_t init();

  /*!
   * \brief   Main loop
   * \details The Engine will loop while \a is_running is \b true
   * \return  SaC2 status
   */
  sac2_status_t loop();

  /*!
   * \brief  Clean
   * \return SaC2 status
   */
  sac2_status_t cleanup();

 private:

  std::string         m_title;            //!< Title for Window
  sf::VideoMode       m_video_mode;       //!< Video Mode (width, height, bpp)
  sf::RenderWindow    m_window;           //!< Render window
  sf::WindowSettings  m_window_settings;  //!< Window settings
  unsigned long       m_window_style;     //!< Window style
  bool                m_running;          //!< True if the application is currently running

  StateManager*        p_state_manager;    //!< State Manager
  AssetManager*        p_asset_manager;    //!< Asset Manager

#ifdef LOG_ENABLED
  std::ofstream       m_log;              //!< Output stream
  std::string         m_log_filename;     //!< Log file name
#endif
};  // class Engine


inline Engine::Engine(const std::string& title):
  m_title(title),
  m_video_mode(DEFAULT_VIDEO_WIDTH, DEFAULT_VIDEO_HEIGHT, DEFAULT_VIDEO_BPP),
  m_window(),
  m_window_settings(),
  m_window_style(DEFAULT_STYLE),
  m_running(false),
  p_state_manager(0)
{
#ifdef LOG_ENABLED
  m_log_filename.assign(defaultLogFile);
  m_log.open(m_log_filename.c_str());
  m_log << "Log File: " << m_log_filename << std::endl;
  m_log << "Engine started" << std::endl;
#endif
}

inline Engine::~Engine()
{
#ifdef LOG_ENABLED
  m_running = false;
  m_log << "Engine ended" << std::endl;
#endif
}

inline bool Engine::is_running() const
{
  return m_running;
}

}  // namespace sac2

#endif