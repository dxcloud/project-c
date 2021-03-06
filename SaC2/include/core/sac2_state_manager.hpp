//////////////////////////////////////////////////////////////////////////////
//! \file sac2_state_manager.hpp
//! \author
//!     Chengwu HUANG
//! \version
//!     0.2 (alpha)
//! \date
//!     2013-04-08: Initial develepment.
//! \brief
//!     Provides StatettManager class.
//////////////////////////////////////////////////////////////////////////////

#ifndef SAC2_STATE_MANAGER_HPP
#define SAC2_STATE_MANAGER_HPP

#include <map>
#include <vector>

#include <sac2_type.hpp>
#include <sac2_manager.hpp>

namespace sac2
{
// forward declaration
class GameState;

//////////////////////////////////////////////////////////////////////////////
//! \class StateManager
//! \brief
//!     This class is used to manage \b sac2::GameState.
//! \details
//!     A State Machine is implemented by the manager.
//! \note
//!     This class is implemented with Singleton Pattern
//////////////////////////////////////////////////////////////////////////////
class StateManager:
  public Manager<StateManager>
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Allows to call constructor and destructor of private attribute.
  ////////////////////////////////////////////////////////////////////////////
  friend class Manager<StateManager>;

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Game State Stack.
  ////////////////////////////////////////////////////////////////////////////
  typedef std::vector<GameState*> state_stack_t;

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Collection, associates ID with Game State.
  ////////////////////////////////////////////////////////////////////////////
  typedef std::map<state_id_t, GameState*> state_map_t;

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Iterator, equivalent to \b state_map_t::iterator.
  ////////////////////////////////////////////////////////////////////////////
  typedef state_map_t::iterator state_iter_t;

public:
  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Test whether the state stack is empty.
  //! \return
  //!     Return \b true whether the state stack is empty, \b false otherwise.
  ////////////////////////////////////////////////////////////////////////////
  bool is_empty() const;

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Update the Manager.
  //! \details
  //!     Update the current Game State.
  //! \param dt
  //!     Elapsed time.
  ////////////////////////////////////////////////////////////////////////////
  void update(float dt);

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Add a new state into the state collection.
  //! \details
  //!     The parameter \b id must be unique, otherwise the second parameter
  //!     will be automatically deleted.
  //! \param id
  //!     Identifier of the new state.
  //! \param game_state
  //!     Pointer of the state to be added, it must be allocated with
  //!     the keyword \b new.
  //! \return
  //!     Status code.
  //! \retval STATUS_SUCCESS
  //!     Successfully added.
  //! \retval STATUS_ALREADY
  //!     The identifier is already used.
  ////////////////////////////////////////////////////////////////////////////
  status_t add_state(state_id_t id, GameState* game_state);

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Start a Game State.
  //! \param id
  //!     Identifier of the Game State to be played.
  //! \return
  //!     Status code.
  //! \retval STATUS_SUCCESS
  //!     Successfully started the Game State specified by \b id.
  //! \retval STATUS_MISS
  //!     Game State not found.
  ////////////////////////////////////////////////////////////////////////////
  status_t start_state(state_id_t id);

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Initialize the Game State on the top of the stack.
  //! \return
  //!     Status code.
  //! \retval STATUS_SUCCESS
  //!     Successfully initialized the Game State.
  //! \retval STATUS_CANCEL
  //!     Method has no effect.
  //! \see sac2::GameState::initializing
  ////////////////////////////////////////////////////////////////////////////
  status_t initialize_state();

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Pause the current Game State.
  //! \return
  //!     Status code.
  //! \retval STATUS_SUCCESS
  //!     Successfully paused the Game State.
  //! \retval STATUS_CANCEL
  //!     Method has no effect.
  //! \see sac2::GameState::pausing
  ////////////////////////////////////////////////////////////////////////////
  status_t pause_state();

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Resume the current Game State.
  //! \return
  //!     Status code.
  //! \retval STATUS_SUCCESS
  //!     Successfully resume the Game State.
  //! \retval STATUS_CANCEL
  //!     Method has no effect.
  //! \see sac2::GameState::resuming
  ////////////////////////////////////////////////////////////////////////////
  status_t resume_state();

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Stop and clean the current Game State.
  //! \return
  //!     Status code.
  //! \retval STATUS_SUCCESS
  //!     Successfully stopped the Game State.
  //! \retval STATUS_CANCEL
  //!     Method has no effect.
  //! \see sac2::GameState::cleaning
  ////////////////////////////////////////////////////////////////////////////
  status_t stop_state();

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Remove the Game State from the stack.
  //! \return
  //!     Status code.
  //! \retval STATUS_SUCCESS
  //!     Successfully paused the Game State.
  //! \retval STATUS_CANCEL
  //!     Method has no effect.
  ////////////////////////////////////////////////////////////////////////////
  status_t drop_state();

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Reinitialize the current Game State.
  //! \return
  //!     Status code.
  //! \retval STATUS_SUCCESS
  //!     Successfully paused the Game State.
  //! \retval STATUS_CANCEL
  //!     Method has no effect.
  //! \see sac2::GameState::cleaning
  //! \see sac2::GameState::initializing
  ////////////////////////////////////////////////////////////////////////////
  status_t reset_state();

protected:
  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Clean the stack and collection.
  ////////////////////////////////////////////////////////////////////////////
  void cleanup();

private:
  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Stack of currently used Game States
  ////////////////////////////////////////////////////////////////////////////
  state_stack_t m_state_stack;

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Collection of available Game States.
  ////////////////////////////////////////////////////////////////////////////
  state_map_t   m_state_map;

private:
  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Private default constructor.
  ////////////////////////////////////////////////////////////////////////////
  StateManager();

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Private destructor.
  ////////////////////////////////////////////////////////////////////////////
  ~StateManager();

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Private copy constructor.
  ////////////////////////////////////////////////////////////////////////////
  StateManager(const StateManager&);

  ////////////////////////////////////////////////////////////////////////////
  //! \brief
  //!     Private assignment operator.
  ////////////////////////////////////////////////////////////////////////////
  StateManager& operator=(const StateManager&);
};  // class StateManager

}  // namespace sac2

#endif //! SAC2_STATE_MANAGER_HPP
