#ifndef _STATE_MANAGER_HPP_
#define _STATE_MANAGER_HPP_

#include <vector>

#include "sac2_type.hpp"

namespace sac2
{

class StateManager
{
 public:
  StateManager();
  
  ~StateManager();
  
  bool is_empty();
  
  sac2_status_t  add_state(GameState* state);
  
  sac2_status_t remove_state(sac2_state_id_t _id);
  
 protected:
 private:
  std::vector<GameState*> m_states;

};  // class StateManager

};

#endif //! _SAC2_STATE_MANAGER_HPP_