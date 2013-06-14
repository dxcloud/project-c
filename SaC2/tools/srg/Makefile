###
### SaC2 Resource Generator
### Makefile
### Version 0.1
### Date: 2013-06-11
###

### Compiler and compilation options
CXX        = clang++
CXXFLAGS  += -Wall -pedantic -O2
#CXXFLAGS  += -DRAPIDXML_NO_EXCEPTIONS
LDFLAGS   +=

### Targets
ALL        = all
EXEC       = srg
CLEAN      = clean
HELP       = help

### Shell command
RM         = rm
PRINT      = echo

### Header and source file
SRG_SOURCE = srg.cpp
SRG_OBJECT = srg.o
SRG_HEADER = srg.hpp

### Rapidxml library path
INCLUDE    = $(shell locate -l 1 SaC2/libs/rapidxml)
CXXFLAGS  += -I$(INCLUDE)

$(ALL): $(EXEC)

$(EXEC): $(SRG_OBJECT)
	$(CXX) $(LDFLAGS) -o $@ $^

$(SRG_OBJECT): $(SRG_SOURCE) $(SRG_HEADER)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(CLEAN):
	$(RM) -rf $(EXEC) *~ *.o

$(HELP):
	@$(PRINT) "Type \"make\" to build"

