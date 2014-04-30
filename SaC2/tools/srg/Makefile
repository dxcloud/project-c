###---------------------------------------------------------------------------
### SaC2 Resource Generator
### Requires GNU Make version 3.80 or newer
###
### file: SaC2/tools/Makefile
### author: Chengwu Huang <chengwhuang@gmail.com>
### date: 2013-06-11
### update: 2013-06-26
### version: 1.0
### description: Build `srg'
###---------------------------------------------------------------------------

SHELL = /bin/sh

### C++ Compiler default parameters
CXX = g++
CXXFLAGS = -Wall -pedantic -std=c++11 -O2
LDFLAGS =

### Header and source file
SRG_TOOL_PATH ?= $(shell locate -l 1 SaC2/tools/srg)
SAC2_TOOLS_BIN = $(addprefix $(dir $(SRG_TOOL_PATH)),bin)

SRG_CLASS = srg
MAIN = sac2rg

SRG_HEADER = $(SRG_TOOL_PATH)/$(SRG_CLASS).hpp
SRG_SOURCE = $(SRG_TOOL_PATH)/$(SRG_CLASS).cpp
OBJECTS = $(SRG_TOOL_PATH)/$(SRG_CLASS).o \
                      $(SRG_TOOL_PATH)/$(MAIN).o

### Target
TARGET = $(SAC2_TOOLS_BIN)/$(MAIN)

### Rapidxml library path
INCLUDE = $(shell locate -l 1 SaC2/libs/rapidxml-1.13)
CXXFLAGS += -I$(INCLUDE)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@if [ ! -d "$(SAC2_TOOLS_BIN)" ]; then \
	  echo "Creating directory \`$(SAC2_TOOLS_BIN)'..."; \
	  mkdir $(SAC2_TOOLS_BIN); \
	fi
	$(CXX) $^ -o $@ $(LDFLAGS)
	@echo "Finished"

%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

$(SRG_SOURCE): $(SRG_HEADER)

clean:
	@rm -rf *~ *.o
	@echo "Removed temporary files"

distclean: clean
	@rm -rf $(TARGET) $(MAIN).1
	@echo "Removed binary executable"

man:
	help2man -o $(MAIN).1 $(MAIN)

.PHONY: all clean distclean
