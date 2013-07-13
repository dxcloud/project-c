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

#include <SFML/System.hpp>

#include <sac2_type.hpp>
#include <sac2_logger.hpp>

namespace sac2
{

class RenderingManager;
class InputManager;
class AssetManager;
class StateManager;

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
  state_t get_engine_state() const;

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
  sf::Clock          m_clock;

//  RenderingManager*  p_rendering_manager;   //!< Window Manager
//  InputManager*      p_input_manager;
//  AssetManager*      p_asset_manager;
//  StateManager*      p_state_manager;

  static state_t     m_engine_state;     //!< Current state of the engine
};  // class Engine

}  // namespace sac2

#include <sac2_engine.inl>

#endif  //! SAC2_ENGINE_HPP
