/*!
 * \file    sac2_asset_sound.hpp
 * \author  Chengwu HUANG
 * \version 0.1
 * \date    2013-04-10
 * \brief   Provides class \b AssetSound
 */

#ifndef SAC2_ASSET_SOUND_HPP
#define SAC2_ASSET_SOUND_HPP

#include <SFML/Audio.hpp>

#include "sac2_type.hpp"
#include "sac2_asset.hpp"

namespace sac2
{

class AssetManager;

/*!
 * \class AssetSound
 * \brief Sound manipulation
 */
class AssetSound:
  public Asset<sf::Sound>
{
public:
  friend class AssetManager;

public:
  /*!
   * \brief Default constructor
   */
  AssetSound();

  /*!
   * \brief Destructor
   */
  ~AssetSound();

  /*!
   * \brief
   */
  status_t play();

  /*!
   * \brief
   */
  status_t pause();

  /*!
   * \brief
   */
  status_t stop();

private:
  /*!
   * \brief
   * \param buffer
   */
  void load(const sf::SoundBuffer& buffer);
};  // class AssetSound

inline AssetSound::AssetSound():
  Asset<sf::Sound>()
{

}

inline AssetSound::~AssetSound()
{

}

}  // namespace sac2

#endif  //! SAC2_ASSET_SOUND_HPP
