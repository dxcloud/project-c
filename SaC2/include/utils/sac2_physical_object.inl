//////////////////////////////////////////////////////////////////////////////
//! \file
//!     sac2_physical_object.inl
//! \author
//!     Chengwu HUANG
//! \version
//!     0.1 (develpment version)
//! \date
//!     2013-07-04
//////////////////////////////////////////////////////////////////////////////

#ifndef SAC2_PHYSICAL_OBJECT_HPP_INCLUDE
#define SAC2_PHYSICAL_OBJECT_HPP_INCLUDE

#include "sac2_physical_object.hpp"

namespace sac2
{


inline PhysicalObject::PhysicalObject(body_type_t type):
  m_type(type),
  m_material(),
  m_mass(),
  m_velocity(0.0F),
  m_force(0.0F, 0.0F),
  m_gravity_scale(1.0F)
{

}

inline PhysicalObject::~PhysicalObject()
{

}



inline body_type_t PhysicalObject::get_body_type() const
{
  return m_type;
}

inline float PhysicalObject::get_gravity_scale() const
{
  return m_gravity_scale;
}

inline float PhysicalObject::get_density() const
{
  return m_material.density;
}

inline vector_t PhysicalObject::get_center() const
{
  return m_mass.center;
}

inline float PhysicalObject::get_friction() const
{
  return m_material.friction;
}

inline float PhysicalObject::get_restitution() const
{
  return m_material.restitution;
}

inline float PhysicalObject::get_mass() const
{
  return (1.0F / m_mass.inv_mass);
}

inline vector_t PhysicalObject::get_force() const
{
  return m_force;
}

inline vector_t PhysicalObject::get_velocity() const
{
  return m_velocity;
}

inline void PhysicalObject::set_density(float density)
{
  if (cts::ZERO > density) { return; }
  m_material.density = density;
}

inline void PhysicalObject::set_force(const vector_t& force)
{
  if (DYNAMIC == m_type) { return; }
  m_force = force;
}

inline void PhysicalObject::apply_force(const vector_t& force)
{
  if (DYNAMIC == m_type) { return; }
  m_force += force;
}




inline void PhysicalObject::update_mass()
{
  float mass(0.0F);
}


}  // namespace sac2

#endif
