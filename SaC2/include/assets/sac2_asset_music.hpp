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
class AssetMusic:
  public Asset<sf::Music>
{
  friend class AssetManager;

public:
  AssetMusic();

  /*!
   * \brief Constructor
   * \param filename Name of file for loading
   */
  explicit AssetMusic(const std::string& filename);

  /*!
   * \brief Destructor
   */
  ~AssetMusic();

  /*!
   * \brief  Start playing music
   * \return SaC2 status
   */
  status_t play();

  /*!
   * \brief  Pause music
   * \return SaC2 status
   */
  status_t pause();

  /*!
   * \brief  Stop playing music
   * \return SaC2 status
   */
  status_t stop();

  /*!
   * \brief Set loop state
   * \param loop \b true to play in loop, \b false to play once
   */
  status_t set_loop(bool loop);

private:
  /*!
   * \brief
   * \return SaC2 status
   */
  status_t load(const std::string& filename);

  const std::string m_filename;
};  // class AssetMusic


inline AssetMusic::AssetMusic():
  Asset<sf::Music>(ASSET_MUSIC)
{

}

inline AssetMusic::AssetMusic(const std::string& filename):
  Asset<sf::Music>(ASSET_MUSIC),
  m_filename(filename)
{
  m_asset.openFromFile(m_filename);
  m_loaded = true;
}

inline AssetMusic::~AssetMusic()
{

}

}  // namespace sac2

#endif  //! SAC2_ASSET_MUSIC_HPP
