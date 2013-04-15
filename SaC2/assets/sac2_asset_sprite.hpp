#ifndef _SAC2_ASSET_SPRITE_HPP_
#define _SAC2_ASSET_SPRITE_HPP_

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

namespace sac2
{

//! \class AssetSprite
/*!
 * \brief   Sprite manipulation
 * \details Sprites are elements can be drawn on screen
 */
class AssetSprite: public Asset<sf::Sprite>, public Drawable
{
 public:

  /*!
   * \brief Constructor
   * \param filename Name of file for loading
   */
  AssetSprite(const std::string& filename);

  /*!
   * \brief Destructor
   */
  ~AssetSprite();

  /*!
   * \brief  Get the current position of the object
   * \return Current position
   */
  sac2_vector_t get_position() const;

  /*!
   * \brief  Get the current scal of the object
   * \return Current scale factor
   */
  sac2_vector_t get_scale() const;

  /*!
   * \brief  Get the current orientation of the object
   * \return Current rotation, in degrees
   */
  float get_rotation() const;

  /*!
   * \brief  Set the position
   * \param  x New X coordinate
   * \param  y New Y coordinate
   * \return SaC2 status
   */
  sac2_status_t set_position(float x, float y);

  /*!
   * \brief  Set the scale
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
   * \brief  Reset all parameter to default value
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
   * \brief  Load the asset
   * \return SaC2 status
   */
  virtual sac2_status_t load_asset();

  /*!
   * \brief  Delete the loaded asset
   * \return SaC2 status
   */
  virtual sac2_status_t delete_asset();
 protected:
 
 private:
  sf::Image* p_image;
};  // class AssetSprite


inline AssetSprite::AssetSprite(const std::string& filename):
    Asset<sf::Sprite>(filename, ASSET_SPRITE),
    Drawable(),
    p_image(0)
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

inline sac2_status_t AssetSprite::reset()
{
  m_asset.SetPosition(0.0F, 0.0F);
  m_asset.SetScale(1.0F, 1.0F);
  m_asset.SetRotation(0.0F);
  return STATUS_SUCCESS;
}

inline sac2_status_t AssetSprite::resize(float width, float height)
{
  m_asset.Resize(width, height);
  return STATUS_SUCCESS;
}

inline sac2_status_t AssetSprite::flip(bool flip_x, bool flip_y)
{
  if (true == flip_x) m_asset.FlipX(true);
  if (true == flip_y) m_asset.FlipY(true);

  return STATUS_SUCCESS;
}

}

#endif  //! _SAC2_ASSET_SPRITE_HPP_
