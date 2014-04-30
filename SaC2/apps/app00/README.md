# SaC2 Demo
__Application:__ SaC2/apps/app00

## Description
This application creates a simple window using SaC3 Engine.

## Files
###main.cpp

Include headers:
`#include <sac2.hpp>`

Declare an engine:
`sac2::Engine app;`

Check options from line command (optional):
`app.parse_options(argc, argv);`

Run engine:
`app.run();`

###Makefile

Set the path of _rules.mk_ if NOT set yet, otherwise the application won't compile:
`SAC_MAKE ?= ../../make/rules.mk`

Give a name for the application:
`EXEC     = SaCDemo`

__CXXFLAGS__ is used for extras C++ flags:
`CXXFLAGS = -DLOG_ENABLED`

Include rules.mk:
`include $(SAC_MAKE)`

## Compilation

        make
The make command will compile _main.cpp_ with SaC2 libraries.

## Execute

        ./build/SaCDemo
Close the window will terminate the application.
