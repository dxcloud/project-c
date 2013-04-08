﻿#ifndef _SAC2_OPENING_STATE_HPP_
#define _SAC2_OPENING_STATE_HPP_

#include <SFML/Window.hpp>

#include "sac2_type.hpp"
#include "sac2_game_state.hpp"

namespace sac2
{

class MenuState: public GameState
{
 public:
  MenuState(Engine* engine, sac2_state_id_t id=MENU):
    GameState(engine, id)
  {}
  virtual ~MenuState() {}
  virtual sac2_status_t handle_events(sf::Event event);
  virtual sac2_status_t update();
  virtual sac2_status_t draw();
  virtual sac2_status_t cleanup();

 protected:
 private:
  // asset
};

}

#endif //!_SAC2_OPENING_STATE_HPP_