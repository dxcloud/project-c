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
#include "sac2_asset.hpp"
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
class AssetSprite: public Asset<sf::Sprite>, public Drawable
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
   * \brief  Get the current position of the sprite
   * \return Current position of the sprite
   */
  sac2_vector_t get_position() const;

  /*!
   * \brief  Get the current scale of the sprite
   * \return Current scale factor
   */
  sac2_vector_t get_scale() const;

  /*!
   * \brief  Get the current orientation of the sprite
   * \return Current rotation, in degrees
   */
  float get_rotation() const;

  /*!
   * \brief   Set the position of the sprite
   * \details The sprite will moved to the new position
   * \param   x New X coordinate
   * \param   y New Y coordinate
   * \return  SaC2 status
   */
  sac2_status_t set_position(float x, float y);

  /*!
   * \brief  Set the scale of the sprite
   * \details The parameters must be positive.
   * \param  x X scale factor
   * \param  y Y scale factor
   * \return SaC2 status
   */
  sac2_status_t set_scale(float x, float y);

  /*!
   * \brief  Set the orientation of the object
   * \param  angle Angle of the rotation, in degrees
   * \return SaC2 status
   */
  sac2_status_t set_rotation(float angle);

  /*!
   * \brief  Move the object of a given offset
   * \param  x X offset
   * \param  y Y offset
   * \return SaC2 status
   */
  sac2_status_t move(float x, float y);

  /*!
   * \brief  Rotate the object
   * \param  angle Angle of rotation, in degrees
   * \return SaC2 status
   */
  sac2_status_t rotate(float angle);

  /*!
   * \brief  Reset all parameter to the default values
   * \return SaC2 status
   */
  sac2_status_t reset();

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
    Asset<sf::Sprite>(ASSET_SPRITE),
    Drawable()
{

}

inline AssetSprite::~AssetSprite()
{

}

inline sac2_vector_t AssetSprite::get_position() const
{
  sf::Vector2f vector2f = m_asset.GetPosition();
  sac2_vector_t position;
  position.x = vector2f.x;
  position.y = vector2f.y;
  return position;
}

inline sac2_vector_t AssetSprite::get_scale() const
{
  sf::Vector2f vector2f = m_asset.GetScale();
  sac2_vector_t scale;
  scale.x = vector2f.x;
  scale.y = vector2f.y;
  return scale;
}

inline float AssetSprite::get_rotation() const
{
  return m_asset.GetRotation();
}

inline sac2_status_t AssetSprite::set_position(float x, float y)
{
  m_asset.SetPosition(x, y);
  return STATUS_SUCCESS;
}

inline sac2_status_t AssetSprite::set_scale(float x, float y)
{
  if ((0 >= x) || (0 >= y)) { return STATUS_INVAL; }
  m_asset.SetScale(x, y);
  return STATUS_SUCCESS;
}

inline sac2_status_t AssetSprite::set_rotation(float angle)
{
  m_asset.SetRotation(angle);
  return STATUS_SUCCESS;
}

inline sac2_status_t AssetSprite::move(float x, float y)
{
  m_asset.Move(x, y);
  return STATUS_SUCCESS;
}

inline sac2_status_t AssetSprite::rotate(float angle)
{
  m_asset.Rotate(angle);
  return STATUS_SUCCESS;
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
