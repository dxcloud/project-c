###
### SaC2/make/rules.mk
### Requires GNU Make version 3.80 or higher
###

AUTHOR          = Chengwu HUANG
DATE            = 2013-04-11
VERSION         = 1.0

### Set directory path
SAC_MAKE_DIR   ?= $(shell locate -l 1 SaC2/make)
SAC_DIR        ?= $(shell dirname $(SAC_MAKE_DIR))
SRC_DIR         = $(SAC_DIR)/src
BASE_DIR        = $(shell pwd)
BUILD_DIR       = $(BASE_DIR)/build
OBJ_DIR         = $(BUILD_DIR)/objs

### Set a default name for the application if not defined
EXEC           ?= main.out
OUTPUT          = $(addprefix $(BUILD_DIR)/,$(EXEC))

### Set C++ Flags
CXX            ?= g++
CXXFLAGS       += $(CFLAGS)
CXXFLAGS       += -Wall -pedantic -O -Wno-long-long

### Add SaC headers
CXXFLAGS       += -I$(SAC_DIR)/include/assets \
                  -I$(SAC_DIR)/include/core \
                  -I$(SAC_DIR)/include/interfaces \
                  -I$(SAC_DIR)/include/states \
                  -I$(SAC_DIR)/include/types
#CXXFLAGS       += -I$(SAC_DIR)/engine
#CXXFLAGS       += -I$(SAC_DIR)/interfaces
#CXXFLAGS       += -I$(SAC_DIR)/states
#CXXFLAGS       += -I$(SAC_DIR)/types

### Sources
SRC             = $(wildcard *.cpp)
OBJ             = $(addprefix $(OBJ_DIR)/,$(SRC:.cpp=.o))
SAC_SRC         = $(wildcard $(SRC_DIR)/*.cpp)
SAC_OBJ         = $(addprefix $(OBJ_DIR)/,$(notdir $(SAC_SRC:.cpp=.o)))

### Dependencies
DEPFILE         = $(BUILD_DIR)/depend
DEP_DIR         = $(BUILD_DIR)/dep


ifneq (,$(findstring build,$(shell ls $(BASE_DIR))))
  BUILD_FLAG = yes
endif


### Define valid goals
override GOALS := clean docs mrproper depend run

### SAC2_HELP is printed if an unvalid target is specified
define SAC2_HELP

 SaC2 make system:

 Usage: make [OPTION]

 - The executable is in 'build' directory.

 OPTION:
   all       Compile source files.
   docs      Generate documentation.
   clean     Clean '.o' files from 'build' directory.
   mrproper  Remove 'build' and 'docs' directories.

 AUTHORS: $(AUTHOR)
 DATE   : $(DATE)
 VERSION: SaC2 $(VERSION)


endef


### Include depends on goal
ifeq (,$(MAKECMDGOALS))
  include $(SAC_MAKE_DIR)/make.mk
else ifeq ($(filter $(MAKECMDGOALS),$(GOALS)),$(MAKECMDGOALS))
  SAC_INCLUDE = $(addsuffix .mk,$(filter $(MAKECMDGOALS),$(GOALS)))
  include $(SAC_MAKE_DIR)/$(SAC_INCLUDE)
else ifeq (all,$(MAKECMDGOALS))
  include $(SAC_MAKE_DIR)/make.mk
else
  $(info $(SAC2_HELP)Error: Unknown option)
  INVALID_TARGET = $(MAKECMDGOALS)
endif

.PHONY: clean mrproper docs depend

$(INVALID_TARGET): FORCE

FORCE::
	@:
