/*!
 * \file    sac2_drawable.hpp
 * \author  Chengwu HUANG
 * \version 0.1
 * \date    2013-04-08 - Initial Development
 * \brief   Provides basic class for drawable elements
 */

#ifndef SAC2_DRAWABLE_HPP
#define SAC2_DRAWABLE_HPP

#include <SFML/Graphics.hpp>

#include "sac2_type.hpp"
#include "sac2_asset.hpp"

namespace sac2
{

template<typename T>
//! \class Drawable
/*!
 * \brief   Base class for drawable objects
 * \details Drawable objects are \b DrawableAsset and \b AssetText classes
 */
class Drawable:
  public Asset<T>
{
public:

  /*!
   * \brief Default Constructor
   */
  Drawable(sac2_asset_type_t type);

  /*!
   * \brief Virtual destructor
   */
  virtual ~Drawable();

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
  status_t set_position(float x, float y);

  /*!
   * \brief  Set the scale
   * \param  x X scale factor
   * \param  y Y scale factor
   * \return SaC2 status
   */
  status_t set_scale(float x, float y);

  /*!
   * \brief  Set the orientation of the object
   * \param  angle Angle of the rotation, in degrees
   * \return SaC2 status
   */
  status_t set_rotation(float angle);

  /*!
   * \brief  Move the object of a given offset
   * \param  x X offset
   * \param  y Y offset
   * \return SaC2 status
   */
  status_t move(float x, float y);

  /*!
   * \brief  Rotate the object
   * \param  angle Angle of rotation, in degrees
   * \return SaC2 status
   */
  status_t rotate(float angle);

  /*!
   * \brief  Reset all parameter to default value
   * \return SaC2 status
   */
  status_t reset();
};  // class Drawable


template<typename T>
inline Drawable<T>::Drawable(sac2_asset_type_t type):
  Asset<T>(type)
{

}

template<typename T>
inline Drawable<T>::~Drawable()
{

}

template<typename T>
inline sac2_vector_t Drawable<T>::get_position() const
{
  sf::Vector2f vector2f = Asset<T>::m_asset.GetPosition();
  sac2_vector_t position;
  position.x = vector2f.x;
  position.y = vector2f.y;
  return position;
}

template<typename T>
inline sac2_vector_t Drawable<T>::get_scale() const
{
  sf::Vector2f vector2f = Asset<T>::m_asset.GetScale();
  sac2_vector_t scale;
  scale.x = vector2f.x;
  scale.y = vector2f.y;
  return scale;
}

template<typename T>
inline float Drawable<T>::get_rotation() const
{
  return Asset<T>::m_asset.GetRotation();
}

template<typename T>
inline status_t Drawable<T>::set_position(float x, float y)
{
  Asset<T>::m_asset.SetPosition(x, y);
  return STATUS_SUCCESS;
}

template<typename T>
inline status_t Drawable<T>::set_scale(float x, float y)
{
  if ((0 >= x) || (0 >= y)) { return STATUS_INVAL; }
  Asset<T>::m_asset.SetScale(x, y);
  return STATUS_SUCCESS;
}

template<typename T>
inline status_t Drawable<T>::set_rotation(float angle)
{
  Asset<T>::m_asset.SetRotation(angle);
  return STATUS_SUCCESS;
}

template<typename T>
inline status_t Drawable<T>::move(float x, float y)
{
  Asset<T>::m_asset.Move(x, y);
  return STATUS_SUCCESS;
}

template<typename T>
inline status_t Drawable<T>::rotate(float angle)
{
  Asset<T>::m_asset.Rotate(angle);
  return STATUS_SUCCESS;
}

template<typename T>
inline status_t Drawable<T>::reset()
{
  Asset<T>::m_asset.SetPosition(0.0F, 0.0F);
  Asset<T>::m_asset.SetScale(1.0F, 1.0F);
  Asset<T>::m_asset.SetRotation(0.0F);
  return STATUS_SUCCESS;
}

}  // namespace sac2

#endif  //! SAC2_DRAWABLE_HPP
