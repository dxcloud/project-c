/*!
 * \file    sac2_input_config.hpp
 * \author  Chengwu Huang
 * \version 1.0
 * \date    2013-05-29
 * \brief   Provides InputConfig class and DefaultInputConfig as a default
 *          input configuration.
 */

#ifndef SAC2_INPUT_CONFIG_HPP
#define SAC2_INPUT_CONFIG_HPP

#include <SFML/Window.hpp>

#include <sac2_type.hpp>
#include <sac2_engine.hpp>
#include <sac2_logger.hpp>

namespace sac2
{
/*!
 * \class InputConfig
 * \brief This is a basic class for input configuration
 */
class InputConfig
{
public:
  /*!
   * \brief Default constructor
   */
  InputConfig();

  /*!
   * \brief Default destructor
   */
  virtual ~InputConfig();

  /*!
   * \brief   Handle inputs from Keyboard
   * \details This method must be override by any derived class
   * \return  SaC2 status
   */
  virtual status_t handle_inputs() = 0;
};  // class InputConfig


//----------------------------------------------------------------------------
//  InputConfig::InputConfig
//----------------------------------------------------------------------------
inline InputConfig::InputConfig()
{
#ifdef SAC2_LOGGER_ENABLED
  Logger::log_info("InputConfig::constructor - new input config created");
#endif
}

//----------------------------------------------------------------------------
//  InputConfig::~InputConfig
//----------------------------------------------------------------------------
inline InputConfig::~InputConfig()
{
#ifdef SAC2_LOGGER_ENABLED
  Logger::log_info("InputConfig::destructor - input config deleted");
#endif
}


/*!
 * \class   DefaultInputConfig
 * \brief   This is a default input configuration
 * \details To use another configuration instead of this one, call
 *          set_input_config(new_input_config_pointer) from InputManager
 * \see     InputManager
 */
class DefaultInputConfig:
  public InputConfig
{
public:
  /*!
   * \brief Default constructor
   */
  DefaultInputConfig();

  /*!
   * \brief Default destructor
   */
  ~DefaultInputConfig();

  /*!
   * \brief   Handle inputs
   * \details Call Engine::quit() whether 'Escape' key is pressed
   */
  status_t handle_inputs();
};  // class DefaultInputConfig


//----------------------------------------------------------------------------
//  DefaultInputConfig::DefaultInputConfig
//----------------------------------------------------------------------------
inline DefaultInputConfig::DefaultInputConfig():
  InputConfig()
{
#ifdef SAC2_LOGGER_ENABLED
  Logger::log_info("DefaultInputConfig::constructor - new input config created");
#endif
}

//----------------------------------------------------------------------------
//  DefaultInputConfig::~DefaultInputConfig
//----------------------------------------------------------------------------
inline DefaultInputConfig::~DefaultInputConfig()
{
#ifdef SAC2_LOGGER_ENABLED
  Logger::log_info("DefaultInputConfig::destructor - input config deleted");
#endif
}

//----------------------------------------------------------------------------
//  DefaultInputConfig::handle_inputs
//----------------------------------------------------------------------------
inline status_t DefaultInputConfig::handle_inputs()
{
  if (true == sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
#ifdef SAC2_LOGGER_ENABLED
    Logger::log_debug("DefaultInputConfig::handle_inputs - Escape key pressed");
#endif
    Engine::quit();
  }
  return STATUS_SUCCESS;
}


}  // namespace sac2

#endif  //! SAC2_INPUT_CONFIG_HPP
