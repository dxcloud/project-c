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
 * \details The following member functions must be defined by any derived
 *          class:
 *          - \b initialize()
 *          - \b pause()
 *          - \b resume()
 *          - \b update()
 *          - \b cleanup()
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
   * \return \b true if the state is initialized, \b false otherwise
   */
  bool is_initialized() const;

  /*!
   * \brief  Test if the state is paused
   * \return \b true if the state is paused, \b false otherwise
   */
  bool is_paused() const;

  /*!
   * \brief  Test if the state is running
   * \return \b true if the state is running, \b false otherwise
   */
  bool is_running() const;

  /*!
   * \brief  Test if the state is stopped
   * \return \b true if the state is stopped, \b false otherwise
   */
  bool is_stopped() const;

protected:
  /*!
   * \brief Initialize the state
   */
  virtual void initialize() = 0;

  /*!
   * \brief  Set the state to pause
   */
  virtual void pause() = 0;
  
  /*!
   * \brief  Resume if the state is paused
   */
  virtual void resume() = 0;

  /*!
   * \brief   Update the state
   * \details Change the position of a sprite for example...
   */
  virtual void update() = 0;

  /*!
   * \brief  Clean before the state is removed
   */
  virtual void cleanup() = 0;

protected:
  StateManager*         p_state_manager;  //!< State Manager
  AssetManager*         p_asset_manager;  //!< Asset Manager
  RenderingManager*     p_rendering_manager; //!< Window Manager
  InputManager*         p_input_manager;

private:
  state_t               m_state_status;
};  // class GameState

#include <sac2_game_state.inl>

}

#endif  //! SAC2_GAME_STATE_HPP
