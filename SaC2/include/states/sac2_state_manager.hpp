/*!
 * \file    sac2_state_manager.hpp
 * \author  Chengwu HUANG
 * \version 0.1
 * \date    2013-04-08 - Initial Development
 * \brief   Provides the StateManager class
 */

#ifndef SAC2_STATE_MANAGER_HPP
#define SAC2_STATE_MANAGER_HPP

#include <vector>
#include <map>

#include <sac2_type.hpp>
#include <sac2_manager.hpp>
#include <sac2_logger.hpp>

namespace sac2
{

class GameState;  // forward declaration

typedef std::vector<GameState*>::iterator state_it;  //!< GameState iterator
typedef std::map<state_id_t, GameState*> state_map_t;
typedef state_map_t::iterator state_iter_t;
typedef state_map_t::const_iterator state_const_iter_t;

/*!
 * \class   StateManager
 * \brief   The class \b StateManager is used for Game states management
 * \details A State Machine is implemented by this manager.
 * \note    The class is implemented with Singleton Pattern.
 */
class StateManager:
  public Manager<StateManager>
{
public:
  friend class Manager<StateManager>;

public:
  /*!
   * \brief  Test whether the state stack is empty
   * \return Return \b true if the state stack is empty, \b false otherwise.
   */
  bool is_empty() const;

  /*!
   * \brief   Update the StateManager
   * \details The current RUNNING game state will be updated.
   */
  void update(float dt);

  /*!
   * \brief   Add a new state to the collection of the states
   * \param   id         Identifier of the new state.
   * \param   game_state Pointer of the state to be added, it must be
   *                     allocated with the keyword \b new.
   * \return  Status code:
   *          - \b STATUS_SUCCESS
   *          - \b STATUS_ALREADY
   * \details The parameter \b id must be unique, if the identifier is
   *          already used the state will NOT be added but deleted.
   */
  status_t add_state(state_id_t id, GameState* game_state);

  /*!
   * \brief  Change the current state to the one specified by \b id
   * \param  id Identifier of the state to be played
   * \return Status code:
   *         - \b STATUS_SUCCESS
   *         - \b STATUS_INVAL
   */
  status_t start_state(state_id_t id);

  /*!
   * \brief   Initialize the state on the top of the stack
   * \return  The following status could be returned:
   *          - \b STATUS_SUCCESS
   *          - \b STATUS_CANCEL
   * \details Initialize the state, \b GameState::initializing() is called
   */
  status_t initialize_state();

  /*!
   * \brief   Set the current state to pause
   * \return  The following status could be returned:
   *          - \b STATUS_SUCCESS
   *          - \b STATUS_CANCEL
   * \details Pause the state, \b GameState::pausing() is called
   */
  status_t pause_state();

  /*!
   * \brief   Resume the current state
   * \return  The following status could be returned:
   *          - \b STATUS_SUCCESS
   *          - \b STATUS_CANCEL
   * \details Resume the state, \b GameState::resuming() is called
   */
  status_t resume_state();

  /*!
   * \brief   Stop and clean the state
   * \return  The following status could be returned:
   *          - \b STATUS_SUCCESS
   *          - \b STATUS_CANCEL
   * \details Stop the state, \b GameState::cleaning() is called
   */
  status_t stop_state();

  /*!
   * \brief   Remove the current state from the stack
   * \return  The following status could be returned:
   *          - \b STATUS_SUCCESS
   *          - \b STATUS_CANCEL
   * \details Remove the state if it is \b STOPPED
   */
  status_t drop_state();

  /*!
   * \brief   Reinitialize the current state
   * \return  The following status could be returned:
   *          - \b STATUS_SUCCESS
   *          - \b STATUS_CANCEL
   * \details Reset the state, \b GameState::cleaning() and
   *          \b GameState::initializing() are called
   */
  status_t reset_state();

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

  /*!
   * \brief  Initialize the manager
   */
  void initialize();

  /*!
   * \brief  Clean all states of the state collection
   */
  void cleanup();

private:
  /**
   * \brief   Private copy constructor
   * \details This class is NOT allowed to be copied
   */
  StateManager(const StateManager&);

  /**
   * \brief   Private assignment operator
   * \details This class is NOT allowed to be copied
   */
  StateManager& operator=(const StateManager&);

  /*!
   * \brief  Find the state specified by the parameter \b id
   * \param  id Identifier of the desired state
   * \return Pointer of the desired state or 0 if the state is NOT found.
   */
  GameState* find_state(state_id_t id) const;

  //! Stack of currently used states
  std::vector<GameState*> m_state_stack;
  //! Map of available states
  std::map<state_id_t, GameState*> m_game_states;
};  // class StateManager

//----------------------------------------------------------------------------
//  StateManager::constructor
//----------------------------------------------------------------------------
inline StateManager::StateManager():
  m_state_stack(),
  m_game_states()
{
#ifdef SAC2_LOGGER_ENABLED
  Logger::log_debug("StateManager::constructor - start initialization");
#endif
  initialize();
}

//----------------------------------------------------------------------------
//  StateManager::destructor
//----------------------------------------------------------------------------
inline StateManager::~StateManager() {
  cleanup();
#ifdef SAC2_LOGGER_ENABLED
  Logger::log_debug("StateManager::destructor - successfully destroyed");
#endif
}

//----------------------------------------------------------------------------
//  StateManager::is_empty
//----------------------------------------------------------------------------
inline bool StateManager::is_empty() const
{
  return m_state_stack.empty();
}

//----------------------------------------------------------------------------
//  StateManager::find_state
//----------------------------------------------------------------------------
inline GameState* StateManager::find_state(state_id_t id) const
{
  return m_game_states.find(id)->second;
}

}  // namespace sac2

#endif //! SAC2_STATE_MANAGER_HPP
