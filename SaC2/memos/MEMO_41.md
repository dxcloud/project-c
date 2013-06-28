# MEMO 41: GAME STATES MANAGEMENT - GAME STATE
**File:** MEMO_41.md    
**Status:** Draft    
**Type:** Documentation    
**Author:** Chengwu HUANG    
**Date:** 2013-06-08    
**Last update:** 2013-06-28

## Introduction
All game states are derived from the class `GameState` and are handled by
`StateManager`.    
Before using a game state, several methods must be defined (see section
[*Indirect called methods*](#Indirect called methods)).

## Member functions
The class `GameState` provides two types of methods:
* Query methods: `bool is_XXX()`
* Indirect called methods: `void XXXing()`

### Query methods
`GameState` has an attribute called `m_state_status`, this attribute
is private so that any derived class cannot modify it - consider it as
a read-only attribute.    
This attribute contains information about the current state status of
the game state (see **MEMO 42** for more information about State lifecycle).    
The *query methods* is the only way to know the current state status.
The prototype of these methods are:
* `bool GameState::is_initialized()`
* `bool GameState::is_running()`
* `bool GameState::is_paused()`
* `bool GameState::is_stopped()`

<a name="Indirect called methods"></a>
### Indirect called methods
These methods are those should be defined. When the state status has changed,
one of these method is called.

#### Initialization
**Prototype:** `void initializing()`    
**Called by:** `StateManager::initialize_state()`, `StateManager::reset_state()`

#### Pause
**Prototype:** `void pausing()`    
**Called by:** `StateManager::pause_state()`

#### Resume
**Prototype:** `void resuming()`    
**Called by:** `StateManager::resume_state()`

#### Update
**Prototype:** `void updating(float dt)`    
**Called by:** `StateManager::update()`

#### Stop
**Prototype:** `void cleaning()`    
**Called by:** `StateManager::stop_state()`

## Handling lifecycle
Use methods provided by `StateManager` to change the state status of
the game state. Calling a method from `StateManager` has sometime no effect.
Checking the return status code allows to know whether the call is failed.    
The following table shows methods of `StateManager` could be called depending
on the current state status.


| Current status     | Available method                   | Next status     |
|--------------------|------------------------------------|-----------------|
| **UNINITIALIZED**  | `StateManager::initialize_state()` | **RUNNING**     |
| **RUNNING**        | `StateManager::pause_state()`      | **PAUSED**      |
| **PAUSED**         | `StateManager::resume_state()`     | **RUNNING**     |
| **PAUSED**         | `StateManager::stop_state()`       | **STOPPED**     |
| **STOPPED**        | `StateManager::reset_state()`      | **RUNNING**     |


## See also
**MEMO 42:** Game States Management - State Machine
