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
OPTFLAGS            = -O2
CXXFLAGS           += -Wall -pedantic -std=c++11
CXXFLAGS           += $(OPTFLAGS)
LDFLAGS             =

### Targets
EXEC                = srg

### Header and source file
SRG_HEADER          = srg.hpp
SRG_SOURCE          = srg.cpp
SRG_OBJECT          = srg.o

### Rapidxml library path
INCLUDE             = $(shell locate -l 1 SaC2/libs/rapidxml)
CXXFLAGS           += -I$(INCLUDE)

all: $(EXEC)

$(EXEC): $(SRG_OBJECT)
	@$(CXX) $(LDFLAGS) -o $@ $^

$(SRG_OBJECT): $(SRG_SOURCE) $(SRG_HEADER)
	@$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	@rm -rf $(EXEC) *~ *.o

.PHONY: all,clean
