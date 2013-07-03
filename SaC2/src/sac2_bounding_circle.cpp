//////////////////////////////////////////////////////////////////////////////
//! \file
//!     sac2_bounding_circle.cpp
//! \author
//!     Chengwu HUANG
//! \version
//!     0.1 (develpment version)
//! \date
//!     2013-07-03
//////////////////////////////////////////////////////////////////////////////

#include <sac2_bounding_circle.hpp>
#include <sac2_math.hpp>

namespace sac2
{

//////////////////////////////////////////////////////////////////////////////
// bool BoundingCircle::intersect(const BoundingCircle& circle) const
//////////////////////////////////////////////////////////////////////////////
bool BoundingCircle::intersect(const BoundingCircle& circle) const
{
  float r(m_radius + circle.m_radius);
  r *= r;
  if (distance_2(m_center, circle.m_center) > r) { return false; }
  return true;
}

}  // namespace sac2
