# MEMO 42: GAME STATE MANAGEMENT - STATE MACHINE
**File:** MEMO_42.md    
**Type:** Information    
**Status:** Draft    
**Author:** Chengwu HUANG    
**Date:** 2013-06-08    
**Last update:** 2013-06-28

## Introduction
Each game state has a built-in state machine to handle its lifecycle.    
The change is done by calling methods provided by the class `StateManager`.
The current state status value is controlled by `StateManager`.

## State machine
The following graph shows the lifecycle of a game state.

```
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
```

## See also
**MEMO 41:** Game State Management - Game State    
**MEMO 43:** Game State Management - Managing States
