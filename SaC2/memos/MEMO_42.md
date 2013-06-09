# GAME STATE MANAGEMENT: STATE MACHINE
**MEMO 42: 2013-06-08**

## State machine

                     +---------------+
                   =>| UNINITIALIZED |
                     +---------------+
                             | initialize_state()
                             V
                     +---------------+
                  +->|  INITIALIZED  |
                  |  +---------------+
                  |          | start_state()
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


