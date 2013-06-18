###---------------------------------------------------------------------------
### SaC2 make system
### Requires GNU Make version 3.80 or newer
###
### file:        SaC2/make/rules.mk
### author:      Chengwu Huang <chengwhuang@gmail.com>
### date:        2013-04-11
### update:      2013-06-17
### version:     1.0
### description: Define global variables needed by different goals.
###---------------------------------------------------------------------------

###---------------------------------------------------------------------------
### Check GNU make version
###---------------------------------------------------------------------------
vmake_required     := 3.80
check_vmake        := $(filter $(vmake_required), \
                      $(firstword $(sort $(MAKE_VERSION) $(vmake_required))))

ifeq (,$(check_vmake))
  $(error GNU make version 3.80 or newer is required.)
endif

###---------------------------------------------------------------------------
### Set SaC2 global variables
###---------------------------------------------------------------------------
SAC2_MAKERULES     ?= $(shell locate -l 1 SaC2/make/rules.mk)
SAC2_MAKE_PATH     ?= $(shell dirname $SAC2_MAKERULES)
SAC2_PATH          ?= $(dirname $SAC2_MAKE_DIR)

### C++ Compiler default parameters
CXX                ?= g++
OPTFLAGS           ?= -O2
CXXFLAGS           += $(CFLAGS) $(OPTFLAGS)
CXXFLAGS           += -Wall -pedantic -std=c++11

### Define source directories
WORK_DIR            = $(PWD)
BUILD_DIR           = $(WORK_DIR)/build
OBJECT_DIR          = $(BUILD_DIR)/objs
LIBRARY_DIR         = $(BUILD_DIR)/lib

### Dependencies file
DEPFILE             = $(BUILD_DIR)/.depend

### Executable parameters
EXEC               ?= main.out
OUTPUT              = $(addprefix $(BUILD_DIR)/,$(EXEC))

### Sources
SOURCES             = $(wildcard *.cpp)

###---------------------------------------------------------------------------
### Define valid goals
###---------------------------------------------------------------------------
override SAC2_GOALS = all \
                      archive \
                      clean \
                      depend \
                      distclean \
                      docs \
                      exec \
                      help \
                      memcheck \
                      mrproper \
                      run

define SAC2_HELP_MAKE
SaC2 make system
endef

###---------------------------------------------------------------------------
### Usage message
###---------------------------------------------------------------------------
define SAC2_HELP_USAGE
USAGE:
  `make <COMMAND>' or `make help <COMMAND>'
endef

###---------------------------------------------------------------------------
### SaC2 version message
###---------------------------------------------------------------------------
define SAC2_HELP_VERSION
VERSION:
  SaC2 1.0
AUTHORS:
  Chengwu Huang <chengwhuang@gmail.com>
DATE:
  2013-04-11
UPDATED:
  2013-06-17
endef

###---------------------------------------------------------------------------
### No executable message
###---------------------------------------------------------------------------
define SAC2_HELP_RUN
$(SAC2_HELP_MAKE)

ERROR:
  The executable `$(EXEC)' does NOT exist.

SEE ALSO:
  For the compilation, type `make help all' or `make help exec'.
  For more information about SaC2 make system, type `make help'.

$(SAC2_HELP_VERSION)
endef

###---------------------------------------------------------------------------
### Include user goal file
### - If no goal is specified, the code sources will be build
### - Otherwise, the valid command will be executed.
###---------------------------------------------------------------------------
SHOW_DEPENDENCIES=no

USER_REQUEST_CMD    = $(word 1,$(filter $(MAKECMDGOALS),$(SAC2_GOALS)))

ifeq (,$(MAKECMDGOALS))
  include $(SAC2_MAKE_PATH)/help.mk
else ifeq ($(USER_REQUEST_CMD),$(MAKECMDGOALS))
  goal_include = $(addsuffix .mk,$(filter $(MAKECMDGOALS),$(SAC2_GOALS)))
  ifeq (depend,$(USER_REQUEST_CMD))
  SHOW_DEPENDENCIES=yes
  endif
  include $(SAC2_MAKE_PATH)/$(goal_include)
else
  include $(SAC2_MAKE_PATH)/help.mk
endif

.PHONY: .FORCE $(SAC2_GOALS)

.DEFAULT: help

.FORCE:
	@:

