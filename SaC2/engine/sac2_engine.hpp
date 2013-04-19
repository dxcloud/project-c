/*!
 * \file    sac2_engine.hpp
 * \author  Chengwu HUANG
 * \version 0.1
 * \date    2013-04-08
 * \brief   Provides Engine class
 */

#ifndef SAC2_ENGINE_HPP
#define SAC2_ENGINE_HPP

#include <string>

#ifdef LOG_ENABLED
#include <fstream>
#endif

#include <SFML/Graphics.hpp>

#include "sac2_type.hpp"
#include "sac2_state_manager.hpp"
#include "sac2_asset_manager.hpp"
#include "sac2_window_manager.hpp"

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
  sac2_status_t initialize();

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
  //! True if the application is currently running
  bool                m_running;

  StateManager*       p_state_manager;    //!< State Manager
  AssetManager*       p_asset_manager;    //!< Asset Manager
  WindowManager*      p_window_manager;   //!< Window Manager

#ifdef LOG_ENABLED
  std::ofstream       m_log;              //!< Output stream
  std::string         m_log_filename;     //!< Log file name
#endif
};  // class Engine


inline Engine::Engine(const std::string& title):
  m_running(false),
  p_state_manager(0),
  p_asset_manager(0),
  p_window_manager(0)
{
#ifdef LOG_ENABLED
  m_log_filename.assign(defaultLogFile);
  m_log.open(m_log_filename.c_str());
  m_log << "Log File: " << m_log_filename << std::endl
        << "<<<< Engine::Engine() >> Completed" << std::endl;
#endif

  initialize();
}

inline Engine::~Engine()
{
  cleanup();

#ifdef LOG_ENABLED
  m_log << ">>>> Engine::~Engine() >> Completed" << std::endl;
#endif
}

inline bool Engine::is_running() const
{
  return m_running;
}

inline sac2_status_t Engine::quit()
{
#ifdef LOG_ENABLED
  m_log << "Engine::quit() >> Called" << std::endl;
#endif
  m_running = false;

  return STATUS_SUCCESS;
}

}  // namespace sac2

#endif  //! SAC2_ENGINE_HPP
