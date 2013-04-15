#ifndef _SAC2_ASSET_SOUND_HPP_
#define _SAC2_ASSET_SOUND_HPP_

/*!
 * \file    sac2_asset_sound.hpp
 * \author  Chengwu HUANG
 * \version 0.1
 * \date    2013-04-10
 * \brief   Provides class \b AssetSound
 */

#include <string>

#include <SFML/Audio.hpp>

#include "sac2_type.hpp"
#include "sac2_asset.hpp"

namespace sac2
{

//! \class AssetSound
/*!
 * \brief Sound manipulation
 */
class AssetSound: public Asset<sf::SoundBuffer>
{
 public:

  /*!
   * \brief Constructor
   * \param filename Name of file for loading
   */
  AssetSound(const std::string& filename);

  /*!
   * \brief Destructor
   */
  ~AssetSound();

  /*!
   * \brief  Load the asset
   * \return SaC2 status
   */
  sac2_status_t load_asset();

  /*!
   * \brief  Delete the loaded asset
   * \return SaC2 status
   */
  sac2_status_t delete_asset();
 protected:
 
 private:

};  // class AssetSound

inline AssetSound::AssetSound(const std::string& filename):
    Asset<sf::SoundBuffer>(filename, ASSET_SOUND)
{

}

inline AssetSound::~AssetSound()
{
  delete_asset();
}

}  // namespace sac2

#endif  //! _SAC2_ASSET_SOUND_HPP_
