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
#include "sac2_asset_image.hpp"

namespace sac2
{

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
  sac2_status_t resize(float width, float height);

  /*!
   * \brief   Flip the sprite horizontally/vertically
   * \details Set \b flip_x and \b flip_y to \b true will flip the sprite
   *          horizontally AND vertically
   * \param   flip_x Flip the sprite horizontally if \b true
   * \param   flip_y Flip the sprite vertically if \b true
   * \return  SaC2 status
   */
  sac2_status_t flip(bool flip_x, bool flip_y);

  /*!
   * \brief   Load the sprite from a image
   * \details This method is only called by \b AssetManager.
   *          For loading, use \b load_sprite of \b AssetManager class.
   * \param   image Image from which the sprite will be loaded
   * \return  SaC2 status
   *          - \b STATUS_SUCCESS
   *          - \b STATUS_ALREADY
   */
  sac2_status_t load(const sf::Image& image);

  /*!
   * \brief
   */
  sac2_status_t unload();
};  // class AssetSprite


inline AssetSprite::AssetSprite():
  Drawable<sf::Sprite>(ASSET_SPRITE)
{

}

inline AssetSprite::~AssetSprite()
{

}

inline sac2_status_t AssetSprite::resize(float width, float height)
{
  m_asset.Resize(width, height);
  return STATUS_SUCCESS;
}

inline sac2_status_t AssetSprite::flip(bool flip_x, bool flip_y)
{
  if (true == flip_x) { m_asset.FlipX(true); }
  if (true == flip_y) { m_asset.FlipY(true); }

  return STATUS_SUCCESS;
}

inline sac2_status_t AssetSprite::unload()
{
  m_loaded = false;
  return STATUS_SUCCESS;
}

}  // namespace sac2

#endif  //! SAC2_ASSET_SPRITE_HPP
