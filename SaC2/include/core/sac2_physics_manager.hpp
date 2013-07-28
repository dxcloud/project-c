#ifndef SAC2_PHYSICS_MANAGER_HPP
#define SAC2_PHYSICS_MANAGER_HPP

#include <sac2_manager.hpp>

namespace sac2
{

class PhysicsManager:
  Manager<PhysicsManager>
{
public:
private:
  PhysicsManager();
  ~PhysicsManager();
  PhysicsManager(const PhysicsManager&);
  PhysicsManager& operator=(const PhysicsManager&);
};

}  // namespace sac2

#endif  //! SAC2_PHYSICS_MANAGER_HPP
