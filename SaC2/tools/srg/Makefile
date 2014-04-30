###---------------------------------------------------------------------------
### SaC2 Resource Generator
### Requires GNU Make version 3.80 or newer
###
### file:        SaC2/tools/Makefile
### author:      Chengwu Huang <chengwhuang@gmail.com>
### date:        2013-06-11
### update:      2013-06-26
### version:     1.0
### description: Build `srg'
###---------------------------------------------------------------------------

### C++ Compiler default parameters
CXX                 = g++
CXXFLAGS            = -Wall -pedantic -std=c++11 -O2
LDFLAGS             =

### Header and source file
SRG_TOOL_PATH      ?= $(shell locate -l 1 SaC2/tools/srg)
SRG_HEADER          = $(SRG_TOOL_PATH)/srg.hpp
SRG_SOURCE          = $(SRG_TOOL_PATH)/srg.cpp
SRG_OBJECT          = $(SRG_TOOL_PATH)/srg.o
SAC2_TOOLS_BIN      = $(dir $(SRG_TOOL_PATH))bin

### Targets
SRG_EXEC            = sac2rg

### Output
SRG_OUTPUT          = $(SAC2_TOOLS_BIN)/$(SRG_EXEC)

### Rapidxml library path
INCLUDE             = $(shell locate -l 1 SaC2/libs/rapidxml)
CXXFLAGS           += -I$(INCLUDE)

all: $(SRG_OUTPUT)

$(SRG_OUTPUT): $(SRG_OBJECT)
	@if [ ! -d "$(SAC2_TOOLS_BIN)" ]; then \
	  echo "Creating directory \`$(SAC2_TOOLS_BIN)' ..."; \
	  mkdir $(SAC2_TOOLS_BIN); \
	fi
	@echo "Building \`$(SRG_EXEC)' ..."
	@$(CXX) $(LDFLAGS) -o $@ $(SRG_OBJECT)
	@echo "Finished"

$(SRG_OBJECT): $(SRG_SOURCE) $(SRG_HEADER)
	@$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	@rm -rf *~ *.o

distclean: clean
	@rm -f $(SRG_OUTPUT)

.PHONY: all clean

