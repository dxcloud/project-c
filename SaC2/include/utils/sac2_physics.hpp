//////////////////////////////////////////////////////////////////////////////
//! \file
//!     sac2_physics.hpp
//! \author
//!     Chengwu HUANG
//! \version
//!     0.1 (develpment version)
//! \date
//!     2013-07-01
//! \brief
//!     Physics simulation functions.
//////////////////////////////////////////////////////////////////////////////

#ifndef SAC2_PHYSICS_HPP
#define SAC2_PHYSICS_HPP

#include <sac2_type.hpp>
#include <sac2_vector2d.hpp>

namespace sac2
{

namespace cts
{

//////////////////////////////////////////////////////////////////////////////
//! Constant of Gravitation
//////////////////////////////////////////////////////////////////////////////
const float GRAVITATION  = 6.67384e-11F;

//////////////////////////////////////////////////////////////////////////////
//! Gravity of Earth
//////////////////////////////////////////////////////////////////////////////
const float ACCELERATION = 9.80665F;

//////////////////////////////////////////////////////////////////////////////
//! Speed of light
//////////////////////////////////////////////////////////////////////////////
const float LIGHT_SPEED  = 299792458.0F;


const material_t ROCK        = { 0.6F, 0.1F };
const material_t WOOD        = { 0.3F, 0.2F };
const material_t METAL       = { 1.2F, 0.05F };
const material_t BOUNCY_BALL = { 0.3F, 0.8F };
const material_t SUPER_BALL  = { 0.3F, 0.95F };
const material_t PILLOW      = { 0.1F, 0.2F };
const material_t STATIC      = { 0.0F, 0.4F };

}





point_t free_fall(const point_t& initial_position,
                  const vector_t& initial_velocity,
                  float dt);



}

#endif //! SAC2_PHYSICS_HPP
