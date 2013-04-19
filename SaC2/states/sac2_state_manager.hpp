#ifndef _SAC2_STATE_MANAGER_HPP_
#define _SAC2_STATE_MANAGER_HPP_

/*!
 * \file    sac2_state_manager.hpp
 * \author  Chengwu HUANG
 * \version 0.1
 * \date    2013-04-08 - Initial Development
 * \brief   Provides the StateManager class
 */

#include <vector>

#include "sac2_type.hpp"
#include "sac2_manager.hpp"

namespace sac2
{

class GameState;  // forward declaration

//! GameState iterator
typedef std::vector<GameState*>::iterator state_it;

//! \class StateManager
/*!
 * \brief   The class \b StateManager is used for Game states management
 * \warning The class is implemented with Singleton Pattern
 */
class StateManager: public Manager<StateManager>
{
 public:

  friend class Manager<StateManager>;

  /*!
   * \brief  Test whether the state stack is empty
   * \return Return \b true if the state stack is empty, \b false otherwise
   */
  bool is_empty() const
  {
    return m_states.empty();
  }

  /*!
   * \brief   Get the current state
   * \return  Pointer of the current state
   */
  GameState* get_state() const
  {
    return m_states.back();
  }

  /*!
   * \brief   Set the state specified by \a id to active
   * \details If the parameter \a id is NOT specified, the current state will
   *          be set to active
   * \param   id Identifier of the state to make it active
   * \return  SaC2 status
   */
  sac2_status_t set_state_to_active(sac2_state_id_t id=STATE_CURRENT);

  /*!
   * \brief   Set the state specified by \a id to inactive
   * \details If the parameter \a id is NOT specified, the current state will
   *          be set to inactive
   * \param   id Identifier of the state to make it inactive
   * \return  SaC2 status
   */
  sac2_status_t set_state_to_inactive(sac2_state_id_t id=STATE_CURRENT);

  /*!
   * \brief   Make the state specified by \a id the current state
   * \details Depends on \a activated, the state will be set to active
   *          or inactive. If \a id is \b STATE_CURRENT, the state will only
   *          be set to active or inactive
   * \param   id        Identifier of the state to make it the current state
   * \param   activated Set the current state to active or inactive
   * \return  SaC2 status
   */
  sac2_status_t set_state_to_current(sac2_state_id_t id, bool activated=true);

  /*!
   * \brief   Add a state on the state stack, make it as the current state
   * \details Depends on \a activated, the added state will be set to active
   *          or inactive.
   * \param   state      Pointer of the state to be added
   * \param   activated  Set the added state to active or inactive
   * \return  SaC2 status
   */
  sac2_status_t add_state(GameState* state, bool activated=true);

  /*!
   * \brief   Reset the state specified by \a id
   * \details If the parameter \a id id NOT specified the current state will
   *          be reset. The state will be set to inactive
   * \param   id Identifier of the state to be reset
   * \return  SaC2 status
   */
  sac2_status_t reset_state(sac2_state_id_t id=STATE_CURRENT);

  /*!
   * \brief   Remove the current state from state stack and return to the
   *          previous state on the stack.
   * \return  SaC2 status
   */
  sac2_status drop_state();

  /*!
   * \brief   Remove the state specified by \b id from the state stack
   * \details If the current state should be removed use \b drop_state()
   *          instead
   * \param   id Identifier of the state to be removed
   * \return  SaC2 status
   */
  sac2_status_t remove_state(sac2_state_id_t id);

  /*!
   * \brief  Handle events
   * \param  event Type of event
   * \param  input Input from Keyboard or Mouse
   * \return SaC2 status
   */
  sac2_status_t handle_events(const sf::Event& event,
                              const sf::Input& input);

  /*!
   * \brief Clean all states of the dropped state stack
   */
  void cleanup();

  void update();
 protected:

  /*!
   * \brief   Default private Constructor
   * \details Only one State Manager is allowed
   */
  StateManager();

  /*!
   * \brief   Private Destructor
   * \details Clean all states on the active and dropped stack
   */
  ~StateManager();

 private:
  /**
   * \brief   Private copy constructor
   * \details This class is NOT allowed to be copied
   */
  StateManager(const StateManager& state_manager);

  /**
   * \brief   Private assignment operator
   * \details This class is NOT allowed to be copied
   */
  const StateManager& operator=(const StateManager& state_manager);

  /*!
   * \brief  Find the state specified by \a id
   * \param  id Identifier of the desired state
   * \return Pointer of the desired state
   *         Return 0 if NOT found
   */
  GameState* find_state(sac2_state_id_t id=STATE_CURRENT);

  //! Stack of currently used states
  std::vector<GameState*> m_states;
  //! Stack of states ready to be cleaned
  std::vector<GameState*> m_dropped_states;
};  // class StateManager


inline StateManager::StateManager():
    m_states(0),
    m_dropped_states(0)
{

}

inline StateManager::~StateManager() {
  while (false == m_states.empty()) {
    drop_state();
  }
  cleanup();
}

}  // namespace sac2

#endif //! _SAC2_STATE_MANAGER_HPP_
