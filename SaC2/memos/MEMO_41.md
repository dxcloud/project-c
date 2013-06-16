﻿# MEMO 41: GAME STATE MANAGEMENT - GAME STATE
**File:** MEMO_41.md    
**Author:** Chengwu HUANG    
**Date:** 2013-06-08    
**Last update:** 2013-06-20

## Introduction
All game states are derived from the class **GameState** and are handled by
**StateManager** class.
To use a game state, several methods must be defined (see paragraph below).

## Member functions
### void GameState::initializing()
If a state has specific attributes, use this method to initialize them.

**Called by:** `StateManager::initialize_state()`, `StateManager::reset_state()`

### void GameState::pausing()
This method is called when the state is set to pause.

**Called by:** `StateManager::pause_state()`

### void GameState::resuming()
In opposition to `pausing()`, this method is called the **StateManager** tries
to resume the state.

**Called by:** `StateManager::resume_state()`

### void GameState::updating(float dt)
Called each time while the state is in **RUNNING** status. Can be used updating
sprites.

**Called by:** `StateManager::update()`

### void GameState::cleaning()
Used for cleaning attributes.

**Called by:*** `StateManager::stop_state()`

## Lifecycle
A **GameState** has also a attribute called **m_state_status**, this attribute
is private so that any derived class cannot modify it, and only
**StateManager** is able to do it. This attribute contains information about
the current period of the state lifecycle (see *MEMO 42* for more information
about State lifecycle). The *query methods* is the only way to know
the current state status, these methods are:
* `is_initialized()`
* `is_running()`
* `is_paused()`
* `is_stopped()`

Because of this state status, the call of some methods from **StateManager**
has no effect. The following paragraphes show the available methods in each
state.

### Uninitialized
**Available:** `StateManager::initialize_state()`

### Initialized
**Available:** `StateManager::start_state()`

### Running
**Available:** `StateManager::pause_state()`

### Paused
**Available:** `StateManager::resume_state()`, `StateManager::stop_state()`

### Stopped
**Available:** `StateManager::reset_state()`

## See also
*MEMO 42:* State Machine

