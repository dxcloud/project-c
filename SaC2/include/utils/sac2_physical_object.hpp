//////////////////////////////////////////////////////////////////////////////
//! \file
//!     sac2_physical_object.hpp
//! \author
//!     Chengwu HUANG
//! \version
//!     0.1 (develpment version)
//! \date
//!     2013-07-04
//! \brief
//!     Physical object.
//////////////////////////////////////////////////////////////////////////////

#ifndef SAC2_PHYSICAL_OBJECT_HPP
#define SAC2_PHYSICAL_OBJECT_HPP

#include <sac2_mp_constant.hpp>

namespace sac2
{

//! \enum body_type_t
//! \var STATIC
//!   mass = 0, velocity = 0, move: manual
//! \var KINEMATIC
//!   mass > 0, velocity: manual, move: auto
//! \var DYNAMIC
//!   mass > 0, velocity: auto, move: auto
enum body_type_t
{
  STATIC,
  KINEMATIC,
  DYNAMIC
};

class PhysicalObject
{
public:
  explicit PhysicalObject(body_type_t type=STATIC);
  ~PhysicalObject();

  //! Body type: Static, Kinematic, Dynamic
  body_type_t get_body_type() const;

  //! Mass of the object
  float get_mass() const;

  //! Density
  float get_density() const;

  //! Restitution
  float get_restitution() const;

  //! Friction
  float get_friction() const;

  //! center of gravity
  vector_t get_center() const;

  //! velocity
  vector_t get_velocity() const;

  //! force
  vector_t get_force() const;

  //! gravity scale
  float get_gravity_scale() const;


  void set_velocity(const vector_t& velocity);
  void set_material(const material_t& material);
  void set_density(float density);
  void set_friction(float friction);
  void set_restitution(float restitution);
  void set_gravity_scale(float gravity_scale);
  void set_force(const vector_t& force);
  void apply_force(const vector_t& force, const point_t& point);

private:
  const body_type_t m_type;
  material_t        m_material;
  mass_t            m_mass;
  vector_t          m_velocity;
  vector_t          m_force;
  float             m_gravity_scale;

private:
  void update_mass();
};

}

#endif
