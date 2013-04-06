
#include <SML/Event.hpp>

#include "sac2_menu_state.hpp"

namespace sac2
{

sac2_status_t MenuState::handle_events(sf::Event _event)
{
  if (_event.Type == sf::Event::Closed) {
    p_engine->quit();
  }
  return STATUS_SUCCESS;
}

sac2_status_t MenuState::update()
{
  p_engine->update();
}

sac2_status_t MenuState::draw()
{
  p_engine->draw();
}

sac2_status_t MenuState::cleanup()
{
// delete
}

};