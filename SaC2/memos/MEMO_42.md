# MEMO 42: GAME STATE MANAGEMENT - STATE MACHINE
**File:** MEMO_42.md    
**Author:** Chengwu HUANG    
**Date:** 2013-06-08    
**Last update:** 2013-06-20

## Introduction
Each **GameState** has a built-in state machine to handle its lifecycle.
The **StateManager** provides methods that are able to change the current
lifecycle of the **GameState**.

## Lifecycle management methods
The lifecycle management methods provided by **StateManager** return all of them
a status code. The code could be **STATUS_SUCCESS** or **STATUS_CANCEL** (can
be caused whether an unavailable method is called).

### status_t StateManager::initialize_state()
This method must be called once to initialize a state.

**Method to be called:** `GameState::initializing()`

### status_t StateManager::pause_state()
To pause a state. When a state is paused, it is NOT updating any more.

**Method to be called:** `GameState::pausing()`

### status_t StateManager::resume_state()
Resume a state, when called the state can keep updating again.

**Method to be called:** `GameState::resuming()`

### status_t StateManager::stop_state()
Called this method to clean the member attributes of the state.

**Method to be called:** `GameState::cleaning()`

### status_t StateManager::reset_state()
Reinitialize the state.

**Method to be called:** `GameState::initializing()`

## State machine
The following graph show the lifecycle of a **GameState**


                         +---------------+
                         | UNINITIALIZED |
                         +---------------+
                                 | initialize_state()
                                 V
                         +---------------+
                      +->|  INITIALIZED  |
                      |  +---------------+
                      |          |
                      |          V
                      |  +---------------+
        reset_state() |  |    RUNNING    |<-------+
                      |  +---------------+        |
                      |          | pause_state()  | resume_state()
                      |          V                |
                      |  +---------------+        |
                      |  |    PAUSED     |--------+
                      |  +---------------+
                      |         | stop_state()
                      |         V
                      |  +---------------+
                      +--|    STOPPED    |
                         +---------------+


## See also
*MEMO 41:* Game State
*MEMO 43:* Managing States

