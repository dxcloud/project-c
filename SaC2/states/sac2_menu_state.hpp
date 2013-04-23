/*!
 * \file sac2_menu_state.hpp
 * \author Chengwu HUANG
 * \version 0.1
 * \date 2013 - 04 - 08
 */

#ifndef SAC2_MENU_STATE_HPP
#define SAC2_MENU_STATE_HPP

#include <SFML/Window.hpp>

#include "sac2_type.hpp"
#include "sac2_game_state.hpp"
#include "sac2_asset_sprite.hpp"

namespace sac2
{

//! \class MenuState
/*!
 * \brief A default game state
 */
class MenuState: public GameState
{
public:

  /*!
   * \brief Default Constructor
   * \param id Identifier of the state
   */
  MenuState(sac2_state_id_t id=STATE_MENU);

  /*!
   * \brief Destructor
   */
  virtual ~MenuState();

  /*!
   * \brief  Initialize the state
   * \return SaC2 Status
   */
  virtual sac2_status_t initialize();

  /*!
   * \brief  Handle events
   * \param  event Type of the event
   * \param  input Input from Keyboard or Mouse
   * \return SaC2 status
   */
  virtual sac2_status_t handle_events(const sf::Event& event,
                                      const sf::Input& input);

  /*!
   * \brief  Update the state
   * \return SaC2 status
   */
  sac2_status_t update();

  /*!
   * \brief  Draw
   * \return SaC2 status
   */
  sac2_status_t draw();

  /*!
   * \brief  Cleanup
   * \return SaC2 status
   */
  sac2_status_t cleanup();

private:

  AssetSprite m_sprite;  //!< Sample sprite
};  // class MenuState


inline MenuState::MenuState(sac2_state_id_t id):
    GameState(id),
    m_sprite()
{
  // nothing to do
}

inline MenuState::~MenuState()
{
  // nothing to do
}

}  // namespace

#endif  //! SAC2_MENU_STATE_HPP
