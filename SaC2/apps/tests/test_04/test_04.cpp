//////////////////////////////////////////////////////////////////////////////
//! \file test_04.cpp
//! \author
//!     Chengwu HUANG
//! \version
//!     0.1 (alpha)
//! \date
//!     2013-08-17
//! \brief
//!     Test Game State Management.
//////////////////////////////////////////////////////////////////////////////

#include "test_04.hpp"

void test()
{
  TestState* state1(new TestState("STATE1"));
  TestState* state2(new TestState("STATE2"));
  STATE_MANAGER.add_state(SID1, state1);
  STATE_MANAGER.add_state(SID1, new TestState("Unused State"));
  STATE_MANAGER.add_state(SID2, state2);
  STATE_MANAGER.start_state(59);  // ID no recognized

  TestInputConfig input1;
  input1.bind_game_state(state1);
  INPUT_MANAGER.set_input_config(&input1);
  STATE_MANAGER.start_state(SID1);

  sf::RenderWindow window(sf::VideoMode(300, 300), "TEST 04");
  window.setVerticalSyncEnabled(true);
  window.setFramerateLimit(10);
  while (window.isOpen())
  {
    INPUT_MANAGER.update(0.1);
    STATE_MANAGER.update(0.1);
    if (STATE_MANAGER.is_empty() == true) {
      cout << ">>>>>>>>Empty Stack" << endl;
    }
    window.clear(sf::Color(0xFF, 0x00, 0x00));
    window.display();

    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }
  }  // window still opened
}

int main()
{
//  test();
  test();
  sac2::InputManager::destroy();
  sac2::StateManager::destroy();
  return 0;
}
