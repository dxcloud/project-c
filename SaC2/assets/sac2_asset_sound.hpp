#ifndef _ASSET_SOUND_HPP_
#define _ASSET_SOUND_HPP_

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
class AssetSound: public Asset
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

  sf::Sound* p_sound;  //!< Sound asset
};  // class AssetSound

inline AssetSound::AssetSound(const std::string& filename):
    Asset(filename, ASSET_SOUND),
    p_sound(new sf::Sound)
{

}

inline AssetSound::~AssetSound()
{
  delete_asset();
}

}  // namespace sac2

#endif