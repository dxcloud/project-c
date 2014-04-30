#include "demo_state.hpp"



int main()
{
  sac2::state_id_t demo_id(1);
  sac2::StateManager::instance().add_state(demo_id, new DemoState);
  sac2::StateManager::instance().start_state(demo_id);
  sac2::Engine engine;
  engine.run();
  return 0;
}