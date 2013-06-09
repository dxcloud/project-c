# GAME STATE MANAGEMENT: GAME STATE
**MEMO 41: 2013-06-08**

## Introduction
All game states should be handled by `StateManager'.
Methods provided by `GameState' must NOT be called directly,
use StateManager instead.

## Lifecycle
### Uninitialized
`StateManager::initialize_state()'
### Initialized
`StateManager::start_state()'
### Running
`StateManager::pause_state()'
### Paused
`StateManager::resume_state()', `StateManager::stop_state()'
### Stopped
`StateManager::reset_state()'

## Member functions

### void initializing()
Initialize 

Called by: `StateManager::initialize_state()', `StateManager::reset_state()'

### void pausing()

Called by `StateManager::pause_state()'

### void resuming()

Called by `StateManager::resume_state()'

### void updating()

Called by `StateManager::update()'

### void cleaning()

Called by `StateManager::stop_state()'
