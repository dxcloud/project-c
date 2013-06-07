#include "sac2_menu_state.hpp"

namespace sac2
{

void MenuState::initialize()
{
/*
  if (false == m_initialized) {

    p_asset_manager->load_sprite(m_sprite, "IM02");
    p_asset_manager->load_font(m_text, "FT01");
    m_text.set_text("Hello World");
    m_text.set_position(500, 200);
    m_text.rotate(90);
    p_asset_manager->load_sound(m_sound, "SD01");
    p_asset_manager->load_music(m_music, "MS01");

    m_initialized = true;
  }
*/
}

/*
void MenuState::handle_events(const sf::Event& event)
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
  else if (true == input.IsKeyDown(sf::Key::Num1)) {
    m_sprite.unload();
    p_asset_manager->load_sprite(m_sprite, "IM01");
  }
  else if (true == input.IsKeyDown(sf::Key::Num2)) {
    m_sprite.unload();
    p_asset_manager->load_sprite(m_sprite, "IM02");
  }
  else if (true == input.IsKeyDown(sf::Key::Num3)) {
    m_sprite.unload();
    p_asset_manager->load_sprite(m_sprite, "IM03");
  }
  else if (true == input.IsKeyDown(sf::Key::Num4)) {
    m_sprite.unload();
    p_asset_manager->load_sprite(m_sprite, "IM04");
  }
  else if (true == input.IsKeyDown(sf::Key::Num5)) {
    m_sprite.unload();
    p_asset_manager->load_sprite(m_sprite, "IM05");
  }
  else if (true == input.IsKeyDown(sf::Key::S)) {
    m_sound.play();
  }
  else if (true == input.IsKeyDown(sf::Key::M)) {
    m_music.play();
  }

}
*/

void MenuState::update()
{
  draw();

}

void MenuState::draw()
{
//  p_window_manager->draw_sprite(m_sprite);
//  p_window_manager->display_text(m_text);

}

void MenuState::cleanup()
{

}

void MenuState::pause()
{

}

void MenuState::resume()
{

}

}
