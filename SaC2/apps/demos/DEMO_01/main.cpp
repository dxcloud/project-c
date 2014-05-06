#include <sac2.hpp>
#include "demo_state.hpp"
#include "../../../include/core/sac2_engine.hpp"

enum {
  DEMO_STATE_ID = 100
};

int main()
{
  ASSET_MANAGER.load_texture(C001);
  STATE_MANAGER.add_state(DEMO_STATE_ID, new DemoState);
  STATE_MANAGER.start_state(DEMO_STATE_ID);
  Engine app;
  app.run();
  return 0;
}

