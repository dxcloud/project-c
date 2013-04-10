#include "sac2_menu_state.hpp"
//#include "sac2_engine.hpp"

namespace sac2
{

sac2_status_t MenuState::init()
{
  return STATUS_SUCCESS;
}

sac2_status_t MenuState::handle_events(sf::Event event)
{
  if (event.Type == sf::Event::Closed) {
    p_engine->quit();
  }
  return STATUS_SUCCESS;
}

sac2_status_t MenuState::update()
{
  //return p_engine->update();
  return STATUS_SUCCESS;
}

sac2_status_t MenuState::draw()
{
  //return p_engine->draw();
  return STATUS_SUCCESS;
}

sac2_status_t MenuState::cleanup()
{
// delete
  return STATUS_SUCCESS;
}

}