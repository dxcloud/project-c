#include "sac2_menu_state.hpp"

namespace sac2
{

sac2_status_t MenuState::initialize()
{
  return STATUS_SUCCESS;
}

sac2_status_t MenuState::handle_events(const sf::Event& event,
                                       const sf::Input& input)
{
  if (true == input.IsKeyDown(sf::Key::Escape)) {
    if (false == m_pause) return STATUS_QUIT;  // Request for Engine::quit()
  }
  else if (true == input.IsKeyDown(sf::Key::P)) { m_pause = true; }
  else if (true == input.IsKeyDown(sf::Key::R)) { m_pause = false; }

  return STATUS_SUCCESS;
}

sac2_status_t MenuState::update()
{
  return STATUS_SUCCESS;
}

sac2_status_t MenuState::draw()
{
  return STATUS_SUCCESS;
}

sac2_status_t MenuState::cleanup()
{
  return STATUS_SUCCESS;
}

}