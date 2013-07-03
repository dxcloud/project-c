//////////////////////////////////////////////////////////////////////////////
//! \file
//!     sac2_bounding_box.hpp
//! \author
//!     Chengwu HUANG
//! \version
//!     0.1 (develpment version)
//! \date
//!     2013-07-03
//! \brief
//!     Provides Axis-Aligned Bounding Box (AABB).
//////////////////////////////////////////////////////////////////////////////

#ifndef SAC2_BOUNDING_BOX_HPP
#define SAC2_BOUNDING_BOX_HPP

#include <sac2_type.hpp>

namespace sac2
{

class BoundingBox
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Default constructor.
  //! \details
  //!     Construct an empty bounding box.
  ////////////////////////////////////////////////////////////////////////////
  BoundingBox();

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Override constructor.
  //! \param[in] min
  //!     The minimum point of the bounding box.
  //! \param[in] max
  //!     The maximum point of the bounding box.
  ////////////////////////////////////////////////////////////////////////////
  BoundingBox(const point_t& min, const point_t& max);

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Override constructor.
  //! \param[in] min_x
  //!     The x coordinate of the minimum point of the bounding box.
  //! \param[in] min_y
  //!     The y coordinate of the maximum point of the bounding box.
  //! \param[in] max_x
  //!     The x coordinate of the minimum point of the bounding box.
  //! \param[in] max_y
  //!     The y coordinate of the maximum point of the bounding box.
  ////////////////////////////////////////////////////////////////////////////
  BoundingBox(float min_x, float min_y, float max_x, float max_y);

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Copy constructor.
  ////////////////////////////////////////////////////////////////////////////
  BoundingBox(const BoundingBox& box);

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Default destructor.
  ////////////////////////////////////////////////////////////////////////////
  ~BoundingBox();

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Assignment operator.
  ////////////////////////////////////////////////////////////////////////////
  BoundingBox& operator=(const BoundingBox& box);

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Operator ().
  //! \param[in] min
  //!     The minimum point of the bounding box.
  //! \param[in] max
  //!     The maximum point of the bounding box.
  ////////////////////////////////////////////////////////////////////////////
  void operator()(const point_t& min, const point_t& max);

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Operator ().
  //! \param[in] min_x
  //!     The x coordinate of the minimum point of the bounding box.
  //! \param[in] min_y
  //!     The y coordinate of the maximum point of the bounding box.
  //! \param[in] max_x
  //!     The x coordinate of the minimum point of the bounding box.
  //! \param[in] max_y
  //!     The y coordinate of the maximum point of the bounding box.
  ////////////////////////////////////////////////////////////////////////////
  void operator()(float min_x, float min_y, float max_x, float max_y);

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Get the center of the bounding box.
  //! \return
  //!     Return the coordinates of the center point of the bounding box.
  ////////////////////////////////////////////////////////////////////////////
  point_t get_center() const;

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Test whether this bounding box is intersecting a specified one.
  //! \param[in] box
  //!     The bounding box to test with.
  //! \return
  //!     Return \b true whether two the bounding box and the specified one
  //!     are intersecting, \b false otherwise.
  ////////////////////////////////////////////////////////////////////////////
  bool intersect(const BoundingBox& box) const;

private:
  //! The lower bounds of the \c x and \c y axis (top left point).
  point_t m_min;
  //! The higher bounds of the \c x and \c y axis (bottom right point).
  point_t m_max;
};

}

#include <sac2_bounding_box.inl>

#endif  //! SAC2_BOUNDING_BOX_HPP
