#ifndef _SAC2_GAME_STATE_HPP_
#define _SAC2_GAME_STATE_HPP_

#include "sac2_type.hpp"

/*!
 * Provides the State interface used by all game engines
 */

namespace sac2
{

//! \class GameState
/*!
 * \brief Base class interface for all game states
 */
class GameState
{
 public:
  GameState(sac2_state_id_t id, Engine* _engine):
    m_state_id(id),
    p_engine(_engine),
    m_pause(false)
  {  }

  virtual ~GameState() {  }
  
  virtual sac2_state_id_t get_state_id() const { return m_state_id; }
  
  virtual sac2_status_t pause() { m_pause = true; }
  
  virtual sac2_status_t resume() { m_pause = false; }
  
  virtual sac2_status_t reset() {  }
  
  virtual sac2_status_t handle_events(sf::Event event) = 0;
  
  virtual sac2_status_t update() = 0;
  
  virtual sac2_status_t draw() = 0;

  virtual sac2_status_t cleanup() = 0;

protected:

  const sac2_state_id_t m_state_id;
  Engine*               p_engine;
  bool                  m_pause;

 private:
};  // class GameState

};

#endif