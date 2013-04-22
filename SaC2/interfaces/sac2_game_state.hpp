/*!
 * \file    sac2_game_state.hpp
 * \author  Chengwu HUANG
 * \version 0.1
 * \date    2013-04-08 - Initial Development
 * \brief   Provides the State interface used by all game engines
 */

#ifndef SAC2_GAME_STATE_HPP
#define SAC2_GAME_STATE_HPP

#include "sac2_type.hpp"
#include "sac2_state_manager.hpp"
#include "sac2_asset_manager.hpp"
#include "sac2_window_manager.hpp"

namespace sac2
{

//! \class GameState
/*!
 * \brief   Base class interface for all game states
 * \details The following member functions must be defined by any derived
 *          class:
 *          - \b initialize()
 *          - \b handle_events()
 *          - \b update()
 *          - \b draw()
 *          - \b cleanup()
 */
class GameState
{
 public:

   /*!
    * \brief Constructor
    * \param id Game State identifier
    */
  GameState(sac2_state_id_t id);

  /*!
   * \brief Destructor
   */
  virtual ~GameState();

  /*!
   * \brief  Get the identifier of the state
   * \return Identifier of the state
   */
  sac2_state_id_t get_state_id() const;

  /*!
   * \brief  Test if the state is paused
   * \return \b true if the state is paused, \b false otherwise
   */
  bool is_paused() const;

  /*!
   * \brief  Set the state to pause
   * \return SaC2 status
   */
  sac2_status_t pause();
  
  /*!
   * \brief  Resume if the state is paused
   * \return SaC2 status
   */
  sac2_status_t resume();

  /*!
   * \brief Initialize the state
   * \return SaC2 status
   */
  virtual sac2_status_t initialize() = 0;

  /*!
   * \brief  Reset the state
   * \return SaC2_status
   */
  sac2_status_t reset();

  /*!
   * \brief  Handle input events
   * \param  event Type of event
   * \param  input Input from Keyboard and mouse
   * \return SaC2 status
   */
  virtual sac2_status_t handle_events(const sf::Event& event,
                                      const sf::Input& input) = 0;

  /*!
   * \brief   Update the state
   * \details Change the position of a sprite for example...
   * \return  SaC status
   */
  virtual sac2_status_t update() = 0;

  /*!
   * \brief  Display sprites on the screen
   * \return SaC2 status
   */
  virtual sac2_status_t draw() = 0;

  /*!
   * \brief  Clean before the state is removed
   * \return SaC2 status
   */
  virtual sac2_status_t cleanup() = 0;

protected:

  const sac2_state_id_t m_state_id;       //!< Identifier of the state
  bool                  m_initialized;    //!< \b true if the state is initialized
  bool                  m_paused;         //!< \b false if the state is active
  StateManager*         p_state_manager;  //!< State Manager
  AssetManager*         p_asset_manager;  //!< Asset Manager
  WindowManager*        p_window_manager; //!< Window Manager

 private:
};  // class GameState


inline GameState::GameState(sac2_state_id_t id):
    m_state_id(id),
    m_initialized(false),
    m_paused(false),
    p_state_manager(0),
    p_asset_manager(0),
    p_window_manager(0)
{
  p_state_manager = StateManager::get_instance();
  p_asset_manager = AssetManager::get_instance();
  p_window_manager = WindowManager::get_instance();
}

inline GameState::~GameState()
{
  // do nothing
}

inline sac2_state_id_t GameState::get_state_id() const
{
  return m_state_id;
}

inline bool GameState::is_paused() const {
  return m_paused;
}

inline sac2_status_t GameState::pause()
{
  m_paused = true;
  return STATUS_SUCCESS;
}

inline sac2_status_t GameState::resume() {
  m_paused = false;
  return STATUS_SUCCESS;
}

inline sac2_status_t GameState::reset()
{
  // do nothing
  return STATUS_SUCCESS;
}

}

#endif  //! SAC2_GAME_STATE_HPP
