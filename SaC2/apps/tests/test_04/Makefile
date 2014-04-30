include $(SAC2_MAKE_PATH)/sfml.mk

EXEC      = test_04

OBJECTS   = test_04.o \
            sac2_state_manager.o \
            sac2_input_manager.o \
            sac2_logger.o

INCLUDES  = -I$(SAC2_PATH)/include/types \
            -I$(SAC2_PATH)/include/assets \
            -I$(SAC2_PATH)/include/states \
            -I$(SAC2_PATH)/include/core \
            -I$(SAC2_PATH)/include/interfaces \
            -I$(SAC2_PATH)/include/utils

CXX       = g++
CXXFLAGS += -Wall -pedantic -std=c++11 -g -O2
CXXFLAGS += -DSAC2_LOGGER_ENABLED
CXXFLAGS += $(INCLUDES)

MEMCHECK_FLAGS = --leak-check=full \
                 --track-origins=yes \
                 --suppressions=default.supp
#                 --gen-suppressions=yes \

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CXX) -o $@ $^ $(LDFLAGS)

test_04.o: test_04.cpp test_04.hpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

sac2_state_manager.o: $(SAC2_PATH)/src/sac2_state_manager.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

sac2_input_manager.o: $(SAC2_PATH)/src/sac2_input_manager.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

sac2_logger.o: $(SAC2_PATH)/src/sac2_logger.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

$(SAC2_PATH)/src/sac2_state_manager.cpp: $(SAC2_PATH)/include/states/sac2_state_manager.hpp

$(SAC2_PATH)/src/sac2_input_manager.cpp: $(SAC2_PATH)/include/core/sac2_input_manager.hpp

$(SAC2_PATH)/src/sac2_logger.cpp: $(SAC2_PATH)/include/core/sac2_logger.hpp

memcheck:
	valgrind $(MEMCHECK_FLAGS) ./$(EXEC)

clean:
	rm -rf *.o *~ $(EXEC)

.PHONY: all clean
