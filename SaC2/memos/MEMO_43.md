# GAME STATE MANAGEMENT: MANAGING STATES
**MEMO 43: 2013-06-08**

## State stack
A first game state is pushed on the stack, at the start of the game.
To start another game state, call `StateManager::change_state(state_id_t),
the new state will be pushed on top of that and the first one will be no
longer updated.
When a game state ends, use `StateManager::drop_state()' to pop it off
the stack, the previous state can be resumed exactly where it is left off.

### Change game state


                           +=========+
                           | State 3 |
    +=========+            +=========+            +=========+
    | State 2 |            | State 2 |            | State 2 |
    +=========+ =========> +---------+ =========> +=========+
    | State 1 |            | State 1 |            | State 1 |
    +---------+            +---------+            +---------+
          change_state("State 3")     drop_state()

    Legend:
    +=========+
    |         | current playing state
    +=========+