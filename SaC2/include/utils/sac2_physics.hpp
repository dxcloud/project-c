#ifndef SAC2_PHYSICS_HPP
#define SAC2_PHYSICS_HPP

#include <sac2_type.hpp>
#include <sac2_vector2d.hpp>

namespace sac2
{

namespace constants
{

const float G(6.67384e-11F);
const float g(9.80665F);
const float c(299792458.0F);

}

point_t free_fall(const point_t& initial_position,
                  const vector_t& initial_velocity,
                  float dt);



}

#endif //! SAC2_PHYSICS_HPP
