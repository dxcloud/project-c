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
#include "sac2_asset_text.hpp"
#include "sac2_asset_sound.hpp"
#include "sac2_asset_music.hpp"

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
  MenuState();

  /*!
   * \brief Destructor
   */
  virtual ~MenuState();

  /*!
   * \brief  Initialize the state
   * \return SaC2 Status
   */
  virtual void initialize();

  /*!
   * \brief  Update the state
   * \return SaC2 status
   */
  void update();

  /*!
   * \brief  Draw
   * \return SaC2 status
   */
  void draw();

  /*!
   * \brief  Cleanup
   * \return SaC2 status
   */
  void cleanup();

  void pause();
  void resume();
private:

  AssetSprite m_sprite;  //!< Sample sprite
  AssetText   m_text;
  AssetSound  m_sound;
  AssetMusic  m_music;
};  // class MenuState


inline MenuState::MenuState():
    GameState(),
    m_sprite(),
    m_text(),
    m_sound(),
    m_music("/home/orange/project-c/SaC2/samples/music01.ogg")
{
  // nothing to do
}

inline MenuState::~MenuState()
{
  // nothing to do
}

}  // namespace

#endif  //! SAC2_MENU_STATE_HPP
