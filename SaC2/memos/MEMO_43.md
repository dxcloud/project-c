# MEMO 43: GAME STATE MANAGEMENT - MANAGING STATES
**File:** MEMO_42.md    
**Author:** Chengwu HUANG    
**Date:** 2013-06-08    
**Last update:** 2013-06-20

## Introduction
**StateManager** provides also methods to add a new **GameState**, or to change
the current state. The **StateManager** class has map which associates
**GameState** with an identifier **state_id_t**. It has also a stack, the state
on the top of stack is handled by the manager class, the others are either
paused or stopped.

## Add/Remove states
Use `status_t StateManager::add_state(state_id_t, GameState*)` to add a new
state to the map. The second parameter must be allocated with the keyword `new`.
The **state_id_t** must be unique, otherwise it will have no effect.
It is possible to have two (or more) identical states but the identifier must
be different.

All states are removed from the map when **StateManager** is destroyed.

## State stack
A first game state is pushed on the stack, at the start of the game.
When a new state is started (by calling the method 
`status_t StateManager::start_state(state_id_t)`), it will be pushed on top of
that and the first one will be no longer updated.
When a game state ends, `status_t StateManager::drop_state()` can be called
to pop it off the stack, and then the previous state can be resumed exactly
where it is left off.

The methods `start_state(state_id_t)` and `drop_state()` can be called in any
step of a state lifecycle. They will try to pause the current state first.
The following table show the methods from **GameState** which are called by
these two methods depends on the current state status.

        +---------------+--------------------------------+-------------+
        |               |          start_state           |  drop_state |
        +---------------+-------------+------------------+-------------+
        |               |   current   |       new        |             |
        +==============================================================+
        | UNINITIALIZED |     ---     | initialize_state |     ---     |
        +---------------+-------------+------------------+-------------+
        | RUNNING       | pause_state |       ---        | pause_state |
        +---------------+-------------+------------------+-------------+
        | PAUSED        |     ---     |   resume_state   |     ---     |
        +---------------+-------------+------------------+-------------+
        | STOPPED       |     ---     |   reset_state    |     ---     |
        +---------------+-------------+------------------+-------------+


## Stack management
The following diagram show the management of the stack. The state on the top is
the current displayed state.

                               +=========+
                               | State 3 |
        +=========+            +=========+            +=========+
        | State 2 |            | State 2 |            | State 2 |
        +=========+ =========> +---------+ =========> +=========+
        | State 1 |            | State 1 |            | State 1 |
        +---------+            +---------+            +---------+
              start_state("State 3")      drop_state()



