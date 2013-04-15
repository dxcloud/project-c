#ifndef _SAC2_ASSET_MUSIC_HPP_
#define _SAC2_ASSET_MUSIC_HPP_

/*!
 * \file    sac2_asset_music.hpp
 * \author  Chengwu HUANG
 * \version 0.1
 * \date    2013-04-08
 * \brief   Provides class \b AssetImage
 */

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
  AssetMusic(const std::string& filename);

  /*!
   * \brief Destructor
   */
  ~AssetMusic();

  /*!
   * \brief  Load the asset
   * \return SaC2 status
   */
  virtual sac2_status_t load_asset();

  /*!
   * \brief  Delete the loaded asset
   * \return SaC2 status
   */
  virtual sac2_status_t delete_asset();

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

 protected:
 
 private:
};  // class AssetMusic


inline AssetMusic::AssetMusic(const std::string& filename):
    Asset<sf::Music>(filename, ASSET_MUSIC)
{

}

inline AssetMusic::~AssetMusic()
{
  delete_asset();
}

}  // namespace sac2

#endif  //! _SAC2_ASSET_MUSIC_HPP_
