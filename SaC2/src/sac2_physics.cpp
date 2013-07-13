#include <sac2_physics.hpp>

namespace sac2
{

point_t free_fall(const point_t& initial_position,
                  const vector_t& initial_velocity,
                  float dt)
{
  point_t result(initial_position);
  result.x += initial_velocity.x * dt;
  result.y += (initial_velocity.y * dt) + (0.5F * cts::ACCELERATION * dt * dt);
  return result;
}

}
