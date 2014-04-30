##
##  test_02
##

include $(SAC2_MAKE_PATH)/sfml.mk

EXEC      = test_02
SOURCE    = test_02

CXX       = g++
CXXFLAGS += -Wall -pedantic -std=c++11 -g -O2

MEMCHECK_FLAGS = --leak-check=full \
                 --show-reachable=yes \
                 --gen-suppressions=yes \
                 --suppressions=default.supp

all: $(EXEC)

$(EXEC): $(SOURCE).o
	$(CXX) -o $@ $^ $(LDFLAGS)

$(SOURCE).o: $(SOURCE).cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

memcheck:
	valgrind $(MEMCHECK_FLAGS) ./$(EXEC)

clean:
	rm -rf *.o *~ $(EXEC)

.PHONY: all clean
