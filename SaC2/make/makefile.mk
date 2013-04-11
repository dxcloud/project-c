###
### This Makefile requires GNU Make version 3.80 or higher
###

VERSION      := 0.1

### Set a default name for the application if not defined
EXEC           ?= main.out

### Set variables
SAC_MAKE_DIR   ?= $(shell locate -l 1 SaC2/make)
SAC_DIR         = $(dir $(SAC_MAKE_DIR))
SRC_DIR         = $(SAC_DIR)/src
BASE_DIR        = $(shell pwd)
BUILD_DIR       = $(BASE_DIR)/build
OBJ_DIR         = $(BUILD_DIR)/obj

### Set C++ Flags
CXX             = g++
CXXFLAGS       += $(CFLAGS)
CXXFLAGS       += -Wall -ansi -pedantic -O2

### Add SaC headers
CXXFLAGS       += -I$(SAC_DIR)/assets
CXXFLAGS       += -I$(SAC_DIR)/engine
CXXFLAGS       += -I$(SAC_DIR)/interfaces
CXXFLAGS       += -I$(SAC_DIR)/states
CXXFLAGS       += -I$(SAC_DIR)/types

SRC             = $(wildcard *.cpp)
OBJ             = $(addprefix $(OBJ_DIR)/,$(SRC:.cpp=.o))
SAC_SRC         = $(wildcard $(SRC_DIR)/*.cpp)
SAC_OBJ         = $(addprefix $(OBJ_DIR)/,$(notdir $(SAC_SRC:.cpp=.o)))

### SFML Path
SFML_PATH      ?= /usr/local/lib
SFML_FLAGS     += -L$(SFML_PATH)
SFML_FLAGS     += -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system

OUTPUT          = $(addprefix $(BUILD_DIR)/,$(EXEC))

override GOALS := all clean docs mrproper

define SAC2_HELP

 SaC2 make system:
 Compile the current project with SaC2

 Usage: make [OPTION]

 OPTION:
   docs      Generate documentation
   clean     Clean '.o' files from 'build' directory
   mrproper  Remove 'build' and 'docs' directories

 SaC2 $(VERSION)


endef


ifeq ($(MAKECMDGOALS),)
  $(info Compiling source files)
  include $(SAC_MAKE_DIR)/make.mk
else ifeq ($(filter $(MAKECMDGOALS),$(GOALS)),$(MAKECMDGOALS))
    SAC_INCLUDE = $(addsuffix .mk,$(filter $(MAKECMDGOALS),$(GOALS)))
    $(info $(SAC_INCLUDE))
    include $(SAC_MAKE_DIR)/$(SAC_INCLUDE)
else
  $(error $(SAC2_HELP)Error: Unknown option)
endif

all: $(BUILD_DIR) $(OUTPUT)

.PHONY: clean mrproper docs help
