# SaC2 Demo
__Application:__ SaC2/apps/app00

## Description
This application creates a simple window using SaC3 Engine.

## Files
1. main.cpp

* #include <sac2.hpp>
_sac2.hpp_ contains all includes.
The class __sac2::Engine__ is declared in _sac2___engine.hpp_, and the return value __sac2::sac2_status_t__ is declared in _sac2___types.hpp_.

Declare an engine
* sac2::Engine app;

Check options from line command (optional)
* app.parse_options(argc, argv);

Run the engine
* app.run

2. Makefile

Make sure the path of rules.mk is set, otherwise the application won't compile
* SAC_MAKE ?= ../../make/rules.mk

Give a name for the application
* EXEC     = SaCDemo

Use __CXXFLAGS__ for extras C++ flags, the flag LOG_ENABLED enable to generate a log file
* CXXFLAGS = -DLOG_ENABLED

Include rules.mk
* include $(SAC_MAKE)

## Compilation

* make
The make command will compile main.cpp with SaC2 libraries

## Execute

The executable is in __build__ directory
* ./build/SaCDemo

