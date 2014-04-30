CXXFLAGS += -DSAC2_LOGGER_ENABLED
CXX = g++

OBJ  = test.o logger.o
SRC  = ../../../src/sac2_logger.cpp
INCL = -I../../../include/core/ \
        -I../../../include/types \
        -I../../../include/utils

CXXFLAGS += -Wall -std=c++11 $(INCL)

include ../../../make/sfml.mk

all: test .FORCE

test: $(OBJ)
	$(CXX) $^ -o $@ $(LDFLAGS)

test.o: .FORCE
	$(CXX) $(CXXFLAGS) -c test_06.cpp -o $@

logger.o: .FORCE
	$(CXX) $(CXXFLAGS) -c $(SRC) -o $@


clean:
	rm -rf *~ *.o test

#include $(SAC2_MAKERULES)

.FORCE:


