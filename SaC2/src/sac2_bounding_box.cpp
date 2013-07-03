//////////////////////////////////////////////////////////////////////////////
//! \file
//!     sac2_bounding_box.cpp
//! \author
//!     Chengwu HUANG
//! \version
//!     0.1 (develpment version)
//! \date
//!     2013-07-03
//////////////////////////////////////////////////////////////////////////////

#include <sac2_bounding_box.hpp>

namespace sac2
{

//////////////////////////////////////////////////////////////////////////////
// bool BoundingBox::intersect(const BoundingBox& box) const
//////////////////////////////////////////////////////////////////////////////
bool BoundingBox::intersect(const BoundingBox& box) const
{
  // exit with no intersection if found separated along an axis
  if((box.m_min.x > m_max.x) || (box.m_max.x < m_min.x)) { return false; }
  if((box.m_min.y > m_max.y) || (box.m_max.y < m_min.y)) { return false; }
  return true;
}

}  // namespace sac2
