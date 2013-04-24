#ifndef SAC2_DRAWABLE_HPP
#define SAC2_DRAWABLE_HPP

/*!
 * \file    sac2_drawable.hpp
 * \author  Chengwu HUANG
 * \version 0.1
 * \date    2013-04-08 - Initial Development
 * \brief   Provides basic class for drawable elements
 */

#include <SFML/Graphics.hpp>

#include "sac2_type.hpp"

namespace sac2
{

//! \class Drawable
/*!
 * \brief   Base class for drawable objects
 * \details Drawable objects are \b AssetSprite and \b AssetText classes
 */
class Drawable
{
public:

  /*!
   * \brief Default Constructor
   */
  Drawable();

  /*!
   * \brief Virtual destructor
   */
  virtual ~Drawable();

  /*!
   * \brief  Get the current position of the object
   * \return Current position
   */
  virtual sac2_vector_t get_position() const = 0;

  /*!
   * \brief  Get the current scal of the object
   * \return Current scale factor
   */
  virtual sac2_vector_t get_scale() const = 0;

  /*!
   * \brief  Get the current orientation of the object
   * \return Current rotation, in degrees
   */
  virtual float get_rotation() const = 0;

  /*!
   * \brief  Set the position
   * \param  x New X coordinate
   * \param  y New Y coordinate
   * \return SaC2 status
   */
  virtual sac2_status_t set_position(float x, float y) = 0;

  /*!
   * \brief  Set the scale
   * \param  x X scale factor
   * \param  y Y scale factor
   * \return SaC2 status
   */
  virtual sac2_status_t set_scale(float x, float y) = 0;

  /*!
   * \brief  Set the orientation of the object
   * \param  angle Angle of the rotation, in degrees
   * \return SaC2 status
   */
  virtual sac2_status_t set_rotation(float angle) = 0;

  /*!
   * \brief  Move the object of a given offset
   * \param  x X offset
   * \param  y Y offset
   * \return SaC2 status
   */
  virtual sac2_status_t move(float x, float y) = 0;

  /*!
   * \brief  Rotate the object
   * \param  angle Angle of rotation, in degrees
   * \return SaC2 status
   */
  virtual sac2_status_t rotate(float angle) = 0;

  /*!
   * \brief  Reset all parameter to default value
   * \return SaC2 status
   */
  sac2_status_t reset();
};  // class Drawable


inline Drawable::Drawable()
{

}

inline Drawable::~Drawable()
{

}

inline sac2_status_t Drawable::reset()
{
  return STATUS_SUCCESS;
}

}  // namespace sac2

#endif  //! SAC2_DRAWABLE_HPP
