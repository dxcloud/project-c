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

//#include <sac2_type.hpp>
#include <sac2_mp_constant.hpp>
#include <sac2_mp_type.hpp>

namespace sac2
{

struct Material
{
  float density;  //! Area density (kg.m^-2)
  float restitution;
  float friction;

  Material():
    density(0.0F),
    restitution(0.0F),
    friction(0.0F)
  {

  }
};

struct MassData
{
  vector_t center;  //! center of gravity
  float inv_mass;   //! mass (kg)
  float inertia;

  MassData():
  center(0.0F, 0.0F),
  inv_mass(0.0F),
  inertia(0.0F)
  {

  }
};

typedef Material material_t;
typedef MassData mass_t;

point_t free_fall(const point_t& initial_position,
                  const vector_t& initial_velocity,
                  float dt);



}

#endif //! SAC2_PHYSICS_HPP
