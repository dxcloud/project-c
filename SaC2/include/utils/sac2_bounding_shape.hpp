#ifndef SAC2_BOUNDING_SHAPE_HPP
#define SAC2_BOUNDING_SHAPE_HPP

#include <sac2_type.hpp>

namespace sac2
{

class BoundingShape
{
public:
  BoundingShape() {};
  virtual ~BoundingShape() {};
  //! Compute the area of the shape.
  virtual float area() const = 0;
};

}

#endif  //! SAC2_BOUNDING_SHAPE_HPP
