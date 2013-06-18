/*!
 * \file    sac2_game_state.hpp
 * \author  Chengwu HUANG
 * \version 0.1
 * \date    2013-04-08 - Initial Development
 * \brief   Provides the State interface used by all game engines
 */

#ifndef SAC2_GAME_STATE_HPP
#define SAC2_GAME_STATE_HPP

#include <sac2_type.hpp>
#include <sac2_state_manager.hpp>
#include <sac2_asset_manager.hpp>
#include <sac2_rendering_manager.hpp>
#include <sac2_input_manager.hpp>
#include <sac2_logger.hpp>

namespace sac2
{

/*!
 * \class   State
 * \brief   Base class interface for all game states
 * \details The following member functions must be defined by all derived
 *          classes:
 *          - \b initializing()
 *          - \b pausing()
 *          - \b resuming()
 *          - \b updating()
 *          - \b cleaning()
 * \warning None of these methods should be called directly, instead use
 *          methods provided by StateManager to pause, resume.
 */
class GameState
{
public:
  friend class StateManager;

public:
   /*!
    * \brief Default constructor
    */
  GameState();

  /*!
   * \brief Destructor
   */
  virtual ~GameState();

  /*!
   * \brief  Test if the state is initialized
   * \return Return \b true if the state is initialized, \b false otherwise
   */
  bool is_initialized() const;

  /*!
   * \brief  Test if the state is paused
   * \return Return \b true if the state is paused, \b false otherwise
   */
  bool is_paused() const;

  /*!
   * \brief  Test if the state is running
   * \return Return \b true if the state is running, \b false otherwise
   */
  bool is_running() const;

  /*!
   * \brief  Test if the state is stopped
   * \return Return \b true if the state is stopped, \b false otherwise
   */
  bool is_stopped() const;

protected:

  /*!
   * \brief Initialize the state
   */
  virtual void initializing() = 0;

  /*!
   * \brief When the state is paused
   */
  virtual void pausing() = 0;
  
  /*!
   * \brief When the state is resumed
   */
  virtual void resuming() = 0;

  /*!
   * \brief Called if the state is currently running
   */
  virtual void updating() = 0;

  /*!
   * \brief Clean elements of the state before to be destroyed
   */
  virtual void cleaning() = 0;

protected:
  StateManager*         p_state_manager;  //!< State Manager
  AssetManager*         p_asset_manager;  //!< Asset Manager
  RenderingManager*     p_rendering_manager; //!< Window Manager
  InputManager*         p_input_manager;

private:
  state_t               m_state_status;
};  // class GameState

}

#include <sac2_game_state.inl>

#endif  //! SAC2_GAME_STATE_HPP
