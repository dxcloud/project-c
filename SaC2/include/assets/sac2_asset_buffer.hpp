/*!
 * \file sac2_asset_buffer.hpp
 * \author
 * \version
 * \date 2013 - 05- 05
 * \brief
 */

#ifndef SAC2_ASSET_BUFFER_HPP
#define SAC2_ASSET_BUFFER_HPP

#include <string>

#include <SFML/Audio.hpp>

#include "sac2_type.hpp"
#include "sac2_asset.hpp"

namespace sac2
{

//! \class AssetBuffer
/*!
 * \brief 
 */
class AssetBuffer:
  public Asset<sf::SoundBuffer>
{
  friend class AssetManager;

public:
  /*!
   * \brief
   */
  explicit AssetBuffer(const std::string& filename);

  /*!
   * \brief
   */
  ~AssetBuffer();

private:
  /*!
   * \brief
   */
  status_t load();

  const std::string m_filename;
};  // class AssetBuffer


inline AssetBuffer::AssetBuffer(const std::string& filename):
  Asset<sf::SoundBuffer>(ASSET_BUFFER),
  m_filename(filename)
{

}

inline AssetBuffer::~AssetBuffer()
{

}

}  // namespace sac2

#endif  //! SAC2_ASSET_BUFFER_HPP
