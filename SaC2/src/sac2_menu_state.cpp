#include "sac2_menu_state.hpp"

namespace sac2
{

sac2_status_t MenuState::initialize()
{
  if (false == m_initialized) {
    p_asset_manager->load_sprite(m_sprite, "IM04");
    m_initialized = true;
    return STATUS_SUCCESS;
  }
  return STATUS_ALREADY;
}

sac2_status_t MenuState::handle_events(const sf::Event& event,
                                       const sf::Input& input)
{
  if (true == input.IsKeyDown(sf::Key::Escape)) {
    if (false == m_paused) { p_window_manager->close(); }  // request Engine::quit()
  }  // 'Escape' quit, 'P' pause, 'R' resume
  else if (true == input.IsKeyDown(sf::Key::P)) { m_paused = true; }
  else if (true == input.IsKeyDown(sf::Key::R)) { m_paused = false; }
  else if (true == input.IsKeyDown(sf::Key::Up)) { m_sprite.move(0, -10); }
  else if (true == input.IsKeyDown(sf::Key::Down)) { m_sprite.move(0, 10); }
  else if (true == input.IsKeyDown(sf::Key::Left)) { m_sprite.move(-10, 0); }
  else if (true == input.IsKeyDown(sf::Key::Right)) { m_sprite.move(10, 0); }

  return STATUS_SUCCESS;
}

sac2_status_t MenuState::update()
{
  draw();
  return STATUS_SUCCESS;
}

sac2_status_t MenuState::draw()
{
  p_window_manager->draw(m_sprite);
  return STATUS_SUCCESS;
}

sac2_status_t MenuState::cleanup()
{
  return STATUS_SUCCESS;
}

}
