/*!
 * \file    sac2_input_manager.hpp
 * \author  Chengwu Huang
 * \version 1.0
 * \date    2013-05-29
 * \brief   Provides class to manage inputs from keyboard
 */

#ifndef SAC2_INPUT_MANAGER_HPP
#define SAC2_INPUT_MANAGER_HPP

#include <sac2_type.hpp>
#include <sac2_manager.hpp>
#include <sac2_input_config.hpp>
#include <sac2_logger.hpp>

namespace sac2
{
/*!
 * \class   InputManager
 * \brief   This class handle inputs.
 * \details DefaultInputConfig is used as default configuration for handling
 *          input.
 */
class InputManager:
  public Manager<InputManager>
{
public:
  friend class Manager<InputManager>;

public:
  /*!
   * \brief   Change the current input configuration
   * \param   input_config New input configuration
   * \details The argument must be allocated with the keyword \b new, the old
   *          configuration will be deleted before setting the new one.
   */
  void set_input_config(InputConfig* input_config);

  /*!
   * \brief   Update InputManager
   * \details This method calls handle_inputs() of the InputConfig.
   */
  void update(float dt);

protected:
  /*!
   * \brief Default constructor
   */
  InputManager();

  /*!
   * \brief Default destructor
   */
  ~InputManager();

  void initialize();

  /*!
   * \brief Delete the current input configuration
   */
  void cleanup();

private:
  /*!
   * \brief   Private copy constructor
   * \details This class cannot be copied
   */
  InputManager(const InputManager&);

  /*!
   * \brief Private assignement operator
   * \details This class cannot be copied
   */
  InputManager& operator=(const InputManager&);

private:
  InputConfig* p_input_config;  //!< Current input configuration
};  // class InputManager


//----------------------------------------------------------------------------
//  InputManager::InputManager
//----------------------------------------------------------------------------
inline InputManager::InputManager():
  Manager<InputManager>(),
  p_input_config(new DefaultInputConfig)
{
  initialize();
#ifdef SAC2_LOGGER_ENABLED
  Logger::log_info("InputManager::constructor - successfully initialized");
#endif
}

//----------------------------------------------------------------------------
//  InputManager::~InputManager
//----------------------------------------------------------------------------
inline InputManager::~InputManager()
{
  cleanup();
#ifdef SAC2_LOGGER_ENABLED
  Logger::log_info("InputManager::destructor - successfully destroyed");
#endif
}

}  // namespace sac2

#endif  //! SAC2_INPUT_MANAGER_HPP
