#include <sac2.hpp>

using namespace sac2;

int main(int argc, char** argv)
{
  Engine app("First game state");
  app.parse_options(argc, argv);

  StateManager* p_state_manager = StateManager::get_instance();
  MenuState* first_game_state = new MenuState;
  first_game_state->initialize();
  p_state_manager->add_state(first_game_state);

  sac2_status_t status(STATUS_SUCCESS);

  status = app.run();

  return status;
}
