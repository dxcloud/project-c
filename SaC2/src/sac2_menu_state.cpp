#include "sac2_menu_state.hpp"

namespace sac2
{

sac2_status_t MenuState::initialize()
{
//  p_asset_manager->add_asset(ASSET_SPRITE, "/home/orange/project-c/SaC2/samples/image01.png", "DX");
//  p_sprite = p_asset_manager->get_asset(ASSET_SPRITE, "DX");
//sf::Image image;
//image.LoadFromFile("/home/orange/project-c/SaC2/samples/image01.png");
//image.SetSmooth(false);
  m_sprite.load_asset();

  return STATUS_SUCCESS;
}

sac2_status_t MenuState::handle_events(const sf::Event& event,
                                       const sf::Input& input)
{
  if (true == input.IsKeyDown(sf::Key::Escape)) {
    if (false == m_pause) { return STATUS_QUIT; }  // Request for Engine::quit()
  }  // 'Escape' quit, 'P' pause, 'R' resume
  else if (true == input.IsKeyDown(sf::Key::P)) { m_pause = true; }
  else if (true == input.IsKeyDown(sf::Key::R)) { m_pause = false; }
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
//  p_asset_manager->draw(m_sprite);
  return STATUS_SUCCESS;
}

sac2_status_t MenuState::cleanup()
{
  return STATUS_SUCCESS;
}

}
