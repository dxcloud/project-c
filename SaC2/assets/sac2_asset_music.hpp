/*!
 * \file    sac2_asset_music.hpp
 * \author  Chengwu HUANG
 * \version 0.1
 * \date    2013-04-08
 * \brief   Provides class \b AssetMusic
 */

#ifndef SAC2_ASSET_MUSIC_HPP
#define SAC2_ASSET_MUSIC_HPP

#include <string>

#include <SFML/Audio.hpp>

#include "sac2_type.hpp"
#include "sac2_asset.hpp"

namespace sac2
{

//! \class AssetMusic
/*!
 * \brief Music manipulation
 */
class AssetMusic: public Asset<sf::Music>
{
public:
  /*!
   * \brief Constructor
   * \param filename Name of file for loading
   */
  AssetMusic();

  /*!
   * \brief Destructor
   */
  ~AssetMusic();

  /*!
   * \brief  Start/Stop playing music
   * \param  play \b true for playing music, \b false to stop
   * \return SaC2 status
   */
  virtual sac2_status_t play_music(bool play);

  /*!
   * \brief Set loop state
   * \param loop \b true to play in loop, \b false to play once
   */
  virtual sac2_status_t set_loop(bool loop);
};  // class AssetMusic


inline AssetMusic::AssetMusic():
    Asset<sf::Music>(ASSET_MUSIC)
{

}

inline AssetMusic::~AssetMusic()
{

}

}  // namespace sac2

#endif  //! SAC2_ASSET_MUSIC_HPP
