#include <sac2.hpp>
#include "test_04.hpp"

using namespace sac2;

const sac2::state_id_t TestState::S1(0x01);
const sac2::state_id_t TestState::S2(0x02);

void test(StateManager* manager)
{
  TestInputConfig input_config;
  while (false == input_config.is_end()) {
    input_config.handle_inputs();
  }
}

int main()
{
  StateManager* manager(StateManager::create());
  manager->add_state(TestState::S1, new TestState("1"));
  manager->add_state(TestState::S2, new TestState("2"));

  test(manager);

  StateManager::destroy();
  return 0;
}
