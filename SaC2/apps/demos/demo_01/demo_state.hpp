#ifndef DEMO_STATE_HPP
#define DEMO_STATE_HPP

#include <iostream>

#include <sac2.hpp>

#include "resource.hpp"

class DemoState: public sac2::GameState
{
public:
  DemoState() { }
  virtual ~DemoState() { }

  void initializing() {
    if (sac2::STATUS_SUCCESS != sac2::AssetManager::instance().use_texture(BALL, m_ball_sprite)) {
      std::cout << "Failed to load sprite" << std::endl;
      return;
    }
    m_ball_position = m_ball_sprite.get_position();
  }
  void pausing() {}
  void resuming() {}
  void cleaning() {}
  void updating(float dt) {
    sac2::point_t pos;
    pos = sac2::free_fall(m_ball_position, 5.0F * sac2::vector_t::ones, dt);
    m_ball_sprite.move(pos.x, pos.y);
//    std::cout << pos << std::endl;

    m_ball_sprite.draw();
//    p_rendering_manager->clear();
//    p_rendering_manager->draw_sprite(m_ball_sprite);
//    p_rendering_manager->display();
  }

private:
  sac2::SpriteAsset m_ball_sprite;
  sac2::point_t m_ball_position;
};

#endif
