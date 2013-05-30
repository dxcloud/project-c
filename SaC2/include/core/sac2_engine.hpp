/*!
 * \file    sac2_engine.hpp
 * \author  Chengwu HUANG
 * \version 1.0
 * \date    2013-04-08
 * \brief   Provides Engine class
 */

#ifndef SAC2_ENGINE_HPP
#define SAC2_ENGINE_HPP

#include <string>

#include <sac2_type.hpp>
#include <sac2_logger.hpp>

namespace sac2
{

class RenderingManager;
class InputManager;

/*!
 * \class   Engine
 * \brief   Base Engine
 * \warning \b LOG_ENABLED should be defined only for \a Debug or
 *          \a Test \a Purposes
 */
class Engine
{
public:
  /*!
   * \brief Constructor
   * \param title Title for the window
   */
  explicit Engine(const std::string& title=defaultApplicationName);

  /*!
   * \brief Destructor
   */
  virtual ~Engine();

  /*!
   * \brief  Accessor
   * \return Current state of the engine
   * \see    engine_state_t
   */
  engine_state_t get_engine_state() const;

  /*!
   * \brief Analyse command line arguments
   * \param argc Number of arguments
   * \param argv Values of the arguments
   */
  void parse_options(int argc, char* argv[]);

  /*!
   * \brief   Start the engine
   * \details The following methods are called:
   *          - \b initialize()
   *          - \b loop()
   *          - \b cleanup()
   */
  status_t run(void);

  /*!
   * \brief  Stop the Engine and quit
   * \return SaC2 status
   */
  static void quit();

protected:
  /*!
   * \brief  Initialize the Engine
   * \return Return
   *         - \b STATUS_SUCCESS
   *         - \b STATUS_FAIL
   */
  void initialize();

  /*!
   * \brief   Main loop
   * \details The Engine will loop while \a is_running is \b true
   * \return  SaC2 status
   */
  void loop();

  /*!
   * \brief  Clean
   * \return SaC2 status
   */
  void cleanup();

private:
  RenderingManager*  p_rendering_manager;   //!< Window Manager
  InputManager*      p_input_manager;

  static engine_state_t     m_engine_state;     //!< Current state of the engine
};  // class Engine


//----------------------------------------------------------------------------
//  Engine::Engine
//----------------------------------------------------------------------------
inline Engine::Engine(const std::string& title):
  p_rendering_manager(0),
  p_input_manager(0)
{
#ifdef SAC2_LOGGER_ENABLED
  Logger::log_info("Engine::constructor - start initialization");
#endif
  initialize();
}

//----------------------------------------------------------------------------
//  Engine::~Engine
//----------------------------------------------------------------------------
inline Engine::~Engine()
{
  cleanup();
#ifdef SAC2_LOGGER_ENABLED
  Logger::log_info("Engine::destructor - successfully destroyed");
#endif
}

//----------------------------------------------------------------------------
//  Engine::get_engine_state
//----------------------------------------------------------------------------
inline engine_state_t Engine::get_engine_state() const
{
  return m_engine_state;
}

//----------------------------------------------------------------------------
//  Engine::quit
//----------------------------------------------------------------------------
inline void Engine::quit()
{
#ifdef SAC2_LOGGER_ENABLED
  Logger::log_info("Engine::quit - called");
#endif
  m_engine_state = STOPPED;
}

}  // namespace sac2

#endif  //! SAC2_ENGINE_HPP
