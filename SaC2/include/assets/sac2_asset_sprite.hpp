#ifndef SAC2_ASSET_SPRITE_HPP
#define SAC2_ASSET_SPRITE_HPP

/*!
 * \file    sac2_asset_sprite.hpp
 * \author  Chengwu HUANG
 * \version 0.1
 * \date    2013-04-08
 * \brief   Provides class \b AssetSprite
 */

#include <string>

#include <SFML/Graphics.hpp>

#include "sac2_type.hpp"
#include "sac2_drawable.hpp"

namespace sac2
{

class AssetManager;

//! \class AssetSprite
/*!
 * \brief   Sprite manipulation
 * \details Sprites are elements can be drawn on screen.
 *          This class can be manipulate be any other classes.
 *          Use \b AssetManager for loading a sprite from an image.
 */
class AssetSprite:
  public Drawable<sf::Sprite>
{
public:
  friend class AssetManager;

public:
  /*!
   * \brief Default constructor
   */
  AssetSprite();

  /*!
   * \brief Destructor
   */
  ~AssetSprite();

  /*!
   * \brief  Resize the sprite
   * \param  width  New width of the sprite
   * \param  height New height of the sprite
   * \return SaC2 status
   */
  status_t resize(float width, float height);

  /*!
   * \brief   Flip the sprite horizontally/vertically
   * \details Set \b flip_x and \b flip_y to \b true will flip the sprite
   *          horizontally AND vertically
   * \param   flip_x Flip the sprite horizontally if \b true
   * \param   flip_y Flip the sprite vertically if \b true
   * \return  SaC2 status
   */
  status_t flip(bool flip_x, bool flip_y);

private:
  /*!
   * \brief   Load the sprite from a image
   * \details This method is only called by \b AssetManager.
   *          For loading, use \b load_sprite of \b AssetManager class.
   * \param   texture Image from which the sprite will be loaded
   */
  void load(const sf::Texture& texture);

};  // class AssetSprite


inline AssetSprite::AssetSprite():
  Drawable<sf::Sprite>()
{

}

inline AssetSprite::~AssetSprite()
{

}

inline status_t AssetSprite::resize(float width, float height)
{
//  m_asset.resize(width, height);
  return STATUS_SUCCESS;
}

inline status_t AssetSprite::flip(bool flip_x, bool flip_y)
{
//  if (true == flip_x) { m_asset.flipX(true); }
//  if (true == flip_y) { m_asset.FlipY(true); }

  return STATUS_SUCCESS;
}

inline void AssetSprite::load(const sf::Texture& texture)
{
  m_asset.setTexture(texture);
}

}  // namespace sac2

#endif  //! SAC2_ASSET_SPRITE_HPP
